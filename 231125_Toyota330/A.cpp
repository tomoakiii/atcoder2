#include <bits/stdc++.h>
using namespace std;

int main(){

    int N, L, A;
    cin >> N >> L;
    int cnt = 0;
    for (int i=1; i<=N; i++){
        cin >> A;
        if (A >= L){
            cnt++;
        }
    }
    cout << cnt << endl;

    return 0;
}