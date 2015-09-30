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
		int spos = 0;
		int epos = 0;

		for(int i=0; i<n; ++i){
			if(start > intervals[i].start) spos++; 
			if(end > intervals[i].end) epos++;
		}
		if(spos == 0 && epos == 0){
			output = intervals;
			output.insert(output.begin(),newInterval);
			return output;
		}
		else if (spos == n && epos == n){
			output = intervals;
			output.push_back(newInterval);
			return output;
		}
		else{
			for(int i=0; i<n; i++){
				if(i<spos){
					output.push_back(intervals[i]);
				}

			}
		}
		
		
		return output;
    }
};

 //For testing
int main(){
    Solution test;
	Interval a(1,5);
	/*Interval b(3,4);
	Interval c(5,6);
	Interval d(7,8);
	Interval e(9,10);*/
	Interval i(0,0);
	vector<Interval> v;
	v.push_back(a);
	/*v.push_back(b);
	v.push_back(c);
	v.push_back(d);
	v.push_back(e);*/

	vector<Interval> re;
	re = test.insert(v,i);
	for(unsigned int i=0; i<re.size(); i++){
		cout << re[i].start << " " << re[i].end << endl;
	}

    return 0;
}
