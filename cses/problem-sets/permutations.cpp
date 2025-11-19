#include <bits/stdc++.h>
using namespace std;

/*
n = 1 output = 1
n = 2 output NO SOLUTION
n = 3 output NO SOLUTION
n = 4 output 2 4 1 3, 3 1 4 2,
n = 5 output 4 2 5 3 1, 4 1 3 5 2, 2 4 1 5 3, 3 5 2 4 1

Strategy 1:
Create a graph where the node is each number and an edge connects node that can be adjacent to each other, differ more than 1. Then traverse the graph starting from each node, until a beautiful sequence is found.
Time Complexity: O(n!)

Strategy 2:
Go through all permutations of n and check if each one is valid. This is also O(n!)

Observation:
The size of input for this problem is up to 10^6, time limit is 1s which means the algorithm we're looking for is O(n) or O(nlogn).

Strategy 3:
https://www.geeksforgeeks.org/competitive-programming/cses-solutions-permutations/
Output all even numbers first then odd numbers
Provable that is correct
*/

// int main() {
//     int n;
//     cin >> n;
        
//     if (n == 2 || n == 3) {
//         cout << "NO SOLUTION\n";
//         return 0;
//     } 
//     // Output all even numbers
//     for (int i = 2; i <= n; i += 2) {
//         cout << i << " ";
//     }
//     // Output all odd numbers
//     for (int i = 1; i <= n; i += 2) {
//         cout << i << " ";
//     }
//     cout << "\n";
// }

/*
Solution by CSES
for n >= 4, we know that n / 2 is always >= 2
So by starting in the middle number and decreasing to 1 we get a pair of number that is always 2 or more apart.
Odd number just have extra n at the end.
*/
int main() {
    int n;
    cin >> n;
    if (n == 1) {
        cout << "1\n";
        return 0;
    }
    if (n == 2 || n == 3) {
        cout << "NO SOLUTION\n";
        return 0;
    }
    for (int i = n / 2; i >= 1; i--) {
        cout << i << " " << i + n / 2 << " ";
    }
    if (n % 2 == 1) cout << n << " ";
    cout << "\n";
}
