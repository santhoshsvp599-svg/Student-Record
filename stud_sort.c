
#include <stdio.h>
#include <string.h>
#include "student.h"

void stud_sort(void)
{
    char choice;
    Student *p, *q;
    int swapped;

    printf("N/n : Sort by Name\n");
    printf("M/m: Sort by Marks\n");
    printf("Enter Your Choice: ");
    scanf(" %c", &choice);

    if (choice >= 'a' && choice <= 'z')
        choice = (char)(choice - 'a' + 'A');

    if (choice != 'N' && choice != 'M') {
        printf("Invalid choice.\n");
        return;
    }

    if (head == NULL || head->next == NULL) {
        printf("Not enough records to sort.\n");
        return;
    }

    do {
        swapped = 0;
        p = head;

        while (p->next != NULL) {
            q = p->next;

            if ((choice == 'N' &&
                 strcmp(p->name, q->name) > 0) ||
                (choice == 'M' &&
                 p->marks > q->marks)) {

                int temp_roll = p->roll;
                char temp_name[NAME_LEN];
                float temp_marks = p->marks;

                strcpy(temp_name, p->name);

                p->roll = q->roll;
                strcpy(p->name, q->name);
                p->marks = q->marks;

                q->roll = temp_roll;
                strcpy(q->name, temp_name);
                q->marks = temp_marks;

                swapped = 1;
            }

            p = p->next;
        }

    } while (swapped);

    printf("Records sorted successfully.\n");
    printf("Select V to save the sorted records.\n");
}