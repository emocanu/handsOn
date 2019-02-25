#include <iostream> 
#include <vector>
#include <algorithm>

int knapSack(int W, int wt[], int val[], int n)
{
    int i, w;
    std::vector<int> row(W+1, 0);
    std::vector<std::vector<int>> K(n+1, row);
    //K.reserve(n + 1);
    //for (std::vector<int> row : K)
    //    row.reserve(W + 1);
    
    // Build table K[][] in bottom up manner 
    for (i = 0; i <= n; i++)
    {
        for (w = 0; w <= W; w++)
        {
            if (i == 0 || w == 0)
                K[i][w] = 0;
            else if (wt[i - 1] <= w)
                K[i][w] = std::max(val[i - 1] + K[i - 1][w - wt[i - 1]], K[i - 1][w]);
            else
                K[i][w] = K[i - 1][w];
        }
    }

    return K[n][W];
}

int main()
{
    int val[] = { 60, 100, 120 };
    int wt[] = { 10, 20, 30 };
    int  W = 50;
    int n = sizeof(val) / sizeof(val[0]);
    printf("%d", knapSack(W, wt, val, n));
    return 0;
}