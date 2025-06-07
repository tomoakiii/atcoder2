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
    ll N,M;
    cin>>N>>M;
    vector<ll> A(M), B(M),C(M),D(M);    
    rep(i,M) {
        cin>>A[i]>>B[i];
        A[i]--, B[i]--;
    }
    rep(i,M) {
        cin>>C[i]>>D[i];
        C[i]--, D[i]--;
    }
    vector<ll> arr(N);
    rep(i,N) arr[i] = i;
	
    bool ans = false;
    do {
        bool ok = true;
        rep(i,M) {
            int a = A[i], b = B[i];
            if(a>b) swap(a,b);
            bool flg = false;
            rep(j,M) {
                int a2 = arr[C[j]], b2 = arr[D[j]];
                if(a2>b2) swap(a2,b2);
                if(a==a2 && b==b2) {
                    flg = true;
                    break;
                }
            }
            if(!flg) {
                ok = false;
            }
        }
        if(ok) {
            ans = true;
            break;
        }
	} while (next_permutation(arr.begin(), arr.end()));
    if(ans) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}