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
    ll H,W,M;
    cin >> H >> W >> M;
    vector<ll> A(H),B(W);
    rep(i,H) cin>>A[i];
    rep(i,W) cin>>B[i];
    vector<tuple<ll,ll,bool>> RCT(M), CRT(M);
    rep(i,M){
        ll r,c; bool t;
        cin>>r>>c>>t;
        r--,c--;
        RCT[i] = make_tuple(r,c,t);
        CRT[i] = make_tuple(c,r,t);
    }
    ll ans = INF;
    rep(kkk,2){
        map<ll, bool> RC[H], CR[H], RCvis[H];
        vector<bool> Rvis(H), Cvis(W);
        for(auto [r,c,t] : RCT){
            Rvis[r]=false;
            Cvis[c]=false;
            RC[r][c]=0;
            CR[c][r]=0;
        }
        ll tmp = 0;
        ll cnt = 0;
        for(auto [r,c,t] : RCT){
            if(RC[r][c] != t){
                if(!Rvis[r] && !RCvis[r][c]){
                    Rvis[r] = true;
                    tmp += A[r];
                    cnt++;
                    for(auto &[v,x]:RC[r]){
                        x = !x;
                        CR[v][r]=x;
                        RCvis[r][c]=true;
                    }
                } else if(!Cvis[c] && !RCvis[r][c]) {
                    Cvis[c] = true;
                    tmp += B[c];
                    cnt++;
                    for(auto &[v,x]:CR[c]){
                        x = !x;
                        RC[v][c]=x;
                        RCvis[v][c]=true;
                    }
                } else {
                    cout << -1 << endl;
                    return 0;
                }
            }
        }
        if(cnt%2==0) chmin(ans, tmp);
        swap(RCT,CRT); swap(A,B), swap(H,W);
    }
    if(ans == INF) cout << -1 << endl;
    else cout << ans << endl;
    return 0;
}