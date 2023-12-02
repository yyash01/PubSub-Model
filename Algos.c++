class Solution {
private:
    int ceilDivide(int x,int y){
        return x%y==0 ? x/y : (x/y)+1;
    }

    bool check(int x,vector<int>& piles,int h)
    {
        int cntHrs=0;

        // here koko can eat (x) bananas from a pile per hour

        for(auto &num : piles)
        {
            cntHrs += ceilDivide(num,x);
        }
        return cntHrs<=h;
    }

public:
    int minEatingSpeed(vector<int>& piles, int h) {

        int ans=-1;
        int low = 1; // the minimum limit per hour for koko is 1 since speed=0 doesn't make sense.
        int high= *max_element(piles.begin(),piles.end());

        while(low<=high)
        {
            int mid = low + (high-low)/2;
            if(check(mid,piles,h))
            {
                ans=mid;
                high=mid-1;
            }
            else
            {
                low= mid+1;
            }
        }

        return ans;

    }
};
