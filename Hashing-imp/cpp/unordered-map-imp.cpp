#include <iostream>
#include <unordered_map>
#include <iterator>

using namespace std;

int main()
{

    unordered_map<int, int> ump;

    ump.insert(pair<int, int>(1, 4));
    ump.insert(pair<int, int>(2, 8));
    ump.insert(pair<int, int>(3, 12));
    ump.insert(pair<int, int>(5, 60));
    ump.insert(pair<int, int>(7, 84));

    unordered_map<int, int>::iterator itr;

    cout << "printing map value with key \n";
    cout << "Key "
         << "Value \n";
    for (itr = ump.begin(); itr != ump.end(); itr++)
    {
        cout << itr->first << " -> " << itr->second << '\n';
    }

    return 0;
}