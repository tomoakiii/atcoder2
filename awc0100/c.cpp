#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (ll i = 0; i < (n); ++i)
template<typename T> inline bool chmax(T &a, T b) { return ((a < b) ? (a = b, true) : (false)); }
template<typename T> inline bool chmin(T &a, T b) { return ((a > b) ? (a = b, true) : (false)); }

typedef unsigned long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const int INFi = 0x0F0F0F0F;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll N,L,Q;
    cin >> N>>L>>Q;
    vector<ll> Sb(N);
    rep(i,N){
        string S; cin>>S;
        ll x=0;
        for(auto c:S){
            x<<=1;
            if(c=='1') x+=1;
        }
        Sb[i]=x;
    }
    while(Q--){
        int M; cin>>M;
        ll ans=0;
        while(M--){
            int c; cin>>c; c--;
            ans |= Sb[c];
        }
        string as;
        while(ans){
            as.push_back('0'+ans%2);
            ans/=2;
        }
        while(as.size()<L)as.push_back('0');
        reverse(as.begin(),as.end());
        cout<<as<<endl;
    }
    return 0;
}