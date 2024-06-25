#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)
typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const int INFi = 0x0F0F0F0F;
using mint = modint998244353;

int main(){
    ll N, M;
    cin >> N >> M;    
    mint cnt = 0;
    vector<int> dM(60), dN(60);
    int ind=0;
    ll N2=N, M2=M;
    while(M2 > 0) {
        dM[ind++] = M2%2;
        M2 /= 2;
    }
    map<ll, mint> memo;
    ind=0;
    auto func = [&](auto func, ll n)->mint{
        int ind=0;
        ll n2 = n;
        while(n2 > 0) {
            dN[ind++] = n2%2;
            n2 /= 2;
        }
        ind--;
        int nn = n - (1<<ind);
        mint tret = 0;
        if (nn > 0) {
            if (memo.count(nn) > 0) {
                mint t = func(func, nn);
                cnt = cnt + t;
                tret = tret + func(func, nn);
            }
            else cnt = cnt + memo[nn];
        }
        for (int i=0; i< ind; i++){
            if (dM[i]) cnt = cnt + (1<<(ind-1));
        }
        if (dM[ind]) cnt = cnt + n - (1<<ind) + 1;
    };
    func(func, N);
    cout << cnt.val() << endl;
    return 0;
}