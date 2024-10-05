#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const int INFi = 0x0F0F0F0F;


int main(){
    int x = 0, y = 0;
    int k1, k2;
    for(int i=1; i<=9;i++) {
        cin >> k1;
        x+=k1;        
    }
    for(int i=1; i<=8;i++) {
        cin >> k2;
        y+=k2;        
    }
    cout << max(0, x-y+1) << endl;
    return 0;
}