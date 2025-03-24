cmake_minimum_required(VERSION 3.10)

# Projeto C
project(AnsiDev C)

# Define flags para conformidade com ANSI C
if (MSVC)
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} /Za /O2 /W4")
elseif (${CMAKE_GENERATOR} MATCHES "Xcode")
    set(CMAKE_CXX_STANDARD 11)
    set(CMAKE_CXX_STANDARD_REQUIRED True)
else()
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c++98 -Wall")
endif()

# Encontra todos os arquivos .c na pasta
file(GLOB SOURCE_FILES "src/*.C")

# Para cada arquivo encontrado, cria um executável
foreach(SOURCE_FILE ${SOURCE_FILES})
    get_filename_component(EXEC_NAME ${SOURCE_FILE} NAME_WE)
    set_source_files_properties(${SOURCE_FILE} PROPERTIES LANGUAGE C)
    add_executable(${EXEC_NAME} ${SOURCE_FILE})
endforeach()
