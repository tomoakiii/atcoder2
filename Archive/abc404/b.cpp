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
    vector<string> S(N), T(N);
    rep(i,N) cin>>S[i];
    rep(i,N) cin>>T[i];
    vector S1 = S, S2 = S, S3 = S;
    ll cnt = 0;
    rep(i,N)rep(j,N) {
        S1[N-j-1][i] = S[i][j];
        S2[j][N-i-1] = S[i][j];
        S3[N-i-1][N-j-1] = S[i][j];
        if(T[i][j] != S[i][j]) cnt++;
    }
    ll mn = cnt;

    cnt = 3;
    rep(i,N)rep(j,N) if(T[i][j] != S1[i][j]) cnt++;
    chmin(mn, cnt);
    
    cnt = 1;
    rep(i,N)rep(j,N) if(T[i][j] != S2[i][j]) cnt++;
    chmin(mn, cnt);

    cnt = 2;
    rep(i,N)rep(j,N) if(T[i][j] != S3[i][j]) cnt++;
    chmin(mn, cnt);




    cout << mn << endl;
    return 0;
}