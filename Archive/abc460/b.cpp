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
    ll N;
    cin >> N;
    while(N--){
        ll x,y,r,x2,y2,r2;
        cin>>x>>y>>r>>x2>>y2>>r2;
        if(r2>r) {
            swap(r,r2);
            swap(x,x2);
            swap(y,y2);
        }
        ll dx=(x-x2);
        dx=dx*dx;
        ll dy=(y-y2);
        dy=dy*dy;
        if(dx+dy>(r+r2)*(r+r2)) cout<<"No"<<endl;
        else if((r-r2)*(r-r2)>dx+dy) cout<<"No"<<endl;
        else cout<<"Yes"<<endl;
    }
    return 0;
}