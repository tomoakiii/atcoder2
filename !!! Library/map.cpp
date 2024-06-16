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
    map<Person, int> mp;
    Person p("aaa", 170);
    cout << mp.count(p) << endl;
    mp[p] = 123;
    for(auto itr = mp.begin(); itr != mp.end(); ++itr) {
        std::cout << "key = " << itr->first.m_name          // キーを表示
                        << ", val = " << itr->second << "\n";    // 値を表示
    }
    cout << mp.count(p) << endl;
    map<int, int> mp3;
    mp3[1] = -100;
    mp3[3] = -300;
    mp3[2] = -200;

    for(auto itr = mp3.begin(); itr != mp3.end(); ++itr) {
        std::cout << "key = " << itr->first         // キーを表示
                        << ", val = " << itr->second << "\n";    // 値を表示
    }

    cout << endl;
    mp3[-1] = -100;
    mp3[-3] = -300;
    mp3[-2] = -200;

    for(auto itr = mp3.begin(); itr != mp3.end(); ++itr) {
        std::cout << "key = " << itr->first         // キーを表示
                        << ", val = " << itr->second << "\n";    // 値を表示
    }


    map<std::string, int> mp2;
    auto itr = mp2.find("xyz");        // "xyz" が設定されているか？
    if( itr != mp2.end() ) {
        cout << itr->first << "\n";             //  "xyz" が表示される
        cout << itr->second << "\n";         // mp["xyz"] の値が表示される
    }
    return 0;
}