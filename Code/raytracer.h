#ifndef RAYTRACER_H_
#define RAYTRACER_H_

#include "scene.h"

#include <string>

// Forward declerations
class Light;
class Material;

#include "json/json_fwd.h"

class Raytracer
{
    Scene scene;
    std::string sceneDir;
    int resolution;

    public:

        bool readScene(std::string const &ifname);
        void renderToFile(std::string const &ofname);

    private:

    	void setResolution(int res);
        bool parseObjectNode(nlohmann::json const &node);

        Light parseLightNode(nlohmann::json const &node) const;
        Material parseMaterialNode(nlohmann::json const &node) const;
};

#endif
