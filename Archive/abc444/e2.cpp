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
    vector<ll> A(N);
    rep(i,N) {
        cin>>A[i];
    }
    ll ans = 0;
    multiset<ll> st;
    st.insert(INF);
    st.insert(-INF);
    ll l = 0, r = 0;
    vector<ll> NG(N, N);
    while(l < N) {
        while(r < N) {
            auto it = st.upper_bound(A[r]);
            ll up = *it;
            it--;
            ll dn = *it;
            if(up >= A[r]+D && dn <= A[r]-D) {
                st.insert(A[r]);
                ans += r-l+1;
                r++;
            }else {
                break;
            }
        }
        st.erase(st.find(A[l]));
        l++;
    }
    cout << ans << endl;
    return 0;
}