#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)

typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const int INFi = 0x0F0F0F0F;

int main(){
    ll N;
    cin >> N;
    vector<ll> A(N);
    rep(i, N) {
        cin >> A[i];
    }
    sort(A.begin(), A.end());
    auto B=A;
    for(int i=N-1; i>=1; i--){
        B[i-1]+=B[i];
    }
    ll ans=0;
    rep(i,N-1){        
        auto it = lower_bound(A.begin(), A.end(), 100000000-A[i]);
        auto id = distance(A.begin(), it);
        if (id<=i) id=i+1;
        if(id>i+1){
            if(id != N){
                ll b = B[i+1] - B[id];
                ans += ((id-i-1)*A[i] + b);
            } else {
                ans += ((id-i-1)*A[i] + B[i+1]);
            }         
        }
        if (id < N){
            ans += (N-id)*(A[i]-100000000) + B[id];
        }             
    }
    cout << ans << endl;
    return 0;
}