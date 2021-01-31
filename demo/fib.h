long cache[1000] = {0,1};
int limit =1;
int uninitialized[1000];

long fib(int n) {
    if(n < 0)
        return 0;
    while (limit < n){
        limit++;
        cache[limit] =cache[limit-1]+cache[limit-2];
    }
    return cache[n];
    
}