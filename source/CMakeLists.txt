# Build example
add_executable(example
  window.cpp
  glew.c
  example.cpp)
target_link_libraries(example
  glfw
  ${GLFW_LIBRARIES}
  nanovg
  ${OPENGL_LIBRARIES})
add_dependencies(example glfw nanovg ${COPY_BINARY})

# Build tests
add_executable(tests
  tests.cpp)
target_link_libraries(tests
  ${GLFW_LIBRARIES})

# Build vec2
add_executable(vec2
  vec2.cpp)

#Build mat2
add_executable(mat2
   mat2.cpp)

#Build color
add_executable(color
   color.cpp)

#Build cirlce
add_executable(circle
   circle.cpp)

#Build rectangle
add_executable(rectangle
   rectangle.cpp)
