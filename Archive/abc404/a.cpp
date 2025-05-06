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
    string S;
    cin>>S;
    vector<bool> visit(100);
    rep(i,S.size()) {
        visit[S[i] - 'a'] = true;
    }
    for(char c='a'; c<='z'; c++) {
        if(!visit[c-'a']) {
            cout<<c<<endl;
            return 0;
        }
    }
    return 0;
}