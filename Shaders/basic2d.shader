#shader vertex
#version 330 core

layout(location = 0) in vec4 position;
layout(location = 1) in vec2 texturePosition;

out vec2 v_textPosition;

void main()
{
   gl_Position = position;
   v_textPosition = texturePosition;
};

#shader fragment
#version 330 core

layout(location = 0) out vec4 color;

in vec2 v_textPosition;

uniform vec4 u_Color;
uniform sampler2D u_Texture;

void main()
{
   vec4 textureColor = texture(u_Texture, v_textPosition);
   color = textureColor;
};