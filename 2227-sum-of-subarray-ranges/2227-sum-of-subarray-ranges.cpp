using ll = long long;
class Solution
{
public:
  ll sumOfMins(vector<int> &nums)
  {
    // find out the no of times that element that can occur
    int n = nums.size();

    vector<int> prevSmallest(n, -1);
    vector<int> nextSmallest(n, n);
    // find the prev smallest
    stack<int> st;
    for (int i = 0; i < n; i++)
    {
      if (st.empty())
      {
        st.push(i);
      }
      else
      {
        while (!st.empty() && nums[st.top()] >= nums[i])
        {
          st.pop();
        }
        if (!st.empty())
          prevSmallest[i] = st.top();
        st.push(i);
      }
    }
    // print(prevSmallest);

    stack<int> st2;
    // get the nextSmallest indexes
    for (int i = n - 1; i >= 0; i--)
    {
      if (st2.empty())
      {
        st2.push(i);
      }
      else
      {
        while (!st2.empty() && nums[st2.top()] > nums[i])
          st2.pop();
        if (!st2.empty())
        {
          nextSmallest[i] = st2.top();
        }
        st2.push(i);
      }
    }
    // print(nextSmallest);
    ll sum = 0;
    for (int i = 0; i < n; i++)
    {
      sum = sum + (ll)(nextSmallest[i] - i) * (ll)(i - prevSmallest[i]) *(ll) nums[i];
    }
    return sum;
  }

  // find the sum of the max elements
  ll sumOfMax(vector<int> &nums)
  {
    // find the prev max
    int n = nums.size();
    vector<int> prevGreater(n, -1);
    vector<int> nextGreater(n, n);
    stack<int> st;
    for (int i = 0; i < n; i++)
    {
      if (st.empty())
      {
        st.push(i);
      }
      else
      {
        while (!st.empty() && nums[st.top()] <= nums[i])
          st.pop();
        if (!st.empty())
          prevGreater[i] = st.top();
        st.push(i);
      }
    }
    // print(prevGreater);
    stack<int> st2;
    for (int i = n - 1; i >= 0; i--)
    {
      if (st2.empty())
      {
        st2.push(i);
      }
      else
      {
        while (!st2.empty() && nums[st2.top()] < nums[i])
          st2.pop();
        if (!st2.empty())
          nextGreater[i] = st2.top();
        st2.push(i);
      }
    }
    // print(nextGreater);
    ll sum = 0;
    for (int i = 0; i < n; i++)
    {
      sum = sum + (ll)(nextGreater[i] - i) *(ll) (i - prevGreater[i]) * (ll)nums[i];
    }
    return sum;
  }
  long long subArrayRanges(vector<int> &nums)
  {
    return sumOfMax(nums) - sumOfMins(nums);
  }
};