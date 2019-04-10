#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NON_YEAR_NUMBER  6
#define MAXIMUM 54

void printArr(int *a, int len);
void sortmyArray(int *a);
void printFirst(int *a, int len);
void findIndex(int *a, int *b);
void printSortedArr(int *a, int len);

int main() {

    FILE *fp;
    fp = freopen("lottofile.txt", "r", stdin);
    int currentarr[MAXIMUM + 1]= {0};
    int overallarr[MAXIMUM + 1]= {0};
    int tempArr[MAXIMUM + 1] = {0};
    int year;
    int temp;
    int digitCOUNTER = 0;
    int tempYear = 0;

    /**
     * Used to verify if the file is not empty.
     * If the file is empty the user will see an Error message and the program will close.
     * */

    if(fp == NULL){
        printf("File Not found.\n");
        printf("This Program is Written by Alexander and Andrew Gonzalez\n");
        printf("4-10-2019");
        exit(1);
    }

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


    printf("%s", "For each year, the frequency of drawn numbers in the Texas\n");
    printf("%s", "Lotto are as follows :- \n");
    printf("\n");
    printf("%s","Year ->  No\t 1\t2\t3\t4\t5\t6\t7\t8\t9\t10\n");
    printf("\n");
    printf("|");
    printf("\n");


    /**While the file is not empty the program will run.
      * The Program will read in the year and set it equal to a variable
      * This will also start our digit counter so we can verify the amount of
      * ints read in the file
      * */

    while (!feof(fp)){

        fscanf(fp,"%d", &year);
        digitCOUNTER++;


        /**This if statement verifies that the year has changed, and if so
         * we will set the current year's array equal to zero.
         * */
        if(tempYear == 0)
        {
            memset(currentarr, 0, sizeof(currentarr));

        }else if (year != tempYear ){
            printf("%d\t", tempYear);

            printFirst(currentarr,MAXIMUM);
            printf("\n");
            memset(currentarr, 0, sizeof(currentarr));

        }
        /**This for loop is used to read the numbers from the lottofile and places them
         * into a current Year array and a overall array.
         * The current year array will only hold a count of the numbers for one year
         * The overall array will hold the count for all the numbers present in the lottofile
         * */
        for (int i = 0; i < NON_YEAR_NUMBER; i++) {
            scanf("%d", &temp);
            digitCOUNTER++;
            currentarr[temp]++;
            overallarr[temp]++;
        }


        tempYear = year;
    }


    printf("%d\t", tempYear);
    printFirst(currentarr, MAXIMUM);
    printf("\n");
    printf("Over All The Data , The Frequency of drawn numbers in the \n");
    printf("Texas Lotto are :-\n");
    printf("%s", "No --->");
    printf("\n");
    printf("%s", "|");
    printf("\n");
    printf("\n");

    printf("Frequency: \t");
    printf("\n");
    printf("\n");
    printArr(overallarr,MAXIMUM);
    printf("\n");

    printf("The MOST frequent Numbers Drawn in the Texas LOTTO Game from \n");
    printf("Highest to Lowest \n");
    printf("\n");
    memcpy(tempArr, overallarr, sizeof(overallarr));
    sortmyArray(overallarr);

    findIndex(overallarr, tempArr);
    printSortedArr(tempArr, MAXIMUM);
    printf("\n");
    printf("%s %d", "Total number of integers read : ", digitCOUNTER);
    printf("\n");

    fclose(fp);
    printf("This Program is Written by Alexander and Andrew Gonzalez\n");
    printf("4-10-2019");

    return 0;

}
void printArr(int *a, int len) {

    for (int i = 1; i < 11; i++) {

        printf("%d ", i);
    }

    printf("\n");

    for (int i = 1; i < 11; i++){

        printf("%d ", a[i]);
    }

    printf("\n");

}

void sortmyArray(int *a){

    int temp = 0;
    int i = 0;
    int j = 0;

    for(i=0;i< MAXIMUM;i++)
    {
        for(j=i+1;j< MAXIMUM;j++)
        {
            if(a[i]< a[j])
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
    //printArr(a,MAXIMUM);
}

void printFirst(int *a, int len){

    printf("\t ");

    for (int i = 1; i < 11; i++){

        printf("%d\t", a[i]);

    }

    printf("\n");
}

void findIndex(int *a, int *b) {
    int i;
    int j = 0;

    int tempSortedArray[MAXIMUM] = {0};

    for(i = 1; i < MAXIMUM ; i++){

        if(b[i] == a[i]){

            tempSortedArray[j] = i;
            printf("%d ", i);
        }

    }
    printf("%d \n", i);

}
void printSortedArr(int *a, int len) {

    for (int i = 1; i < 11; i++){

        printf("%d ", a[i]);

    }

    printf("\n");

}