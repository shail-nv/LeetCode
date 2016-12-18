int removeDuplicates(int nums, int numsSize) {
    int i;
    int j;
    int count = 1;
    
    if (!nums  !numsSize)
    return 0;
    
    if (numsSize == 1)
    return 1;
    
    j = nums;
    i = nums +1;
    for (int elem =1; elem  numsSize; elem++)
    {
        if (i == j)
        {
            i++;
            continue;
        }
        
        j++;
        j = i;
        i++;
        count++;
    }
    
    return count;
}

