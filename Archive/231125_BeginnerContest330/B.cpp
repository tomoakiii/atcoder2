#include <bits/stdc++.h>
using namespace std;

int main(){

    int N, L, R;
    cin >> N >> L >> R;
    int A;
    for (int i=1; i<=N; i++){
        cin >> A;
        if (L >= A){
            cout << L << " ";
        }else if (R <= A){
            cout << R << " ";
        }else {
            cout << A << " ";
        }
    }
    cout << endl;

    return 0;
}