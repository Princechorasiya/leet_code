using ll =long long;
class Solution {
public:
    long long minEnd(int n, int x)
  {
    vector<ll> bitStore(64, 0); // number /store teh possible combination of that posiiton

    string nbit = bitset<64>(x).to_string();

    string ans = nbit;
    vector<int> indexes;
    for (int i = 0; i <= 63; i++)
    {
      if (nbit[i] == '0')
        indexes.push_back(i);
    }

    int t = indexes.size();

    string nasbit = bitset<64>(n - 1).to_string();

    int offset = 64 - t;
    for (int i = t - 1; i >= 0; i--)
    {

      ans[indexes[i]] = nasbit[i + offset];
    }

    return bitset<64>(string(ans)).to_ullong();
  }
};