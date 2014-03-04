
varying vec3 viewSpacePosition;
varying vec3 normal;

void main()
{
    gl_FragColor = vec4(1, 0, 0, 1) * dot(normal, vec3(0, 1, 0));
}