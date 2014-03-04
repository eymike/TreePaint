uniform mat4 world;
uniform mat4 view;
uniform mat4 proj;

varying vec3 viewSpacePosition;
varying vec3 normal;

void main()
{
    mat4 viewWorld = view * world;
    viewSpacePosition = (viewWorld * gl_Vertex).xyz;
    normal = (viewWorld * vec4(gl_Normal, 0)).xyz;
    gl_Position = (proj) * vec4(viewSpacePosition, 1);
}