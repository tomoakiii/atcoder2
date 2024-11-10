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
    ll N, K;
    cin >> N >> K;
    string S;
    cin >> S;

    ll cnt = 0;
    rep(i,N-K+1) {
        bool flg = true;
        for(int j=i; j<i+K; j++) {
            if (S[j] == 'X')  {
                flg = false;
            }
        }
        if(flg) {
            cnt++;
            for(int j=i; j<i+K; j++) {
                S[j] = 'X';
            }
        }
    }
    cout << cnt << endl;
    return 0;
}