#pragma once

#define POTATO_UNUSED(x) do { (void)sizeof(x); } while(0)

#ifdef _WIN32
#  define POTATO_EXPORT __declspec( dllexport )
#else
#  define POTATO_EXPORT
#endif