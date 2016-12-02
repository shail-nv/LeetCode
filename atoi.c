void removeUnwantedChars(char * str)
{
    int i = 0, j = 0;
    
    // walk thru he string ktill end and ignore characters you which you don't want
    while (str[i] != '\0')
    {
        if (str[i] == ' ')
        {
            // We found unwanted chars, skip them
            ++i;
            continue;
        }
        else
          str[j++] = str[i++];
    }
    
    // Add null in last character
    str[j] = '\0';
}

int myAtoi(char* str) {
    
    char * numStart;
    unsigned long long res = 0;
    int sign = 1;
    
    if (!str)
        return 0;
    
    //removeUnwantedChars(str);
    
    // Find first non space char
    while(*str == ' ')
        str++;
    
    // Now take first character out as sign and convert rest to integer while taking care of overflow
    if (*str == '-')
        sign = -1;
        
    //  Convert string to a string of numbers
    numStart = sign == -1 ? str++ : str;
    
    while(*numStart != '\0')
    {
        if (*numStart < '0' || *numStart > '9')
            break;
            
        res = res*10 + (*numStart - '0');
        if (res > INT_MAX)
            return 0;
        numStart++;
    }
    
    return res * sign;
}
