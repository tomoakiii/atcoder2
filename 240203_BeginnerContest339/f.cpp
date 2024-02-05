#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MODN = 4;

int main() {
    int N;
    cin >> N;
    string s;
    map<vector<ll>, int> mp;

    long long MOD3[MODN] = {1000000007, 924844033, 2147483647, 1224736769};
    for(int a=0; a<N; a++){
        cin >> s;
        vector<ll> am(MODN, 0); 
        for (int i=0; i<MODN; i++){
            for (auto c:s) {
                am[i] *= 10;
                am[i] += c-'0';
                am[i] %= MOD3[i];
            }
        }
        mp[am]++;
    }

    int cnt = 0;
    for(auto it = mp.begin(); it != mp.end(); it++){
        for(auto it2 = mp.begin(); it2 != mp.end(); it2++ ){
            vector<ll> am(MODN, 0);
            for (int i=0; i<MODN; i++){
                am[i] = it->first[i] * it2->first[i] % MOD3[i];
            }
            if(mp.find(am) == mp.end()) continue;
            cnt += it->second * it2->second * mp[am];
        }
    }
    cout << cnt << endl;
}
