#include "list.h"
#include "Stake.h"
#include "Competitor.h"
#include "BrockerResult.h"

class Brocker
{
public:
	Brocker();
	~Brocker();
	List<Competitor>* getCompetitorsList();
	List<Competitor>* getCompetitorsActualList();
	List<BrockerResult>* getResultsList();
	int* getAvailableStakes();
	int putTheBet();
	int getMoney();

private:
	List<Competitor>* competitorsList;
	List<Competitor>* competitorsActualList;
	List<Stake>* stakeList;
	List<BrockerResult>* resultsList;
	int brokerRate;
	double brokerProfit;
	int* stakeArray;

	template <class T>
	int copyList(List<T>* listFrom, List<T>* &listTo);
};

