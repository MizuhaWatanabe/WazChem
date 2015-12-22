#include "PastFx.h"
#include <iostream>

PastFx::PastFx(void)
{
	hozonsaki="aaa";
}


PastFx::~PastFx(void)
{
}

void PastFx::Scraper(void)
{
	CURL *curl = curl_easy_init();
	if(curl) {
		CURLcode res;
		curl_easy_setopt(curl, CURLOPT_URL, "http://info.finance.yahoo.co.jp/fx/list/");
            // CURLOPT_WRITEFUNCTION �ɃR�[���o�b�N�֐����w��
            curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, cbf);
            // CURLOPT_WRITEDATA �ɃR�[���o�b�N�֐��ɂď������ꂽ���Ƃ̃f�[�^�i�[�|�C���^���w��
            curl_easy_setopt(curl, CURLOPT_WRITEDATA, (string*)&hozonsaki);
            // ���N�G�X�g���s
            res = curl_easy_perform(curl);

		
		//res = curl_easy_perform(curl);
		curl_easy_cleanup(curl);
	}
}


size_t cbf(char* ptr, size_t size, size_t nmemb, string* stream) {
    int realsize = size * nmemb;
    stream->append(ptr, realsize);
    return realsize;
}
