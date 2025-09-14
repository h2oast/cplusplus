

all: compile

compile:
	@bazel help test > /dev/null 2>&1                                 || \
	    (echo "[ERROR]: bazel is not installed"; exit 1)
	@bazel build --action_env=BAZEL_CXXOPTS=-std=c++20 //main:machine

check: compile
	@./bazel-bin/main/machine

clean:
	@bazel clean
	@find . -name *~ | xargs $(RM)
