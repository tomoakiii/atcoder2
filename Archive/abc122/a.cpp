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
    char b; cin>>b;
    switch(b){
        case 'A': cout<<'T'<<endl; break;
        case 'T': cout<<'A'<<endl; break;
        case 'G': cout<<'C'<<endl; break;
        case 'C': cout<<'G'<<endl; break;
        default: break;
    }
    return 0;
}