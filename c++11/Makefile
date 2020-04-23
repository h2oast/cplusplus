
CMAKE                        = cmake
RM                           = rm -rf
MACHINE_CORE                 = $(shell cat /proc/cpuinfo | grep "processor" | wc -l)

PROJECT_ROOT                 = $(shell pwd)
THIRDPARTY_ROOT              = $(shell pwd)/..

CXXFLAGS                     = -g -std=c++11



# googletest definations
GOOGLETEST_VERSION           = 1.10.0
GOOGLETEST_SOURCE            = $(THIRDPARTY_ROOT)/googletest-release-$(GOOGLETEST_VERSION)
GOOGLETEST_BUILD             = $(PROJECT_ROOT)/googletest_build
GOOGLETEST_HOME              = $(PROJECT_ROOT)/googletest

.PHONY: all googletest run

all   : learn

# googletest:
# 	$(info "number of cores is $(MACHINE_CORE)")	
# 	@$(CMAKE) -DCMAKE_INSTALL_PREFIX=$(GOOGLETEST_HOME)                   \
# 	          -DCMAKE_INSTALL_LIBDIR=lib                                  \
#                   -DCMAKE_CXX_STANDARD=11                                     \
#                   -B $(GOOGLETEST_BUILD) -S $(GOOGLETEST_SOURCE)
# 	@$(MAKE)  -C $(GOOGLETEST_BUILD) -j $(MACHINE_CORE) # VERBOSE=1
# 	@$(MAKE)  -C $(GOOGLETEST_BUILD) -j $(MACHINE_CORE) install


run : all
	./__build/learn

learn : 
	@$(CMAKE) -DCMAKE_CXX_STANDARD=11                                     \
                  -B ${PROJECT_ROOT}/__build -S .
	@$(MAKE)  -C $(PROJECT_ROOT)/__build  -j $(MACHINE_CORE)  VERBOSE=1

clean : 
	@$(RM)     $(GOOGLETEST_BUILD) $(PROJECT_ROOT)/__build
