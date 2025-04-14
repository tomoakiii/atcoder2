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
    vector<int> Ppos(N);
    vector<int> Pnum(N);
    rep(i,N) {
        Ppos[i] = i;
        Pnum[i] = 1;
    }
    int ans = 0;
    while(Q--) {
        int k;
        cin >> k;
        if(k==1) {
            int P, H;
            cin >> P >> H;
            P--, H--;            
            bool flg2 = Pnum[H] < 2;
            Pnum[H]++;
            bool flg = Pnum[Ppos[P]] > 1;
            Pnum[Ppos[P]]--;
            if(flg2 && Pnum[H] > 1) ans++;
            if(flg && Pnum[Ppos[P]] <= 1) ans--;
            Ppos[P] = H;
        } else {
            cout << ans << endl;
        }

    }
    return 0;
}