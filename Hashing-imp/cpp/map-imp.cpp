#include <iostream>
#include <map>
#include <iterator>

using namespace std;

int main()
{

    map<int, int> mp;

    mp.insert(pair<int, int>(1, 4));
    mp.insert(pair<int, int>(2, 8));
    mp.insert(pair<int, int>(3, 12));
    mp.insert(pair<int, int>(5, 60));
    mp.insert(pair<int, int>(7, 84));

    map<int, int>::iterator itr;

    cout << "printing map value with key \n";
    cout << "Key "
         << "Value \n";
    for (itr = mp.begin(); itr != mp.end(); itr++)
    {
        cout << itr->first << " -> " << itr->second << '\n';
    }

    return 0;
}