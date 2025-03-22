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
    const int N = 7;
    map<int, int> mp;
    rep(i,N) {
        int a;
        cin >> a;
        mp[a]++;
    }
    int c3 = 0, c2 = 0;
    for(auto m: mp) {
        if(m.second >= 3) c3++;
        else if(m.second >= 2) c2++;
    }
    if(c3 >= 2 || (c3>=1 && c2>=1)) cout << "Yes" << endl;
    else cout << "No" << endl;


    return 0;
}