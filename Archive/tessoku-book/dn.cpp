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
typedef pair<ll, pair<int,int>> pl;
typedef modint1000000007 mint;

int main(){
    ll X,Y;cin>>X>>Y;
    vector<pair<ll,ll>> ans;
    while(X>1 || Y>1) {
        ans.emplace_back(X,Y);
        if(X>Y) X-=Y;
        else Y-=X;
    }
    cout << ans.size() << endl;
    reverse(ans.begin(),ans.end());
    for(auto [x,y]:ans) {
        cout << x << " " << y << endl;
    }
    return 0;
}