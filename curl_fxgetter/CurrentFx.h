//	CurrentFx.h
//	�I���^�C���̈בփ��[�g���擾����N���X�B
//	�܂�yahoo,���̂����e�БΉ���ڎw��

 
#include "WebScraper.h"
#include <string>
#include <vector>
#include <iostream>
#include <ctime>

#pragma once




class CurrentFx
{
	string verbose;//�璷���B�Q�Ɛ�̕\���ȂǂɁB

	time_t got_time;//�擾����
	
	string currency_pair;//�ǂނׂ��y�A�����߂�

	double bid_price;//Bid�̐��l
	double ask_price;//Ask�̐��l
	

public:
	CurrentFx(void);
	CurrentFx(string);//�����Ȃ�ʉ݃y�A���w�肷��z
	~CurrentFx(void);

	void set_currency_pair(string);
	string get_currency_pair(void);
	string get_verbose(void);
	double get_bid_price(void);
	double get_ask_price(void);
	time_t get_got_time(void);

	void LoadCurrentFx(void);

};

