#include <stdio.h>
#include <stdlib.h>

#define BUILD_COMMAND \
    "gcc -Wall -Wextra -std=c11 " \
    "main.c stud_add.c stud_del.c stud_mod.c stud_save.c " \
    "stud_show.c stud_sort.c -o student.exe"

#ifdef _WIN32
#define RUN_COMMAND "student.exe"
#else
#define RUN_COMMAND "./student.exe"
#endif

static int run_command(const char *command)
{
    int result = system(command);

    if (result != 0) {
        fprintf(stderr, "Command failed: %s\n", command);
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}

int main(void)
{
    printf("Building student-record application...\n");

    if (run_command(BUILD_COMMAND) != EXIT_SUCCESS) {
        fprintf(stderr, "Build failed. The application was not started.\n");
        return EXIT_FAILURE;
    }

    printf("Build completed successfully.\n");
    printf("Starting student-record application...\n\n");

    return run_command(RUN_COMMAND);
}
