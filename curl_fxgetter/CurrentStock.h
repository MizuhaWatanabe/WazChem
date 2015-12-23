//	CurrentStock.h
//	�����̌��݉��i�������N���X�B
//	�ꕔ�@�\��CurrentStock�Ƃ��Ԃ�i�ʓ|�ȋC�������̂Ōp���͂��Ă��Ȃ��j
//	�����I�ɂ͑��T�C�g�A���������������݌v��ڎw���Ă���B
//	���Ƃ��΂��̃N���X����CurrentStock_topix, CurrentStock_mothers�Ȃǂ�
//	�p�����Ă����Ƃ��c

#include <string>
#include <ctime>
#include "WebScraper.h"

#pragma once
using namespace std;

class CurrentStock
{	

	string verbose;//�璷���B�Q�Ɛ�̕\���ȂǂɁB
	time_t got_time;//�擾����
	int stock_code;//��ЃR�[�h

	double stock_price;//���i
	double order_bid;//�����i�[����Ƃ�	
	double order_ask;//�����i�[����Ƃ�

public:
	CurrentStock(void);
	CurrentStock(int);//�����Ȃ�R�[�h��ł�����Ŏn�߂���
	~CurrentStock(void);

	string get_verbose(void);
	time_t get_got_time(void);

	double get_stock_price(void);
	double get_order_bid(void);
	double get_order_ask(void);
	int get_stock_code(void);
	void set_stock_code(int);

	void LoadCurrentStock(void);
};

