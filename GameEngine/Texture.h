#ifndef TEXTURE_H
#define TEXTURE_H

#include "ErrorHandler.h"
#include "vendor/STB_Image.h"

class Texture
{
    private:
        unsigned int textureID;
        std::string textureFile;
        unsigned char* localBuffer;
        int width, height, bpp;
    
    public:
        Texture():localBuffer(nullptr),width(0),height(0),bpp(0)
        {
            this->textureID = 0;
        }
        Texture(const std::string& texturePath):textureFile(texturePath),localBuffer(nullptr),width(0),height(0),bpp(0)
        {
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
        void initTexture(const std::string& texturePath);
        void Bind(unsigned int slot = 0)const;
        void UnBind()const;
        int GetWidth()const;
        int GetHeight()const;
        ~Texture()
        {
            glWrap(glDeleteTextures(1, &textureID));
        }
};

#endif