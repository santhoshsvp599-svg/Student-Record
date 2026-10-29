
#include <stdio.h>
#include "student.h"

void stud_show(void)
{
    Student *temp;

    if (head == NULL) {
        printf("No student records found.\n");
        return;
    }

    printf("\n-----------------------------------------------\n");
    printf("%-10s %-25s %s\n",
           "Roll No", "Name", "Marks");
    printf("-----------------------------------------------\n");

    temp = head;

    while (temp != NULL) {
        printf("%-10d %-25s %.2f\n",
               temp->roll,
               temp->name,
               temp->marks);

        temp = temp->next;
    }

    printf("-----------------------------------------------\n");
}