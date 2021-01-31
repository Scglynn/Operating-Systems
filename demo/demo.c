#include <stdio.h>

int main()
{
    int maxLength = 30;
    int maxLines = 3;
    
    //char c_array [maxLength];
    char s_array [maxLines] [maxLength];
    
    for (int i = 0; i < maxLines; ++i)
    {
        printf ("Enter string: ");
        
        // long way: read data into char[] then copy into char[][]
        //fgets(c_array, maxLength, stdin);
        //strcpy(s_array[i], c_array);
        
        // short way: read data directly into char[][]
        fgets(s_array[i], maxLength, stdin);
    }
    
    // make sure everything was stored
    for (int j = 0; j < maxLines; ++j)
    {
        printf(s_array[j]);
    }

    return 0;
}
