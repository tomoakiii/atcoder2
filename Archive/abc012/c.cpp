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

    for(int i=1; i<=9; i++)for(int j=1; j<=9; j++){
        int sm = 0;
        for(int x=1; x<=9; x++)for(int y=1; y<=9; y++){
            if(x==i && y==j) continue;
            sm += x*y;
        }
        if(sm==N) cout << i << " x " << j << endl;
    }
    return 0;
}