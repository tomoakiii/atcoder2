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
    string S, T;
    cin >> S >> T;        
    int M = 'z' - 'a' + 1;
    vector<int> mp(M, -1);
    int cnt = 0;
    rep(i,N) {
        int s = S[i] - 'a';
        int t = T[i] - 'a';
        if(mp[s] == t) continue;
        if(mp[s] != -1) {
            cout << -1 << endl;
            return 0;
        }
        mp[s] = t;
        // if(s != t) cnt++;        
    }

    vector<bool> visit(M, false);
    auto f = [&](auto f, int cur, int start) -> void {
        visit[cur] = true;
        if(mp[cur] == -1) return;
        if (mp[cur] == start) {
            cnt++;
        }
        if(!visit[mp[cur]]) {
            cnt++;
            f(f, mp[cur], start);
        }
    };
    rep(i, M) {
        if(mp[i] == -1) continue;
        if(!visit[i]) {            
            f(f, i, i);
        }
    }
    cout << cnt << endl;
    return 0;
}