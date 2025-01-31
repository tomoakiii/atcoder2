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
    vector<string> S(N);
    rep(i,N) cin >> S[i];
    int ans = INFi;
    rep(n, 10) {
        int cnt = 0;
        vector<bool> visit(N);
        int t = 0;
        while(true) {
            rep(i,N) {
                if(visit[i]) continue;
                if(S[i][t%10] == '0' + n) {
                    visit[i] = true;
                    cnt++;
                    break;
                }
            }
            if(cnt == N) {
                chmin(ans, t);
                break;
            }
            t++;
        }      
    }
    cout << ans << endl;
    return 0;
}