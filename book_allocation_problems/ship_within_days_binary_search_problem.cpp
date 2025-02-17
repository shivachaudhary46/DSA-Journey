  #include<iostream>
using namespace std;

   // Check if it's possible to ship all packages within 'days' using 'capacity'
    bool checkCapacity(vector<int>& weights, int days, int capacity) {
        int currentCapacity = capacity, daysCount = 1, n = weights.size();
         
        for(int i = 0; i < n; i++) {
            // If current package can fit in the remaining capacity for the current day
            if(currentCapacity >= weights[i]) {
                currentCapacity -= weights[i];
            } else {
                // Move to the next day
                daysCount++;
                // If we exceed the allowed number of days, return false
                if(daysCount > days) {
                    return false;
                }
                // Reset the capacity for the new day
                currentCapacity = capacity - weights[i];
            }
        }
        return true;
    }
    
    // Find the least capacity of ship to ship all packages within 'days'
    int shipWithinDays(vector<int>& weights, int days) {
        int maxWeight = *max_element(weights.begin(), weights.end());
        int totalWeight = accumulate(weights.begin(), weights.end(), 0);
        
        // Binary search boundaries: min capacity is maxWeight, max capacity is totalWeight
        int s = maxWeight, e = totalWeight;
        int minCapacity = s + (e - s) / 2;
        
        // Binary search to find the smallest possible capacity
        while(s <= e) {
            // If this capacity works, search for a smaller valid capacity
            if(checkCapacity(weights, days, minCapacity)) {
                e = minCapacity - 1;
            } 
            // If this capacity doesn't work, search for a larger valid capacity
            else {
                s = minCapacity + 1;
            }
            minCapacity = s + (e - s) / 2;
        }
        
        // The answer is the smallest valid capacity found
        return s;
    }
int main(){
	vector<int> weights;//weights vector array elements is not given
	cout<<shipWithinDays(weights);
}

