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
    vector A(N, vector<int>(N));
    string s;
    rep(i, N){
        string s;
        cin >> s;
        rep(j, N){
            A[i][j] = s[j] - '0';
        }
    }
    vector B = A;
    for(int i=1; i<N;i++){
        B[0][i] = A[0][i-1];
    }
    for(int i=1; i<N;i++){
        B[i][N-1] = A[i-1][N-1];
    }
    for(int i=N-2; i>=0; i--){
        B[N-1][i] = A[N-1][i+1];
    }    
    for(int i=N-2; i>=0; i--){
        B[i][0] = A[i+1][0];
    }
    for(int i=0; i<N;i++){
        for(int j=0; j<N;j++) {
            cout << B[i][j];
        }
        cout << endl;
    }
    return 0;
}