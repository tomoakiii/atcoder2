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
    int Q;
    cin>>Q;
    deque<pair<ll,ll>> deq;
    while(Q--){
        int t; cin>>t;
        if(t==1) {
            ll c,x; cin>>c>>x;
            deq.push_back({c,x});
        } else {
            ll k; cin>>k;
            ll sm = 0;
            while(k){            
                auto [c,x] = deq.front();
                deq.pop_front();
                if(c<=k) {
                    k -= c;
                    sm += c*x;
                } else {
                    c -= k;
                    sm += k*x;
                    k = 0;
                    deq.push_front({c,x});
                }
            }
            cout<<sm<<endl;

        }
    }
    return 0;
}