


CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g
#CXXFLAGS += O3
#LDFLAGS = -lboost_date_time

OBJS = main.o isValidInput.o menuShell.o tiger.o penguin.o turtle.o bonusAnimal.o animal.o zoo.o

SRCS = isValidInput.cpp menuShell.cpp main.cpp tiger.cpp penguin.cpp turtle.cpp bonusAnimal.cpp animal.cpp zoo.cpp

HEADERS = isValidInput.hpp menuShell.hpp tiger.hpp penguin.hpp turtle.hpp bonusAnimal.hpp animal.hpp zoo.hpp

DOCUMENTS = ZooTycoonDesignReflection.pdf

main: ${OBJS} ${HEADERS}
	${CXX}  ${OBJS} -o main

${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

#zip: lab3_Wellheuser_Phillip.zip ${HEADERS}${SRCS}${DOCUMENTS}
