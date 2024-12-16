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
    ll N, S;
    cin >> N >> S;

    vector<ll> A(N);
    
    int l = 0;
    ll sm = 0;
    rep(i,N) {
        cin>>A[i];
        sm += A[i];
    }
    ll d = S/sm;
    
    sm *= (d+1);

    rep(r, N) {
        sm += A[r];
        if(sm == S) {
            cout << "Yes" << endl;
            return 0;
        }
        while(sm > S) {
            sm -= A[l];
            l++;
            l%=N;
        }
        if(sm == S) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}