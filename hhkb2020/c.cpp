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

int main(){
    int N; cin>>N;
    set<int> st;
    rep(i,N){
        int p; cin>>p;
        st.insert(p);
    }
    rep(i,200002) {
        if(!st.contains(i)) cout<<i<<endl;
        break;
    }
    return 0;
}