find_jar(JARJAR_JAR NAMES jarjar)

# jarjar_process will process a jar file according to the passed rules file, REPLACING the original jar with the
# processed file, renaming the existing jar to the passed new name. This allows us to use the original jar file's
# target name to do linking in other places (e.g. linking framework to conscrypt's jarjared version)
function(jarjar_process _TARGET _RULES _JAR_FILE _NEW_NAME)
    add_custom_command(
        TARGET ${_TARGET}
        POST_BUILD
        COMMENT "Processing ${_TARGET} with JarJar"
        COMMAND cp ${_JAR_FILE} ${_NEW_NAME}
        COMMAND ${Java_JAVA_EXECUTABLE} -jar ${JARJAR_JAR} --rules=${_RULES} ${_NEW_NAME} ${_JAR_FILE}
    )
endfunction()
