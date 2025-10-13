#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    long long p; // p可能很大，使用long long
    cin >> N >> p;

    vector<long long> arr(N);
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    // 排序
    sort(arr.begin(), arr.end());

    int maxCount = 1;
    int left = 0;

    // 双指针滑动窗口
    for (int right = 0; right < N; right++)
    {
        // 当前窗口不满足条件时，移动左指针
        while (arr[right] > arr[left] * p)
        {
            left++;
        }
        // 更新最大长度
        maxCount = max(maxCount, right - left + 1);
    }

    cout << maxCount << endl;

    return 0;
}