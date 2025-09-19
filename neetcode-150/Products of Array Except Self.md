# Products of Array Except Self (Medium)

## Problem Statement

Given an integer array nums, return an array output where ``output[i]`` is the product of all the elements of nums except ``nums[i]``.

Could you solve it in ``O(n)`` time without using the division operation?

### Example

```python
Input: nums = [1,2,4,6]

Output: [48,24,12,8]
```

## Python Solution

- The value of ``output[i]`` in the ``output`` array is the product of the multiplicative sum of all numbers before the current number (``nums[0:x-1]``) and all numbers after the current number ``nums[x+1:]``.

- For the multiplicative sum of all numbers before the current number (``nums[0:x-1]``), our solution is to calculate a prefix sum array.
   - Element ``x`` in the prefix sum array is (x * multiplicative sum of all numbers BEFORE the current number)

- For the multiplicative sum of all numbers after the current number (``nums[x+1:]``), our solution is to calculate a postfix sum array.
   - Element ``x`` in the postfix sum array is (x * multiplicative sum of all numbers AFTER the current number)  

**Time:** O(N)
**Space:** O(N)


```python
class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        prefix = [nums[x] for x in range(len(nums))]
        postfix = [nums[x] for x in range(len(nums))]
        output = [nums[x] for x in range(len(nums))]

        # Element x in the prefix array is the (x * multiplicative sum of all previous elements)
        i = 0
        j = 1
        while j < len(prefix):
            prefix[j] = prefix[i] * prefix[j]
            i += 1
            j += 1

        # Element x in the postfix array is (x * multiplicative sum of all subsequent elements)
        i = len(postfix) - 1 # Last element in array
        j = len(postfix) - 2 # Before last position in array

        while j >= 0:
            postfix[j] = postfix[j] * postfix[i]

            i -= 1
            j -= 1

        # Creates an array of product except self
        for x in range(len(nums)):
            # The first element is the multiplicative sum of all elements after this position
            if x == 0:
                output[x] = postfix[x + 1]
            # The last element The multiplicative sum of all elements before this position
            elif x == len(nums) - 1:
                output[x] = prefix[x - 1]
            # Every other element is the multiplicative sum of all elements after this position * the multiplicative sum of all elements before this position
            else:
                output[x] = prefix[x - 1] * postfix[x + 1]

        return output
```
