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


int main() {
    int H,W,K; cin>>H>>W>>K;
    vector A(H, vector<int>(W));
    rep(i,H) {
        int cnt = 0;
        string S; cin>>S;
        rep(j,W) {
            if(S[j] == '#') {
                cnt++;
                A[i][j] = 1;
            }
        }
    }

    int ans = 0;
    rep(kk, 1ll<<H) {
        auto P = A;
        int cnt = 0;
        rep(i, H) if(kk >> i & 1) {
            cnt++;
            rep(j,W) P[i][j] = 1;
        }
        if(cnt > K) continue;
        int rm = K-cnt;
        int bl = 0;
        rep(i,H) rep(j,W) bl += P[i][j];

        priority_queue<int> que;
        rep(j, W) {
            int e = 0;
            rep(i,H) e += P[i][j];
            que.push(H-e);
        }

        rep(i, rm) {
            bl += que.top();
            que.pop();
        }
        cerr << bl << endl;
        chmax(ans, bl);
    }
    cout << ans << endl;
}