# Sorting Choice Implementation

## Changes

- The main menu uses `T` or `t` to open the sorting menu.
- The sorting menu accepts:
  - `N` or `n` to sort by name
  - `M` or `m` to sort by marks
- Removed the dependency on `ctype.h` from `stud_sort.c`.
- Lowercase sorting choices are converted manually to uppercase.

## Build and Run

Run these commands from the project directory:

```powershell
gcc -Wall -Wextra -std=c11 -o student.exe main.c stud_add.c stud_del.c stud_mod.c stud_save.c stud_show.c stud_sort.c
.\student.exe
```

## Sorting Usage

1. Select `T` from the main menu.
2. Select `N` to sort by name or `M` to sort by marks.
3. Select `V` from the main menu to save the sorted records.
