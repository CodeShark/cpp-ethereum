cmake_policy(SET CMP0015 NEW)

aux_source_directory(. SRC_LIST)

include_directories(../libethereum)
link_directories(../libethereum)

add_executable(testsignals ${SRC_LIST})

if (${TARGET_PLATFORM} STREQUAL "w64")
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static-libgcc -static-libstdc++")
        target_link_libraries(testsignals gcc)
        target_link_libraries(testsignals gdi32)
        target_link_libraries(testsignals ws2_32)
        target_link_libraries(testsignals mswsock)
        target_link_libraries(testsignals shlwapi)
        target_link_libraries(testsignals iphlpapi)
        target_link_libraries(testsignals cryptopp)
        target_link_libraries(testsignals boost_system-mt-s)
        target_link_libraries(testsignals boost_filesystem-mt-s)
        target_link_libraries(testsignals boost_thread_win32-mt-s)
        set(CMAKE_SHARED_LIBRARY_LINK_CXX_FLAGS)
else ()
        target_link_libraries(testsignals ${CRYPTOPP_LIBRARIES})
        target_link_libraries(testsignals boost_system)
        target_link_libraries(testsignals boost_filesystem)
        find_package(Threads REQUIRED)
        target_link_libraries(testsignals ${CMAKE_THREAD_LIBS_INIT})
endif ()

if(${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
        include_directories(/usr/local/include)
endif(${CMAKE_SYSTEM_NAME} MATCHES "Darwin")

target_link_libraries(testsignals ethereum)
target_link_libraries(testsignals miniupnpc)
target_link_libraries(testsignals leveldb)
target_link_libraries(testsignals gmp)

install( TARGETS testsignals DESTINATION bin )

