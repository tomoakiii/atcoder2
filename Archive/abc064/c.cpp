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
    ll N;
    cin >> N;
    set<int> st;
    ll r = 0;
    rep(i,N) {
        ll a; cin>>a;
        if(a >= 3200) r++;
        else st.insert(a/400);
    }
    cout<<max(1,(int)st.size())<<" ";
    cout<<r+st.size()<<endl;
    return 0;
}