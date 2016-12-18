int lengthOfLongestSubstring(char* s) {
    
    int * charMap = NULL;
    int begin = 0, end = 0, i = 0, maxLength = 0;
    
    if (!s)
    return 0;
    
    charMap = malloc(sizeof(int) * 256);
    memset(charMap, 0, sizeof(int) * 256);
    
    while(s[i] != '\0')
    {
        if ((charMap[s[i]] == 0))
        {
            charMap[s[i]]++;
        }
        else if (charMap[s[i]] > 0)
        {
            charMap[s[i]]++;
            
            // Found a duplicate char. Move begin till this duplicate char is not taken out
            while(s[begin] != s[i] && begin < i)
            {
                charMap[s[begin++]]--;
            }
            
            charMap[s[begin++]]--;
        }
        
        if (maxLength < (i - begin + 1))
        {
            maxLength = i - begin + 1;
        }
        
        i++;
    }
    
    free(charMap);
    return maxLength;
}
