#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)
typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const int INFi = 0x0F0F0F0F;

int main(){
    ll N;
    cin >> N;
    vector<int> A(N, 0);
    vector M(3, vector<int>(N));
    vector X(3, vector<int>(N));

    rep(i, N){
        cin >> A[i];
    }
    
    vector<ll> score((1<<3) + 1, 0);    
    score[1<<0] = 1;
    score[(1<<0) | (1<<1)] = 2;
    score[(1<<2) | (1<<1) | (1<<0)] = 3;
    score[(1<<0) | (1<<2)] = 1;

    string S;
    cin >> S;
    rep(i, N){
        if (S[i] == 'M') M[A[i]][i]++;
        if (S[i] == 'X') X[A[i]][i]++;
    }
    rep(i, N-1){
        rep (j, 3){
            M[j][i+1]+=M[j][i];            
        }
    }
    for(int i=N-1; i>=1; i--){
        rep (j, 3){
            X[j][i-1]+=X[j][i];            
        }
    }
    ll sm = 0;
    rep(i, N){        
        if (S[i] == 'E'){
            int m = 1<<A[i];
            rep (j, 3) {
                int mm = m;
                mm |= 1<<j;
                rep (k, 3) {
                    int mmm = mm;
                    mmm |= 1<<k;
                    sm += score[mmm] * M[j][i] * X[k][i];
                }
            }
        }
    }

    cout << sm << endl;
    return 0;
}