#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;
    char look = 'A';
    for (auto c:s){
        if (c==look) continue;
        if (c==look+1){
            look+=1;
            continue;
        }
        if (c==look+2){
            look+=2;
            continue;
        } else {
            cout << "No" << endl;
            return 0;
        }
        
    }

    cout << "Yes" << endl;
    
    return 0;
}