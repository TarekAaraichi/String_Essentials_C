PROG = main.exe 
SRC = main.c input_utils.c utility_functions.c
CFLAGS = -g
LIBS =

all: $(PROG)

$(PROG): $(SRC)
	$(CC) -o $@ $(CFLAGS) $(LDFLAGS) $(SRC)  $(LIBS) 

clean:
	rm -f $(PROG)

.PHONY: all clean