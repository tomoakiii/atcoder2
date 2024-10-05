#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)

typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const int INFi = 0x0F0F0F0F;

int main(){
    ll N, M, K;
    cin >> N >> M >> K;
    vector A(M, vector<int>{});
    vector<char> R(M);
    rep(i, M) {
        int c;
        cin >> c;
        A[i].resize(c);
        rep(j, c) {            
            cin >> A[i][j];
            A[i][j]--;
        }
        cin >> R[i];
    }
    ll cnt = 0;
    for(int k = 0; k <= ((1<<N)-1) ; k++) {
        bool res = true;
        rep(i, M) {
            ll kn = 0;            
            rep(j, A[i].size()){
                int a = A[i][j];
                if ((k >> a) & 1) kn++;
            }
            if (kn >= K && R[i] == 'x') {
                res = false;
                break;
            }
            if (kn < K && R[i] == 'o') {
                res = false;
                break;
            }
        }
        if (res) cnt++;
    }
    
    cout << cnt << endl;
    return 0;
}