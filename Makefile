CC ?= gcc
CFLAGS ?= -Wall -Wextra -std=c11

TARGET := out
OBJECTS := main.o stud_add.o stud_del.o stud_sort.o stud_save.o stud_show.o stud_mod.o

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $@

main.o stud_add.o stud_del.o stud_sort.o stud_save.o stud_show.o stud_mod.o: student.h

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJECTS) $(TARGET) $(TARGET).exe
