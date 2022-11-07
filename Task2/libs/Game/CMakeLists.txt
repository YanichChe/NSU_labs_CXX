set(LIBRARY_NAME Game)
set(LIBRARY_HEADERS_DIR include)
set(LIBRARY_HEADERS include/game.h)
set(LIBRARY_SOURCE src/game.cpp)

add_library(${LIBRARY_NAME} STATIC ${LIBRARY_HEADERS} ${LIBRARY_SOURCE})
target_include_directories(${LIBRARY_NAME} PUBLIC ${LIBRARY_HEADERS_DIR})
target_link_libraries(${LIBRARY_NAME} PUBLIC ${LINK_LIBRARY})

