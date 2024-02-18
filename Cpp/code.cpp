#include <bits/stdc++.h>

using namespace std;

#define gc getchar_unlocked
#define fo(i, n) for (i = 0; i < n; i++)
#define Fo(i, k, n) for (i = k; k < n ? i < n : i > n; k < n ? i += 1 : i -= 1)
#define ll long long
#define deb(x) cout << #x << "=" << x << endl
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, false, sizeof(x))
#define sortall(x) sort(all(x))
#define tr(it, a) for (auto it = a.begin(); it != a.end(); it++)
#define PI 3.1415926535897932384626
#define mod 1000000007
typedef pair<int, int> pii;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pl> vpl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;

int countPrefixSuffixPairs(vector<string> &w)
{
    unordered_map<string, set<int>> pmp;
    unordered_map<string, set<int>> smp;

    for (int k = 0; k < w.size(); k++)
    {
        int i = 0, n = w[k].size() - 1;
        string pre = "", suf = "";
        while (n >= 0)
        {
            pre += w[k][i++];
            suf = w[k][n--] + suf;
            pmp[pre].insert(k);
            smp[suf].insert(k);
        }
    }
    int ans = 0;

    for (auto it : pmp)
    {
        cout << it.first << ": ";
        for (auto iter : it.second)
            cout << iter << " ";
        cout << endl;
    }
    cout << endl;
    for (auto it : smp)
    {
        cout << it.first << ": ";
        for (auto iter : it.second)
            cout << iter << " ";
    }
    for (int i = 0; i < w.size(); i++)
    {
        int cnt = 0;

        cnt = pmp[w[i]].size();
        if (pmp[w[i]].find(i) != pmp[w[i]].end())
            cnt--;

        cnt += smp[w[i]].size();
        if (smp[w[i]].find(i) != smp[w[i]].end())
            cnt--;

        ans += cnt;
    }

    cout << endl;
    return ans;
}
int main()
{

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<string> arr(n);
    for (auto &it : arr)
        cin >> it;

    cout << countPrefixSuffixPairs(arr);

    return 0;
}