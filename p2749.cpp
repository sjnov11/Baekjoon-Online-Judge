#include <iostream>
#include <vector>
using namespace std;

typedef vector<vector<long long>> matrix;
const long long mod = 1000000;

matrix operator * (const matrix &a, const matrix &b) {
    int n = a.size();
    matrix c(n, vector<long long>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                c[i][j] += a[i][k] * b[k][j];
            }
            c[i][j] %= mod;
        }
    }

    return c;
}

int main() {
    long long n;
    scanf("%lld", &n);

    if (n <= 1) {
        printf ("%lld\n", n);
        return 0;
    }
    //matrix answer(2, vector<long long>(2));
    matrix ans = {{1, 0}, {0, 1}};
    //matrix a(2, vector<long long>(2));
    matrix a = {{1, 1}, {1, 0}};

    while (n > 0) {
        if (n & 1) {
            ans = ans * a;
            --n;               
        }
        a = a*a;
        n /= 2;
    }

    printf("%lld\n", ans[0][1]);

    return 0;
}