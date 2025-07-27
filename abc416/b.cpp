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
    string S;
    cin>>S;
    int mode = 0;
    
    rep(i, S.size()) {
        if(S[i] == '#') {
            if (mode == 0) {
                //
            } else if (mode == 1) {
                mode = 2;
            } else if (mode == 2) {

            }
        } else {
            if(mode == 0) {
                S[i] = 'o';
                mode = 1;
            } else if (mode == 1) {
                //
            } else if (mode == 2) {
                S[i] = 'o';
                mode = 1;
            }
        }
    }
    cout << S << endl;
    return 0;
}