class Solution {
public:
    // IDEA: Interleave characters from z-a so that no character is repeated more
    //       than L times
    string repeatLimitedString(const string& s, int L) {
      // Get the total number of each character	
      array<int, 26> freq; freq.fill(0);
      for (char c : s) freq[c-'a']++;
      
      // Order the characters that occur from z-a in a stack	  
      vector<char> st; st.reserve(26);
      for (int i = 0; i < 26; i++) {
        if (freq[i]) {
          st.emplace_back(i);
        }
      }
      
      string res; res.reserve(size(s));
	  
      // while there are characters to add, take from the stack and add as many of that character as we can	  
      while (!st.empty()) {
        auto ch = st.back(); st.pop_back();
        int nchars = min(freq[ch], L);
        
        // Add in as many of ch as possible		
        freq[ch] -= nchars;
        res.append(nchars, ch + 'a');
        
        // If there are any leftover, we need to use the next largest character
        // this time only add one		
        if (freq[ch] > 0 && !st.empty()) {
          auto nextCh = st.back(); st.pop_back();
          
          res.push_back(nextCh + 'a');
		  
		  // If there are leftovers, we need to re-add nextCh to the stack before ch
          if (--freq[nextCh])
            st.emplace_back(nextCh);
          
          // Re-add ch to the stack as there are still leftovers (ch will be at the top again)		  
          st.emplace_back(ch);
        }
      }
      
      return res;
    }
};
