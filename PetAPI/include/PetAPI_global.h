#ifndef PETAPI_GLOBAL_H
#define PETAPI_GLOBAL_H

#ifdef PETAPI_EXPORT
#  define PETAPI __declspec(dllexport)
#else
#  define PETAPI __declspec(dllimport)
#endif

#include <string>
#include <cstdint>
#include <vector>

#endif // PETAPI_GLOBAL_H
