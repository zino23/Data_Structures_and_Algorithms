#include <list>
#include <string>
#include <vector>

using namespace std;

class Hashmap {
 public:
  void insert(string s) {
    ULL key = (hash(s) % SIZE + SIZE) % SIZE;
    container_[key].push_back({key, s});
  }

  bool find(string s) {
    ULL key = (hash(s) % SIZE + SIZE) % SIZE;
    if (container_[key].empty()) {
      return false;
    }

    for (auto p : container_[key]) {
      if (p.second == s) {
        return true;
      }
    }
    return false;
  }

 private:
  using ULL = unsigned long long;
  using PIS = pair<ULL, string>;

  ULL hash(string s) {
    ULL res = 0;
    /**
     * Assume there will not be key conflicts
     * P == 131
     * Q == 2^64
     */
    for (auto c : s) {
      res = res * 131 + (c - 'A' + 1);
    }
    return res;
  }

  // The first prime that is larger than 1e5
  const static int SIZE = 1e5 + 3;
  list<PIS> container_[SIZE];
};
