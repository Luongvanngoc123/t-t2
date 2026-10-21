#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("CAU1.INP", "r", stdin);
    freopen("CAU1.OUT", "w", stdout);
    int day[9];
    for (int i = 1; i <= 8; i++) {
        cin >> day[i];
    }
    bool tang = true;
    bool giam = true;
    for (int i = 1; i < 8; i++) {
        if (day[i] > day[i + 1]) {
            tang = false;
        }
        if (day[i] < day[i + 1]) {
            giam = false;
        }
    }
    if (tang == true) {
        cout << "ascending" << endl;
    } else if (giam == true) {
        cout << "descending" << endl;
    } else {
        cout << "mixed" << endl;
    }
    return 0;
}
