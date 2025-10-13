#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main()
{
    int N;
    cin >> N;

    vector<vector<int>> matrix(N, vector<int>(N));

    // 读取矩阵
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> matrix[i][j];
        }
    }

    // 提取边界元素
    vector<int> boundary;

    // 第一行
    for (int j = 0; j < N; j++)
    {
        boundary.push_back(matrix[0][j]);
    }

    // 最后一行（如果N>1，避免重复添加）
    if (N > 1)
    {
        for (int j = 0; j < N; j++)
        {
            boundary.push_back(matrix[N - 1][j]);
        }
    }

    // 第一列和最后一列（排除已经添加的四个角）
    for (int i = 1; i < N - 1; i++)
    {
        boundary.push_back(matrix[i][0]);     // 第一列
        boundary.push_back(matrix[i][N - 1]); // 最后一列
    }

    // 统计每个元素的出现次数
    map<int, int> count;
    for (int num : boundary)
    {
        count[num]++;
    }

    // 找到最大出现次数
    int maxCount = 0;
    for (auto &pair : count)
    {
        if (pair.second > maxCount)
        {
            maxCount = pair.second;
        }
    }

    // 收集所有出现次数等于最大次数的元素
    vector<int> result;
    for (auto &pair : count)
    {
        if (pair.second == maxCount)
        {
            result.push_back(pair.first);
        }
    }

    // 按数值从大到小排序
    sort(result.begin(), result.end(), greater<int>());

    // 输出结果
    for (int i = 0; i < result.size(); i++)
    {
        if (i > 0)
            cout << " ";
        cout << result[i];
    }
    cout << endl;

    return 0;
}