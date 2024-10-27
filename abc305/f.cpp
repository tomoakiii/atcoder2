#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)

typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const int INFi = 0x0F0F0F0F;

int main(){
    ll N, M;
    cin >> N >> M;
    vector uv(N, vector<ll>{});
    vector<bool> visit(N);
    bool flg = false;
    auto f = [&](auto f, int cur, int pre)->void{
        if (cur == N-1) {
            flg = true;
        }
        if (flg) return;
        int k;
        cin >> k;
        rep(i,k) {
            int p;
            cin >> p;
            p--;
            if (visit[cur]) continue;
            uv[cur].push_back(p);
        }
        visit[cur] = true;
        for(auto p: uv[cur]) {
            if (flg) return;
            if (visit[p]) continue;
            cout << (p+1) << endl;
            f(f, p, cur);
        }
        if (flg) return;
        cout << pre+1 << endl;
    };   
    f(f,0,-1);
    return 0;
}