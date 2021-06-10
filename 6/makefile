
CXX = g++

TARGET = 6.exe

#INCLUDES +=
#LIBS +=

SRCS = 6.cpp
OBJS = $(SRCS:.cpp=.o)

%.o: %.cpp
	$(CXX) -fPIC $(CFLAGS) $(LDFLAGS) $(INCLUDES) $(LIBS) $(CompileFlags) -std=c++11 -g -c -o $@ $<

$(TARGET): $(OBJS)
	$(CXX) -o $@ $(OBJS) $(LIBS) $(LDFLAGS)

all: $(TARGET)

clean:
	rm -rf $(TARGET) *.o *~