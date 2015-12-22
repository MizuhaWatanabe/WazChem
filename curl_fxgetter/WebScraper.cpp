#include "WebScraper.h"



//////////////////////////�R���X�g���N�^//////////////////////////

WebScraper::WebScraper()
{
}

WebScraper::WebScraper(string str)//�擾�ƃX�v���b�g�����ׂĂ��^�C�v�̃R���X�g���N�^
{
	url=str;
	LoadHtml();
	SplitHtml();
}

WebScraper::~WebScraper(void)
{
}

//////////////////////////�A�N�Z�T////////////////////////////////

void WebScraper::set_url(string str)
{
	url=str;
}

string WebScraper::get_html(void)//html�̃A�N�Z�T
{
	return loaded_html;
}

vector<string> WebScraper::get_splitted_tag(void)//�X�v���b�g�����z��ւ̃A�N�Z�T
{
	return splitted_tag;
}

//////////////////////////�����n////////////////////////////////////

void WebScraper::LoadHtml(void)
{
  CURL *curl;
  CURLcode res;
  curl = curl_easy_init();
  if(curl) {
	  curl_easy_setopt(curl, CURLOPT_URL, url.c_str() );
    /* example.com is redirected, so we tell libcurl to follow redirection */ 
    curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
 
	//�擾�f�[�^��ϐ��Ɋi�[���邽�߂̋L�q

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

void WebScraper::LoadHtml(string str)//�����ɑł�����
{
  CURL *curl;
  CURLcode res;
  curl = curl_easy_init();
  if(curl) {
	  curl_easy_setopt(curl, CURLOPT_URL, str.c_str() );
    /* example.com is redirected, so we tell libcurl to follow redirection */ 
    curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
 
	//�擾�f�[�^��ϐ��Ɋi�[���邽�߂̋L�q

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
//�u<>�v�L�����ƂɃX�v���b�g����֐��B���s�͖��������̂ŁA���s�݂̗̂v�f�͍쐬����Ȃ��B
//vector<string>�Ɋi�[���ĕԂ��B

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


////////////////////////////�񃁃��o///////////////////////////////////////

size_t CallbackFunc(char *ptr, size_t size, size_t nmemb, string *str)//�R�[���o�b�N�֐�
{
	int realsize=size*nmemb;
	str->append(ptr,realsize);//�i�[�H
	return realsize;
}
