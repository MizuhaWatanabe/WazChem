#include "WebScraper.h"



//////////////////////////�R���X�g���N�^//////////////////////////

WebScraper::WebScraper()
{
}

WebScraper::WebScraper(string)
{
}

WebScraper::~WebScraper(void)
{
}

//////////////////////////�A�N�Z�b�T////////////////////////////////

void set_url(string);//�ꉞ�Z�b�^�[��݂��邪�A�g���@��͂Ȃ������H
	void LoadHtml(void);
	void LoadHtml(string);//����url�ł����ރ^�C�v
	void SplitHtml(void);

	string get_html(void);//html�̃A�N�Z�T
	vector<string> get_splitted_tag(void);//�X�v���b�g�����z��ւ̃A�N�Z�T

