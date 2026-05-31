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
    ll N, M;
    cin >> N >> M;
    vector<int> A(M),B(M);
    rep(i,M) {
        cin>>A[i]>>B[i];
        A[i]--, B[i]--;
    }
    dsu UF(N);
    ll ans = N*(N-1)/2;
    vector<ll> av;
    for(int i=M-1;i>=0;i--) {
        av.push_back(ans);
        if(UF.same(A[i],B[i])) {
        } else {
            ans -= UF.size(A[i]) * UF.size(B[i]);
            UF.merge(A[i],B[i]);
        }
    }
    reverse(av.begin(),av.end());
    for(auto a:av)cout<<a<<endl;
    return 0;
}