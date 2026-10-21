#include <bits/stdc++.h>
using namespace std;

long long vuiToiDa[305][105];

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
                long long neuChon = vuiToiDa[gio - tgAn][an - luong] + vui;
                if (neuChon > vuiToiDa[gio][an]) {
                    vuiToiDa[gio][an] = neuChon;
                }
            }
        }
    }
    cout << vuiToiDa[thoiGian][thucAn] << endl;
    return 0;
}
