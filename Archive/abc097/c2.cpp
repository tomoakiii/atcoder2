// https://atcoder.jp/contests/abc403/tasks/abc403_e
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
    string S; int K;
    cin>>S>>K;
    set<string> st;
    rep(i,S.size()) {
        string t = "";
        int mn = S.size();
        chmin(mn, (int)i+6);
        for(int j = i; j < mn; j++) {
            t.push_back(S[j]);
            st.insert(t);
        }
    }
    auto s = st.begin();
    rep(i,K-1) s++;
    cout<<*s<<endl;
    return 0;
}