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
 66;
 0.00000;1.22526;-3.37131;,
 -2.38387;1.22526;-2.38387;,
 -7.17766;4.79667;-6.82845;,
 0.00000;4.79667;-9.65688;,
 -3.37131;1.22526;0.00000;,
 -10.15075;4.79667;0.00000;,
 -2.38387;1.22526;2.38388;,
 -7.17766;4.79667;6.82846;,
 0.00000;1.22526;3.37131;,
 0.00000;4.79667;9.65689;,
 2.38387;1.22526;2.38387;,
 7.17766;4.79667;6.82845;,
 3.37131;1.22526;0.00000;,
 10.15075;4.79667;0.00000;,
 2.38387;1.22526;-2.38387;,
 7.17766;4.79667;-6.82845;,
 0.00000;1.22526;-3.37131;,
 0.00000;4.79667;-9.65688;,
 -7.07107;7.46349;-7.07107;,
 0.00000;7.46348;-10.00000;,
 -10.00000;7.46349;0.00000;,
 -7.07107;7.46349;7.07107;,
 0.00000;7.46349;10.00000;,
 7.07107;7.46349;7.07107;,
 10.00000;7.46349;0.00000;,
 7.07107;7.46349;-7.07107;,
 0.00000;7.46348;-10.00000;,
 0.00000;-0.12941;1.11301;,
 0.00000;-0.12941;1.11301;,
 0.00000;-0.12941;1.11301;,
 0.00000;-0.12941;1.11301;,
 0.00000;-0.12941;1.11301;,
 0.00000;-0.12941;1.11301;,
 0.00000;-0.12941;1.11301;,
 0.00000;-0.12941;1.11301;,
 0.00000;25.38560;0.00000;,
 0.00000;25.38560;0.00000;,
 0.00000;25.38560;0.00000;,
 0.00000;25.38560;0.00000;,
 0.00000;25.38560;0.00000;,
 0.00000;25.38560;0.00000;,
 0.00000;25.38560;0.00000;,
 0.00000;25.38560;0.00000;,
 0.00000;7.31407;-10.26498;,
 0.94746;6.92162;-10.26498;,
 0.00000;6.92162;-11.21244;,
 0.00000;7.31407;-10.26498;,
 0.00000;6.92162;-9.31752;,
 0.00000;7.31407;-10.26498;,
 -0.94746;6.92162;-10.26498;,
 0.00000;7.31407;-10.26498;,
 0.00000;6.92162;-11.21244;,
 1.33992;5.97415;-10.26498;,
 0.00000;5.97415;-11.60490;,
 0.00000;5.97415;-8.92506;,
 -1.33992;5.97415;-10.26498;,
 0.00000;5.97415;-11.60490;,
 0.94746;5.02670;-10.26498;,
 0.00000;5.02670;-11.21244;,
 0.00000;5.02670;-9.31752;,
 -0.94746;5.02670;-10.26498;,
 0.00000;5.02670;-11.21244;,
 0.00000;4.63424;-10.26498;,
 0.00000;4.63424;-10.26498;,
 0.00000;4.63424;-10.26498;,
 0.00000;4.63424;-10.26498;;
 
 48;
 4;0,1,2,3;,
 4;1,4,5,2;,
 4;4,6,7,5;,
 4;6,8,9,7;,
 4;8,10,11,9;,
 4;10,12,13,11;,
 4;12,14,15,13;,
 4;14,16,17,15;,
 4;3,2,18,19;,
 4;2,5,20,18;,
 4;5,7,21,20;,
 4;7,9,22,21;,
 4;9,11,23,22;,
 4;11,13,24,23;,
 4;13,15,25,24;,
 4;15,17,26,25;,
 3;27,1,0;,
 3;28,4,1;,
 3;29,6,4;,
 3;30,8,6;,
 3;31,10,8;,
 3;32,12,10;,
 3;33,14,12;,
 3;34,16,14;,
 3;35,19,18;,
 3;36,18,20;,
 3;37,20,21;,
 3;38,21,22;,
 3;39,22,23;,
 3;40,23,24;,
 3;41,24,25;,
 3;42,25,26;,
 3;43,44,45;,
 3;46,47,44;,
 3;48,49,47;,
 3;50,51,49;,
 4;45,44,52,53;,
 4;44,47,54,52;,
 4;47,49,55,54;,
 4;49,51,56,55;,
 4;53,52,57,58;,
 4;52,54,59,57;,
 4;54,55,60,59;,
 4;55,56,61,60;,
 3;58,57,62;,
 3;57,59,63;,
 3;59,60,64;,
 3;60,61,65;;
 
 MeshMaterialList {
  4;
  48;
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
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
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
   0.172800;0.172800;0.172800;1.000000;;
   5.000000;
   0.760000;0.760000;0.760000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.000000;0.003200;0.800000;1.000000;;
   5.000000;
   0.780000;0.780000;0.780000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.640000;0.640000;0.640000;1.000000;;
   5.000000;
   0.830000;0.830000;0.830000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.800000;0.000000;0.009600;1.000000;;
   5.000000;
   0.560000;0.560000;0.560000;;
   0.000000;0.000000;0.000000;;
  }
 }
 MeshNormals {
  52;
  0.000000;-0.997592;0.069359;,
  0.000000;-0.919678;-0.392673;,
  -0.281439;-0.917575;-0.280799;,
  -0.424383;-0.905438;0.009017;,
  -0.326446;-0.879892;0.345288;,
  0.000001;-0.863980;0.503527;,
  0.326447;-0.879891;0.345288;,
  0.424383;-0.905438;0.009018;,
  0.281439;-0.917575;-0.280799;,
  0.000000;-0.558783;-0.829314;,
  -0.588774;-0.539488;-0.601911;,
  -0.470037;-0.882647;-0.000000;,
  -0.391449;-0.689583;0.609297;,
  0.000001;-0.558782;0.829315;,
  0.588775;-0.539488;0.601911;,
  0.470037;-0.882647;-0.000000;,
  0.391449;-0.689584;-0.609296;,
  0.000000;0.204413;-0.978885;,
  -0.684099;0.236743;-0.689899;,
  -0.963309;0.268393;-0.000000;,
  -0.684099;0.236744;0.689899;,
  0.000000;0.204415;0.978884;,
  0.684099;0.236743;0.689899;,
  0.963310;0.268393;0.000000;,
  0.684099;0.236743;-0.689899;,
  -0.777953;0.539399;-0.322239;,
  -0.999571;0.029273;-0.000000;,
  -0.920077;0.026945;0.390810;,
  0.999572;0.029272;0.000000;,
  0.920077;0.026944;-0.390810;,
  0.322239;0.539399;0.777953;,
  0.617488;0.487253;-0.617489;,
  0.000000;1.000000;-0.000000;,
  0.267626;0.791446;-0.549536;,
  0.549535;0.791446;-0.267627;,
  0.267627;0.791446;0.549536;,
  -0.549536;0.791446;0.267627;,
  0.707107;-0.000003;-0.707107;,
  0.707107;-0.000003;0.707107;,
  -0.707107;-0.000003;0.707107;,
  0.267626;-0.791443;-0.549540;,
  0.549540;-0.791443;-0.267626;,
  0.267626;-0.791443;0.549540;,
  -0.549540;-0.791443;0.267626;,
  0.000000;-1.000000;-0.000000;,
  0.678598;0.281088;0.678598;,
  -0.678598;0.281088;0.678598;,
  -0.678598;0.281088;-0.678598;,
  -0.707107;-0.000003;-0.707107;,
  0.678597;-0.281093;0.678597;,
  -0.678597;-0.281093;0.678597;,
  -0.678596;-0.281093;-0.678597;;
  48;
  4;1,2,10,9;,
  4;2,3,11,10;,
  4;3,4,12,11;,
  4;4,5,13,12;,
  4;5,6,14,13;,
  4;6,7,15,14;,
  4;7,8,16,15;,
  4;8,1,9,16;,
  4;9,10,18,17;,
  4;10,26,19,18;,
  4;26,27,20,19;,
  4;12,13,21,20;,
  4;13,14,22,21;,
  4;14,28,23,22;,
  4;28,29,24,23;,
  4;16,9,17,24;,
  3;0,2,1;,
  3;0,3,2;,
  3;0,4,3;,
  3;0,5,4;,
  3;0,6,5;,
  3;0,7,6;,
  3;0,8,7;,
  3;0,1,8;,
  3;25,17,18;,
  3;25,18,19;,
  3;25,19,20;,
  3;30,20,21;,
  3;30,21,22;,
  3;30,22,23;,
  3;31,23,24;,
  3;31,24,17;,
  3;32,34,33;,
  3;32,35,34;,
  3;32,36,35;,
  3;32,33,36;,
  4;33,34,37,37;,
  4;45,35,38,38;,
  4;46,36,39,39;,
  4;47,47,48,48;,
  4;37,37,41,40;,
  4;38,38,42,49;,
  4;39,39,43,50;,
  4;48,48,51,51;,
  3;40,41,44;,
  3;41,42,44;,
  3;42,43,44;,
  3;43,40,44;;
 }
 MeshTextureCoords {
  66;
  0.000000;0.000000;,
  0.125000;0.000000;,
  0.125000;0.500000;,
  0.000000;0.500000;,
  0.250000;0.000000;,
  0.250000;0.500000;,
  0.375000;0.000000;,
  0.375000;0.500000;,
  0.500000;0.000000;,
  0.500000;0.500000;,
  0.625000;0.000000;,
  0.625000;0.500000;,
  0.750000;0.000000;,
  0.750000;0.500000;,
  0.875000;0.000000;,
  0.875000;0.500000;,
  1.000000;0.000000;,
  1.000000;0.500000;,
  0.125000;1.000000;,
  0.000000;1.000000;,
  0.250000;1.000000;,
  0.375000;1.000000;,
  0.500000;1.000000;,
  0.625000;1.000000;,
  0.750000;1.000000;,
  0.875000;1.000000;,
  1.000000;1.000000;,
  0.062500;0.000000;,
  0.187500;0.000000;,
  0.312500;0.000000;,
  0.437500;0.000000;,
  0.562500;0.000000;,
  0.687500;0.000000;,
  0.812500;0.000000;,
  0.937500;0.000000;,
  0.062500;1.000000;,
  0.187500;1.000000;,
  0.312500;1.000000;,
  0.437500;1.000000;,
  0.562500;1.000000;,
  0.687500;1.000000;,
  0.812500;1.000000;,
  0.937500;1.000000;,
  0.125000;0.000000;,
  0.250000;0.250000;,
  0.000000;0.250000;,
  0.375000;0.000000;,
  0.500000;0.250000;,
  0.625000;0.000000;,
  0.750000;0.250000;,
  0.875000;0.000000;,
  1.000000;0.250000;,
  0.250000;0.500000;,
  0.000000;0.500000;,
  0.500000;0.500000;,
  0.750000;0.500000;,
  1.000000;0.500000;,
  0.250000;0.750000;,
  0.000000;0.750000;,
  0.500000;0.750000;,
  0.750000;0.750000;,
  1.000000;0.750000;,
  0.125000;1.000000;,
  0.375000;1.000000;,
  0.625000;1.000000;,
  0.875000;1.000000;;
 }
}