class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (hand.size() % groupSize)
            return false;
        map<int, int> count;
        for (int i = 0; i < hand.size(); i++) {
            count[hand[i]]++;
        }
        while (!count.empty()) {

            int num = count.begin()->first;

            for (int i = 1; i < groupSize; i++) {
                int b = num + i;
                if (count.find(b) != count.end()) {
                    count[b]--;
                    if (count[b] == 0) {
                        count.erase(b);
                    }

                } else {
                    return false;
                }
            }
            count[num]--;
            if (count[num] == 0) {
                count.erase(num);
            }
        }
        return true;
    }
};