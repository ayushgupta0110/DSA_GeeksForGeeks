#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//Complete this function

class Solution
{
    public:
    //Function to find the minimum number of coins to make the change 
    //for value using the coins of given denominations.
    long long minimumNumberOfCoins(int coins[], int numberOfCoins, int value)
    {
        int table[value+1];
 
        table[0] = 0;

        for (int i=1; i<=value; i++)
            table[i] = INT_MAX;

        for (int i=1; i<=value; i++)
        {
            for (int j=0; j<numberOfCoins; j++)
              if (coins[j] <= i)
              {
                  int sub_res = table[i-coins[j]];
                  if (sub_res != INT_MAX && sub_res+1 < table[i])
                      table[i] = sub_res + 1;
              }
        }
       
          if(table[value]==INT_MAX)
            return -1;
       
        return table[value];
    }
};

// { Driver Code Starts.



int main() {
	
	//taking total count of testcases
	int testcases;
	cin>>testcases;
	while(testcases--)
	{
	    //taking value
	    int value;
	    cin>>value;
	    
	    //taking number of coins
	    int numberOfCoins;
	    cin>>numberOfCoins;
	    int coins[numberOfCoins];
	    
	    //taking value of each coin
	    for(int i=0;i<numberOfCoins;i++)
	    cin>>coins[i];
	    Solution obj;
	    //calling function minimumNumberOfCoins()
	    int answer=obj.minimumNumberOfCoins(coins,numberOfCoins,value);
	    
	    //printing "Not Possible" if answer is -1
	    //else printing answer
	    if(answer==-1)
	    cout<<"Not Possible"<<endl;
	    else
	    cout<<answer<<endl;
	    
	}
	return 0;
}
