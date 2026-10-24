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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll N,Q;
    cin >> N >> Q;
    set<tuple<ll,ll,int>> XS;
    XS.insert(make_tuple(-INF,0,-1));
    XS.insert(make_tuple(INF,0,-1));

    rep(i,N) {
        ll x,s; cin>>x>>s;
        XS.insert(make_tuple(x,s,i));
    }
    while(Q--){
        ll p; cin>>p;
        auto it1 = XS.lower_bound(make_tuple(p,0,0));
        auto it2 = it1;
        it2--;
        auto [x1,s1,i1]=*it1;
        auto [x2,s2,i2]=*it2;

        ll d1 = abs(x1 - p);
        ll d2 = abs(x2 - p);
        if(d1<d2){
            cout << i1 + 1 << '\n';
            XS.erase(it1);
        } else if (d1 > d2){
            cout << i2 + 1 << '\n';
            XS.erase(it2);
        } else {
            if(s1 > s2) {
                cout << i1 + 1 << '\n';
                XS.erase(it1);
            } else {
                cout << i2 + 1 << '\n';
                XS.erase(it2);
            }
        }
    }

    return 0;
}