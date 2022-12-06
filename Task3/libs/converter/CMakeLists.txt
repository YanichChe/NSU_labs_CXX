set(LIBRARY_NAME converter)
set(LIBRARY_HEADERS_DIR include)

set(LIBRARY_HEADERS include/converter.h
                    include/converterFactory.h
                    include/mix.h
                    include/mute.h)

set(LIBRARY_SOURCE  src/converterFactory.cpp
                    src/mix.cpp
                    src/mute.cpp
        )

add_library(${LIBRARY_NAME} STATIC ${LIBRARY_HEADERS} ${LIBRARY_SOURCE})
target_include_directories(${LIBRARY_NAME} PUBLIC ${LIBRARY_HEADERS_DIR} ${CMAKE_SOURCE_DIR}/libs/WAV/include)
target_link_libraries(${LIBRARY_NAME} PUBLIC ${LINK_LIBRARY} WAV)
