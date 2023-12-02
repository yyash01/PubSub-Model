class Solution {
private:
    int integerDivide(int x,int y){
        return x%y==0 ? x/y : (x/y)+1;
    }

    bool check(int x,vector<int>& piles,int h)
    {
        int cntHrs=0;

        // here koko can eat (x) bananas from a pile per hour

        for(auto &pile : piles)
        {
            cntHrs += integerDivide(pile,x);
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


/*
min value of speed = 1
max value of speed = we have to think about that what would be the sufficient maximum
speed by which koko would eat bananas within (h) hours

it would be equal to 1 pile in one hour
and that 1 pile should be equal to the max of among the given piles

explain a Example now. how max and min works

so now let say koko have speed = x and with this speed he is able to eat all piles within (h) hours

then if speed > x he is able to do the same.
so to find the min value of speed we have to check for speed = x-1 now

and other case is :
if speed = x and koko is not able to eat all the piles within (h) hours
then speed < x he will not be able to do the same
so to find the answer we have to check speed (x+1) now

so we can divide the search space every time according the mid value = using the binary Search
*/
