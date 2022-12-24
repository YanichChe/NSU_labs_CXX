set(LIBRARY_NAME soundProcessor)
set(LIBRARY_HEADERS_DIR include)
set(LIBRARY_HEADERS include/soundProcessor.h)
set(LIBRARY_SOURCE src/soundProcessor.cpp)

add_library(${LIBRARY_NAME} STATIC ${LIBRARY_HEADERS} ${LIBRARY_SOURCE})
target_include_directories(${LIBRARY_NAME} PUBLIC ${LIBRARY_HEADERS_DIR} ${CMAKE_SOURCE_DIR}/libs/WAV/include
        ${CMAKE_SOURCE_DIR}/libs/converter/include)
target_link_libraries(${LIBRARY_NAME} PUBLIC ${LINK_LIBRARY} WAV converter)

set(TEST_LIBRARY_NAME sound_processor_tests)
set(TEST_SOURCE test/sound_processor_tests.cpp)
include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/58d77fa8070e8cec2dc1ed015d66b454c8d78850.zip
)
FetchContent_MakeAvailable(googletest)

add_executable(${TEST_LIBRARY_NAME} ${TEST_SOURCE})
target_link_libraries(${TEST_LIBRARY_NAME} gtest_main ${LIBRARY_NAME})