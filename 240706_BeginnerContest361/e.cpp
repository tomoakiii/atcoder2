#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)

typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const int INFi = 0x0F0F0F0F;

int main(){
    int N;
    cin >> N;
    vector P(N, vector<pair<int, ll>>{});
    ll sm = 0;
    rep(i, N-1) {
        ll a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        P[a].push_back({b, c});
        P[b].push_back({a, c});
        sm += c;
    }
    ll mx[2] = {0, 0};
    rep(i, N) {
        if (P[i].size() == 1) {
            ll nx = P[i][0].first, cnt = P[i][0].second, last = i;
            while (true) {
                if (P[nx].size() == 2) {
                    if (P[nx][0].first == last) { 
                        cnt += P[nx][1].second;
                        nx = P[nx][1].first;
                    } else {
                        cnt += P[nx][0].second;
                        nx = P[nx][0].first;
                    }
                    last = nx;                    
                    continue;
                }
                if (P[nx].size() > 2) {
                    break;
                }
                if (P[nx].size() == 1) {
                    cout << cnt << endl;
                    return 0;
                }
            }
            mx[1] = max(mx[1], cnt);
            if (mx[1] > mx[0]) swap(mx[0], mx[1]);
        }
    }
    cout << (sm + sm - mx[0] - mx[1]) << endl;
    return 0;
}