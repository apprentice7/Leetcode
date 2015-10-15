#include <iostream>
using namespace std;

class Solution {
public:
    int mySqrt(int x) {
    if(x<=0) return 0;
		int lower = 0;
		int upper = x/2 + 1;

		while(lower <= upper){
			int root = (lower+upper)/2;

			long long sqr = (long long)root * (long long)root;
			if(sqr < x) lower = root + 1;
			else if(sqr > x) upper = root - 1;
			else{
				return root;
			}
		}
		return upper;
    }
};

/* //For testing
int main(){
	Solution test;
	cout << test.mySqrt(2147483647) << endl;

	return 0;
}
*/
