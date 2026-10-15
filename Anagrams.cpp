#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>
using namespace std;
int main()
{
    int n;
    string words[20], key;
    unordered_map<string, string> mp;
    cout << "Enter number of words: ";
    cin >> n;
    cout << "Enter words: ";
    for(int i = 0; i < n; i++)
    {
        cin >> words[i];
        key = words[i];
        sort(key.begin(), key.end());
        mp[key] += words[i] + " ";
    }
    cout << "Anagram groups:\n";
    for(auto p : mp)
    {
        cout << "[ " << p.second << "]\n";
    }
    return 0;
}
