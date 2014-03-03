uniform mat4 world;
uniform mat4 view;
uniform mat4 proj;

varying vec3 position;

void main()
{
    gl_Position = world * view * proj * gl_Vertex;
}