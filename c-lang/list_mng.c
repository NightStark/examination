#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

struct list 
{
    struct list *next;
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

int main(void)
{
    struct list head = {0};
    int cnt = 0;

    generate_a_list(&head);

    cnt = get_list_cnt(&head);
    printf("cnt = %d\n", cnt);

    return 0;
}
