project(utils)

set(REPO_PATH ${ANDROID_CORE_PATH}/libutils)
set(INC_PATH ${ANDROID_CORE_PATH}/include/utils)

if(NOT THREADS_FOUND)
    find_package(Threads REQUIRED)
endif()

include_directories(
    ${INC_PATH}/../
)

set(SRC
   ${REPO_PATH}/BasicHashtable.cpp
   ${REPO_PATH}/BlobCache.cpp
   ${REPO_PATH}/CallStack.cpp
   ${REPO_PATH}/FileMap.cpp
   ${REPO_PATH}/JenkinsHash.cpp
   ${REPO_PATH}/LinearAllocator.cpp
   ${REPO_PATH}/LinearTransform.cpp
   ${REPO_PATH}/Looper.cpp
   ${REPO_PATH}/Log.cpp
   ${REPO_PATH}/NativeHandle.cpp
   ${REPO_PATH}/Printer.cpp
   ${REPO_PATH}/ProcessCallStack.cpp
   ${REPO_PATH}/PropertyMap.cpp
   ${REPO_PATH}/RefBase.cpp
   ${REPO_PATH}/SharedBuffer.cpp
   ${REPO_PATH}/Static.cpp
   ${REPO_PATH}/StopWatch.cpp
   ${REPO_PATH}/String16.cpp
   ${REPO_PATH}/String8.cpp
   ${REPO_PATH}/SystemClock.cpp
   ${REPO_PATH}/Threads.cpp
   ${REPO_PATH}/Timers.cpp
   ${REPO_PATH}/Tokenizer.cpp
   ${REPO_PATH}/Trace.cpp
   ${REPO_PATH}/Unicode.cpp
   ${REPO_PATH}/VectorImpl.cpp
   ${REPO_PATH}/misc.cpp
)

set(INC
   ${INC_PATH}/AndroidThreads.h
   #    ${INC_PATH}/ashmem.h
   ${INC_PATH}/Atomic.h
   ${INC_PATH}/BasicHashtable.h
   ${INC_PATH}/BitSet.h
   ${INC_PATH}/BlobCache.h
   ${INC_PATH}/ByteOrder.h
   ${INC_PATH}/CallStack.h
   ${INC_PATH}/Compat.h
   ${INC_PATH}/Condition.h
   ${INC_PATH}/Debug.h
   ${INC_PATH}/Endian.h
   ${INC_PATH}/Errors.h
   ${INC_PATH}/FileMap.h
   ${INC_PATH}/Flattenable.h
   ${INC_PATH}/Functor.h
   ${INC_PATH}/JenkinsHash.h
   ${INC_PATH}/KeyedVector.h
   ${INC_PATH}/LinearAllocator.h
   ${INC_PATH}/LinearTransform.h
   ${INC_PATH}/List.h
   ${INC_PATH}/Log.h
   ${INC_PATH}/Looper.h
   ${INC_PATH}/LruCache.h
   ${INC_PATH}/misc.h
   ${INC_PATH}/Mutex.h
   ${INC_PATH}/PropertyMap.h
   ${INC_PATH}/RefBase.h
   ${INC_PATH}/RWLock.h
   ${INC_PATH}/SharedBuffer.h
   ${INC_PATH}/Singleton.h
   ${INC_PATH}/SortedVector.h
   ${INC_PATH}/StopWatch.h
   ${INC_PATH}/String16.h
   ${INC_PATH}/String8.h
   ${INC_PATH}/StrongPointer.h
   ${INC_PATH}/SystemClock.h
   ${INC_PATH}/ThreadDefs.h
   ${INC_PATH}/Thread.h
   ${INC_PATH}/threads.h
   ${INC_PATH}/Timers.h
   ${INC_PATH}/Tokenizer.h
   ${INC_PATH}/Trace.h
   ${INC_PATH}/TypeHelpers.h
   ${INC_PATH}/Unicode.h
   ${INC_PATH}/UniquePtr.h
   ${INC_PATH}/Vector.h
   ${INC_PATH}/VectorImpl.h
)

add_library(${PROJECT_NAME} SHARED ${SRC})
target_link_libraries(${PROJECT_NAME}
    ${CMAKE_THREAD_LIBS_INIT}
    ${LIBCUTILS_LIBRARY}
    ${LIBLOG_LIBRARY}
    ${LIBBACKTRACE_LIBRARY}
)

install(TARGETS ${PROJECT_NAME} DESTINATION ${ANDROID_LIB_DIR})
install(FILES ${INC}
        DESTINATION include/utils)

add_subdirectory(tests)
