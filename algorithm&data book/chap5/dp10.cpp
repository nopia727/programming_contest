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
const int INF = 2 << 29;
int main()
{
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    vector<long long> s(n + 1, 0);
    for (int i = 0; i < n; i++)
        s[i + 1] = s[i] + a[i];
    vector<vector<long long>> dp(n + 1, vector<long long>(n + 1, INF));

    for (int i = 0; i < n; i++)
        dp[i][i + 1] = 0;
    for (int bet = 2; bet <= n; bet++)
    {
        for (int i = 0; i + bet < n; i++)
        {
            int j = i + bet;
            for (int k = i + 1; k < j; k++)
            {
                chmin(dp[i][j], dp[i][k] + dp[k][j] + s[j] - s[i]);
            }
        }
    }
}