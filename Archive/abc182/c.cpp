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
    vector<int> v;
    while(N) {
        v.push_back(N%10);
        N/=10;
    }
    ll sm = 0;
    vector<int> cnt(3);
    for(auto &vv: v) {
        vv %= 3;
        cnt[vv]++;
        sm += vv;
    }
    sm = sm % 3;
    if(sm == 0) cout << 0 << endl;
    else if (sm == 1 ) {
        if(cnt[1] >= 1 && v.size() > 1) cout << 1 << endl;
        else if(cnt[2]>= 2 && v.size() > 2) cout << 2 << endl;
        else cout << -1 << endl;
    } else {
        if(cnt[2] >= 1 && v.size() > 1) cout << 1 << endl;
        else if(cnt[1]>= 2 && v.size() > 2) cout << 2 << endl;
        else cout << -1 << endl;
    }
    return 0;
}