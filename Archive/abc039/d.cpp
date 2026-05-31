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
int dy[] = {-1,-1,-1,0,1,1,1,0};
int dx[] = {-1,0,1,1,1,0,-1,-1};
ll H,W;


void print(vector<string> &S){
    rep(i,H) {
        rep(j,W) cout<<S[i][j];
        cout<<endl;
    }
}

void fnc(vector<string> &S, vector<string> &newS) {
    rep(i,H) rep(j,W) {
        if(newS[i][j] == '#') continue;
        rep(k,8) {
            int ny = dy[k] + i;
            int nx = dx[k] + j;
            if(ny >= H || ny < 0 || nx >= W || nx < 0)continue;
            if(S[ny][nx] == '#') newS[i][j] = '#';
        }
    }
}

void fnc2(vector<string> &S, vector<string> &newS) {
    rep(i,H) rep(j,W) {
        if(newS[i][j] == '.') continue;
        rep(k,8) {
            int ny = dy[k] + i;
            int nx = dx[k] + j;
            if(ny >= H || ny < 0 || nx >= W || nx < 0)continue;
            if(S[ny][nx] == '.') newS[i][j] = '.';
        }
    }
    //cerr<<endl;
    //print(newS);
}

bool chk(vector<string> &S, vector<string> &S2){
    rep(i,H) rep(j,W) {
        if(S[i][j] != S2[i][j]) return false;
    }
    return true;
}

int main(){
    cin>>H>>W;
    vector<string> S(H);
    rep(i,H) cin>>S[i];
    vector newS = S;
    fnc2(S, newS);
    //cerr<<endl;
    //print(newS);
    vector newS2 = newS;
    fnc(newS, newS2);
    if(chk(newS2, S)) {
        cout<<"possible"<<endl;
        print(newS);
    } else {
        cout<<"impossible"<<endl;
    }
    return 0;
}