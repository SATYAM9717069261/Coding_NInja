#include <bits/stdc++.h>
using namespace std;

void precal(long long *res, long long *phi, long long n)
{
    for (long long i = 1; i <= n; ++i)

        phi[i] = i;

    for (long long i = 2; i <= n; ++i)
    {
        if (phi[i] == i)
        {
            for (int j = i; j <= n; j += i)
            {
                phi[j] /= i;
                phi[j] *= i - 1;
            }
        }
    }
    for (long long i = 1; i <= n; ++i)
    {
        for (int j = i; j <= n; j += i)
            res[j] += (i * phi[i]);
    }
    return;
}

int main()
{

    long long *res = new long long[100010];
    long long *phi = new long long[100010];

    precal(res, phi, 100000);

    int t;
    cin >> t;
    while (t--)
    {
        long long int n;
        cin >> n;

        long long ans = res[n] + 1;
        ans *= n;
        ans /= 2;
        cout<<ans<<endl;
    }
}

