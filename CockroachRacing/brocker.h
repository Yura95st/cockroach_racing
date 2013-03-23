#include "list.h"
#include "Stake.h"
#include "Competitor.h"
#include "BrockerResult.h"

class Brocker
{
public:
	Brocker();
	~Brocker();

private:
	List<Competitor>* competitorList;
	List<Competitor>* competitorActualList;
	List<Stake>* stakeList;
	List<BrockerResult>* resultsList;
	int brokerRate;
	double brokerProfit;
	int stakeArray[];
	//
};

