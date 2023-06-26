class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        //stores sorted elements from start index of the costs
        priority_queue<int, vector<int> , greater<int>> pq1;
        //stores sorted elements from the end index of the costs
        priority_queue<int, vector<int> , greater<int>> pq2;

        //2 pointers
        int i=0;                    //start
        int j= costs.size() - 1;    //end

        long long amount = 0;   // total minimum cost

        while(k--){

            //insert the candidates from start of the costs in pq1
            while(i <= j && pq1.size() < candidates){
                pq1.push(costs[i++]);
            }

            //inserting the candidates from the last part of costs in pq2
            while(i <= j && pq2.size() < candidates){
                pq2.push(costs[j--]);
            }

            //get the top element from both the heaps for comparision 
            long long top1 = LLONG_MAX;
            long long top2 = LLONG_MAX;

            //add a condition to check if the heap is empty
            if(!pq1.empty()){
                top1 = pq1.top();
            }

            if(!pq2.empty()){
                top2 = pq2.top();
            }

            //compare top 1 and top 2

            //if values are same we use the element with lower index, 
            //and since the pq1 stores elements from start , 
            //its index will always be lower, thus we use top 1

            if(top1 <= top2){  
 
                amount += top1;
                pq1.pop();
                //insert the next element
                if(i <= j){
                    pq1.push(costs[i++]);
                }

            }
            else{

                amount+= top2;
                pq2.pop();

                // insert next element from the last of the array in pq2
                if(i<=j){
                    pq2.push(costs[j--]);
                }
            }


        }

        return amount;
    }
};
