#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)

typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const int INFi = 0x0F0F0F0F;

int main(){
    ll N, M;
    cin >> N >> M;
    vector<string> S(N);
    rep(i,N) cin >> S[i];
    vector dist(N, vector<int>(N));
    rep(i,N-1) for(int j=i+1; j<N; j++){
        int d = 0;
        rep(k, M){
            if(S[i][k] != S[j][k]) d++;
        }
        dist[i][j] = dist[j][i] = d;        
    }
        
    
    rep(k, N){
        vector<bool> b(N, false);  
        auto f = [&](auto f, int cur, int a)->void{
            if (a==N-1) {
                cout << "Yes" << endl;
                exit(0);
            }
            rep(i, N) {
                if (b[i]) continue;
                b[i] = true;
                if (dist[cur][i] == 1) {
                    f(f, i, a+1);
                }
                b[i] = false;
            }
        };
        f(f, k, 0);
    }
    
    cout << "No" << endl;
    return 0;
}