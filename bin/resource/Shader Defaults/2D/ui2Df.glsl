#version 330 core

in vec2 uv;

out vec4 fragColor;

uniform vec4 color;
uniform sampler2D tex;
uniform bool useTexture;
uniform bool isText;

void main()
{
	if (useTexture)
    {
        if (!isText)
        {
            fragColor = texture(tex, uv);
        }
        else
        {
            float pixel = texture(tex, uv).x;
            fragColor = vec4(1.0, 1.0, 1.0, pixel);
        }
    }
	else
    {
		fragColor = color;
    }
}
