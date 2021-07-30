#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int val;
    struct node *next;
} node;
typedef node *List;
List create()
{
    node *head = (node *)malloc(sizeof(node));
    head->val = 0;
    head->next = NULL;
    List list = head;
    return list;
}
int List_insert(int pos, int x, List L)
{
    node *p, *q;
    p = L;
    if (pos < 0)
        return 0;
    else
    {
        for (int i = 0; i < pos; ++i)
        {
            if (p->next == NULL)
                return 0;
            else
                p = p->next;
        }
        q = (node *)malloc(sizeof(node));
        q->val = x;
        q->next = p->next;
        p->next = q;
        return 1;
    }
}
int List_delete(int x, List L)
{
    node *p = L;
    node *q;
    while (p->next != NULL)
    {
        if (p->next->val == x)
        {
            q = p->next;
            p->next = q->next;
            free(q);
            return 1;
        }
        else
            p = p->next;
    }
    return 0;
}
node *List_find(int x, List L)
{
    node *p = L;
    while (p->next != NULL)
    {
        p = p->next;
        if (p->val == x)
            return p;
    }
    return NULL;
}
int main()
{
    List list = create();
    List_insert(0, 3, list);
    List_insert(1, 4, list);
    List_insert(2, 5, list);
    List_delete(3, list);
    node *result = List_find(6, list);
    if (result == NULL)
        printf("%d", -1);
    else
        printf("%d", result->val);
    return 0;
}