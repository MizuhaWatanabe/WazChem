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
	
//	PastFx pfx;
//	pfx.Scraper();
//	cout << pfx.hozonsaki <<endl;
	return 0;
}
