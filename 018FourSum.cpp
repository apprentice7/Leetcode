class Solution {
public:
    vector < vector<int> > fourSum(vector<int>& nums, int target) {
        int size = nums.size();
        vector < vector<int> > output;
        /*
        sort(nums.begin(),nums.end());
        if(nums[0]+nums[1]+nums[2]+nums[3] > target) return output;
        if(nums[size-1]+nums[size-2]+nums[size-3]+nums[size-4] < target) return output;
        if(size < 4) return output;
        */
	vector < vector<int> > map;
		
	for(int i=0; i<size; i++){
		for(int j=i+1; j<size; j++){
			vector<int> temp;
			int total = nums[i] + nums[j];
			temp.push_back(i);
			temp.push_back(j);
			temp.push_back(total);
			map.push_back(temp);
		}
	}
	int flag = 0;
	int Msize = map.size();
	for(int x=0; x<Msize; x++){
		for(int y=x+1; y<Msize; y++){
			if(map[x][2] + map[y][2] == target){
				if(map[x][0] != map[y][0] && map[x][0] != map[y][1] && map[x][1] != map[y][0] && map[x][1] != map[y][1]){
					vector<int> tempout;
					int flag = 0;
					tempout.push_back(nums[map[x][0]]);
					tempout.push_back(nums[map[x][1]]);
					tempout.push_back(nums[map[y][0]]);
					tempout.push_back(nums[map[y][1]]);
					sort(tempout.begin(),tempout.end());
					for(int check=0; check < output.size(); check++){
						if(output[check] == tempout){
							flag = 1;
						}
					}
					if(flag == 0){
						output.push_back(tempout);
					}
				}
			}
		}
	}
	return output;
}
};

/* //For testing
int main(){
	Solution test;
	int arr[] = {-476,-471,-457,-449,-444,-444,-423,-419,-417,-404,-398,-392,-382,-382,-369,-358,-352,-352,-344,-305,-300,-297,-291,-272,-271,-268,-266,-253,-249,-222,-172,-161,-126,-124,-106,-104,-101,-101,-89,-71,-68,-67,-45,-37,-26,-23,-18,-17,-15,7,17,29,73,77,84,84,106,118,122,128,140,146,191,201,214,220,234,240,257,264,296,301,314,320,332,336,339,363,396,422,435,457,477,478,478,485,487};
	//int arr[]={1,0,-1,0,-2,2};
	vector<int> numbers;
	numbers.assign(arr,arr+87);
	vector < vector<int> > re = test.fourSum(numbers,-6401);
	for(int tt=0;tt<re.size();tt++){
		cout << re[tt][0] <<","<< re[tt][1] <<","<< re[tt][2] <<","<< re[tt][3] << endl;
	}
	return 0;
}
*/
