#include <bits/stdc++.h>
using namespace std;



int main(){
    int N;
    cin >> N;
    int a;
    cin >> a;
    int a2;
    for (int i=1; i<N; i++){
        cin >> a2;
        cout << a2 * a << " ";
        a = a2;
    }
    cout << endl;
    
    return 0;
}