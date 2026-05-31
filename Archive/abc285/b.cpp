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
    cin >> S;
    for(int i=1; i<=N-1; i++) {
        bool flg = true;
        ll cnt = 0;
        for(int j=0; (i+j)<N; j++) {
            if (S[j] == S[i+j]) {
                flg = true;
                break;
            }
            cnt++;
        }
        cout << cnt << endl;
    }

    return 0;
}