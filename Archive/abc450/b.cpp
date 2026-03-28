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
    ll N;
    cin >> N;
    vector C(N,vector<ll>(N));
    int K=1;
    rep(i,N-1) {
        for(int j=K;j<N;j++) {
            cin>>C[i][j];
            C[j][i]=C[i][j];
        }
        K++;
    }
    rep(a,N) {
        for(int b=a+1; b<N; b++) {
            for(int c=b+1; c<N; c++) {
                if(C[a][c] > C[a][b]+C[b][c] ){
                    cout<<"Yes"<<endl;
                    return 0;
                }
            }
        }
    }
    cout<<"No"<<endl;
    return 0;
}