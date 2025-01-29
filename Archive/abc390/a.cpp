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
    const int N = 5;
    vector<ll> A(N);
    rep(i,N) {
        cin>>A[i];
        A[i]--;
    }
    ll cnt = 0;
    rep(i,N-1) {
        vector AA = A;
        swap(AA[i], AA[i+1]);
        bool flg = true;
        rep(j, N) {
            if (AA[j] != j) flg = false;
        }
        if(flg) {
            cout << "Yes" << endl;
            return 0;
        }
        
    }
    cout<<"No"<<endl;
    return 0;
}