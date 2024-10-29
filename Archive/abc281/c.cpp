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
    ll N, T;
    cin >> N >> T;
    vector<ll> A(N, 0);
    ll ttl = 0;
    rep(i,N) {
        cin>>A[i];
        ttl += A[i];
    }
    T %= ttl;
    ll cnt = 0, sm = 0;
    while(sm < T){
        if (sm + A[cnt] > T) {
            cout << cnt+1 << " " << T - sm << endl;
            return 0;
        }
        sm += A[cnt];
        cnt++;
    }     
    return 0;
}