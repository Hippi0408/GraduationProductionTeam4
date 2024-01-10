xof 0302txt 0064
template Header {
 <3D82AB43-62DA-11cf-AB39-0020AF71E433>
 WORD major;
 WORD minor;
 DWORD flags;
}

template Vector {
 <3D82AB5E-62DA-11cf-AB39-0020AF71E433>
 FLOAT x;
 FLOAT y;
 FLOAT z;
}

template Coords2d {
 <F6F23F44-7686-11cf-8F52-0040333594A3>
 FLOAT u;
 FLOAT v;
}

template Matrix4x4 {
 <F6F23F45-7686-11cf-8F52-0040333594A3>
 array FLOAT matrix[16];
}

template ColorRGBA {
 <35FF44E0-6C7C-11cf-8F52-0040333594A3>
 FLOAT red;
 FLOAT green;
 FLOAT blue;
 FLOAT alpha;
}

template ColorRGB {
 <D3E16E81-7835-11cf-8F52-0040333594A3>
 FLOAT red;
 FLOAT green;
 FLOAT blue;
}

template IndexedColor {
 <1630B820-7842-11cf-8F52-0040333594A3>
 DWORD index;
 ColorRGBA indexColor;
}

template Boolean {
 <4885AE61-78E8-11cf-8F52-0040333594A3>
 WORD truefalse;
}

template Boolean2d {
 <4885AE63-78E8-11cf-8F52-0040333594A3>
 Boolean u;
 Boolean v;
}

template MaterialWrap {
 <4885AE60-78E8-11cf-8F52-0040333594A3>
 Boolean u;
 Boolean v;
}

template TextureFilename {
 <A42790E1-7810-11cf-8F52-0040333594A3>
 STRING filename;
}

template Material {
 <3D82AB4D-62DA-11cf-AB39-0020AF71E433>
 ColorRGBA faceColor;
 FLOAT power;
 ColorRGB specularColor;
 ColorRGB emissiveColor;
 [...]
}

template MeshFace {
 <3D82AB5F-62DA-11cf-AB39-0020AF71E433>
 DWORD nFaceVertexIndices;
 array DWORD faceVertexIndices[nFaceVertexIndices];
}

template MeshFaceWraps {
 <4885AE62-78E8-11cf-8F52-0040333594A3>
 DWORD nFaceWrapValues;
 Boolean2d faceWrapValues;
}

template MeshTextureCoords {
 <F6F23F40-7686-11cf-8F52-0040333594A3>
 DWORD nTextureCoords;
 array Coords2d textureCoords[nTextureCoords];
}

template MeshMaterialList {
 <F6F23F42-7686-11cf-8F52-0040333594A3>
 DWORD nMaterials;
 DWORD nFaceIndexes;
 array DWORD faceIndexes[nFaceIndexes];
 [Material]
}

template MeshNormals {
 <F6F23F43-7686-11cf-8F52-0040333594A3>
 DWORD nNormals;
 array Vector normals[nNormals];
 DWORD nFaceNormals;
 array MeshFace faceNormals[nFaceNormals];
}

template MeshVertexColors {
 <1630B821-7842-11cf-8F52-0040333594A3>
 DWORD nVertexColors;
 array IndexedColor vertexColors[nVertexColors];
}

template Mesh {
 <3D82AB44-62DA-11cf-AB39-0020AF71E433>
 DWORD nVertices;
 array Vector vertices[nVertices];
 DWORD nFaces;
 array MeshFace faces[nFaces];
 [...]
}

Header{
1;
0;
1;
}

Mesh {
 24;
 36.31900;345.00001;-50.00000;,
 50.00025;345.00001;-50.00000;,
 49.99950;292.75374;-50.00002;,
 21.46515;292.75374;-50.00002;,
 50.00025;345.00001;-50.00000;,
 50.00025;345.00001;50.00000;,
 49.99950;256.65960;49.99998;,
 49.99950;292.75374;-50.00002;,
 50.00025;345.00001;50.00000;,
 36.31900;345.00001;50.00000;,
 21.46515;256.65960;49.99998;,
 49.99950;256.65960;49.99998;,
 36.31900;345.00001;50.00000;,
 36.31900;345.00001;-50.00000;,
 21.46515;292.75374;-50.00002;,
 21.46515;256.65960;49.99998;,
 36.31900;345.00001;50.00000;,
 50.00025;345.00001;50.00000;,
 50.00025;345.00001;-50.00000;,
 36.31900;345.00001;-50.00000;,
 21.46515;292.75374;-50.00002;,
 49.99950;292.75374;-50.00002;,
 49.99950;256.65960;49.99998;,
 21.46515;256.65960;49.99998;;
 
 6;
 4;0,1,2,3;,
 4;4,5,6,7;,
 4;8,9,10,11;,
 4;12,13,14,15;,
 4;16,17,18,19;,
 4;20,21,22,23;;
 
 MeshMaterialList {
  4;
  6;
  0,
  1,
  0,
  2,
  3,
  2;;
  Material {
   0.800000;0.800000;0.800000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
   TextureFilename {
    "texture\\bill002.jpg";
   }
  }
  Material {
   0.800000;0.800000;0.800000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
   TextureFilename {
    "texture\\bill002.jpg";
   }
  }
  Material {
   0.800000;0.800000;0.800000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
   TextureFilename {
    "texture\\Concrete.png";
   }
  }
  Material {
   0.800000;0.800000;0.800000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
   TextureFilename {
    "texture\\Concrete.png";
   }
  }
 }
 MeshNormals {
  6;
  0.000000;0.000000;-1.000000;,
  1.000000;-0.000011;-0.000002;,
  0.000000;-0.000000;1.000000;,
  -0.975057;0.219926;0.029930;,
  0.000000;1.000000;0.000000;,
  0.000000;-0.940605;-0.339503;;
  6;
  4;0,0,0,0;,
  4;1,1,1,1;,
  4;2,2,2,2;,
  4;3,3,3,3;,
  4;4,4,4,4;,
  4;5,5,5,5;;
 }
 MeshTextureCoords {
  24;
  0.731457;-1.313499;,
  0.818645;-1.313499;,
  0.818641;-1.015229;,
  0.636795;-1.015229;,
  0.181366;-1.313542;,
  0.818634;-1.313542;,
  0.818634;-0.809201;,
  0.181366;-1.015265;,
  0.818645;-1.313499;,
  0.731457;-1.313499;,
  0.636795;-0.809170;,
  0.818641;-0.809170;,
  0.859710;0.023860;,
  0.140290;0.023860;,
  0.140290;0.149180;,
  0.859710;0.269230;,
  2.315950;3.000000;,
  3.000013;3.000000;,
  3.000013;-2.000000;,
  2.315950;-2.000000;,
  0.140290;0.423860;,
  0.859710;0.423860;,
  0.859710;0.423860;,
  0.140290;0.423860;;
 }
}
