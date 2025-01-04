#include <bits/stdc++.h>
#include <atcoder/all>
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
    vector<ll> X(N,0), Y(N,0);
    rep(i,N) cin>>X[i]>>Y[i];
    sort(X.begin(), X.end());
    vector sX = X;
    rep(i,N-1) sX[i+1] += sX[i];
    sort(Y.begin(), Y.end());
    vector sY = Y;
    rep(i,N-1) sY[i+1] += sY[i];

    auto f = [&N](vector<ll> &v, vector<ll> &sm, int k) -> ll {
        int p = lower_bound(v.begin(), v.end(), k) - v.begin();
        if(p == 0) {
            return sm[N-1] - N * v[0];
        }
        ll s = p*k - sm[p-1];
        s += sm[N-1] - sm[p-1] - k * (N-p);
        return s;
    };


    auto fmain = [&](vector<ll> &xy, vector<ll> &sm)->ll {
        map<ll, ll> mp;
        ll l=xy[0], r=xy[N-1];
        while(r-l > 1) {
            // cout << r - l << endl;
            ll cr = (2*r+l)/3;
            ll cl = (r+2*l)/3;
            if(!mp.contains(cl)) mp[cl] = f(xy, sm, cl);
            if(!mp.contains(cr)) mp[cr] = f(xy, sm, cr);
            if (mp[cl] < mp[cr]) {
                if(r == cr) return mp[cl];
                r = cr;
            } else {
                if(l == cl) return mp[cr];
                l = cl;
            }
        }
        if(!mp.contains(l)) mp[l] = f(xy, sm, l);
        if(!mp.contains(r)) mp[r] = f(xy, sm, r);
        return min(mp[l], mp[r]);
    };

    ll p1 = fmain(X, sX);
    ll p2 = fmain(Y, sY);
    
    cout << p1 + p2 << endl;
    return 0;
}