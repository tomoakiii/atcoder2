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
        
    
    vector<int> ord(N);
    iota(ord.begin(), ord.end(), 0);
    bool fans=false;
    do {
        bool ans=true;
		rep(i, N-1) {
            if (dist[ord[i]][ord[i+1]] != 1) {
                ans=false;
            }
        }
        if(ans) {
            fans=true;
            break;
        }
	} while (next_permutation(ord.begin(), ord.end()));
    
    
    cout << (fans?"Yes":"No") << endl;
    return 0;
}