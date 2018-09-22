#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
//      Get the skyline from the top/bottom
        vector<int> topSkyline;
        for (int i = 0;i < grid[0].size();i++) {
            vector<int> building_heights;
            for (int j = 0; j < grid.size(); j++) {
                building_heights.push_back(grid[j][i]);
            }
            topSkyline.push_back(*max_element(building_heights.begin(), building_heights.end()));
        }
        
//      Get skyline from right/left
        vector<int> sideSkyline;
        for (int i = 0; i < grid.size(); i++) {
            vector<int> building_heights;
            sideSkyline.push_back(*max_element(grid[i].begin(), grid[i].end()));
        }
        
        int increase = 0;
        
        for (int i = 0;i < grid.size(); i++) {
            int rowMax = sideSkyline[i];
            for (int j = 0; j < grid[0].size(); j++) {
                int lowerHeight = rowMax < topSkyline[j] ? rowMax : topSkyline[j];
                increase += lowerHeight - grid[i][j];
            }
        }
        
        return increase;
    }
};