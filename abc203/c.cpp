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
    ll N,K;
    cin >> N >> K;
    vector<pair<ll,ll>> A(N);
    rep(i,N) {
        cin>>A[i].first>>A[i].second;
    }

    sort(A.begin(), A.end());
    ll st = 0;
    rep(i,N) {        
        if(A[i].first - st <= K) {
            K -= A[i].first - st;
            st = A[i].first;
            K += A[i].second;
        } else {
            cout << st+K << endl;
            return 0;
        }
    }    
    cout<<st+K<<endl;
    return 0;
}