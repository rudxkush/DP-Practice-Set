class Solution {
public: 
    int n = 0;
    vector<int> dp;
    int recMaximiseProfit(vector<tuple<int, int, int>>& intervals, int i) {
        // base case
        if(i >= n) {
            return 0;
        }
        if(dp[i] != -1) return dp[i];
        // if I choose to pick then I would be need to 
        // perform BS to find the next start of an   
        // another non overlapping interval.
        int start = i + 1, end = n - 1, j = n;
        while(start <= end) {
            int mid = (start + end)/2;
            if(get<0>(intervals[mid]) >= get<1>(intervals[i])) {
                j = mid;
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }

        int pick = get<2>(intervals[i]) + recMaximiseProfit(intervals, j);

        int notPick = recMaximiseProfit(intervals, i + 1);

        return dp[i] = max(pick, notPick);
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        n = startTime.size();
        vector<tuple <int, int, int>> intervals(n);     
        for(int i = 0; i < n; i++) {
            int start = startTime[i];
            int end = endTime[i];
            int gain = profit[i];
            intervals[i] = {start, end, gain};
        }
        dp.assign(n, -1);
        sort(intervals.begin(), intervals.end());
        return recMaximiseProfit(intervals, 0);
    }
};
