#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

struct list 
{
    struct list *next;
    int data;
};

int get_list_cnt(struct list *head)
{
    int cnt = 0;
    struct list *p = NULL;
    if (!head) {
        return 0;
    }

    p = head->next;

    while (p) {
        cnt++;
        p = p->next;
    }

    return cnt;
}

int generate_a_list(struct list *head)
{
    struct list *p = NULL;
    struct list *t = NULL;
    int i = 0;

    while (i < 112) {
        p = malloc(sizeof(struct list));
        if (!p) {
            return -1;
        }
        memset(p, 0, sizeof(struct list));
        p->data = i;
        if (!head->next) {
            head->next = p;
        } else {
            t->next = p;    
        }
        t = p;
        i++;
    }



    return 0;
}

struct list * reverse_list(struct list *head)
{
    struct list *c = NULL;
    struct list *T = NULL;
    struct list *p = NULL;

    if (!head) {
        return NULL;
    }

    c = head->next;
    
    /* 核心语句通过变量T保证旧表不会断，新表头不丢 */
    while (c) {
        T = c;
        c = c->next;
        T->next = p;
        p = T;
    }

    head = p;

    return head;
}
#if 0
struct list * reverse_list(struct list *head)
{
    struct list *p = NULL;
    if (!head->next) {
        return head;
    }

    p = reverse_list(head->next->next);
    if (p == head->next) {
        p->next = head;
        return p;
    }

    return;
}
#endif

void dump_list(struct list *head)
{
    struct list *p = NULL;

    p = head->next;

    while (p) {
        printf("[%d]\n",p->data);
        p = p->next;
    }

    return;
}

int main(void)
{
    struct list head = {0};
    int cnt = 0;

    generate_a_list(&head);

    cnt = get_list_cnt(&head);
    printf("cnt = %d\n", cnt);

    struct list *N = NULL;
    N = reverse_list(&head);
    dump_list(N);

    return 0;
}
