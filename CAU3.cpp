#include <bits/stdc++.h>
using namespace std;

const long long MOD1 = 1000000007, MOD2 = 998244353, COSO = 131;

int n;
string xau;
long long h1[200005], h2[200005], mu1[200005], mu2[200005];

bool kiemTra(int doDai) {
    vector<long long> ds;
    for (int i = 0; i + doDai <= n; i++) {
        long long a = (h1[i + doDai] - h1[i] * mu1[doDai] % MOD1 + MOD1) % MOD1;
        long long b = (h2[i + doDai] - h2[i] * mu2[doDai] % MOD2 + MOD2) % MOD2;
        ds.push_back(a * MOD2 + b);
    }
    sort(ds.begin(), ds.end());
    for (int i = 1; i < (int)ds.size(); i++) {
        if (ds[i] == ds[i - 1]) return true;
    }
    return false;
}

int main() {
    freopen("CAU3.INP", "r", stdin);
    freopen("CAU3.OUT", "w", stdout);
    cin >> n >> xau;
    mu1[0] = mu2[0] = 1;
    for (int i = 0; i < n; i++) {
        h1[i + 1] = (h1[i] * COSO + xau[i]) % MOD1;
        h2[i + 1] = (h2[i] * COSO + xau[i]) % MOD2;
        mu1[i + 1] = mu1[i] * COSO % MOD1;
        mu2[i + 1] = mu2[i] * COSO % MOD2;
    }
    int thap = 0, cao = n - 1;
    while (thap < cao) {
        int giua = (thap + cao + 1) / 2;
        if (kiemTra(giua)) thap = giua;
        else cao = giua - 1;
    }
    cout << thap << endl;
    return 0;
}
