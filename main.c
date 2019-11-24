/**

A program that compares sorting algorithms performance.

@author: Hidir Yuzuguzel

*/

#include<stdio.h>

#include<stdlib.h>

#include<time.h>

#include<math.h>

 /**maximum size of integer array*/

#define SIZE 100000

 /**number of elements between 0 and 99*/

#define MAX 100

 /**

 function which swaps two integers.

 @param *a first number

 @param *b second number

 */

 void swap(int *a,int *b){

    int temp;

    temp=*a;

    *a=*b;

    *b=temp;

    

} 

 /**

 function which sorts the array in an ascending 

 order through selectionsort algorithm.

 @param arr  input integer array

 @param size size of input array

 */

 void selectionSort(int arr[],int size){

    int i,j;

    for(i=0;i<size;i++){

        for(j=i+1;j<size;j++){

            if(arr[j]<arr[i]){

                swap(&arr[j],&arr[i]);

            }

        }

    }

    

} 

 /**

 function which controls whether the input array

 is sorted or not.

 @param arr input integer array

 @param size size of input array

 @return 1 if the input array is initially sorted

 @return 0 if the input array is not initially sorted

 */

 int isSorted(int arr[],int size){ 

    int i,j;

    for(i=0;i<size;i++){

        for(j=i+1;j<size;j++){

            if(arr[i]>arr[j]){

                return 0;

                

            }

        }

    }

    return 1;

}  

 /**

 function which prints the array

 @param arr integer array

 @param size size of array

 */

 void printArr(int arr[],int size){ 

    int i;

    for(i=0;i<size;i++){

        printf("%d ",arr[i]);

    }

    printf("\n");

} 

 /**

 function which sorts the array in an ascending 

 order through bucketsort algorithm.

 @param arr  input integer array

 @param size size of input array

 */

 

 void bucketSort(int arr[],int size){

    //assign bucket of size MAX to 0 initially:

    int bucket[MAX]={0},i,j,k=0;

    /**

    counting the frequency of every item in the 

    input array via incrementing indexes

    */

    for(i=0;i<size;i++){

        bucket[arr[i]]++;

    }

    //extracting the bucket array onto output array: 

    for(i=0;i<MAX;i++){

        for(j=0;j<bucket[i];j++){

            arr[k++]=i;

        }

    }



     

}  

 /**

 Main function.Reads the input array with its size and choice

 of algorithm from the user.According to choice,namely 1 for 

 selectionsort and 2 for bucketsort, the programs implements

 sorting algorithms.

 */

int main(){ 

     int arr[SIZE],size,i,choice;

     // read the size and check whether it is valid:

     printf("Enter size of the array:\n");

     scanf("%d",&size);

     if(size<=0 || size>SIZE){

         printf("Error: size must be between 1 and %d inclusive\n",SIZE);

         system("pause");

         return -1;

     }

     // initialize array randomly:

     srand((unsigned) time(NULL));

     printf("Randomly initializing array...\n");

     for(i=0;i<size;i++){

         arr[i]=rand()%MAX;

     }

     printf("array randomly initialized\n");

     /** check whether the array is sorted accidentally at the

      beginning, if so, quit*/

     if(isSorted(arr,size)){

         printf("Error: initial array seems sorted (it must not be!), quitting..\n");

         system("pause");

         return -2;

     }

     // if the size of the array is less than or equal to 100, print it:

     if(size<=100){

         printArr(arr,size);

     }

     // ask the user for sorting choice

     printf("Enter your sorting choice:\n");

     printf("1 selection sort\n");

     printf("2 bucket sort\n");

     scanf("%d",&choice);

     printf("sorting array, start your timer!\n");

 

     /** apply appropriate sorting algorithm based on

      user's choice*/

     if(choice==1){

         selectionSort(arr,size);

     }

     else if(choice==2){

         bucketSort(arr,size);

     }

     else{

         printf("Error: invalid choice, quitting..\n");

         system("pause");

         return -3;

     }

     printf("Sorting ended, end your timer and report duration!\n");

     // check whether the sorting algorithm worked:

     if(isSorted(arr,size)){

         printf("Array is successfully sorted\n");

     }

     else{

         printf("Error: sorting algorithm failed!\n");

         system("pause");

         return -4;

     }

     // print the sorted array if size is less than or equal to 100

     if(size<=100){

         printArr(arr,size);

     }

 

     system("pause");

     return 0;

}

 /*

 Sorting algorithms performance comparison:

     array size   selectionSort    bucketSort 

     100           ~0                ~0

     1000          ~0                ~0

     10000         0.4 s             ~0

     25000         1.71 s            ~0

     50000         6.53 s            ~0

     100000        24.75 s           ~0

 */

 
