#version 130

in vec3 position;
in vec3 color;

out vec3 fColor;

uniform mat4 projection;
uniform mat4 transform;

void main() {

  vec4 eyeProjection = vec4(position, 1);
  eyeProjection = eyeProjection * transform;
  vec4 clipPosition = projection * eyeProjection;

  fColor=color;

  gl_Position=clipPosition;
}
