#include <iostream>
#include <vector>
#include <set>
#include <climits>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<int> heights(n);
    for (int i = 0; i < n; i++)
    {
        cin >> heights[i];
    }

    // 特殊情况：k == 1，但题目保证k>=1，且需要最高和第二高
    // 实际上k>=2才有意义，但题目描述中k>=1
    // 如果k == 1，那么没有第二高，但题目样例k=3，所以假设k>=2
    if (k == 1)
    {
        // 理论上k=1时无法定义第二高，但题目可能保证k>=2
        // 为了安全，输出0
        cout << 0 << endl;
        return 0;
    }

    multiset<int> window;

    // 初始化第一个窗口
    for (int i = 0; i < k; i++)
    {
        window.insert(heights[i]);
    }

    int min_diff = INT_MAX;

    // 计算第一个窗口的差值
    auto it = window.end();
    it--; // 最大值
    int max_val = *it;
    it--; // 第二大值
    int second_max = *it;
    min_diff = min(min_diff, max_val - second_max);

    // 滑动窗口
    for (int i = k; i < n; i++)
    {
        // 移除左边的元素
        auto erase_it = window.find(heights[i - k]);
        window.erase(erase_it);

        // 添加右边的元素
        window.insert(heights[i]);

        // 获取最大值和第二大值
        it = window.end();
        it--;
        max_val = *it;
        it--;
        second_max = *it;

        min_diff = min(min_diff, max_val - second_max);
    }

    cout << min_diff << endl;

    return 0;
}