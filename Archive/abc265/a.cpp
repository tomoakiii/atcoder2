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
    ll X, Y, N;
    cin >> X >> Y >> N;
    ll min = INF;
    for(int i=0; i<=N; i++) {
        if (((N - i)%3) == 0) {
            int a = (N - i)/3;
            chmin(min, a*Y + i*X);
        }
    }
    cout << min << endl;
    return 0;
}