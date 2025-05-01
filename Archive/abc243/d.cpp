#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (ll i = 0; i < (n); ++i)
template<typename T> inline bool chmax(T &a, T b) { return ((a < b) ? (a = b, true) : (false)); }
template<typename T> inline bool chmin(T &a, T b) { return ((a > b) ? (a = b, true) : (false)); }

typedef unsigned long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const int INFi = 0x0F0F0F0F;
typedef modint998244353 mint;

int main(){
    ll N, X;
    string S;
    cin>>N>>X>>S;
    ll cur = X;
    deque<char> que;
    rep(i,N) {        
        if(que.size() == 0) {
            que.push_back(S[i]);
            continue;
        }
        if(S[i] == 'U') {
            char s = que.back();
            if(s == 'R' || s == 'L') que.pop_back();
            else que.push_back(S[i]);
        } else que.push_back(S[i]);        
    }

    while(!que.empty()) {
        char s = que.front();
        que.pop_front();
        if(s=='U') {
            cur /= 2;
        } else if (s == 'L') {
            cur = cur * 2;
        } else {
            cur = cur * 2 + 1;
        }
    }
    cout << cur << endl;
    return 0;
}