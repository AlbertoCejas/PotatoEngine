
#ifndef POTATOENGINE_EXPORT_H
#define POTATOENGINE_EXPORT_H

#ifdef POTATOENGINE_STATIC
#  define POTATOENGINE_EXPORT
#  define POTATOENGINE_NO_EXPORT
#else
#  ifndef POTATOENGINE_EXPORT
#    ifdef PotatoEngine_EXPORTS
        /* We are building this library */
#      define POTATOENGINE_EXPORT __declspec(dllexport)
#    else
        /* We are using this library */
#      define POTATOENGINE_EXPORT __declspec(dllimport)
#    endif
#  endif

#  ifndef POTATOENGINE_NO_EXPORT
#    define POTATOENGINE_NO_EXPORT 
#  endif
#endif

#ifndef POTATOENGINE_DEPRECATED
#  define POTATOENGINE_DEPRECATED __declspec(deprecated)
#endif

#ifndef POTATOENGINE_DEPRECATED_EXPORT
#  define POTATOENGINE_DEPRECATED_EXPORT POTATOENGINE_EXPORT POTATOENGINE_DEPRECATED
#endif

#ifndef POTATOENGINE_DEPRECATED_NO_EXPORT
#  define POTATOENGINE_DEPRECATED_NO_EXPORT POTATOENGINE_NO_EXPORT POTATOENGINE_DEPRECATED
#endif

#if 0 /* DEFINE_NO_DEPRECATED */
#  ifndef POTATOENGINE_NO_DEPRECATED
#    define POTATOENGINE_NO_DEPRECATED
#  endif
#endif

#endif /* POTATOENGINE_EXPORT_H */
