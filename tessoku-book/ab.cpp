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
    ll N; cin>>N;
    ll st = 0;
    ll M = 10000;
    while(N--) {
        char T; ll A; cin>>T>>A;
        if(T=='+') st+=A;
        else if(T=='-') st=st+M-A;
        else st*=A;
        st %= M;
        cout << st << endl;
    }
    return 0;
}