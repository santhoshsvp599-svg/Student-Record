
#include <stdio.h>
#include <stdlib.h>
#include "student.h"

void stud_save(void)
{
    FILE *fp;
    Student *temp;

    fp = fopen("student.dat", "wb");

    if (fp == NULL) {
        printf("Unable to open file.\n");
        return;
    }

    temp = head;

    while (temp != NULL) {
        if (fwrite(&temp->roll, sizeof(int), 1, fp) != 1 ||
            fwrite(temp->name, sizeof(temp->name), 1, fp) != 1 ||
            fwrite(&temp->marks, sizeof(float), 1, fp) != 1) {

            printf("Error saving records.\n");
            fclose(fp);
            return;
        }

        temp = temp->next;
    }

    fclose(fp);
    printf("Records saved successfully.\n");
}

void stud_load(void)
{
    FILE *fp;
    Student *node, *tail = NULL;
    int roll;
    char name[NAME_LEN];
    float marks;

    fp = fopen("student.dat", "rb");

    if (fp == NULL)
        return;

    while (fread(&roll, sizeof(int), 1, fp) == 1) {
        if (fread(name, sizeof(name), 1, fp) != 1 ||
            fread(&marks, sizeof(float), 1, fp) != 1) {
            printf("Incomplete record in file.\n");
            break;
        }

        node = malloc(sizeof(Student));

        if (node == NULL) {
            printf("Memory allocation failed.\n");
            break;
        }

        node->roll = roll;
        name[NAME_LEN - 1] = '\0';

        snprintf(node->name, NAME_LEN, "%s", name);

        node->marks = marks;
        node->next = NULL;

        if (head == NULL)
            head = node;
        else
            tail->next = node;

        tail = node;
    }

    fclose(fp);
}

void free_records(void)
{
    Student *temp;

    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}