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
    int N = S.size();
    set<char> ok;
    string oks = "AGCT";
    for(auto c:oks) ok.insert(c);
    ll mx = 0;
    rep(i,N) {
        int j = i;
        for(; j<N; j++) {
            if(!ok.contains(S[j])) break;
        }
        chmax(mx, j-i);
    }
    cout<<mx<<endl;
    return 0;
}