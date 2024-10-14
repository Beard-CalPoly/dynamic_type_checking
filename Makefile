BASEDIR := /home/srbeard/courses/csc429-compilers/llvm-install
BINDIR := $(BASEDIR)/bin

CLANG := $(BINDIR)/clang
CLANGPP := $(BINDIR)/clang++
OPT := $(BINDIR)/opt
lld := $(BINDIR)/lld

CBINS := test_shadow_lib.exe demo_dynamic_type_check.exe

all: $(CBINS) 

test_shadow_lib.exe: test_shadow_lib.ll shadowlib.ll
	$(CLANGPP) $^ -o $@

demo_dynamic_type_check.exe: demo_dynamic_type_check.ll shadowlib.ll
	$(CLANGPP) $^ -o $@

shadowlib.ll: shadowlib.cpp
	$(CLANGPP) -S -emit-llvm -o $@ $<

%.ll: %.c
	$(CLANG) -S -emit-llvm -o $@ $<

.PHONY: clean
clean:
	rm -rf *.o *.ll *.s $(CBINS)
