#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)

typedef unsigned long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const int INFi = 0x0F0F0F0F;

int main(){
    ll N, M;
    cin >> N >> M;
    vector<ll> A(N, 0);
    vector<ll> rM(M);
    ll rnd=0;
    rep(i,N) {
        cin>>A[i];
        rnd+=A[i];
        rnd %= M;
    }
    
    ll sm=0;
    for(int i=0; i<N-1; i++){
        sm += A[i];
        sm %= M;
        rM[sm]++;
    }

    ll ans = rM[0];
    sm = A[0];
    sm %= M;
    rM[sm]--;
    ll sm2 = rnd;
    rM[sm2%M]++;
    ans += rM[sm];
    for(int i=1; i<N-1; i++){
        sm += A[i];
        sm %= M;
        rM[sm]--;
        sm2 += A[i-1];
        sm2 %= M;
        rM[sm2]++;
        ans += rM[sm];
    }

    
    cout << ans << endl;
    return 0;
}