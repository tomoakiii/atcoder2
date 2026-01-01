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
    ll N,K;
    cin >> N >> K;
    set<int> st;
    rep(i,K) {
        int d; cin>>d; st.insert(d);
    }
    for(int n = N; ; n++) {
        int n2 = n;
        bool flg = true;
        while(n2 > 0) {
            if(st.contains(n2 % 10)) {
                flg = false;
                break;
            }
            n2 /= 10;
        }
        if(flg) {
            cout << n << endl;
            return 0;
        }
    }


    return 0;
}