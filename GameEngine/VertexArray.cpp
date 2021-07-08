#include "VertexArray.h"

void VertexArray::initVertexArray()
{
    glWrap(glGenVertexArrays(1, &vertexArrayID));
}

void VertexArray::Bind()const
{
    glWrap(glBindVertexArray(vertexArrayID));
}

void VertexArray::UnBind()const
{
    glWrap(glBindVertexArray(0));
}

void VertexArray::AddBuffer(const VertexBuffer& vbuffer, const VBSpecs& vbuffer_specs)
{
    Bind();
    vbuffer.Bind();
    const std::vector<VBConfig> configs = vbuffer_specs.GetConfigs();
    unsigned int offValue = 0;
    for(unsigned int i=0; i<configs.size(); i++)
    {

        const VBConfig config = configs[i];
        // std::cout << "Config Size: " << config.size << std::endl;
        // std::cout << "Config Type: " << std::hex << config.type << std::dec << std::endl;
        // std::cout << "Config Norm: " << config.norm << std::endl;
        // std::cout << "Spacing: " << vbuffer_specs.GetSpacing() << std::endl;
        glWrap(glEnableVertexAttribArray(i));
        glWrap(glVertexAttribPointer(i, config.size, config.type, config.norm, vbuffer_specs.GetSpacing(), (const void*)offValue));
        offValue += (config.size * VBConfig::getSizeType(config.type));
    }
}