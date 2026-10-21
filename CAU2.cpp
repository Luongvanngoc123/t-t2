#include <bits/stdc++.h>
using namespace std;

bool hopSo[10000001];

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
    hopSo[0] = hopSo[1] = true;
    for (int i = 2; i * i <= den; i++) {
        if (!hopSo[i]) {
            for (int j = i * i; j <= den; j += i) hopSo[j] = true;
        }
    }
    int dem = 0;
    for (int i = tu; i <= den; i++) {
        if (!hopSo[i] && tongChuSo(i) % k == 0) dem++;
    }
    cout << dem << endl;
    return 0;
}
