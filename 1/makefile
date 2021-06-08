
CXX = g++

TARGET = 1.exe

#INCLUDES +=
#LIBS +=

SRCS = 1.cpp
OBJS = $(SRCS:.cpp=.o)

%.o: %.cpp
	$(CXX) -fPIC $(CFLAGS) $(LDFLAGS) $(INCLUDES) $(LIBS) $(CompileFlags) -g -c -o $@ $<

$(TARGET): $(OBJS)
	$(CXX) -o $@ $(OBJS) $(LIBS) $(LDFLAGS)

all: $(TARGET)

clean:
	rm -rf $(TARGET) *.o *~