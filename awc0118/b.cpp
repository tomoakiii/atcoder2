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
    ll N,K;
    cin >> N >> K;
    deque<ll> A(N);
    rep(i,N) cin>>A[i];
    sort(A.begin(),A.end());
    ll ans=0;
    while(A.size()>=2){
        if(abs(A[0]-A[1])<=K){
            ans++;
            A.pop_front();A.pop_front();
        } else{
            A.pop_front();
        }
    }
    cout<<ans<<endl;
    return 0;
}