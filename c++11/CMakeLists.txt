##############################################################################
#                                                                            #
#                      build environment requirements                        #
#                                                                            #
##############################################################################
CMAKE_MINIMUM_REQUIRED(VERSION 3.13)

IF (CMAKE_VERSION VERSION_LESS "3.1")
    IF (CMAKE_C_COMPILER_ID STREQUAL "GNU")
        set (CMAKE_C_FLAGS "--std=gnu99 ${CMAKE_C_FLAGS}")
    ENDIF ()
ELSE ()
    set (CMAKE_C_STANDARD 99)
ENDIF ()

set(GOOGLETEST_VERSION 1.10.0)
message(STATUS "Generating build using CMake ${CMAKE_VERSION}")

##############################################################################
#                                                                            #
#                      common building block                                 #
#                                                                            #
##############################################################################
PROJECT("c++ learning" CXX)

SET(CMAKE_CXX_STANDARD 11)
ADD_SUBDIRECTORY(../googletest-release-1.10.0
                 __build_googletest
)

INCLUDE_DIRECTORIES(
    include
)

ADD_LIBRARY(c++11 SHARED src/auto.cpp
)

##############################################################################
#                                                                            #
#                      c++11 test                                            #
#                                                                            #
##############################################################################
ADD_EXECUTABLE(learn
    test/tc_main.cpp
    test/tc_auto.cpp
)

TARGET_LINK_LIBRARIES(learn c++11 pthread gtest)
