
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STUDENT_H

#define NAME_LEN 100

typedef struct Student {
    int roll;
    char name[NAME_LEN];
    float marks;
    struct Student *next;
} Student;

extern Student *head;

void stud_add(void);
void stud_del(void);
void stud_show(void);
void stud_mod(void);
void stud_save(void);
void stud_load(void);
void stud_sort(void);
void free_records(void);
