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
bool comp(Interval& x, Interval& y){
    return x.end < y.end;
}


class Solution {
private:
    int nonOverlap(vector<Interval>& arr){
        int n = arr.size();

        sort(arr.begin(), arr.end(), comp);
        int cend = INT_MIN;
        int cnt = 0;

        for(int i = 0; i < n; i++){
            if(arr[i].start >= cend){
                cend = arr[i].end;
                cnt++;
            }
        }

        return n - cnt;
    }

public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        int x = nonOverlap(intervals);

        return x == 0;
    }
};
