class FoodRatings {
public:

    unordered_map<string, int> dict;
    unordered_map<string, map<int, set<string>>> rank;

    vector<int>& m_ratings;
    vector<string>& m_cuisines;

    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings)
        : m_ratings(ratings),
        m_cuisines(cuisines)
    {
        int n = foods.size();
        for (int i = 0; i < n; i++)
        {
            dict[foods[i]] = i;
            rank[cuisines[i]][ratings[i]].insert(foods[i]);
        }
    }
    
    void changeRating(string food, int newRating) {
        int idx = dict[food];

        if (m_ratings[idx] == newRating)
            return;

        rank[m_cuisines[idx]][m_ratings[idx]].erase(food);
        
        if (rank[m_cuisines[idx]][m_ratings[idx]].empty())
            rank[m_cuisines[idx]].erase(m_ratings[idx]);

        rank[m_cuisines[idx]][newRating].insert(food);
        m_ratings[idx] = newRating;
    }
    
    string highestRated(string cuisine) {
        return *rank[cuisine].rbegin()->second.begin();
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */
