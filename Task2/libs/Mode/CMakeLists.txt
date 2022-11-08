set(LIBRARY_NAME Mode)
set(LIBRARY_HEADERS_DIR include)
set(LIBRARY_HEADERS include/mode.h include/detailed.h include/fast.h include/modeFactory.h)
set(LIBRARY_SOURCE src/mode.cpp src/detailed.cpp src/fast.cpp src/modeFactory.cpp)

set(TEST_LIBRARY_NAME modes_tests)
set(TEST_SOURCE test/modes_tests.cpp)

add_library(${LIBRARY_NAME} STATIC ${LIBRARY_HEADERS} ${LIBRARY_SOURCE})
target_include_directories(${LIBRARY_NAME} PUBLIC ${LIBRARY_HEADERS_DIR})
target_link_libraries(${LIBRARY_NAME} PUBLIC ${LINK_LIBRARY})

include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/58d77fa8070e8cec2dc1ed015d66b454c8d78850.zip
)
FetchContent_MakeAvailable(googletest)

add_executable(${TEST_LIBRARY_NAME} ${TEST_SOURCE})
target_link_libraries(${TEST_LIBRARY_NAME} gtest_main ${LIBRARY_NAME})

target_include_directories(${LIBRARY_NAME} PUBLIC ${CMAKE_SOURCE_DIR}/libs/Strategy/include ${CMAKE_SOURCE_DIR}/libs/GameData/include)
target_link_directories(${LIBRARY_NAME} PUBLIC  ${CMAKE_BINARY_DIR}/libs/Strategy ${CMAKE_BINARY_DIR}/libs/GameData)
target_link_libraries(${LIBRARY_NAME} PUBLIC Strategy GameData)

