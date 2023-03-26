#include <iostream>
#include <string>
#include <vector>
using namespace std;

template <class T>
void chmin(T &a, T b)
{
    if (a > b)
    {
        a = b;
    }
}

const int INF = 1 << 29;

int main()
{
    string s, t;
    cin >> s >> t;
    vector<vector<int>> dp(s.size() + 1, vector<int>(t.size() + 1, INF));
    dp[0][0] = 0;

    for (int i = 0; i <= s.size(); i++)
    {
        for (int j = 0; j <= t.size(); j++)
        {
            if (i > 0 && j > 0)
            {
                if (s[i - 1] == t[j - 1])
                {
                    chmin(dp[i][j], dp[i - 1][j - 1]);
                }
                else
                {
                    chmin(dp[i][j], dp[i - 1][j - 1] + 1);
                }
            }
            if (i > 0)
                chmin(dp[i][j], dp[i - 1][j] + 1);
            if (j > 0)
                chmin(dp[i][j], dp[i][j - 1] + 1);
        }
    }
    cout << dp[s.size()][t.size()] << endl;
}