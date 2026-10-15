int minEatingSpeed(int* piles, int pilesSize, int h) {
    int left = 1;
    int right = 0;
    
    for (int i = 0; i < pilesSize; i++) {
        if (piles[i] > right) {
            right = piles[i];
        }
    }
    
    int res = right;
    
    while (left <= right) {
        int k = left + (right - left) / 2;
        
        long long total_time = 0; 
        for (int i = 0; i < pilesSize; i++) {
            total_time += (piles[i] + k - 1LL) / k; 
        }
        
        if (total_time <= h) {
            res = k;
            right = k - 1;
        } else {
            left = k + 1;
        }
    }
    
    return res;
}