#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;

int main () {
    ll n = 1;
    vector<ll> a;


    while (n!= 0){
        cin >> n;
        a.push_back(n);
    }
    for (auto itr = a.end()-1; itr >= a.begin(); itr--){
        cout << *itr << endl;
    }

    return 0;
}

