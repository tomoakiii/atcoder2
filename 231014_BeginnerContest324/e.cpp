#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const ll INFi = 0x0F0F0F0F;


int main(){
    ll N;
    string T;
    cin >> N >> T;
    ll M = T.size();    
    vector<ll> cnt_f(M+1), cnt_r(M+1);
    // 0: 0文字含む、M: M文字すべて含む
    string s;
    for(ll i=0; i<N; i++){
        cin >> s;
        ll ss = s.size();
        ll ind = 0;
        for (ll k=0; k<ss; k++){
            if (s[k] == T[ind]){
                ind++;
                if (ind > M) {
                    break;
                }
            }
        }
        cnt_f[ind]++; // ind文字目まで前方一致で含んだ個数

        ind = M;
        for (ll k=ss - 1; k>=0; k--){
            if (s[k] == T[ind-1]){                
                ind--;
                if (ind <= 0){
                    break;
                }
            }
        }
        cnt_r[ind]++; // ind文字目まで後方一致で含んだ個数
    }

    for (ll i = 0; i < M; i++) {
        cnt_r[i+1] += cnt_r[i]; // ind文字目まで後方一致で含む全数
    }

    // cnt_f[0] * cnt_f[0]
    ll ans = 0;    
    for (ll i = 0; i <= M; i++) {
        ans += cnt_f[i] * cnt_r[i];
    }

    cout << ans << endl;
    return 0;
}