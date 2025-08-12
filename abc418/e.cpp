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
    vector<ll> X(N), Y(N);
    rep(i,N) {
        cin>>X[i]>>Y[i];
        X[i] *= 2, Y[i] *= 2;
    }
    vector<pair<ll,ll>> mp;
    vector<pair<ll,ll>> mp2;
    rep(i,N) for(int j=i+1; j<N; j++) {
        int ii = i, jj = j;
        if(X[ii] > X[jj]) swap(ii, jj);
        ll dx = X[jj] - X[ii], dy = Y[jj] - Y[ii];
        mp2.push_back({X[ii] + dx/2, Y[ii] + dy/2});
        if(dx == 0) {
            mp.push_back({0,1});
            continue;
        }
        if(dy == 0) {
            mp.push_back({1,0});
            continue;
        }
        ll g = gcd(dx, dy);
        mp.push_back({dx/g, dy/g});
    } 
    sort(mp.begin(), mp.end());
    sort(mp2.begin(), mp2.end());
    mp.push_back({INF-1, INF-1});
    mp2.push_back({INF-1, INF-1});
    ll ans = 0;
    ll last1 = INF, last2 = INF;
    ll cnt = 0;
    for(auto [m1, m2]:mp) {
        if(last1 == m1 && last2 == m2) cnt++;
        else {
            if (cnt >= 2) ans += cnt * (cnt-1) / 2;
            cnt = 1;
            last1 = m1, last2 = m2;
        }
    }
    ll ans2 = 0;
    last1 = INF, last2 = INF, cnt = 0;
    for(auto [m1, m2]:mp2) {
        if(last1 == m1 && last2 == m2) cnt++;
        else {
            if (cnt >= 2) ans2 += cnt * (cnt-1) / 2;
            cnt = 1;
            last1 = m1, last2 = m2;
        }
    }

    cout << ans - ans2 << endl;
    return 0;
}