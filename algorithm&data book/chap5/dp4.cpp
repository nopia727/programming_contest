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
    int n;
    cin >> n;
    vector<vector<long long>> a(n, vector<long long>(3));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> a[i][j];
        }
    }
    vector<vector<long long>> dp(n + 1, vector<long long>(3, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                if (j == k)
                    continue;
                chmax(dp[i + 1][k], dp[i][j] + a[i][k]);
            }
        }
    }
    long long res = 0;
    for (int j = 0; j < 3; j++)
        chmax(res, dp[n][j]);
    cout << res << endl;
}