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
    vector<ll> A,B;
    rep(i,N) {
        ll a; cin>>a;
        if(a<0) B.push_back(-a);
        else A.push_back(a);
    }
    ll sm = 0;
    rep(kkk,2){
        if(!A.empty()){
            sort(A.begin(),A.end());
            ll last = 0;
            rep(i, A.size()) {
                sm += A[i]-last;
                last = A[i];
            } 
            sm += A.back();
        }
        swap(A,B);
    }
    cout << sm << endl;
    return 0;
}