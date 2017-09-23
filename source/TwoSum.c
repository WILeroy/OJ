/*Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:

Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].

Subscribe to see which companies asked this question.*/

/************************     answer  code      ***************************/

int* twoSum(int* nums, int numsSize, int target) 
{  
    int *result = (int*)malloc(2 * sizeof(int));
    result[0] = result[1] = -1;
    
    for(int i = 0; i<numsSize; i++)  
    {  
        for(int j=i+1; j<numsSize; j++)  
        {  
            if(nums[i] + nums[j] == target)  
            {  
                result[0] = i;  
                result[1] = j;
                break;
            }  
        }  
        
        if (result[0] != -1)
        {
            break;
        }
    }  
    return result;  
} 
