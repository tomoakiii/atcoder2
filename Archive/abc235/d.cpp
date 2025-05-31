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
    ll a, N;
    cin >> a >> N;
    int cnt = 0;

    unordered_set<ll> st;
    queue<pair<int,ll>> que;
    que.push({0, 1});
    st.insert(1);
    while(!que.empty()){
        auto [k, x] = que.front();
        que.pop();
        if(x == N) {
            cout << k << endl;
            return 0;
        }
        ll x2 = x * a;
        if(x2 < 10*N && !st.contains(x2)) {
            st.insert(x2);
            que.push({k+1, x2});
        }
        if(x%10 == 0) continue;
        if(x<10) continue;
        x2 = x;
        ll p = 1;
        while(1) {
            x2 /= 10;            
            if(x2>0) p *= 10;
            else break;
        }
        x = (x%10)*p + x/10;
        if(x < 10*N && !st.contains(x)) {
            st.insert(x);
            que.push({k+1, x});
        }
    }


    cout << -1 << endl;
    return 0;
}