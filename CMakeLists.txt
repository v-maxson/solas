cmake_minimum_required (VERSION 3.8)

#---- Project Config
project (
	"solas"
	LANGUAGES C
)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

#---- Compilation
	#- Project Files
	file(GLOB_RECURSE PROJECT_FILES ./src/*.c ./src/*.h)

	#- SDL2
	add_subdirectory("./dependencies/SDL2")
	include_directories("./dependencies/SDL2/include")

add_executable(${PROJECT_NAME} WIN32 ${PROJECT_FILES})
target_link_libraries(${PROJECT_NAME} SDL2main SDL2-static)

