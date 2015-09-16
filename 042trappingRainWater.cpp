// Source : https://oj.leetcode.com/problems/
// Author : Tony
// Date   : 15-09-2015

/********************************************************************************** 
* Given n non-negative integers representing an elevation map where the width of each bar is 1, 
* compute how much water it is able to trap after raining. 
* For example, 
* Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.
*     ^                                             
*     |                                             
*   3 |                       +--+                  
*     |                       |  |                  
*   2 |          +--+xxxxxxxxx|  +--+xx+--+         
*     |          |  |xxxxxxxxx|  |  |xx|  |         
*   1 |   +--+xxx|  +--+xxx+--+  |  +--+  +--+      
*     |   |  |xxx|  |  |xxx|  |  |  |  |  |  |      
*   0 +---+--+---+--+--+---+--+--+--+--+--+--+----->
*       0  1   0  2  1   0  1  3  2  1  2  1        
* The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 
* 6 units of rain water (blue section) are being trapped. Thanks Marcos for contributing this image!
**********************************************************************************/


#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        if(n<2) return 0;
        int area=0;
        int left=0;
        int right=0;

        for(int i=0; i<n; i++){
        	//cout << "start: " << i << endl;
        	left = height[i];
        	int j=i+1;
        	int flag=0;
        	while(j<n){
        		if(height[j] >= left){
        			flag = 1;
        			break;	
        		}
        		j++;
        	}
        	if(flag == 1 && (j-i)>1 ){
        		for(int k=i+1; k<j; k++){
        			area = area + left - height[k];
        		}
        		i = j-1;
        	}
        }

		for(int i=n-1; i>=0; i--){
			right = height[i];
			int j = i-1;
			int flag = 0;
			while(j>=0){
				if(height[i] > right){
					flag=1;
					break;
				}
				j--;
			}
			if(flag==1 && (i-j)>1 ) {
				for(int k=i-1; k>j; k--){
					area = area + right - height[k];
				}
				i = j+1;
			}
		}

        return area;
    }
};


int main(){
	Solution test;
	int arr[] = {0,1,0,2,1,0,1,3,2,1,2,1};
	vector<int> v;
	v.assign(arr,arr+12);
	int k = test.trap(v);
	cout << "Result:" << k << endl;
	return 0;
}
