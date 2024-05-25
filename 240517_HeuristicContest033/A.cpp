#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)

typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const int INFi = 0x0F0F0F0F;

struct xystruct{
    int x;
    int y;  
};

class bigCrane{
    public:
    xystruct xy;
    int holdContainer;
     bigCrane(int y, int x){
        xy.x = 0;
        xy.y = 0;
        holdContainer = -1;
    };
    private:
    
};

class smallCrane{
    public:
    xystruct xy;
    int holdContainer;
    smallCrane(int y, int x){
        xy.x = x;
        xy.y = y;
        holdContainer = -1;
    };
    private:

};


class Cell{
    public:
    bool craine;    
    vector<int> container;
};

class Grid{
    public:
    vector<vector<Cell>> Cells;
    Grid(int n){
        Cells.resize(n, vector<Cell>(n));
    }
};




int main(){
    int N;
    cin >> N;
    vector A(N, vector<int>(N, 0)); 
    rep(i, N) {
        rep(j, N){
            cin >> A[i][j];
        }
    }
    bigCrane bC(0, 0);    
    vector<smallCrane> sC{};
    for(int i=1; i<N; i++){
        sC.push_back(smallCrane(i,0));
    }

    return 0;
}