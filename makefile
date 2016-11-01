.SUFFXIES:.c .o

CC=gcc
SRCS=itoa.c
OBJS=$(SRCS:.c=.o)
EXEC=myitoa
start:$(OBJS)
	$(CC)  -o  $(EXEC)  $(OBJS)
	@echo '^-^-^-^-^-^-^-^ok^-^-^-^-^-^-^-^-^-^'
.c.o:
	$(CC) -Wall -g  -o  $@  -c  $<
clean:
	rm -f $(OBJS)
	rm -f core*
