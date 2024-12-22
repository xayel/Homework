CXX = g++

CXXFLAGS = -Wall -std=c++2a -O2

LDFLAGS =

TARGET = main

SOURCES = main.cpp

OBJECTS = $(SOURCES:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(LDFLAGS) $(OBJECTS) -o $@

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

report:  
	xelatex report.tex

clean:
	rm -f $(TARGET) $(OBJECTS) report.pdf report.log report.aux

.PHONY: all clean
