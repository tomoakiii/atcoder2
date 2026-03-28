#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (ll i = 0; i < (n); ++i)
template<typename T> inline bool chmax(T &a, T b) { return ((a < b) ? (a = b, true) : (false)); }
template<typename T> inline bool chmin(T &a, T b) { return ((a > b) ? (a = b, true) : (false)); }

typedef long long ll;
const ll INF = 0x7F7F7F7F7F7F7F7F;
const int INFi = 0x7F0F0F0F;
typedef modint1000000007 mint;
int main(){
    ll N; cin>>N;
    if(N==1) {
        cout<<"Deficient"<<endl;
        return 0;
    }
    unordered_set<ll> st;
    for(ll a=2; a*a<=N; a++) {
        if(N%a==0) {
            st.insert(a);
            st.insert(N/a);
        }
    }
    ll sm=1;
    for(auto s:st) sm+=s;
    if(N==sm) cout<<"Perfect"<<endl;
    else if(N>sm) cout<<"Deficient"<<endl;
    else cout<<"Abundant"<<endl;
    return 0;
}