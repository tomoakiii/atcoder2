#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const int INFi = 0x0F0F0F0F;

typedef modint998244353 mint;

int main(){
    ll N; cin >>N;
    ll sm=0;
    for(ll i=0;i<N;i++) {
        ll a; cin>>a;
        sm+=a;
    }
    cout<<sm-N<<endl;
    return 0;
}