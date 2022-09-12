#include <bits/stdc++.h>

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)

#define endl "\n"

using namespace std;

void hanoi(int disks, int start, int end)
{
    // base case:
    if (disks == 1)
    {
        cout << "move from " << start << " to " << end << endl;
    }else if (disks == 2){
        cout << "move from " << start << " to " << 6-start-end << endl;
        cout << "move from " << start << " to " << end << endl;
        cout << "move from " << 6-start-end << " to " << end << endl;
    }
    else
    {
        // divide all disks into top n-1 disk and bottom one disk
        // for top n-1 disks:
        hanoi(disks - 1, start, 6 - start - end); // 6-start-end gives the number of third rod
        hanoi(1, start, end);
        hanoi(disks - 1, 6-start-end, end);
    }
}

int main()
{
    // for 3 towers only
    int disks;
    cout << "Enter number of disks in tower A" << endl;
    cin >> disks;
    hanoi(disks, 1, 3);
    return 0;
}