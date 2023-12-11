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
 18;
 11.78906;9.54462;0.00000;,
 4.90123;-0.07189;-0.00000;,
 4.90123;9.54462;-5.89852;,
 11.78906;9.54462;0.00000;,
 4.90123;9.54462;5.89852;,
 11.78906;9.54462;0.00000;,
 2.86002;19.16113;0.00000;,
 11.78906;9.54462;0.00000;,
 4.90123;9.54462;-5.89852;,
 -4.90123;-0.07189;0.00000;,
 -4.90123;9.54462;-5.89852;,
 -4.90123;9.54462;5.89852;,
 -2.86003;19.16113;0.00000;,
 -4.90123;9.54462;-5.89852;,
 -11.78906;9.54462;0.00000;,
 -11.78906;9.54462;0.00000;,
 -11.78906;9.54462;0.00000;,
 -11.78906;9.54462;0.00000;;
 
 12;
 3;0,1,2;,
 3;3,4,1;,
 3;5,6,4;,
 3;7,8,6;,
 4;2,1,9,10;,
 4;1,4,11,9;,
 4;4,6,12,11;,
 4;6,8,13,12;,
 3;10,9,14;,
 3;9,11,15;,
 3;11,12,16;,
 3;12,13,17;;
 
 MeshMaterialList {
  2;
  12;
  0,
  0,
  0,
  0,
  1,
  1,
  1,
  1,
  0,
  0,
  0,
  0;;
  Material {
   0.496000;0.496000;0.496000;1.000000;;
   5.000000;
   0.740000;0.740000;0.740000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.238400;0.000000;0.536800;1.000000;;
   5.000000;
   0.740000;0.740000;0.740000;;
   0.000000;0.000000;0.000000;;
  }
 }
 MeshNormals {
  14;
  0.649516;0.053641;-0.758454;,
  0.352342;0.029099;-0.935419;,
  0.310087;-0.497082;-0.810405;,
  0.352342;0.029099;0.935419;,
  0.291472;0.544345;0.786595;,
  -0.310087;-0.497082;-0.810405;,
  -0.310087;-0.497082;0.810405;,
  -0.291473;0.544345;0.786595;,
  -0.649516;0.053641;-0.758454;,
  0.649516;0.053641;0.758454;,
  0.310087;-0.497082;0.810405;,
  0.291472;0.544345;-0.786595;,
  -0.291473;0.544345;-0.786595;,
  -0.649516;0.053641;0.758454;;
  12;
  3;0,2,1;,
  3;9,3,10;,
  3;9,4,3;,
  3;0,1,11;,
  4;1,2,5,5;,
  4;10,3,6,6;,
  4;3,4,7,7;,
  4;11,1,12,12;,
  3;5,5,8;,
  3;6,6,13;,
  3;7,7,13;,
  3;12,12,8;;
 }
 MeshTextureCoords {
  18;
  0.125000;0.000000;,
  0.250000;0.333330;,
  0.000000;0.333330;,
  0.375000;0.000000;,
  0.500000;0.333330;,
  0.625000;0.000000;,
  0.750000;0.333330;,
  0.875000;0.000000;,
  1.000000;0.333330;,
  0.250000;0.666670;,
  0.000000;0.666670;,
  0.500000;0.666670;,
  0.750000;0.666670;,
  1.000000;0.666670;,
  0.125000;1.000000;,
  0.375000;1.000000;,
  0.625000;1.000000;,
  0.875000;1.000000;;
 }
}
