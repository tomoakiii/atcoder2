#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (ll i = 0; i < (n); ++i)

typedef long long ll;

int main(){
    ll N;
    cin >> N;
    vector<ll> A(N),B(N);
    map<ll,ll> mp;
    rep(i,N) {
        cin>>A[i];
        mp[A[i]+i+1]++;
        B[i] = (i+1) - A[i];
    }
    ll ans = 0;
    for(auto b:B) ans += mp[b];
    cout << ans << endl;
    return 0;
}