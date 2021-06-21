####

CC = g++
CFLAGS = -c -O3
LDFLAGS =
SOURCES = main.cpp SortLib/MergeSort.cpp SortLib/TreeSort.cpp StringLib/StringLib.cpp
OBJECTS = $(SOURCES:.cpp=.o)
EXECUTABLE = .bin/Onegin

all: $(SOURCES) $(EXECUTABLE) clean

$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) $(LIBS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm $(OBJECTS)


