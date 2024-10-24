#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (ll i = 0; i < (n); ++i)

typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const int INFi = 0x0F0F0F0F;


int main(){
    ll N;
    cin >> N;
    vector<ll> A(N);
    vector<string> S(N);
    rep(i,N) cin>>A[i];
    rep(i,N) cin>>S[i];
    vector dist(N, vector<int>(N, INFi));
    vector Sv(N, vector<ll>(N));

    rep(i,N) {
        dist[i][i] = 0;
        Sv[i][i] = A[i];
    }
    rep(i,N) rep(j,N) {
        if (S[i][j] == 'Y') {
            dist[i][j] = 1;  
            Sv[i][j] = A[i] + A[j];
        }
    }
    rep(k,N) rep(i,N) rep(j,N) {
        if (dist[i][j] > dist[i][k]+dist[k][j]){
            dist[i][j] = dist[i][k]+dist[k][j];
            Sv[i][j] = Sv[i][k]+Sv[k][j]-A[k];
        } else if (dist[i][j] == dist[i][k]+dist[k][j]) {
            Sv[i][j] = max(Sv[i][j], Sv[i][k]+Sv[k][j]-A[k]);
        }
        

    }
    
    int Q;
    cin >> Q;
    while(Q--) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        if (dist[u][v] >= INFi) cout << "Impossible" << endl;
        else   cout << dist[u][v] << " " << Sv[u][v] << endl;
    }
    return 0;
}