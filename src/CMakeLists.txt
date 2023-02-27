add_subdirectory(Assets)
add_subdirectory(ECS)
add_subdirectory(Graphics)
add_subdirectory(Utils)

target_sources(inari PRIVATE
        BaseGame.cpp
        GameServices.cpp
        InputManager.cpp
        )