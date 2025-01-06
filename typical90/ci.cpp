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
    ll N, P, K;
    cin >> N >> P >> K;
    vector dist(N, vector<ll>(N, INF));
    rep(i, N) rep(j, N) {
        cin >> dist[i][j];
    }
    auto f = [&](ll X)->ll{
        vector d = dist;
        rep(i, N) rep(j, N) if(dist[i][j] == -1) d[i][j] = X;
        rep(k, N) rep(i, N) rep(j, N) chmin(d[i][j], d[i][k] + d[k][j]);
        ll cnt = 0;
        rep(i, N) for(int j = i+1; j < N; j++) {
            if(d[i][j] <= P) cnt++;
        }
        return cnt;
    };
    ll r = INF, l = 0, m;
    map<ll, ll> mp;
    mp[r] = f(r); mp[l] = f(l);
    if(mp[r] == K) cout << "Infinity" << endl;
    else if(mp[r] > K) cout << 0 << endl;
    else if(mp[l] < K) cout << 0 << endl;
    else {
        ll lku = INF;
        while(mp[r] != K && r-l > 1) {
            m = (r+l)/2;
            if(!mp.contains(m)) mp[m] = f(m);
            if (mp[m] > K) {
                l = m;
            } else if (mp[m] < K) {
                r = m;
                lku = m;
            } else {
                r = m;
                break;
            }
        }
        if(mp[r] != K) {
            cout << 0 << endl;
            return 0;
        }
        ll lk = r;
        while(r-l > 1) {
            m = (r+l)/2;
            if(!mp.contains(m)) mp[m] = f(m);
            if (mp[m] == K) r = m;
            else if (mp[m] > K) l = m;
        }
        ll mn = r;
        l = lk;
        r = lku;
        while(r-l > 1) {
            m = (r+l)/2;
            if(!mp.contains(m)) mp[m] = f(m);
            if (mp[m] == K) l = m;
            else if (mp[m] < K) r = m;
        }
        ll mx = l;
        cout << mx - mn + 1 << endl;

    }
    return 0;
}