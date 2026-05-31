#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (ll i = 0; i < (n); ++i)
template<typename T> inline bool chmax(T &a, T b) { return ((a < b) ? (a = b, true) : (false)); }
template<typename T> inline bool chmin(T &a, T b) { return ((a > b) ? (a = b, true) : (false)); }

typedef long long ll;
const ll INF = 0x7F7F7F7F7F7F7F7F;
const int INFi = 0x7F0F0F0F;

int main(){
    ll H,W;
    cin >> H >> W;
    vector<string> S(H);
    rep(i,H) cin>>S[i];
    int dy[]={1,-1,0,0};
    int dx[]={0,0,1,-1};
    rep(i,H)rep(j,W){
        if(S[i][j]=='.')continue;
        int cnt=0;
        rep(k,4){
            int ny=dy[k]+i;
            int nx=dx[k]+j;
            if(ny<0||ny>=H||nx<0||nx>=W)continue;
            if(S[ny][nx]=='#')cnt++;
        }
        if(cnt==0||cnt>3){
            cout<<"No"<<endl;
            return 0;
        }
    }
    cout<<"Yes"<<endl;
    return 0;
}