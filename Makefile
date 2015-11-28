# Project: UniMake: Universal Makefile
# Just change 'BIN' to the desired output name

BIN     = D9mGFXgen
CC      = gcc
CPP     = g++
RC      = windres -O coff
CFLAGS  = -I. -O3 -Wall -pedantic -std=c11 -funroll-loops -ffast-math -fsched-spec-load -fomit-frame-pointer
LDFLAGS = -s -static -static-libgcc -static-libstdc++ -lpthread -L libwinpthread-1.dll
CSRC    = $(wildcard *.c)
CPPSRC  = $(wildcard *.cpp)
DEPS    = $(wildcard *.h) Makefile
OBJ     = $(patsubst %.c,%.o,$(CSRC)) $(patsubst %.cpp,%.o,$(CPPSRC))
RES     = 

%.o: %.cpp $(DEPS)
	$(CPP) -c -o $@ $< $(CFLAGS)
	
%.res: %.rc
	$(RC) $< $@

$(BIN): $(OBJ) $(RES)
	$(CPP) -o $@ $^ $(LDFLAGS)
	UPX --best --lzma $@.exe
	rm *.o

clean:
	rm *.o
