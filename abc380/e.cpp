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
    ll N, Q;
    cin >> N >> Q;
    dsu UF(N+2);
    vector<int> col(N+2);
    vector<int> colN(N+2, 1);
    vector<pair<int, int>> grp(N+2);
    rep(i,N+2) {
        col[i] = i;
        grp[i] = {i, i};
    }
    
    while(Q--){
        int q;
        cin >> q;
        if(q == 1) {
            int x, c;
            cin >> x >> c;
            if(x > 0) {
                int ld = UF.leader(x);
                colN[col[ld]] -= UF.size(ld);
                colN[c] += UF.size(ld);

                auto [a, b] = grp[ld];
                int ld2 = UF.leader(a-1);                
                if(col[ld2] == c) {
                    auto [a2, b2] = grp[ld2];
                    UF.merge(x, a-1);
                    int nld = UF.leader(x);
                    col[nld] = c;
                    grp[nld] = grp[ld];
                    grp[nld].first = a2;
                    ld = nld;
                    
                }
                ld2 = UF.leader(b+1);
                if(col[ld2] == c) {
                    auto [a2, b2] = grp[ld2];
                    UF.merge(x, b+1);
                    int nld = UF.leader(x);
                    col[nld] = c;
                    grp[nld] = grp[ld];
                    grp[nld].second = b2;
                    ld = nld;
                }
                col[ld] = c;
            }
        } else {
            int c;
            cin >> c;
            cout << colN[c] << "\n";
        }
    }
   return 0;
}