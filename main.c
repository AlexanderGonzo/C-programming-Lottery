#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUMS_TO_READ  6
#define MAX_NUM 56



void printArr(int *a, int len) {
    for (int i = 1; i < len/3; i++) {
        printf("%d ", i);
    }
    printf("\n");
    for (int i = 1; i < len/3; i++)
        printf("%d ", a[i]);
    printf("\n");

}

void sortmyArray(int arr[]){
    int temp,i,j = 0;

    for(i=0;i< MAX_NUM;i++)
    {
        for(j=i+1;j< MAX_NUM;j++)
        {
            if(arr[i]< arr[j])
            {
                temp    =arr[i];
                arr[i]  =arr[j];
                arr[j]  =temp;
            }
        }
    }
    printArr(arr,MAX_NUM);
}
void menu(){
    printf("This Program is Written by Alexander and Andrew Gonzalez\n");
    printf("The function of this program is to find the frequency\n"
           "of each number that has been drawn in the Texas lotto game.\n"
           "The program :\n");
    printf("   1. Calculates and displays the frequency of drawn numbers\n"
           "       in Texas Lotto in each year.");
    printf("   2. Calculates and displays the overall frequency of each\n"
           "       number that has been drawn since the lotto started.");
    printf("   3. Sorts the frequency numbers in Descending order. Display\n"
           "      the sorted list.");
    printf("   4. Display total number of integers in the entire file. \n");
}

int main() {
    FILE *fp;
    fp = freopen("lottofile.txt", "r", stdin);


    int currentarr[MAX_NUM + 1]= {0};
    int overallarr[MAX_NUM + 1]= {0};
    int year;
    int temp;
    int digitCOUNTER=0;
    int tempYear = -1;
    //printf("%s","Year ->  No\t 1\t2\t3\t4\t5\t6\t7\t8\t9\t10\n");
    printf("|");
    printf("\n");
    while (!feof(fp)){


        fscanf(fp,"%d", &year);
        digitCOUNTER++;

        if(tempYear == -1)
        {
            memset(currentarr, 0, sizeof(currentarr));

        }else if (year != tempYear ){
            printf("%d\t", tempYear);

            printArr(currentarr,MAX_NUM);
            memset(currentarr, 0, sizeof(currentarr));

        }

        for (int i = 0; i < NUMS_TO_READ; i++) {
            scanf("%d", &temp);
            digitCOUNTER++;
            //printf("%d ", temp);
            currentarr[temp]++;
            overallarr[temp]++;
        }


        tempYear = year;
    }


    printf("%d\t", tempYear);
    printArr(currentarr, MAX_NUM);
    printf("\n");
    printf("Over All The Data , The Frequency of drawn numbers in the \n");
    printf("Texas Lotto are     :-\n");
   // printf("%s","No -->     \t1\t2\t3\t4\t5\t6\t7\t8\t9\t10\n");
    printf("|\n");
    printf("Frequency");
    printArr(overallarr,MAX_NUM);
    printf("\n");

    printf("The MOST frequent Numbers Drawn in the Texas LOTTO Game from \n");
    printf("Highest to Lowest \n");
    sortmyArray(overallarr);
    printf("\n");
    printf("%s %d", "Total number of integers read : ", digitCOUNTER);
    printf("\n");

    //printArr(currentarr, MAX_NUM);
    return 0;

}
