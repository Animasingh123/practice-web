#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int>arr = {-1,2,3,-10,4,-5,10,-8,10};
    int max_sum=INT_MIN,max_ending_sum=0;
    for(int i=0; i < arr.size() ;++i)
    {
        max_ending_sum += arr[i];
        max_sum = max(max_sum,max_ending_sum);
        max_ending_sum = max(max_ending_sum,0);
    }
    cout<<"Max sum of contiguous sub array is "<<max_sum<<endl;
    return 0;
}