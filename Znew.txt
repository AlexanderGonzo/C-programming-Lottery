#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>



int main(){

    struct dirent *de;  // Pointer for directory entry
    DIR *dr = opendir("."); // opendir() returns a pointer of DIR type.
    FILE *fptrRead, *fptrWrite;
    char content;


    if (dr == NULL)  // opendir returns NULL if couldn't open directory
    {
        printf("Could not open current directory" );
        return 0;
    }

    printf("The content of the current Directory :- \n");
    while ((de = readdir(dr)) != NULL)
        printf("%s\n", de->d_name);


    //Open Zold.c to read
    fptrRead = fopen("Zold.c" , "r");
    fptrWrite = fopen("Znew.txt", "w");

    if(fptrRead == NULL){
        printf("Cannot open file \n");
        exit(0);
    }
    content = fgetc(fptrRead);

    while(content != EOF){
        fputc(content, fptrWrite);
        content = fgetc(fptrRead);
    }


    closedir(dr);
    fclose(fptrRead);
    fclose(fptrWrite);
    return 0;

}