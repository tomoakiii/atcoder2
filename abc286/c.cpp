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
    ll N, A, B;
    cin >> N >> A >> B;
    string S;
    cin >> S;
    ll minA = INF;

    int st = 0;
    int ed = N-1;
    rep(i, N) {
        ll cnt = 0;
        rep(j, (N+1)/2) {
            if (S[(st+j)%N] != S[(ed-j)%N]) cnt++;
        }
        chmin(minA, A*i + B*cnt);
        st++, ed++;        
    }

    cout << minA << endl;
    return 0;
}