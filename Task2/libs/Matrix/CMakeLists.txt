set(LIBRARY_NAME Matrix)
set(LIBRARY_HEADERS_DIR include)
set(LIBRARY_HEADERS include/matrix.h)
set(LIBRARY_SOURCE src/matrix.cpp)

set(TEST_LIBRARY_NAME matrix_tests)
set(TEST_SOURCE test/matrix_tests.cpp)

add_library(${LIBRARY_NAME} STATIC ${LIBRARY_HEADERS} ${LIBRARY_SOURCE})
target_include_directories(${LIBRARY_NAME} PUBLIC ${LIBRARY_HEADERS_DIR} ${CMAKE_SOURCE_DIR}/libs/Strategy/include)
target_link_libraries(${LIBRARY_NAME} PUBLIC ${LINK_LIBRARY})

include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/58d77fa8070e8cec2dc1ed015d66b454c8d78850.zip
)
FetchContent_MakeAvailable(googletest)

add_executable(${TEST_LIBRARY_NAME} ${TEST_SOURCE})

target_include_directories(${TEST_LIBRARY_NAME} PUBLIC ${LIBRARY_HEADERS_DIR})
target_link_libraries(${TEST_LIBRARY_NAME} gtest_main ${LIBRARY_NAME})