#include "Broker.h"

int main(int argc, char *argv[]) {
	Broker broker;
	switch(*argv[1]) {
	case '0' :
		{
			try
			{
				broker.init();

				List<Stake*> stakeList = broker.createStakeList();
				List<Track*> trackList = broker.createTrackList();

				broker.createUserList(trackList, stakeList);
				broker.createBrokerResultsFile();
				broker.createBrokerFile();
			}
			catch (Broker::Exception e) {
				cout << e.text;
			}
			break;
		}
	default:
		{
			break;
		}
	}
	system("pause");
	return 0;
}