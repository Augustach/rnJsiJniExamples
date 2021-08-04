cmake_minimum_required(VERSION 3.9.0)

include_directories(
        ../../node_modules/react-native/React
        ../../node_modules/react-native/React/Base
        ../../node_modules/react-native/ReactCommon/jsi
)

add_library(rnJsiExamples  # <-- Library name
        SHARED
        # Provides a relative path to your source file(s).
        ../../node_modules/react-native/ReactCommon/jsi/jsi/jsi.cpp
        java-jsi.cpp
)

add_library(rnKotlinJsiExamples  # <-- Library name
        SHARED
        # Provides a relative path to your source file(s).
        ../../node_modules/react-native/ReactCommon/jsi/jsi/jsi.cpp
        kotlin-jsi.cpp
        )


find_library(
        log-lib # Sets the name of the path variable.
        log
)

target_link_libraries(
        rnJsiExamples
        log
        android
)