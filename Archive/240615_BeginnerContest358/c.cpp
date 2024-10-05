#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)

typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const int INFi = 0x0F0F0F0F;

int main(){
    ll N, M;
    cin >> N >> M;
    vector<string> S(N);
    rep(i, N) cin >> S[i];
    ll mn = INF;
    for (ll k = 0; k < (1<<N) ; k++) {
        ll vis = 0;
        ll cnt = 0;
        for (int j = 0; j < N; j++) {
            if (((k>>j)&1) == 0) continue;
            cnt++;
            for (int i =0; i < M; i++){
                if (S[j][i] == 'x') continue;
                vis |= (1<<i);
            }        
        }
        if (vis == (1<<M)-1) {
            mn = min(mn, cnt);
        }
    }
    cout << mn << endl;
    return 0;
}