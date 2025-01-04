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
    ll N, K;
    cin >> N >> K;
    vector<int> next(100000, -1);
    ll x = N;
    int lps;
    ll cnt = 0;
    while(true) {
        cnt++;
        ll k = 0;
        ll a0 = x%10; k+=a0;
        ll a1 = x%100-k; a1/=10; k+=10*a1;
        ll a2 = x%1000-k; a2/=100; k+=100*a2;
        ll a3 = x%10000-k; a3/=1000; k+=1000*a3;
        ll a4 = x%100000-k; a4/=10000; k+=10000*a4;
        ll y = x + a0 + a1 + a2 + a3 + a4;
        y %= 100000;
        if(cnt == K) {
            cout << y << endl;
            return 0;
        }
        next[x] = y;
        x = y;
        if(next[x] != -1) {
            lps = x;
            break;
        }
    }
    x = N;
    while(x != lps) {
        K--;
        x = next[x];
    }
    int y = lps;
    cnt = 0;
    while(1) {
        cnt++;
        y = next[y];
        if(y == lps) break;
    }
    K %= cnt;
    while(K--) {
        x = next[x];
    }
    cout << x << endl;
    return 0;
}