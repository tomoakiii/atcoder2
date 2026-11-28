//#include <atcoder/all>
//using namespace atcoder;
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (ll i = 0; i < (n); ++i)
template<typename T> inline bool chmax(T &a, T b) { return ((a < b) ? (a = b, true) : (false)); }
template<typename T> inline bool chmin(T &a, T b) { return ((a > b) ? (a = b, true) : (false)); }

typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const int INFi = 0x0F0F0F0F;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll K;
    cin >> K;
    vector<ll> A(K);
    rep(i,K) cin>>A[i];
    sort(A.begin(),A.end());
    if(A.back() != 9) cout<<-1<<endl;
    else cout<<A[0]<<endl;
    return 0;
}