uniform sampler2D texture;
uniform float time;

void main()
{
    // lookup the pixel in the texture
    vec4 pixel = texture2D(texture, vec2((gl_TexCoord[0].x / 2.0) + ((sin(gl_TexCoord[0].y * 3.14 * 2.0 + (time * 2.0)) + 1.0) / 4.0), gl_TexCoord[0].y));

    // multiply it by the color
    gl_FragColor = gl_Color * pixel;
}