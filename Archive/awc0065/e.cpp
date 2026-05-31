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
    ll N,K,D;
    cin >> N >> K >> D;
    vector<ll> H(N);
    rep(i,N) cin>>H[i];
    multiset<ll> st;
    int r=0;
    ll ans = -1;
    rep(i,N) {
        auto chk = [&]()->bool{
            auto it = st.end();
            it--;
            ll k = *it - *st.begin();
            return (k <= D);
        };
        while(r<N) {
            if(st.empty()){
                st.insert(H[r++]);
                continue;
            }
            if(!chk()) break;
            if(st.size()>=K) chmax(ans,(ll)st.size());
            st.insert(H[r++]);
        }
        if(chk()) if(st.size()>=K) chmax(ans,(ll)st.size());
        st.erase(st.find(H[i]));
    }
    cout<<ans<<endl;
    return 0;
}