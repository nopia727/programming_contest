#include <iostream>
#include <vector>
using namespace std;
template <class T>
void chmax(T &a, T b)
{
    if (a < b)
        a = b;
}
template <class T>
void chmin(T &a, T b)
{
    if (a > b)
        a = b;
}

int main()
{
    string s, t;
    cin >> s >> t;
    int n = s.size(), m = t.size();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            if (i > 0 && j > 0)
            {
                if (s[i - 1] == t[j - 1])
                    chmax(dp[i][j], dp[i - 1][j - 1] + 1);
                else
                    chmax(dp[i][j], dp[i - 1][j - 1]);
            }
            if (i > 0)
            {
                chmax(dp[i][j], dp[i - 1][j]);
            }
            if (j > 0)
            {
                chmax(dp[i][j], dp[i][j - 1]);
            }
        }
    }
}