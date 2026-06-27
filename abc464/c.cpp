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
    ll N,M;
    cin >> N >> M;
    vector vec(M, vector<tuple<ll,ll,int>>{});
    unordered_map<ll,ll> mp;
    rep(i,N){
        ll a,d,b;
        cin>>a>>d>>b;
        d--;
        mp[a]++;
        vec[d].push_back(make_tuple(a,b,i));
    }
    rep(i,M) {
        for(auto [a,b,j] : vec[i]){
            mp[a]--;
            if(mp[a]==0) mp.erase(a);
            mp[b]++;
        }
        cout<<mp.size()<<endl;
    }
    return 0;
}