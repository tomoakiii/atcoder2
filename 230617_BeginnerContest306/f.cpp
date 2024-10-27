#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)

typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const int INFi = 0x0F0F0F0F;

int main(){
    ll N, M;
    cin >> N >> M;
    vector A(N, vector<ll>(M));
    
    rep(i,N)  {
        rep(j,M) cin >> A[i][j];
        sort(A[i].begin(), A[i].end());
    }

    set<ll> st;
    ll ans = 0;
    rep(j,M) st.insert(A[N-1][j]);
    for(int i=N-2; i>=0; i--) {
        rep(j, M) {
            auto is = st.lower_bound(A[i][j]);
            int rank = is - st.begin();
            ans += (j+1) * (N-1-i);
            ans += rank;
        }
        rep(j,M) {
            st.insert(A[i][j]);
        }
    }
    cout << ans << endl;
    return 0;
}