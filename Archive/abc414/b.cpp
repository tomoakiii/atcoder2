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
    ll N;
    cin >> N;
    string S; 
    int tc = 0;
    rep(i,N) {
        char c;
        int l;
        cin >> c >> l;
        tc += l;
        if(tc > 100) {
            cout << "Too Long" << endl;
            return 0;
        }
        rep(j,l) {
            S.push_back(c);
        }
    }
    cout << S << endl;
    return 0;
}