#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>

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

int generate_two_list(struct list *head1, struct list *head2, int cnt)
{
    struct list *p = NULL;

    struct list *t1 = NULL;
    struct list *t2 = NULL;
    int i = 0;

    srand(time(0));

    while (i++ < cnt) {
        //printf("rand:%d\n", rand());
        p = malloc(sizeof(struct list));
        if (!p) {
            return -1;
        }
        memset(p, 0, sizeof(struct list));
        p->data = i;

        if (rand() % 2 == 0) {
            if (i < 5) { //start at 5
                continue;
            }
            if (!head1->next) {
                head1->next = p;
            } else {
                //continue; //only one
                t1->next = p;    
            }
            t1 = p;
        } else {
            if (!head2->next) {
                head2->next = p;
            } else {
                t2->next = p;    
            }
            t2 = p;
        }
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

void swap_two_node(struct list *head, int data)
{
    struct list *P = NULL; 
    struct list *T = NULL; 
    struct list *N = NULL; 

    P = head->next;

    if (NULL == P) {
        return;
    }
    T = P->next;
    if (NULL == T) {
       return; 
    }

    N = T->next;
    if (NULL == N) {
        if(P->data == data) {
            T->next = P;
            P->next = NULL;
            head->next = T;
        }
        return;
    }
    while (T) {
        if (T->data == data) {
            T->next = N->next;
            N->next = T;
            P->next = N;
            break;
        }
        P = T;
        T = N;
        N = N->next;
    }

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

    struct list S = {0};
    generate_a_list(&S, len);

    swap_two_node(&S, len < 2 ? 0 : len / 2);
    printf("SWAP TWO NODE len=%d len/2=%d >>> \n", len, len/2);
    dump_list(&S);
    printf("SWAP TWO NODE <<< \n");

    printf("<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n");
    printf("END len = %d\n", len);
    printf("<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n");

    return 0;
}

struct list * find_last_k(struct list *head, int k)
{
    int i = 0;
    struct list *p = NULL; 
    struct list *k_t = NULL;

    if (!head) {
        return NULL;
    }

    p = head->next;
    k_t = p;

    while (p && (i < k)) {
        p = p->next;
        i++;
    }

    if (NULL == p) {
        printf("length of list is less than k[%d]\n", k);
        return NULL;
    }

    while (p) {
        p = p->next;
        k_t = k_t->next;
    }

    return k_t;
}

struct list *merge_sorted_list(struct list *head1, struct list *head2)
{
    if (!head1) {
        return head2;
    }
    if (!head2) {
        return head1;
    }
 
    if (head1->data < head2->data) {
        return head1->next = merge_sorted_list(head1->next, head2), head1;
    } else {
        return head2->next = merge_sorted_list(head1, head2->next), head2;
    }
    
}

int main(void)
{
    list_mng_test(0);
    list_mng_test(1);
    list_mng_test(2);
    list_mng_test(10);

    struct list F = {0};
    struct list *lk = NULL;

    generate_a_list(&F, 15);
    lk = find_last_k(&F, 5);
    dump_list(&F);

    printf("lk = %d\n", lk->data);
    
    struct list A = {0};
    struct list B = {0};
    generate_two_list(&A, &B, 20);
    dump_list(&A);
    dump_list(&B);
    struct list M = {0};
    M.next = merge_sorted_list(A.next, B.next);
    dump_list(&M);

    struct list S = {0};
    generate_a_list(&S, 2);
    dump_list(&S);
    swap_two_node(&S, 0);
    dump_list(&S);

    return 0;
}
