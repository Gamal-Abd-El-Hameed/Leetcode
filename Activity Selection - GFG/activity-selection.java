//{ Driver Code Starts
import java.io.*; 
import java.util.*; 
import java.lang.*;

class Main
{
    public static void main (String[] args) throws IOException  
    {
        
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		//testcases
		int t = Integer.parseInt(br.readLine().trim());
		
		while(t-- > 0)
		{
		    String inputLine[] = br.readLine().trim().split(" ");
		    //size of array
		    int n = Integer.parseInt(inputLine[0]);
		    int start[] = new int[n];
		    int end[] = new int[n];
		    
		    //adding elements to arrays start and end
		    inputLine = br.readLine().trim().split(" ");
		    for(int i = 0; i < n; i++)
		     start[i] = Integer.parseInt(inputLine[i]);
		    
		    inputLine = br.readLine().trim().split(" ");
		    for(int i= 0; i < n; i++)
		      end[i] = Integer.parseInt(inputLine[i]);
		    
		    //function call
		    System.out.println(new Solution().activitySelection(start, end, n));
		}
    }
}


// } Driver Code Ends


class Solution
{
    static class Activity {
    private int start;
    private int finish;

    public int getStart() {
        return start;
    }

    public Activity(int start, int finish) {
        this.start = start;
        this.finish = finish;
    }

    public int getFinish() {
        return finish;
    }
}

    public static int activitySelection(int start[], int end[], int n)
    {
        Activity[] A = new Activity[n];
        for (int i = 0; i < n; ++i)
            A[i] = new Activity(start[i], end[i]);
        return solve(A);
    }
    
    public static int solve(Activity[] A) {
        Arrays.sort(A, Comparator.comparingInt(Activity::getFinish));
        int n = A.length, weight, idx;
        int[] DP = new int[n];
        DP[0] = 1;
        for (int i = 1; i < n; ++i) {
            idx = binarySearch(A, i);
            weight = 1;
            if (idx != -1)
                weight += DP[idx];
            DP[i] = Math.max(weight, DP[i - 1]);
        }
        return DP[n - 1];
    }

    private static int binarySearch(Activity[] A, int targetIndex) {
        int low = 0, high = targetIndex - 1, mid;
        while (low <= high) {
            mid = (low + high) >> 1;
            if (noOverlapBetween(A[mid].getFinish(), A[targetIndex].getStart())) {
                if (A[mid + 1].getFinish() < A[targetIndex].getStart())
                    low = mid + 1;
                else
                    return mid;
            }
            else
                high = mid - 1;
        }
        return -1;
    }
    
    private static boolean noOverlapBetween(int first, int second) {
        return first < second;
    }
}