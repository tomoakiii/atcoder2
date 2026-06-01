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
    vector<tuple<ll,ll,ll>> v(N);
    rep(i,N) {
        ll A,B; cin>>A>>B;
        v[i]=make_tuple(B,A,-i);
    }
    sort(v.rbegin(),v.rend());
    for(auto [a,b,i]:v){
        cout<<(-i)+1<<endl;
    }
    return 0;
}