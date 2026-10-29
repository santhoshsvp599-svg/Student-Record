
#include <stdio.h>
#include <string.h>
#include "student.h"

void stud_mod(void)
{
    char search_choice, field_choice;
    char name[NAME_LEN];
    int roll = -1, ch, found = 0;
    float marks;
    Student *temp;

    printf("Search Record:\n");
    printf("R/r : Roll Number\n");
    printf("N/n : Name\n");
    printf("M/m : Marks\n");
    printf("Enter Your Choice: ");
    scanf(" %c", &search_choice);

    if (search_choice >= 'a' && search_choice <= 'z')
        search_choice = (char)(search_choice - 'a' + 'A');

    if (search_choice == 'R') {
        printf("Enter roll number: ");

        if (scanf("%d", &roll) != 1)
            return;

    } else if (search_choice == 'N') {
        while ((ch = getchar()) != '\n' && ch != EOF) {
        }

        printf("Enter name to search: ");

        if (fgets(name, NAME_LEN, stdin) == NULL)
            return;

        name[strcspn(name, "\n")] = '\0';

        for (temp = head; temp != NULL; temp = temp->next) {
            if (strcmp(temp->name, name) == 0) {
                printf("Roll: %d  Name: %s  Marks: %.2f\n",
                       temp->roll, temp->name,
                       temp->marks);
            }
        }

        printf("Enter roll number to modify: ");

        if (scanf("%d", &roll) != 1)
            return;

    } else if (search_choice == 'M') {
        printf("Enter marks to search: ");

        if (scanf("%f", &marks) != 1)
            return;

        for (temp = head; temp != NULL; temp = temp->next) {
            if (temp->marks == marks) {
                printf("Roll: %d  Name: %s  Marks: %.2f\n",
                       temp->roll, temp->name,
                       temp->marks);
            }
        }

        printf("Enter roll number to modify: ");

        if (scanf("%d", &roll) != 1)
            return;

    } else {
        printf("Invalid choice.\n");
        return;
    }

    for (temp = head; temp != NULL; temp = temp->next) {
        if (temp->roll == roll) {
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Record not found.\n");
        return;
    }

    printf("N/n : Modify Name\n");
    printf("M/m : Modify Marks\n");
    printf("Enter Your Choice: ");
    scanf(" %c", &field_choice);

    if (field_choice >= 'a' && field_choice <= 'z')
        field_choice = (char)(field_choice - 'a' + 'A');    

    if (field_choice == 'N') {
        while ((ch = getchar()) != '\n' && ch != EOF) {
        }

        printf("Enter new name: ");

        if (fgets(name, NAME_LEN, stdin) == NULL)
            return;

        name[strcspn(name, "\n")] = '\0';

        if (name[0] == '\0') {
            printf("Name cannot be empty.\n");
            return;
        }

        strcpy(temp->name, name);

    } else if (field_choice == 'M') {
        printf("Enter new marks: ");

        if (scanf("%f", &marks) != 1 ||
            marks < 0 || marks > 100) {
            printf("Invalid marks.\n");
            return;
        }

        temp->marks = marks;

    } else {
        printf("Invalid choice.\n");
        return;
    }

    printf("Record modified successfully.\n");
    printf("Select V from the main menu to save changes.\n");
}