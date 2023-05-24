cmake_minimum_required (VERSION 3.8)

#---- Project Config
project (
	"solas"
	LANGUAGES C
	VERSION 0.1.0
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

	#- GLAD
	include_directories("./dependencies/glad/include")
	file(GLOB_RECURSE GLAD_FILES "./dependencies/glad/src/*.c")

	#- GLFW
	add_subdirectory("./dependencies/glfw")
	include_directories("./dependencies/glfw/include")

add_executable(${PROJECT_NAME} WIN32 ${PROJECT_FILES} ${GLAD_FILES})
target_link_libraries(${PROJECT_NAME} SDL2main SDL2-static opengl32 glfw)

