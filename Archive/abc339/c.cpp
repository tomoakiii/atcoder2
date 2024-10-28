#include <bits/stdc++.h>
using namespace std;


int main(){
    int N;
    cin >> N;
    const long long INF = 0x0f0f0f0f0f0f0f0f;
    long long c = 0, a, mm = INF;
    while(N--){
        cin >> a;
        c += a;
        mm = min(c, mm);
    }
    if (mm >= 0)  cout << c << endl;
    else cout << -1*mm + c << endl;
    return 0;
}

