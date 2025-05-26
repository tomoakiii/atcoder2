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
    ll N, M;
    cin >> N >> M;
    vector<string> S(N);
    unordered_set<string> st;
    rep(i,N) cin>>S[i];
    rep(i,M) {
        string t;
        cin>>t;
        st.insert(t);
    }
    for(auto s: S) {
        if(st.contains(s)) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }

    return 0;
}