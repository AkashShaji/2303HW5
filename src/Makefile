#CS-2303 PA4

#Akash Created file 02/08/16

CXXFLAGS = -g -Wall -fmessage-length=0

OBJS =  Ant.o Board.o Doodlebug.o Organism.o PA5.o

all: PA5

PA5: $(OBJS)
	$(CXX) $(CXXFLAGS) -o PA5 $(OBJS) $(LIBS)

*.o:*.cpp
	$(CXX) -c $(CXXFLAGS) *.cpp

clean:
	rm -rf *.o
	rm -f PA5
