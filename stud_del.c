
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include "student.h"

void stud_del(void)
{
    char choice;
    char name[NAME_LEN];
    int roll, ch;
    Student *temp, *prev;

    printf("R/r : Delete using Roll Number\n");
    printf("N/n : Delete using Name\n");
    printf("Enter Your Choice: ");
    scanf(" %c", &choice);

    choice = (char)toupper((unsigned char)choice);

    if (choice == 'R') {
        printf("Enter roll number: ");

        if (scanf("%d", &roll) != 1) {
            printf("Invalid roll number.\n");
            return;
        }
    } else if (choice == 'N') {
        while ((ch = getchar()) != '\n' && ch != EOF) {
        }

        printf("Enter student name: ");

        if (fgets(name, NAME_LEN, stdin) == NULL)
            return;

        name[strcspn(name, "\n")] = '\0';

        printf("\nMatching Records:\n");

        for (temp = head; temp != NULL; temp = temp->next) {
            if (strcmp(temp->name, name) == 0) {
                printf("Roll: %d  Name: %s  Marks: %.2f\n",
                       temp->roll, temp->name,
                       temp->marks);
            }
        }

        printf("Enter roll number to delete: ");

        if (scanf("%d", &roll) != 1) {
            printf("Invalid roll number.\n");
            return;
        }
    } else {
        printf("Invalid choice.\n");
        return;
    }

    temp = head;
    prev = NULL;

    while (temp != NULL) {
        if (temp->roll == roll) {
            if (prev == NULL)
                head = temp->next;
            else
                prev->next = temp->next;

            printf("Record deleted: %s\n", temp->name);
            free(temp);
            return;
        }

        prev = temp;
        temp = temp->next;
    }

    printf("Roll number not found.\n");
}