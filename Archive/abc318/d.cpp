#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
int main(){
    int N;    
    cin >> N;
    vector<ll> A(N);
    map<ll, vector<int>> mp;
    for(int i = 0; i<N; i++) {
        cin>>A[i];
        mp[A[i]].push_back(i);
    }
    ll ans = 0;
    for (auto it = mp.begin(); it != mp.end(); it++){
        ll sz = it->second.size();
        ll r = sz-1, l = 1;
        for (int i = 1; i < sz; i++){
            ll len = it->second[i] - it->second[i-1] - 1;
            ans += len * (l * r);
            l++, r--;
        }
    }
    
    cout << ans << endl;
    return 0;
}