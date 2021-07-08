#include "Texture.h"

void Texture::Bind(unsigned int slot)const
{
    glWrap(glActiveTexture(GL_TEXTURE0 + slot));
    glWrap(glBindTexture(GL_TEXTURE_2D, textureID));
}

void Texture::initTexture(const std::string& texturePath)
{
    this->textureFile = texturePath;
    stbi_set_flip_vertically_on_load(1);
    localBuffer = stbi_load(texturePath.c_str(), &width, &height, &bpp, 4);
    glWrap(glGenTextures(1, &textureID));
    glWrap(glBindTexture(GL_TEXTURE_2D, textureID));
    glWrap(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR));
    glWrap(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR));
    glWrap(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE));
    glWrap(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE));
    glWrap(glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, localBuffer));
    glWrap(glBindTexture(GL_TEXTURE_2D, 0));
    if(localBuffer)
    {
        stbi_image_free(localBuffer);
    }
}

void Texture::UnBind()const
{
    glWrap(glBindTexture(GL_TEXTURE_2D, 0));
}

int Texture::GetWidth()const
{
    return width;
}

int Texture::GetHeight()const
{
    return height;
}