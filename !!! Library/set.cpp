#include <bits/stdc++.h>
using namespace std;


struct Person {
public:
    Person(const string &name, int height)
        : m_name(name)
        , m_height(height)
        {}
public:
    string m_name;
    int    m_height;
};

bool operator<(const Person &lhs, const Person &rhs)
{
    return lhs.m_name < rhs.m_name;
}

int main(){
    std::set<int> st{3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5};
    std::set<int> x(st);      // コピーコンストラクタ
    auto itr = st.begin();       // 最初の要素へのイテレータを取得
    // std::cout << *itr << "\n";      // イテレータの指す先のデータを表示
    for(itr = st.begin(); itr != st.end(); ++itr) {
    //    std::cout << *itr << "\n";      // イテレータの指す先のデータを表示
    }
    set<int> st2;
    st2.insert(1);
    itr = st2.begin();
    cout << *itr << endl;
    itr = st2.end();
    itr--;
    cout << *itr << endl;
    
    return 0;
}