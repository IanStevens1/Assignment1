CC=g++
CXXFLAGS = -std=c++11

LIBDIR=-L./
LIBS = -ltokenlib
LDFLAGS=$(LIBDIR) $(LIBS)
SOURCES=driver.cpp cmdline_parser.cpp studentrecord.cpp database.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=driver


all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC)  $(OBJECTS) $(CXXFLAGS) -lboost_program_options -o $(EXECUTABLE) $(LDFLAGS) -Wl,-rpath=./

run:
	./driver -f ./students.txt

clean:
	$(RM) *.o $(EXECUTABLE)

