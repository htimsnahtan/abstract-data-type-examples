CXX = g++
CXXFLAGS = -std=c++0x

OBJS = main.o libraryFunctions.o Queue.o Stack.o

SRCS = main.cpp libraryFunctions.cpp Queue.cpp Stack.cpp

HEADERS = libraryFunctions.hpp Queue.hpp Stack.hpp

FILE = program

${FILE}: ${OBJS} ${HEADERS}
	${CXX} ${SRCS} -o ${FILE}
	
${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)
	
clean:
	rm ${OBJS}