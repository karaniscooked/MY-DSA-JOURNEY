// 01 knapsack problem using recursive method 
#include <stdio.h>
#include <limits.h>
// definig the max function 
int max(int a, int b)
{
    return (a>b) ? a:b;
}
//code for the knapsack function
int knapsack(int wt[],int val[],int w,int n)
{
    //stating the base condition 
    if(w==0 || n==0){
        return 0;
    }
    if(wt[n-1]<= w)
    {
        return max(val[n-1]+knapsack(wt,val,w-wt[n-1],n-1),knapsack(wt,val,w,n-1));
    }else
    {
        return knapsack(wt,val,w,n-1);
    }
}
int main(){
    int wt[] = { 12,23,4,56,5};
    int val[] = {9,8,7,6,5};
    int w = 12;
    int n =5;
    int result = knapsack(wt,val,w,n);
    printf("the maximum profit is :%d",result);
    return 0;
    
}
