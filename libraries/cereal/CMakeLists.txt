add_library(cereal_lib INTERFACE)
include(GNUInstallDirs)
target_include_directories(
        cereal_lib
        INTERFACE
            $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
            $<INSTALL_INTERFACE:./>
)

target_compile_features(
        cereal_lib
        INTERFACE
            cxx_std_17
)