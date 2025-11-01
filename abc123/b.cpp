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
    vector<int> a(5);
    int sm = 0;
    rep(i,5) {
        cin>>a[i];
        sm += a[i] - (a[i]%10);
        a[i] %= 10;
    }
    sort(a.begin(),a.end());
    bool f = false;
    rep(i,5) {
        if(a[i] == 0) continue;
        if(!f){
            sm += a[i];
            f = true;
        } else {
            sm += 10;
        }
    }
    cout<<sm<<endl;
    return 0;
}