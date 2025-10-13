#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;

    vector<string> grid(N);
    for (int i = 0; i < N; i++)
    {
        cin >> grid[i];
    }

    int count = 0;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (grid[i][j] == '#')
            {
                // 检查是否为左上角
                bool isTopLeft = true;

                // 检查上方
                if (i > 0 && grid[i - 1][j] == '#')
                {
                    isTopLeft = false;
                }

                // 检查左方
                if (j > 0 && grid[i][j - 1] == '#')
                {
                    isTopLeft = false;
                }

                if (isTopLeft)
                {
                    count++;
                }
            }
        }
    }

    cout << count << endl;

    return 0;
}