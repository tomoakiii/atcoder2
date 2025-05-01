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
    ll N;
    cin >> N;
    vector<string> S(2001);
    vector<ll> cnt(2001, INF);
    S[0] = "0"; cnt[0] = 1;
    S[1] = "1"; cnt[1] = 1;
    S[11] = "11"; cnt[11] = 2;
    S[111] = "111"; cnt[111] = 3;
    S[1111] = "1111"; cnt[1111] = 4;
    for(int k = 2; k <= N; k++) {
        if(cnt[k] > cnt[k-1] + 2) {
            cnt[k] = cnt[k-1] + 2;
            S[k] = S[k-1] + "+1";
            for(int p = 1; p <= k; p++) {
                if(cnt[k+p] > cnt[k] + cnt[p] + 1) {
                    cnt[k+p] = cnt[k] + cnt[p] + 1;
                    S[k+p] = S[k] + "+" + S[p];
                }
            }
            for(int p = 2; p*k <= N && p <= k; p++) {
                if(cnt[k*p] > (cnt[p] + 2) + (cnt[k] + 2) + 1) {
                    cnt[k*p] = (cnt[p] + 2) + (cnt[k] + 2) + 1;
                    S[k*p] = "(" + S[p] + ")*(" + S[k] + ")";
                }
            }            
        }
    }
    cout << S[N] << endl;
    return 0;
}