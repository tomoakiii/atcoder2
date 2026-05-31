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

int main(){
    ll N; cin>>N;
    vector<pair<ll,ll>> RL(N);
    rep(i,N) cin>>RL[i].second>>RL[i].first;
    sort(RL.begin(),RL.end());
    ll ed = 0;
    ll ans = 0;
    for(auto [r,l]:RL) {
        if(l >= ed) {
            ans++;
            ed = r;
        }
    }
    cout << ans << endl;
    return 0;
}