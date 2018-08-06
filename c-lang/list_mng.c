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

int generate_a_list(struct list *head, int cnt)
{
    struct list *p = NULL;
    struct list *t = NULL;
    int i = 0;

    while (i < cnt) {
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

    head->next = p;

    return head;
}

struct list * reverse_list2(struct list *head, struct list *next)
{
    struct list *p = NULL;
    if (NULL == head) {
        printf("error\n");
        return NULL;
    }
    
    if (NULL == next) {
        printf("no next\n");
        return head;
    }

    if (NULL == next->next) {
        printf("only two\n");
        next->next = head;
        head->next = NULL;
        return next;
    }

    p = reverse_list2(next, next->next);
    if (!p) {
        printf("never come to here\n");
    }


    next->next = head;
    head->next = NULL;

    return p;
}

void dump_list(struct list *head)
{
    int cnt = 0;
    struct list *p = NULL;

    p = head->next;

    printf("============================\n");
    while (p) {
        printf("[%d]\n",p->data);
        p = p->next;
        if (cnt++ > 200) {
            printf("dump error\n");
            break;
        }
    }
    printf("============================\n");

    return;
}

int list_mng_test(int len)
{
    struct list head = {0};
    int cnt = 0;

    printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
    printf("START len = %d\n", len);
    printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
    generate_a_list(&head, len);
    //dump_list(&head);

    cnt = get_list_cnt(&head);
    printf("cnt = %d\n", cnt);

    struct list *N = NULL;
    N = reverse_list(&head);
    cnt = get_list_cnt(N);
    printf("cnt = %d\n", cnt);
    dump_list(N);

    if (N->next) {
        N->next = reverse_list2(N->next, N->next->next);
        dump_list(N);
    }
    printf("<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n");
    printf("END len = %d\n", len);
    printf("<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n");

    return 0;
}

int main(void)
{
    list_mng_test(0);
    list_mng_test(1);
    list_mng_test(2);
    list_mng_test(10);
}
