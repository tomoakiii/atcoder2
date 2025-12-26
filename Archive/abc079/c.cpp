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
    vector<ll> A;
    for(auto c: S) {
        A.push_back(c-'0');
    }
    rep(k, 1<<3) {
        ll ans = A[0];
        rep(p, 3) {
            if(k>>p & 1) {
                ans += A[p+1];
            } else {
                ans -= A[p+1];
            }
        }
        if(ans == 7) {
            string T;
            T.push_back('0' + A[0]);
            rep(p,3) {
                if(k>>p & 1) T.push_back('+');
                else T.push_back('-');
                T.push_back('0' + A[p+1]);
            }
            cout<<T<<"=7"<<endl;
            return 0;
        }
    }

    return 0;
}