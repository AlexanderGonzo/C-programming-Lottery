#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUMS_TO_READ  6
#define MAX_NUM 56


void sortmyArray(int *arr){
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
    //printSortedArr(arr,MAX_NUM);
}
void printArr(int *a, int len) {
    for (int i = 1; i < 11; i++) {
        printf("%d ", i);
    }
    printf("\n");
    for (int i = 1; i < 11; i++)
        printf("%d ", a[i]);
    printf("\n");

}
void printSortedArr(int *a, int len) {
    for (int i = 0; i < 11; i++)
        printf("%d ", a[i]);
    printf("\n");

}
void findIndex(int *a, int *b) {
    int i;
    int tempSortedArray[MAX_NUM] = {0};

    for(i = 0; i < MAX_NUM ; i++){

        if(b[i] == a[i]){
            tempSortedArray[i-1] = i;

            //printf("%d ", i);
        }
    }
    sortmyArray(tempSortedArray);
    printSortedArr(tempSortedArray,MAX_NUM);
}

void printFirst(int *a, int len){
    printf("\t ");
    for (int i = 1; i < 11; i++)
        printf("%d\t", a[i]);
    printf("\n");
}



int main() {

    FILE *fp;
    fp = freopen("lottofile.txt", "r", stdin);

    printf("This Program is Written by Alexander and Andrew Gonzalez\n");
    printf("The function of this program is to find the frequency\n"
           "of each number that has been drawn in the Texas lotto game.\n"
           "The program :\n");
    printf("   1. Calculates and displays the frequency of drawn numbers\n"
           "       in Texas Lotto in each year.\n");
    printf("   2. Calculates and displays the overall frequency of each\n"
           "       number that has been drawn since the lotto started.\n");
    printf("   3. Sorts the frequency numbers in Descending order. Display\n"
           "      the sorted list.\n");
    printf("   4. Display total number of integers in the entire file. \n");
    printf("\n");

    int currentarr[MAX_NUM + 1]= {0};
    int overallarr[MAX_NUM + 1]= {0};
    int tempArr[MAX_NUM + 1] = {0};
    int year;
    int temp;
    int digitCOUNTER=0;
    int tempYear = -1;

    printf("%s", "For each year, the frequency of drawn numbers in the Texas\n");
    printf("%s", "Lotto are as follows :- \n");
    printf("\n");
    printf("%s","Year ->  No\t 1\t2\t3\t4\t5\t6\t7\t8\t9\t10\n");
    printf("\n");
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

            printFirst(currentarr,MAX_NUM);
            printf("\n");
            memset(currentarr, 0, sizeof(currentarr));

        }

        for (int i = 0; i < NUMS_TO_READ; i++) {
            scanf("%d", &temp);
            digitCOUNTER++;
            currentarr[temp]++;
            overallarr[temp]++;
        }


        tempYear = year;
    }


    printf("%d\t", tempYear);
    printFirst(currentarr, MAX_NUM);
    printf("\n");
    printf("Over All The Data , The Frequency of drawn numbers in the \n");
    printf("Texas Lotto are :-\n");
    printf("%s", "No --->");
    printf("%s", "|");
    printf("\n");

    printf("Frequency: ");
    printArr(overallarr,MAX_NUM);
    printf("\n");

    printf("The MOST frequent Numbers Drawn in the Texas LOTTO Game from \n");
    printf("Highest to Lowest \n");


    //Copy overall array into a temp array
    //Sort overall, Then find the number in the temp array returning the index.
    memcpy(tempArr, overallarr, sizeof(overallarr));
    sortmyArray(tempArr);

    findIndex(overallarr,tempArr);
    printSortedArr(tempArr,MAX_NUM);

    printf("\n");
    printf("%s %d", "Total number of integers read : ", digitCOUNTER);
    printf("\n");

    return 0;

}
