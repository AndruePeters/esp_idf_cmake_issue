set(elf_file ${CMAKE_PROJECT_NAME}.elf)
add_executable(${elf_file} app.cpp )

# Link the static libraries to the executable
target_link_libraries(${elf_file} hal_gpio wifi)

# Attach additional targets to the executable file for flashing,
# linker script generation, partition_table generation, etc.
idf_build_executable(${elf_file})
