class Solution {
  public:
    vector<vector<int>> insertInterval(vector<vector<int>> &intervals,
                                       vector<int> &newInterval) {
        vector<vector<int>> ans;
        int index = 0;
        const int n = intervals.size();
        
        while (index < n) {
            if (intervals[index][1] >= newInterval[0]) break;
            ans.push_back(intervals[index++]);
        }
        
        if (index == n) {
            ans.push_back(newInterval);
            return ans;
        }
        
        newInterval[0] = min(newInterval[0], intervals[index][0]);
        
        while (index < n) {
            if (intervals[index][0] > newInterval[1]) break;
            newInterval[1] = max(newInterval[1], intervals[index][1]);
            index++;
        }
        
        ans.push_back(newInterval);
        
        while (index < n) {
            ans.push_back(intervals[index++]);
        }
        
        return ans;
    }
};