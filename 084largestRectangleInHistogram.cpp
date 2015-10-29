// Source : https://oj.leetcode.com/problems/
// Author : Tony
// Date   : 29-10-2015

/********************************************************************************** 
 * Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, 
 * find the area of largest rectangle in the histogram.
 *                    6          
 *                  +---+        
 *               5  |   |        
 *              +---+   |        
 *              |   |   |        
 *              |   |   |        
 *              |   |   |     3  
 *              |   |   |   +---+
 *        2     |   |   | 2 |   |
 *      +---+   |   |   +---+   |
 *      |   | 1 |   |   |   |   |
 *      |   +---+   |   |   |   |
 *      |   |   |   |   |   |   |
 *      +---+---+---+---+---+---+
 * Above is a histogram where width of each bar is 1, given height = [2,1,5,6,2,3].
 *      
 *                    6          
 *                  +---+        
 *               5  |   |        
 *              +-------|        
 *              |-------|        
 *              |-------|        
 *              |-------|     3  
 *              |-------|   +---+
 *        2     |-------| 2 |   |
 *      +---+   |-------|---+   |
 *      |   | 1 |-------|   |   |
 *      |   +---|-------|   |   |
 *      |   |   |-------|   |   |
 *      +---+---+---+---+---+---+
 * The largest rectangle is shown in the shaded area, which has area = 10 unit.
 * For example,
 * Given height = [2,1,5,6,2,3],
 * return 10.
 **********************************************************************************/

/* idea adopted from: http://www.geeksforgeeks.org/largest-rectangle-under-histogram/
*  code adopted from: https://leetcode.com/discuss/12780/my-concise-c-solution-ac-90-ms
*  not fully understand
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int largestRectangleArea(vector<int> &height) {
    int ret = 0;
    height.push_back(0);
    vector<int> index;

    for(int i = 0; i < height.size(); i++){
      while(index.size() > 0 && height[index.back()] >= height[i]){
        int h = height[index.back()];
        index.pop_back();
        int sidx = index.size() > 0 ? index.back() : -1;
        if(h * (i-sidx-1) > ret) ret = h * (i-sidx-1);
      }
      index.push_back(i);
    }
    return ret;
  }
};

/* //For testing
int main(){
	Solution test;
	int his[] ={2,1,5,6,2,3};
	vector<int> v;
	v.assign(his,his+6);
	cout<< test.largestRectangleArea(v) << endl;

	return 0;
}
*/
