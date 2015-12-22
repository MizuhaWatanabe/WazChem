#include "CurrentFx.h"

/////////////////�R���X�g���N�^�E�f�X�g���N�^////////////////////

CurrentFx::CurrentFx(void)
{
	ask_price=0;
	bid_price=0;
}

CurrentFx::CurrentFx(string str)//�����Ȃ�ʉ߃y�A�w�肷��z�B���[�h�܂ňꊇ�ōs���Ă��܂��B
{
	currency_pair=str;
	ask_price=0;
	bid_price=0;
	LoadCurrentFx();


}


CurrentFx::~CurrentFx(void)
{
}

/////////////////�A�N�Z�b�T//////////////////////////////////

double CurrentFx::get_bid_price(void)
{
	return bid_price;
}

double CurrentFx::get_ask_price(void)
{
	return ask_price;
}

time_t CurrentFx::get_got_time(void)
{
	return got_time;
}

void CurrentFx::set_currency_pair(string str)
{
	currency_pair=str;
}

string CurrentFx::get_currency_pair(void)
{
	return currency_pair;
}

/////////////////�����n//////////////////////////////////////

void CurrentFx::LoadCurrentFx(void)
//
//
{
	string url="http://info.finance.yahoo.co.jp/fx/list/";
	WebScraper websc;
	websc.set_url(url);
	websc.LoadHtml();
	cout << websc.get_html() << endl;
	/*vector<string> splitted_tag = websc.get_splitted_tag();

	vector<string>::iterator cIter=find(splitted_tag.begin(), splitted_tag.end(), "span id=\""+currency_pair+"_chart_bid\"");
	if(cIter!=splitted_tag.end()){
		size_t index=distance(splitted_tag.begin(),cIter);
		bid_price=stod("0"+splitted_tag[(int)index+1]);
	}
	cIter=find(splitted_tag.begin(), splitted_tag.end(), "span id=\""+currency_pair+"_chart_ask\"");
	if(cIter!=splitted_tag.end()){
		size_t index=distance(splitted_tag.begin(),cIter);
		bid_price=stod("0"+splitted_tag[(int)index+1]);
	}*/
}


