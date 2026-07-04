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
    ll N;
    cin >> N;
    deque<ll> A(N);
    deque<ll> B;
    rep(i,N) cin>>A[i];
    sort(A.begin(),A.end());
    B.push_back(A.back());
    A.pop_back();
    while(!A.empty()){
        ll d1=abs(B.front() - A.front());
        ll d2=abs(B.back() - A.front());
        ll d3=abs(B.front() - A.back());
        ll d4=abs(B.back() - A.back());
        if(d1>=d2 && d1>=d3 && d1>=d4){
            B.push_front(A.front());
            A.pop_front();
        }else if(d2>=d1 && d2>=d3 && d2>=d4){
            B.push_back(A.front());
            A.pop_front();
        }else if(d3>=d1 && d3>=d2 && d3>=d4){
            B.push_front(A.back());
            A.pop_back();
        }else{
            B.push_back(A.back());
            A.pop_back();
        }
    }
    ll ans=0;
    rep(i,N-1){
        ans+=abs(B[i]-B[i+1]);
    }
    cout<<ans<<endl;
    return 0;
}