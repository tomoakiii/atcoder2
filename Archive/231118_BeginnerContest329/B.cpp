#include <bits/stdc++.h>
using namespace std;

int main(){

    int N;
    cin >> N;    
    priority_queue<int> A;
    int maxa = 0;

    for (int i=0; i<N; i++){
        int a;
        cin >> a;
        A.push(a);
        maxa = max(a, maxa);
    }

    while(!A.empty()){
        int a;
        a = A.top();
        A.pop();
        if (a != maxa){
            cout << a << endl;
            return 0;
        }
    }
    return 0;
}