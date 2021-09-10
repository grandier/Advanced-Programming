#include<stdio.h> 
#include<stdlib.h> 
 
int nCk(int n,int loopno,int ini,int *a,int k) 
{ 
    static int count=0; 
    int i; 
    loopno--; 
    if(loopno<0) 
    { 
        a[k-1]=ini; 
        for(i=0;i<k;i++) 
        { 
            printf("%d,",a[i]); 
        } 
        printf("\n"); 
        count++; 
        return 0; 
    } 
    for(i=ini;i<=n-loopno-1;i++) 
    { 
        a[k-1-loopno]=i+1; 
        nCk(n,loopno,i+1,a,k); 
    } 
    if(ini==0) 
    return count; 
    else 
    return 0; 
} 
 
void main() 
{ 
    int n,k,*a,count; 
    printf("Enter the value of n and k\n"); 
    scanf("%d %d",&n,&k); 
    a=(int*)malloc(k*sizeof(int)); 
    count=nCk(n,k,0,a,k); 
    printf("No of combinations=%d\n",count); 
} 
