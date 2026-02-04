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
typedef pair<ll, pair<int,int>> pl;

int main(){
    ll N,A,B; cin>>N>>A>>B;
    vector<int> visit(N+1, -1);
    auto func = [&](auto func, ll cur)->bool{
        if(visit[cur] != -1) return (visit[cur]);
        if(cur < A) visit[cur] = 0;
        else if(func(func, cur-A) == 0) visit[cur] = 1;
        else if(cur < B) visit[cur] = 0;
        else if(func(func, cur-B) == 0) visit[cur] = 1;
        else visit[cur] = 0;
        return visit[cur];
    };
    int ans = func(func, N);
    rep(i,N+1) cerr<<visit[i]<<endl;
    if(ans == 1) cout<<"First"<<endl;
    else cout<<"Second"<<endl;
    return 0;
}