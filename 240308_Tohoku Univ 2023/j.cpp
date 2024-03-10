#include <bits/stdc++.h>
using namespace std;

int main () {
    int N;
    cin >> N;

    int Q;
    Q = 2*N;
    int pnt = 1;
    vector<int> get;
    get.push_back(pnt);
    vector<int> miss;
    vector<pair<int, int>> side;
    chat col;
    while(pnt < N){
        bool up = false;
        for(int n=pnt+1; n<=N; n++){
            cout << "? " << pnt << " " << n << endl;
            cin >> col;
            if (col == 'R'){
                get.push_back(n);
                side.push_back(make_pair(pnt, n));
                up = true;
                pnt = n;
                break;
            } else {
                miss.push_back(n);
            }
        }
        if (!up) break;
    }
    for (auto m: miss){
        for (auto g: get){
            cout << "? " << m << " " << g << endl;
            cin >> col;
            if (col == 'R'){
                side.push_back(make_pair(m, g));
                break;
            }
        }
    }
    
    return 0;
}

