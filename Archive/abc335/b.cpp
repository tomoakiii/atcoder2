#include <bits/stdc++.h>
using namespace std;

int main(){
    int N, x, y, z;
    cin >> N;
    for(int x=0; x<=N; x++)
        for(int y=0; y<=N-x; y++)
            for(int z=0; z<=N-x-y; z++)
                cout << x << " " << y << " " << z << endl;
    return 0;
}

