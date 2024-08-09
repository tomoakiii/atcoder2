#include <iostream>
#include <vector>
#include <numeric> // std::iota()
#include <utility> // std::swap()

using namespace std;



int main(){
    int N, Q;
    cin >> N >> Q;
    vector<int> anso(Q);

    class bowl{
        public:
        bowl *prev = NULL;
        bool isempty = false;
        vector<bool> cols;
        bowl(int N){
            cols.resize(N+1);
        }
    };

    vector<bowl> C(N+1, N+1);
    
    for (int i = 1; i <= N; i++){
        int col;
        cin >> col;
        C[i].cols[col] = true;
    }

    for (int i = 0; i < Q; i++){
        int a, b;
        cin >> a >> b;
        C[b].cols += C[a].cols;
    }

    for (auto a : anso){
        cout << a << endl;
    }
    return 0;
}