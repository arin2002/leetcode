class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int> minutes;

        for (const auto& timePoint : timePoints) {
            int hours = stoi(timePoint.substr(0, 2));
            int minutes_ = stoi(timePoint.substr(3, 2));
            minutes.push_back(hours * 60 + minutes_);
        }

        sort(minutes.begin(), minutes.end());

        int min_diff = INT_MAX;
        for (int i = 1; i < minutes.size(); i++) {
            min_diff = min(min_diff, abs(minutes[i] - minutes[i - 1]));
        }

        // Handle the case where the first and last time-points are adjacent
        min_diff = min(min_diff, abs(minutes.front() - minutes.back() + 1440));

        return min_diff;
    }
};
