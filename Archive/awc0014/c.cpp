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
typedef long double ld;
int main(){
    ld G,M,D,K,V;
    cin >> G>>M>>D>>K>>V;
    ld t;
    if(G>K*D) t=(G-K*D) + K;
    else t=G/D;
    ld u=(M-G)/V;
    if(t<=u)cout<<"Yes"<<endl;
     else cout<<"No"<<endl;
    return 0;
}