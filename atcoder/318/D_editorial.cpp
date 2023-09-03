#include <bits/stdc++.h>
using namespace std;

#define rep(i, x) for (int i = 0; i < (x); i++)

int main()
{
    // Read the number of vertices
    long long n;
    cin >> n;

    // Initialize a 2D vector to store edge weights
    vector<vector<long long>> d(n, vector<int>(n, 0));

    // Read the edge weights for the complete graph
    rep(i, n)
    {
        for (int j = i + 1; j < n; j++)
        {
            cin >> d[i][j];
        }
    }

    // Initialize a vector to store the maximum total weight for subsets of vertices
    vector<long long> dp(1 << n, 0ll);

    // Iterate through all possible subsets of vertices
    rep(b, (1 << n) - 1)
    {
        int l = -1; // Initialize an unused vertex

        // Find an unused vertex in the current subset represented by bitmask b
        rep(i, n)
        {
            if (!(b >> i & 1))
            {
                l = i;
                break;
            }
        }

        // Iterate through all vertices i within the same subset
        rep(i, n)
        {
            if (!(b >> i & 1))
            {
                // Create a new subset nb by adding vertices l and i to the current subset b
                int nb = b | (1 << l) | (1 << i);

                // Update dp[nb] with the maximum of its current value and dp[b] + d[l][i]
                dp[nb] = max(dp[nb], dp[b] + d[l][i]);
            }
        }
    }

    // Print the maximum total weight, which corresponds to the full set of vertices
    cout << dp[(1 << n) - 1] << endl;

    return 0;
}
