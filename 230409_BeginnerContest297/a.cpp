#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int N;
    ll D;
    cin >> N >> D;
    ll t1, t2=-D;
    for(int i=0; i<N; i++){
        cin >> t1;
        if (t1-t2 <= D) {
            cout << t1 << endl;
            return 0;
        }
        t2 = t1;
    }
    cout << -1 << endl;
    return 0;
}