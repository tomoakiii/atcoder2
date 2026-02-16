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
    ll N,D;
    cin >> N >> D;
    vector<pair<ll,ll>> A(N);
    rep(i,N) {
        cin>>A[i].first;
        A[i].second = i;
    }
    sort(A.begin(), A.end());
    set<ll> st;
    st.insert(N);
    ll l = 0, r = 0;
    vector<ll> NG(N, N);
    rep(l,N) {
        while(r < N && A[r].first - A[l].first < D) {
            auto it = st.upper_bound(A[r].second);
            chmin(NG[A[r].second], *it);
            if(*it != *st.begin()) {
                it--;
                chmin(NG[*it], A[r].second);
            }
            st.insert(A[r].second);
            r++;
        }
        st.erase(A[l].second);
    }
    multiset<ll> NGs;
    rep(i,N) NGs.insert(NG[i]);
    ll ans = 0;
    rep(i,N) {
        ll r = *NGs.begin();
        ans += r - i;
        // cerr << r-i << endl;
        NGs.erase(NGs.find(NG[i]));
    }
    cout << ans << endl;
    return 0;
}