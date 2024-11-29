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
    vector<int> v(14);
    rep(i,5) {
        int a;
        cin >> a;
        v[a]++;;
    }
    bool f2=false, f3=false;
    rep(i,14) {
        if (v[i] == 2) f2 = true;
        if (v[i] == 3) f3 = true;
    }
    if(f2 && f3) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}