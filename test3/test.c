
char *p = NULL;
size_t *n =0;
getline(&p,&n,file);

//for every pointer
free(p);


----------------------------

charr *array[100];
size_t n;

{
    array[i] = NULL;
    n=0;
    //if(getline(&array[i],&n,file);<0)....
    //getline(array+i,&n,file);

}