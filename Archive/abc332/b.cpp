#include <bits/stdc++.h>
using namespace std;

int main(){
    int K, G, M;
    cin >> K >> G >> M;
    int gsum = 0, msum = 0;
    for (int i=1; i<=K; i++){
        if (gsum == G){
            gsum=0;
        } else if (msum == 0) {
            msum = M;
        } else {
            int move = min(G-gsum, msum);
            gsum += move;
            msum -= move;
        }
    }

    cout << gsum << " " << msum << endl;
    return 0;
}