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
    map<ll, int> A;
    vector<ll> C(N);
    vector B(N+1, vector<ll>{});
    rep(i,N) {
        ll a; cin >> a;
        A[a]++;
    }
    rep(i,N) {
        ll b; cin>>b;
        B[b].push_back(i);
    }
    rep(i,N) {
        ll c;
        cin>>c;
        c--;
        C[c]++;
    }    
    ll ans = 0;
    for(auto a: A) {
        for(auto k: B[a.first]){
            ans+=C[k] * a.second;
        }
    }

    cout<<ans<<endl;
    return 0;
}