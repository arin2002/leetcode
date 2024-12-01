class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        set<int>st;
for( int i = 0 ; i< arr.size() ; i++){
    if( (arr[i]%2 == 0)  && (st.find(arr[i] / 2) != st.end())){
        cout << arr[i];
        return true;
    }

    else if(st.find(arr[i]*2) != st.end()){
        return true;
    }

    st.insert(arr[i]);
}

return false;
    }
};
