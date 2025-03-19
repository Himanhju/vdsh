CC = clang
CCFLAGS = 

all:
	mkdir bin -p
	$(CC)  -o bin/vdsh src/shell/shell.c src/main.c src/run/run.c src/misc/misc.c $(CCFLAGS)

clean:
	rm -f vdsh
