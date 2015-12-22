#include "WebScraper.h"



//////////////////////////コンストラクタ//////////////////////////

WebScraper::WebScraper()
{
}

WebScraper::WebScraper(string)
{
}

WebScraper::~WebScraper(void)
{
}

//////////////////////////アクセッサ////////////////////////////////

void set_url(string);//一応セッターを設けるが、使う機会はなさそう？
	void LoadHtml(void);
	void LoadHtml(string);//直にurl打ち込むタイプ
	void SplitHtml(void);

	string get_html(void);//htmlのアクセサ
	vector<string> get_splitted_tag(void);//スプリットした配列へのアクセサ

