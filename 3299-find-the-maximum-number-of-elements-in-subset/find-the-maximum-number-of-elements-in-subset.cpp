class Solution {
public:
    int maximumLength(vector<int>& nums) {
        
        unordered_map<long long,int> mp;

        for(int x : nums)
            mp[x]++;

        int ans = 1;

        // Special handling for 1
        if(mp.count(1)) {
            int cnt = mp[1];

            // only odd count possible
            if(cnt % 2 == 0)
                cnt--;

            ans = max(ans, cnt);
        }

        for(auto &[x, cnt] : mp) {

            if(x == 1) continue;

            long long cur = x;
            int len = 0;

            while(mp[cur] >= 2) {

                // next square must exist
                long long nxt = cur * cur;

                if(mp.find(nxt) == mp.end())
                    break;

                len += 2;
                cur = nxt;
            }

            // center element
            if(mp[cur] >= 1)
                len++;

            ans = max(ans, len);
        }

        return ans;
    }
};