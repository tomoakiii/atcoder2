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
    ll L,R;
    cin>>L>>R;
    string S;
    cin>>S;
    string T = S;
    int c = 0;
    for(int i=L-1; i<R; i++) {
        T[R-1-c] = S[i];
        c++;
    }
    cout<<T<<endl;
    return 0;
}