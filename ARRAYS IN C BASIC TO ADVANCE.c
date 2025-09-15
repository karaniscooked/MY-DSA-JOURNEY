ARRAYS PROBLEMS BASICS TO ADVANCE IN C
Q1 .print the sum of all the elements of the array
#include <stdio.h>
int main()
{
    int n = 10;
    int arr[10] = {1,2,3,4,5,6,7,8,9,10};           ----------------- Learning -----------------
    int sum = 0;                                    | 1. Loop traversal se array ke har element |
    for(int i = 0; i<n; i++)                        |    ko access karna seekha.                |
    {                                               |                                            |
        sum = sum + arr[i]; // sum += arr[i];       | 2. Ek variable (sum) bana ke repeatedly   |
    }                                               |    update karne ka logic samjha.          |
    printf("The total sum of the array is %d", sum);|                                           |
    return 0;                                       | 3. sum += arr[i]; shorthand ka matlab     |
}                                                   |    clear hua.                             |
                                                    |                                            |
                                                    | 4. Array ke elements ka total nikalne ke  |
                                                    |     liye basic approach samjha.            |
                                                     --------------------------------------------


2 find the max element in the array

#include <stdio.h>
int main()
{   
    int n = 7;
    int arr[7] = {5,7,3,4,5,8,88};                 ----------------- 📘 Learning -----------------
    int max = arr[0];                              | 🔢 1. Seekha kaise array me **maximum**   |
    for(int i = 0; i<n; i++)                       |       element dhoondte hain.             |
    {                                              |                                           |
        if( arr[i] > max)                          | 🏁 2. max ko hamesha **arr[0]** se        |
            max = arr[i];                          |       initialize karna best practice hai.|
    }                                              |                                           |
    printf("the maximum element is %d", max);      | 🔄 3. Har element se compare karke        |
    return 0;                                      |       **bada value update** karna seekha.|
}                                                  |                                           |
                                                   | ✅ 4. if-condition ka use aur logic clear |
                                                   |       hua for comparison & update.       |
                                                   ---------------------------------------------


3 .find the second greatest element in the array

#include <stdio.h>
#include <limits.h>
int main()
{
    int max = INT_MIN;
    int secondMax = INT_MIN;
    int n = 7;
    int arr[] = {78, 98, 5, 6, 746, 894, 455};      ----------------- 📘 Learning -----------------
                                                    | 🔝 1. **INT_MIN** use karna sikha for     |
    for(int i = 0; i<n; i++)                        |       safe initialization (sabse chhoti  |
    {                                               |       possible value).                   |
        if (arr[i] > max)                           |                                           |
            max = arr[i];                           | 🥇 2. Pehle loop se **maximum element**   |
    }                                               |       nikalna clear hua.                 |
    printf("the max element is %d", max);           |                                           |
                                                    | 🥈 3. Second loop me **max ko skip karke**|
    for(int j = 0; j<n; j++)                        |       dusra sabse bada element mila.     |
    {                                               |                                           |
        if(arr[j] != max && arr[j] > secondMax)     | 🔄 4. Comparison aur update ka logic     |
        {                                           |       aur strong hua.                    |
            secondMax = arr[j];                     |                                           |
        }                                           | ✅ 5. Ab pata chala kaise ek hi pass me   |
    }                                               |       max nikale aur fir second max.     |
    printf("\nthe second max element is: %d",       ----------------------------------------------
           secondMax);
  return 0;
}


