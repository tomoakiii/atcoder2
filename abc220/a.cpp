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
    ll A,B,C; cin>>A>>B>>C;
    
    if(A%C==0){
        cout<<(A/C)*C<<endl;
    } else if (B%C==0 || B/C>A/C) {
        cout<<(B/C)*C<<endl;
    } else {
        cout<<-1<<endl;
    }
    return 0;
}