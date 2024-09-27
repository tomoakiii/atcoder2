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
    int R,C;
    cin >> R >> C;
    vector<string> S(R);
    rep(i,R) cin>>S[i];
    
    rep(i,R) rep(j,C) {
        if (S[i][j] == '.' || S[i][j] == '#') continue;
        int p = S[i][j] - '0';
        for(int ny = i-p; ny <= i+p; ny++) for(int nx = j-p; nx <= j+p; nx++){
            if(ny < 0 || nx < 0 || ny >= R || nx >= C) continue;
            if (abs(ny-i) + abs(nx-j) <= p) {
                if (S[ny][nx] == '#') {
                    S[ny][nx] = '.';
                }
            }
        }
        S[i][j] = '.';
    }
    
    rep(i,R) cout << S[i] << endl;
    
    return 0;
}