class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        
        priority_queue<int> pq;
        for(auto a : stones)
            pq.push(a);
        
        while(pq.size() >= 2) {
            int x = pq.top();
            pq.pop();
            int y = pq.top();
            pq.pop();
            if(x != y)
                pq.push(abs(y - x));
        }
        
        return (!pq.empty() ? pq.top() : 0);
    }
};