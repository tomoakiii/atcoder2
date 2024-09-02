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
    vector<map<int, int>> box(N+1);
    vector<set<int>> card(200005);

    while(Q--){
        int p, x, y;
        cin >> p;
        if (p == 1){
            cin >> x >> y;
            box[y][x]++;
            card[x].insert(y);
        } else if (p == 2) {
            cin >> x;
            for(auto i: box[x]) rep(j, i.second) cout << i.first << " ";
            cout << endl;
        } else {
            cin >> x;
            for(auto i: card[x]) cout << i << " ";
            cout << endl;
        }
    }

    return 0;
}