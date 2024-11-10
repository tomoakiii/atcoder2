#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)

typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const int INFi = 0x0F0F0F0F;

int main(){
    ll N, K;
    cin >> N >> K;
    vector<int> A(N);
    ll Kt = K;
    rep(i, N) cin >> A[i];
    int i=0, cnt=0;
    bool last;
    while(i<N) {
        if (Kt >= A[i]) {
            Kt-=A[i];
            i++;
            last = true;
        } else {
            Kt=K;
            cnt++;
            last = false;
        }
    }
    if(last) {cnt++;}
    cout << cnt << endl;
    return 0;
}