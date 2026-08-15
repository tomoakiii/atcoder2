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
    vector<ll> A(N);
    ll cnt = 0;
    ll pow = 0;
    ll r = 0;
    rep(i,N){
        while(r < N){
            pow += (S[r]=='o');
            if(pow == 0) break;
            r++;
            pow--;
        }
        pow++;
        A[i] = min(r+1,N);

    }

    for(auto a:A) cout<<a<<endl;

    return 0;
}