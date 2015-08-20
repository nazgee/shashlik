

set(UNWINDARCH unwind-${CMAKE_SYSTEM_PROCESSOR})

find_path(LIBUNWIND_INCLUDE_DIR unwind.h)
find_library(LIBUNWIND_LIBRARY NAMES unwind)
find_library(LIBUNWIND_LIBRARY_ARCH NAMES ${UNWINDARCH})
find_library(LIBUNWIND_PTRACE_LIBRARY NAMES unwind-ptrace)

if(LIBUNWIND_INCLUDE_DIR AND LIBUNWIND_PTRACE_LIBRARY AND (LIBUNWIND_LIBRARY OR LIBUNWIND_LIBRARY_ARCH))
   # assuming we're not cross-compiling, arch-specific lib is better
   # hence overwrited the library name
   if (LIBUNWIND_LIBRARY_ARCH)
      set(LIBUNWIND_LIBRARY ${LIBUNWIND_LIBRARY_ARCH})
   endif()
   set(UNWIND_FOUND TRUE)
endif()

if(NOT UNWIND_FOUND)
    if(UNWIND_FIND_REQUIRED)
       message(FATAL_ERROR "Could not find UNWIND library")
    endif()
endif()

mark_as_advanced(LIBUNWIND_LIBRARY LIBUNWIND_INCLUDE_DIR LIBUNWIND_PTRACE_LIBRARY)
