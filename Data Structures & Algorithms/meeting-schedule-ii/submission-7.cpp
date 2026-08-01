/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        int n = intervals.size();
        
        vector<int> starts(n);
        vector<int> ends(n);

        
        for(int i = 0; i < n; i++){
            starts[i] = intervals[i].start;
            ends[i] = intervals[i].end;
        }

        sort(starts.begin(), starts.end());
        sort(ends.begin(), ends.end());

        int s = 0; // curr start time idx
        int e = 0; // curr end time idx

        int maxcnt = 0;
        int cnt = 0;
        while(s < n){
            
            while(s < n && starts[s] < ends[e]){
                cnt++;
                s++;
            }

            
            maxcnt = max(maxcnt, cnt);
            e++;
            cnt--;
        }

        return maxcnt;
    }
};
