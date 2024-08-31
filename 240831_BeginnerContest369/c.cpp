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
    vector<ll> A(N, 0);
    rep(i,N) cin>>A[i];
    if (N==1) {
        cout << 1 << endl;
        return 0;
    }
    vector<ll> cnt(N+1);
    ll clen = 2, cdel = A[1]-A[0];
    for(int i=2; i<N; i++) {
        ll d = A[i] - A[i-1];
        if(d == cdel)  clen++;
        else {
            cnt[clen]++;
            clen = 2;
            cdel = d;            
        }
    }
    cnt[clen]++;
    
    ll ans=N;
    for(ll i=2;i<=N;i++){
        ll p = (i * (i-1))/2;
        ans += cnt[i] * p;
    }
    
    cout << ans << endl;
    return 0;
}