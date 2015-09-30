// Source : https://oj.leetcode.com/problems/
// Author : Tony
// Date   : 30-09-2015

/********************************************************************************** 
* Given a collection of intervals, merge all overlapping intervals.
* For example,
* Given [1,3],[2,6],[8,10],[15,18],
* return [1,6],[8,10],[15,18].
**********************************************************************************/

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
};

/* 
  using a map to sort the Interval.start 
  better solution: self-defined function by sort()
*/
class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> output;
		int n = intervals.size();
		if(n<=0) return output;

		map<int,int> tmp;
		for(int i=0; i<n; i++){
			if(tmp.find(intervals[i].start) == tmp.end() || 
					intervals[i].end > tmp.at(intervals[i].start)){
				tmp[intervals[i].start] = intervals[i].end;
			}
		}
		while(tmp.size()!=0){
			auto next = tmp.cbegin();
			auto it = next++;
			if(next == tmp.cend()){
				Interval tempInterval((*it).first, (*it).second);
				output.push_back(tempInterval);
				tmp.erase(it);
				break;
			}
			if((*it).second < (*next).first){
				//not overlapped
				Interval tempInterval((*it).first, (*it).second);
				output.push_back(tempInterval);
				tmp.erase(it);
			}
			else if((*it).second >= (*next).first && (*it).second <= (*next).second){
				//partially overlapped
				tmp[(*it).first] = (*next).second;
				tmp.erase(next);
			}
			else if((*it).second > (*next).second){
				//overlapped
				tmp.erase(next);
			}
		}
		return output;
    }
};

/* adopted from: https://github.com/haoel/leetcode/blob/master/algorithms/mergeIntervals/mergeIntervals.cpp
 //Two factos sorting [start:end]
bool compare(const Interval& lhs, const Interval& rhs){
    return (lhs.start==rhs.start) ? lhs.end < rhs.end : lhs.start < rhs.start;
}

vector<Interval> merge(vector<Interval> &intervals) {

    vector<Interval> result;

    if (intervals.size() <= 0) return result;
    //sort the inervals. Note: using the customized comparing function.
    sort(intervals.begin(), intervals.end(), compare);
    for(int i=0; i<intervals.size(); i++) { 
        int size = result.size();
        // if the current intervals[i] is overlapped with previous interval.
        // merge them together
        if( size>0 && result[size-1].end >= intervals[i].start) {
            result[size-1].end = max(result[size-1].end, intervals[i].end); 
        }else{
            result.push_back(intervals[i]);
        }
    }
    
    return result;
}
*/

/* //For testing
int main(){
    Solution test;
	Interval a(1,9);
	Interval b(4,8);
	Interval c(10,11);
	vector<Interval> v;
	v.push_back(a);
	v.push_back(b);
	v.push_back(c);

	vector<Interval> re;
	re = test.merge(v);
	for(unsigned int i=0; i<re.size(); i++){
		cout << re[i].start << " " << re[i].end << endl;
	}

    return 0;
}
*/
