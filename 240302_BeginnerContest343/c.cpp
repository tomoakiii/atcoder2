#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;

bool isK(ll x){
    ll y=x;
    int k=0;
    vector<int> C;
    while (y>0){
        C.push_back(y%10);
        y/=10;
        k++;
    }
    for (int i=0; i<k; i++){
        if (C[i] != C[k-i-1]) return false;
    }
    return true;
    
}


int main(){
    ll N;
    cin >> N;
    vector<ll> box;
    
    for (ll i=0; i*i*i <= N; i++) box.push_back(i*i*i);
    for (int k=box.size()-1; k>=1; k--){
        if (isK(box[k])) {
            cout << box[k] << endl;
            return 0;
        }
    }
    return 0;
}

