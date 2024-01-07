#include<bits/stdc++.h>
using namespace std;
#define pb push_back
typedef long long int ll;
int findPairs(vector<ll>arr,ll n,ll x)
{
    ll l = 0, r = n-1;
    ll result = 0;
    while (l < r)
    {
        if (arr[l] + arr[r] < x)
        {
            result += (r - l);
            l++;
        }
        else
            r--;
    }
 
    return result;
}
int help(vector<int>v,int n,int i,int c){
    if(i==n)
    {
        if(v[i-1]<v[i-2]){
            return INT_MAX;
        }
        // for(int id=1;id<n;id++){
        // if(v[id]<v[id-1]){
        //     return INT_MAX;
        // }
    // }
        return c;
    }
    if(i>=2 && v[i-1]<v[i-2]){
        return INT_MAX;
    }
    if(i>=2){
        int j=1;
        int k=i-1;
        while(j<=k){
            if(v[j]<v[j-1] || v[k]<v[k-1]){
                return INT_MAX;
            }
        }
    }
    int nt=help(v,n,i+1,c);
    v[i]=1;
    int ct1=help(v,n,i+1,c+1);
    v[i]=2;
    int ct2=help(v,n,i+1,c+1);
    v[i]=3;
    int ct3=help(v,n,i+1,c+1);
    return min({nt,ct1,ct2,ct3}); 
}
int minimumOperations(vector<int>& nums) {
        int n=nums.size();
        vector<int>t={};
        int co=0;
        vector<int>nums2=nums;
        int f=0;
        sort(nums2.begin(),nums2.end());
        int cc=0;
        for(int i=0;i<n;i++){
            if(nums2[i]!=nums[i]){
                f=1;
                cc++;
                // break;
            }
        }
        if(f==0){
            return 1;
        }
        for(int i=0;i<n;i++){
            auto f=upper_bound(nums.begin(),nums.end(),nums[i]);
            if(f==t.end()){
                t.push_back(nums[i]);
            }
            else if(f!=t.end()){
                int jk=abs(t.begin()-f);
                t[jk]=min(jk,nums[i]);
                co++;
            }
        }
        return co;




        
        
        int i1=0;
        // int ans=help(nums,n,0,0);
        // cout<<cc<<endl;
        // return min(cc,ans);
}
int main(){
    int t;
    t=1;
    
// for(int i=0;i<33;i++){
//     cout<<"3,";
// }for(int i=0;i<33;i++){
//     cout<<"2,";
// }
// for(int i=0;i<34;i++){
//     cout<<1<<",";
// }

    // cin>>t;
    // t=0;
    while(t--){
        vector<int>v={1,3,2,1,2,2,3,3,2,1,2,3,1};
        int n=v.size();
        v={1,2,3};
        int i=n;
        int j=1;
        int k=i-1;
        while(j<=k){
            cout<<j<<" "<<k<<endl;
            // if(v[j]<v[j-1] || v[k]<v[k-1]){
                // cout<<"-\n";
            // }
            j++;
            k--;
        }
        cout<<"!!";
        // cout<<minimumOperations(v);
    }
}