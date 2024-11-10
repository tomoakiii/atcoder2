#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)

typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const int INFi = 0x0F0F0F0F;

int main(){
    ll N, A, B;
    cin >> N >> A >> B;
    rep(i, N) {
        int c;
        cin >> c;
        if (c == A+B) {
            cout << (i+1) << endl;
            return 0;
        }
    }
    
    return 0;
}