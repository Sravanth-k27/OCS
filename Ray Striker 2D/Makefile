PATH=/Documents/Sem 2/CS1023/cs1023-sdf-project-team-11-main
INCLUDEDIR=$(PATH)
CC =g++
LIBFLAGS=-lncurses
SRCS = main.cpp ray.cpp level1.cpp level2.cpp level3.cpp level4.cpp level5.cpp level6.cpp/
       level7.cpp level8.cpp
OBJS =$(addsuffix .o,$(basename $(SRCS)))
EXE = raystricker2d
.PHONY = clean all
all = $(EXE) 

$(EXE) : $(OBJS)
	$(CC) -o $@ -L  $(OBJS) $(PATH)

$(OBJS) :%.o :%.cpp
	$(CC) -c -I  $<
	
clean:
	rm $(OBJS) $(EXE)
