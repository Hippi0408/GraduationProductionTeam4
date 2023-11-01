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
 40;
 6.63000;10.37834;-7.56637;,
 6.63000;10.37834;3.85143;,
 4.72304;1.08936;3.85143;,
 4.72304;1.08936;-3.85143;,
 -6.63000;10.37834;3.85143;,
 -6.63000;10.37834;-7.56637;,
 -4.72304;1.08936;-3.85143;,
 -4.72304;1.08936;3.85143;,
 -1.49821;1.08936;-4.96576;,
 -4.72304;1.08936;-3.85143;,
 -6.63000;10.37834;-7.56637;,
 -2.10313;10.37834;-8.23216;,
 -1.49821;1.08936;-4.96576;,
 -1.49821;1.08936;5.02836;,
 -4.72304;1.08936;-3.85143;,
 -2.10313;10.37834;-8.23216;,
 -6.63000;10.37834;-7.56637;,
 -2.10313;10.37834;5.02836;,
 -1.49821;1.08936;5.02836;,
 -2.10313;10.37834;5.02836;,
 -6.63000;10.37834;3.85143;,
 -4.72304;1.08936;3.85143;,
 1.15983;1.08936;-4.96576;,
 1.62812;10.37834;-8.23216;,
 6.63000;10.37834;-7.56637;,
 4.72304;1.08936;-3.85143;,
 1.15983;1.08936;-4.96576;,
 4.72304;1.08936;-3.85143;,
 1.15983;1.08936;5.02836;,
 1.62812;10.37834;-8.23216;,
 1.62812;10.37834;5.02836;,
 6.63000;10.37834;-7.56637;,
 1.15983;1.08936;5.02836;,
 4.72304;1.08936;3.85143;,
 6.63000;10.37834;3.85143;,
 1.62812;10.37834;5.02836;,
 -0.67326;1.63974;-5.92751;,
 0.24548;1.63974;-5.92751;,
 -0.88235;10.92871;-9.64246;,
 0.40734;10.92871;-9.64246;;
 
 18;
 4;0,1,2,3;,
 4;4,5,6,7;,
 4;8,9,10,11;,
 4;12,13,7,14;,
 4;15,16,4,17;,
 4;18,19,20,21;,
 4;22,23,24,25;,
 4;26,27,2,28;,
 4;26,28,13,12;,
 4;29,15,17,30;,
 4;29,30,1,31;,
 4;32,33,34,35;,
 4;32,35,19,18;,
 4;36,37,22,8;,
 4;38,36,8,11;,
 4;39,38,11,23;,
 4;37,39,23,22;,
 4;37,36,38,39;;
 
 MeshMaterialList {
  9;
  18;
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3;;
  Material {
   0.762400;0.746400;0.800000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.746400;0.743200;0.800000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.800000;0.800000;0.800000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.140400;0.043550;0.043550;1.000000;;
   15.000000;
   0.550000;0.550000;0.550000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.800000;0.800000;0.800000;1.000000;;
   21.000000;
   0.270000;0.270000;0.270000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.062400;0.040800;0.040800;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.169600;0.442400;0.448800;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.069960;0.182490;0.185130;;
  }
  Material {
   0.194400;0.222400;0.592800;1.000000;;
   5.000000;
   0.710000;0.710000;0.710000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.489600;0.260000;0.140800;1.000000;;
   5.000000;
   0.470000;0.470000;0.470000;;
   0.000000;0.000000;0.000000;;
  }
 }
 MeshNormals {
  20;
  -0.979571;-0.201099;0.000000;,
  0.979571;-0.201099;-0.000000;,
  -0.318586;-0.556171;-0.767579;,
  -0.449455;-0.337591;-0.827056;,
  0.000000;-1.000000;-0.000000;,
  0.000000;1.000000;0.000000;,
  0.305762;-0.554149;-0.774228;,
  0.431725;-0.335373;-0.837340;,
  -0.241062;-0.567001;-0.787654;,
  -0.346936;-0.353316;-0.868794;,
  0.234950;-0.564840;-0.791046;,
  0.000000;0.931576;0.363548;,
  -0.221848;-0.364033;-0.904579;,
  0.000000;0.992398;0.123068;,
  -0.150435;-0.018717;0.988443;,
  -0.297392;-0.037000;0.954038;,
  0.202321;-0.361773;-0.910047;,
  0.137055;-0.015863;0.990436;,
  0.271488;-0.031423;0.961929;,
  0.337763;-0.350952;-0.873355;;
  18;
  4;1,1,1,1;,
  4;0,0,0,0;,
  4;2,12,12,3;,
  4;4,4,4,4;,
  4;13,5,5,5;,
  4;14,14,15,15;,
  4;6,7,16,16;,
  4;4,4,4,4;,
  4;4,4,4,4;,
  4;13,13,5,5;,
  4;13,5,5,5;,
  4;17,18,18,17;,
  4;17,17,14,14;,
  4;8,10,6,2;,
  4;9,8,2,3;,
  4;11,11,13,13;,
  4;10,19,7,6;,
  4;10,8,9,19;;
 }
 MeshTextureCoords {
  40;
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.341390;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  0.341390;0.000000;,
  0.341390;0.000000;,
  0.341390;1.000000;,
  0.000000;0.000000;,
  0.341390;1.000000;,
  0.000000;1.000000;,
  0.341390;0.000000;,
  0.658610;1.000000;,
  0.658610;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.622780;1.000000;,
  0.622780;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.622780;0.000000;,
  1.000000;0.000000;,
  0.622780;1.000000;,
  0.622780;1.000000;,
  0.622780;0.000000;,
  1.000000;1.000000;,
  0.377220;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  0.377220;0.000000;,
  0.341390;1.000000;,
  0.622780;1.000000;,
  0.341390;0.000000;,
  0.622780;0.000000;;
 }
}
