#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;


int main(){
    int N, M;
    cin >> N >> M;
    vector<vector<ll>> A(N, vector<ll>(N));
    for(auto &a1: A) for(auto &a: a1) cin >> a;
    vector<vector<ll>> smh(N, vector<ll>(N, 0));
    for(int i=0; i<N; i++) {
        smh[i][0] = A[i][0];
        for(int j=1; j<N; j++){
            smh[i][j] = smh[i][j-1] + A[i][j];
        }
    }
    
    vector<vector<ll>> smv(N, vector<ll>(N, 0));
    for(int j=0; j<N; j++){
        smv[0][j] = A[0][j];
        for(int i=1; i<N; i++) {
            smv[i][j] = smv[i-1][j] + A[i][j];
        }
    }

    vector<vector<ll>> sma(N, vector<ll>(N, 0));
    for(int i=0; i<M; i++)
        sma[0][0] += smh[i][M-1];
    }
        
    for(int j=1; j<N-M; j++){
        sma[0][j] = sma[0][j-1] - (smv[M-1][j-1]);
        sma[0][j] += smv[M-1][j];
    }
    
    for(int i=1; i<N-M; i++){
        sma[i][0] = sma[i-1][0] - (smh[i-1][M-1]);
        sma[0][j] += smh[i][M-1];
    }
    
    for(int i=1; i<N-M; i++){
        for(int j=1; j<N-M; j++){
            sma[i][j] = sma[i][j-1] - (smv[i+M-1][j-1] - smv[i-1][j-1]);
            sma[i][j] += (smv[i+M-1][j] - smv[i-1][j]);
        }
    }

    ll sa, sb, sc;
    for(int i=0; i<N; i++) for(int j=0; j<N; j++){
        sa = sma[i][j];
        for()
    }

    return 0;
}