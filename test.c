#include<stdio.h>

struct node {
    int i;
    int *c;
};

int main(int argc, char const *argv[])
{
    struct node a[2], *p;
    int b[2] = {30,40};
    p = a;
    a[0].i = 10;
    a[0].c = b;
    a[1].i = 20;
    int x;
    // int x = ++p -> i;
    // x = (++p) -> i;
    // x = (p++) -> i;
    // x = *p -> c;
    // x = *p -> c++;
    // x = (*p -> c)++;
    x = *p++ -> c;
    printf("%d\n",x);
    printf("%d\n",*(p->c));
    return 0;
}
