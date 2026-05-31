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
    ll T;
    cin>>T;
    while(T--) {
        ll N;
        cin >> N;
        string S;
        cin>>S;
        char lst = -1;
        int stage = 0;
        char l;
        string ans = "";
        rep(i,N) {
            char c = S[i];
            if(stage == 0) {
                if(i == N-1) {
                    ans.push_back(S[i]);
                }
                else if(S[i] > S[i+1]) {
                    stage = 1;
                    l = S[i];
                } else {
                    ans.push_back(S[i]);
                }
            } else if (stage == 1) {
                if(l < S[i]) {
                    stage = 2;
                    ans.push_back(l);
                }                
                ans.push_back(S[i]);
            } else {
                ans.push_back(S[i]);
            }
            lst = c;
        }
        if(stage == 1) {
            ans.push_back(l);
        }
        cout<<ans<<endl;
    }
    return 0;
}