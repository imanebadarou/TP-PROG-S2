cmake_minimum_required(VERSION 3.20)
cmake_path(GET CMAKE_CURRENT_SOURCE_DIR FILENAME FolderName)   
string(REPLACE " " "_" FolderName ${FolderName})
project(${FolderName}_Project)

# Trouve tous les fichiers .cpp dans mon répertoire src
file(GLOB_RECURSE CPP_FILES CONFIGURE_DEPENDS src/*.cpp)

message((${CPP_FILES}))

add_executable(${PROJECT_NAME} ${CPP_FILES})
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_23)






