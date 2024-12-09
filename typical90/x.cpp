#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
typedef long long ll;
#define rep(i,n) for (ll i = 0; i < (n); ++i)

int main(){
    int N;
    ll K;
    cin >> N >> K;
    vector<ll> A(N);
    vector<ll> B(N);
    rep(i,N) cin>>A[i];
    rep(i,N) cin>>B[i];
    rep(i,N) K -= abs(A[i] - B[i]);
    if(K<0 || K%2 != 0) cout << "No" << endl;
    else cout << "Yes" << endl;
    return 0;
}