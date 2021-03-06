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

int make_a_loop_in_list(struct list *head, int index)
{
    int i = 0;
    struct list *T = NULL;
    struct list *L = NULL;

    T = head->next;

    if (NULL == T) {
        return -1;
    }

    while (T) {
        if (i >= index) {
            L = T;
            break;
        }
        T = T->next;
        i++;
    }

    if (NULL == L || NULL == T) {
        return -1;
    }

    while (T->next) {
        T = T->next;
    }

    T->next = L;

    return 0;
}

int let_two_list_intersect(struct list *head1, struct list *head2, int h1_index)
{
    /*                             h1_index
     *                             V
     * head1 ______________________.______________
     *                            /
     * head2 ____________________/
     * */

    int i = 0;
    struct list * a = NULL;
    struct list * b = NULL;

    if (NULL == head1 || NULL == head1->next) {
        return -1;
    }
    if (NULL == head2 || NULL == head2->next) {
        return -1;
    }

    a = head1->next;
    b = head2->next;

    while (a) {
        if (i >= h1_index) {
            break;
        }
        a = a->next;
        i++;
    }

    if (NULL == a) {
        return -1;
    }

    while (b->next) {
        b = b->next;
    }

    b->next = a;

    return 0;
} 

int generate_two_list(struct list *head1, struct list *head2, int cnt) {
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

int find_loop_in_list(struct list *head)
{
    struct list *Fast = NULL;
    struct list *Slow = NULL;

    Fast = head->next;
    Slow = Fast;

    if (NULL == Fast) {
        return 0;
    }

    while (Fast && Fast->next) {
        Fast = Fast->next->next;
        Slow = Slow->next;
        if (Fast == Slow) {
            printf("find loop\n");
            return 1;
        }
    }

    return 0;
}

struct list * get_first_comm_note_of_intersected(struct list *head1, struct list *head2)
{
    struct list *a = NULL;
    struct list *b = NULL;

    if (head1 == NULL || head1->next == NULL) {
        return NULL;
    }
    if (head2 == NULL || head2->next == NULL) {
        return NULL;
    }

    a = head1->next;
    b = head2->next;

    int len_a = 0;
    int len_b = 0;

    while (a) {
        len_a++;
        a = a->next;
    }

    while (b) {
        len_b++;
        b = b->next;
    }

    int diff = 0;
    a = head1->next;
    b = head2->next;

    if (len_a > len_b) {
        diff = len_a - len_b;
        while (diff--) {
            a = a->next;
        }
    } else {
        diff = len_b - len_a;
        while (diff--) {
            b = b->next;
        }
    }

    while (a != b) {
        a = a->next;
        b = b->next;
    }

    if (NULL == a || NULL == b) {
        printf("this two list is not intersected.\n");    
        return NULL;
    }

    printf("find comm node, data = [%d]\n", a->data);

    return a;
}

int check_two_list_is_intersected(struct list *head1, struct list *head2)
{
    struct list *a = NULL;
    struct list *b = NULL;

    if (NULL == head1 || NULL == head1->next) {
        return -1;
    }
    if (NULL == head2 || NULL == head2->next) {
        return -1;
    }

    a = head1->next;
    b = head2->next;

    while (a->next) {
        a = a->next;
    }
    while (b->next) {
        b = b->next;
    }

    if (a == b) {
        printf("two list IS INTERSECT.\n");
    } else {
        printf("two list is NOT intersect.\n");
    }

    return 0;
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

    struct list LOOP = {0};
    generate_a_list(&LOOP, 10);
    //dump_list(&LOOP);
    make_a_loop_in_list(&LOOP, 5);
    //dump_list(&LOOP);
    find_loop_in_list(&LOOP);


    struct list IN_A = {0};
    struct list IN_B = {0};
    generate_a_list(&IN_A, 15);
    generate_a_list(&IN_B, 10);

    let_two_list_intersect(&IN_A, &IN_B, 8);
    dump_list(&IN_A);
    dump_list(&IN_B);

    check_two_list_is_intersected(&IN_A, &IN_B);
    get_first_comm_note_of_intersected(&IN_A, &IN_B);

    return 0;
}
