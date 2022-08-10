#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

string ans;
bool visit[1000000][11];

void solve(string& s, int th, int chance)
{
    if (th == chance) {
        ans = max(ans, s);
        return;
    }

    int num = s[0] - '0';
    for (int i = 1; i < s.size(); ++i) {
        num *= 10;
        num += (s[i] - '0');
    }

    if (visit[num][th]) return;

    visit[num][th] = true;
    for (int i = 0; i < s.size() - 1; ++i) {
        for (int j = i + 1; j < s.size(); ++j) {
            std::swap(s[i], s[j]);
            solve(s, th + 1, chance);
            std::swap(s[i], s[j]);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);

    int t; cin >> t;
    for (int tc = 1; tc <= t; ++tc) {
        int chance;
        string str;
        cin >> str >> chance;

        ans = "0";
        memset(visit, 0, sizeof(visit));

        solve(str, 0, chance);
        cout << "#" << tc << ' ' << ans << '\n';
    }
    return 0;
}