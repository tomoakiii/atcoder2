#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;



int main(){
    int N;
    cin >> N;
    vector<ll> A(N), C(N);
    for(int i=0; i<N; i++) {
        cin >> A[i] >> C[i];
    }

    map<ll, ll> mp;
    for (int i=0; i<N; i++){
        if (mp.find(C[i]) != mp.end()){
            mp[C[i]] = min(mp[C[i]], A[i]);
        } else {
            mp[C[i]] = A[i];
        }
    }

    ll ans = 0;
    for (auto  it = mp.begin(); it != mp.end(); it++){
        ans = max(ans, it->second);
    }


    cout << ans << endl;
    
    return 0;
}