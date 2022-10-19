set(LIBRARY_NAME Strategy)
set(LIBRARY_HEADERS_DIR include)
set(LIBRARY_HEADERS include/strategy.h include/alwaysCooperate.h include/alwaysDesert.h include/copyMove.h)
set(LIBRARY_SOURCE src/alwaysCooperate.cpp src/alwaysDesert.cpp src/copyMove.cpp)

add_library(${LIBRARY_NAME} STATIC ${LIBRARY_HEADERS} ${LIBRARY_SOURCE})
target_include_directories(${LIBRARY_NAME} PUBLIC ${LIBRARY_HEADERS_DIR})
target_link_libraries(${LIBRARY_NAME} PUBLIC ${LINK_LIBRARY})

