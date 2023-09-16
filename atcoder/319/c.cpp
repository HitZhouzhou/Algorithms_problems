#include <iostream>
#include <array>
#include <algorithm>
#include <tuple>
#include <vector>
#include <numeric>
int main()
{
    using namespace std;
    array<int, 9> cells;
    for (auto &&c : cells)
        cin >> c;
    vector<tuple<int, int, int>> row{
        {0, 1, 2}, {3, 4, 5}, {6, 7, 8}, {0, 3, 6}, {1, 4, 7}, {2, 5, 8}, {0, 4, 8}, {2, 4, 6}};
    int order[] = {0, 1, 2, 3, 4, 5, 6, 7, 8};
    int not_disappoint = 0, all = 0;
    do
    {
        bool disappoint = false;
        ++all;
        for (auto &&[a, b, c] : row)
        {
            if (cells[a] == cells[b] && order[a] < order[c] && order[b] < order[c])
            {
                disappoint = true;
            }
            else if (cells[a] == cells[c] && order[a] < order[b] && order[b] > order[c])
            {
                disappoint = true;
            }
            else if (cells[b] == cells[c] && order[a] > order[b] && order[c] < order[a])
            {
                disappoint = true;
            }
        }
        if (!disappoint)
        {
            not_disappoint++;
        }
    } while (next_permutation(order, order + 9));
    printf("%.10lf", (double)not_disappoint / all);
    return 0;
}