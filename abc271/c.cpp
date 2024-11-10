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
    map<ll, int> mp;
    rep(i,N) {
        ll a;
        cin >> a;
        mp[a]++;
    }

    int sell=0;
    for(auto &m: mp) {
        if(m.second > 1) {
            sell += m.second - 1;
            m.second = 1;
        }
    }
    int tgt = 1;
    auto scrap = mp.rbegin();
    auto m = mp.begin();
    rep(i, N) {
        if (m != mp.end() && m->first == tgt && m->second>=1) {
            m->second = 0;
            tgt++;
            m++;
            continue;
        }
        while(scrap != mp.rend() && sell < 2){
            if(scrap->second >= 1) {
                scrap->second = 0;
                sell++;
            }
            scrap++;
        }
        if (sell >= 2) {
            sell -= 2;
            tgt++;
            continue;
        } else {
            break;
        }
    }
   
    cout << tgt-1 << endl;
    return 0;
}