CC=g++
OPTIONS=-Wall -std=c++11
INCLUDES=-I/usr/include/eigen3
VERSION=0.1.0

root=$(shell pwd)

exec_dir=build/bin
doc_dir=build/doc

test_exec_dir=build/test/bin
test_work_dir=build/test/work
test_result_dir=build/test-report

default:
	mkdir -p $(exec_dir)
	$(CC) $(OPTIONS) $(INCLUDES) -o $(exec_dir)/datagram-dump src/examples/datagram-dump.cpp
	$(CC) $(OPTIONS) $(INCLUDES) -o $(exec_dir)/cidco-decoder src/examples/cidco-decoder.cpp

test: default
	mkdir -p $(test_exec_dir)
	$(CC) $(OPTIONS) $(INCLUDES) -o $(test_exec_dir)/tests test/main.cpp
	mkdir -p $(test_result_dir)
	mkdir -p $(test_work_dir)
	cd $(test_work_dir)
	$(root)/$(test_exec_dir)/tests -r junit -o $(test_result_dir)/mbes-lib-test-report.xml

doc:
	rm -rf build/doxygen
	mkdir -p build/doxygen
	doxygen
	mkdir -p $(doc_dir)

clean:
	rm -rf build
	rm *.txt || true
	rm *.svp || true

s7k-datagrams: default
	./build/bin/datagram-dump test/data/s7k/20141016_150519_FJ-Saucier.s7k | grep "Type"|cut -d " " -f 2|sort|uniq -c

.PHONY: all test clean doc
