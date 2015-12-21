#include <iostream>
#include <curl/curl.h>
#include <string>
#include <vector>
//#include <algorithm>

using namespace std;

size_t callBackFunc(char *ptr, size_t size, size_t nmemb, string *str)
{
	int realsize=size*nmemb;
	str->append(ptr,realsize);//‚±‚±‚Å‘‚«ž‚Ý‚ðs‚¤‚ç‚µ‚¢B
	return realsize;//‚È‚­‚Ä‚à‚¢‚¢‚Ì‚©cH
}


vector<string> tagsplitter(string &str)
{
	
	vector<string> res;
	//size_t current=0;
	size_t current=str.find_first_not_of("\n<>",1);
	size_t found;



	//‚Í‚¶‚ß‚Í‚©‚È‚ç‚¸<>\n‚Ì‚Ç‚ê‚©‚È‚Ì‚Åc

	
	while((found=str.find_first_of("\n<>",current)) != string::npos){ 
		
		//cout<<str.find_first_not_of("\n<>",found)<<","<<found<<","<<current<<endl;
		res.push_back(string(str,current,found-current));
		//current=found+1;
		if(str.find_first_not_of("\n<>",found) != string::npos){
			current=str.find_first_not_of("\n<>",found);
		}
		else break;
		

	}
    res.push_back(string(str, current, str.size() - current));
	return res;
}



int main(void)
{
  CURL *curl;
  CURLcode res;

  for(int k=0;k<1000;k++){

  string hozonsaki;


  curl = curl_easy_init();
  if(curl) {
    curl_easy_setopt(curl, CURLOPT_URL, "http://info.finance.yahoo.co.jp/fx/detail/?code=USDJPY=FX");
    /* example.com is redirected, so we tell libcurl to follow redirection */ 
    curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
 

	//string‚ÉŠi”[‚·‚é‚½‚ß‚ÌƒR[ƒ‹ƒoƒbƒNŠÖ”‚Æ•Û‘¶æ‚ÌŽw’è

	curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, callBackFunc);
	curl_easy_setopt(curl, CURLOPT_WRITEDATA, &hozonsaki);


    /* Perform the request, res will get the return code */ 
    res = curl_easy_perform(curl);

    /* Check for errors */ 
    if(res != CURLE_OK)
      fprintf(stderr, "curl_easy_perform() failed: %s\n",
              curl_easy_strerror(res));
 
	////////////ŒŸõ‚Æo—Í

	vector<string> ans=tagsplitter(hozonsaki);

	vector<string>::iterator cIter=find(ans.begin(), ans.end(), "dd id=\"USDJPY_detail_bid\"");

	size_t index=distance(ans.begin(),cIter);
	cout<<stoi("0"+ans[(int)index+1])+(double)stod("0."+ans[(int)index+3])+(double)stod("0.00"+ans[(int)index+5])<<endl;
	

    /* always cleanup */ 
    curl_easy_cleanup(curl);
  }
  Sleep(10000);
  }
  return 0;
}