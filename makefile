cc = g++
cflags = -Wall -lsfml-graphics -lsfml-window -lsfml-system
objects = SpriteCutter.o

install: $(objects)
	$(cc) -o SpriteCutter $(objects) $(cflags)
	./SpriteCutter

SpriteCutter.o:
	$(cc) -c SpriteCutter.cpp $(cflags)
clean:
	rm *.o
	rm SpriteCutter
	
