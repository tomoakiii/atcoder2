#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;

typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const int INFi = 0x0F0F0F0F;

int main(){
    ll N, P, Q;
    cin >> N >> P >> Q;
    ll mn = INF;
    for(int i=0; i<N;i++) {
        ll d;
        cin >> d;
        mn = min(mn, d);
    }
    cout << min(P, Q+mn) << endl;
    return 0;
}