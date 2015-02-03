#version 130
uniform sampler2D texture;
uniform float coeff;

in vec4 fColor;
in vec2 fTexCoord;

out vec4 fragColor;
        
void main() {
    //fragColor=fColor;
    fragColor = texture2D(texture,fTexCoord) * fColor.b;
    fragColor.g*=(1.0-coeff);
}
