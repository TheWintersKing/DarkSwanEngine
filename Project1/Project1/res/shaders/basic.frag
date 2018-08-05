#version 330 core
out vec4 FragColor;

in vec2 tex;

uniform sampler2D ourTex1;
uniform sampler2D ourTex2;
uniform vec4 ourColor;

void main()
{
	FragColor =  mix( texture(ourTex1 , tex) , texture(ourTex2 , tex)  , 0.2) * ourColor;
};