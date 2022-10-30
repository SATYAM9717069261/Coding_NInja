#include <bits/stdc++.h>
using namespace std;
using namespace __gnu_cxx;

void init() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    cout.tie(0);
    cout.sync_with_stdio(0);
}

const int N = 5e6 + 5;
int pr[N], cnt[N][3], p[N];

void manacher(string s) {
    int n = s.length();
    int l = 0, r = -1;
    for (int i = 0; i < n; i++) {
        int k = i > r ? 0 : min(p[l + r - i], r - i);
        while (0 <= i - k && i + k < n && s[i - k] == s[i + k])
            k++;
        p[i] = --k;
        if (i + k > r) {
            l = i - k;
            r = i + k;
        }
    }
}

int t(char c) {
    if (c == '#')
        return 0;
    return (c - '0') % 3;
}

int main() {
    init();
    string x;
    cin >> x;
    string s(2 * x.size() + 1, '#');
    for (int i = 0; i < x.size(); i++) {
        s[2 * i + 1] = x[i];
    }
    manacher(s);
    pr[0] = t(s[0]);
    for (int i = 1; i < s.size(); ++i) {
        pr[i] = pr[i - 1] + t(s[i]);
        pr[i] %= 3;
         //cout << s[i]<<" "<<pr[i]<<"\n";
        for (int j = 0; j < 3; ++j) {
            cnt[i][j] = cnt[i - 1][j];
        }
        if (s[i] != '#' && s[i] != '0')
            cnt[i][pr[i]]++;
    }
    long long ans = 0;
    for (int i = 1; i < s.size() - 1; ++i) {

        int l = p[i];
        int j = i + l - 1;
        if (!t(s[i]) && s[i]!='#')
            ans++;
      /*  cout << pr[i] << " " << t(s[i]) % 3 << " " << " " << s[i] << " " << i << " " << j << " " << cnt[i][(pr[i] + t(s[i])) % 3] << " " << cnt[j][(pr[i] + t(s[i])) % 3]
             << " " << (pr[i] + t(s[i])) % 3
             << "\n";*/
        ans += (cnt[j][(pr[i] + t(s[i])) % 3] - cnt[i][(pr[i] + t(s[i])) % 3]);
    }
    cout << ans;


}
