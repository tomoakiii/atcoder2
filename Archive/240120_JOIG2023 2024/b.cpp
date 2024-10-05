#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

int main(){
    int N, D;
    cin >> N >> D;
    vector<int> A(2*N);
    for(int i=0; i<N*2; i++){
        cin >> A[i];
    }
    sort(A.begin(), A.end());
    for(int i=0; i<N*2; i+=2){
        if(A[i] + D < A[i+1]){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}

