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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll N,K;
    cin >> N >> K;
    vector<pair<ll,int>> A(N);
    rep(i,N) {
        ll a,b; cin>>a>>b;
        A[i].first = a+b;
        A[i].second = -i;
    }
    sort(A.rbegin(), A.rend());
    set<int> ans;
    rep(i,K) ans.insert(-A[i].second);
    for(auto a : ans) cout<<a+1<<endl;
    return 0;
}