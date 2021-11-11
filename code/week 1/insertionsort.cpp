#include <bits/stdc++.h>
using namespace std;

void mySort(vector<int> &nums)
{
    for (int i = 0; i < nums.size(); i++)
    {
        int j = i;
        while (j > 0 && nums[j] < nums[j - 1])
        {
            //greater value
            swap(nums[j], nums[j - 1]);
            j--;
        }
    }
}

int main()
{

    vector<int> unsorted = {5, 4, 3, 2, 1};
    mySort(unsorted);

    for (int i = 0; i < unsorted.size(); i++)
    {
        cout << unsorted[i] << "\t";
    }
    cout << endl;
    return 0;
}