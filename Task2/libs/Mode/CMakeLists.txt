set(LIBRARY_NAME Mode)
set(LIBRARY_HEADERS_DIR include)
set(LIBRARY_HEADERS include/mode.h include/detailed.h include/fast.h include/modeFactory.h)
set(LIBRARY_SOURCE src/mode.cpp src/detailed.cpp src/fast.cpp src/modeFactory.cpp)

add_library(${LIBRARY_NAME} STATIC ${LIBRARY_HEADERS} ${LIBRARY_SOURCE})
target_include_directories(${LIBRARY_NAME} PUBLIC ${LIBRARY_HEADERS_DIR})
target_link_libraries(${LIBRARY_NAME} PUBLIC ${LINK_LIBRARY})

