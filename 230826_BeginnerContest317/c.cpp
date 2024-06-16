#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;

int main()
{    
    ll N, M;
    cin >> N >> M;
    vector R(N, vector<ll>(N));
    ll A, B, C;
    while(M--) {
        cin >> A >> B >> C;
        A--, B--;
        R[A][B] = C;
        R[B][A] = C;
    };

    ll ans = 0;
    auto func = [&](auto func, int nd, vector<bool> v, ll d) -> void {
        ll mx = 0;
        v[nd] = true;
        for(int i=0; i<N; i++){
            if (R[nd][i] == 0) continue;
            if (!v[i]) {                
                ans = max(ans, d+R[nd][i]);
                func(func, i, v, d + R[nd][i]);
            }
        }        
    };
    vector <bool> visit(N, false);
    for (int i = 0; i<N; i++){
        func(func, i, visit, 0); 
    }
    cout << ans << endl;
    return 0;
}