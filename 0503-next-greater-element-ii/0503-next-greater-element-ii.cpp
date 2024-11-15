class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        return nextGreater(nums);
    }

    vector<int> nextGreater(vector<int> nums)
{
  stack<int> st1; // monotonic decreasing stack
  // for theat particualr eel
  stack<int> st2;
  // for last element prepare the stack
  int n = nums.size();
  vector<int> ans(n, -1);
  for (int i = n - 2; i >= 0; i--)
  {
    if (st2.empty())
    {
      st2.push(nums[i]);
    }
    else
    {
      while (!st2.empty() && st2.top() <= nums[i])
      {
        st2.pop();
      }
      st2.push(nums[i]);
    }
  }
  for (int i = n - 1; i >= 0; i--)
  {
    if (st1.empty())
    {
      // find the max from the stack2 and
      st1.push(nums[i]);
      while (!st2.empty() && st2.top() <= nums[i])
      {
        st2.pop();
      }
      ans[i] = st2.empty() ? -1 : st2.top();
    }
    else
    {
      // look for the max value in the first stack
      while (!st1.empty() && st1.top() <= nums[i])
      {
        st1.pop();
      }
      if (!st1.empty())
      {
        ans[i] = st1.top();
      }
      else
      {
        // llook for the value in the second stack
        while (!st2.empty() && st2.top() <= nums[i])
        {
          st2.pop();
        }
        ans[i] = st2.empty() ? -1 : st2.top();
      }
      st1.push(nums[i]);
    }
  }

  // print(st2);
  return ans;
}
};