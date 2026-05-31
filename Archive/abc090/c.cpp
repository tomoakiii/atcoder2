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
    ll N,M;
    cin >> N >> M;
    if(N==1 && M==1) {
        cout<<1<<endl;
        return 0;
    }
    if(N>M) swap(N,M);
    if(N==1) {
        cout<<M-2<<endl;
        return 0;
    }
    cout<<N*M - (N+(M-1)+(N-1)+(M-2))<<endl;
    return 0;
}