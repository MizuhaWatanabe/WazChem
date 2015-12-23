//	CurrentStock.c
//	株式の現在価格を扱うクラス。
//	一部機能がCurrentStockとかぶる（面倒な気がしたので継承はしていない）
//	将来的には多サイト、多取引所を扱える設計を目指している。
//	たとえばこのクラスからCurrentStock_topix, CurrentStock_mothersなどへ
//	継承していくとか…

#include "CurrentStock.h"


////////////////////コンストラクタ/////////////////

CurrentStock::CurrentStock(void)
{
	stock_code=0;
	stock_price=0;
	order_bid=0;
	order_ask=0;
}

CurrentStock::CurrentStock(int stkcode)//いきなりコードを入れて始めるやつ
{
	stock_code=0;
	stock_price=0;
	order_bid=0;
	order_ask=0;
	set_stock_code(stkcode);
	LoadCurrentStock();
}

CurrentStock::~CurrentStock(void)
{
}

/////////////////////アクセッサ///////////////////

string CurrentStock::get_verbose(void)
{
	return verbose;
}

time_t CurrentStock::get_got_time(void)
{ 
	return got_time;
}

void CurrentStock::set_stock_code(int stkcode)
{
	stock_code=stkcode;
}

int CurrentStock::get_stock_code(void)
{
	return stock_code;
}

double CurrentStock::get_stock_price(void)
{
	return stock_price;
}

double CurrentStock::get_order_bid(void)
{
	return order_bid;
}

double CurrentStock::get_order_ask(void)
{
	return order_ask;
}


///////////////////////処理系//////////////////////

void CurrentStock::LoadCurrentStock(void)
{
	string url="http://stocks.finance.yahoo.co.jp/stocks/detail/?code="+to_string(stock_code);
	verbose="scraped from"+url+".\n";
	WebScraper websc(url);
	time(&got_time);//時刻の取得
	vector<string> splitted_tag = websc.get_splitted_tag();


	vector<string>::iterator cIter=find(splitted_tag.begin(), splitted_tag.end(), "td class=\"stoksPrice\"");
	if(cIter!=splitted_tag.end()){
		size_t index=distance(splitted_tag.begin(),cIter);
		stock_price=stod("0"+splitted_tag[(int)index+1]);
	}

	//一応株式会社名も取っておく?
	cIter=find(splitted_tag.begin(), splitted_tag.end(), "title");
	if(cIter!=splitted_tag.end()){
		size_t index=distance(splitted_tag.begin(),cIter);
		verbose+=splitted_tag[(int)index+1];
	}



}










