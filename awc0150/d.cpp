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

vector<vector<char>> imrotate(vector<vector<char>> A, int d){
    if(d==0) {
        return A;
    }
    int N = A.size();
    if(N==0)return A;
    int M = (int)A[0].size();
    vector<vector<char>> B;
    if(d==1 || d==3) B.resize(M,vector<char>(N));
    else B.resize(N,vector<char>(M));

    if(d == 1) { // 90deg
        for(int i=0;i<N;i++) for(int j=0;j<A[i].size();j++) B[j][N-1-i]=A[i][j];
    } else if (d == 3) { // 270deg
        for(int i=0;i<N;i++) for(int j=0;j<A[i].size();j++) B[M-1-j][i]=A[i][j];
    } else { // 180 deg
        for(int i=0;i<N;i++) for(int j=0;j<A[i].size();j++) B[N-1-i][M-1-j]=A[i][j];
    }
    return B;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll N,K,Q;
    cin >> N >> K >> Q;
    vector S(N,vector<char>(N));
    rep(i,N)rep(j,N) cin>>S[i][j];
    while(Q--){
        int r,c; cin>>r>>c;
        r--,c--;
        vector T(K,vector<char>(K));
        rep(i,K)rep(j,K)T[i][j]=S[i+r][j+c];
        T=imrotate(T,1);
        rep(i,K)rep(j,K) S[i+r][j+c]=T[i][j];
    }
    rep(i,N) {
        rep(j,N) cout<<S[i][j];
        cout<<endl;
    }

    return 0;
}