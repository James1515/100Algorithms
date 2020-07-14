#include <bits/stdc++.h>
using namespace std;

//Function: MinCoins
//Parameters:
//m - size of coins array
//V - the amount looked for
//coins - array of denominations of coins
//Returns: The int value of table[V] which provides the solution:
 int MinCoins(int coins[], int m, int V)
{
    // table[i] will be storing the minimum number of coins
    // required for i value.  So table[V] will have result
    int table[V+1];

    // Base case (If given value V is 0)
    table[0] = 0;

    // Initialize all table values as Infinite
    for (int i=1; i<=V; i++)
        table[i] = INT_MAX;

    // Compute minimum coins required for all
    // values from 1 to V
    for (int i=1; i<=V; i++)
    {
        // Go through all coins smaller than i
        for (int j=0; j<m; j++)
            if (coins[j] <= i)
            {
                int sub_res = table[i-coins[j]];
                if (sub_res != INT_MAX && sub_res + 1 < table[i])
                    table[i] = sub_res + 1;
            }
    }
    return table[V];
}



int main() {

    int coins[] = {1, 3, 4};

    int m = sizeof(coins) / sizeof(coins[0]);

    int V;

    cin >> V;

    cout << MinCoins(coins, m, V);

    return 0;
}
