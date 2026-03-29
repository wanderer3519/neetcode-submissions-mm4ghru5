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
        int n = times.size();
	    
	    vector<int> start(n);
	    vector<int> end(n);
	    
	    for(int i = 0; i < n; i++){
	        start[i] = times[i].start;
	        end[i] = times[i].end;
	    }
	    
	    sort(start.begin(), start.end());
	    sort(end.begin(), end.end());
	    
	    int s = 0;
	    int e = 0;
	    int maxcnt = 0;
	    int cnt = 0;
	    while(e < n){
    	    while(s < n && start[s] < end[e]){
    	        s++;
    	        cnt++;
    	    }
    	    
    	    
    	    maxcnt = max(maxcnt, cnt);
            cnt--;
            e++;
	    }
	    
	    return maxcnt;
    }
};
