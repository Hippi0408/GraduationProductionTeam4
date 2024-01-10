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
 23.22950;158.60492;-50.00002;,
 23.22950;146.38361;-23.23002;,
 -13.17955;118.93971;-23.23002;,
 -13.17955;131.16101;-50.00002;,
 23.22950;124.13425;23.22998;,
 11.88425;96.69036;23.22998;,
 23.22950;109.10696;49.99998;,
 0.58425;88.17906;49.99998;,
 -50.00050;109.10696;49.99998;,
 -50.00050;124.13425;23.22998;,
 11.88425;96.69036;23.22998;,
 0.58425;88.17906;49.99998;,
 -50.00050;146.38361;-23.23002;,
 -13.17955;118.93971;-23.23002;,
 -50.00050;158.60492;-50.00002;,
 -13.17955;131.16101;-50.00002;,
 23.22950;124.13425;23.22998;,
 -50.00050;124.13425;23.22998;,
 23.22950;146.38361;-23.23002;,
 -50.00050;146.38361;-23.23002;,
 23.22950;158.60492;-50.00002;,
 -50.00050;158.60492;-50.00002;,
 0.58425;88.17906;49.99998;,
 23.22950;109.10696;49.99998;,
 -50.00050;109.10696;49.99998;,
 -13.17955;131.16101;-50.00002;,
 -50.00050;158.60492;-50.00002;,
 23.22950;158.60492;-50.00002;;
 
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
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  0,
  0;;
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
  14;
  -0.561188;-0.752936;-0.343738;,
  0.565515;-0.750252;-0.342513;,
  0.631702;-0.655883;-0.413244;,
  0.768324;-0.573137;-0.284944;,
  0.816550;-0.571570;-0.080949;,
  -0.353818;-0.825365;-0.439983;,
  -0.419488;-0.830649;-0.366131;,
  -0.522102;-0.791858;-0.316812;,
  0.000000;0.872004;0.489498;,
  0.000000;0.887425;0.460951;,
  0.000000;0.905837;0.423627;,
  0.000000;0.909685;0.415299;,
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
  0.503723;0.152674;,
  0.648039;0.033198;,
  0.181353;0.033198;,
  0.416008;-0.092707;,
  0.181353;-0.249382;,
  0.648039;-0.249382;;
 }
}
