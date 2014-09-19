#Source files
OBJS = *.cpp */*.cpp */*/*.cpp

#Compiler
CC = g++

#Compiler Flags
COMP_FLAG = -w -std=c++11

#Linker Flags
LINK_FLAG = -lSDL2 -lGLU -lGL

#Name
NAME = windjammers

#Target
all : $(OBJS) 
	$(CC) $(OBJS) $(COMP_FLAG) $(LINK_FLAG) -o $(NAME)