#include "Brocker.h"
#include "list.h"


Brocker::Brocker()
	:competitorsList(new List<Competitor>), competitorsActualList(new List<Competitor>),
	 stakeArray(new int[4])
{
	//available stakes
	stakeArray[0] = 10;
	stakeArray[1] = 25;
	stakeArray[2] = 50;
	stakeArray[3] = 100;
}


Brocker::~Brocker()
{
	delete competitorsList;
	delete competitorsActualList;
	delete stakeArray;
}

List<Competitor>* Brocker::getCompetitorsList()
{
	//TODO: get list of competitors from the association
	//TODO: copy recieved list to the attribute "competitorsList"
	return competitorsList;
}

List<Competitor>* Brocker::getCompetitorsActualList()
{
	//TODO: get actual list of competitors from the association
	//TODO: copy recieved list to the attribute "competitorsActualList"
	return competitorsActualList;
}

List<BrockerResult>* Brocker::getResultsList()
{
	//TODO: get result list from the association
	//TODO: copy recieved list to the attribute "resultsList"
	return resultsList;
}

int* Brocker::getAvailableStakes()
{
	return stakeArray;
}

int Brocker::putTheBet()
{
	Stake stake;
	//TODO: set necessary attributes of the stake object
	(*stakeList).add(stake);
}

int Brocker::getMoney()
{
}

template <class T>
int Brocker::copyList(List<T>* listFrom, List<T>* &listTo)
{
	for (int i=0, count=(*listFrom).count(); i<count; ++i) {
		Node* elem = (*listFrom).find(i);
		if (elem != NULL) {
			(*listTo).add(elem->value);
		}
	}
	return ((*listTo).count() > 0);
}