EXENAME = project
OBJS = TwitterGraph.o Parser.o main.cpp

CXX = clang++
CXXFLAGS = $(CS225) -std=c++1y -stdlib=libc++ -c -g -O0 -Wall -Wextra -pedantic
LD = clang++
LDFLAGS = -std=c++1y -stdlib=libc++ -lc++abi -lm

# Custom Clang version enforcement logic:
ccred=$(shell echo -e "\033[0;31m")
ccyellow=$(shell echo -e "\033[0;33m")
ccend=$(shell echo -e "\033[0m")

IS_EWS=$(shell hostname | grep "ews.illinois.edu") 
IS_CORRECT_CLANG=$(shell clang -v 2>&1 | grep "version 6")
ifneq ($(strip $(IS_EWS)),)
ifeq ($(strip $(IS_CORRECT_CLANG)),)
CLANG_VERSION_MSG = $(error $(ccred) On EWS, please run 'module load llvm/6.0.1' first when running CS225 assignments. $(ccend))
endif
else
ifneq ($(strip $(SKIP_EWS_CHECK)),True)
CLANG_VERSION_MSG = $(warning $(ccyellow) Looks like you are not on EWS. Be sure to test on EWS before the deadline. $(ccend))
endif
endif



all : $(EXENAME)

output_msg: ; $(CLANG_VERSION_MSG)

$(EXENAME) : output_msg $(OBJS)
	$(LD) $(OBJS) $(LDFLAGS) -o $(EXENAME)

TwitterGraph.o : TwitterGraph.h TwitterGraph.cpp
	$(CXX) $(CXXFLAGS) TwitterGraph.cpp

Parser.o: Parser.h Parser.cpp
	$(CXX) $(CXXFLAGS) Parser.cpp


test: output_msg tests.o TwitterGraph.o Parser.o floyd-warshall.o
	$(LD) tests.o TwitterGraph.o Parser.o floyd-warshall.o $(LDFLAGS) -o test

tests.o : tests/tests.cpp catch/catch.hpp
	$(CXX) $(CXXFLAGS) tests/tests.cpp

.PHONY: all test clean output_msg


clean :
	-rm -f *.o $(EXENAME) test
