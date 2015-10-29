cc = $(CC)
bin = grap
CFLAGS = -O2 -std=c89 -pedantic -Wall -DANSI
.PHONY: all clean
all: $(bin)
$(bin): main.o grap.o
	$(cc) -o $(bin) main.o grap.o
main.o: main.c grap.h
	$(cc) -c $(CFLAGS) main.c
grap.o: grap.c grap.h
	$(cc) -c $(CFLAGS)  grap.c
clean:
	rm -f $(bin) *.o *~

