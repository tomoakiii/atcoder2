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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll N,W,D;
    cin >> N >> W >> D;
    vector<ll> X(N),Y(N);
    map<pair<ll,ll>, int> ind;
    vector Grid(N,vector<int>{});
    int id = 0;
    ll div = D/2;
    if(div==0)div=1;
    rep(i,N) {
        cin>>X[i]>>Y[i];
        ll dx = X[i]/div;
        ll dy = Y[i]/div;
        if(!ind.contains({dx,dy})){
            ind[{dx,dy}]=id++;
        }
        int k = ind[{dx,dy}];
        Grid[k].push_back(i);

    }


    return 0;
}