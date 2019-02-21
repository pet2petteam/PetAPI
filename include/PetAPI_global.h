#ifndef PETAPI_GLOBAL_H
#define PETAPI_GLOBAL_H

#ifdef PETAPI_EXPORT
#  define PETAPI __declspec(dllexport)
#else
#  define PETAPI __declspec(dllimport)
#endif

#endif // PETAPI_GLOBAL_H
