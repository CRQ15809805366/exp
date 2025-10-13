#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> records(n);
    for (int i = 0; i < n; i++)
    {
        cin >> records[i];
    }

    unordered_map<int, int> count;
    vector<int> result(n);

    for (int i = 0; i < n; i++)
    {
        count[records[i]]++;
        result[i] = count[records[i]];
    }

    for (int i = 0; i < n; i++)
    {
        if (i > 0)
            cout << " ";
        cout << result[i];
    }
    cout << endl;

    return 0;
}