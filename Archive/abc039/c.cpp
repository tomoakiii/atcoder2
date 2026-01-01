#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (ll i = 0; i < (n); ++i)
template<typename T> inline bool chmax(T &a, T b) { return ((a < b) ? (a = b, true) : (false)); }
template<typename T> inline bool chmin(T &a, T b) { return ((a > b) ? (a = b, true) : (false)); }

typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const int INFi = 0x0F0F0F0F;

int main(){
    string S; cin>>S;
    string T = "WBWBWWBWBWBW";
    vector<string> ans = {"Do","Do", "Re", "Re", "Mi", "Fa", "Fa", "So", "So", "La", "La", "Si", "Si"};
    rep(i,T.size()) {
        bool flg = true;
        rep(j, S.size()) {
            if(T[(i+j)%T.size()] != S[j]) {
                flg = false;
                break;
            }
        }
        if(flg) {
            cout << ans[i] << endl;
            return 0;
        }
    }
    return 0;
}