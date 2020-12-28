
uniform vec3 u_lightPos;

vec3 normal;
float intensity;
vec3  lightDir;



void main(void) {
    lightDir        = vec3(u_lightPos[0],u_lightPos[2],u_lightPos[1]);
    lightDir        = normalize(lightDir);
    normal          = normalize(gl_Normal);
    intensity       = dot(lightDir, normal);
    intensity       = max(intensity, 0.0);
    gl_FrontColor   = intensity*gl_Color;
    gl_Position     = gl_ModelViewProjectionMatrix * gl_Vertex;
    
}

