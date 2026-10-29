
#include <stdio.h>
#include <ctype.h>
#include "student.h"

Student *head = NULL;

int main(void)
{
    char choice;

    stud_load();

    do {
        printf("\n");
        printf("===============================\n");
        printf("\n**** STUDENT RECORD MENU ****\n");
        printf("===============================\n");
        printf("| A/a : Add New Record\n");
        printf("| D/d : Delete a Record\n");
        printf("| S/s : Show the List\n");
        printf("| M/m : Modify a Record\n");
        printf("| V/v : Save\n");
        printf("| T/t : Sort the List\n");
        printf("| E/e : Exit\n");
        printf("================================\n");
        printf("Enter Your Choice: ");

        if (scanf(" %c", &choice) != 1)
            break;

        choice = (char)toupper((unsigned char)choice);

        switch (choice) {
            case 'A':
                stud_add();
                break;

            case 'D':
                stud_del();
                break;

            case 'S':
                stud_show();
                break;

            case 'M':
                stud_mod();
                break;

            case 'V':
                stud_save();
                break;

            case 'T':
                stud_sort();
                break;

            case 'E': {
                char exit_choice;

                printf("S/s : Save and Exit\n");
                printf("E/e : Exit Without Saving\n");
                printf("Enter Your Choice: ");

                if (scanf(" %c", &exit_choice) != 1)
                    exit_choice = 'E';

                exit_choice = (char)toupper(
                    (unsigned char)exit_choice
                );

                if (exit_choice == 'S')
                    stud_save();

                free_records();
                return 0;
            }

            default:
                printf("Invalid choice. Try again.\n");
        }

    } while (1);

    free_records();
    return 0;
}