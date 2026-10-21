#include <bits/stdc++.h>
using namespace std;

long long dp[305][105];

int main() {
    freopen("CAU4.INP", "r", stdin);
    freopen("CAU4.OUT", "w", stdout);
    int thoiGian, thucAn, soQuan;
    cin >> thoiGian >> thucAn >> soQuan;
    for (int i = 1; i <= soQuan; i++) {
        int vui, tgAn, luong;
        cin >> vui >> tgAn >> luong;
        for (int gio = thoiGian; gio >= tgAn; gio--) {
            for (int an = thucAn; an >= luong; an--) {
                dp[gio][an] = max(dp[gio][an], dp[gio - tgAn][an - luong] + vui);
            }
        }
    }
    cout << dp[thoiGian][thucAn] << endl;
    return 0;
}
