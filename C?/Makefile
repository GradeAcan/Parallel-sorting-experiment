CC = gcc
CXX = g++
CFLAGS = -O3 -march=native
CXXFLAGS = -O3 -march=native
LDFLAGS = -ltbb

TARGET = parallel
OBJS = newtest.o sort.o

$(TARGET): $(OBJS)
	$(CXX) $(OBJS) -o $(TARGET) $(LDFLAGS)

newtest.o: newtest.c
	$(CC) $(CFLAGS) -c newtest.c -o newtest.o

sort.o: sort.cpp
	$(CXX) $(CXXFLAGS) -c sort.cpp -o sort.o

clean:
	rm -f $(OBJS) $(TARGET)