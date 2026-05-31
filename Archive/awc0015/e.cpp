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
    ll N,Q;
    cin >> N >> Q;
    vector<ll> P(N);
    rep(i,N) {
        cin>>P[i];
        P[i]--;
    }
    ll M=1e5;
    ll ln = sqrt(M);
    vector v(N,vector<tuple<ll,ll,int>>{});
    rep(i,Q) {
        ll x,y; cin>>x>>y;
        x--, y--;
        ll p = x/ln;
        v[p].push_back({y,x,i});
    }
    vector<ll> ans(Q);
    ll cy=0, cx=0;
    ll sm=0;
    vector<ll> cnt(N);
    cnt[P[0]]++;
    sm=1;
    rep(i,N) {
        if(i%2==0) sort(v[i].begin(),v[i].end());
        else sort(v[i].rbegin(),v[i].rend());
        for(auto [y,x,q]:v[i]) {
            while(y>cy) {
                cy++;
                if(cnt[P[cy]] == 0) sm++;
                cnt[P[cy]]++;
            }
            while(x<cx) {
                cx--;
                if(cnt[P[cx]] == 0) sm++;
                cnt[P[cx]]++;
            }
            while(y<cy){
                cnt[P[cy]]--;
                if(cnt[P[cy]] == 0) sm--;
                cy--;
            }
            while(x>cx){
                cnt[P[cx]]--;
                if(cnt[P[cx]] == 0) sm--;
                cx++;
            }
            ans[q] = sm;
        }
    }
    for(auto a:ans) cout<<a<<endl;
    return 0;
}