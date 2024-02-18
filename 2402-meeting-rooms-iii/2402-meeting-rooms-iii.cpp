class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        vector<int> meetingCount(n, 0);
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> usedRooms;
        priority_queue<int, vector<int>, greater<int>> unusedRooms;
        for (int i = 0; i < n; i++) {
            unusedRooms.push(i);
        }
        sort(meetings.begin(), meetings.end());

        for(int i = 0;i < meetings.size();i++) {
            int start = meetings[i][0];
            int end = meetings[i][1];
            while(!usedRooms.empty() && usedRooms.top().first <= start) {
                unusedRooms.push(usedRooms.top().second);
                usedRooms.pop();
            }
            if(!unusedRooms.empty()) {
                int room = unusedRooms.top();
                unusedRooms.pop();
                usedRooms.push({end,room});
                meetingCount[room]++;
            }
            else {
                long long endTime = usedRooms.top().first;
                int room = usedRooms.top().second;
                usedRooms.pop();
                usedRooms.push({endTime + end - start,room});
                meetingCount[room]++;
            }
        }
        int maxMeetingCount = 0, maxMeetingCountRoom = 0;
        for (int i = 0; i < n; i++) {
            if (meetingCount[i] > maxMeetingCount) {
                maxMeetingCount = meetingCount[i];
                maxMeetingCountRoom = i;
            }
        }
        return maxMeetingCountRoom;
    }
};
