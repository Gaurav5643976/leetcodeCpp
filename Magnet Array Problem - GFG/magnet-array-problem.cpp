// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
     /*hiLM -> highestIndexofLeftMagnet*/
   double forcesAtDistance(double d, int hiLM, bool leftForces, double magnets[], int n)
   {
       double force=0.0;
       if(leftForces)
       {
           for(int i=0; i<=hiLM; i++)
           {
               force += (1.0/(d-magnets[i]));
           }
       }
       else
       {
           for(int i=hiLM+1; i<n; i++)
           {
               force += (1.0/(magnets[i]-d));
           }
       }
       return force;
   }
       void nullPoints(int n, double magnets[], double getAnswer[])
   {
       // Your code goes here
       double low =0, high = 0, mid = 0;
       for(int i=0; i<n-1; i++)
       {
           low = magnets[i];
           high = magnets[i+1];
           while(low<high)
           {
               mid = (low+high)/2;
               double leftForces = forcesAtDistance(mid, i, 1, magnets, n);
               double rightForces = forcesAtDistance(mid, i, 0, magnets, n);
               /*cout<<"Low:"<<low<<" High:"<<high<<" Distance:"<<mid<<" Leftforces:"<<leftForces<<" RightForces:"<<rightForces<<endl;*/
               if(abs(leftForces - rightForces) < 0.00000000001)
               {
                   getAnswer[i] = mid;
                   break;
               }
               if(leftForces < rightForces)
               {
                   high = mid;
               }
               else /* leftForces > rightForces*/
               {
                   low = mid;
               }
           }
       }
   }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        double magnets[n], getAnswer[n];
        for(int i=0;i<n;i++)
        cin>>magnets[i];
        Solution ob;
        ob.nullPoints(n, magnets, getAnswer);
        
        for(int i=0; i<n-1; i++)
            printf("%0.2lf ",getAnswer[i]);
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends