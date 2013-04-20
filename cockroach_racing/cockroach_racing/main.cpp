#include "Broker.h"

int main() {
	Broker broker;
	try
	{
		List<Stake*> stakeList = broker.createStakeList();
		List<Track*> trackList = broker.createTrackList();

		broker.createUserList(trackList, stakeList);
		broker.createBrokerResultsFile();
	}
	catch (Broker::Exception e) {
		cout << e.text;
	}
	system("pause");
	return 0;
}