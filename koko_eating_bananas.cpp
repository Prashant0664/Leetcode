#include<bits/stdc++.h>
using namespace std;
long long int help(vector<int>&arr,int n,int s){
    if(n<s){
        return 0;
    }
    long long int nt=help(arr,n-1,s);
    long long int t=arr[n]+help(arr,n-2,s);
    return max(t,nt);
}
long long int houseRobber(vector<int>& arr)
{
    int n=arr.size();
    int m=n-1;
    long long int ans1=0;
    ans1=help(arr,n-1,1);
    long long int ans2=0;
    ans2=help(arr,n-2,0);
    return max(ans1,ans2);
}
int main(){

    vector<int>arr = {1,2,3,4,5,4,3,2,5,1};
    cout<<houseRobber(arr)<<endl;
}