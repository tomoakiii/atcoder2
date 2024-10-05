#include <bits/stdc++.h>
using namespace std;

int main(){
    int Q;
    cin >> Q;
    int a, b;
    vector<long long> v;
    while(Q--){
        cin >> a >> b;
        if (a==1) v.push_back(b);
        else{
            cout << v[v.size()-b]<<endl;
        }
    }
    return 0;
}

