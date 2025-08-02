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
    ll N,M;
    cin >> N >> M;
    multiset<ll> A;
    vector<ll> B(M);
    rep(i,N) {
        ll a; cin >> a;
        A.insert(a);
    }
    rep(i,M) {
        ll b; cin>>b;
        if(A.contains(b)) A.erase(A.find(b));
    }
    for(auto a: A) cout<<a<<" ";
    cout<<endl;
    return 0;
}