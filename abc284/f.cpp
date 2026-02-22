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
    string T;
    cin >> T;
    string S1(N/2,'A'), S2(N/2,'A');
    rep(i,N/2){
        S1[i] = T[i];
        S2[i] = T[N+i];
    }
    int l = N/2;
    int r = N/2;
    if(N%2==0) {
        l--;
    }
    bool flg = true;
    int ans;
    while(l>=0){
        if(flg){
            if(S1[l] != S2[l+N] || S1[r] != S2[r]) {
                flg = false;
                ans = l;
                if(S1[l] != S2[r] || S1[r] != S2[l]) {
                    cout << -1 << endl;
                    return 0;
                }
            }
        } else {
            if(S1[l] != S2[r] || S1[r] != S2[l]) {
                cout << -1 << endl;
                return 0;
            }
        }
        l--, r++;
    }
    cout << ans << endl;
    cout << S1 << endl;    
    return 0;
}