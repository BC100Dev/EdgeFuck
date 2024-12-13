CollectSources(${PROJECT_MODULE_ROOT} MOD_SOURCES)

add_executable(EdgeFuck ${MOD_SOURCES})
target_link_libraries(EdgeFuck PRIVATE EF_shared)