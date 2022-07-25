#include <cstdio>
#include <vector>
#include <algorithm>

typedef long long llong;

int main() {

    llong n_tests; 
    scanf("%lld", &n_tests);

    while (n_tests--) {
        llong n_items;
        llong capacity;
        
        scanf("%lld %lld", &n_items, &capacity);

        std::vector<std::pair<llong, llong>> weights(n_items); 
        
        for (llong i = 0; i < n_items; i++) {
            scanf("%lld", &weights[i].first); 
            weights[i].second = i + 1;
        }
        
        sort(weights.begin(), weights.end());
        std::vector<llong> result; 
        llong knapsack(0);
        
        for (llong i = 0; i < n_items; i++) {
            
            llong current_weight = weights[i].first;
            llong position = weights[i].second;
            llong new_value = knapsack + current_weight;
            
            
            if (2 * new_value < capacity) {
                knapsack += current_weight; 
                result.push_back(position);
                
            }
            else if (capacity <= 2 * new_value && new_value <= capacity) {
                knapsack += current_weight; 
                result.push_back(position); 
                break;
                
            }
            else if (current_weight <= capacity) {
                knapsack = current_weight; 
                result = std::vector<llong>(1, position); 
                break;
                
            }
            else { 
                result = std::vector<llong>(0); 
                break;
            }
        }

        if (capacity <= 2 * knapsack && knapsack <= capacity && result.size() > 0) {
            printf("%ld\n", result.size());
            for (llong i = 0; i < result.size(); i++) {
                printf("%lld ", result[i]);
                
            };
            
            puts("");
        }
        else { 
            puts("-1"); 
            
        }
        
    }

    return 0;
}