int maxProfit(int* prices, int pricesSize) {
    
    if (!prices || pricesSize == 0)
    return 0;
    
    int min = prices[0];
    int max = prices[0];
    int maxProfit = 0;
    
    for (int i = 1; i < pricesSize; i++)
    {
        if (prices[i] < min)
        {
            min = prices[i];
            
            // Reset the window where we can sell this stock
            max = min;
        }
        else if (prices[i] > max)
                max = prices[i];
        
        if (max - min > maxProfit)
        maxProfit = max - min;
    }
    return maxProfit;
}
