#include <bits/stdc++.h>
#include <iostream>
#define vi vector<int>
using namespace std;

class Solution {
    void helper(vector<vector<int>> &image,int x,int y,int prev, int newColor){
        if(x<0|| x>=image.size()||y<0||y>image[0].size())
            return;
        if(image[x][y]!=prev||image[x][y]==newColor)
            return;
        image[x][y] = newColor;
        helper(image,x+1, y,prev, newColor);
        helper(image,x-1, y, prev, newColor);
        helper(image,x, y+1, prev, newColor);
        helper(image,x, y-1, prev, newColor);
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int prevc = image[sr][sc];
        helper(image,sr,sc,prevc,newColor);
        return image;
    }
};

int main(){
    Solution s;
    vector<vi> image={{1,1,1},{1,1,0},{1,0,1}};
    for(auto v:s.floodFill(image,1,1,2)){
        for(auto i:v){
            cout<<i<<"\t";
        }
        cout<<endl;
    }
}