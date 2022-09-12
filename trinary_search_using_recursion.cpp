#include <bits/stdc++.h>

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)

#define endl "\n"

using namespace std;

void trin_search(int n, vector<int> vec){
    //base and terminating condition
    if (vec.size() == 1)
    {
        if (vec[0] == n)
            cout << "Found" << endl;
        else
            cout << "not found" << endl;
    }else{
        int s = vec.size();
        int l1 = ceil(s/3.0);
        int l2 = ceil((s-l1)/2.0);
        int l3 = s - l1 - l2;
        if (vec[0] <= n && vec[l1 - 1] >= n)
        {
            vector<int> newvec(vec.begin(), vec.begin() + l1);
            trin_search(n, newvec);
        }else if(vec[l1] <= n && vec[l1+l2-1] >= n){
            vector<int> newvec(vec.begin()+l1, vec.begin()+l1+l2);
            trin_search(n, newvec);
        }else if(vec[l1+l2] <= n && vec[vec.size()-1] >= n){
            vector<int> newvec(vec.begin()+l1+l2, vec.end());
            trin_search(n, newvec);
        } else cout<< "Not found" << endl;
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
    trin_search(n, list);
    return 0;
}