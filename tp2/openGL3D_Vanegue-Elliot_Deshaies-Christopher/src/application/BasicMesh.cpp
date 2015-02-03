#include "BasicMesh.h"
#include "ObjLoader.h"
#include <vector>
#include <iostream>

using namespace std;
using namespace p3d;

BasicMesh::~BasicMesh() {
  glDeleteBuffers(1,&_attributeBuffer);
  glDeleteBuffers(1,&_elementBuffer);
}


BasicMesh::BasicMesh() {
  _attributeBuffer=0;
  _elementBuffer=0;
}







void BasicMesh::initTetrahedron() {
  std::vector<float> position={
    -1,0,-1, // V0
    1,0,-1,  // V1
    0,1,1,  // V2
    0,-1,1  // V3
  };

  std::vector<float> color={
    1,0,0, // rouge
    0,1,0, // vert
    0,0,1, // bleu
    0,1,1  // magenta
  };

  // index for 4 triangles
  _element={
    0,1,2,0,2,3,0,1,3,1,2,3
  };








  _attribute.clear();
  for(unsigned int i=0;i<position.size()/3;++i) {

    _attribute.push_back(position[i*3+0]);
    _attribute.push_back(position[i*3+1]);
    _attribute.push_back(position[i*3+2]);



    _attribute.push_back(color[i*3+0]);
    _attribute.push_back(color[i*3+1]);
    _attribute.push_back(color[i*3+2]);

  }
}


void BasicMesh::initObj(const ObjLoader &obj) {
  _attribute.clear();
  _element.clear();

  // initialisation de _attribute :
  // - obj.nbFace() = nombre de triangles
  // - obj.positionVertex(i,j) = position du j-ème sommet dans le i-ème triangle (de type Vector3)
  // - obj.normalVertex(i,j) = normale du j-ème sommet dans le i-ième triangle (de type Vector3)
  for(unsigned int i=0;i<obj.nbFace();++i) {
    for(unsigned int j=0;j<3;++j) {

    // TODO

    }
  }


}

void BasicMesh::initBuffer() {
  glGenBuffers(1,&_attributeBuffer);
  glBindBuffer(GL_ARRAY_BUFFER,_attributeBuffer);
  glBufferData(GL_ARRAY_BUFFER,_attribute.size()*sizeof(float),_attribute.data(),GL_STATIC_DRAW);


  glGenBuffers(1,&_elementBuffer);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,_elementBuffer);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER,_element.size()*sizeof(unsigned int),_element.data(),GL_STATIC_DRAW);

}

void BasicMesh::initVAO() {

  glGenVertexArrays(1,&_vao);
  glBindVertexArray(_vao);
  glBindBuffer(GL_ARRAY_BUFFER,_attributeBuffer);


  // TODO



  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,_elementBuffer);

  glBindVertexArray(0);
}

void BasicMesh::initDraw() {
  initBuffer();
  initVAO();
}


void BasicMesh::draw() {
  glBindVertexArray(_vao);

  glDrawElements(GL_TRIANGLES,_element.size(),GL_UNSIGNED_INT,(const GLvoid *)(0*sizeof(GLuint)));

  glBindVertexArray(0);
}


void BasicMesh::updateBuffer() {

}

