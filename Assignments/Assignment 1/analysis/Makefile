# automatic variables defined by Make:
#
#   $@	File name of the rule's target
#   $%	The target member's name, if the rule's target is an archive
#   $<	File name of the first prerequisite
#   $^	List of all prerequisites
#   $?	List of all prerequisites that are newer than the target
#   $*	The "stem" of an implicit or pattern rule

#
# for details, see   https://www.gnu.org/software/make/manual/html_node/Automatic-Variables.html
#                    https://riptutorial.com/makefile/example/21469/automatic-variables

# identify compiler
CC = g++

objects = run1.o run2.o run3.o run4.o run5.o
LoopObjects = $(wildcard Loop*.o)

TestAnalysis: TestAnalysis.cpp $(objects)
	$(CC) TestAnalysis.cpp   $(objects) -o TestAnalysis

%.o: %.cpp
	$(CC) -c $<


clean:
	rm *.o TestAnalysis
