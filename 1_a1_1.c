// #include<stdio.h>


// void  LargestElement(int arr[], int n)
// {
//    int max, max2, max3;
//    max3 = max = max2 = arr[0];
//    for(int i = 0; i < n; i++)
//    {
//       if (arr[i] > max){
//          max3 = max2;
//          max2 = max;
//          max = arr[i];
//       }
//       else if (arr[i] > max2)
//       {
//          max3 = max2;
//          max2 = arr[i];
//       }
//       else if (arr[i] > max3)
//          max3 = arr[i];
//    }
//    printf("3rd largest element is %d: ",max3);
// }
   
// int main()
// {
//     int n;
//     printf("enter the size of the array: ");
//     scanf("%d",&n);
//     int arr[n];
//     printf("enter the elements: ");
//     for(int i=0;i<n;i++)
//     {
//         scanf("%d",& arr[i]);
//     }

//   LargestElement(arr,n);

// return 0;
// }
#include<stdio.h>
int main()
{
   int n;
   printf("Enter the size of the array");
   scanf("%d",&n);
   int arr[n];
   printf("Enter the element");
   for(int i=0;i<n;i++)
   {
      scanf("%d",&arr[i]);
   }
   int max, max2, max3;
   max3 = max = max2 = arr[0];
    for(int i = 0; i < n; i++)
   {
      if (arr[i] > max){
         max3 = max2;
         max2 = max;
         max = arr[i];
      }
      else if (arr[i] > max2)
      {
         max3 = max2;
         max2 = arr[i];
      }
      else if (arr[i] > max3)
         max3 = arr[i];
   }
   printf("3rd largest element is %d: ",max3);
   return 0;
}
