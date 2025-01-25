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
    vector<pair<ll, int>> C(9);
    vector<pair<int, ll>> C2(9);
    rep(i, 9) {
        ll c;
        cin>>c;
        C[i] = {c, i};
        C2[i] = {i, c};
    }
    sort(C.begin(), C.end());
    int k = N / C[0].first;
    if(k == 0) {
        cout << 0 << endl;
        return 0;
    }

    ll sum = k * C[0].first;
    vector<ll> ans(k, C[0].second + 1); 
    sort(C2.rbegin(), C2.rend());
    rep(i, k) {
        rep(j, 9) {
            if(sum - C[0].first + C2[j].second <= N) {
                ans[i] = C2[j].first + 1;
                sum = sum - C[0].first + C2[j].second;
                break;
            }
        }
    }
    rep(i, k) printf("%d", ans[i]);
    printf("\n");
    
    return 0;
}