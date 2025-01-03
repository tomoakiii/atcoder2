#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)
typedef long long ll;
int main(){
    ll N;
    cin >> N;
    string Ss;
    cin >> Ss;
    vector<bool> S(N+1);
    rep(i,N) S[i] = (Ss[i] == 'o');
    S[N] = (Ss[N-1]=='x');
    ll cnt = 1;
    ll ans = 0;
    bool ls = S[0];
    for(int i=1; i<=S.size(); i++) {
        if (S[i] == ls) {
            cnt++;
        } else {
            ans += (cnt-1)*cnt/2;            
            cnt = 1;
            ls = S[i];
        }
    }
    ans = N*(N-1) / 2 - ans;
    cout << ans << endl;
    return 0;
}