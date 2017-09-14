#include <stdlib.h>
#include<stdio.h>
int main()
{
    typedef struct ParentStr {
        long    srb_Identity;
        struct ChildStr {
            struct child_u {
                //long double a;
                long long int b;
                long long int c;
                long long int d;
                long long int e;
 //               long long int g;
   //             long long int f;
            } choice;
        } *child;
    } Parent_t;

    Parent_t *p;// =(void*)(calloc(2,sizeof(Parent_t)));
    //p->child = (void*)(calloc(1,);
    //p->child->choice.c =100000000000000000LL;
//    p->child->choice.b =1;
    printf("%lld ",sizeof(*p));
    printf("%lld %lld ",sizeof(struct ChildStr),sizeof(*(p->child)));
    //printf("%lld",p->child->choice.c);
    return 0;
}
