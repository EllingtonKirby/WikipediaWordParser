COMPILER = g++
FLAGS = -g -Wall -std=c++0x
EXECUTABLE = proj1

all: Driver.o Processor.o
	$(COMPILER) $(FLAGS) -o $(EXECUTABLE) Processor.o Driver.o

Processor.o: Processor.cpp
	$(COMPILER) $(FLAGS) -c Processor.cpp

Driver.o: Driver.cpp
	$(COMPILER) $(FLAGS) -c Driver.cpp

clean:
	rm *.o proj1
