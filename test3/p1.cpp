#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<long long> arr; // 使用long long避免溢出
    arr.reserve(N);

    for (int op_idx = 0; op_idx < N; op_idx++)
    {
        int op;
        cin >> op;

        if (op == 1)
        {
            long long x;
            cin >> x;
            arr.push_back(x);
        }
        else if (op == 2)
        {
            int i;
            long long x;
            cin >> i >> x;

            int n = arr.size();
            long long count = 0;

            // 以位置i为右端点（向左扩展）
            long long sum = 0;
            for (int j = i; j >= 1; j--)
            {
                sum += arr[j - 1];
                if (sum == x)
                {
                    count++;
                }
            }

            // 以位置i为左端点（向右扩展）
            sum = 0;
            for (int j = i; j <= n; j++)
            {
                sum += arr[j - 1];
                if (sum == x)
                {
                    count++;
                }
            }

            // 减去重复计算的[i,i]子段
            if (arr[i - 1] == x)
            {
                count--;
            }

            cout << count << '\n';
        }
    }

    return 0;
}