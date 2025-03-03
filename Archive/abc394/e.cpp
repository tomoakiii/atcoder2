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
typedef pair<int, int> pii;
int main(){
    ll N;
    cin >> N;
    vector<string> C(N);
    rep(i,N) cin>>C[i];

    vector dist(N, vector<ll>(N, INF));
    rep(i,N) dist[i][i] = 0;    
    set<pii> vp, vp2;
    rep(i,N) rep(j,N) {
        if(C[i][j] == '-') continue;
        chmin(dist[i][j], (ll)1);
        vp.insert({i, j});
    }
    rep(i,N) rep(j,N) {
        if(C[i][j] == '-') continue;
        rep(k, N) {
            if(C[i][j] == C[j][k]){
                chmin(dist[i][k], (ll)2);
                vp2.insert({i, k});
            }
        }
    }
    int a = 1;
    bool flg = true;
    while(flg) {
        flg = false;
        set<pii> vp3, vp4;
        for(auto [from, to]: vp) {
            rep(i, N) {
                char c = C[i][from];
                if(c == '-') continue;
                rep(j, N) {        
                    if(c != C[to][j]) continue;
                    if(chmin(dist[i][j], (ll)(a+2))) {
                        flg = true;
                        vp3.insert({i, j});
                    }
                }
            }
        }

        for(auto [from, to]: vp2) {
            rep(i, N) {
                char c = C[i][from];
                if(c == '-') continue;
                rep(j, N) {        
                    if(c != C[to][j]) continue;
                    if(chmin(dist[i][j], (ll)(a+3))) {
                        flg = true;
                        vp4.insert({i, j});
                    }
                }
            }
        }
        a += 2;
        swap(vp, vp3);
        swap(vp2, vp4);
    }

    rep(i,N) {        
        rep(j,N) {
            if(dist[i][j] == INF) printf("-1 ");
            else printf("%lld ", dist[i][j]);
        }            
        printf("\n");
    }
    return 0;
}


