#include <bits/stdc++.h>
#include <iostream>
#define vi vector<int>
using namespace std;

class Solution {
    int check(int x2,int y2,int x,float m){
        return m*(x-x2)+y2;
    }
public:
    bool checkStraightLine(vector<vector<int>>& co) {
        if(co.size()<2)
            return false;
        if(co.size()==2)
            return true;
        int den = co[1][0]-co[0][0];
        int num = co[1][1]-co[0][1];
        for(int i = 2;i<co.size();i++){
            int d = co[i][0]-co[i-1][0];
            int n = co[i][1]-co[i-1][1];
            if(n*den!=num*d)
                return false;
        }
        return true;
        // int y,m,i=2;
        // int size = co.size();
        // vector<int> c;
        // if(co.size()<2)
        //     return false;
        // if(co.size()==2)
        //     return true;
        // int den = co[size-1][0]-co[0][0];
        // if(den==0)
        //     return false;
        // m = (co[size-1][1]-co[0][1])/float(den);
        // while(i<co.size()){
        //     c = co[i];
        //     y = check(co[size-1][0],co[size-1][1],c[0],m);
        //     if(y!=c[1])
        //         return false;
        //     i++;
        // }
        // return true;
    }
};

int main(){
    Solution s;
    vector<vi> points = {{1,2},{2,3},{3,4},{4,5},{5,6},{6,7}};
    s.checkStraightLine(points);
}