char* longestPalindrome(char* s) {
    
    char * upper, * lower;
    int maxLength = 1;
    char * maxStrStart = NULL, * result = NULL;
    int length = 0, tempLen = 0;
    
    // lets create 2 pointers to move thru the string from say middle
    if (!s || strlen(s) == 1)
        return s;
    
    length = strlen(s);
    maxStrStart = s;
    
    for (int i = 0; i < length; i++)
    {
        upper = lower = &s[i];
    
        while(*lower==*(lower+1)) lower++;
        
        while(upper > s && lower < (s + length) && *(upper - 1) == *(lower + 1))
        {
            upper--;
            lower++;
        }
        
        // mismtach. Get the string length and see if it's greater than max
        tempLen = (lower-upper)/sizeof(char) + 1;
        if(tempLen > maxLength)
        {
            maxLength = tempLen;
            maxStrStart = upper;
        }
        
    }
    
    // create new string and copy the resultant string in it
    result = malloc(sizeof(char) * maxLength + 1);
    strncpy(result, maxStrStart, maxLength);
    result[maxLength] = '\0';
    
    return result;
}
