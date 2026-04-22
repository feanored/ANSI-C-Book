cmake_minimum_required(VERSION 3.10)

# Configura o Clang
if (CLANG AND WIN32)
    set(CMAKE_C_COMPILER "clang")
    set(CMAKE_LINKER "lld-link")

    if (NOT CMAKE_GENERATOR STREQUAL "Ninja")
        message(FATAL_ERROR "Use: cmake .. -DCLANG=1 -G Ninja")
    endif()
endif()

# Release como padrão se não especificado
if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()

# Projeto C
project(AnsiDev C)

# Define flags para conformidade com ANSI C
if (CLANG AND WIN32)
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -O2")
    message(STATUS "Usando CLANG como compilador: ${CMAKE_C_COMPILER}")
elseif (MSVC)
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} /permissive- /O2 /W4")
    set(CMAKE_CXX_STANDARD 11)
elseif (${CMAKE_GENERATOR} MATCHES "Xcode")
    set(CMAKE_CXX_STANDARD 11)
    set(CMAKE_CXX_STANDARD_REQUIRED True)
else() # Linux
    set(CMAKE_C_COMPILER "gcc")
    set(CMAKE_C_STANDARD 99)
    set(CMAKE_C_STANDARD_REQUIRED ON)
    add_compile_options(-Wall -O2)
endif()

# Encontra todos os arquivos .c na pasta
file(GLOB SOURCE_FILES "src/*.c")

# Para cada arquivo encontrado, cria um executável
foreach(SOURCE_FILE ${SOURCE_FILES})
    get_filename_component(EXEC_NAME ${SOURCE_FILE} NAME_WE)
    set_source_files_properties(${SOURCE_FILE} PROPERTIES LANGUAGE C)
    add_executable(${EXEC_NAME} ${SOURCE_FILE})
endforeach()
