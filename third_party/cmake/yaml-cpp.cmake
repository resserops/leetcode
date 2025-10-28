if(NOT TARGET yaml-cpp)
    execute_process(COMMAND git submodule update --init --recursive ${3rd_dir}/yaml-cpp)

    set(YAML_CPP_BUILD_CONTRIB OFF CACHE BOOL "Enable yaml-cpp contrib in library" FORCE)
    set(YAML_CPP_BUILD_TOOLS OFF CACHE BOOL "Enable parse tools" FORCE)

    include_directories(SYSTEM ${3rd_dir}/yaml-cpp/include)
    add_subdirectory(${3rd_dir}/yaml-cpp)
endif()
