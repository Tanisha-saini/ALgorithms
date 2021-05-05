#include <iostream>
#include <algorithm>
using namespace std;

struct Job 
{
   int start, end, profit;
};

bool comp(Job job1, Job job2)
{
   return (job1.end < job2.end);
}

int nonConflictJob(Job jobList[], int i) 
{
   for (int j=i-1; j>=0; j--) 
   {
      if (jobList[j].end <= jobList[i-1].start)
         return j;
   }
   return -1;
}

int findMaxProfit(Job jobList[], int n) 
{
   sort(jobList, jobList+n, comp);           //sort jobs based on the ending time

   int *table = new int[n];       //create jon table
   table[0] = jobList[0].profit;

   for (int i=1; i<n; i++) {
      // Find profit including the current job
      int addProfit = jobList[i].profit;
      int l = nonConflictJob(jobList, i);
      if (l != -1)
         addProfit += table[l];
      table[i] = (addProfit>table[i-1])?addProfit:table[i-1];       //find maximum
   }

   int result = table[n-1];
   delete[] table;              
   return result;
}

int main() 
{
  Job jobList[] = 
    {
      {3, 5, 25},
      {1, 2, 50},
      {6, 15, 75},
      {2, 100, 100}
   };
   
   int n = 4;
   cout << "The maximum profit: " << findMaxProfit(jobList, n);
   return 0;
}
