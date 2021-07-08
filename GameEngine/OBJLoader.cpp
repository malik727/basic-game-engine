#include "OBJLoader.h"

void OBJLoader::loadModel()
{
    std::fstream objFile;
    objFile.open(this->objFilePath, std::ios::in);
    if(!objFile.is_open())
    {
        std::cout << "Failed to load wavefront obj file at \"" << this->objFilePath << "\"!" << std::endl;
    }
    std::string line;
    int colorCoordNum = 0;
    while(getline(objFile, line))
    {
        std::stringstream ss(line);
        // std::cout << line << std::endl;
        if(line.find("#") != std::string::npos)
        {
            continue;
        }
        if(line.find("v ") != std::string::npos)
        {
            std::string v1, v2, v3;
            ss >> v1;
            ss >> v1;
            ss >> v2;
            ss >> v3;
            vertices.push_back(glm::vec3(stof(v1), stof(v2), stof(v3)));
            // std::cout << "Vertice: " << stof(v1) << " " << stof(v2) << " " << stof(v3) << std::endl;
        }
        else if(line.find("usemtl") != std::string::npos)
        {
            std::string colorGroup;
            ss >> colorGroup;
            ss >> colorGroup;
            std::fstream mtlFile;
            mtlFile.open(this->mtlFilePath, std::ios::in);
            if(!mtlFile.is_open())
            {
                std::cout << "Failed to load wavefront mtl file at \"" << this->objFilePath << "\"!" << std::endl;
            }
            std::string mtline;
            bool found = false;
            while(getline(mtlFile, mtline))
            {
                std::stringstream ss2(mtline);
                if(mtline.find(colorGroup) != std::string::npos)
                {
                    found = true;
                }
                else if(mtline.find("Kd") != std::string::npos && found == true)
                {
                    std::string c1, c2, c3;
                    ss2 >> c1;
                    ss2 >> c1;
                    ss2 >> c2;
                    ss2 >> c3;
                    colorCoords.push_back(glm::vec3(stof(c1), stof(c2), stof(c3)));
                    colorCoordNum++;
                    found = false;
                    break;
                }
            }
        }
        if(line.find("f ") != std::string::npos)
        {
            std::string v1, v2, v3;
            ss >> v1;
            ss >> v1;
            ss >> v2;
            ss >> v3;
            // std::cout << "Face: " << v1 << " " << v2 << " " << v3 << std::endl;
            faces.push_back(glm::vec4(stoi(v1), stoi(v2), stoi(v3), colorCoordNum));
        }
    }
}
/*
    This is a sample fuction showing how to process obj file vertices and make them render ready
*/
float* OBJLoader::generateTokenVertices(int& size)
{
    size = this->faces.size()*3*3*2;
    int k = 0;
    float* vs = new float[size];
    for(int i=0; i<this->faces.size(); i++)
    {
        glm::vec3 tempFace = faces[i];
        std::vector <glm::vec3> v_temp;
        v_temp.push_back(vertices[faces[i].x - 1]); // X
        v_temp.push_back(vertices[faces[i].y - 1]); // Y
        v_temp.push_back(vertices[faces[i].z - 1]); // Z
        for(int j=0; j<3; j++)
        {
            vs[k] = v_temp[j].x*100;
            k++;
            vs[k] = v_temp[j].y*100;
            k++;
            vs[k] = v_temp[j].z*100;
            k++;
            vs[k] = colorCoords[faces[i].w - 1].x;
            k++;
            vs[k] = colorCoords[faces[i].w - 1].y;
            k++;
            vs[k] = colorCoords[faces[i].w - 1].z;
            k++;
            // std::cout << v_temp[j].x/150.0 << " " << v_temp[j].y/150.0 << " " << v_temp[j].z/6.0 << " " << colorCoords[faces[i].w - 1].x << " " << colorCoords[faces[i].w - 1].y << " " << colorCoords[faces[i].w - 1].z << std::endl;
        }
    }
    return vs;
}
std::vector <glm::vec3> OBJLoader::getVertices()const
{
    return this->vertices;
}
std::vector <glm::vec3> OBJLoader::getColorCoords()const
{
    return this->colorCoords;
}