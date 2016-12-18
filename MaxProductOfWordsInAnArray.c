int maxProduct(char** words, int wordsSize) {
    
    char * str1, *str2;
    int maxProd = 0;
    unsigned long long * charFound;
    
    if (!words || wordsSize == 0 || wordsSize == 0)
    return 0;
    
    charFound = (unsigned long long *)malloc(sizeof(unsigned long long) * wordsSize);
    memset((void *)charFound, 0, sizeof(unsigned long long) * wordsSize);
    
    // Create bitvector for all strings
    for (int i = 0; i < wordsSize; i++)
    {
        str1 = words[i];
        while(*str1 != '\0')
        {
            charFound[i] |= (1 << *str1);
            str1++;
        }
    }
    
    // walk thru every word and maintain max product if no word is found matching
    for (int i = 0; i < wordsSize; i++)
    {
        for (int k = i+1; k < wordsSize; k++)
        {
            // Nothing common. Consider it for product calculation
            if ((charFound[i] & charFound[k]) == 0)
            {
                int prod = strlen(words[i]) * strlen(words[k]);
                if (prod > maxProd)
                {
                    maxProd = prod;
                }
            }
        }
    }
    
    return maxProd;
}
