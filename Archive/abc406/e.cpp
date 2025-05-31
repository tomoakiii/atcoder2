#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (ll i = 0; i < (n); ++i)
template<typename T> inline bool chmax(T &a, T b) { return ((a < b) ? (a = b, true) : (false)); }
template<typename T> inline bool chmin(T &a, T b) { return ((a > b) ? (a = b, true) : (false)); }

typedef unsigned long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const int INFi = 0x0F0F0F0F;
typedef modint998244353 mint;

int main(){
    int T;
    cin>>T;
    vector dp1(61, vector<mint>(61)); // iまで見てj個bitが立っているものの個数
    vector dp2(61, vector<mint>(61)); // iまで見てj個bitが立っているものの総和
    dp1[0][0] = 1; dp1[0][1] = 1;
    dp2[0][0] = 0; dp2[0][1] = 1;

    for(int i=0; i<60; i++) {
        for(int j=0; j<60; j++) {
            dp1[i+1][j+1] += dp1[i][j]; // i+1 bit目が1
            dp1[i+1][j] += dp1[i][j]; // i+1 bit目が0
            dp2[i+1][j+1] += ((mint)((ll)1<<(i+1))) * dp1[i][j] + dp2[i][j]; // i+1 bit目が1
            dp2[i+1][j] += dp2[i][j]; // i+1 bit目が0
        }
    }

    while(T--) {
        ll N,K;
        cin >> N >> K;
        int dg;
        vector<int> lmt(61);        
        rep(i,61) {
            lmt[i] = N%2;
            N/=2;
            if(N==0) {
                dg = i;
                break;
            }
        }        
        auto f = [&](auto f, int cur, int nm)->pair<mint,mint> {
            if(nm==0) return {0, 1};
            if(cur==0){
                if(nm>1) return {0, 0};
                else if(nm==1) {
                    if(lmt[0]==0) return {0, 0};
                    else return {1, 1};
                }
                else return {0, 1};
            }
            mint sm = 0, m = 0;
            if(lmt[cur] == 1) {                
                sm += dp2[cur-1][nm]; // cur bit目が0
                m += dp1[cur-1][nm];
                auto [sm2, m2] = f(f, cur-1, nm-1); // cur bit目が1 -> cur-1 bit目まで見てnm-1個
                sm += (mint)((ll)1<<cur) * m2;
                sm += sm2;
                m+=m2;            
            } else {                
                auto [sm2, m2] = f(f, cur-1, nm);
                sm += sm2;
                m = m2;            
            }
            /* cout<<cur<< " "<<nm<<" "<<sm.val()<<" "<<m.val()<<endl; */
            return {sm, m};
        };
        auto [ans, m] = f(f, dg, K);
        cout << ans.val() << endl;
    }
    return 0;
} 