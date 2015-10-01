// Source : https://oj.leetcode.com/problems/
// Author : Tony
// Date   : 01-10-2015

/********************************************************************************** 
* Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).
* You may assume that the intervals were initially sorted according to their start times.
* Example 1:
* Given intervals [1,3],[6,9], insert and merge [2,5] in as [1,5],[6,9].
* Example 2:
* Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] in as [1,2],[3,10],[12,16].
* This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10].
**********************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
};


class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval){
        vector<Interval> output;
		int n = intervals.size();
		int start = newInterval.start;
		int end = newInterval.end;
		int spos = -1;

		for(int i=0; i<n; ++i){
			if(start < intervals[i].start){
				spos = i;
				break;
			}
		}
		if(spos == -1){
			spos = n;
		}
		intervals.insert(intervals.begin()+spos, newInterval);
		for(int i=0; i<intervals.size(); i++) { 
        int size = output.size();
        if( size>0 && output[size-1].end >= intervals[i].start) {
            output[size-1].end = max(output[size-1].end, intervals[i].end); 
        }else{
            output.push_back(intervals[i]);
        }
    }
		return output;
    }
};

/* //For testing
int main(){
    Solution test;
	Interval a(1,5);
	Interval b(3,4);
	Interval c(5,6);
	Interval d(7,8);
	Interval e(9,10);
	Interval i(0,0);
	vector<Interval> v;
	v.push_back(a);
	v.push_back(b);
	v.push_back(c);
	v.push_back(d);
	v.push_back(e);

	vector<Interval> re;
	re = test.insert(v,i);
	for(unsigned int i=0; i<re.size(); i++){
		cout << re[i].start << " " << re[i].end << endl;
	}

    return 0;
}
*/
