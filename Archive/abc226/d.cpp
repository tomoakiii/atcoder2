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
    vector<pair<ll,ll>> vp(N); 
    rep(i,N){        
        cin >> vp[i].first >> vp[i].second;
    }
    set<pair<ll,ll>> st;
    rep(i,N) {
        auto [a,b] = vp[i];
        rep(j,N) {
            if(i==j) continue;
            auto [a2,b2] = vp[j];
            ll da = a2-a;
            ll db = b2-b;
            if(db==0) {
                st.insert({da/abs(da), 0});
            } else if(da==0) {
                st.insert({0, db/abs(db)});
            } else {
                ll g = gcd(da,db);
                st.insert({da/g, db/g});
            }
        }
    }
    cout<<st.size()<<endl;
    return 0;
}