#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)

typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const int INFi = 0x0F0F0F0F;

int main(){
    string S, T;
    cin >> S >> T;
    vector<int> nS('z' - 'a' + 1);
    vector<int> nT('z' - 'a' + 1);
    int aS = 0, aT = 0;
    for(auto c:S) {
        if (c=='@') aS++;
        else nS[c-'a']++;
    }
    for(auto c:T) {
        if (c=='@') aT++;
        else nT[c-'a']++;
    }
    string atc = "atcoder";
    for(char c=0; c <= 'z'-'a'; c++) {
        bool atflag = false;
        for (auto p: atc) {
            if (p-'a' == c) atflag = true;
        }
        if (atflag) {
            if (nS[c] > nT[c]) aT -= (nS[c] - nT[c]);
            else if (nS[c] < nT[c]) aS -= (nS[c] - nT[c]);
        } else {
            if (nS[c] != nT[c]){
                cout << "No" << endl;
                return 0;
            }
        }
    }
    if (aT >= 0 && aS >= 0) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}