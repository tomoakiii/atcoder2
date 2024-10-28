#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const int INFi = 0x0F0F0F0F;


int main(){
    ll N, X, Y, Z;
    cin >> N >> X >> Y >> Z;    
    if(X > Y) swap(X, Y);
    if (Y>Z && Z>X) cout<<"Yes" <<endl;
    else  cout<<"No" <<endl;    
    return 0;
}