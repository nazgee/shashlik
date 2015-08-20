project(art C ASM)

set(REPO_PATH ${ART_PATH}/runtime)
#set(MODULE_PATH ${REPO_PATH}/runtime)
#set(LIBENC_PATH ${MODULE_PATH}/compiler/codegen/x86/libenc)

include_directories(${REPO_PATH}
#                    ${MODULE_PATH}
#                    ${LIBENC_PATH}
                    ${LIBCUTILS_INCLUDE_DIR}
#                    ${CMAKE_INSTALL_PREFIX}/include/android-libcore #FIXME
                    ${LIBNATIVEHELPER_INCLUDE_DIR}
#                    ${LIBANDROIDCORE_INCLUDEDIRS}
#                    ${LIBANDROIDLIBCORE_INCLUDEDIRS}
                    ${ART_PATH}/sigchainlib
)
#include_directories(SYSTEM ${CMAKE_INSTALL_PREFIX}/include)

# default art gc
add_definitions(-DBUILDING_LIBART)
add_definitions(-DART_BASE_ADDRESS_MIN_DELTA=-0x1000000)
add_definitions(-DART_BASE_ADDRESS_MAX_DELTA=0x1000000)
add_definitions(-DART_BASE_ADDRESS=0x60000000)
include_directories(${CMAKE_SOURCE_DIR}/../libnativehelper/include/nativehelper)
include_directories(${CMAKE_SOURCE_DIR}/fakes/includes)
include_directories(.)
include_directories(${CMAKE_SOURCE_DIR})
include_directories(${CMAKE_SOURCE_DIR}/system/)
include_directories(${CMAKE_SOURCE_DIR}/sigchainlib)
include_directories(${CMAKE_SOURCE_DIR}/cmdline)
#set(SRC_LIST "")
#list(APPEND SRC_LIST ${REPO_PATH}/art_field.cc)
list(APPEND SRC_LIST ${REPO_PATH}/atomic.cc)
list(APPEND SRC_LIST ${REPO_PATH}/barrier.cc)
list(APPEND SRC_LIST ${REPO_PATH}/base/allocator.cc)
#list(APPEND SRC_LIST ${REPO_PATH}/base/arena_allocator.cc)
list(APPEND SRC_LIST ${REPO_PATH}/base/bit_vector.cc)
list(APPEND SRC_LIST ${REPO_PATH}/base/hex_dump.cc)
list(APPEND SRC_LIST ${REPO_PATH}/base/logging.cc)
list(APPEND SRC_LIST ${REPO_PATH}/base/mutex.cc)
#list(APPEND SRC_LIST ${REPO_PATH}/base/scoped_arena_allocator.cc)
list(APPEND SRC_LIST ${REPO_PATH}/base/scoped_flock.cc)
list(APPEND SRC_LIST ${REPO_PATH}/base/stringpiece.cc)
list(APPEND SRC_LIST ${REPO_PATH}/base/stringprintf.cc)
list(APPEND SRC_LIST ${REPO_PATH}/base/timing_logger.cc)
list(APPEND SRC_LIST ${REPO_PATH}/base/unix_file/fd_file.cc)
list(APPEND SRC_LIST ${REPO_PATH}/base/unix_file/mapped_file.cc)
list(APPEND SRC_LIST ${REPO_PATH}/base/unix_file/null_file.cc)
list(APPEND SRC_LIST ${REPO_PATH}/base/unix_file/random_access_file_utils.cc)
list(APPEND SRC_LIST ${REPO_PATH}/base/unix_file/string_file.cc)
list(APPEND SRC_LIST ${REPO_PATH}/check_jni.cc)
list(APPEND SRC_LIST ${REPO_PATH}/class_linker.cc)
list(APPEND SRC_LIST ${REPO_PATH}/common_throws.cc)
list(APPEND SRC_LIST ${REPO_PATH}/debugger.cc)
list(APPEND SRC_LIST ${REPO_PATH}/dex_file.cc)
list(APPEND SRC_LIST ${REPO_PATH}/dex_file_verifier.cc)
list(APPEND SRC_LIST ${REPO_PATH}/dex_instruction.cc)
list(APPEND SRC_LIST ${REPO_PATH}/elf_file.cc)
list(APPEND SRC_LIST ${REPO_PATH}/field_helper.cc)
list(APPEND SRC_LIST ${REPO_PATH}/gc/allocator/dlmalloc.cc)
list(APPEND SRC_LIST ${REPO_PATH}/gc/allocator/rosalloc.cc)
#list(APPEND SRC_LIST ${REPO_PATH}/gc/accounting/bitmap.cc)
list(APPEND SRC_LIST ${REPO_PATH}/gc/accounting/card_table.cc)
list(APPEND SRC_LIST ${REPO_PATH}/gc/accounting/heap_bitmap.cc)
list(APPEND SRC_LIST ${REPO_PATH}/gc/accounting/mod_union_table.cc)
list(APPEND SRC_LIST ${REPO_PATH}/gc/accounting/remembered_set.cc)
list(APPEND SRC_LIST ${REPO_PATH}/gc/accounting/space_bitmap.cc)
list(APPEND SRC_LIST ${REPO_PATH}/gc/collector/concurrent_copying.cc)
list(APPEND SRC_LIST ${REPO_PATH}/gc/collector/garbage_collector.cc)
list(APPEND SRC_LIST ${REPO_PATH}/gc/collector/immune_region.cc)
list(APPEND SRC_LIST ${REPO_PATH}/gc/collector/mark_compact.cc)
list(APPEND SRC_LIST ${REPO_PATH}/gc/collector/mark_sweep.cc)
list(APPEND SRC_LIST ${REPO_PATH}/gc/collector/partial_mark_sweep.cc)
list(APPEND SRC_LIST ${REPO_PATH}/gc/collector/semi_space.cc)
list(APPEND SRC_LIST ${REPO_PATH}/gc/collector/sticky_mark_sweep.cc)
list(APPEND SRC_LIST ${REPO_PATH}/gc/gc_cause.cc)
list(APPEND SRC_LIST ${REPO_PATH}/gc/heap.cc)
list(APPEND SRC_LIST ${REPO_PATH}/gc/reference_processor.cc)
list(APPEND SRC_LIST ${REPO_PATH}/gc/reference_queue.cc)
list(APPEND SRC_LIST ${REPO_PATH}/gc/space/bump_pointer_space.cc)
list(APPEND SRC_LIST ${REPO_PATH}/gc/space/dlmalloc_space.cc)
list(APPEND SRC_LIST ${REPO_PATH}/gc/space/image_space.cc)
list(APPEND SRC_LIST ${REPO_PATH}/gc/space/large_object_space.cc)
list(APPEND SRC_LIST ${REPO_PATH}/gc/space/malloc_space.cc)
#$list(APPEND SRC_LIST ${REPO_PATH}/gc/space/region_space.cc)
list(APPEND SRC_LIST ${REPO_PATH}/gc/space/rosalloc_space.cc)
list(APPEND SRC_LIST ${REPO_PATH}/gc/space/space.cc)
list(APPEND SRC_LIST ${REPO_PATH}/gc/space/zygote_space.cc)
#list(APPEND SRC_LIST ${REPO_PATH}/gc/task_processor.cc)
list(APPEND SRC_LIST ${REPO_PATH}/hprof/hprof.cc)
list(APPEND SRC_LIST ${REPO_PATH}/image.cc)
list(APPEND SRC_LIST ${REPO_PATH}/indirect_reference_table.cc)
list(APPEND SRC_LIST ${REPO_PATH}/instruction_set.cc)
list(APPEND SRC_LIST ${REPO_PATH}/instrumentation.cc)
list(APPEND SRC_LIST ${REPO_PATH}/intern_table.cc)
list(APPEND SRC_LIST ${REPO_PATH}/interpreter/interpreter.cc)
list(APPEND SRC_LIST ${REPO_PATH}/interpreter/interpreter_common.cc)
#list(APPEND SRC_LIST ${REPO_PATH}/interpreter/interpreter_goto_table_impl.cc)
list(APPEND SRC_LIST ${REPO_PATH}/interpreter/interpreter_switch_impl.cc)
#list(APPEND SRC_LIST ${REPO_PATH}/interpreter/unstarted_runtime.cc)
#list(APPEND SRC_LIST ${REPO_PATH}/java_vm_ext.cc)
list(APPEND SRC_LIST ${REPO_PATH}/jdwp/jdwp_event.cc)
list(APPEND SRC_LIST ${REPO_PATH}/jdwp/jdwp_expand_buf.cc)
list(APPEND SRC_LIST ${REPO_PATH}/jdwp/jdwp_handler.cc)
list(APPEND SRC_LIST ${REPO_PATH}/jdwp/jdwp_main.cc)
list(APPEND SRC_LIST ${REPO_PATH}/jdwp/jdwp_request.cc)
list(APPEND SRC_LIST ${REPO_PATH}/jdwp/jdwp_socket.cc)
list(APPEND SRC_LIST ${REPO_PATH}/jdwp/object_registry.cc)
#list(APPEND SRC_LIST ${REPO_PATH}/jni_env_ext.cc)
#list(APPEND SRC_LIST ${REPO_PATH}/jit/jit.cc)
#list(APPEND SRC_LIST ${REPO_PATH}/jit/jit_code_cache.cc)
#list(APPEND SRC_LIST ${REPO_PATH}/jit/jit_instrumentation.cc)
list(APPEND SRC_LIST ${REPO_PATH}/jni_internal.cc)
list(APPEND SRC_LIST ${REPO_PATH}/jobject_comparator.cc)
#list(APPEND SRC_LIST ${REPO_PATH}/linear_alloc.cc)
list(APPEND SRC_LIST ${REPO_PATH}/mem_map.cc)
list(APPEND SRC_LIST ${REPO_PATH}/memory_region.cc)
list(APPEND SRC_LIST ${REPO_PATH}/method_helper.cc)
#list(APPEND SRC_LIST ${REPO_PATH}/mirror/abstract_method.cc)
list(APPEND SRC_LIST ${REPO_PATH}/mirror/art_field.cc)
list(APPEND SRC_LIST ${REPO_PATH}/mirror/art_method.cc)
list(APPEND SRC_LIST ${REPO_PATH}/mirror/array.cc)
list(APPEND SRC_LIST ${REPO_PATH}/mirror/class.cc)
list(APPEND SRC_LIST ${REPO_PATH}/mirror/dex_cache.cc)
#list(APPEND SRC_LIST ${REPO_PATH}/mirror/field.cc)
#list(APPEND SRC_LIST ${REPO_PATH}/mirror/method.cc)
list(APPEND SRC_LIST ${REPO_PATH}/mirror/object.cc)
list(APPEND SRC_LIST ${REPO_PATH}/mirror/reference.cc)
list(APPEND SRC_LIST ${REPO_PATH}/mirror/stack_trace_element.cc)
list(APPEND SRC_LIST ${REPO_PATH}/mirror/string.cc)
list(APPEND SRC_LIST ${REPO_PATH}/mirror/throwable.cc)
list(APPEND SRC_LIST ${REPO_PATH}/monitor.cc)
list(APPEND SRC_LIST ${REPO_PATH}/native_bridge_art_interface.cc)
list(APPEND SRC_LIST ${REPO_PATH}/native/dalvik_system_DexFile.cc)
list(APPEND SRC_LIST ${REPO_PATH}/native/dalvik_system_VMDebug.cc)
list(APPEND SRC_LIST ${REPO_PATH}/native/dalvik_system_VMRuntime.cc)
list(APPEND SRC_LIST ${REPO_PATH}/native/dalvik_system_VMStack.cc)
list(APPEND SRC_LIST ${REPO_PATH}/native/dalvik_system_ZygoteHooks.cc)
list(APPEND SRC_LIST ${REPO_PATH}/native/java_lang_Class.cc)
list(APPEND SRC_LIST ${REPO_PATH}/native/java_lang_DexCache.cc)
list(APPEND SRC_LIST ${REPO_PATH}/native/java_lang_Object.cc)
list(APPEND SRC_LIST ${REPO_PATH}/native/java_lang_Runtime.cc)
list(APPEND SRC_LIST ${REPO_PATH}/native/java_lang_String.cc)
list(APPEND SRC_LIST ${REPO_PATH}/native/java_lang_System.cc)
list(APPEND SRC_LIST ${REPO_PATH}/native/java_lang_Thread.cc)
list(APPEND SRC_LIST ${REPO_PATH}/native/java_lang_Throwable.cc)
list(APPEND SRC_LIST ${REPO_PATH}/native/java_lang_VMClassLoader.cc)
list(APPEND SRC_LIST ${REPO_PATH}/native/java_lang_ref_FinalizerReference.cc)
list(APPEND SRC_LIST ${REPO_PATH}/native/java_lang_ref_Reference.cc)
list(APPEND SRC_LIST ${REPO_PATH}/native/java_lang_reflect_Array.cc)
list(APPEND SRC_LIST ${REPO_PATH}/native/java_lang_reflect_Constructor.cc)
list(APPEND SRC_LIST ${REPO_PATH}/native/java_lang_reflect_Field.cc)
list(APPEND SRC_LIST ${REPO_PATH}/native/java_lang_reflect_Method.cc)
list(APPEND SRC_LIST ${REPO_PATH}/native/java_lang_reflect_Proxy.cc)
list(APPEND SRC_LIST ${REPO_PATH}/native/java_util_concurrent_atomic_AtomicLong.cc)
list(APPEND SRC_LIST ${REPO_PATH}/native/org_apache_harmony_dalvik_ddmc_DdmServer.cc)
list(APPEND SRC_LIST ${REPO_PATH}/native/org_apache_harmony_dalvik_ddmc_DdmVmInternal.cc)
list(APPEND SRC_LIST ${REPO_PATH}/native/sun_misc_Unsafe.cc)
list(APPEND SRC_LIST ${REPO_PATH}/oat.cc)
list(APPEND SRC_LIST ${REPO_PATH}/oat_file.cc)
#list(APPEND SRC_LIST ${REPO_PATH}/oat_file_assistant.cc)
list(APPEND SRC_LIST ${REPO_PATH}/object_lock.cc)
list(APPEND SRC_LIST ${REPO_PATH}/offsets.cc)
list(APPEND SRC_LIST ${REPO_PATH}/os_linux.cc)
list(APPEND SRC_LIST ${REPO_PATH}/parsed_options.cc)
list(APPEND SRC_LIST ${REPO_PATH}/primitive.cc)
list(APPEND SRC_LIST ${REPO_PATH}/quick_exception_handler.cc)
list(APPEND SRC_LIST ${REPO_PATH}/quick/inline_method_analyser.cc)
list(APPEND SRC_LIST ${REPO_PATH}/reference_table.cc)
list(APPEND SRC_LIST ${REPO_PATH}/reflection.cc)
list(APPEND SRC_LIST ${REPO_PATH}/runtime.cc)
#list(APPEND SRC_LIST ${REPO_PATH}/runtime_options.cc)
list(APPEND SRC_LIST ${REPO_PATH}/signal_catcher.cc)
list(APPEND SRC_LIST ${REPO_PATH}/stack.cc)
#list(APPEND SRC_LIST ${REPO_PATH}/stack_map.cc)
list(APPEND SRC_LIST ${REPO_PATH}/thread.cc)
list(APPEND SRC_LIST ${REPO_PATH}/thread_list.cc)
list(APPEND SRC_LIST ${REPO_PATH}/thread_pool.cc)
list(APPEND SRC_LIST ${REPO_PATH}/throw_location.cc)
list(APPEND SRC_LIST ${REPO_PATH}/trace.cc)
list(APPEND SRC_LIST ${REPO_PATH}/transaction.cc)
list(APPEND SRC_LIST ${REPO_PATH}/profiler.cc)
list(APPEND SRC_LIST ${REPO_PATH}/fault_handler.cc)
list(APPEND SRC_LIST ${REPO_PATH}/utf.cc)
list(APPEND SRC_LIST ${REPO_PATH}/utils.cc)
list(APPEND SRC_LIST ${REPO_PATH}/verifier/dex_gc_map.cc)
list(APPEND SRC_LIST ${REPO_PATH}/verifier/instruction_flags.cc)
list(APPEND SRC_LIST ${REPO_PATH}/verifier/method_verifier.cc)
list(APPEND SRC_LIST ${REPO_PATH}/verifier/reg_type.cc)
list(APPEND SRC_LIST ${REPO_PATH}/verifier/reg_type_cache.cc)
list(APPEND SRC_LIST ${REPO_PATH}/verifier/register_line.cc)
list(APPEND SRC_LIST ${REPO_PATH}/well_known_classes.cc)
list(APPEND SRC_LIST ${REPO_PATH}/zip_archive.cc)

