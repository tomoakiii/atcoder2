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
    ll N, Q;
    cin >> N >> Q;
    string S;
    cin >> S;
    int X;
    char C;
    int cnt = 0;
    rep(i, S.size()-2) {
        if (S[i] == 'A' && S[i+1] == 'B' && S[i+2] == 'C') cnt++;
    }

    while(Q--) {
        cin >> X >> C;
        X--;
        if (S[X-2] == 'A' && S[X-1] == 'B' && S[X] == 'C') cnt--;
        if (S[X-1] == 'A' && S[X] == 'B' && S[X+1] == 'C') cnt--;
        if (S[X] == 'A' && S[X+1] == 'B' && S[X+2] == 'C') cnt--;
        S[X] = C;
        if (S[X-2] == 'A' && S[X-1] == 'B' && S[X] == 'C') cnt++;
        if (S[X-1] == 'A' && S[X] == 'B' && S[X+1] == 'C') cnt++;
        if (S[X] == 'A' && S[X+1] == 'B' && S[X+2] == 'C') cnt++;
        cout << cnt << endl;
    }
    return 0;
}