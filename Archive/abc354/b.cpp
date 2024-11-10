#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)

typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const int INFi = 0x0F0F0F0F;

int main(){
    ll N;
    cin >> N;
    map<string, ll> mp;
    ll total = 0;
    rep(i, N){
        string s;
        ll t;
        cin >> s >> t;
        mp[s] = t;
        total += t;
    }
    ll tgt = total%N;
    ll cnt = 0;
    for (auto m: mp) {
        if (cnt == tgt) {
            cout << m.first << endl;
            return 0;
        }
        cnt ++;
    }
    return 0;
}