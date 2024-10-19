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
    ll T;
    cin >> T;
    while(T--){
        ll N;
        cin >> N;
        vector<ll> A(N, 0);
        rep(i,N) cin>>A[i];
        ll last = A[0];
        ll bdt = 0, ngt = 0;
        bool flg = true;
        ll sm = A[0];
        for(int i=1; i<N; i++){
            ll d = A[i] - A[i-1];
            if (d < 0) {
                d *= -1;
                A[i] += d;                
                ngt += d;
                sm += A[i];
            } else {
                if (d < ngt) {
                    A[i] -= d;
                    ngt -= d;
                } else {
                    A[i] -= ngt;
                    ngt = 0;
                }
                sm += A[i];
                ll avg = (sm+i) / (i+1);
                A[i] = avg;
            }            
        }
        if (ngt > 0) {
            cout << "No" << endl;            
        } else {
            cout << "Yes" << endl;
        }
   }
    return 0;
}