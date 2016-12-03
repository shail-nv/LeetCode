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
    while(*str == ' ' && *str != '\0')
        str++;
    
    // Now take first character out as sign and convert rest to integer while taking care of overflow
    if (*str == '-')
    {
        sign = -1;
        str++;
    }
    else if (*str == '+')
    {
        sign = 1;
        str++;
    }
        
    while(*str != '\0')
    {
        if (*str < '0' || *str > '9')
            break;
            
        res = res*10 + (*str - '0');
        if (res > INT_MAX)
            return sign == -1 ? INT_MIN : INT_MAX;
        
        str++;
    }
    
    return res * sign;
}
