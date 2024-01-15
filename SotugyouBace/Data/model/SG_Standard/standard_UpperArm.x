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
 80;
 0.17393;-12.29780;3.30500;,
 3.39070;-12.29780;3.30500;,
 3.39070;-7.04324;3.30500;,
 0.17393;-7.04324;3.30500;,
 -3.02930;-7.04324;3.30500;,
 -3.02930;-12.29780;3.30500;,
 0.17393;-0.14780;3.30500;,
 -3.02930;-0.14780;3.30500;,
 3.39070;-0.14780;3.30500;,
 3.39070;-12.29780;1.04169;,
 3.39070;-12.29780;3.30500;,
 0.17393;-12.29780;3.30500;,
 0.17393;-12.29780;1.04169;,
 0.17393;-12.29780;-3.30500;,
 3.39070;-12.29780;-3.30500;,
 3.39070;-0.14780;1.04169;,
 3.39070;-0.14780;-3.30500;,
 0.17393;-0.14780;-3.30500;,
 0.17393;-0.14780;1.04169;,
 0.17393;-0.14780;3.30500;,
 3.39070;-0.14780;3.30500;,
 -3.02930;-12.29780;3.30500;,
 -3.02930;-12.29780;1.04169;,
 -3.02930;-12.29780;-3.30500;,
 -3.02930;-0.14780;-3.30500;,
 -3.02930;-0.14780;1.04169;,
 -3.02930;-0.14780;3.30500;,
 0.75450;-1.45958;-4.30500;,
 0.75450;-5.73146;-4.30500;,
 0.17393;-7.04324;-3.30500;,
 0.17393;-0.14780;-3.30500;,
 2.81816;-1.45958;-4.30500;,
 3.39070;-0.14780;-3.30500;,
 2.81816;-5.73146;-4.30500;,
 3.39070;-7.04324;-3.30500;,
 -2.45701;-5.73146;-4.30500;,
 -0.40202;-5.73146;-4.30500;,
 -3.02930;-7.04324;-3.30500;,
 -2.45701;-1.45958;-4.30500;,
 -3.02930;-0.14780;-3.30500;,
 -0.40202;-1.45958;-4.30500;,
 3.55209;-7.04733;-3.65402;,
 0.17482;-7.04733;-4.32402;,
 0.17482;-12.32817;-4.32402;,
 3.40714;-12.32817;-3.82152;,
 3.39070;-12.29780;-3.30500;,
 0.17393;-12.29780;-3.30500;,
 -3.04574;-12.32817;-3.82152;,
 -3.02930;-12.29780;-3.30500;,
 -3.19069;-7.04733;-3.65402;,
 3.84198;-12.32817;3.32402;,
 3.84198;-7.04733;3.32402;,
 3.39070;-7.04324;3.30500;,
 3.84198;-12.32817;1.04940;,
 3.39070;-12.29780;1.04169;,
 3.84198;-7.04735;1.04940;,
 3.40714;-12.32817;-3.82152;,
 3.39070;-12.29780;-3.30500;,
 3.55209;-7.04733;-3.65402;,
 3.84198;-0.11744;-3.31902;,
 3.39070;-7.04324;-3.30500;,
 3.39070;-0.14780;-3.30500;,
 3.84198;-0.11746;1.04940;,
 3.39070;-0.14780;1.04169;,
 3.84198;-0.11744;3.32402;,
 -3.48058;-12.32817;3.32402;,
 -3.48058;-12.32817;1.04940;,
 -3.02930;-12.29780;1.04169;,
 -3.48058;-7.04733;3.32402;,
 -3.02930;-7.04324;3.30500;,
 -3.48058;-7.04735;1.04940;,
 -3.04574;-12.32817;-3.82152;,
 -3.02930;-12.29780;-3.30500;,
 -3.19069;-7.04733;-3.65402;,
 -3.48058;-0.11744;-3.31902;,
 -3.48058;-0.11746;1.04940;,
 -3.02930;-0.14780;1.04169;,
 -3.02930;-0.14780;-3.30500;,
 -3.02930;-7.04324;-3.30500;,
 -3.48058;-0.11744;3.32402;;
 
 50;
 4;0,1,2,3;,
 4;0,3,4,5;,
 4;6,7,4,3;,
 4;6,3,2,8;,
 4;9,10,11,12;,
 4;9,12,13,14;,
 4;15,16,17,18;,
 4;15,18,19,20;,
 4;12,11,21,22;,
 4;12,22,23,13;,
 4;18,17,24,25;,
 4;18,25,26,19;,
 4;27,28,29,30;,
 4;31,27,30,32;,
 4;33,31,32,34;,
 4;28,33,34,29;,
 4;28,27,31,33;,
 4;35,36,29,37;,
 4;38,35,37,39;,
 4;40,38,39,30;,
 4;36,40,30,29;,
 4;36,35,38,40;,
 4;41,42,29,34;,
 4;43,44,45,46;,
 4;42,41,44,43;,
 4;47,43,46,48;,
 4;42,49,37,29;,
 4;42,43,47,49;,
 4;50,51,52,10;,
 4;53,50,10,54;,
 4;55,51,50,53;,
 4;56,53,54,57;,
 4;55,53,56,58;,
 4;59,58,60,61;,
 4;62,59,61,63;,
 4;55,58,59,62;,
 4;64,62,63,20;,
 4;51,64,20,52;,
 4;55,62,64,51;,
 4;65,66,67,21;,
 4;68,65,21,69;,
 4;66,65,68,70;,
 4;66,71,72,67;,
 4;66,70,73,71;,
 4;74,75,76,77;,
 4;73,74,77,78;,
 4;75,74,73,70;,
 4;79,68,69,26;,
 4;75,79,26,76;,
 4;75,70,68,79;;
 
 MeshMaterialList {
  3;
  50;
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
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
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0;;
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
  69;
  0.024642;0.956102;-0.291996;,
  0.086943;-0.995981;0.021526;,
  -0.024642;0.956102;-0.291996;,
  -0.086940;-0.995981;0.021525;,
  -0.021059;0.000000;0.999778;,
  0.021059;0.000000;0.999778;,
  0.305012;-0.318208;-0.897614;,
  0.867828;0.000000;-0.496865;,
  -0.864817;0.000000;-0.502087;,
  0.000002;-0.999755;0.022126;,
  0.000000;0.896174;-0.443703;,
  0.000000;0.000000;1.000000;,
  -0.081378;-0.996671;0.004990;,
  -0.033576;0.999436;-0.000000;,
  0.000000;-1.000000;-0.000000;,
  0.000000;1.000000;0.000000;,
  0.081378;-0.996671;0.004990;,
  0.033576;0.999436;-0.000000;,
  0.000000;0.319945;-0.947436;,
  -0.867921;0.000000;-0.496702;,
  0.000000;-0.319945;-0.947436;,
  0.000000;0.319945;-0.947436;,
  0.067114;0.997745;0.000002;,
  0.130515;-0.990920;0.032314;,
  -0.553144;0.029178;-0.832574;,
  -0.130510;-0.990920;0.032312;,
  -0.067114;0.997745;-0.000004;,
  -0.042110;0.000000;0.999113;,
  0.042110;0.000000;0.999113;,
  0.067135;-0.997744;-0.000000;,
  -0.001069;0.999972;-0.007382;,
  0.001066;0.999972;-0.007383;,
  -0.000002;0.999973;-0.007383;,
  0.000005;-0.999021;0.044240;,
  0.999617;-0.007915;-0.026507;,
  -0.162593;-0.986643;0.009970;,
  -0.067114;0.997745;-0.000001;,
  0.162593;-0.986643;0.009970;,
  0.067114;0.997745;-0.000001;,
  -0.999617;-0.007915;-0.026507;,
  -0.033586;-0.999436;0.000000;,
  -0.033576;0.999436;-0.000002;,
  0.033586;-0.999436;-0.000000;,
  0.033576;0.999436;-0.000002;,
  0.000000;-0.319945;-0.947436;,
  -0.305011;-0.318208;-0.897614;,
  0.000000;-0.606255;-0.795270;,
  0.866550;0.000000;-0.499090;,
  -0.000305;0.013080;-0.999914;,
  -0.204126;0.022653;-0.978682;,
  0.174124;0.012885;-0.984639;,
  -0.174725;0.012874;-0.984533;,
  0.203828;0.022650;-0.978745;,
  -0.067135;-0.997744;0.000000;,
  1.000000;0.000000;0.000000;,
  0.999273;-0.006134;-0.037636;,
  0.997092;-0.012258;-0.075217;,
  0.998469;-0.015827;-0.053000;,
  -0.067114;0.997745;0.000002;,
  0.999339;-0.019388;-0.030756;,
  0.999835;-0.009695;-0.015380;,
  -0.999273;-0.006133;-0.037636;,
  -1.000000;0.000000;0.000000;,
  -0.998469;-0.015827;-0.053000;,
  -0.997092;-0.012258;-0.075218;,
  0.553146;0.029178;-0.832573;,
  -0.999835;-0.009695;-0.015381;,
  -0.999339;-0.019388;-0.030756;,
  0.067114;0.997745;-0.000004;;
  50;
  4;11,4,4,11;,
  4;11,11,5,5;,
  4;11,5,5,11;,
  4;11,11,4,4;,
  4;12,40,14,14;,
  4;12,14,9,3;,
  4;13,2,10,15;,
  4;13,15,15,41;,
  4;14,14,42,16;,
  4;14,16,1,9;,
  4;15,10,0,17;,
  4;15,17,43,15;,
  4;8,8,8,8;,
  4;18,18,10,2;,
  4;7,7,7,7;,
  4;44,44,45,46;,
  4;44,18,18,44;,
  4;20,20,46,6;,
  4;19,19,19,19;,
  4;21,21,0,10;,
  4;47,47,47,47;,
  4;20,20,21,21;,
  4;31,32,32,31;,
  4;33,25,3,9;,
  4;48,49,50,48;,
  4;23,33,9,1;,
  4;32,30,30,32;,
  4;48,48,51,52;,
  4;27,27,4,4;,
  4;35,53,40,12;,
  4;34,54,54,55;,
  4;25,35,12,3;,
  4;34,55,56,57;,
  4;24,49,45,24;,
  4;36,58,2,13;,
  4;34,57,59,60;,
  4;26,36,13,41;,
  4;27,27,4,4;,
  4;34,60,54,54;,
  4;29,37,16,42;,
  4;28,28,5,5;,
  4;61,62,62,39;,
  4;37,23,1,16;,
  4;61,39,63,64;,
  4;22,38,17,0;,
  4;52,65,65,6;,
  4;66,67,63,39;,
  4;28,28,5,5;,
  4;38,68,43,17;,
  4;66,39,62,62;;
 }
 MeshTextureCoords {
  80;
  0.501050;1.000000;,
  0.000000;1.000000;,
  0.000000;0.567530;,
  0.501050;0.567530;,
  1.000000;0.567530;,
  1.000000;1.000000;,
  0.501050;0.000000;,
  1.000000;0.000000;,
  0.000000;0.000000;,
  1.000000;0.657590;,
  1.000000;1.000000;,
  0.498950;1.000000;,
  0.498950;0.657590;,
  0.498950;0.000000;,
  1.000000;0.000000;,
  1.000000;0.342410;,
  1.000000;1.000000;,
  0.498950;1.000000;,
  0.498950;0.342410;,
  0.498950;0.000000;,
  1.000000;0.000000;,
  0.000000;1.000000;,
  0.000000;0.657590;,
  0.000000;0.000000;,
  0.000000;1.000000;,
  0.000000;0.342410;,
  0.000000;0.000000;,
  0.498950;0.000000;,
  0.498950;0.567530;,
  0.498950;0.567530;,
  0.498950;0.000000;,
  1.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;0.567530;,
  1.000000;0.567530;,
  0.000000;0.567530;,
  0.498950;0.567530;,
  0.000000;0.567530;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.498950;0.000000;,
  1.000000;0.567530;,
  0.498950;0.567530;,
  0.498950;1.000000;,
  1.000000;1.000000;,
  1.000000;1.000000;,
  0.498950;1.000000;,
  0.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.567530;,
  1.000000;1.000000;,
  1.000000;0.567530;,
  1.000000;0.567530;,
  0.657590;1.000000;,
  0.657590;1.000000;,
  0.657590;0.567530;,
  0.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.567530;,
  0.000000;0.000000;,
  0.000000;0.567530;,
  0.000000;0.000000;,
  0.657590;0.000000;,
  0.657590;0.000000;,
  1.000000;0.000000;,
  0.000000;1.000000;,
  0.342410;1.000000;,
  0.342410;1.000000;,
  0.000000;0.567530;,
  0.000000;0.567530;,
  0.342410;0.567530;,
  1.000000;1.000000;,
  1.000000;1.000000;,
  1.000000;0.567530;,
  1.000000;0.000000;,
  0.342410;0.000000;,
  0.342410;0.000000;,
  1.000000;0.000000;,
  1.000000;0.567530;,
  0.000000;0.000000;;
 }
}