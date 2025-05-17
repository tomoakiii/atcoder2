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
    ll N, M, Q;
    cin >> N >> M >> Q;
    vector<bool> full(N);
    vector<set<int>> acc(N);
    while(Q--) {
        int t;
        cin >> t;
        if(t == 1) {
            int x, y;
            cin >> x >> y;
            x--, y--;
            acc[x].insert(y);
        } else if (t == 2) {
            int x;
            cin >> x;
            x--;
            full[x] = true;        
        } else {
            int x, y;
            cin >> x >> y;
            x--, y--;
            if(full[x]) {
                cout << "Yes" << endl;
            } else {
                if(acc[x].contains(y)) {
                    cout << "Yes" << endl;
                } else {
                    cout << "No" << endl;
                }
            }
        }
    }
    
    return 0;
}