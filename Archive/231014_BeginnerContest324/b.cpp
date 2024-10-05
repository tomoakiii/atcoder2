#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const ll INFi = 0x0F0F0F0F;


int main(){
    ll N;
    cin >> N;
    while (true) {
        if (N%2 == 0) N/=2;
        else break;
    }
    while (true) {
        if (N%3 == 0) N/=3;
        else break;
    }
    if (N == 1) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}