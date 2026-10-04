//Leetcode 1552 
//Same question aggressive cows on Geeks for Geeks 
//In the universe Earth C-137, Rick discovered a special form of magnetic force between two balls if they are put in his new invented basket. Rick has n empty baskets, the ith basket is at position[i], Morty has m balls and needs to distribute the balls into the baskets such that the minimum magnetic force between any two balls is maximum.

//Rick stated that magnetic force between two different balls at positions x and y is |x - y|.

//Given the integer array position and the integer m. Return the required force.
class Solution {
public:
    bool fun(vector<int>& position, int n, int guess, int m) {
        int balls = 1;
        int prevpos = position[0];

        for(int i = 1; i < n; i++) {
            int dist = position[i] - prevpos;

            if(dist < guess) {
                continue;
            }
            else {
                balls++;
                prevpos = position[i];
            }
        }

        if(balls >= m) {
            return true;
        }
        else {
            return false;
        }
    }

    int maxDistance(vector<int>& position, int m) {
        int n = position.size();

        sort(position.begin(), position.end());

        int low = 1;
        int high = position[n-1] - position[0];
        int res = -1;

        while(low <= high) {
            int guess = (low + high) / 2;

            if(fun(position, n, guess, m)) {
                res = guess;
                low = guess + 1;
            }
            else {
                high = guess - 1;
            }
        }

        return res;
    }
};
