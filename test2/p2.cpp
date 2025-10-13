#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        // 按升序排序
        sort(a.begin(), a.end());

        // 找到最大面额，用于确定DP数组大小
        int max_val = a.back();
        vector<bool> dp(max_val + 1, false);
        dp[0] = true;

        int count = 0; // 必要面额的数量

        for (int i = 0; i < n; i++)
        {
            // 如果当前面额不能被前面的面额表示，则它是必要的
            if (!dp[a[i]])
            {
                count++;
                // 用这个必要面额更新DP数组
                for (int j = a[i]; j <= max_val; j++)
                {
                    if (dp[j - a[i]])
                    {
                        dp[j] = true;
                    }
                }
            }
        }

        cout << count << endl;
    }

    return 0;
}