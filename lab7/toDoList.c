#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Task {
    char *name;
    struct Task *next;
};

struct Task *head = NULL;
struct Task *tail = NULL;

struct Task* task_new(const char *name) {
    struct Task *task = malloc(sizeof(struct Task));
    task->name = strdup(name);
    task->next = NULL;

    if (tail != NULL) {
        tail->next = task;
    }
    tail = task;

    if (head == NULL) {
        head = tail;
    }
}

void task_free(struct Task *task) {
    if (task) {
        free(task->name);
        free(task);
    }
}

void show_tasks() {
    struct Task *current = head;
    if (current != NULL) {
        printf("%s", current -> name);
        current = current -> next;
    }    
}

void add_task(const char *name) {
    struct Task *new_task = task_new(name);
    if (tail != NULL) {
        tail -> next = new_task;
    }
    tail = new_task;
    if (head == NULL) {
        head = tail = new_task;
    }
}

void remove_task() {
    if (head == NULL) {
        printf("Brak zadań w kolejce");
    }
    struct Task *task_remove = head;
    head = head -> next;

    if (head == NULL) {
        tail = NULL;
    }

    printf("Usunięto zadanie: %s\n", task_remove->name);
    task_free(task_remove);
}

int main() {
    add_task("Wynieś śmieci \n");
    add_task("Zapłać rachunki \n");
    add_task("Naucz się na kolokwium \n");
    add_task("Wyśpij się \n");
    
    printf("Wszystkie zadania: \n");
    show_tasks();

    printf("Usuwanie zadania: \n");
    remove_task();

    printf("Pokaż wszystkie zadania: \n");
    show_tasks();

    while (head != NULL) {
        remove_task();
    }
    return 0;
}