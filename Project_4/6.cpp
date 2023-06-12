#include <iostream>
using namespace std;

int main()
{
    int n, m, s, f;
    cin >> n >> m >> s >> f;
    s--; f--;

    int** graph = new int* [n];
    for (int i = 0; i < n; i++)
        graph[i] = new int[n];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (i == j) graph[i][j] = 0; else graph[i][j] = -1;
    for (int i = 0; i < m; i++)
    {
        int a, b, t;
        cin >> a >> b >> t;
        a--; b--;
        graph[a][b] = t;
    }

    long int* b = new long int[n];
    int* c = new int[n];
    for (int i = 0; i < n; i++)
    {
        b[i] = graph[s][i];
        if (i == s) c[i] = 1; else c[i] = 0;
    }

    short int indmin = -1;
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < n; j++) if (!c[j] && b[j] > 0)
        {
            indmin = j;
            break;
        }
        if (indmin == -1) break;

        for (int j = 0; j < n; j++)
            if (c[j] == 0 && b[j] < b[indmin] && b[j] > 0) indmin = j;
        c[indmin] = 1;

        for (int j = 0; j < n; j++)
            if (!c[j])
                if (graph[indmin][j] > 0 && (b[j] > graph[indmin][j] + b[indmin] || b[j] < 0))
                    b[j] = graph[indmin][j] + b[indmin];

        if (indmin == f) break;
    }

    if (indmin == -1) cout << indmin;
    else cout << b[f];

    delete[] b;
    delete[] c;

    for (int i = 0; i < n; i++)
        delete[] graph[i];
    delete[] graph;

    return 0;
}

