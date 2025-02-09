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
    vector<bool> A(N+1, true);
    int cnt = 0;
    rep(i,M) {
        ll a;
        cin >> a;
        A[a] = false;
    }

    set<ll> st;
    for(int i=1; i<=N; i++) {
        if(A[i]) st.insert(i);
    }
    cout << st.size() << endl;
    for(auto s: st) cout << s << " ";
    cout << endl;
    return 0;
}