#include <bits/stdc++.h>
using namespace std;

int main(){
    long long N;
    cin >> N;
    int a[24];
    long long f=0;
    int i2;
    N--;
    for (int i=0; i<24; i++){
        a[i] = (N%5) * 2;
        N/=5;
        if (N==0) {
            i2=i;
            break;
        }
    }
    for (int i=i2; i>=0; i--){
        cout << a[i];
    }
    cout << endl;
    return 0;
}

