#include <iostream>
using namespace std;

int main() {
    int n, W;
    int wt[100], val[100], dp[100][100];

    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> wt[i] >> val[i];

    cin >> W;

    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (i == 0 || w == 0)
                dp[i][w] = 0;
            else if (wt[i - 1] <= w) {
                int include = val[i - 1] + dp[i - 1][w - wt[i - 1]];
                int exclude = dp[i - 1][w];
                dp[i][w] = max(include, exclude);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    cout << "Maximum value = " << dp[n][W];

    return 0;
}