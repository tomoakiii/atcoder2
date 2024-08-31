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
    string S;
    cin >> S;

    int cnt = 0;
    bool flg = false;
    int mx = 0;
    rep (k, 2){       
        rep(i, N) {
            if (S[i] == '-') {
                flg = true;
                cnt = 0;
            }
            if (flg && S[i] == 'o') {
                cnt++;
                mx = max(mx, cnt);
            }
        }
        reverse(S.begin(), S.end());
        flg = false;
    }
    
    if (mx == 0) mx = -1;
    cout << mx << endl;
    return 0;
}