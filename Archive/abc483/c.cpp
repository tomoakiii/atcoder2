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
    vector<ll> A(M), B(M);
    vector<map<ll,ll>> nex(N);
    vector<ll> cnt(N);
    vector<pair<ll,ll>> mx(2, {0,INF});
    rep(i,M) {
        int a,b; cin>>a>>b; a--,b--;
        nex[a][b]++;
        cnt[a]++;
    }
    rep(i,N){
        chmin(mx[1], {-cnt[i], i});
        sort(mx.begin(), mx.end());
    }
    rep(i,N){
        pair<ll,ll> ans;
        if(i==mx[0].second){
            ans = mx[1];
        } else {
            ans = mx[0];
        }
        ans.first *= -1;
        for(auto [nx, v]:nex[i]){
            ll nc = cnt[nx] + v;
            if( (nc > ans.first) || ( nc == ans.first && nx <= ans.second ) ) {
                ans = {cnt[nx] + v, nx};
            }
        }
        cout << ans.second+1 << endl;
    }
    return 0;
}