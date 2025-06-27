#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)
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


void disp(vector<vector<char>> &A) {
    rep(i,A.size()) {
        rep(j,A[i].size()) {
            cout<<A[i][j];
        }
        cout<<endl;
    }
}

int main(){
    ll N;
    cin >> N;
    vector S(N, vector<char>(N));
    auto T = S;
    rep(i,N)rep(j,N) {
        cin>>S[i][j];
    }
    int y = INFi, x = INFi, ye = 0, xe = 0;
    rep(i,N)rep(j,N) {
        cin>>T[i][j];
        if(T[i][j] == '#'){
            chmin(y, i);
            chmin(x, j);
            chmax(ye, i);
            chmax(xe, j);
        }
    }
    
    rep(k,4) {
        auto B = imrotate(S, k);        
        int y2 = INFi, x2 = INFi, ye2 = 0, xe2 = 0;
        rep(i,N)rep(j,N) {
            if(B[i][j] == '#'){                
                chmin(y2, i);
                chmin(x2, j);
                chmax(ye2, i);
                chmax(xe2, j);
            }
        }
        bool flg = true;
        if(ye-y != ye2-y2 || xe-x != xe2-x2) {
            continue;
        }
        for(int i = y, i2 = y2 ; i <= ye; i++, i2++) {
            for(int j = x, j2 = x2; j <= xe; j++, j2++) {
                if(T[i][j] != B[i2][j2]) {
                    flg = false;
                }                
            }            
        }
        if(flg) {
            cout<<"Yes"<<endl;
            return 0;
        }
    }
    cout<<"No"<<endl;
    return 0;
}