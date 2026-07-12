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
typedef modint998244353 mint;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string Ns;
    cin >> Ns;
    //mint total = tonum;
    ll len = Ns.size();
    ll ful = 1ll<<10;
    vector dp1(vector(3, vector(2, vector(ful, vector<mint>(2))))); // k:mod3, p:visit, 0:even
    dp1[0][1][0][0] = 1;
    rep(i,len){
        vector dp2(vector(3, vector(2, vector(ful, vector<mint>(2))))); // k:mod3, p:visit, 0:even
        dp2[0][1][0][0] += dp1[0][1][0][0];
        dp2[0][1][1][0] += dp1[0][1][1][0];
        int a = Ns[i]-'0';
        // dp2[0][1][0][1] += dp1[0][1][0][0] + dp1[0][1][0][1];
        for(int j=0;j<=9;j++) { // next num;
            rep(S, ful) { // visit loop
                ll nS = S | (1ll<<j);
                for(int k=0;k<=2;k++){
                    int nk=(k+j)%3;
                    dp2[nk][0][nS][1] += dp1[k][0][S][1];
                    if(j<a) dp2[nk][0][nS][1] += dp1[k][0][S][0];
                    else if(j==a) dp2[nk][0][nS][0] += dp1[k][0][S][0];
                    if(S==0 && j>0){
                        if(j<a) dp2[nk][0][nS][1] += dp1[k][1][0][0];
                        else if(j==a) dp2[nk][0][nS][0] += dp1[k][1][0][0];
                        dp2[nk][0][nS][1] += dp1[k][1][0][1];
                    }
                }
            }

        }
        swap(dp1,dp2);
    }

    mint ans = 0;

    rep(a0,10){
        for(int a1=a0+1; a1<=9; a1++){
            for(int a2=a1+1; a2<=9; a2++){
                ll S = (1ll<<a0) | (1ll<<a1) | (1ll<<a2);
                set<int> st;
                st.insert(a0);
                st.insert(a1);
                st.insert(a2);
                int sz = st.size();
                if(!st.contains(3) && sz != 3) {
                    ans += dp1[0][0][S][0] + dp1[0][0][S][1]; // only 1
                }
                if(st.contains(3) && sz != 3) { // only 2
                    ans += dp1[1][0][S][0] + dp1[1][0][S][1]; // only 1
                    ans += dp1[2][0][S][0] + dp1[2][0][S][1]; // only 1
                } else if (!st.contains(3) && sz == 3) {// only 3
                    ans += dp1[1][0][S][0] + dp1[1][0][S][1]; // only 1
                    ans += dp1[2][0][S][0] + dp1[2][0][S][1]; // only 1
                }
            }
        }
    }
    cout << ans.val() << endl;

    return 0;
}