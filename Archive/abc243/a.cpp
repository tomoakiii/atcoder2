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
typedef modint998244353 mint;

int main(){
    int v,a,b,c;
    cin>>v>>a>>b>>c;
    while(v>=0){
        v-=a;
        if(v<0) {
            cout<<"F"<<endl;
            break;
        }
        v-=b;
        if(v<0) {
            cout<<"M"<<endl;
            break;
        }
        v-=c;
        if(v<0) {
            cout<<"T"<<endl;
            break;
        }
        
    }
    return 0;
}