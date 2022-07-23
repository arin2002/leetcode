class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int n = letters.size();
        int i = 0, j = n-1;
        
        while(i<=j)
        {
            int mid = i + (j-i)/2;
            
            int next = (mid+1)%n;
            
            if(target == letters[mid]){
                if(letters[mid] != letters[next])
                    return letters[next];
                
                i = mid+1;
            }
            
            else if(letters[mid] < target)
                i = mid+1;
            else
                j = mid-1;
            
        }
        
        if(i == n)
        return letters[0];

        return letters[i];
    }
};