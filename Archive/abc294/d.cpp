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
    int cur = 0;
    vector<bool> visit(N, false);
    while(Q--){
        int x, p;
        cin >> x;
        if (x==2) {
            cin >> p;
            p--;
            visit[p] = true;
            if (p == cur) {
                while (visit[cur]) {cur++;}
            }
        } else if (x==3) {
            cout << cur+1 << endl;
        }
    }
    return 0;
}