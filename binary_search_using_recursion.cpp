#include <bits/stdc++.h>

using namespace std;

void bin_search(int n, vector<int> vec)
{
    if (vec.size() == 1)
    {
        if (vec[0] == n)
            cout << "Found" << endl;
        else
            cout << "not found" << endl;
    }
    else
    {
        int l1 = ceil(vec.size() / 2.0);
        // vec[0] to vec[l1-1], both included, will go to one recursion tree and remaining vec[l1] to vec[vec.end()] will go to another.
        // check if the element we are searching is in the first set or second:
        if (vec[0] <= n && vec[l1 - 1] >= n)
        {
            vector<int> newvec(vec.begin(), vec.begin() + l1);
            bin_search(n, newvec);
        }else if(vec[l1] <= n && vec[vec.size() - 1] >= n){
            vector<int> newvec(vec.begin()+l1, vec.end());
            bin_search(n, newvec);
        }else cout << "Not found" << endl;
    }
}

int main()
{
    vector<int> list;
    int n, i;
    cout << "Enter the number of integers (enter in ascending order)" << endl;
    cin >> n;
    while (n--)
    { // taking inputs
        cin >> i;
        list.push_back(i);
    }

    cout << "enter value to find" << endl;
    cin >> n;
    bin_search(n, list);
}