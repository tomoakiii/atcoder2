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
    string S;
    cin >> S;
    int m = S.size();
    double ans = 0;
    rep(i,m) {
        if(S[i]!='t') continue;
        ll tl = 1, x = 1;
        for(int j=i+1; j<m; j++) {            
            tl+=1;
            if(S[j] == 't') {
                x+=1;
                if(tl >= 3) chmax(ans, ((double)x-2)/((double)tl-2));
            }            
        }
    }
    printf("%.11f\n", ans);
    return 0;
}