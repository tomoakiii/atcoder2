#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (ll i = 0; i < (n); ++i)
template<typename T> inline bool chmax(T &a, T b) { return ((a < b) ? (a = b, true) : (false)); }
template<typename T> inline bool chmin(T &a, T b) { return ((a > b) ? (a = b, true) : (false)); }
typedef long long ll;
int main(){
    ll X, Q;
    cin >> X >> Q;
    multiset<ll> qh,ql;
    qh.insert(X);
    rep(i,Q){
      ll a[2]; cin>>a[0]>>a[1];
      for(auto x:a){
        if(*qh.begin() <= x) {
          qh.insert(x);
        }else{
          ql.insert(x);
        }
      }
      while(qh.size() <= ql.size()) {
        auto it = ql.end();
        it--;
        qh.insert(*it);
        ql.erase(it);
      }
      while(qh.size() > ql.size()+1) {
        auto it = qh.begin();
        ql.insert(*it);
        qh.erase(it);
      }
      cout << *qh.begin() << endl;
    }


    return 0;
}