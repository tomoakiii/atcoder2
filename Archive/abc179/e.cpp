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
    ll N,X,M;
    cin >> N >> X >> M;
    deque<ll> A;
    A.push_back(X);
    vector<bool> visit(M);
    visit[X] = true;
    ll nx = (X*X)%M;
    while(true) {
        if(visit[nx]) break;
        visit[nx] = true;
        A.push_back(nx);
        nx = (nx*nx)%M;
    }
    ll ans = 0;
    while(A[0] != nx) {
        N--;
        ans += A[0];
        A.pop_front();
        if(N==0) {
            cout<<ans<<endl;
            return 0;
        }
    }
    ll sm = 0;
    for(auto a:A) sm+=a;
    ll p = N/A.size();
    ans += sm * p;
    N -= p*A.size();
    rep(i,N) ans += A[i];
    cout<<ans<<endl;
    return 0;
}