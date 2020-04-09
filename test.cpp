// #include <pair>
#include <iostream>
#include <utility>
#include <map>
#include <string>

using namespace std;

pair<int, bool> fun()
{
    pair<int, bool> test = {1, true};
    return test;
}

int main()
{
    const auto [test_a, test_b] = fun();
    cout << test_a << test_b << endl;

    map<int, float>m;
    m.insert({1, 1.5});
    m.insert(make_pair(2, 2.15));
    cout << m[1] << endl;
    cout << m[2] << endl;

    string s;
    s.append(string(5, 'c'));
    cout << s << endl;
    return 0;
}