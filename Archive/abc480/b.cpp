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
    vector<string> S(N);
    rep(i,N) cin>>S[i];
    vector<ll> ans(N);
    rep(kkk,M){
        string T; cin>>T;
        int j;
        ll nm = 0;
        rep(i,N){
            ll cnt=0;
            if(S[i].size()!=T.size())continue;
            rep(j,S[i].size()){
                if(S[i][j]!=T[j])cnt++;
            }
            if(cnt==0){
                ans[i]++;
                nm=INF;
                break;
            } else if(cnt == 1){
                nm++;
                j = i;
            }
        }
        if(nm==1){
            ans[j]++;
        }
    }
    rep(i,N)cout<<ans[i]<<endl;
    return 0;
}