include ../z3/build/config.mk

all: z3server.out main.out

main.out: main.cc z3client.cc z3client.h 
	$(CXX) $(EBPF_FLAG) $(CXXFLAGS) $(OS_DEFINES) $(EXAMP_DEBUG_FLAG) $(CXX_OUT_FLAG)main.o  -I../z3/src/api -I../z3/src/api/c++ main.cc
	g++ -std=c++11 main.o z3client.cc -o main.out ../z3/build/libz3$(SO_EXT) $(LINK_EXTRA_FLAGS)

z3server.out: z3server.cc
	$(CXX) $(CXXFLAGS) $(OS_DEFINES) $(CXX_OUT_FLAG) z3server.o -I../z3/src/api -I../z3/src/api/c++ z3server.cc
	$(CXX) z3server.o -o z3server.out ../z3/build/libz3$(SO_EXT) $(LINK_EXTRA_FLAGS)

clean:
	for i in */; do find . -name "*.o" -delete; done
	for i in */; do find . -name "*.out" -delete; done