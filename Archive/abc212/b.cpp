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
    string S; cin>>S;
    vector<ll> X(4);
    set<ll> st;
    rep(i,4) {
        X[i] = S[i] - '0';
        st.insert(X[i]);
    }
    if(st.size()==1) {
        cout<<"Weak"<<endl;
        return 0;
    }    
    rep(i,3) {
        if(X[i+1] != (X[i]+1)%10) {
            cout<<"Strong"<<endl;
            return 0;
        }
    }
    cout<<"Weak"<<endl;
    return 0;
}