/* Exercise 4-1.  Our binary search makes two tests inside the loop, when one
would suffice (at the price of more tests outside).  Write a version with only
one test inside the loop and measure the difference in run-time.
*/
#include<stdio.h>

int main(void)
{
    int x = 4;
    int n = 11;
    int v[11] = {0,1,4,5,6,11,16,23,34,52};
    printf("Array index is %d\n",binsearch(x,v,n));
    printf("Array index is %d\n",binsearch2(x,v,n));
    
    return 0;
}

/* binsearch:  find x in v[0] <= v[1] <= ... <= v[n-1] */
int binsearch(int x, int v[], int n)
{
    int low, high, mid;
    
    low = 0;
    high = n - 1;
    int loop_iters = 0;
    while (low <= high) {
        loop_iters++;
        mid = (low+high) / 2;
        printf("mid = %d, high=%d, low=%d, v[mid]=%d\n",mid,high,low,v[mid]);
        if (x < v[mid]) {
            printf("%d < %d\n",x,v[mid]);
            high = mid - 1;
        } else if (x > v[mid]) {
            printf("%d > %d\n",x,v[mid]);
            low = mid + 1;
        } else {   /* found match */
            printf("%d = %d\n",x,v[mid]);
            printf("Loop iterations = %d\n",loop_iters);
            return mid;
        }
    }
    printf("Loop iterations = %d\n",loop_iters);
    return -1;  /* no match */
}

/* binsearch2:  find x in v[0] <= v[1] <= ... <= v[n-1] */
int binsearch2(int x, int v[], int n)
{
    int low, high, mid;
    int loop_iters = 0;
    
    low = 0;
    high = n - 1;
    mid = (low+high) / 2;
    while (low <= high) {
        loop_iters++;
        printf("mid = %d, high=%d, low=%d, v[mid]=%d\n",mid,high,low,v[mid]);
        if (x < v[mid]) {
            printf("%d < v[%d]=%d\n",x,mid,v[mid]);
            high = mid - 1;
            printf("Set high = %d\n",high);
        } else  {
            printf("%d >= v[%d]=%d\n",x,mid,v[mid]);
            low = mid + 1;
            printf("Set low = %d\n",low);
        }
        mid = (low+high) / 2;
    }
    if(x == v[mid]) {   /* found match */
        printf("%d = %d\n",x,v[mid]);
        printf("Loop iterations = %d\n",loop_iters);
        return mid;
    }
    printf("Loop iterations = %d\n",loop_iters);
    return -1;  /* no match */
}