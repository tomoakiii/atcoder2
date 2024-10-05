#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)

typedef unsigned long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const int INFi = 0x0F0F0F0F;

int main(){
    ll N;
    string S;
    cin >> S;
    cin >> N;
    ll sm = 0;
    reverse(S.begin(), S.end());
    for(int i=0; i<S.size(); i++) {
        if (S[i] == '1') {
            sm += ((ll)1<<i);
        }
    }
    if (sm > N){
        cout << -1 << endl;
        return 0;
    }

    for(int i=S.size()-1; i>=0; i--){
        if (S[i] != '?') continue;
        ll k = ((ll)1<<i);
        if (sm+k <= N) {
            sm += k;
        }
    }
    cout << sm << endl;
    return 0;
}