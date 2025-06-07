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
    string S, T;
    cin>>S>>T;
    int p;
    int N = 'z'-'a'+1;
    rep(i, 30) {
        int c = S[0] - 'a';
        c += i;
        if(c >= N) c%=N;
        if(T[0]-'a' == c) p = i;
    }
    string Q;
    for(auto s:S) {
        int c = s - 'a';
        c += p;
        c %= N;
        Q.push_back(c+'a');
    }
    if(T==Q) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}