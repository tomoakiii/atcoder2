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

int main(){
    ll N,M;
    cin >> N >> M;
    vector<ll> A(N), B(M);

    rep(i,N) {
        cin>>A[i]; A[i]--;
        B[A[i]]++;
    }
    vector<string> ans(2,"Yes");
    rep(i,M) {
        if(B[i]>=2) ans[0]="No";
        if(B[i]==0) ans[1]="No";
    }
    for(auto s:ans)cout<<s<<endl;
    return 0;
}