# Student Record Management System

A menu-driven C application for managing student records. Records are held in a
linked list while the program is running and can be saved to or loaded from
`student.dat`.

## Features

- Add a student with an automatically assigned roll number
- Display all records
- Search and delete records by roll number or name
- Search and modify records by roll number, name, or marks
- Sort records by name or marks
- Save records and load them automatically when the program starts
- Exit with or without saving

## Requirements

- GCC
- GNU Make (optional)

## Build

Using Make:

```sh
make
```

This creates the `out` executable. To remove build outputs:

```sh
make clean
```

Alternatively, compile directly with GCC:

```sh
gcc -Wall -Wextra -std=c11 -o out main.c stud_add.c stud_del.c stud_mod.c stud_save.c stud_show.c stud_sort.c
```

On Windows, run the executable with:

```powershell
.\out.exe
```

On Linux or macOS, run:

```sh
./out
```

## Menu

| Key | Action |
| --- | --- |
| `A` | Add a student |
| `D` | Delete a record |
| `S` | Show all records |
| `M` | Modify a record |
| `V` | Save records |
| `T` | Sort by name or marks |
| `E` | Save and exit, or exit without saving |

Commands accept uppercase or lowercase letters.

## Data file

Selecting `V` writes records to `student.dat` in the current working directory.
The file is created automatically when records are saved and loaded on the next
start. It is a binary file intended for use by this application.

## Source files

- `main.c` — program entry point and menu
- `student.h` — student structure and function declarations
- `stud_add.c` — add records
- `stud_del.c` — delete records
- `stud_mod.c` — modify records
- `stud_show.c` — display records
- `stud_sort.c` — sort records
- `stud_save.c` — save, load, and free records
