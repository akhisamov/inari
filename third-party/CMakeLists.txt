# ---------------------------
#             SDL
# ---------------------------

FetchContent_Declare(
        SDL2
        GIT_REPOSITORY https://github.com/libsdl-org/SDL
        GIT_TAG release-2.26.0
        GIT_PROGRESS TRUE
)

FetchContent_MakeAvailable(SDL2)
target_link_libraries(inari PUBLIC SDL2main SDL2-static)

# ---------------------------
#             stb
# ---------------------------

target_include_directories(inari PRIVATE stb)


# ---------------------------
#            GLAD
# ---------------------------

add_subdirectory(glad)
target_link_libraries(inari PRIVATE glad)

# ---------------------------
#            json
# ---------------------------

FetchContent_Declare(
        json
        GIT_REPOSITORY https://github.com/nlohmann/json
        GIT_TAG v3.11.2
        GIT_PROGRESS TRUE
)

FetchContent_MakeAvailable(json)
target_link_libraries(inari PRIVATE nlohmann_json::nlohmann_json)