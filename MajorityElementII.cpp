//
//  MajorityElementII.cpp
//  CppTrain
//
//  Created by Wanchao Liang on 2/21/16.
//  Copyright © 2016 Wanchao Liang. All rights reserved.
//

#include "utils.h"

class Solution {
    
public:

    vector<int> majorelement(vector<int> &nums) {
        
        int major1 = 0, major2 = 0;
        int count1 = 0, count2 = 0;
        
        for(size_t i = 0; i < nums.size(); ++ i) {
            
            if(major1 == nums[i]) {
                ++ count1;
            }
            else if(major2 == nums[i]) {
                ++ count2;
            }
            else if(count1 == 0) {
                major1 = nums[i];
                ++ count1;
            }
            else if(count2 == 0) {
                major2 = nums[i];
                ++ count2;
            }
            else{
                --count1;
                --count2;
                
            }
            
        }

		count1 = 0, count2 = 0;
		vector<int> res;


		for (auto ele : nums) {
			if (ele == major1) {
				++ count1;
				
			}
			else if (ele == major2) {
				++ count2;
			}
		}

		if (count1 >(int) nums.size()/3) {
			res.push_back(major1);
			
		}
		if (count2 >(int) nums.size()/3) {
			res.push_back(major2);
			
		}
		
		return res;

    }
    
    
    
};

int main(int argc, char const *argv[])
{
	vector<int> test{2,2,3,3,4,4,4,4};
	vector<int> test2{3,2,3};

	Solution sol;

	vector<int> res =sol.majorelement(test2);

	cout<<res;


	return 0;
}





