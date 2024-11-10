#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)

typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const int INFi = 0x0F0F0F0F;
using mint = modint998244353;

int main(){
    ll N, K;
    cin >> N >> K;
    string S;
    cin >> S;
    vector<map<string, mint>> dp(N+1);
    map<string, bool> mp;
    
    auto f_jdg = [&](string s)-> bool {
        bool b=true;
        rep(i, K/2) {
            if (s[i] != s[K-1-i]) b=false;
        }
        return b;
    };

    auto f2 = [&](auto f2, int d)->void{
        string s21;
        for(auto m: dp[d]) {
            string s = m.first;
            for (char c='A'; c<='B'; c++){
                if (S[d]=='A' && c=='B') continue;
                if (S[d]=='B' && c=='A') continue;
                string ss = s+c;
                if (ss.length() < K) {
                    dp[d+1][ss] = 1;
                } else {
                    if (mp.find(ss) == mp.end()){
                        mp[ss] = f_jdg(ss);
                    }
                    string sss = ss.substr(1, K-1);
                    if (!mp[ss]) {
                        dp[d+1][sss] += dp[d][s]; 
                    }
                }
            }
        }
        if (d==N-1){
            return;
        }else{
            f2(f2, d+1);
        }
    };

    dp[0][""] = 1;
    f2(f2, 0);

    mint ans = 0;
    for(auto m: dp[N]) {
        ans += m.second;
    }
    cout << ans.val() << endl;
    return 0;
}