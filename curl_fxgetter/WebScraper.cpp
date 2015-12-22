#include "WebScraper.h"



//////////////////////////コンストラクタ//////////////////////////

WebScraper::WebScraper()
{
}

WebScraper::WebScraper(string str)//取得とスプリットをすべてやるタイプのコンストラクタ
{
	url=str;
	LoadHtml();
	SplitHtml();
}

WebScraper::~WebScraper(void)
{
}

//////////////////////////アクセサ////////////////////////////////

void WebScraper::set_url(string str)
{
	url=str;
}

string WebScraper::get_html(void)//htmlのアクセサ
{
	return loaded_html;
}

vector<string> WebScraper::get_splitted_tag(void)//スプリットした配列へのアクセサ
{
	return splitted_tag;
}

//////////////////////////処理系////////////////////////////////////

void WebScraper::LoadHtml(void)
{
  CURL *curl;
  CURLcode res;
  curl = curl_easy_init();
  if(curl) {
	  curl_easy_setopt(curl, CURLOPT_URL, url.c_str() );
    /* example.com is redirected, so we tell libcurl to follow redirection */ 
    curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
 
	//取得データを変数に格納するための記述

	curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, CallbackFunc);
	curl_easy_setopt(curl, CURLOPT_WRITEDATA, &loaded_html);


    /* Perform the request, res will get the return code */ 
    res = curl_easy_perform(curl);

    /* Check for errors */ 
    if(res != CURLE_OK)
      fprintf(stderr, "curl_easy_perform() failed: %s\n",
              curl_easy_strerror(res));
 

    /* always cleanup */ 
    curl_easy_cleanup(curl);
  }

}

void WebScraper::LoadHtml(string str)//じかに打ち込む
{
  CURL *curl;
  CURLcode res;
  curl = curl_easy_init();
  if(curl) {
	  curl_easy_setopt(curl, CURLOPT_URL, str.c_str() );
    /* example.com is redirected, so we tell libcurl to follow redirection */ 
    curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
 
	//取得データを変数に格納するための記述

	curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, CallbackFunc);
	curl_easy_setopt(curl, CURLOPT_WRITEDATA, &loaded_html);


    /* Perform the request, res will get the return code */ 
    res = curl_easy_perform(curl);

    /* Check for errors */ 
    if(res != CURLE_OK)
      fprintf(stderr, "curl_easy_perform() failed: %s\n",
              curl_easy_strerror(res));
 

    /* always cleanup */ 
    curl_easy_cleanup(curl);
  }

}

void WebScraper::SplitHtml(void)
{
//「<>」記号ごとにスプリットする関数。改行は無視されるので、改行のみの要素は作成されない。
//vector<string>に格納して返す。

	vector<string> res;
	size_t current=loaded_html.find_first_not_of("\n<>",1);
	size_t found;



	
	while((found=loaded_html.find_first_of("\n<>",current)) != string::npos){ 
		
		res.push_back(string(loaded_html,current,found-current));
		if(loaded_html.find_first_not_of("\n<>",found) != string::npos){
			current=loaded_html.find_first_not_of("\n<>",found);
		}
		else break;
		

	}
	res.push_back(string(loaded_html, current, loaded_html.size() - current));
	splitted_tag=res;
}


////////////////////////////非メンバ///////////////////////////////////////

size_t CallbackFunc(char *ptr, size_t size, size_t nmemb, string *str)//コールバック関数
{
	int realsize=size*nmemb;
	str->append(ptr,realsize);//格納？
	return realsize;
}
