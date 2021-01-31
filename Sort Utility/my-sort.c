#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

//input the text file
int main(__attribute__((unused)) int argc,const char* sam_file[]) {

    FILE * fPointer;
    //maximum number of characters to be occupied
    int max = 500;

    //number of characters in the array
    int size=0;

   // printf("%d %s",argc, argv[1]);
    char c_array[500];

    int i, j;

    //need to make a string to hold the char; string is an array of array of chars.
    char s_array[size][max];

    char temp [size];


    //open the file
    if (argc > 1)
    {
        fPointer = fopen(sam_file[1], "r");
        if (!fPointer)
        {
            printf("Standard error\n");
            return 0;
        }
        
    }else
    {
        fPointer = stdin;
    }
    

    while (!feof(fPointer))
    {
        
        size++;
        fgets(c_array,max, fPointer);

        strcpy(s_array[size],c_array);

        //printf("copying to s_array \n");
        //printf("%d. %s", size , s_array[size]);
        
    }
    //sort the txt file
    for ( i = 0; i < size; i++)
    {
        for (j = i+1; j < size; j++)
        {
            if (strcmp(s_array[i],s_array[j]) > 0)
            {
                strcpy(temp,s_array[i]);
                strcpy(s_array[i],s_array[j]);
                strcpy(s_array[j],temp);
            }
        }
    }


    // //print out the new list
    for ( i = 0; i < size; i++)
    {
        //puts(s_array[i]);
        printf("%s", s_array[i]);
    }
    
    
    //close the file
    fclose(fPointer);

    return 0;
}