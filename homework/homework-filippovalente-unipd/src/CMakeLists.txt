find_package(Threads)
add_executable(main main.cpp)

target_link_libraries(main PRIVATE mylib ${CMAKE_THREAD_LIBS_INIT})
