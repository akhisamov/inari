add_subdirectory(Systems)

target_sources(inari PRIVATE
        EntityRegistry.cpp
        SystemRegistry.cpp
        )