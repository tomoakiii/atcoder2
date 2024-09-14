#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)

typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const int INFi = 0x0F0F0F0F;

int main(){
    int N, Q;
    cin >> N >> Q;
    vector<set<int>> st(N+1);
    int ans = N;
    while(Q--){
        int a, u, v;
        cin >> a;
        if (a == 1) {
            cin >> u >> v;
            if (st[u].size() == 0) ans--;
            st[u].insert(v);
            if (st[v].size() == 0) ans--;
            st[v].insert(u);
        } else {
            cin >> v;
            if (st[v].size() > 0) {
                for(auto p: st[v]) {
                    st[p].erase(v);
                    if (st[p].size() == 0) ans++;
                }
                st[v].clear();
                ans++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}