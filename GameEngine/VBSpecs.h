#ifndef VERTEXBUFFERLAYOUT_H
#define VERTEXBUFFERLAYOUT_H

#include <vector>
#include <GL/glew.h>

struct VBConfig
{
    unsigned int size;
    unsigned int type;
    int norm;
    static unsigned int getSizeType(unsigned int type)
    {
        switch (type)
        {
            case GL_FLOAT: return 4;
            case GL_UNSIGNED_BYTE: return 1;
            case GL_UNSIGNED_INT: return 4;   
        }
        return 0;
    }
};

class VBSpecs
{
    private:
        std::vector<VBConfig> configs;
        unsigned int spacing;

    public:
        VBSpecs():spacing(0)
        {
            
        }
        void pushF(unsigned int count)
        {
            configs.push_back({count, GL_FLOAT, 0});
            spacing += count * VBConfig::getSizeType(GL_FLOAT);
        }
        void pushUI(unsigned int count)
        {
            configs.push_back({count, GL_UNSIGNED_INT, 0});
            spacing += count * VBConfig::getSizeType(GL_UNSIGNED_INT);
        }
        void pushUC(unsigned int count)
        {
            configs.push_back({count, GL_UNSIGNED_BYTE, 0});
            spacing += count * VBConfig::getSizeType(GL_UNSIGNED_BYTE);
        }
        unsigned int GetSpacing()const;
        std::vector<VBConfig> GetConfigs()const;
        ~VBSpecs()
        {

        }
};

#endif