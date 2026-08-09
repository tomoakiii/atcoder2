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
    ll N,M,K;
    cin >> N >> M >> K;
    vector<ll> A(N);
    rep(i,N) {
        cin>>A[i];
        if(A[i]>K) {
            cout<<"Yes"<<endl;
            return 0;
        }
    }
    ll ng=0, ok=1e16;
    while(ok-ng>1){
        ll mid=(ok+ng)/2;
        ll cnt=0;
        ll tmp=mid+1;
        rep(i,N) {
            if(A[i]+tmp>mid) {
                cnt++;
                tmp = A[i];
            } else {
                tmp+=A[i];
            }
        }
        if(cnt<=M) ok=mid;
        else ng=mid;
    }
    //cout<<ok<<endl;
    if(ok>K) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}