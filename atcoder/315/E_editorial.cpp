#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;

// Function to perform topological sorting on a directed graph
vector<int> topological_sort(vector<vector<int>> graph)
{
    int n = graph.size();
    vector<int> indegree(n);

    // Calculate the in-degrees for each node
    for (int i = 0; i < n; i++)
        for (int j : graph[i])
            indegree[j]++;

    vector<int> res;
    queue<int> que;

    // Initialize the queue with nodes having in-degrees of 0
    for (int i = 0; i < n; i++)
        if (indegree[i] == 0)
            que.push(i);

    // Perform topological sorting
    while (!que.empty())
    {
        int ver = que.front();
        que.pop();
        res.push_back(ver);

        // Decrease the in-degrees of adjacent nodes and enqueue them if in-degrees become 0
        for (int i : graph[ver])
        {
            indegree[i]--;
            if (indegree[i] == 0)
                que.push(i);
        }
    }
    return res;
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> graph(n, vector<int>());

    // Read input: prerequisites for each book
    rep(i, n)
    {
        int c;
        cin >> c;
        rep(_, c)
        {
            int v;
            cin >> v;
            v--; // Convert to 0-based indexing
            graph[i].push_back(v);
        }
    }

    queue<int> que;
    que.push(0); // Start from book 1
    vector<bool> f(n);

    // Perform BFS to mark reachable books
    while (!que.empty())
    {
        int q = que.front();
        que.pop();
        for (int i : graph[q])
        {
            if (!f[i])
            {
                f[i] = true;
                que.push(i);
            }
        }
    }

    // Perform topological sorting to determine the order to read books
    vector<int> t = topological_sort(graph);
    vector<int> order(n);
    rep(i, n) order[t[i]] = i;

    vector<int> ans;

    // Find the minimum books to read (excluding book 1)
    for (int i = 1; i < n; i++)
        if (f[i])
            ans.push_back(i);

    // Sort the books based on topological order

    // Sorting function explanation:
    // [&] is a lambda function that captures variables by reference.
    // In this case, it captures 'order', which is a vector that stores the topological order of books.
    // This lambda function is used by the sort() function to compare two books 'x' and 'y' based on their order.
    // The comparison is such that it ensures that the books are sorted in descending order of their topological order.

    sort(ans.begin(), ans.end(), [&](int x, int y)
         { return order[x] > order[y]; });

    // Output the order of books to read
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] + 1 << " \n"[i == ans.size() - 1]; // Add 1 to convert back to 1-based indexing
}
