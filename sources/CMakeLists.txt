

set(SOURCE_FILES main.cpp Adder.cpp Adder.h)
add_executable(ZPR_Draughts ${SOURCE_FILES})

if (_ENABLE_TESTS_AT_EACH_BUILD_)
    add_dependencies(ZPR_Draughts runTests)
    endif()