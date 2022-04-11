#include <stdio.h>

// code 1
struct bnode {
    int v;                  // label
    struct bnode *lc, *rc;  // left & right children
};

// code 3
void trav_pre(struct bnode *t) {
     if (t != NULL) {
        printf("%d", t->v);
        trav_pre(t->lc);
        trav_pre(t->rc);
    }
}

/*
// code 4
void trav_in(struct bnode *t) {
    if (t != NULL) {
        trav_in(t->lc);
        printf("%d", t->v);
        trav_in(t->rc);
    }
}
*/

/*
// code 5
void trav_pre(struct bnode *t) {
start:
     if (t != NULL) {
        printf("%d", t->v);
        trav_pre(t->lc);
        t = t->rc;
        goto start;
    }
}
*/

/*
// code 6
void trav_pre(struct bnode *t) {
    while (t != NULL) {
        printf("%d", t->v);
        trav_pre(t->lc);
        t = t->rc;
    }
}
*/

/*
#define STACK_SIZE 32

// code 7
void trav_pre(struct bnode *t) {
    struct bnode* stack[STACK_SIZE];
    int sp = 0;
start:
    while (t != NULL) {
        printf("%d", t->v);
        stack[sp++] = t; // PUSH
        t = t->lc;
        goto start;
resume:
        t = t->rc;
    }
    if (sp > 0) {
        t = stack[--sp]; // POP
        goto resume;
    }
}
*/

/*
#define STACK_SIZE 32

// code 8
void trav_pre(struct bnode *t) {
    struct bnode *stack[STACK_SIZE];
    int sp = 0;
    for (;;) {
        while (t != NULL) {
            printf("%d\n", t->v);
            stack[sp++] = t; // PUSH
            t = t->lc;
        }
        if (sp == 0) return;
        t = stack[--sp];     // POP
        t = t->rc;
    }
}
*/

/*
// code 9
void trav_post(struct bnode *t) {
    if (t != NULL) {
        trav_post(t->lc);
        trav_post(t->rc);
        printf("%d", t->v);
    }
}
*/

/*
// code 10
void trav_pre(struct bnode *t) {
    while (t != NULL) {
        if (t->lc == NULL) {
            printf("%d", t->v);
            t = t->rc;
        }
        else {
            struct bnode *rm = t->lc;
            while (rm->rc != NULL && A) {  // A should be replaced
                rm = rm->rc;
            }
            if (rm->rc == NULL) {
                printf("%d", t->v);
                rm->rc = t;
                t = t->lc;
            }
            else {
                rm->rc = NULL;
                t = t->rc;
            }
        }
    }
}
*/

int main() {
    // code 2
    struct bnode n8 = { 8, NULL, NULL };
    struct bnode n7 = { 7, NULL, NULL };
    struct bnode n6 = { 6, NULL, NULL };
    struct bnode n5 = { 5, &n8,  NULL };
    struct bnode n4 = { 4, NULL, NULL };
    struct bnode n3 = { 3, &n6,  &n7  };
    struct bnode n2 = { 2, &n4,  &n5  };
    struct bnode n1 = { 1, &n2,  &n3  };

    trav_pre(&n1);
    printf("\n");

    return 0;
}
