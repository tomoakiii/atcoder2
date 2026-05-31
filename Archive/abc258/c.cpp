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
    ll N, Q;
    cin >> N >> Q;
    string S;
    cin >> S;
    int ofs = 0;
    while(Q--) {
        int t, x;
        cin >> t >> x;        
        if(t == 1) {
            ofs += N-x;
            ofs %= N;
        } else {
            x--;
            x += ofs;
            x %= N;
            cout << S[x] << endl;
        }
    }

    return 0;
}