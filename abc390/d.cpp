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
    ll N;
    cin >> N;    
    vector<ll> A(N);
    rep(i,N) cin>>A[i];
    vector<ll> st;
    auto f = [&](auto f, int cur, vector<ll> gsum)->void {
        if (cur == N) {
            ll ans = 0;
            for(auto g: gsum) ans ^= g;
            st.emplace_back(ans);
            return;
        }
        rep(i, (int)gsum.size()) {
            gsum[i] += A[cur];
            f(f, cur+1, gsum);
            gsum[i] -= A[cur];
        }
        gsum.push_back(A[cur]);
        f(f, cur+1, gsum);
    };
    f(f, 0, {});
    sort(st.begin(), st.end());
    st.erase(unique(st.begin(), st.end()), st.end());
    cout << st.size() << endl;
    return 0;
}