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
    rep(i,5) cin>>a[i];
    int k; cin>>k;
    rep(i,4) for(int j=i+1;j<5;j++) {
        if(abs(a[j]-a[i]) > k) {
            cout<<":("<<endl;
            return 0;
        }
    }
    cout<<"Yay!"<<endl;
    return 0;
}