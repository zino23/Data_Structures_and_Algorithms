class Solution {
public:
  // Insert one char from stringstream
  unordered_map<char, int> map;
  queue<char> q;
  void insert(char ch) {
    if (++map[ch] > 1) {
      while (!q.empty() && map[q.front()] > 1) {
        q.pop();
      }
    } else {
      q.push(ch);
    }
  }
  // Return the first appearence once char in current stringstream
  char firstAppearingOnce() {
    if (!q.empty()) {
      return q.front();
    }
    return '#';
  }
};
