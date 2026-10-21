#include <bits/stdc++.h>
using namespace std;

const long long MOD1 = 1000000007, MOD2 = 998244353, COSO = 131;

int n;
string xau;
long long bam1[200005], bam2[200005], luyThua1[200005], luyThua2[200005];

bool coXauConLap(int doDai) {
    vector<long long> danhSach;
    for (int i = 0; i + doDai <= n; i++) {
        long long giaTri1 = (bam1[i + doDai] - bam1[i] * luyThua1[doDai] % MOD1 + MOD1) % MOD1;
        long long giaTri2 = (bam2[i + doDai] - bam2[i] * luyThua2[doDai] % MOD2 + MOD2) % MOD2;
        danhSach.push_back(giaTri1 * MOD2 + giaTri2);
    }
    sort(danhSach.begin(), danhSach.end());
    for (int i = 1; i < (int)danhSach.size(); i++) {
        if (danhSach[i] == danhSach[i - 1]) {
            return true;
        }
    }
    return false;
}

int main() {
    freopen("CAU3.INP", "r", stdin);
    freopen("CAU3.OUT", "w", stdout);
    cin >> n >> xau;
    luyThua1[0] = 1;
    luyThua2[0] = 1;
    for (int i = 0; i < n; i++) {
        bam1[i + 1] = (bam1[i] * COSO + xau[i]) % MOD1;
        bam2[i + 1] = (bam2[i] * COSO + xau[i]) % MOD2;
        luyThua1[i + 1] = luyThua1[i] * COSO % MOD1;
        luyThua2[i + 1] = luyThua2[i] * COSO % MOD2;
    }
    int dau = 0, cuoi = n - 1;
    while (dau < cuoi) {
        int giua = (dau + cuoi + 1) / 2;
        if (coXauConLap(giua) == true) {
            dau = giua;
        } else {
            cuoi = giua - 1;
        }
    }
    cout << dau << endl;
    return 0;
}
