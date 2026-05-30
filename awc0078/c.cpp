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
    vector<pair<ll,int>> L(N);
    rep(i,N) {
        cin>>L[i].first;
        L[i].second=i;
    }

    sort(L.begin(),L.end());
    fenwick_tree<ll> FT(N);
    rep(i,N)FT.add(i,1);
    for(auto [l,i]:L){
        cout<<FT.sum(0,i+1)<<endl;
        FT.add(i,-1);
    }

    return 0;
}