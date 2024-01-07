class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& n) {
        int a=0,l=0;
        for(auto i:n)
            if(i[0]*i[0]+i[1]*i[1]>=l)
                l=i[0]*i[0]+i[1]*i[1];
        for(auto i:n)
            if(i[0]*i[0]+i[1]*i[1]==l)
                a=max(a,i[0]*i[1]);
        return a;
    }
};