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
    ll N, M;
    cin >> N >> M;
    vector<pair<int, ll>> XA(M);
    ll sm=0;
    rep(i,M) cin>>XA[i].first;
    rep(i,M) {
        cin>>XA[i].second;
        sm += XA[i].second;
    }
    if(sm != N){
        cout << -1 << endl;
        return 0;
    }
    sort(XA.rbegin(), XA.rend());
    ll last = N;
    ll cnt = 0;
    for(auto [x, a] : XA) {
        ll p = last-x;
        if(p+1 < a) {
            cout << -1 << endl;            
            return 0;
        }
        ll ltmp = (p * (p+1)) / 2;
        ltmp -= ((p-a)*(p-a+1))/2;
        cnt += ltmp;
        last -= a;
    }
    cout << cnt << endl;
    return 0;
}