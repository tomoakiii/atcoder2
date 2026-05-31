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
    ll K;
    cin >> K;
    if(K<=9) {
        cout<<K<<endl;
        return 0;
    }
    K-=9;
    for(ll i=2; i<INF; i++) {
        set<ll>st;
        auto func = [&](auto func, int cur, ll d, ll p)->void{
            if(cur == i) {
                st.insert(p);
                return;
            }
            if(d<9) func(func,cur+1,d+1,p*10+(d+1));
            func(func,cur+1,d,p*10+(d));
            if(d>0) func(func,cur+1,d-1,p*10+(d-1));
        };
        rep(j,9) func(func, 1, j+1, j+1);
        if(st.size() > K) {
            auto it = st.begin();
            K--;
            while(K--){
                it++;
            }
            cout << *it << endl;
            return 0;
        } else {
            K -= st.size();
        }
    }    
    return 0;
}