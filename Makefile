BASEDIR := /home/srbeard/courses/csc429-compilers/llvm-install
BINDIR := $(BASEDIR)/bin

CLANG := $(BINDIR)/clang
CLANGPP := $(BINDIR)/clang++
OPT := $(BINDIR)/opt
lld := $(BINDIR)/lld

C_SRCS := $(wildcard *.c)
CBINS := $(C_SRCS:%.c=%.exe)

all: $(CBINS) 

%.exe: %.ll shadowlib.ll
	$(CLANGPP) $^ -o $@

shadowlib.ll: shadowlib.cpp
	$(CLANGPP) -S -emit-llvm -o $@ $<

%.ll: %.c
	$(CLANG) -O1 -S -emit-llvm -o $@ $<

.PHONY: clean
clean:
	rm -rf *.o *.ll *.s $(CBINS)
