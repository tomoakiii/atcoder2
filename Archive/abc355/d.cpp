#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)

typedef long long ll;
typedef pair<ll, ll> pll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const int INFi = 0x0F0F0F0F;

int main(){
    ll N;
    cin >> N;
    vector<pll> lr(2*N);
    rep(i, N) {
        ll l, r;        
        cin >> l >> r;
        lr[2*i] = {l, 0};
        lr[2*i+1] = {r, 1};
    }
    sort(lr.begin(), lr.end());
    ll ans = 0;
    ll cnt = 0;
    rep(i, 2*N){
        if (lr[i].second == 0) {
            if (cnt > 0) {
                ans += cnt;
            }
            cnt++;
        } else {
            cnt--;
        }
    }
      
    cout << ans << endl;
    return 0;
}