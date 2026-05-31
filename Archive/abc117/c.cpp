#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (ll i = 0; i < (n); ++i)
template<typename T> inline bool chmax(T &a, T b) { return ((a < b) ? (a = b, true) : (false)); }
template<typename T> inline bool chmin(T &a, T b) { return ((a > b) ? (a = b, true) : (false)); }

typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const int INFi = 0x0F0F0F0F;
typedef pair<int,int> pii;
typedef pair<pii, int> piii;
typedef pair<ll,ll> pll;
typedef pair<pll, pii> pp;
int main(){
    ll N,M,sm=0;
    cin>>N>>M;
    vector<ll> A(M),B(M-1);
    rep(i,M)cin>>A[i];
    sort(A.begin(),A.end());
    rep(i,M-1)B[i]=A[i+1]-A[i];
    sort(B.rbegin(),B.rend());
    rep(i,min(N-1, (ll)B.size())) sm+=B[i];
    cout<<A[M-1] - A[0] - sm<<endl;
    return 0;
}