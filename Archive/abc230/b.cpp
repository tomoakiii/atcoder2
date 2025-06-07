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
    char d[] = {'o', 'x', 'x'};
    rep(st,3){
        int id = st;
        bool flg = true;
        rep(i, S.size()) {
            if(S[i] != d[id]) {
                flg = false;
                break;
            }
            id++;
            id %= 3;
        }
        if(flg) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;            
    return 0;
}