Question 4 find the secondmax element in the array
#include <stdio.h>
#include <limits.h>
int main()
{
    int max = INT_MIN;
    int secondMax = INT_MIN;
    int maxIndx = -1, secondmaxIndx = -1;
    int arr[] = {123,45,5,3445,768,564,355,978};
    int n = sizeof(arr)/sizeof(arr[0]);

    for(int i=0; i<n; i++)
    {
        if(arr[i] > max)  // agar new max milta hai
        {
            secondMax = max;             // purana max ab second max ban jayega
            secondmaxIndx = maxIndx;     // uska index bhi update
            max = arr[i];                // new max set
            maxIndx = i;                 // aur uska index
        }
        else if(arr[i] > secondMax && arr[i] != max) // agar value max se chhoti hai 
        {
            secondMax = arr[i];          // update second max
            secondmaxIndx = i;           // aur uska index
        }
    }

    printf("The MAX element is %d and its index is %d", max, maxIndx);
    printf("\nThe SECOND MAX element is %d and its index is %d", secondMax, secondmaxIndx);

    return 0;
}                                               ----------------- 📘 Learning -----------------
                                                | 🔢 Problem: Ek hi loop me find karna hai   |
                                                |     1. Maximum element 🥇                 |
                                                |     2. Second Maximum element 🥈          |
                                                |     3. Unke index positions 📍            |
                                                |                                            |
                                                | 💡 Logic:                                 |
                                                | 1. max ko sabse chhoti value (INT_MIN) se |
                                                |    initialize kiya, taaki koi bhi value   |
                                                |    usse bada ho sake.                     |
                                                |                                            |
                                                | 2. Har element ke liye:                   |
                                                |    👉 Agar wo current max se bada hai →   |
                                                |       - Purana max second max ban gaya.   |
                                                |       - Indexes bhi accordingly shift hue.|
                                                |       - New element max ban gaya.         |
                                                |                                            |
                                                |    👉 Agar wo max se chhota hai lekin     |
                                                |       secondMax se bada hai →             |
                                                |       - Directly secondMax update kiya.   |
                                                |                                            |
                                                | 🏁 Result: Loop khatam hote hi dono        |
                                                |    values aur unke indexes mil jaate hain.|
                                                |                                            |
                                                | ✅ Efficiency: O(n) time, O(1) space.     |
                                                ----------------------------------------------


--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
Q7: Ek C program likho jo ek array ke pehle r elements ko reverse kare, jabki baaki array as it is rahe.

User se array ka size, elements, aur r ka value input lena hai.

Output me updated array print karna hai.

Example:

Input:  
Size = 7  
Array = 1 2 3 4 5 6 7  
r = 4

Output:  
4 3 2 1 5 6 7

