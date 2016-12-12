class Solution {
public:
    string multiply(string num1, string num2) {
        
        // create a array of strings whose size should be equal to number of 
        // elements in second string
        vector<string> result;
	   int * strArr;
        int elemCOunt = 0; 
        
        // Check which one is smaller. Use smaller one to multipy with bigger one
        if (num2.size() > num2.size())
        {
            // swap the strings
            string temp = num1;
            num1 = num2;
            num2 = temp;
        }

	    strArr = new(sizeof(int) * num1.size());
          memset(strArr, 0, sizeof(int) * (num1.size() + num2.size() + 1);
        
        // Step -1 - Multiply all elements if num1 with num2[i < lenght of num1]
        // and save them in this vector. Then every element will be shifted by their
        // index and added and saved back in string
        for (int i = 0; i < num1.size(); i++)
        {
            int multiplier = 0, sum = 0, carry = 0;
            string multRes;
            
            if (!num1.empty())
                multiplier= num2.pop_back() - '0';
            else
                break;
            
            for (int j = num1.size() -1; j >= 0; j--)
            {
                int multiplicand = num1.at(j) - '0';
                int res = carry + (multiplier * mutliplicand) + 				          str[j - i] + '0';
			carry = res/10;
			strArr[j - i] = res % 10;
                elemCount++;
            }
            
        }
        
        if (carry)
		 str[sizeof(strArr) - elemCount++] = carry;
        
        // convert array to string
	   while(elemCount)
        {
         	result.push_front(strArr[elemCount--]);
	   }
         result.push_back('\0');

         return result;       
        
    }
};