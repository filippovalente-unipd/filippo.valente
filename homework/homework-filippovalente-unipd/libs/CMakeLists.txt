add_library(mylib SHARED Auto.cpp Date_&_hour.cpp Park.cpp)

target_include_directories(mylib PUBLIC ../include)

add_compile_options(-Wall -Weextra -pedantic -Werror)