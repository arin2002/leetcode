class Solution {
public:
    
    int solve(string s)
    {
         int n=s.size(),ans=0,i=0,j=n-1;
        
         while(i<j)
         {
            if(s[i]!=s[j])
            {
    //Step 1 ->We are fixing the first half and changing 2nd half according to it    
                
                int idx=j;
                while(s[idx]!=s[i])  //j se i ki trf aao aur dekho kaunsa idx s[i] ke equal
                    idx--;
      
    //Step 2 -> special case like "ahbbaaa" here h should come in middle so just swap with its next element and (NO i++,j-- here as process krna baaki hai use to ab "abhbaaa" is string me process kro NO i++ and j--)
                
                if(i==idx) 
                {
                    swap(s[idx],s[idx+1]);
                    ans++;
                    continue;  //IMPORTANT --> No i++ and j-- for special case
                }
                
    //Step 3 -> Agar koi milgya hume s[i] ke equal to use hume jth place tk lana to idx<j jab tk hai tb tk swap marte rho aur ans++ krdo
                
                else
                {
                    while(idx<j)
                    {
                        swap(s[idx],s[idx+1]);
                        idx++; ans++;
                    }
                }
            }
             
            i++;
            j--;    //i aur j position match krwadi ab aage bdo         
         }
        return ans;
    }
    int minMovesToMakePalindrome(string s) {
        
        return solve(s);
    }

};