
varying vec3 viewSpacePosition;
varying vec3 normal;

void main()
{
    gl_FragData[0] = vec4(1, 0, 0, 1) * dot(normal, vec3(1, 1, 0));
    gl_FragData[1] = vec4(1, 1, 0, 1) * dot(normal, vec3(1, 1, 0));
    
}