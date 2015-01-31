#version 130
uniform float coeff;

in vec3 position;
in vec4 color;
in vec2 texCoord;

out vec4 fColor;
out vec2 fTexCoord;

void main() {
    vec3 newPosition = position * coeff;
    fColor = color;
    fTexCoord = texCoord;
    gl_Position = vec4(newPosition,1.0);
}
