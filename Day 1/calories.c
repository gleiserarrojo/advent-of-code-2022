#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    long calories;
    struct node *next;
} node;

typedef struct {
    node *head, *tail, *bigger, *second, *third;
    int size;
} list;

void insertHead(list *l, long calories){
    node *new = (node *)malloc(sizeof(node));
    new->calories = calories;

    if(l->head == NULL){
        new->next = NULL;
        l->head = new;
        l->tail = new;
        l->bigger = new;
        l->second = new;
        l->third = new;
    }
    else {
        new->next = l->head;
        l->head = new;
        if (new->calories > l->bigger->calories) {
            l->bigger = new;
        }
        else if (new->calories > l->second->calories) {
            l->second = new;
        }
        else if (new->calories > l->third->calories) {
            l->third = new;
        }
    }

    l->size++;
}

void insertTail(list *l, long calories){
    node *new = (node *)malloc(sizeof(node));
    new->calories = calories;
        new->next = NULL;

    if(l->head == NULL){
        l->head = new;
        l->tail = new;
        l->bigger = new;
        l->second = new;
        l->third = new;
    }
    else {
        l->tail->next = new;
        l->tail = new;
        if (new->calories > l->bigger->calories) {
            l->bigger = new;
        }
        else if (new->calories > l->second->calories) {
            l->second = new;
        }
        else if (new->calories > l->third->calories) {
            l->third = new;
        }
        
    }

    l->size++;
}

void printBigger(list *l){
    printf("Most calories: %ld\n", l->bigger->calories);
}

void printSumThreeBiggest(list *l){
    long total;
    total = l->bigger->calories + l->second->calories + l->third->calories;
    printf("Sum 3 biggest: %ld\n", total);
}

int main(){
    list l;
    l.bigger = NULL;
    l.second = NULL;
    l.third = NULL;
    l.head = NULL;
    l.tail = NULL;
    l.size = 0;

    char *string;

    long calories = 0;

    FILE *file;

    file = fopen("input.txt", "r");

    if (file != NULL) {
        printf("Abriu arquivo\n");

        while (fgets(string, 30, file) != NULL) {
            printf("%s", string);
            if (string[0] == '\n') {
                printf("calories = %ld\n", calories);
                insertTail(&l, calories);
                calories = 0;
            }
            else {
                calories += atol(string);
            }
            memset(string, 0, 20);
        }

        printBigger(&l);
        printSumThreeBiggest(&l);
    }
    else {
        printf("empty file :/\n");
    }

    fclose(file);
    return 0;
}