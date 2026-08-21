class Solution {
public:
    
    long long gcd(long long a, long long b) {
        while (b != 0) {
            long long temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }
    
    long long count(long long x, vector<int>& coins) {
        int n = coins.size();
        long long total = 0;
        
        // Check every non-empty subset
        for (int mask = 1; mask < (1 << n); mask++) {
            
            long long lcm = 1;
            int bits = 0;
            
            for (int i = 0; i < n; i++) {
                
                if (mask & (1 << i)) {
                    bits++;
                    
                    long long g = gcd(lcm, (long long)coins[i]);
                    
                    // Calculate LCM
                    lcm = (lcm / g) * coins[i];
                    
                    // This subset cannot contribute
                    if (lcm > x)
                        break;
                }
            }
            
            if (lcm > x)
                continue;
            
            long long multiples = x / lcm;
            
            // Inclusion-Exclusion
            if (bits % 2 == 1)
                total += multiples;
            else
                total -= multiples;
        }
        
        return total;
    }
    
    long long findKthSmallest(vector<int>& coins, int k) {
        
        int n = coins.size();
        
        long long low = 1;
        long long high = 1LL * (*min_element(coins.begin(), coins.end())) * k;
        
        long long ans = high;
        
        while (low <= high) {
            
            long long mid = low + (high - low) / 2;
            
            if (count(mid, coins) >= k) {
                ans = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        
        return ans;
    }
};