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

    ll N; string S;
    cin >> N >> S;
    deque<ll> fr, ed;
    ll cnt=0;
    for(int i=N-1;i>=0;i--){
        if(S[i]=='o') cnt++;
        if(cnt%2==1) {
            fr.push_back(i+1);
        }else{
            ed.push_front(i+1);
        }
    }
    for(auto x:fr) cout<<x<<endl;
    for(auto x:ed) cout<<x<<endl;
    return 0;
}