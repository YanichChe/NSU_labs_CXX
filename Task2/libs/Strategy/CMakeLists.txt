set(LIBRARY_NAME Strategy)
set(LIBRARY_HEADERS_DIR include)

set(LIBRARY_HEADERS include/strategy.h include/alwaysCooperate.h
        include/alwaysDefect.h include/random.h
                    include/strategyFactory.h include/titForTat.h
                    include/softGrudger.h
                    include/pavlov.h
                    )

set(LIBRARY_SOURCE  src/alwaysCooperate.cpp
        src/alwaysDefect.cpp
                    src/random.cpp
                    src/strategyFactory.cpp
                    src/titForTat.cpp
                    src/softGrudger.cpp
                    src/pavlov.cpp
                   )

set(TEST_LIBRARY_NAME strategy_tests)
set(TEST_SOURCE test/strategy_tests.cpp)

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