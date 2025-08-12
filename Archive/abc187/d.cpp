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
    ll Aoki = 0;
    vector<ll> B2A(N);
    rep(i,N){
        ll a,b; cin>>a>>b;
        Aoki += a;
        B2A[i] = 2*a + b;
    }
    sort(B2A.rbegin(), B2A.rend());
    rep(i,N) {
        Aoki -= B2A[i];
        if(Aoki < 0) {
            cout<<i+1<<endl;
            return 0;
        }
    }    
    return 0;
}