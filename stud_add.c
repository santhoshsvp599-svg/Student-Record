
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student.h"

void stud_add(void)
{
    Student *newnode, *temp;
    char *newline;
    int roll = 1;
    int ch;

    /* Find the smallest available roll number */
    for (;;) {
        int used = 0;

        for (temp = head; temp != NULL; temp = temp->next) {
            if (temp->roll == roll) {
                used = 1;
                break;
            }
        }

        if (!used)
            break;
        roll++;
    }

    newnode = malloc(sizeof(Student));

    if (newnode == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    newnode->roll = roll;

    /* Remove leftover newline from previous input */
    while ((ch = getchar()) != '\n' && ch != EOF) {
    }

    printf("Enter student name: ");

    if (fgets(newnode->name, NAME_LEN, stdin) == NULL) {
        free(newnode);
        return;
    }

    newline = strchr(newnode->name, '\n');
    if (newline != NULL)
        *newline = '\0';

    if (newnode->name[0] == '\0') {
        printf("Name cannot be empty.\n");
        free(newnode);
        return;
    }

    printf("Enter marks: ");

    if (scanf("%f", &newnode->marks) != 1 ||
        newnode->marks < 0 ||
        newnode->marks > 100) {

        printf("Invalid marks. Enter 0 to 100.\n");
        free(newnode);
        return;
    }

    newnode->next = NULL;

    if (head == NULL) {
        head = newnode;
    } else {
        temp = head;

        while (temp->next != NULL)
            temp = temp->next;

        temp->next = newnode;
    }

    printf("Student added successfully.\n");
    printf("Assigned Roll Number: %d\n", roll);
}