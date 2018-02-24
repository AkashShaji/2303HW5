#CS-2303 PA4

#Akash Created file 02/08/16

CXXFLAGS = -g -Wall -fmessage-length=0

OBJS =  Ants.o Board.o Doodlebugs.o Organism.o qSim.o

all: qSim

qSim: $(OBJS)
	$(CXX) $(CXXFLAGS) -o qSim $(OBJS) $(LIBS)

*.o:*.cpp
	$(CXX) -c $(CXXFLAGS) *.cpp


