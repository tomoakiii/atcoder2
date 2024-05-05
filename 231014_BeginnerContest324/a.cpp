#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const ll INFi = 0x0F0F0F0F;


int main(){
    ll N;
    cin >> N;
    ll last = -1;
    ll a;
    for (ll i=0; i<N; i++){
        cin >> a;
        if (last == -1) last = a;
        else if (a != last){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}