// ITNOA
// O(n.log(n)) DP with 1D/1D Optimization by lnxdx, Mashhad, 2019
#include<bits/stdc++.h>
using namespace std;
#define ll long long
int INF = 2e9 + 1;
const int N = 1e4 + 10;
int dp[N];
int t[N];
int f[N];
int n, s;
int w(int i, int x) {
  return s*(f[n] - f[i]) + t[x] * (f[x] - f[i]);
}
int main()
{
  cin >> n >> s;
  for (int i = 1;i <= n;i++)
  {
    cin >> t[i] >> f[i];
    t[i] += t[i - 1];
    f[i] += f[i - 1];
  }
  vector<pair<int, int> > v; // argmin stack = {x, i}
  v.push_back({ 0, 0 });
 
  for (int i = 1; i <= n; i++)
  {
    int k = (--lower_bound(v.begin(), v.end(), make_pair(i + 1, 0)))->second;
    dp[i] = dp[k] + w(k, i);
 
    for (int j = (int)v.size() - 1; j >= 0; j--)
    {
      int x = v[j].first;
      int k = v[j].second;
      if (x > i && dp[i] + w(i, x) < dp[k] + w(k, x))
        v.pop_back();
      else
      {
        int l = x + 1;
        int r = n + 1;
        while (l < r)
        {
          int mid = (l + r) / 2;
          if (dp[i] + w(i, mid) < dp[k] + w(k, mid))
            r = mid;
          else
            l = mid + 1;
        }
        if (r != n + 1)
          v.push_back(make_pair(r, i));
        break;
      }
    }
  }
  cout << dp[n];
}
