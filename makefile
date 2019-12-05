CC = g++  # use g++ compiler

FLAGS = -std=c++11  # compile with C++ 11 standard
FLAGS += -Wall      # compile with all warnings

INCLUDE = -I inc  # add include and test dirs to include path
FLAGS += $(INCLUDE)

LINK = $(CC) $(FLAGS) -o  # final linked build to binary executable

COMPILE = $(CC) $(FLAGS) -c  # compilation to inter	mediary .o files

test: clean sub_one sub_two sub_three
	@echo TESTING ONE;
	./sub_one text_files/test.txt
	@echo PRINTING NEW FILE:;
	@cat text_files/test.txt
	@echo TESTING TWO;
	./sub_two text_files/test.txt
	@echo PRINTING NEW FILE:;
	@cat text_files/test.txt
	@echo TESTING THREE;
	./sub_three text_files/test.txt
	@echo PRINTING NEW FILE:;
	@cat text_files/test.txt

build: sub_one sub_two sub_three

sub_one: one.o
	$(LINK) $@ $^

one.o: one/one.cc
	$(COMPILE) $<

sub_two: two.o
	$(LINK) $@ $^

two.o: two/two.cc
	$(COMPILE) $<

sub_three: three.o
	$(LINK) $@ $^

three.o: three/three.cc
	$(COMPILE) $<

clean:
	rm -f sub_one
	rm -f sub_two
	rm -f sub_three
	rm -f *.o
