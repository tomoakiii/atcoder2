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
    vector<ll> X(N), Y(N), P(N);    
    rep(i, N) cin >> X[i] >> Y[i] >> P[i];

    auto judge = [&](ll s) -> bool {
        vector uv(N, vector<int>{});
        rep(i, N) rep(j, N) {       
            if(i==j) continue;
            if(P[i]*s >= abs(X[i] - X[j]) + abs(Y[i] - Y[j])) {
                uv[i].emplace_back(j);
            }
        }
        /*
        vector<bool> visit(N);
        auto f = [&](auto f, int cur)->void {
            visit[cur] = true;
            for(auto nx: uv[cur]) {
                if(visit[nx]) continue;
                f(f, nx);
            }            
        };
        */
        
        auto f2 = [&](int st)->bool {
            vector<bool> visit(N);
            visit[st] = true;
            queue<int> que;
            que.push(st);
            while(!que.empty()) {
                auto q = que.front();
                que.pop();
                for(auto nx: uv[q]) {
                    if(visit[nx]) continue;
                    que.push(nx);
                    visit[nx] = true;
                }
            }
            rep(i,N) {
                if (!visit[i]) return false;
            }
            return true;
        };
        

        rep(i,N) {
            if (f2(i) ) return true;
        }
        return false;
    };

    ll l = 0, r = 4E9;
    while(r - l > 1) {
        ll c = (r + l) / 2;
        if(judge(c)) r = c;
        else l = c;
    }

    cout << r << endl;
    return 0;
}