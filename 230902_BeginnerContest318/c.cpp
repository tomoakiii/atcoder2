#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
int main(){
    int N, D;
    ll P;
    cin >> N >> D >> P;
    vector<ll> F(N+1);
    for (int i=1; i<=N; i++){
        cin >> F[i];
    }
    sort(F.begin(), F.end());
    for (int i=1; i<=N; i++){
        F[i] += F[i-1];
    }
    ll ans = INF;
    for (int i=0; (i-1)*D < N; i++){
        ll cst = i*P;
        ll x = N - min(i*D, N);
        cst += F[x];
        ans = min(ans, cst);
    }
    cout << ans << endl;
    return 0;
}