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
 28;
 6.38354;67.66286;-25.00013;,
 6.38354;62.80512;-9.92300;,
 -3.62226;51.89630;-9.92300;,
 -3.62226;56.75407;-25.00013;,
 6.38354;53.96112;9.92275;,
 -7.28444;43.05232;9.92275;,
 6.38466;47.98794;24.99987;,
 -4.93569;27.86412;24.99987;,
 -24.99921;47.98804;24.99987;,
 -25.00034;53.96119;9.92275;,
 -7.28444;43.05232;9.92275;,
 -4.93569;27.86412;24.99987;,
 -25.00034;62.80519;-9.92300;,
 -3.62226;51.89630;-9.92300;,
 -25.00034;67.66294;-25.00013;,
 -3.62226;56.75407;-25.00013;,
 6.38354;53.96112;9.92275;,
 -25.00034;53.96119;9.92275;,
 6.38354;62.80512;-9.92300;,
 -25.00034;62.80519;-9.92300;,
 6.38354;67.66286;-25.00013;,
 -25.00034;67.66294;-25.00013;,
 -4.93569;27.86412;24.99987;,
 6.38466;47.98794;24.99987;,
 -24.99921;47.98804;24.99987;,
 -3.62226;56.75407;-25.00013;,
 -25.00034;67.66294;-25.00013;,
 6.38354;67.66286;-25.00013;;
 
 11;
 4;0,1,2,3;,
 4;1,4,5,2;,
 4;4,6,7,5;,
 4;8,9,10,11;,
 4;9,12,13,10;,
 4;12,14,15,13;,
 4;8,6,16,17;,
 4;17,16,18,19;,
 4;19,18,20,21;,
 3;22,23,24;,
 3;25,26,27;;
 
 MeshMaterialList {
  4;
  11;
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  0,
  0;;
  Material {
   0.800000;0.800000;0.800000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
   TextureFilename {
    "texture\\bill005.jpg";
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
  Material {
   0.800000;0.800000;0.800000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
   TextureFilename {
    "texture\\bill005.jpg";
   }
  }
 }
 MeshNormals {
  14;
  -0.436891;-0.856172;-0.275854;,
  0.720071;-0.660465;-0.212798;,
  0.690096;-0.684177;-0.235942;,
  0.674193;-0.653962;-0.343216;,
  0.682794;-0.594756;-0.424331;,
  -0.558305;-0.714186;-0.422177;,
  -0.504642;-0.758635;-0.412079;,
  -0.443727;-0.829696;-0.338692;,
  0.000003;0.929698;0.368322;,
  0.000002;0.921756;0.387771;,
  0.000002;0.933961;0.357375;,
  0.000002;0.951816;0.306669;,
  0.000000;-0.000000;1.000000;,
  0.000000;0.000000;-1.000000;;
  11;
  4;1,2,2,1;,
  4;2,3,3,2;,
  4;3,4,4,3;,
  4;5,6,6,5;,
  4;6,7,7,6;,
  4;7,0,0,7;,
  4;8,8,9,9;,
  4;9,9,10,10;,
  4;10,10,11,11;,
  3;12,12,12;,
  3;13,13,13;;
 }
 MeshTextureCoords {
  28;
  0.000000;0.000000;,
  0.333330;0.000000;,
  0.333330;1.000000;,
  0.000000;1.000000;,
  0.666670;0.000000;,
  0.666670;1.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;0.000000;,
  0.333330;0.000000;,
  0.333330;1.000000;,
  0.000000;1.000000;,
  0.666670;0.000000;,
  0.666670;1.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  1.000000;0.333330;,
  0.000000;0.333330;,
  1.000000;0.666670;,
  0.000000;0.666670;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.424066;0.788908;,
  0.598226;0.636455;,
  0.115397;0.636454;,
  0.444273;0.570045;,
  0.115379;0.487402;,
  0.598208;0.487403;;
 }
}
