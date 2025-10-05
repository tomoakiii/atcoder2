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
    int T; cin>>T;
    while(T--) {
        int N; cin>>N;
        string S; cin>>S;
        int last0 = 0, last1 = 0;
        int m0=0, m1=0;
        int cnt0=0, cnt1=0;
        char lc = '2';
        for(auto c: S) {
            if(c == lc) {
                if(c == '0') {
                    last0++;
                } else {
                    last1++;
                }
            } else {
                if(c == '0') {
                    last0 = 1;
                } else {
                    last1 = 1;
                }
                lc = c;
            }
            chmax(m0, last0);
            chmax(m1, last1);
            if(c == '0') {
                cnt0++;
            } else {
                cnt1++;
            }
        }
        ll ans = 0;        
        ans += 2*(cnt0 - m0);
        ans += cnt1;
        ll ans1 = 0;
        ans1 += 2*(cnt1 - m1);
        ans1 += cnt0;
        cout << min(ans,ans1) << endl;
    }
    return 0;
}