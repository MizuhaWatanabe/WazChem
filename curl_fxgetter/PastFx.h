
#include <curl/curl.h>
#include <string>

#pragma once
using namespace std;

class PastFx
{
public:
	PastFx(void);
	~PastFx(void);
	string hozonsaki;

	void Scraper(void);
	

};


size_t cbf(char* , size_t , size_t , string*);