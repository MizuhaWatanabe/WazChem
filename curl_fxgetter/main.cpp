#include <iostream>
#include <string>
#include <curl/curl.h>

//#include "WebScraper.h"
#include "CurrentFx.h"
#include "PastFx.h"



using namespace std;


int main()
{

	CurrentFx cfx;
	cfx.set_currency_pair("USDJPY");
	cfx.LoadCurrentFx();
	time_t got_time=cfx.get_got_time();
	cout << ctime(&got_time) << endl;
	cout << cfx.get_bid_price() <<endl;
	cout << cfx.get_ask_price() <<endl;

//	PastFx pfx;
//	pfx.Scraper();
//	cout << pfx.hozonsaki <<endl;
	return 0;
}