#include<stdio.h>
void reverseArray(int arr[],int n,int r)
{
    int start = 0 ;
    int end = r-1;
    int temp;
    while(start<end)
    {
        temp=arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}
int main()
{
    int arr[100];
    int n;
    int r;
    printf("enter the size of the array:");
    scanf("%d",&n);
    printf("enter the %d elements of the array:\n",n);
    for(int i=0; i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("the index upto which you want to reverse the array:");
    scanf("%d",&r);
    reverseArray(arr,n,r);
    printf("\n the reversed array is:");
       for(int i=0; i<n;i++)
    {
        printf("%d",arr[i]);
    }
    return 0;
}



 ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------   
// 8 . finding the odd and even no using a function
#include <stdio.h>
void SeperateevenOdd(int arr[], int n)
{
    printf("\neven numbers:\n");
   for(int i =0; i<=n; i++) 
   {
        if(arr[i] % 2 == 0)
        printf("%d",arr[i]);
       
    }
      printf("\nODD numbers:\n");
   for(int i =0; i<=n; i++) 
   {
        if(arr[i] % 2 != 0)
        printf("%d",arr[i]);
        
    }
    printf("\n");
}

int main()
{
    int arr[50];
    int n;
    printf("enter the size of the arrays:\n");
    scanf("%d",&n);
    printf("enter the elements of the arrays:\n");
    for(int i = 0; i<n; i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("the numbers are");
   SeperateevenOdd(arr, n) ;
   return 0;
    
}
-----------------------------------------------------------------------------------------------------------------------------------------------------------------------
// 9 odd and even no without function
#include <stdio.h>
int main()
{
    int arr[50];
    int n;
    int evencount = 0;
    int oddcount =0;
    printf("enter the size of the arrays:\n");
    scanf("%d",&n);
    printf("enter %d element in the arrays\n");
    for(int i=0; i<n; i++)
    {
        scanf("%d",&arr[i]);
    }
    for(int i=0; i<n; i++)
    {
        if(arr[i]%2==0)
        {
            printf(" %d",arr[i]);
            evencount++;
        }
        else{
           printf(" %d",arr[i]);
            oddcount++;
        }
        
    }
    printf("\nthe no even count are %d:",evencount);
    printf("\nthe no of odd numbers are:%d",oddcount);
    return 0;
}

----------------------------------------------------------------------------------------------------------------------------------------------------
/* 10. SORT AN ARRAY IN DESCENDING ORDER (BUBBLE SORT) */
#include <stdio.h>

void bubbleSortDescending(int arr[], int n) {   ----------------- 📘 Learning -----------------
    int i, j, temp;                             | 🔎 Problem:                                    |
                                                | Array ke elements ko descending order me sort  |
    for (i = 0; i < n - 1; i++) {               | karna hai (bada → chhota).                     |
        for (j = 0; j < n - 1 - i; j++) {       |                                                 |
            if (arr[j] < arr[j + 1]) {          | 💡 Sorting Technique:                           |
                temp = arr[j];                  | Bubble Sort (adjacent elements swap).          |
                arr[j] = arr[j + 1];            |                                                 |
                arr[j + 1] = temp;              | ⚙️ Main Logic:                                  |
            }                                   | Agar arr[j] < arr[j+1] ho toh dono ko swap.    |
        }                                       |                                                 |
    }                                           | 🌀 Working:                                     |
}                                               | - Outer loop har pass ke baad ek element fix.  |
                                                | - Inner loop me adjacents compare hote hain.   |
int main() {                                    | - n-1-i: last wale already sorted, skip karo.  |
    int arr[] = {5, 2, 9, 1, 7};                |                                                 |
    int n = sizeof(arr) / sizeof(arr[0]);       | ✅ Why Swap Needed?                             |
                                                | Descending me bada left me hona chahiye,       |
    bubbleSortDescending(arr, n);               | chhota agar left me hai toh swap karna zaroori.|
                                                |                                                 |
    printf("Sorted Array (Descending): ");      | 📊 Example Dry Run:                             |
    for (int i = 0; i < n; i++) {               | Input: 5 2 9 1 7                                |
        printf("%d ", arr[i]);                  | Pass 1 → 9 5 2 7 1                             |
    }                                           | Pass 2 → 9 7 5 2 1 (sorted ✅)                 |
                                                |                                                 |
    return 0;                                   | ⏱️ Time Complexity:                             |
}                                               | Worst: O(n²), Best: O(n) (with optimization).  |
                                                |                                                 |
                                                | ⚠️ Common Mistake:                              |
                                                | Agar condition `>` likh diya toh ascending ho   |
                                                | jaayega instead of descending.                 |
                                                ---------------------------------------------------
---------------------------------------------------------------------------------------------------------------------------------------------------------------------------


question 11 make a slot array 
    /* 11. INITIALIZE SLOT ARRAY FOR JOB SCHEDULING */
#include <stdio.h>

int main() {                                    ----------------- 📘 Learning -----------------
    int maxDeadline = 4;                        | 🔎 Problem:                                    |
    int slot[10];                               | Jobs ko schedule karne ke liye time slots banane|
                                                | hain. Har slot ek "din" ya "unit time" ko       |
    // sab slots ko -1 se initialize            | represent karta hai.                            |
    for (int i = 1; i <= maxDeadline; i++) {    |                                                 |
        slot[i] = -1;                           | 💡 Concept:                                     |
    }                                           | 1. Max deadline nikal ke utne slots banate hain.|
                                                | 2. -1 ka matlab: slot abhi khaali hai.          |
    printf("Slots after initialization:\n");   |                                                 |
    for (int i = 1; i <= maxDeadline; i++) {    | ⚙️ Main Logic:                                  |
        printf("Slot[%d] = %d\n", i, slot[i]);  | Har slot ko initially -1 set karo (empty).      |
    }                                           | Jab koi job allocate hoga tab replace karenge.  |
                                                |                                                 |
    return 0;                                   | 🌀 Working:                                     |
}                                               | - Suppose maxDeadline = 4                       |
                                                | - Slot array banega: Slot[1..4]                 |
                                                | - Initialization ke baad: {-1, -1, -1, -1}      |
                                                |                                                 |
                                                | 📊 Example Output:                              |
                                                | Slot[1] = -1                                    |
                                                | Slot[2] = -1                                    |
                                                | Slot[3] = -1                                    |
                                                | Slot[4] = -1                                    |
                                                |                                                 |
                                                | ✅ Why -1?                                       |
                                                | Taaki hume clearly dikhe kaunse slots khaali    |
                                                | hain. 0 ya koi aur value confuse kar sakti hai. |
                                                |                                                 |
                                                | ⚠️ Common Mistake:                              |
                                                | - Agar slot array ka size maxDeadline se chhota |
                                                | diya toh error ayega.                           |
                                                | - Loop ko 0 se start karne ki zaroorat nahi hai.|
                                                ---------------------------------------------------









Q 12 leetcode Two sum problem
    
#include <stdio.h>
void twoSum(int arr[],int target,int n)
{
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(arr[i]+arr[j]==target)
            {
             printf("[%d,%d]",i,j); 
             return;
            }
        }
    }
    printf("[no such subsets exist]");
}

int main(){
    int arr[] = { 2,7,11,15};
    int n = sizeof(arr)/sizeof(arr[0]);
    int target;
    printf("Enter the target:\n");
    scanf("%d",&target);
    printf("the required subset is:\n");
    twoSum(arr,target,n);

    return 0;
}
