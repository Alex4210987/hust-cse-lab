#include <stdio.h>
int main()
{
    struct node
    {
        int data;;
        struct node *next;
    };
    struct node *q,*head,*p;
    int m,n;
    scanf("%d%d",&m,&n);
    head=p=(struct node*)malloc(sizeof(struct node));
    p->data=1;
    int i=0;
    for(i=2;i<=m;++i)
    {
        q=(struct node*)malloc(sizeof(struct node));;
        q->data=i;
        p->next=q;
        p=q;
    }
    p->next=head;
    q=head;

    while(q->next!=q)
    {
        for(i=1;i<n;++i) q=q->next;
        printf("%d ",q->data);
        struct node *delt,*del;
        delt=head;
        while(delt->next!=q) delt=delt->next;
        del=delt->next;
        delt->next=del->next;
        free(del);
        q=delt->next;

    }
    printf("%d",q->data);
    return 0;
}
