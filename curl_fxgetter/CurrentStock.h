//	CurrentStock.h
//	株式の現在価格を扱うクラス。
//	一部機能がCurrentStockとかぶる（面倒な気がしたので継承はしていない）
//	将来的には多サイト、多取引所を扱える設計を目指している。
//	たとえばこのクラスからCurrentStock_topix, CurrentStock_mothersなどへ
//	継承していくとか…

#include <string>
#include <ctime>
#include "WebScraper.h"

#pragma once
using namespace std;

class CurrentStock
{	

	string verbose;//冗長情報。参照先の表示などに。
	time_t got_time;//取得時間
	int stock_code;//会社コード

	double stock_price;//価格
	double order_bid;//板情報を格納するとこ	
	double order_ask;//板情報を格納するとこ

public:
	CurrentStock(void);
	CurrentStock(int);//いきなりコードを打ち込んで始めるやつ
	~CurrentStock(void);

	string get_verbose(void);
	time_t get_got_time(void);

	double get_stock_price(void);
	double get_order_bid(void);
	double get_order_ask(void);
	int get_stock_code(void);
	void set_stock_code(int);

	void LoadCurrentStock(void);
};

