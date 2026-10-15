int shipWithinDays(int* weights, int weightsSize, int days) {
    int left = 0;
    int right = 0;
    
    for (int i = 0; i < weightsSize; i++) {
        if (weights[i] > left) {
            left = weights[i];
        }
        right += weights[i];
    }
    
    int res = right;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        int days_needed = 1;
        int current_weight = 0;
        
        for (int i = 0; i < weightsSize; i++) {
            if (current_weight + weights[i] > mid) {
                days_needed++;
                current_weight = 0;
            }
            current_weight += weights[i];
        }
        
        if (days_needed <= days) {
            res = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    
    return res;
}