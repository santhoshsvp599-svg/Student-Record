student.exe : main.o stud_add.o stud_del.o stud_save.o stud_mod.o stud_sort.o stud_show.o
	gcc -o student.exe main.c stud_add.c stud_del.c stud_save.c stud_mod.c stud_sort.c stud_show.c

main.o : main.c
	gcc -c main.c
stud_add.o : stud_add.c
	gcc -c stud_add.c
stud_del.o : stud_del.c
	gcc -c stud_del.c
stud_save.o : stud_save.c
	gcc -c stud_save.c
stud_mod.o : stud_mod.c
	gcc -c stud_mod.c
stud_sort.o : stud_sort.c
	gcc -c stud_sort.c
stud_show.o : stud_show.c
	gcc -c stud_show.c