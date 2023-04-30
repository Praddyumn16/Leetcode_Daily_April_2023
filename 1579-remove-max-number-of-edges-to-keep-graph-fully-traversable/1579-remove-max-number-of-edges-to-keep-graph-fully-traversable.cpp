class Solution {
public:
    vector<int> parent1 , parent2 , rank1 , rank2;

    int find1(int a) {
        return parent1[a] = (parent1[a] == a ? a : find1(parent1[a]));
    }

    int find2(int a) {
        return parent2[a] = (parent2[a] == a ? a : find2(parent2[a]));
    }

    bool Union1(int a , int b) {
        int parent_a = find1(a) , parent_b = find1(b);
        if(parent_a != parent_b) {
            (rank1[parent_a] < rank1[parent_b]) ? (parent1[parent_a] = parent_b) : (parent1[parent_b] = parent_a);
            rank1[parent_a] += (rank1[parent_a] == rank1[parent_b]);
            return true;
        }
        return false;
    }

    bool Union2(int a , int b) {
        int parent_a = find2(a) , parent_b = find2(b);
        // cout << parent_a << " " << parent_b << endl;
        if(parent_a != parent_b) {
            (rank2[parent_a] < rank2[parent_b]) ? (parent2[parent_a] = parent_b) : (parent2[parent_b] = parent_a);
            rank2[parent_a] += (rank2[parent_a] == rank2[parent_b]);
            return true;
        }
        return false;
    }

    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        
        sort(edges.begin() , edges.end() , [&](auto const& a , auto const& b){
            return a[0] > b[0];
        });

        parent1.resize(n + 1);
        parent2.resize(n + 1);
        rank1.resize(n + 1 , 0);
        rank2.resize(n + 1 , 0);

        for(int i = 1 ; i <= n ; i++)
            parent1[i] = parent2[i] = i;

        int count1 = 1 , count2 = 1 , removed = 0;

        for(auto a : edges) {
            if(a[0] == 3){
                bool temp1 = Union1(a[1] , a[2]) , temp2 = Union2(a[1] , a[2]);
                if(temp1)
                    count1++;
                if(temp2)
                    count2++;
                if(!temp1 && !temp2)
                    removed++;
            }
            else if(a[0] == 1) 
                Union1(a[1] , a[2]) ? count1++ : removed++;
            else
                Union2(a[1] , a[2]) ? count2++ : removed++;
        }

        if(count1 < n || count2 < n)
            return -1;
        
        return removed;
    }
};