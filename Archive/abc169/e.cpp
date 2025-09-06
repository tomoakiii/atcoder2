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
    vector<pair<ll,ll>> AB(N), BA(N);
    rep(i,N) {
        cin>>AB[i].first>>AB[i].second;
        BA[i] = {AB[i].second, AB[i].first};
    }
    sort(AB.begin(), AB.end());
    sort(BA.begin(), BA.end());
    if(N%2==1) {
        cout << (BA[N/2].first - AB[N/2].first) + 1 << endl;
    } else {
        ll lw = (AB[N/2 - 1].first + AB[N/2].first);
        ll up = (BA[N/2 - 1].first + BA[N/2].first);
        cout << (up-lw) + 1 << endl;
    }
    return 0;
}