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
    int M=0;
    cin >> N;
    vector<string> S(N);
    rep(i,N){
        cin >> S[i];
        M = max(M, (int)S[i].size());
    }
    vector T(M, vector<char>(N, '*'));
    rep(i,N) rep(j, S[i].size()) {
        T[j][N-i-1] = S[i][j];
    }
    rep(i, M) for(int j=T[i].size()-1; j>=0; j--){
        if(T[i][j] == '*') T[i][j] = '\n';
        else break;
    }
    rep(i, M) {
        rep(j, T[i].size()){
            cout<<T[i][j];
        }
        cout << endl;
    }

    return 0;
}