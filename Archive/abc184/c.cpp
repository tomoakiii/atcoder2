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
    ll a,b,c,d;
    cin >> a >> b >> c >> d;
    if(a==c && b==d){
        cout<<0<<endl; return 0;
    }
    if(a+b == c+d || a-b == c-d){
        cout<<1<<endl; return 0;
    }
    if(abs(a-c) + abs(b-d) <= 3){
        cout<<1<<endl; return 0;
    }
    if((a+b)%2 == (c+d)%2) {
        cout<<2<<endl; return 0;    
    }
    for(ll x=a-3; x<=a+3; x++)for(ll y=b-3; y<=b+3; y++){
        if(abs(x-a)+abs(y-b) > 3) continue;
        if(x+y == c+d || x-y == c-d) {
            cout<<2<<endl; return 0;
        }
        if(abs(x-c) + abs(y-d) <= 3){
            cout<<2<<endl; return 0;
        }
    }

    cout<<3<<endl;
    return 0;
}