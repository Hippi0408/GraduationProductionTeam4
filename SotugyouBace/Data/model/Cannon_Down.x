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
 160;
 0.00000;14.50490;-65.87472;,
 46.58046;14.50490;-46.58046;,
 46.58046;0.11636;-46.58046;,
 0.00000;0.11636;-65.87472;,
 65.87472;14.50490;0.00000;,
 65.87472;0.11636;0.00000;,
 46.58046;14.50490;46.58046;,
 46.58046;0.11636;46.58046;,
 0.00000;14.50490;65.87472;,
 0.00000;0.11636;65.87472;,
 -46.58046;14.50490;46.58044;,
 -46.58046;0.11636;46.58044;,
 -65.87472;14.50490;0.00000;,
 -65.87472;0.11636;0.00000;,
 -46.58046;14.50490;-46.58046;,
 -46.58046;0.11636;-46.58046;,
 0.00000;14.50490;-65.87472;,
 0.00000;0.11636;-65.87472;,
 0.00000;14.50490;0.00000;,
 0.00000;14.50490;0.00000;,
 0.00000;14.50490;0.00000;,
 0.00000;14.50490;0.00000;,
 0.00000;14.50490;0.00000;,
 0.00000;14.50490;0.00000;,
 0.00000;14.50490;0.00000;,
 0.00000;14.50490;0.00000;,
 0.00000;0.11636;0.00000;,
 0.00000;0.11636;0.00000;,
 0.00000;0.11636;0.00000;,
 0.00000;0.11636;0.00000;,
 0.00000;0.11636;0.00000;,
 0.00000;0.11636;0.00000;,
 0.00000;0.11636;0.00000;,
 0.00000;0.11636;0.00000;,
 20.05826;34.11872;-41.66630;,
 47.59718;34.11872;-13.64248;,
 47.59718;15.09408;-13.64248;,
 20.05826;15.09408;-41.66630;,
 47.25432;34.11872;25.64628;,
 47.25432;15.09408;25.64628;,
 19.23050;34.11872;53.18520;,
 19.23050;15.09408;53.18520;,
 -20.05826;34.11872;52.84234;,
 -20.05826;15.09408;52.84234;,
 -47.59718;34.11872;24.81854;,
 -47.59718;15.09408;24.81854;,
 -47.25432;34.11872;-14.47024;,
 -47.25432;15.09408;-14.47024;,
 -19.23050;34.11872;-42.00916;,
 -19.23050;15.09408;-42.00916;,
 20.05826;34.11872;-41.66630;,
 20.05826;15.09408;-41.66630;,
 0.00000;34.11872;5.58802;,
 0.00000;34.11872;5.58802;,
 0.00000;34.11872;5.58802;,
 0.00000;34.11872;5.58802;,
 0.00000;34.11872;5.58802;,
 0.00000;34.11872;5.58802;,
 0.00000;34.11872;5.58802;,
 0.00000;34.11872;5.58802;,
 0.00000;15.09408;5.58802;,
 0.00000;15.09408;5.58802;,
 0.00000;15.09408;5.58802;,
 0.00000;15.09408;5.58802;,
 0.00000;15.09408;5.58802;,
 0.00000;15.09408;5.58802;,
 0.00000;15.09408;5.58802;,
 0.00000;15.09408;5.58802;,
 18.33250;6.13024;65.92596;,
 15.63404;6.13024;59.41136;,
 15.63404;0.17878;59.41136;,
 18.33250;0.17878;68.15880;,
 15.63404;6.13024;59.41136;,
 28.60004;6.13024;54.04064;,
 28.60004;0.17878;54.04064;,
 15.63404;0.17878;59.41136;,
 28.60004;6.13024;54.04064;,
 31.29850;6.13024;60.55526;,
 31.29850;0.17878;62.78810;,
 28.60004;0.17878;54.04064;,
 31.29850;6.13024;60.55526;,
 18.33250;6.13024;65.92596;,
 18.33250;0.17878;68.15880;,
 31.29850;0.17878;62.78810;,
 15.63404;6.13024;59.41136;,
 18.33250;6.13024;65.92596;,
 18.33250;0.17878;68.15880;,
 15.63404;0.17878;59.41136;,
 60.41224;24.87646;-74.26474;,
 70.79476;24.87646;-65.23934;,
 77.88752;-0.63102;-73.39864;,
 67.50498;-0.63102;-82.42402;,
 70.79476;24.87646;-65.23934;,
 36.98190;19.36656;-26.34216;,
 36.98190;-0.63102;-26.34216;,
 77.88752;-0.63102;-73.39864;,
 36.98190;19.36656;-26.34216;,
 26.59940;19.36656;-35.36754;,
 26.59940;-0.63102;-35.36754;,
 36.98190;-0.63102;-26.34216;,
 26.59940;19.36656;-35.36754;,
 60.41224;24.87646;-74.26474;,
 67.50498;-0.63102;-82.42402;,
 26.59940;-0.63102;-35.36754;,
 70.79476;24.87646;-65.23934;,
 60.41224;24.87646;-74.26474;,
 67.50498;-0.63102;-82.42402;,
 77.88752;-0.63102;-73.39864;,
 17.79358;8.01314;59.38852;,
 21.15038;8.01314;61.32660;,
 21.15038;6.24192;61.32660;,
 17.79358;6.24192;59.38852;,
 21.15038;8.01314;65.20268;,
 21.15038;6.24192;65.20268;,
 17.79358;8.01314;67.14074;,
 17.79358;6.24192;67.14074;,
 14.43678;8.01314;65.20268;,
 14.43678;6.24192;65.20268;,
 14.43678;8.01314;61.32660;,
 14.43678;6.24192;61.32660;,
 17.79358;8.01314;59.38852;,
 17.79358;6.24192;59.38852;,
 17.79358;8.01314;63.26466;,
 17.79358;8.01314;63.26466;,
 17.79358;8.01314;63.26466;,
 17.79358;8.01314;63.26466;,
 17.79358;8.01314;63.26466;,
 17.79358;8.01314;63.26466;,
 17.79358;6.24192;63.26466;,
 17.79358;6.24192;63.26466;,
 17.79358;6.24192;63.26466;,
 17.79358;6.24192;63.26466;,
 17.79358;6.24192;63.26466;,
 17.79358;6.24192;63.26466;,
 29.32856;8.01314;53.52122;,
 32.68536;8.01314;55.45930;,
 32.68536;6.24192;55.45930;,
 29.32856;6.24192;53.52122;,
 32.68536;8.01314;59.33538;,
 32.68536;6.24192;59.33538;,
 29.32856;8.01314;61.27344;,
 29.32856;6.24192;61.27344;,
 25.97174;8.01314;59.33538;,
 25.97174;6.24192;59.33538;,
 25.97174;8.01314;55.45930;,
 25.97174;6.24192;55.45930;,
 29.32856;8.01314;53.52122;,
 29.32856;6.24192;53.52122;,
 29.32856;8.01314;57.39736;,
 29.32856;8.01314;57.39736;,
 29.32856;8.01314;57.39736;,
 29.32856;8.01314;57.39736;,
 29.32856;8.01314;57.39736;,
 29.32856;8.01314;57.39736;,
 29.32856;6.24192;57.39736;,
 29.32856;6.24192;57.39736;,
 29.32856;6.24192;57.39736;,
 29.32856;6.24192;57.39736;,
 29.32856;6.24192;57.39736;,
 29.32856;6.24192;57.39736;;
 
 96;
 4;0,1,2,3;,
 4;1,4,5,2;,
 4;4,6,7,5;,
 4;6,8,9,7;,
 4;8,10,11,9;,
 4;10,12,13,11;,
 4;12,14,15,13;,
 4;14,16,17,15;,
 3;18,1,0;,
 3;19,4,1;,
 3;20,6,4;,
 3;21,8,6;,
 3;22,10,8;,
 3;23,12,10;,
 3;24,14,12;,
 3;25,16,14;,
 3;26,3,2;,
 3;27,2,5;,
 3;28,5,7;,
 3;29,7,9;,
 3;30,9,11;,
 3;31,11,13;,
 3;32,13,15;,
 3;33,15,17;,
 4;34,35,36,37;,
 4;35,38,39,36;,
 4;38,40,41,39;,
 4;40,42,43,41;,
 4;42,44,45,43;,
 4;44,46,47,45;,
 4;46,48,49,47;,
 4;48,50,51,49;,
 3;52,35,34;,
 3;53,38,35;,
 3;54,40,38;,
 3;55,42,40;,
 3;56,44,42;,
 3;57,46,44;,
 3;58,48,46;,
 3;59,50,48;,
 3;60,37,36;,
 3;61,36,39;,
 3;62,39,41;,
 3;63,41,43;,
 3;64,43,45;,
 3;65,45,47;,
 3;66,47,49;,
 3;67,49,51;,
 4;68,69,70,71;,
 4;72,73,74,75;,
 4;76,77,78,79;,
 4;80,81,82,83;,
 4;80,73,84,85;,
 4;86,87,74,83;,
 4;88,89,90,91;,
 4;92,93,94,95;,
 4;96,97,98,99;,
 4;100,101,102,103;,
 4;100,93,104,105;,
 4;106,107,94,103;,
 4;108,109,110,111;,
 4;109,112,113,110;,
 4;112,114,115,113;,
 4;114,116,117,115;,
 4;116,118,119,117;,
 4;118,120,121,119;,
 3;122,109,108;,
 3;123,112,109;,
 3;124,114,112;,
 3;125,116,114;,
 3;126,118,116;,
 3;127,120,118;,
 3;128,111,110;,
 3;129,110,113;,
 3;130,113,115;,
 3;131,115,117;,
 3;132,117,119;,
 3;133,119,121;,
 4;134,135,136,137;,
 4;135,138,139,136;,
 4;138,140,141,139;,
 4;140,142,143,141;,
 4;142,144,145,143;,
 4;144,146,147,145;,
 3;148,135,134;,
 3;149,138,135;,
 3;150,140,138;,
 3;151,142,140;,
 3;152,144,142;,
 3;153,146,144;,
 3;154,137,136;,
 3;155,136,139;,
 3;156,139,141;,
 3;157,141,143;,
 3;158,143,145;,
 3;159,145,147;;
 
 MeshMaterialList {
  5;
  96;
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
  4,
  4,
  4,
  4,
  4,
  4,
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
  3,
  3;;
  Material {
   0.228800;0.228800;0.228800;1.000000;;
   5.000000;
   0.940000;0.940000;0.940000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.800000;0.680800;0.000000;1.000000;;
   5.000000;
   0.750000;0.750000;0.750000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.191200;0.269600;0.552000;1.000000;;
   5.000000;
   0.830000;0.830000;0.830000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.408000;0.800000;0.800000;1.000000;;
   5.000000;
   0.700000;0.700000;0.700000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.044000;0.000000;0.323200;1.000000;;
   5.000000;
   0.560000;0.560000;0.560000;;
   0.000000;0.000000;0.000000;;
  }
 }
 MeshNormals {
  48;
  0.000000;1.000000;0.000000;,
  0.000000;0.000000;-1.000000;,
  0.707107;0.000000;-0.707107;,
  1.000000;0.000000;0.000000;,
  0.707107;0.000000;0.707107;,
  -0.000000;0.000000;1.000000;,
  -0.707107;0.000000;0.707107;,
  -1.000000;0.000000;0.000000;,
  -0.707107;0.000000;-0.707107;,
  0.000000;-1.000000;-0.000000;,
  0.000000;1.000000;0.000000;,
  0.390731;0.000000;-0.920505;,
  0.927184;0.000000;-0.374607;,
  0.920505;0.000000;0.390731;,
  0.374607;0.000000;0.927184;,
  -0.390731;0.000000;0.920505;,
  -0.927184;0.000000;0.374607;,
  -0.920505;0.000000;-0.390731;,
  -0.374607;0.000000;-0.927184;,
  0.000000;-1.000000;-0.000000;,
  -0.939272;0.055105;0.338721;,
  -0.382685;0.000000;-0.923879;,
  0.939272;-0.055105;-0.338720;,
  0.361579;0.327501;0.872928;,
  0.000000;1.000000;0.000000;,
  0.000000;-1.000000;-0.000000;,
  0.604043;0.390238;-0.694872;,
  0.754709;-0.000000;0.656060;,
  -0.656060;0.000000;0.754709;,
  -0.754709;0.000000;-0.656059;,
  -0.069740;0.994334;0.080226;,
  0.000000;-1.000000;-0.000000;,
  0.000000;1.000000;0.000000;,
  0.500006;0.000000;-0.866022;,
  1.000000;0.000000;0.000000;,
  0.500002;0.000000;0.866024;,
  -0.500002;0.000000;0.866024;,
  -1.000000;0.000000;0.000000;,
  0.000000;-1.000000;-0.000000;,
  -0.500006;0.000000;-0.866022;,
  0.000000;1.000000;0.000000;,
  0.500006;0.000000;-0.866022;,
  1.000000;0.000000;0.000000;,
  0.500001;0.000000;0.866025;,
  -0.499999;0.000000;0.866026;,
  -1.000000;0.000000;0.000000;,
  0.000000;-1.000000;-0.000000;,
  -0.500004;0.000000;-0.866023;;
  96;
  4;1,2,2,1;,
  4;2,3,3,2;,
  4;3,4,4,3;,
  4;4,5,5,4;,
  4;5,6,6,5;,
  4;6,7,7,6;,
  4;7,8,8,7;,
  4;8,1,1,8;,
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  3;9,9,9;,
  3;9,9,9;,
  3;9,9,9;,
  3;9,9,9;,
  3;9,9,9;,
  3;9,9,9;,
  3;9,9,9;,
  3;9,9,9;,
  4;11,12,12,11;,
  4;12,13,13,12;,
  4;13,14,14,13;,
  4;14,15,15,14;,
  4;15,16,16,15;,
  4;16,17,17,16;,
  4;17,18,18,17;,
  4;18,11,11,18;,
  3;10,10,10;,
  3;10,10,10;,
  3;10,10,10;,
  3;10,10,10;,
  3;10,10,10;,
  3;10,10,10;,
  3;10,10,10;,
  3;10,10,10;,
  3;19,19,19;,
  3;19,19,19;,
  3;19,19,19;,
  3;19,19,19;,
  3;19,19,19;,
  3;19,19,19;,
  3;19,19,19;,
  3;19,19,19;,
  4;20,20,20,20;,
  4;21,21,21,21;,
  4;22,22,22,22;,
  4;23,23,23,23;,
  4;24,24,24,24;,
  4;25,25,25,25;,
  4;26,26,26,26;,
  4;27,27,27,27;,
  4;28,28,28,28;,
  4;29,29,29,29;,
  4;30,30,30,30;,
  4;31,31,31,31;,
  4;33,33,33,33;,
  4;34,34,34,34;,
  4;35,35,35,35;,
  4;36,36,36,36;,
  4;37,37,37,37;,
  4;39,39,39,39;,
  3;32,32,32;,
  3;32,32,32;,
  3;32,32,32;,
  3;32,32,32;,
  3;32,32,32;,
  3;32,32,32;,
  3;38,38,38;,
  3;38,38,38;,
  3;38,38,38;,
  3;38,38,38;,
  3;38,38,38;,
  3;38,38,38;,
  4;41,41,41,41;,
  4;42,42,42,42;,
  4;43,43,43,43;,
  4;44,44,44,44;,
  4;45,45,45,45;,
  4;47,47,47,47;,
  3;40,40,40;,
  3;40,40,40;,
  3;40,40,40;,
  3;40,40,40;,
  3;40,40,40;,
  3;40,40,40;,
  3;46,46,46;,
  3;46,46,46;,
  3;46,46,46;,
  3;46,46,46;,
  3;46,46,46;,
  3;46,46,46;;
 }
 MeshTextureCoords {
  160;
  0.000000;0.000000;,
  0.125000;0.000000;,
  0.125000;1.000000;,
  0.000000;1.000000;,
  0.250000;0.000000;,
  0.250000;1.000000;,
  0.375000;0.000000;,
  0.375000;1.000000;,
  0.500000;0.000000;,
  0.500000;1.000000;,
  0.625000;0.000000;,
  0.625000;1.000000;,
  0.750000;0.000000;,
  0.750000;1.000000;,
  0.875000;0.000000;,
  0.875000;1.000000;,
  1.000000;0.000000;,
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
  0.000000;0.000000;,
  0.125000;0.000000;,
  0.125000;1.000000;,
  0.000000;1.000000;,
  0.250000;0.000000;,
  0.250000;1.000000;,
  0.375000;0.000000;,
  0.375000;1.000000;,
  0.500000;0.000000;,
  0.500000;1.000000;,
  0.625000;0.000000;,
  0.625000;1.000000;,
  0.750000;0.000000;,
  0.750000;1.000000;,
  0.875000;0.000000;,
  0.875000;1.000000;,
  1.000000;0.000000;,
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
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  0.000000;0.000000;,
  0.166670;0.000000;,
  0.166670;1.000000;,
  0.000000;1.000000;,
  0.333330;0.000000;,
  0.333330;1.000000;,
  0.500000;0.000000;,
  0.500000;1.000000;,
  0.666670;0.000000;,
  0.666670;1.000000;,
  0.833330;0.000000;,
  0.833330;1.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.083330;0.000000;,
  0.250000;0.000000;,
  0.416670;0.000000;,
  0.583330;0.000000;,
  0.750000;0.000000;,
  0.916670;0.000000;,
  0.083330;1.000000;,
  0.250000;1.000000;,
  0.416670;1.000000;,
  0.583330;1.000000;,
  0.750000;1.000000;,
  0.916670;1.000000;,
  0.000000;0.000000;,
  0.166670;0.000000;,
  0.166670;1.000000;,
  0.000000;1.000000;,
  0.333330;0.000000;,
  0.333330;1.000000;,
  0.500000;0.000000;,
  0.500000;1.000000;,
  0.666670;0.000000;,
  0.666670;1.000000;,
  0.833330;0.000000;,
  0.833330;1.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.083330;0.000000;,
  0.250000;0.000000;,
  0.416670;0.000000;,
  0.583330;0.000000;,
  0.750000;0.000000;,
  0.916670;0.000000;,
  0.083330;1.000000;,
  0.250000;1.000000;,
  0.416670;1.000000;,
  0.583330;1.000000;,
  0.750000;1.000000;,
  0.916670;1.000000;;
 }
}