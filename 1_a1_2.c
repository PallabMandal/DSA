#include<stdio.h>
void reverse(int arr[],int n)
{
    int s=0;
    int e=n-1;
    while(s<=e)
 {
        
  int temp=arr[s];
       arr[s]=arr[e];
       arr[e]=temp;
        s++;
        e--;
 }

}     
 int main()
{
    int n;
    printf("enter the size of the array: ");
    scanf("%d",&n);
    int arr[n];
    printf("enter the elements: ");
    for(int i=0;i<n;i++)
    {
        scanf("%d", &arr[i]);
    }

reverse(arr,n);

printf("Reversed array: ");
    for (int i = 0; i < n; i++) 
    {
        printf("%d", arr[i]);
    }
    return 0;
}