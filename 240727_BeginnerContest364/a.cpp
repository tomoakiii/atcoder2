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
    string S;
    bool last = true;
    rep(i, N-1) {
        cin >> S;        
        if(S == "sweet") {
            if (!last) {
                cout << "No" << endl;
                return 0;
            }
            last = false;
        } else {
            last = true;
        }
    }
    cin >> S;
    cout << "Yes" << endl;
    return 0;
}