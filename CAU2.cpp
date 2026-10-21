#include <bits/stdc++.h>
using namespace std;

bool nguyenTo[10000001];

int tongChuSo(int so) {
    int tong = 0;
    while (so > 0) {
        tong += so % 10;
        so /= 10;
    }
    return tong;
}

int main() {
    freopen("CAU2.INP", "r", stdin);
    freopen("CAU2.OUT", "w", stdout);
    int tu, den, k;
    cin >> tu >> den >> k;
    for (int i = 2; i <= den; i++) {
        nguyenTo[i] = true;
    }
    for (int i = 2; i * i <= den; i++) {
        if (nguyenTo[i] == true) {
            for (int j = i * i; j <= den; j += i) {
                nguyenTo[j] = false;
            }
        }
    }
    int dem = 0;
    for (int i = tu; i <= den; i++) {
        if (nguyenTo[i] == true && tongChuSo(i) % k == 0) {
            dem++;
        }
    }
    cout << dem << endl;
    return 0;
}
