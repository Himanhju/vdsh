CC = gcc
CCFLAGS = 

all:
	$(CC)  -o vdsh src/shell/shell.c src/main.c src/run/run.c src/file/file.c $(CCFLAGS)

clean:
	rm -f vdsh
