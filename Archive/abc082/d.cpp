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
    string s; ll x,y; cin>>s>>x>>y;
    s.push_back('T');
    vector<ll> h,w;
    bool ln = true;
    ll tmp = 0;
    bool ini = true;
    for(auto c: s) {
        if(c == 'T') {
            if(ini) {
                x -= tmp;
                ini = false;
            } else {
                if(ln) {
                    w.push_back(tmp);
                }
                else {
                    h.push_back(tmp);
                }
            }
            tmp = 0;
            ln = !ln;
        } else {
            tmp++;
        }
    }
    unordered_set<ll> hst, wst;
    rep(kk,2){
        wst.insert(0);
        for(auto v: w) {
            unordered_set<ll> p;
            for(auto s: wst){
                p.insert(s+v);
                p.insert(s-v);
            }
            swap(wst, p);
        }
        swap(hst,wst); swap(w,h);
    }

    if(hst.contains(y) && wst.contains(x)) {
        cout<<"Yes"<<endl;
    } else {
        cout<<"No"<<endl;
    }
    return 0;
}