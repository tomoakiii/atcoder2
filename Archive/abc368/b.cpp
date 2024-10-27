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
    rep(i,N) cin>>A[i];
    int cnt = 0;
    sort(A.begin(), A.end());
    while(A[N-2]>=1){        
        A[N-1]--;
        A[N-2]--;
        cnt++;
        sort(A.begin(), A.end());
    }
    cout << cnt << endl;
    return 0;
}