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
    vector<bool> visit(N+1);
    for(int k=3; k<=N; k+=3) visit[k]=true;
    for(int k=5; k<=N; k+=5) visit[k]=true;
    ll sm = 0;
    rep(i,N+1) if(!visit[i]) sm+=i;
    cout<<sm<<endl;
    return 0;
}