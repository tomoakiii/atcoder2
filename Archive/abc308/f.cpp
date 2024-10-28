#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)
typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const int INFi = 0x0F0F0F0F;
typedef pair<ll, ll> pll;

int main(){
    ll N, M;
    cin >> N >> M;
    vector<pll> LD(M);
    vector<ll> P(N);
    
    rep(i, N) cin >> P[i];
    rep(i, M) cin >> LD[i].first;
    rep(i, M) cin >> LD[i].second;
    sort(P.begin(), P.end());
    sort(LD.begin(), LD.end());
    int it = 0;
    priority_queue<ll> que;
    rep(i, N) {
        ll p = P[i];
        while(it < M && LD[it].first <= p){
            que.push(LD[it].second);
            it++;
        }
        if (que.empty()) continue;
        ll d = que.top();
        que.pop();
        P[i] -= d;
    }
    ll ans = 0;
    rep(i, N) ans+=P[i];
    cout << ans << endl;
    return 0;
}