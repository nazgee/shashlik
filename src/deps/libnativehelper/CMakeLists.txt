project(nativehelper)

set(REPO_PATH ${NATIVEHELPER_PATH})
set(INC_PATH ${NATIVEHELPER_PATH}/include/nativehelper)

include_directories(
    ${INC_PATH}
    ${LIBLOG_INCLUDE_DIR}
    ${LIBCUTILS_INCLUDE_DIR}
)

add_definitions(
    -fpermissive # To allow cast from char* to int
)

set(SRC
   ${REPO_PATH}/JniConstants.cpp
   ${REPO_PATH}/JNIHelp.cpp
   ${REPO_PATH}/JniInvocation.cpp
   ${REPO_PATH}/toStringArray.cpp
)

set(INC
   ${INC_PATH}/JniConstants.h
   ${INC_PATH}/jni.h
   ${INC_PATH}/JNIHelp.h
   ${INC_PATH}/JniInvocation.h
   ${INC_PATH}/ScopedBytes.h
   ${INC_PATH}/ScopedFd.h
   ${INC_PATH}/ScopedLocalFrame.h
   ${INC_PATH}/ScopedLocalRef.h
   ${INC_PATH}/ScopedPrimitiveArray.h
   ${INC_PATH}/ScopedStringChars.h
   ${INC_PATH}/ScopedUtfChars.h
   ${INC_PATH}/toStringArray.h
   ${INC_PATH}/UniquePtr.h
)

add_library(${PROJECT_NAME} SHARED ${SRC})

target_link_libraries(${PROJECT_NAME}
    ${LIBLOG_LIBRARY}
)

install(TARGETS ${PROJECT_NAME} DESTINATION ${ANDROID_LIB_DIR})
install(FILES ${INC}
        DESTINATION ${CMAKE_INSTALL_PREFIX}/include/nativehelper)
