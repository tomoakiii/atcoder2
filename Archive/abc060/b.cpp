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
    ll A,B,C; cin>>A>>B>>C;
    set<ll> st;
    ll a = A;
    while(true){
        ll c = a%B;
        if(c == C) {
            cout<<"YES"<<endl;
            return 0;
        }
        else if (st.contains(c)) {
            cout << "NO" << endl;
            return 0;
        } else {
            st.insert(c);
            a += A;
        }
    }
    return 0;
}