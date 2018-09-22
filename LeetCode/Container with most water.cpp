class Solution {
public:
    int maxArea(vector<int>& height) {
        int max_vol = 0;
        int lo = 0;
        int hi = height.size() - 1;
        int j = hi;
        
        for (int i = 0;i < j;i++) {
            int vol = height[lo] > height[hi] ? (hi-lo)*height[hi] : (hi-lo)*height[lo];
            max_vol = vol > max_vol ? vol: max_vol;
            
            if (height[lo] > height[hi]) {
                hi--;
            } else {
                lo++;
            }
        }
        
        return max_vol;
    }
};