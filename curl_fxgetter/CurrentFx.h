//	CurrentFx.h
//	オンタイムの為替レートを取得するクラス。
//	まずyahoo,そのうち各社対応を目指す

 
#include "WebScraper.h"
#include <string>
#include <vector>
#include <iostream>
#include <ctime>

#pragma once




class CurrentFx
{
	string verbose;//冗長情報。参照先の表示などに。

	time_t got_time;//取得時間
	
	string currency_pair;//読むべきペアを決める

	double bid_price;//Bidの数値
	double ask_price;//Askの数値
	

public:
	CurrentFx(void);
	CurrentFx(string);//いきなり通貨ペアを指定する奴
	~CurrentFx(void);

	void set_currency_pair(string);
	string get_currency_pair(void);
	string get_verbose(void);
	double get_bid_price(void);
	double get_ask_price(void);
	time_t get_got_time(void);

	void LoadCurrentFx(void);

};

