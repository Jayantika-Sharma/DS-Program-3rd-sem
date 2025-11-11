# include <stdio.h>
int n,count=0;
char s='s',m='m',d='d';
void toh(int n,char s,char m,char d)
{
    if (n==1)
    {
        printf("\nMove disk from %c to %c",s,d);
        count++;
    }
    else
    {
        toh(n-1,s,d,m);
        printf("\nMove disk from %c to %c",s,d);
        count++;
        toh(n-1,m,s,d);
    }
}
int main()
{
    printf("Enter number of Disk: ");
    scanf("%d",&n);
    toh(n,s,m,d);
    printf("\nNumber of count:%d",count);
    return 0;
}