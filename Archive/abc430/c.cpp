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
    ll N,A,B; cin>>N>>A>>B;
    string S; cin>>S;
    int ca = 0, cb = 0;
    int amn = -1, bmx = N;
    rep(i,N) {
        if(S[i] == 'a') ca++;        
        if(ca == A) {
            amn = i;
            break;
        }
    }
    rep(i,N) {
        if(S[i] == 'b') cb++;
        if(cb == B) {
            bmx = i;
            break;
        }
    }
    ll ans = 0;        
    if(A == ca && bmx > amn) ans += bmx - amn;
    rep(i,N) {
        if(S[i] == 'a') ca--;
        else cb--;
        while(ca < A && amn < N) {
            amn++;
            if(amn == N) break;
            if(S[amn] == 'a') ca++;
        }
        while(cb < B && bmx < N) {
            bmx++;
            if(bmx == N) break;
            if(S[bmx] == 'b') cb++;
        }
        if(A == ca && bmx >= amn) ans += bmx - amn;
    }
    cout<<ans<<endl;

    return 0;
}