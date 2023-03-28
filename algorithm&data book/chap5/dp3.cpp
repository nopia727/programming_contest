#include <iostream>
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

const long long INF = 1 << 60;

int main()
{
    int n;
    cin >> n;
    vector<vector<long long>> c(n + 1, vector<long long>(n + 1));
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < n + 1; j++)
        {
            cin >> c[i][j];
        }
    }
    vector<long long> dp(n, INF);
    dp[0] = 0;

    cout << dp[n] << endl;
}