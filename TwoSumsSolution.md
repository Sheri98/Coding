## TWO SUMS CPP Solutions using HashMaps:

### Method:
if the target which we are trying to find using addition of two values in the array, can be solved by thinking if we subtract (target - oneValue) then the remaining value should be present in the array.

```
Remainder = target - Value1
```

Now, we can retrive the index by storing the value -> Index in a hashamap and trying to find it in it and retirive the index.


THis make the solution in O(n) and Space O(n).  Why should not directly use array to find the index because any opeartion to do so will perform search algorithm which will increase the complexity to O(n*m) where m being mth index where we find the second value.

```
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map <int,int> indToVal;

        for(int i=0; i<nums.size(); i++){
            int rem = target - nums[i];
            if (indToVal.find(rem)  != indToVal.end()){

                    return {indToVal[rem], i};
            }
            indToVal.insert({nums[i],i});
        }
        return {};
    }
};

```

