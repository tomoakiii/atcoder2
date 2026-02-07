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
typedef pair<ll, pair<int,int>> pl;
typedef modint1000000007 mint;

int main(){
    ll N,X; cin>>N>>X;
    string S; cin>>S;
    X--;
    int p = X;
    S[p] = '@';
    while(p-1>=0 && S[p-1] == '.') {
        p--;
        S[p] = '@';
    }
    p = X;
    while(p+1<N && S[p+1] == '.') {
        p++;
        S[p] = '@';
    }
    cout << S << endl;
    return 0;
}