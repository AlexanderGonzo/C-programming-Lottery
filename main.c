#include <stdio.h>

//TODO 1. Calculates and displays the frequency of drawn numbers in Texas Lotto in each year.
// 2. Calculates and displays the overall frequency of each number that has been drawn since the lotto started.
// 3. Sorts the frequency numbers in Descending order.
// 4. Displays total number of integers in the entire file .

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
    menu();
    return 0;
}