file(GLOB GENERATED_ENUMS ${CMAKE_SOURCE_DIR}/generated_enums/*.cc)

list(APPEND SRC_LIST ${REPO_PATH}/arch/context.cc)
#list(APPEND SRC_LIST ${REPO_PATH}/arch/instruction_set.cc)
#list(APPEND SRC_LIST ${REPO_PATH}/arch/instruction_set_features.cc)
list(APPEND SRC_LIST ${REPO_PATH}/arch/memcmp16.cc)
#list(APPEND SRC_LIST ${REPO_PATH}/arch/arm/instruction_set_features_arm.cc)
list(APPEND SRC_LIST ${REPO_PATH}/arch/arm/registers_arm.cc)
#list(APPEND SRC_LIST ${REPO_PATH}/arch/arm64/instruction_set_features_arm64.cc)
list(APPEND SRC_LIST ${REPO_PATH}/arch/arm64/registers_arm64.cc)
#list(APPEND SRC_LIST ${REPO_PATH}/arch/x86/instruction_set_features_x86.cc)
list(APPEND SRC_LIST ${REPO_PATH}/arch/x86/registers_x86.cc)
#list(APPEND SRC_LIST ${REPO_PATH}/arch/mips/instruction_set_features_mips.cc)
list(APPEND SRC_LIST ${REPO_PATH}/arch/mips/registers_mips.cc)
#list(APPEND SRC_LIST ${REPO_PATH}/arch/mips64/instruction_set_features_mips64.cc)
#list(APPEND SRC_LIST ${REPO_PATH}/arch/mips64/registers_mips64.cc)
#list(APPEND SRC_LIST ${REPO_PATH}/arch/x86_64/instruction_set_features_x86_64.cc)
#list(APPEND SRC_LIST ${REPO_PATH}/arch/x86_64/registers_x86_64.cc)
list(APPEND SRC_LIST ${REPO_PATH}/entrypoints/entrypoint_utils.cc)
list(APPEND SRC_LIST ${REPO_PATH}/entrypoints/interpreter/interpreter_entrypoints.cc)
list(APPEND SRC_LIST ${REPO_PATH}/entrypoints/jni/jni_entrypoints.cc)
list(APPEND SRC_LIST ${REPO_PATH}/entrypoints/math_entrypoints.cc)
list(APPEND SRC_LIST ${REPO_PATH}/entrypoints/portable/portable_alloc_entrypoints.cc)
list(APPEND SRC_LIST ${REPO_PATH}/entrypoints/portable/portable_cast_entrypoints.cc)
list(APPEND SRC_LIST ${REPO_PATH}/entrypoints/portable/portable_dexcache_entrypoints.cc)
list(APPEND SRC_LIST ${REPO_PATH}/entrypoints/portable/portable_field_entrypoints.cc)
list(APPEND SRC_LIST ${REPO_PATH}/entrypoints/portable/portable_fillarray_entrypoints.cc)
list(APPEND SRC_LIST ${REPO_PATH}/entrypoints/portable/portable_invoke_entrypoints.cc)
list(APPEND SRC_LIST ${REPO_PATH}/entrypoints/portable/portable_jni_entrypoints.cc)
list(APPEND SRC_LIST ${REPO_PATH}/entrypoints/portable/portable_lock_entrypoints.cc)
list(APPEND SRC_LIST ${REPO_PATH}/entrypoints/portable/portable_thread_entrypoints.cc)
list(APPEND SRC_LIST ${REPO_PATH}/entrypoints/portable/portable_throw_entrypoints.cc)
list(APPEND SRC_LIST ${REPO_PATH}/entrypoints/portable/portable_trampoline_entrypoints.cc)
list(APPEND SRC_LIST ${REPO_PATH}/entrypoints/quick/quick_alloc_entrypoints.cc)
list(APPEND SRC_LIST ${REPO_PATH}/entrypoints/quick/quick_cast_entrypoints.cc)
list(APPEND SRC_LIST ${REPO_PATH}/entrypoints/quick/quick_deoptimization_entrypoints.cc)
list(APPEND SRC_LIST ${REPO_PATH}/entrypoints/quick/quick_dexcache_entrypoints.cc)
list(APPEND SRC_LIST ${REPO_PATH}/entrypoints/quick/quick_field_entrypoints.cc)
list(APPEND SRC_LIST ${REPO_PATH}/entrypoints/quick/quick_fillarray_entrypoints.cc)
list(APPEND SRC_LIST ${REPO_PATH}/entrypoints/quick/quick_instrumentation_entrypoints.cc)
list(APPEND SRC_LIST ${REPO_PATH}/entrypoints/quick/quick_jni_entrypoints.cc)
list(APPEND SRC_LIST ${REPO_PATH}/entrypoints/quick/quick_lock_entrypoints.cc)
list(APPEND SRC_LIST ${REPO_PATH}/entrypoints/quick/quick_math_entrypoints.cc)
list(APPEND SRC_LIST ${REPO_PATH}/entrypoints/quick/quick_thread_entrypoints.cc)
list(APPEND SRC_LIST ${REPO_PATH}/entrypoints/quick/quick_throw_entrypoints.cc)
list(APPEND SRC_LIST ${REPO_PATH}/entrypoints/quick/quick_trampoline_entrypoints.cc)

# Source files that only compile with GCC.
list(APPEND SRC_LIST ${REPO_PATH}/interpreter/interpreter_goto_table_impl.cc)

# FIXME I don't know if this should be compiled?
#LIBART_TARGET_SRC_FILES := \
#  $(LIBART_COMMON_SRC_FILES) \
#  base/logging_android.cc \
#  jdwp/jdwp_adb.cc \
#  monitor_android.cc \
#  runtime_android.cc \
#  thread_android.cc

# FIXME Think about 32 bits too
#LIBART_SRC_FILES_x86 := \
#  arch/x86/context_x86.cc \
#  arch/x86/entrypoints_init_x86.cc \
#  arch/x86/jni_entrypoints_x86.S \
#  arch/x86/memcmp16_x86.S \
#  arch/x86/portable_entrypoints_x86.S \
#  arch/x86/quick_entrypoints_x86.S \
#  arch/x86/thread_x86.cc \
#  arch/x86/fault_handler_x86.cc

list(APPEND SRC_LIST ${REPO_PATH}/arch/x86_64/context_x86_64.cc)
list(APPEND SRC_LIST ${REPO_PATH}/arch/x86_64/entrypoints_init_x86_64.cc)
list(APPEND SRC_LIST ${REPO_PATH}/arch/x86_64/jni_entrypoints_x86_64.S)
list(APPEND SRC_LIST ${REPO_PATH}/arch/x86_64/memcmp16_x86_64.S)
list(APPEND SRC_LIST ${REPO_PATH}/arch/x86_64/portable_entrypoints_x86_64.S)
list(APPEND SRC_LIST ${REPO_PATH}/arch/x86_64/quick_entrypoints_x86_64.S)
list(APPEND SRC_LIST ${REPO_PATH}/arch/x86_64/thread_x86_64.cc)
list(APPEND SRC_LIST ${REPO_PATH}/monitor_pool.cc)
list(APPEND SRC_LIST ${REPO_PATH}/arch/x86/fault_handler_x86.cc)

set_property(SOURCE arch/x86_64/jni_entrypoints_x86_64.S PROPERTY LANGUAGE ASM)
set_property(SOURCE arch/x86_64/memcmp16_x86_64.S PROPERTY LANGUAGE ASM)
set_property(SOURCE arch/x86_64/portable_entrypoints_x86_64.S PROPERTY LANGUAGE ASM)
set_property(SOURCE arch/x86_64/quick_entrypoints_x86_64.S PROPERTY LANGUAGE ASM)

# HOST Files
list(APPEND SRC_LIST ${REPO_PATH}/base/logging_linux.cc)
list(APPEND SRC_LIST ${REPO_PATH}/monitor_linux.cc)
list(APPEND SRC_LIST ${REPO_PATH}/runtime_linux.cc)
list(APPEND SRC_LIST ${REPO_PATH}/thread_linux.cc)

#add_definitions(-DART_USE_PORTABLE_COMPILER=1)
add_definitions(-DIMT_SIZE=64)
add_definitions(-DART_DEFAULT_GC_TYPE_IS_CMS
    -DART_DEFAULT_INSTRUCTION_SET_FEATURES=default
    -DANDROID_SMP=1
    -fno-rtti
    -m64
    #-fvisibility=protected
    #-fstrict-aliasing
    -ggdb3
    # madness
    -fno-exceptions
    -Wa,--noexecstack
    -no-canonical-prefixes
    -O2
    -fno-strict-aliasing
    #-Wno-multichar
    #-msoft-float
    #-ffunction-sections
    #-fdata-sections
    #-funwind-tables
    #-fstack-protector
    #-Wa,--noexecstack
    #-Werror=format-security
    #-fno-short-enums
    #-no-canonical-prefixes
    #-fno-canonical-system-headers
    #-fno-builtin-sin
    #-fno-strict-volatile-bitfields
    #-Wno-psabi
    #-fmessage-length=0
    #-W
    #-Wall
    #-Wno-unused
    #-Winit-self
    #-Wpointer-arith
    #-Werror=return-type
    #-Werror=non-virtual-dtor
    #-Werror=address
    #-Werror=sequence-point
    #-Wstrict-aliasing=2
    #-fgcse-after-reload
    #-frerun-cse-after-loop
    #-frename-registers
    #-fvisibility-inlines-hidden
    #-Wpointer-arith
    #-Os
    #-fomit-frame-pointer
    #-fno-strict-aliasing
    #-Wextra
    #-Wframe-larger-than=1728
)


#target_link_libraries(${PROJECT_NAME} ${CMAKE_BINARY_DIR}/disassembler/libart-disassembler.so)

#target_link_libraries(dvm
#    dex
#    shashlik_jni
#    javacore
#    ${FFI_LIBRARIES})

#install(TARGETS dvm DESTINATION ${ANDROID_LIB_DIR})
#install(FILES
#        ${vm_HEADERS}
#        DESTINATION include/dex)

# dex2oat
#set(REPO_PATH ${ART_PATH}/dex2oat)
include_directories(${REPO_PATH}
#                    ${MODULE_PATH}
#                    ${LIBENC_PATH}
                    ${LIBCUTILS_INCLUDE_DIR}
#                    ${CMAKE_INSTALL_PREFIX}/include/android-libcore #FIXME
                    ${LIBNATIVEHELPER_INCLUDEDIRS}
#                    ${LIBANDROIDCORE_INCLUDEDIRS}
#                    ${LIBANDROIDLIBCORE_INCLUDEDIRS}
                    ${ART_PATH}/sigchainlib
                    ${ART_PATH}/compiler
)

set(ENUMS_SRC
    ${REPO_PATH}/arch/x86_64/registers_x86_64.h
    ${REPO_PATH}/base/allocator.h
    ${REPO_PATH}/base/mutex.h
    ${REPO_PATH}/base/unix_file/fd_file.h
    ${REPO_PATH}/dex_file.h
    ${REPO_PATH}/dex_instruction.h
    ${REPO_PATH}/gc_root.h
    ${REPO_PATH}/gc/collector/gc_type.h
    ${REPO_PATH}/gc/collector_type.h
    ${REPO_PATH}/gc/space/space.h
    ${REPO_PATH}/gc/heap.h
    ${REPO_PATH}/indirect_reference_table.h
    ${REPO_PATH}/instruction_set.h
    ${REPO_PATH}/invoke_type.h
    ${REPO_PATH}/jdwp/jdwp.h
    ${REPO_PATH}/jdwp/jdwp_constants.h
    ${REPO_PATH}/lock_word.h
    ${REPO_PATH}/mirror/class.h
    ${REPO_PATH}/oat.h
    ${REPO_PATH}/quick/inline_method_analyser.h
    ${REPO_PATH}/thread.h
    ${REPO_PATH}/thread_state.h
    ${REPO_PATH}/verifier/method_verifier.h
)

function(generate_enums gf)
    set(generated_files "")
    foreach(src ${ARGN})
        message(SRC: ${src})
        string(REPLACE .h .cc enum_impl ${src})
        string(REPLACE ${REPO_PATH} "" enum_impl ${enum_impl})
        get_filename_component(dir ${enum_impl} DIRECTORY)
        if (dir)
            file(MAKE_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/${dir})
        endif()
        add_custom_command(OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/${enum_impl}
            COMMAND ${ART_PATH}/tools/generate-operator-out.py ${REPO_PATH} ${src} > ${CMAKE_CURRENT_BINARY_DIR}/${enum_impl}
            DEPENDS ${src}
            IMPLICIT_DEPENDS CXX ${src})
        list(APPEND generated_files ${CMAKE_CURRENT_BINARY_DIR}/${enum_impl})
        set_source_files_properties(${CMAKE_CURRENT_BINARY_DIR}/${enum_impl} PROPERTIES GENERATED TRUE)
    endforeach()
    add_custom_target(${PROJECT_NAME}_generated_enums DEPENDS ${generated_files})
    set(${gf} ${generated_files} PARENT_SCOPE)
endfunction()

generate_enums(GENERATED_ENUMS ${ENUMS_SRC})
add_library(${PROJECT_NAME} SHARED ${SRC_LIST} ${GENERATED_ENUMS})
target_link_libraries(${PROJECT_NAME} pthread backtrace nativehelper ziparchive nativebridge utils sigchainlib)
add_dependencies(${PROJECT_NAME} ${PROJECT_NAME}_generated_enums)

