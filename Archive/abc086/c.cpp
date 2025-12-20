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
    ll i=0, j=0;
    ll st = 0;
    while(N--) {
        ll t, x, y;
        cin>>t>>x>>y;
        ll dt = abs(x-i) + abs(y-j);
        if(st+dt > t) {
            cout<<"No"<<endl;
            return 0;
        }
        st += dt;
        if((t - st)%2 == 1) {
            cout<<"No"<<endl;
            return 0;
        }
        st = t;
        i = x, j = y;
    }
    cout<<"Yes"<<endl;
    return 0;
}