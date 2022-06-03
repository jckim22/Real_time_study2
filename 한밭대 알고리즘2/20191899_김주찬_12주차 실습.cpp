#include <iostream>
#include <algorithm>
#include <climits>
#include <random>

using namespace std;

int main()
{
    random_device rd;
    mt19937 gen(rd());   
    uniform_int_distribution<int> dis(0, 1000);

    int N = 15;
   
    int P[502][502];
    int minCost[502][502];
    int record[502][502];

    for (int i = 1; i <= N; i++)
    {
        P[i][0] = dis(gen);
        P[i][1] = dis(gen);
    }

    for (int l = 2; l <= N; l++)
    {
        for (int i = 1; i <= N - l + 1; i++)
        {

            int j = i + l - 1;
            minCost[i][j] = INT_MAX;
            for (int k = i; k <= j - 1; k++)
            {
                int q = minCost[i][k] + minCost[k + 1][j] + P[i][0] * P[k][1] * P[j][1];
                if (q < minCost[i][j]) {
                    minCost[i][j] = q;
                    record[i][j] = k;
                }
            }
        }
    }

    cout << endl;
    cout << "Minimum multiplication: " << minCost[1][N] << endl;

    cout << endl;
    cout << "Number of optimal multiplication" << endl;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cout << minCost[i][j] << "\t";
        }
        cout << endl;
    }

    cout << endl;
    cout << "Paranthesis Position" << endl;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cout << record[i][j] << "\t";
        }
        cout << endl;
    }

}




