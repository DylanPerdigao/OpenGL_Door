//
//  materials.h
//  CG_Projeto
//
//  Created by Dylan Perdigão on 22/11/2020.
//

#ifndef materials_h
#define materials_h

#define BRASS 0
#define BRONZE 1
#define POLISHED_BRONZE 2
#define CHROME 3
#define COPPER 4
#define POLISHED_COPPER 5
#define GOLD 6
#define POLISHED_GOLD 7
#define TIN 8
#define SILVER 9
#define POLISHED_SILVER 10
#define EMERALD 11
#define JADE 12
#define OBSIDIAN 13
#define PERL 14
#define RUBY 15
#define TURQUOISE 16
#define BLACK_PLASTIC 17
#define CYAN_PLASTIC 18
#define GREEN_PLASTIC 19
#define RED_PLASTIC 20
#define WHITE_PLASTIC 21
#define YELLOW_PLASTIC 22
#define BLACK_RUBBER 23
#define CYAN_RUBBER 24
#define GREEN_RUBBER 25
#define RED_RUBBER 26
#define WHITE_RUBBER 27
#define YELLOW_RUBBER 28
#define GLASS 29

typedef struct Material{
    float *ambient;
    float *diffuse;
    float *specular;
    float shine;
}Material;

GLfloat specularCoef=0;;
int     originalCoef=true;

