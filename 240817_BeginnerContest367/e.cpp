#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)

typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const int INFi = 0x0F0F0F0F;

int main(){
    ll N,K;
    cin >> N >> K;    
    vector<int> X(N), A(N, 0);
    rep(i,N) {
        cin>>X[i];
        X[i]--;
    }
    rep(i,N) cin>>A[i];
    vector XP(61, vector<int>(N));
    XP[0] = X;
    for(int i=1; i<61; i++){
        vector B = A;
        rep(j, N) {
            XP[i][j] = XP[i-1][XP[i-1][j]];
        }
    }

    rep(k, 61){
        if ((K>>k) & 1){    
            vector B = A;
            rep(i, N) B[i] = A[XP[k][i]];
            swap(A, B);
        }
    }
    rep(i, N) cout << A[i] << " ";
    cout << endl;
    return 0;
}