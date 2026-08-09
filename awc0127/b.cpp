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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll N,Q;
    cin >> N >> Q;
    string S;
    cin >> S;
    ll cnt=0;
    rep(i,N-1){
        if(S[i]==S[i+1]) cnt++;
    }
    rep(i,Q){
        int j; char c;
        cin >> j >> c; j--;
        if(j>0) if(S[j]==S[j-1]) cnt--;
        if(j<N-1) if(S[j]==S[j+1]) cnt--;
        S[j] = c;
        if(j>0) if(S[j]==S[j-1]) cnt++;
        if(j<N-1) if(S[j]==S[j+1]) cnt++;
        cout << cnt << endl;
    }
    return 0;
}