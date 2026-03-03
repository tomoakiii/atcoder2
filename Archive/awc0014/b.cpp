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
    ll N,V;
    cin >> N >> V;
    vector<ll> D(N), T(N);
    rep(i,N-1) cin>>D[i];
    rep(i,N-1) {
        cin>>T[i];
    }


    __int128_t sm = 0;
    vector<int> ans;
    rep(i,N-1) {
        sm += D[i];
        __int128_t x;
        x=T[i];
        x=x*V;
        if(sm < x) ans.push_back(i+2);
    }
    if(ans.empty()) cout<<-1<<endl;
    else {
        for(auto a:ans) cout<<a<<" ";
        cout<<endl;
    }
    return 0;
}