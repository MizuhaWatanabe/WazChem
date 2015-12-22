//	WebScraper.h					
//	webスクレイプを行うためのクラス	   
//	コールバック関数のみメンバにできていないのは今後の課題。

#include <string>
#include <curl/curl.h>
#include <vector>

#pragma once

using namespace std;

class WebScraper
{
private:
	string url;
	vector<string> splitted_tag;
	string loaded_html;

public:
	
	WebScraper(void);
	WebScraper(string);//はじめからurl読み込むタイプのコンストラクタ
	~WebScraper(void);
	
	void set_url(string);//一応セッターを設けるが、使う機会はなさそう？
	void LoadHtml(void);
	void LoadHtml(string);//直にurl打ち込むタイプ
	void SplitHtml(void);

	string get_html(void);//htmlのアクセサ
	vector<string> get_splitted_tag(void);//スプリットした配列へのアクセサ

};


size_t CallbackFunc(char*, size_t, size_t, string*);//curl書き出し用のコールバック関数
