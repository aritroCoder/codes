#include <bits/stdc++.h>

#define endl "\n"

using namespace std;

void check(vector<int> &v, int size, string s, int stringSize, int index)
{
    if (index >= 0)
    {
        // dont include last element
        check(v, size, s, stringSize + 1, index - 1);
        // inlcude last element
        s = s.append(to_string(v[index]));
        check(v, size, s, stringSize + 1, index - 1);
    }
    else{
        cout<<s<<endl;
    }
}

int main()
{
    vector<int> v = {1, 2, 3, 4};
    string s = "";
    check(v, v.size(), s, s.size(), v.size() - 1);
    return 0;
}