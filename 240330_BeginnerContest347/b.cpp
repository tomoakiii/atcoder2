#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;


int main(){
    string S;
    map<string, int> sS;
    cin >> S;
    int cnt = 0;
    for (int i=0; i<S.size(); i++){
        string tS = "";
        for (int j=i; j<S.size(); j++){
            tS = tS + S[j];            
            if (sS.find(tS) == sS.end()){
                cnt++;
                sS[tS]++;
            }
        }
    }
    cout << cnt << endl;
    return 0;
}