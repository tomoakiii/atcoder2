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
    ll N,M; cin>>N>>M;
    vector<int> A(M);
    rep(i,M) cin>>A[i];
    int cost[] = {0, 2,5,5,4,5,6,3,7,6 };
    vector<pair<int,int>> crd;
    for(auto a: A) {
        crd.push_back({-cost[a], a});
    }
    sort(crd.rbegin(), crd.rend());
    auto [v, n] = crd[0];
    v *= -1;
    vector<pair<int,int>> pos,neg;
    for(auto a: A) {
        if(a == n) continue;
        if(a < n) neg.push_back({cost[a], a});
        else pos.push_back({a, -cost[a]});
    }
    sort(neg.rbegin(), neg.rend());
    sort(pos.rbegin(), pos.rend());
    ll t = 0;
    string s;
    while(t + v < N) {
        s = s + (char)('0' + n);
        t += v;
    }

    if(!pos.empty()){
        for(auto &c: s) {
            if(t == N) break;
            for(auto [np, vp]: pos) {
                vp *= -1;
                ll dv = vp - v;
                if(t + dv <= N){
                    t += dv;
                    c = (char)('0' + np);
                    break;
                }
            }
        }
    }

    if(!neg.empty()){
        for(int i = s.size()-1; i>=0; i--) {
            if(t == N) break;
            for(auto [vp, np]: neg) {
                ll dv = vp - v;
                if(t + dv <= N){
                    t += dv;
                    s[i] = (char)('0' + np);
                    break;
                }
            }
        }
    }
    cout << s << endl;
    return 0;
}
