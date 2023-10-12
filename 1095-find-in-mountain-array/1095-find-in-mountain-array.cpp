class Solution {
public:
    int findMaximum(MountainArray &mountainArr, int n) 
    {
	    if(n==1) return 0;
	    int lo=0;
        int hi=n-1;
        
        int peak;
        while(hi-lo>1)
        {
            int mid=lo+(hi-lo)/2;
            if(mountainArr.get(mid)>mountainArr.get(mid-1) and mountainArr.get(mid)>mountainArr.get(mid+1))
            {
                  peak=mid;
                  return peak;
            }
            else if(mountainArr.get(mid)>mountainArr.get(mid-1) and mountainArr.get(mid)<mountainArr.get(mid+1))
            {
                lo=mid+1;
            }
            else
            {
                hi=mid-1;
            }
        }
        return mountainArr.get(hi)>mountainArr.get(lo)?hi:lo;
	}
    int left(int lo,int hi,MountainArray &mountainArr,int target)
    {
        while(hi-lo>1)
        {
            int mid= lo+ (hi-lo)/2;
            if(mountainArr.get(mid)>=target)
            {
                hi=mid;
            }
            else
            {
                lo=mid+1;
            }
        }
        if(mountainArr.get(lo)==target) return lo;
        else if(mountainArr.get(hi)==target) return hi;
        else return -1;
    }
    int right(int lo,int hi,MountainArray &mountainArr,int target)
    {
        while(hi-lo>1)
        {
            int mid= lo+ (hi-lo)/2;
            if(target<=mountainArr.get(mid))
            {
                lo=mid;
            }
            else
            {
                hi=mid-1;
            }
        }
        if(mountainArr.get(lo)==target) return lo;
        else if(mountainArr.get(hi)==target) return hi;
        else return -1;
    }

    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n=mountainArr.length();
        int lo=0;
        int hi=n-1;
        int peakIndex= findMaximum(mountainArr, n) ;
        // cout<<"Peak Index is :"<<peakIndex<<endl;
        int a=left(0,peakIndex,mountainArr,target);
        // cout<<"A is :"<<a<<endl;
        if(a!=-1) return a;
        int b=right(peakIndex,hi,mountainArr,target);
        // cout<<"B is "<<b<<endl;
        if(b!=-1) return b;

        return -1;

    }
};
