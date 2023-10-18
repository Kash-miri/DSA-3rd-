//Problem 1:
//-----------

class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) 
{
        vector<int> newArray(nums.size(), 0);
	{
        for (int i = 0; i < nums.size(); i++) 
	{
            for (int j = 0; j < nums.size(); j++) 
	    {
		if (nums[i] > nums[j]) 
		{
                    	newArray[i]++;
                }
            }
        }

        return newArray;
        }
};

//------------------------------------------------------------------------------------

//Problem 2:
//-----------

class Solution {
public:
    int removeElement(vector<int>& nums, int val) 
	{
        int k = 0;
        for (int i = 0; i < nums.size(); i++) 
	{
            if (nums[i] != val) 
		{
                nums[k] = nums[i];
                k++;
                }
        }
        return k;
        }
};

//------------------------------------------------------------------------------------

//Problem 3:
//-----------

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) 
    {
        int n = matrix.size();
        for(int i = 0; i < n ; i++)
        {
            for(int j = 0; j < n;j++)
            {
                if(target == matrix[i][j])
                {
                    return true;
                }
            }
        }
        return false;
    }
};

//------------------------------------------------------------------------------------

//Problem 4:
//-----------

class Solution {
public:
    int removeDuplicates(vector<int>& nums) 
	{
        int k = 1;
        for(int i = 1; i< nums.size(); i++)
	{
            if(nums[i]!= nums[i-1])
		{
                nums[k] = nums[i];
                k++;
                }
        }
        return k;
        }
};

//------------------------------------------------------------------------------------

//Problem 5:
//-----------

class Solution {
public:
    int maxSubArray(vector<int>& nums) 
    {
        int sum = nums[0];
        int maxi = nums[0];
        for(int i = 1; i<nums.size();i++)
        {
            sum = max(nums[i],sum + nums[i]);
            maxi = max(sum,maxi);     
        }
        return maxi;
    }
};
//------------------------------------------------------------------------------------

//Problem 6:
//-----------

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) 
    {
        int right = n;
        int left = 1;
        while(left<right)
        {
            int mid = left + (right-left)/2;
            if(isBadVersion(mid))
            {
                right = mid;
            }
            else
            {
                left = mid + 1;
            }   
        }
        return left;
    }
};

//------------------------------------------------------------------------------------

//Problem 7:
//-----------

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) 
    {
        int n = nums.size();
        for (int i = 0; i < n; i++) 
        {
            while (nums[i] > 0 && nums[i] <= n && nums[nums[i] - 1] != nums[i]) 
            {
                swap(nums[i], nums[nums[i] - 1]);
            }
        }
        for (int i = 0; i < n; i++) 
        {
            if (nums[i] != i + 1) 
            {
                return i + 1;
            }
        }
        return n + 1;
    }
};