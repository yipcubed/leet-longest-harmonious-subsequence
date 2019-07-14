#include <algorithm>
#include <cstring>
#include <climits>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>


#include "../utils/VectorUtils.hpp"
#include "../utils/PrintUtils.hpp"

// https://leetcode.com/problems/longest-harmonious-subsequence/

// #include "../utils/HeapUtils.hpp"
// #include "../utils/BinarySearch.hpp"
// #include "../utils/TreeUtils.hpp"

using namespace std;

#pragma GCC diagnostic ignored "-Wunknown-pragmas"

// Live coding problems, watch at
// https://www.twitch.tv/yipcubed
// https://www.youtube.com/channel/UCTV_UOPu7EWXvYWsBFxMsSA/videos
//

// makes code faster, but larger. Just for LeetCode fun!
#pragma GCC optimise ("Ofast")

// makes stdin not synced so it is faster. Just for LeetCode fun!
static auto __ __attribute__((unused)) = []() {              // NOLINT
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int findLHS(vector<int>& nums) {
        if (nums.empty()) return 0;
        map<int,int> m;
        for (auto& item : nums) {
            ++m[item];
        }
        int res = 0;
        for (auto& p : m) {
            if (m.count(p.first + 1)) {
                res = max(res, p.second + m[p.first +1]);
            }
        }

        return res;
    }
};

void test1() {
    vector<int> v1{1,3,2,2,5,2,3,7};

    cout << "5 ? " << Solution().findLHS(v1) << endl;

    vector<int> v2{1,1,1,1};

    cout << "0 ? " << Solution().findLHS(v2) << endl;

    vector<int> v3{1,2,2,1};

    cout << "4 ? " << Solution().findLHS(v3) << endl;
}

void test2() {

}

void test3() {

}