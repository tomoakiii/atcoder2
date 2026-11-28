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
    ll H,W; cin>>H>>W;
    vector<string> S(H);
    rep(i,H) cin>>S[i];
    int dy[]={0,-1,0,1,0};
    int dx[]={0,0,-1,0,1};
    int Q; cin>>Q;
    while(Q--){
        int r,c; cin>>r>>c; r--,c--;
        rep(k,5){
            int ny=dy[k]+r;
            int nx=dx[k]+c;
            if(ny<0||ny>=H||nx<0||nx>=W)continue;
            if(S[ny][nx]=='1')S[ny][nx]='0';
            else S[ny][nx]='1';
        }
    }
    rep(i,H)cout<<S[i]<<endl;
    return 0;
}