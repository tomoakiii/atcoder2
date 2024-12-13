#include <bits/stdc++.h>
using namespace std;





int main(){
    /*
    vector<string> S = {
        "FFFFFD3EFFFFA92F000027BCFD472D00ACDCFFF5A8000000",
        "0000001300005ABB00001D5900022B0017B2000312000000",
        "FFFFD68D0000165000002CF601567D00F0F80015B500032A",
        "000027C90000158E00002CA3FE830B00E681FFE2C30001E7",
    };
    */
   vector<string> S = {"FFFFFDA9FFFFA7BE000027AC02C75500AFDCFFF4BC000000"};
    vector<int> len = {8,8,8,6,6,6,6};
    vector<string> type = {"s32", "s32", "s32", "s24", "s24", "s24", "s24"};
    for(int i=0; i<S.size(); i++) {
        int ind = 0;
        for(int k=0; k<len.size(); k++){
            string t = "";            
            for (int j = 0; j < len[k]; j++){
                t += S[i][ind++];
            }
            int x;
            if(type[k] == "s32") {
                sscanf(t.c_str(), "%x", &x);
            } else if(type[k] == "s24") {
                if (('8'<=t[0] && t[0]<='9') || ('A'<=t[0] && t[0]<='F')) {
                    t = "FF" + t;
                }
                sscanf(t.c_str(), "%x", &x);
            }
            cout << t << endl << x << endl;
        }
        cout << "-----------" << endl;
    }
    return 0;
}
