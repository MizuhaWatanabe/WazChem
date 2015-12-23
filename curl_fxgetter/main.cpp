#include <iostream>
#include <string>
#include <curl/curl.h>

//#include "WebScraper.h"
#include "CurrentFx.h"
#include "PastFx.h"
#include "CurrentStock.h"



using namespace std;


int main()
{
	/*
	CurrentFx cfx("EURJPY");
	time_t got_time=cfx.get_got_time();
	cout << ctime(&got_time) << endl;
	cout << cfx.get_bid_price() <<endl;
	cout << cfx.get_ask_price() <<endl;
	*/
	
	CurrentStock cst(8704);
	time_t got_time=cst.get_got_time();
	cout << ctime(&got_time) <<endl;
	cout << cst.get_verbose() <<endl;
	cout << cst.get_stock_price() <<endl;
	


	
	return 0;
}
