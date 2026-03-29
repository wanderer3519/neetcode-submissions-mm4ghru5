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
    int minMeetingRooms(vector<Interval>& times) {
        sort(times.begin(), times.end(), [&](const auto& a, const auto& b){
			return a.start < b.start;
	    });
	    
		priority_queue<int, vector<int>, greater<int>> pq;
		
		int n = times.size();
		
		for(int i = 0; i < n; i++){
			if(!pq.empty() && pq.top() <= times[i].start){
				pq.pop();
			}
			pq.push(times[i].end);
		}
	    
	    return pq.size();
    }
};
