class Solution {
public:
  vector<int> getLeastNumbers_Solution(vector<int> input, int k) {
    priority_queue<int> h;
    for (auto i : input) {
      h.push(i);
      if (h.size() > k)
        h.pop();
    }

    vector<int> res;
    while (!h.empty()) {
      res.push_back(h.top());
      h.pop();
    }
    reverse(res.begin(), res.end());
    return res;
  }
};
