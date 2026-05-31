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
    vector<ll> P(N);
    rep(i,N) cin>>P[i];
    vector PP = P;
    set<ll> st;
    st.insert(P[N-1]);
    for(int i=N-1; i>=1; i--){
        st.insert(P[i-1]);        
        if (P[i-1] > P[i]) {
            ll cmx = INF, c;
            int k;
            for (int j = i; j < N; j++) {
                if (P[j] > P[i-1]) continue;
                if (P[i-1] - P[j] < cmx) {
                    cmx = P[i-1] - P[j];
                    k  = j;
                }
            }
            PP[i-1] = P[k];
            st.erase(P[k]);
            auto it = st.end();
            it--;
            for (int j = i; j < N; j++) {
                PP[j] = *it;
                if (st.begin() != it) it--;
            }
            break;
        }
    }
    
    rep(i,N) cout << PP[i] << " ";
    cout << endl;
    return 0;
}