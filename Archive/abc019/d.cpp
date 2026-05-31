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
    ll mx = 0;
    int mxi;
    for(int i=2; i<=N; i++) {
        cout<<"? 1 "<<i<<endl;
        ll d; cin>>d;
        if(chmax(mx, d)) mxi = i;
    }
    for(int i=1; i<=N; i++) {
        if(i == mxi) continue;
        cout << "? " << mxi << " " << i << endl;
        ll d; cin>>d;
        chmax(mx, d);
    }
    cout << "! " << mx << endl;
    return 0;
}