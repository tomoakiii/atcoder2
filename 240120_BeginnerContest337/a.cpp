#include <bits/stdc++.h>
using namespace std;

int main(){
    int N, x, y, xs=0, ys=0;
    cin >> N;

    for (int i=1; i<=N; i++){
        cin >> x >> y;
        xs += x;
        ys += y;        
    }

    if (xs==ys){
        cout << "Draw" << endl;
    } else if (xs > ys){
        cout << "Takahashi" << endl;
    } else {
        cout << "Aoki" << endl;
    }
    
    return 0;
}