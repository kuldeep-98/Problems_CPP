#include <bits/stdc++.h>
#include <iostream>
#define vi vector<int>
using namespace std;

class Solution{
public:
    vi searchRange(vi &nums, int t){
        vi result;
        bool present = binary_search(nums.begin(),nums.end(),t);
        if(!present)
            return result = {-1,-1};
        else{
            auto low = 0;
            auto high = nums.size()-1;
            int mid = 0;
            while(low <= high){
                mid = (low+high)/2;
                if(nums[mid]<t){
                    low = mid+1;
                }else if(nums[mid]>t){
                    high = mid-1;
                }else break;
            }
            if(nums.size()>0){
                while(nums[mid-1]==nums[mid]){
                    mid--;
                }
            }
            auto upper = upper_bound(nums.begin(),nums.end(),t);
            result.push_back(mid);
            result.push_back(upper - nums.begin()-1);
        }
        return result;
    }
};

int main(){
    Solution s;
    vi arr = {1};
    arr = s.searchRange(arr,1);
    for(int x: arr){
        cout<<x<<endl;
    } 
}