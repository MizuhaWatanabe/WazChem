#include <iostream>
#include <string>
#include <twitcurl.h>

using namespace std;

class Proc
{
    twitCurl twitterObj;
    string strConsumerKey, strConsumerSecret;
    string strAccessTokenKey, strAccessTokenSecret;
    string strReplyMsg;
public:
    Proc();                 // Constructor
    bool execMain(string);  // Main Process
};

Proc::Proc()
{
    strConsumerKey       = "ysnBDljCMPNlI0bsECBpGWBDI";
    strConsumerSecret    = "qKMwy3nkGiEDFBouNb1mBgMbs4Jy2fsNwJxokkLNLCoCfnsYh2";
    strAccessTokenKey    = "4618823672-fIKt5kNgtIpKWeYmRgnubXaZt8Fqwgy8lKWP1Jg";
    strAccessTokenSecret = "lxe3rPSW5haT9F1UCS4Mr5KFUdIaERgM5UI4wvjYnDC3I";
}

bool Proc::execMain(string strString)
{
    try {
        twitterObj.getOAuth().setConsumerKey(strConsumerKey);
        twitterObj.getOAuth().setConsumerSecret(strConsumerSecret);
        twitterObj.getOAuth().setOAuthTokenKey(strAccessTokenKey);
        twitterObj.getOAuth().setOAuthTokenSecret(strAccessTokenSecret);

        // Verify account credentials
        if (!twitterObj.accountVerifyCredGet()) {
            twitterObj.getLastCurlError(strReplyMsg);
            cerr << "\ntwitCurl::accountVerifyCredGet error:\n"
                 << strReplyMsg.c_str() << endl;
            return false;
        }

        // Post a message
        strReplyMsg = "";
        if (!twitterObj.statusUpdate(strString)) {
            twitterObj.getLastCurlError(strReplyMsg);
            cerr << "\ntwitCurl::statusUpdate error:\n"
                 << strReplyMsg.c_str() << endl;
            return false;
        }
    } catch (char *e) {
        cerr << "[EXCEPTION] " << e << endl;
        return false;
    }
    return true;
}

int main(int argc, char* argv[]){
    try {
        if (argc != 2) {
            cout << "Usage: ./Twitcurl sentence" << endl;
            return true;
        }
        Proc objMain;
        bool bRet = objMain.execMain(argv[1]);
        if (!bRet) cout << "ERROR!" << endl;
    } catch (char *e) {
        cerr << "[EXCEPTION] " << e << endl;
        return 1;
    }
    return 0;
}
