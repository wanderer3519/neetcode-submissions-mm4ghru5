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
    return x.start <= y.start;
}


class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), comp);

        int n = intervals.size();
        for(int i = 1; i < n; i++){
            Interval& int2 = intervals[i];
            Interval& int1 = intervals[i - 1];

            if(int1.end > int2.start)
                return false;
        }

        return true;
    }
};
