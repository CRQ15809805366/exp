#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

string to_string(long long x)
{
    if (x == 0)
        return "0";
    string s;
    while (x)
    {
        s += char('0' + x % 10);
        x /= 10;
    }
    reverse(s.begin(), s.end());
    return s;
}

long long stoll(const string &s)
{
    long long res = 0;
    for (char c : s)
    {
        res = res * 10 + (c - '0');
    }
    return res;
}

// 获取使用所有剩余数字能组成的最大数字
string getMaxFromCount(vector<int> &count)
{
    string res;
    for (int i = 9; i >= 0; i--)
    {
        res += string(count[i], '0' + i);
    }
    return res;
}

// 主要的解决函数
string solve(long long A, long long B)
{
    string a_str = to_string(A);
    string b_str = to_string(B);

    if (a_str.length() < b_str.length())
    {
        // 直接返回最大排列
        sort(a_str.begin(), a_str.end(), greater<char>());
        if (a_str[0] == '0' && a_str.length() > 1)
        {
            // 找第一个非零数字
            int firstNonZero = -1;
            for (int i = 0; i < a_str.length(); i++)
            {
                if (a_str[i] != '0')
                {
                    firstNonZero = i;
                    break;
                }
            }
            if (firstNonZero == -1)
                return "-1";
            swap(a_str[0], a_str[firstNonZero]);
        }
        return a_str;
    }

    if (a_str.length() > b_str.length())
    {
        return "-1";
    }

    // 长度相等的情况
    vector<int> count(10, 0);
    for (char c : a_str)
    {
        count[c - '0']++;
    }

    string current;
    vector<int> used_count = count;

    // 尝试构造每一位
    for (int i = 0; i < b_str.length(); i++)
    {
        int limit = b_str[i] - '0';
        bool found_equal = false;

        // 先尝试等于limit的数字
        if (used_count[limit] > 0)
        {
            used_count[limit]--;
            // 检查剩余数字是否能填满后面的位置
            int remaining_positions = b_str.length() - i - 1;
            int remaining_digits = 0;
            for (int d = 0; d < 10; d++)
            {
                remaining_digits += used_count[d];
            }

            if (remaining_digits == remaining_positions)
            {
                current += char('0' + limit);
                found_equal = true;
            }
            else
            {
                used_count[limit]++; // 回溯
            }
        }

        if (!found_equal)
        {
            // 尝试小于limit的最大数字
            for (int d = limit - 1; d >= 0; d--)
            {
                if (used_count[d] > 0)
                {
                    used_count[d]--;
                    current += char('0' + d);
                    current += getMaxFromCount(used_count);
                    return current;
                }
            }
            // 无法构造
            return "-1";
        }
    }

    return current;
}

int main()
{
    long long A, B;
    cin >> A >> B;

    string result = solve(A, B);

    if (result == "-1")
    {
        cout << -1 << endl;
    }
    else
    {
        // 检查前导零
        if (result.length() > 1 && result[0] == '0')
        {
            cout << -1 << endl;
        }
        else
        {
            cout << result << endl;
        }
    }

    return 0;
}