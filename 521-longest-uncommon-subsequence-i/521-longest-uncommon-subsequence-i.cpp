class Solution {
public:
int findLUSlength(string a, string b)
{
    // Case 1: If strings are equal
    if (!a.compare(b))
        return -1;
 
     // for case 2 and case 3
    return max(a.length(), b.length());
}
};