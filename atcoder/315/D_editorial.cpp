#include <iostream>
#include <vector>
#include <algorithm>

#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;

int main()
{
    int h, w;
    cin >> h >> w;
    vector<vector<char>> c(h, vector<char>(w));

    rep(i, h) rep(j, w) cin >> c[i][j];

    vector<vector<int>> row_counts(h, vector<int>(26, 0)); // Initialize with all zeros
    vector<vector<int>> col_counts(w, vector<int>(26, 0));

    // Count the occurrences of each letter in rows and columns
    rep(i, h) rep(j, w)
    {
        row_counts[i][c[i][j] - 'a']++;
        col_counts[j][c[i][j] - 'a']++;
    }

    // Process rows and columns until no more cookies can be marked
    bool marked = true;
    int remaining_cookies = h * w;

    while (marked)
    {
        marked = false;

        // Process rows
        rep(i, h)
        {
            rep(j, 26)
            {
                if (row_counts[i][j] >= 2)
                {
                    int cookies_to_remove = row_counts[i][j] - 1;
                    remaining_cookies -= cookies_to_remove;
                    row_counts[i][j] = 1;
                    marked = true;
                }
            }
        }

        // Process columns
        rep(j, w)
        {
            rep(k, 26)
            {
                if (col_counts[j][k] >= 2)
                {
                    int cookies_to_remove = col_counts[j][k] - 1;
                    remaining_cookies -= cookies_to_remove;
                    col_counts[j][k] = 1;
                    marked = true;
                }
            }
        }
    }

    cout << remaining_cookies << '\n';
    return 0;
}
