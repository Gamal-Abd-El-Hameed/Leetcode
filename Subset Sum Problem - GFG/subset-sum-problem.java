//{ Driver Code Starts
import java.io.*;
import java.util.*;

class GFG
{
    public static void main(String args[])throws IOException
    {
        BufferedReader read = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(read.readLine());
        while(t-- > 0)
        {
            int N = Integer.parseInt(read.readLine());
            String input_line[] = read.readLine().trim().split("\\s+");
            int arr[]= new int[N];
            for(int i = 0; i < N; i++)
                arr[i] = Integer.parseInt(input_line[i]);
            int sum = Integer.parseInt(read.readLine());

            Solution ob = new Solution();
            if(ob.isSubsetSum(N, arr, sum))
            System.out.println(1);
            else
            System.out.println(0);

            
        }
    }
}

// } Driver Code Ends


//User function Template for Java

class Solution{
    static Boolean isSubsetSum(int n, int arr[], int S){
        boolean[][] dp = new boolean[S + 1][n + 1];
        for (int i = 0; i <= n; i++)
            dp[0][i] = true;
        for (int i = 1; i <= S; i++)
            dp[i][0] = false;
        for (int sum = 1; sum <= S; sum++) {
            for (int j = 1; j <= n; j++) {
                dp[sum][j] = dp[sum][j - 1];
                if (sum >= arr[j - 1])
                    dp[sum][j] = dp[sum][j] || dp[sum - arr[j - 1]][j - 1];
            }
        }
        return dp[S][n];
    
    }
}