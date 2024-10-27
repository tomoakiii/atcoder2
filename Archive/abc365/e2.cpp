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
    vector<ll> A(N), LAST(N+1);
    rep(i, N) {
        cin >> A[i];
    }
    ll ans = 0;
    ll last = 0;
    ll SM = 0;
            
    LAST[0] = A[0] ^ A[1];
    SM += LAST[0];
    for(int i=1; i<N-1; i++) {
        LAST[i] = LAST[i-1]^A[i-1];
        LAST[i] = LAST[i]^A[i+1];
        SM += LAST[i];
    }
    for (int k=3; k<=N; k++){
        for (int j=0 ; j<=N-k; j++) {
            LAST[j] = LAST[j] ^ A[j+k-1];
            SM += LAST[j];
        }
    }
        
    cout << SM << endl;
    return 0;
}