Material setMaterial(int mat){
    Material material;
    switch(mat){
        case GLASS:
            //Brass
            material.ambient = new float[4]{0.329412f, 0.223529f, 0.027451f,1.0f};
            material.diffuse = new float[4]{ 0.780392f, 0.568627f, 0.113725f, 0.2f };
            material.specular = new float[4]{ 0.992157f, 0.941176f, 0.807843f, 1.0f };
            material.shine = 27.8974f;
            break;
        case BRASS:
            //Brass
            material.ambient = new float[4]{0.329412f, 0.223529f, 0.027451f,1.0f};
            material.diffuse = new float[4]{ 0.780392f, 0.568627f, 0.113725f, 1.0f };
            material.specular = new float[4]{ 0.992157f, 0.941176f, 0.807843f, 1.0f };
            material.shine = 27.8974f;
            break;
        case BRONZE:
            // Bronze
             material.ambient  = new float[4]{ 0.2125f, 0.1275f, 0.054f, 1.0f };
            material.diffuse  = new float[4]{ 0.714f, 0.4284f, 0.18144f, 1.0f };
            material.specular  = new float[4]{ 0.393548f, 0.271906f, 0.166721f, 1.0f };
            material.shine = 25.6f;
            break;
        case POLISHED_BRONZE:
            //Polished bronze
            material.ambient  = new float[4]{0.25f, 0.148f, 0.06475f, 1.0f  };
            material.diffuse  = new float[4]{0.4f, 0.2368f, 0.1036f, 1.0f };
            material.specular  = new float[4]{0.774597f, 0.458561f, 0.200621f, 1.0f };
            material.shine =76.8f ;
            break;
        case CHROME:
            //Chrome
             material.ambient  = new float[4]{0.25f, 0.25f, 0.25f, 1.0f  };
            material.diffuse  = new float[4]{0.4f, 0.4f, 0.4f, 1.0f };
            material.specular  = new float[4]{0.774597f, 0.774597f, 0.774597f, 1.0f };
            material.shine = 76.8f;
            break;
        case COPPER:
            //Copper
             material.ambient  = new float[4]{ 0.19125f, 0.0735f, 0.0225f, 1.0f };
            material.diffuse  = new float[4]{0.7038f, 0.27048f, 0.0828f, 1.0f };
            material.specular  = new float[4]{0.256777f, 0.137622f, 0.086014f, 1.0f };
            material.shine = 12.8f;
            break;
        case POLISHED_COPPER:
            //Polished copper
             material.ambient  = new float[4]{ 0.2295f, 0.08825f, 0.0275f, 1.0f };
            material.diffuse  = new float[4]{0.5508f, 0.2118f, 0.066f, 1.0f };
            material.specular  = new float[4]{0.580594f, 0.223257f, 0.0695701f, 1.0f };
            material.shine =51.2f ;
            break;
        case GOLD:
            //Gold
             material.ambient  = new float[4]{ 0.24725f, 0.1995f, 0.0745f, 1.0f };
            material.diffuse  = new float[4]{0.75164f, 0.60648f, 0.22648f, 1.0f };
            material.specular  = new float[4]{0.628281f, 0.555802f, 0.366065f, 1.0f };
            material.shine =51.2f ;
            break;
        case POLISHED_GOLD:
            //Polished gold
             material.ambient  = new float[4]{ 0.24725f, 0.2245f, 0.0645f, 1.0f };
            material.diffuse  = new float[4]{0.34615f, 0.3143f, 0.0903f, 1.0f };
            material.specular  = new float[4]{ 0.797357f, 0.723991f, 0.208006f, 1.0f};
            material.shine =83.2f ;
            break;
        case TIN:
            //Tin
             material.ambient  = new float[4]{ 0.105882f, 0.058824f, 0.113725f, 1.0f };
            material.diffuse  = new float[4]{0.427451f, 0.470588f, 0.541176f, 1.0f };
            material.specular  = new float[4]{0.333333f, 0.333333f, 0.521569f, 1.0f };
            material.shine = 9.84615f;
            break;
        case SILVER:
            //Silver
             material.ambient  = new float[4]{ 0.19225f, 0.19225f, 0.19225f, 1.0f };
            material.diffuse  = new float[4]{ 0.50754f, 0.50754f, 0.50754f, 1.0f};
            material.specular  = new float[4]{0.508273f, 0.508273f, 0.508273f, 1.0f };
            material.shine = 51.2f;
            break;
        case POLISHED_SILVER:
            //Polished silver
             material.ambient  = new float[4]{ 0.23125f, 0.23125f, 0.23125f, 1.0f };
            material.diffuse  = new float[4]{0.2775f, 0.2775f, 0.2775f, 1.0f };
            material.specular  = new float[4]{0.773911f, 0.773911f, 0.773911f, 1.0f };
            material.shine =89.6f ;
            break;
        case EMERALD:
            //Emerald
             material.ambient  = new float[4]{ 0.0215f, 0.1745f, 0.0215f, 0.55f };
            material.diffuse  = new float[4]{0.07568f, 0.61424f, 0.07568f, 0.55f };
            material.specular  = new float[4]{0.633f, 0.727811f, 0.633f, 0.55f };
            material.shine = 76.8f;
            break;
        case JADE:
            //Jade
             material.ambient  = new float[4]{ 0.135f, 0.2225f, 0.1575f, 0.95f };
            material.diffuse  = new float[4]{0.54f, 0.89f, 0.63f, 0.95f };
            material.specular  = new float[4]{0.316228f, 0.316228f, 0.316228f, 0.95f };
            material.shine = 12.8f;
            break;
        case OBSIDIAN:
            //Obsidian
             material.ambient  = new float[4]{ 0.05375f, 0.05f, 0.06625f, 0.82f };
            material.diffuse  = new float[4]{ 0.18275f, 0.17f, 0.22525f, 0.82f};
            material.specular  = new float[4]{0.332741f, 0.328634f, 0.346435f, 0.82f };
            material.shine =38.4f ;
            break;
        case PERL:
            //Perl
             material.ambient  = new float[4]{ 0.25f, 0.20725f, 0.20725f, 0.922f };
            material.diffuse  = new float[4]{1.0f, 0.829f, 0.829f, 0.922f };
            material.specular  = new float[4]{0.296648f, 0.296648f, 0.296648f, 0.922f };
            material.shine = 11.264f;
            break;
        case RUBY:
            //Ruby
             material.ambient  = new float[4]{ 0.1745f, 0.01175f, 0.01175f, 0.55f };
            material.diffuse  = new float[4]{0.61424f, 0.04136f, 0.04136f, 0.55f };
            material.specular  = new float[4]{0.727811f, 0.626959f, 0.626959f, 0.55f };
            material.shine =76.8f ;
            break;
        case TURQUOISE:
            //Turquoise
             material.ambient  = new float[4]{ 0.1f, 0.18725f, 0.1745f, 0.8f };
            material.diffuse  = new float[4]{0.396f, 0.74151f, 0.69102f, 0.8f };
            material.specular  = new float[4]{0.297254f, 0.30829f, 0.306678f, 0.8f };
            material.shine = 12.8f;
            break;
        case BLACK_PLASTIC:
            //Black plastic
             material.ambient  = new float[4]{0.0f, 0.0f, 0.0f, 1.0f };
            material.diffuse  = new float[4]{0.01f, 0.01f, 0.01f, 1.0f };
            material.specular  = new float[4]{0.50f, 0.50f, 0.50f, 1.0f };
            material.shine =32.0f ;
            break;
        case CYAN_PLASTIC:
            //Cyan plastic
             material.ambient  = new float[4]{ 0.0f,0.1f,0.06f ,1.0f};
            material.diffuse  = new float[4]{ 0.0f,0.50980392f,0.50980392f,1.0f};
            material.specular  = new float[4]{0.50196078f,0.50196078f,0.50196078f,1.0f };
            material.shine =32.0f ;
            break;
        case GREEN_PLASTIC:
            //Green plastic
             material.ambient  = new float[4]{ 0.0f,0.0f,0.0f,1.0f };
            material.diffuse  = new float[4]{ 0.1f,0.35f,0.1f,1.0f};
            material.specular  = new float[4]{0.45f,0.55f,0.45f,1.0f };
            material.shine = 32.0f ;
            break;
        case RED_PLASTIC:
            //Red plastic
             material.ambient  = new float[4]{ 0.0f,0.0f,0.0f,1.0f };
            material.diffuse  = new float[4]{ 0.5f,0.0f,0.0f,1.0f};
            material.specular  = new float[4]{0.7f,0.6f,0.6f,1.0f };
            material.shine =32.0f ;
            break;
        case WHITE_PLASTIC:
            //White plastic
             material.ambient  = new float[4]{ 0.0f,0.0f,0.0f,1.0f };
            material.diffuse  = new float[4]{ 0.55f,0.55f,0.55f,1.0f};
            material.specular  = new float[4]{0.70f,0.70f,0.70f,1.0f };
            material.shine = 32.0f ;
            break;
        case YELLOW_PLASTIC:
            //Yellow plastic
             material.ambient  = new float[4]{0.0f,0.0f,0.0f,1.0f };
            material.diffuse  = new float[4]{0.5f,0.5f,0.0f,1.0f };
            material.specular  = new float[4]{0.60f,0.60f,0.50f,1.0f };
            material.shine = 32.0f ;
            break;
        case BLACK_RUBBER:
            //Black rubber
             material.ambient  = new float[4]{ 0.02f, 0.02f, 0.02f, 1.0f };
            material.diffuse  = new float[4]{ 0.01f, 0.01f, 0.01f, 1.0f};
            material.specular  = new float[4]{0.4f, 0.4f, 0.4f, 1.0f };
            material.shine = 10.0f;
            break;
        case CYAN_RUBBER:
            //Cyan rubber
             material.ambient  = new float[4]{ 0.0f,0.05f,0.05f,1.0f };
            material.diffuse  = new float[4]{0.4f,0.5f,0.5f,1.0f };
            material.specular  = new float[4]{0.04f,0.7f,0.7f,1.0f };
            material.shine = 10.0f;
            break;
        case GREEN_RUBBER:
            //Green rubber
             material.ambient  = new float[4]{ 0.0f,0.05f,0.0f,1.0f };
            material.diffuse  = new float[4]{ 0.4f,0.5f,0.4f,1.0f};
            material.specular  = new float[4]{0.04f,0.7f,0.04f,1.0f };
            material.shine =  10.0f;
            break;
        case RED_RUBBER:
            //Red rubber
             material.ambient  = new float[4]{ 0.05f,0.0f,0.0f,1.0f };
            material.diffuse  = new float[4]{ 0.5f,0.4f,0.4f,1.0f};
            material.specular  = new float[4]{ 0.7f,0.04f,0.04f,1.0f};
            material.shine = 10.0f;
            break;
        case WHITE_RUBBER:
            //White rubber
             material.ambient  = new float[4]{ 0.05f,0.05f,0.05f,1.0f };
            material.diffuse  = new float[4]{ 0.5f,0.5f,0.5f,1.0f};
            material.specular  = new float[4]{ 0.7f,0.7f,0.7f,1.0f};
            material.shine = 10.0f;
            break;
        case YELLOW_RUBBER:
            //Yellow rubber
             material.ambient  = new float[4]{ 0.05f,0.05f,0.0f,1.0f };
            material.diffuse  = new float[4]{0.5f,0.5f,0.4f,1.0f};
            material.specular  = new float[4]{0.7f,0.7f,0.04f,1.0f };
            material.shine = 10.0f;
            break;
    }
    return material;
}
#endif /* materials_h */
