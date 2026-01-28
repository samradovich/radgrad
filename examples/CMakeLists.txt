# Helper function to create examples
function(add_radgrad_example name)
    add_executable(${name} ${name}.cpp)
    target_link_libraries(${name} PRIVATE radgrad::radgrad)
    
    # Optional: Add warnings for examples
    if(MSVC)
        target_compile_options(${name} PRIVATE /W4)
    else()
        target_compile_options(${name} PRIVATE -Wall -Wextra -Wpedantic)
    endif()
endfunction()

add_radgrad_example(main)