CC = gcc

SRC = main.c contact.c file.c populate.c validation.c
OBJ = $(SRC:.c=.o)
TARGET = addressbook

$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET)

%.o: %.c
	$(CC) -c $<

clean:
	rm -f *.o $(TARGET)