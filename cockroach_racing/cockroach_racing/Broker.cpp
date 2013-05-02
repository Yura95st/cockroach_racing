#include "Broker.h"
#include "pugixml.hpp"
using namespace std;
using namespace pugi;

string Broker::stakesFileName = "resources/stakes.xml";
string Broker::raceResultsFileName = "resources/race_results.xml";
string Broker::resultsFileName = "resources/broker_results.xml";
int Broker::brokerInterest = 2;

Broker::Broker(void)
{
}


Broker::~Broker(void)
{
}

List<Stake*> Broker::createStakeList()
{
	xml_document doc;
	xml_parse_result result = doc.load_file(stakesFileName.c_str());

	if (!result) {
		throw(Exception("Error while parsing XML file", 100));
	}

	List<Stake*> stakeList;
	
	for (xml_node stakeDOM = doc.child("StakeList").child("Stake"); stakeDOM != NULL; stakeDOM = stakeDOM.next_sibling()) {
		Stake* stake = new Stake();

		stake->setId(stakeDOM.child("Stake_id").text().as_int());
		stake->setUserId(stakeDOM.child("User_id").text().as_int());
		stake->setTrackId(stakeDOM.child("Track_id").text().as_int());
		stake->setTeamId(stakeDOM.child("Team_id").text().as_int());
		stake->setValue(stakeDOM.child("Stake_value").text().as_int());
		
		stakeList.add(stake);
	}

	return stakeList;
}

List<Track*> Broker::createTrackList()
{
	xml_document doc;
	xml_parse_result result = doc.load_file(raceResultsFileName.c_str());

	if (!result) {
		throw(Exception("Error while parsing XML file", 100));
	}

	List<Track*> trackList;
	
	for (xml_node trackDOM = doc.child("raceResults").child("race"); trackDOM != NULL; trackDOM = trackDOM.next_sibling()) {
		Track* track = new Track();		

		track->setId(trackDOM.child("id").text().as_int());
		for (xml_node roachDOM = trackDOM.child("roach"); roachDOM != NULL; roachDOM = roachDOM.next_sibling()) {
			int roach_position = roachDOM.child("position").text().as_int();
			if (roach_position <= 3 && roach_position > 0) {
				Roach* roach = new Roach();
				roach->setId(roachDOM.child("roach_id").text().as_int());
				roach->setTeamId(roachDOM.child("team_id").text().as_int());
				roach->setPosition(roach_position);

				track->setNewRoach(roach);
			}			
		}		
		trackList.add(track);
	}

	return trackList;
}

int Broker::createUserList(List<Track*> &trackList, List<Stake*> &stakeList)
{
	for (int i=0, track_length = trackList.count(); i<track_length; ++i) {
		Track* track = trackList.find(i)->value;
		for (int j=0, stake_length = stakeList.count(); j<stake_length; ++j) {			
			Stake* stake = stakeList.find(j)->value;

			//if (track->getId() == stake->getTrackId() 
			//	&& track->getWinner()->getTeamId() == stake->getTeamId()) {

			if (track->getId() == stake->getTrackId()) {
				Roach* winner = track->getWinner();
				int id = winner->getTeamId();
				if (id == stake->getTeamId()) {
					User* user = new User();
					int user_id = stake->getUserId();
					int value = stake->getValue() * brokerInterest;
					user->setId(user_id);
					user->setValue(value);

					addUniqueUserListElem(user);
				}
			}
		}
	}
	return 0;
}

void Broker::addUniqueUserListElem(User* user)
{
	bool elemFound = false;

	for(int k=0, user_lenght = userList.count(); k<user_lenght; ++k) {
		Node<User*>* user_elem = userList.find(k);
		if (user_elem->value->getId() == user->getId()) {
			elemFound = true;
			int value = user_elem->value->getValue() + user->getValue();
			user_elem->value->setValue(value);
			break;
		}
	}

	if (!elemFound) {
		userList.add(user);
	}
}

void Broker::createBrokerResultsFile()
{
	string fileContent("<?xml version=\"1.0\" encoding=\"utf-8\"?>");
	fileContent += "<BrokerResults>";

	for(int k=0, user_lenght = userList.count(); k<user_lenght; ++k) {
		Node<User*>* user_elem = userList.find(k);
		if (user_elem == NULL) {
			continue;
		}
		stringstream ss, ss2;
		

		fileContent += "<User>";
			fileContent += "<User_id>";
				ss << user_elem->value->getId();
				fileContent += ss.str();
			fileContent += "</User_id>";

			fileContent += "<Value>";
				ss2 << user_elem->value->getValue();
				fileContent += ss2.str();
			fileContent += "</Value>";
		fileContent += "</User>";
	}

	fileContent += "</BrokerResults>";

	FILE *res_file = fopen(resultsFileName.c_str(), "w");
	if (res_file == NULL) {
		throw(Exception("Error while writing to the result file", 101));
	}

	fprintf(res_file, "%s", fileContent.c_str());
	fclose(res_file);
}