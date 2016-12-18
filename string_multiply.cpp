#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        
        // resultant string can never be greater than sum of both string.
		// create and array if size strlen1 + strlen2 and use that to hold on to
		// temporary result also
		int * resStr;
		int j, i, carry, elemCount, strLen1, strLen2;
		string result;
        
        // Check which one is smaller. Use smaller one to multipy with bigger one
		if (num2.size() > num1.size())
			num1.swap(num2);
        
		strLen1 = num1.size();
		strLen2 = num2.size();

		// Maximum size array which is needed to hold result would be size1 + size2 + 1(for carry)
		resStr = new int[sizeof(int) * (strLen1 + strLen2 + 1)];
		memset(resStr, 0, sizeof(int) * (strLen1 + strLen2 + 1));
        
        // Step -1 - Multiply all elements if num1 with num2[i < length of num1]
        // and save them in this vector. Then every element will be shifted by their
        // index and added and saved back in string
        for (i = strLen2 -1; i >= 0; i--)
        {
            int multiplier = 0;
			carry = 0;
            
			if (!strLen2)
			{
				multiplier = num2.back() - '0';
				num2.pop_back();
			}
            else
                break;
            
            for (j = strLen1 - 1; j >= 0; j--)
            {
                int multiplicand = num1.at(j) - '0';
                int res = carry + (multiplier * multiplicand) + resStr[(strLen1 - 1) - j + i];
				carry = res/10;
				resStr[(strLen1 - 1) - j + i] = res % 10;
            }
            
        }
        
		elemCount = i + j - 1 ;

		if (carry)
		{
			resStr[elemCount] += carry;
			elemCount++;
		}

		// convert integer array to string
		for (i = 0; i < elemCount; i++)
			result.push_back(resStr[i] + '0');

		cout << " Resulting string " << result << endl;

		return result;
    }
};

int main()
{
	string num1{ "123" };
	string num2{ "456" };
	string result;

	Solution mult;
	result =  mult.multiply(num1, num2);
	return 0;
}