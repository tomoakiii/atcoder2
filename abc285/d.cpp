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
    vector<string> S(N), T(N);
    map<string, int> Sm, Tm;
    rep(i,N) {
        cin>>S[i]>>T[i];
        Sm[S[i]] = i;
        Tm[T[i]] = i;
    }
    queue<int> que;
    vector<bool> visit(N,false);
    rep(i,N) {
        if(Sm.count(T[i]) == 0) {
            que.push(i);
            visit[i] = true;
        }
    }
    while(!que.empty()) {
        auto q = que.front();
        que.pop();
        if(Tm.count(S[q])) {
            int x = Tm[S[q]];
            que.push(x);
            visit[x] = true;
        }
    }
    bool ans = true;
    rep(i,N) if(!visit[i]) ans=false;
    if(ans) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}