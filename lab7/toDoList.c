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
    
    if (!task) {
        printf("Błąd alokacji pamięci");
    }

    task->name = strdup(name);
    task->next = NULL;
    return task;
}

void task_free(struct Task *task) {
    if (task) {
        free(task->name);
        free(task);
    }
}

void show_tasks() {
    struct Task *current = head;
    if (current == NULL) {
        printf("Brak zadań. \n");
    }
    
    printf("Zadania: \n");
    while (current != NULL) {
        printf("- %s\n", current -> name);
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
    int option;
    char name[20];

    while (1) {
        printf("\n1. Pokaż zadania \n");
        printf("2. Dodaj zadanie \n");
        printf("3. Usuń pierwsze zadanie \n");
        printf("4. Wyjście \n");
        printf("Wybierz: ");
        scanf("%d", &option);
        getchar();

        if (option == 1) {
            show_tasks();
        } else if (option == 2) {
            printf("Podaj nazwę zadania: ");
            scanf("%[^\n]", name);
            add_task(name);
        } else if (option == 3) {
            remove_task();
        } else if (option == 4) {
            break;
        } 
    }

    while (head != NULL) {
        remove_task();
    }

    return 0;
}