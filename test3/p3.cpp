#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

// 将牌面字符转换为数值（2=2, ..., T=10, J=11, Q=12, K=13, A=14）
int getRank(char c)
{
    if (c >= '2' && c <= '9')
    {
        return c - '0';
    }
    switch (c)
    {
    case 'T':
        return 10;
    case 'J':
        return 11;
    case 'Q':
        return 12;
    case 'K':
        return 13;
    case 'A':
        return 14;
    default:
        return 0;
    }
}

// 获取牌的类型和相关数据
struct HandInfo
{
    int type;          // 1-9，对应题目中的9种类型
    vector<int> ranks; // 用于比较的牌面值序列
};

HandInfo analyzeHand(const vector<string> &cards)
{
    vector<int> ranks;
    vector<char> suits;

    for (const string &card : cards)
    {
        ranks.push_back(getRank(card[0]));
        suits.push_back(card[1]);
    }

    // 排序牌面值（降序）
    sort(ranks.begin(), ranks.end(), greater<int>());

    // 统计每个面值的出现次数
    unordered_map<int, int> count;
    for (int r : ranks)
    {
        count[r]++;
    }

    // 检查是否为同花
    bool isFlush = true;
    for (int i = 1; i < 5; i++)
    {
        if (suits[i] != suits[0])
        {
            isFlush = false;
            break;
        }
    }

    // 检查是否为顺子
    bool isStraight = true;
    for (int i = 0; i < 4; i++)
    {
        if (ranks[i] != ranks[i + 1] + 1)
        {
            isStraight = false;
            break;
        }
    }

    // 特殊情况：A,2,3,4,5 也是顺子（A作为1）
    if (!isStraight && ranks[0] == 14 && ranks[1] == 5 && ranks[2] == 4 && ranks[3] == 3 && ranks[4] == 2)
    {
        isStraight = true;
        // 调整A的值为1，重新排序
        ranks[0] = 1;
        sort(ranks.begin(), ranks.end(), greater<int>());
    }

    // 获取按出现次数和面值排序的序列（用于比较）
    vector<pair<int, int>> freqRank; // {出现次数, 面值}
    for (auto &p : count)
    {
        freqRank.push_back({p.second, p.first});
    }
    // 先按出现次数降序，再按面值降序
    sort(freqRank.begin(), freqRank.end(), [](const pair<int, int> &a, const pair<int, int> &b)
         {
        if (a.first != b.first) return a.first > b.first;
        return a.second > b.second; });

    vector<int> compareRanks;
    for (auto &p : freqRank)
    {
        for (int i = 0; i < p.first; i++)
        {
            compareRanks.push_back(p.second);
        }
    }

    HandInfo info;

    if (isStraight && isFlush)
    {
        info.type = 9;      // Straight flush
        info.ranks = ranks; // 用原始排序的ranks比较
    }
    else if (count.size() == 2 && freqRank[0].first == 4)
    {
        info.type = 8; // Four of a kind
        info.ranks = compareRanks;
    }
    else if (count.size() == 2)
    {
        info.type = 7; // Full house
        info.ranks = compareRanks;
    }
    else if (isFlush)
    {
        info.type = 6; // Flush
        info.ranks = ranks;
    }
    else if (isStraight)
    {
        info.type = 5; // Straight
        info.ranks = ranks;
    }
    else if (freqRank[0].first == 3)
    {
        info.type = 4; // Three of a kind
        info.ranks = compareRanks;
    }
    else if (count.size() == 3 && freqRank[0].first == 2 && freqRank[1].first == 2)
    {
        info.type = 3; // Two pairs
        info.ranks = compareRanks;
    }
    else if (freqRank[0].first == 2)
    {
        info.type = 2; // Pair
        info.ranks = compareRanks;
    }
    else
    {
        info.type = 1; // High card
        info.ranks = ranks;
    }

    return info;
}

// 比较两手牌
int compareHands(const HandInfo &black, const HandInfo &white)
{
    if (black.type != white.type)
    {
        return black.type - white.type;
    }

    // 类型相同，比较具体牌面
    for (int i = 0; i < 5; i++)
    {
        if (black.ranks[i] != white.ranks[i])
        {
            return black.ranks[i] - white.ranks[i];
        }
    }
    return 0; // 完全相同
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    while (n--)
    {
        vector<string> blackCards(5);
        vector<string> whiteCards(5);

        for (int i = 0; i < 5; i++)
        {
            cin >> blackCards[i];
        }
        for (int i = 0; i < 5; i++)
        {
            cin >> whiteCards[i];
        }

        HandInfo blackInfo = analyzeHand(blackCards);
        HandInfo whiteInfo = analyzeHand(whiteCards);

        int result = compareHands(blackInfo, whiteInfo);

        if (result > 0)
        {
            cout << "Black wins.\n";
        }
        else if (result < 0)
        {
            cout << "White wins.\n";
        }
        else
        {
            cout << "Tie.\n";
        }
    }

    return 0;
}