LIBS += -l SDL2main -l SDL2 
OBJS = main.o

all: compile link clean

compile:
	g++ -c src/*.cpp

link:
	g++ -o bin/erizos-place $(OBJS) $(LIBS)

clean:
	rm *.o
