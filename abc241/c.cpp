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
    int N;
    cin >> N;
    vector<string> S(N);
    rep(i,N) cin>>S[i];
    auto jdg = [&](int y, int x)->bool{
      int c = 100, t = 0;
      rep(i, 6) {
        if(x+i>=N) t=100;
        else if(S[y][x+i] == '.') t++;
      }
      chmin(c,t);
      t=0;
      rep(i, 6) {
        if(y+i>=N) t=100;
        else if(S[y+i][x] == '.') t++;
      }
      chmin(c,t);
      t=0;
      rep(i, 6) {
        if(y+i>=N || x+i>=N) t=100;
        else if(S[y+i][x+i] == '.') t++;
      }
      chmin(c,t);
      t=0;
      rep(i, 6) {
        if(y-i<0 || x+i>=N) t=100;
        else if(S[y-i][x+i] == '.') t++;
      }
      chmin(c,t);
      return (c<=2);
    };
    
    rep(i,N) rep(j,N) {
      if(jdg(i, j)){
        cout<<"Yes"<<endl;
        return 0;
      }
    }
    
    cout<<"No"<<endl;
    return 0;
}
