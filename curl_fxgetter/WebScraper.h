//	WebScraper.h					
//	web�X�N���C�v���s�����߂̃N���X	   
//	�R�[���o�b�N�֐��̂݃����o�ɂł��Ă��Ȃ��͍̂���̉ۑ�B

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
	WebScraper(string);//�͂��߂���url�ǂݍ��ރ^�C�v�̃R���X�g���N�^
	~WebScraper(void);
	
	void set_url(string);//�ꉞ�Z�b�^�[��݂��邪�A�g���@��͂Ȃ������H
	void LoadHtml(void);
	void LoadHtml(string);//����url�ł����ރ^�C�v
	void SplitHtml(void);

	string get_html(void);//html�̃A�N�Z�T
	vector<string> get_splitted_tag(void);//�X�v���b�g�����z��ւ̃A�N�Z�T

};


size_t CallbackFunc(char*, size_t, size_t, string*);//curl�����o���p�̃R�[���o�b�N�֐�
