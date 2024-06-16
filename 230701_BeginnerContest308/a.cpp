#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)

typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const int INFi = 0x0F0F0F0F;

int main(){
    ll S, lastS = 0;
    
    rep (i, 8) {
        cin >> S;
        if (S < 100 || S > 675 || S%25 != 0 || S < lastS){
            cout << "No" << endl;
            return 0;
        }
        lastS = S;
    }
    
    cout << "Yes" << endl;
    return 0;
}