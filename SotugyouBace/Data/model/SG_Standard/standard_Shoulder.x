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
 48;
 -0.25144;9.21214;-7.94500;,
 -0.25144;9.21214;7.94500;,
 -0.25144;-6.76792;7.94500;,
 -0.25144;-6.76792;-7.94500;,
 -15.65144;9.21214;7.94500;,
 -15.65144;9.21214;-7.94500;,
 -15.65144;-6.76792;-7.94500;,
 -15.65144;-6.76792;7.94500;,
 -11.31988;9.21214;-7.94500;,
 -11.31988;-6.76792;-7.94500;,
 -15.65144;-6.76792;-7.94500;,
 -15.65144;9.21214;-7.94500;,
 -11.31988;9.21214;-7.94500;,
 -15.65144;9.21214;-7.94500;,
 -11.31988;9.21214;7.94500;,
 -11.31988;-6.76792;-7.94500;,
 -11.31988;-6.76792;7.94500;,
 -15.65144;-6.76792;-7.94500;,
 -11.31988;9.21214;7.94500;,
 -15.65144;9.21214;7.94500;,
 -15.65144;-6.76792;7.94500;,
 -11.31988;-6.76792;7.94500;,
 -5.05306;-6.76792;-7.94500;,
 -5.05306;9.21214;-7.94500;,
 -0.25144;9.21214;-7.94500;,
 -0.25144;-6.76792;-7.94500;,
 -5.05306;-6.76792;-7.94500;,
 -0.25144;-6.76792;-7.94500;,
 -5.05306;-6.76792;7.94500;,
 -5.05306;9.21214;-7.94500;,
 -5.05306;9.21214;7.94500;,
 -0.25144;9.21214;-7.94500;,
 -5.05306;-6.76792;7.94500;,
 -0.25144;-6.76792;7.94500;,
 -0.25144;9.21214;7.94500;,
 -5.05306;9.21214;7.94500;,
 -11.75374;-7.90882;-10.18351;,
 -4.61921;-7.90882;-10.18351;,
 -11.75374;10.85305;-9.61428;,
 -4.61921;10.85305;-9.61428;,
 -11.75374;10.85305;9.61428;,
 -11.75374;10.85305;-9.61428;,
 -4.61921;10.85305;-9.61428;,
 -4.61921;10.85305;9.61428;,
 -4.61921;10.85305;9.61428;,
 -4.61921;-7.90882;10.18351;,
 -11.75374;-7.90882;10.18351;,
 -11.75374;10.85305;9.61428;;
 
 22;
 4;0,1,2,3;,
 4;4,5,6,7;,
 4;8,9,10,11;,
 4;12,13,4,14;,
 4;15,16,7,17;,
 4;18,19,20,21;,
 4;22,23,24,25;,
 4;26,27,2,28;,
 4;26,28,16,15;,
 4;29,30,1,31;,
 4;32,33,34,35;,
 4;36,37,22,9;,
 4;38,36,9,8;,
 4;37,39,23,22;,
 4;37,36,38,39;,
 4;40,41,12,14;,
 4;42,43,30,29;,
 4;42,41,40,43;,
 4;44,45,32,35;,
 4;46,47,18,21;,
 4;45,46,21,32;,
 4;45,44,47,46;;
 
 MeshMaterialList {
  3;
  22;
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  1,
  0,
  0,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1;;
  Material {
   0.800000;0.800000;0.800000;1.000000;;
   5.000000;
   0.810000;0.810000;0.810000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.380000;0.380000;0.380000;1.000000;;
   5.000000;
   0.400000;0.400000;0.400000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.160000;0.160000;0.160000;1.000000;;
   5.000000;
   0.940000;0.940000;0.940000;;
   0.000000;0.000000;0.000000;;
  }
 }
 MeshNormals {
  20;
  -1.000000;0.000000;0.000000;,
  1.000000;0.000000;0.000000;,
  0.000000;0.000000;-1.000000;,
  0.000000;1.000000;0.000000;,
  0.000000;-0.987888;-0.155172;,
  -0.985157;-0.131502;0.110327;,
  0.000000;-0.890954;0.454094;,
  -0.985157;-0.131502;-0.110327;,
  -0.976037;-0.003714;-0.217575;,
  0.985158;-0.131499;0.110325;,
  0.976038;-0.003713;-0.217570;,
  0.985158;-0.131499;-0.110325;,
  0.000000;-0.987888;0.155172;,
  0.000000;-1.000000;-0.000000;,
  0.000000;0.000000;1.000000;,
  -0.976037;-0.003714;0.217575;,
  0.976038;-0.003713;0.217570;,
  0.000000;0.030326;-0.999540;,
  0.000000;-0.890954;-0.454094;,
  0.000000;0.030326;0.999540;;
  22;
  4;1,1,1,1;,
  4;0,0,0,0;,
  4;2,2,2,2;,
  4;3,3,3,3;,
  4;12,4,13,13;,
  4;14,14,14,14;,
  4;2,2,2,2;,
  4;12,13,13,4;,
  4;12,4,4,12;,
  4;3,3,3,3;,
  4;14,14,14,14;,
  4;6,6,12,12;,
  4;5,15,15,5;,
  4;16,9,9,16;,
  4;17,17,17,17;,
  4;7,5,5,7;,
  4;9,11,11,9;,
  4;3,3,3,3;,
  4;11,10,10,11;,
  4;8,7,7,8;,
  4;18,18,4,4;,
  4;19,19,19,19;;
 }
 MeshTextureCoords {
  48;
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.281270;0.000000;,
  0.281270;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  0.281270;1.000000;,
  0.000000;1.000000;,
  0.281270;0.000000;,
  0.281270;0.000000;,
  0.281270;1.000000;,
  0.000000;0.000000;,
  0.718730;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.718730;1.000000;,
  0.688210;1.000000;,
  0.688210;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.688210;0.000000;,
  1.000000;0.000000;,
  0.688210;1.000000;,
  0.688210;1.000000;,
  0.688210;0.000000;,
  1.000000;1.000000;,
  0.311790;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  0.311790;0.000000;,
  0.281270;1.000000;,
  0.688210;1.000000;,
  0.281270;0.000000;,
  0.688210;0.000000;,
  0.281270;0.000000;,
  0.281270;1.000000;,
  0.688210;1.000000;,
  0.688210;0.000000;,
  0.311790;0.000000;,
  0.311790;1.000000;,
  0.718730;1.000000;,
  0.718730;0.000000;;
 }
}
