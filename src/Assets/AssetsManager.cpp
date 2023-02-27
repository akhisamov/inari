#include "Inari/Assets/AssetsManager.h"

#include <SDL_filesystem.h>

#include <fstream>

#include "Inari/Assets/Shader.h"
#include "Inari/Assets/ShaderMaker.h"
#include "Inari/Assets/Texture2D.h"
#include "Inari/Assets/Texture2DMaker.h"
#include "Inari/Assets/World.h"
#include "Inari/Assets/WorldMaker.h"

#include <iostream>

namespace inari {
    std::shared_ptr<AssetsManager> AssetsManager::create()
    {
        auto manager = std::make_shared<AssetsManager>(AssetsManager::Token {});
        manager->addSearchPath(".");
        manager->registerMaker<Texture2D>(std::make_unique<Texture2DMaker>());
        manager->registerMaker<Shader>(std::make_unique<ShaderMaker>());
        manager->registerMaker<World>(std::make_unique<WorldMaker>());
        return manager;
    }

    AssetsManager::AssetsManager(AssetsManager::Token /*unused*/) { }
    AssetsManager::~AssetsManager() = default;

    void AssetsManager::addSearchPath(const std::string_view& searchPath, const std::string_view& mountPoint)
    {
        std::filesystem::path absolutePath(SDL_GetBasePath());
        absolutePath += searchPath.data();
        if (is_directory(absolutePath)) {
            m_searchPaths.insert(absolutePath);
        }
    }

    void AssetsManager::addSearchPaths(const std::map<std::string_view, std::string_view>& searchPaths)
    {
        for (const auto& it : searchPaths) {
            addSearchPath(it.first, it.second);
        }
    }

    bool AssetsManager::unload(const std::string_view& name)
    {
        const AssetID id = std::hash<std::string_view> {}(name);
        return m_assets.erase(id) != 0;
    }

    bool AssetsManager::has(const std::string_view& name)
    {
        const AssetID id = std::hash<std::string_view> {}(name);
        return m_assets.find(id) != m_assets.end();
    }

    std::string AssetsManager::readFileData(const std::string_view& filename)
    {
        const auto& it = m_filesDataByName.find(filename.data());
        if (it != m_filesDataByName.end()) {
            return it->second;
        }

        const auto path = findAbsolutePath(filename);
        assert(!path.empty());

        std::ifstream ifs(path, std::ios::ate);
        assert(ifs);

        auto end = ifs.tellg();
        ifs.seekg(0, std::ios::beg);

        auto size = std::size_t(end - ifs.tellg());
        assert(size != 0);

        std::string buffer(size, '\0');
        assert(ifs.read(buffer.data(), buffer.size()));
        ifs.close();

        m_filesDataByName[filename.data()] = buffer;
        return buffer;
    }

    std::filesystem::path AssetsManager::findAbsolutePath(const std::string_view& filename) const
    {
        for (const auto& searchPath : m_searchPaths)
        {
            auto path = searchPath / filename;
            if (exists(path))
            {
                return path;
            }
        }
        return {};
    }
}
