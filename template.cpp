#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <functional>
#include <unordered_map>
#include <string>
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

using pll = pair<long long, long long>;