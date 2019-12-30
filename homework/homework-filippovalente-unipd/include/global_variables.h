//global_variables.h
#ifndef global_variables_h
#define gloval_variable_h

#include <mutex>
using std::mutex;
#include "Park.h"

extern const int cap{10};
extern Park park;
extern mutex m;
extern int i{0};

#endif 