#pragma once

#ifdef _MSC_VER
#ifdef DO_EXPORTS
#define PUBLIC_API __declspec(dllexport)
#else
#define PUBLIC_API __declspec(dllimport)
#endif
#else
#define PUBLIC_API __attribute__((visibility("default")))
#endif

typedef struct IntegerSet {
    int* arr;
    int n;
}IntegerSet;

PUBLIC_API IntegerSet *CreateSet(int* src, int k);

PUBLIC_API int IsInSet(IntegerSet* array, int n);