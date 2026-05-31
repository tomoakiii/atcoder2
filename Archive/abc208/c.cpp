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
    ll N,K;
    cin >> N >> K;
    vector<ll> ans(N);
    vector<pair<ll,int>> A(N);
    rep(i,N) {
        cin>>A[i].first;
        A[i].second = i;
    }
    sort(A.begin(), A.end());
    rep(i,N) ans[i] += K/N;
    K = K%N;
    rep(i, K) ans[i]++;
    vector<ll> ans2(N);
    rep(i,N) {
        int j = A[i].second;
        ans2[j] = ans[i];
    }
    for(auto a: ans2) cout<<a<<endl;
    return 0;
}