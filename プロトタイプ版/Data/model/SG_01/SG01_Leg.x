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
 200;
 2.29860;-5.23141;0.48275;,
 2.29860;-5.23141;4.29738;,
 5.44518;-5.23141;2.95783;,
 5.44518;-5.23141;0.48275;,
 -1.28223;-5.23141;0.48275;,
 -1.28223;-5.23141;4.29738;,
 -4.92373;-5.23141;0.48275;,
 -4.92373;-5.23141;2.95783;,
 6.37272;-47.11168;0.77625;,
 5.29232;-47.11168;3.39822;,
 2.66319;-47.11168;3.69415;,
 2.66319;-47.11168;0.77625;,
 -1.55828;-47.11168;3.69415;,
 -1.55828;-47.11168;0.77625;,
 -5.85127;-47.11168;0.77625;,
 -4.77087;-47.11168;3.39822;,
 2.29860;-5.23141;-1.60229;,
 5.44518;-5.23141;-1.60229;,
 -1.28223;-5.23141;-1.60229;,
 -4.92373;-5.23141;-1.60229;,
 6.37272;-47.11168;-1.68182;,
 2.66319;-47.11168;-1.68182;,
 2.66319;-47.11168;-6.00967;,
 6.37272;-47.11168;-4.63501;,
 -1.55828;-47.11168;-1.68182;,
 -1.55828;-47.11168;-6.00967;,
 -5.85127;-47.11168;-1.68182;,
 -5.85127;-47.11168;-4.63501;,
 5.44518;-12.27082;-4.10731;,
 5.44518;-5.23141;-4.10731;,
 5.44518;-5.23141;-1.60229;,
 5.44518;-12.27082;-1.60229;,
 -4.92373;-12.27082;-4.10731;,
 -4.92373;-12.27082;-1.60229;,
 -4.92373;-5.23141;-1.60229;,
 -4.92373;-5.23141;-4.10731;,
 5.44518;-5.23141;0.48275;,
 5.44518;-12.27082;0.48275;,
 -4.92373;-12.27082;0.48275;,
 -4.92373;-5.23141;0.48275;,
 5.44518;-12.27082;2.95783;,
 -4.92373;-12.27082;2.95783;,
 5.44518;-12.27082;2.95783;,
 5.44518;-5.23141;2.95783;,
 2.29860;-5.23141;4.29738;,
 2.29860;-12.27082;4.29738;,
 -4.92373;-12.27082;2.95783;,
 -1.28223;-12.27082;4.29738;,
 -1.28223;-5.23141;4.29738;,
 -4.92373;-5.23141;2.95783;,
 2.29860;6.03683;-9.55904;,
 5.44518;3.30614;-9.55904;,
 5.14363;2.56838;-12.50238;,
 2.48447;5.29906;-13.70052;,
 -1.44793;5.29906;-13.70748;,
 -1.28223;6.03683;-9.55904;,
 -4.58185;2.56838;-12.51629;,
 -4.92373;3.30614;-9.55904;,
 2.67034;-5.20880;-14.17093;,
 -1.61363;-5.20880;-14.18484;,
 -1.44793;5.29906;-13.70748;,
 2.48447;5.29906;-13.70052;,
 5.14363;2.56838;-12.50238;,
 4.95834;-5.20880;-12.94070;,
 -4.35624;-5.20880;-12.96853;,
 -4.58185;2.56838;-12.51629;,
 2.29860;-20.12144;-5.37339;,
 -1.28223;-20.12144;-5.37339;,
 -1.28223;-12.27082;-9.82272;,
 2.29860;-12.27082;-9.82272;,
 5.44518;-12.27082;-4.10731;,
 5.44518;-20.12144;-4.10731;,
 -4.92373;-20.12144;-4.10731;,
 -4.92373;-12.27082;-4.10731;,
 5.44518;-20.12144;-4.10731;,
 5.44518;-20.12144;-1.60229;,
 -4.92373;-20.12144;-4.10731;,
 -4.92373;-20.12144;-1.60229;,
 5.44518;-20.12144;0.48275;,
 -4.92373;-20.12144;0.48275;,
 5.44518;-20.12144;2.95783;,
 -4.92373;-20.12144;2.95783;,
 5.44518;-20.12144;2.95783;,
 2.29860;-20.12144;4.29738;,
 -4.92373;-20.12144;2.95783;,
 -1.28223;-20.12144;4.29738;,
 -4.07164;-27.31302;-3.62863;,
 -4.07164;-27.31302;-1.53533;,
 -4.07164;-30.62568;-3.62863;,
 -4.07164;-30.62568;-1.53533;,
 -4.07164;-27.31302;-3.62863;,
 -1.02864;-27.31302;-4.66504;,
 -1.02864;-30.62568;-4.65257;,
 -4.07164;-30.62568;-3.62863;,
 -4.07164;-27.31302;0.20702;,
 -4.07164;-30.62568;0.20702;,
 1.96367;-27.31302;-4.66504;,
 1.96367;-30.62568;-4.65257;,
 -3.27043;-27.31302;1.68664;,
 -3.27043;-30.62568;1.68664;,
 4.59309;-27.31302;-3.62863;,
 4.59309;-30.62568;-3.62863;,
 -3.27043;-27.31302;1.68664;,
 -1.02864;-27.31302;2.27531;,
 -3.27043;-30.62568;1.68664;,
 -1.02864;-30.62568;2.27531;,
 4.59309;-27.31302;-3.62863;,
 4.59308;-27.31302;-1.53533;,
 4.59308;-30.62568;-1.53533;,
 4.59309;-30.62568;-3.62863;,
 1.96367;-27.31302;2.27531;,
 1.96367;-30.62568;2.27531;,
 4.59308;-27.31302;0.20702;,
 4.59308;-30.62568;0.20702;,
 3.79188;-27.31302;1.68664;,
 3.79188;-30.62568;1.68664;,
 3.79188;-27.31302;1.68664;,
 3.79188;-30.62568;1.68664;,
 -5.56608;-41.73056;-4.47480;,
 -5.85127;-47.11168;-4.63501;,
 -5.85127;-47.11168;-1.68182;,
 -5.56608;-41.73056;-1.65941;,
 -5.56608;-41.73056;-4.47480;,
 -1.47340;-41.73056;-5.80190;,
 -1.55828;-47.11168;-6.00967;,
 -5.85127;-47.11168;-4.63501;,
 -5.85127;-47.11168;0.77625;,
 -5.56608;-41.73056;0.68396;,
 2.55110;-41.73056;-5.80190;,
 2.66319;-47.11168;-6.00967;,
 -4.53610;-41.73056;3.16979;,
 6.08753;-41.73056;-4.47480;,
 6.37272;-47.11168;-4.63501;,
 -4.53610;-41.73056;3.16979;,
 -4.77087;-47.11168;3.39822;,
 -1.55828;-47.11168;3.69415;,
 -1.47340;-41.73056;3.46571;,
 6.08753;-41.73056;-4.47480;,
 6.08753;-41.73056;-1.65941;,
 6.37272;-47.11168;-1.68182;,
 6.37272;-47.11168;-4.63501;,
 2.66319;-47.11168;3.69415;,
 2.55110;-41.73056;3.46571;,
 6.08753;-41.73056;0.68396;,
 6.37272;-47.11168;0.77625;,
 5.29232;-47.11168;3.39822;,
 5.05755;-41.73056;3.16979;,
 5.05755;-41.73056;3.16979;,
 -4.62864;-41.13545;-3.94154;,
 -4.62864;-41.13545;-1.57910;,
 -4.62864;-41.13545;-3.94154;,
 -1.19441;-41.13545;-5.05837;,
 -4.62864;-41.13545;0.38726;,
 2.18261;-41.13545;-5.05837;,
 -4.62864;-41.13545;2.72147;,
 5.15009;-41.13545;-3.94154;,
 -4.62864;-41.13545;2.72147;,
 -1.19441;-41.13545;2.72147;,
 5.15009;-41.13545;-3.94154;,
 5.15009;-41.13545;-1.57910;,
 2.18261;-41.13545;2.72147;,
 5.15009;-41.13545;0.38726;,
 5.15009;-41.13545;2.72147;,
 5.15009;-41.13545;2.72147;,
 -1.28223;0.21704;-7.12833;,
 2.29860;0.21704;-7.12833;,
 -4.92373;0.69801;-7.12833;,
 5.44518;0.69801;-7.12833;,
 -4.68629;0.18560;-9.94743;,
 -4.92373;-5.23141;-4.10731;,
 5.23575;0.18560;-9.93777;,
 5.44518;-5.23141;-4.10731;,
 -4.68629;0.18560;-9.94743;,
 -4.52961;-7.36615;-10.26151;,
 -4.92373;-5.23141;-4.10731;,
 5.23575;0.18560;-9.93777;,
 5.10706;-7.36615;-10.24218;,
 5.44518;-5.23141;-4.10731;,
 -1.51240;-7.36615;-12.85226;,
 2.55678;-7.36615;-12.84259;,
 -3.11014;-0.12885;-3.54998;,
 3.43986;-0.12885;-3.54998;,
 3.43986;-8.17885;-3.54998;,
 -3.11014;-8.17885;-3.54998;,
 3.43986;-0.12885;-3.54998;,
 3.43986;-0.12885;2.44002;,
 3.43986;-8.17885;2.44002;,
 3.43986;-8.17885;-3.54998;,
 3.43986;-0.12885;2.44002;,
 -3.11014;-0.12885;2.44002;,
 -3.11014;-8.17885;2.44002;,
 3.43986;-8.17885;2.44002;,
 -3.11014;-0.12885;2.44002;,
 -3.11014;-0.12885;-3.54998;,
 -3.11014;-8.17885;-3.54998;,
 -3.11014;-8.17885;2.44002;,
 3.43986;-0.12885;-3.54998;,
 -3.11014;-0.12885;-3.54998;,
 -3.11014;-8.17885;-3.54998;,
 3.43986;-8.17885;-3.54998;;
 
 128;
 4;0,1,2,3;,
 4;0,4,5,1;,
 4;4,6,7,5;,
 4;8,9,10,11;,
 4;11,10,12,13;,
 4;14,13,12,15;,
 4;16,0,3,17;,
 4;16,18,4,0;,
 4;18,19,6,4;,
 4;20,21,22,23;,
 4;20,8,11,21;,
 4;21,24,25,22;,
 4;21,11,13,24;,
 4;26,24,13,14;,
 4;26,27,25,24;,
 4;28,29,30,31;,
 4;32,33,34,35;,
 4;31,30,36,37;,
 4;33,38,39,34;,
 4;37,36,2,40;,
 4;38,41,7,39;,
 4;42,43,44,45;,
 4;46,47,48,49;,
 4;45,44,48,47;,
 4;50,51,52,53;,
 4;50,53,54,55;,
 4;55,54,56,57;,
 4;58,59,60,61;,
 4;58,61,62,63;,
 4;59,64,65,60;,
 4;66,67,68,69;,
 4;66,69,70,71;,
 4;67,72,73,68;,
 4;74,28,31,75;,
 4;76,77,33,32;,
 4;75,31,37,78;,
 4;77,79,38,33;,
 4;78,37,40,80;,
 4;79,81,41,38;,
 4;82,42,45,83;,
 4;84,85,47,46;,
 4;83,45,47,85;,
 4;86,87,77,76;,
 4;86,88,89,87;,
 4;90,91,92,93;,
 4;90,72,67,91;,
 4;87,94,79,77;,
 4;87,89,95,94;,
 4;91,96,97,92;,
 4;91,67,66,96;,
 4;94,98,81,79;,
 4;94,95,99,98;,
 4;96,100,101,97;,
 4;96,66,71,100;,
 4;102,103,85,84;,
 4;102,104,105,103;,
 4;106,107,108,109;,
 4;106,74,75,107;,
 4;103,110,83,85;,
 4;103,105,111,110;,
 4;107,112,113,108;,
 4;107,75,78,112;,
 4;110,114,82,83;,
 4;110,111,115,114;,
 4;112,116,117,113;,
 4;112,78,80,116;,
 4;118,119,120,121;,
 4;122,123,124,125;,
 4;121,120,126,127;,
 4;123,128,129,124;,
 4;127,126,15,130;,
 4;128,131,132,129;,
 4;133,134,135,136;,
 4;137,138,139,140;,
 4;136,135,141,142;,
 4;138,143,144,139;,
 4;142,141,145,146;,
 4;143,147,9,144;,
 4;148,149,89,88;,
 4;148,118,121,149;,
 4;150,151,123,122;,
 4;150,93,92,151;,
 4;149,152,95,89;,
 4;149,121,127,152;,
 4;151,153,128,123;,
 4;151,92,97,153;,
 4;152,154,99,95;,
 4;152,127,130,154;,
 4;153,155,131,128;,
 4;153,97,101,155;,
 4;156,157,105,104;,
 4;156,133,136,157;,
 4;158,159,138,137;,
 4;158,109,108,159;,
 4;157,160,111,105;,
 4;157,136,142,160;,
 4;159,161,143,138;,
 4;159,108,113,161;,
 4;160,162,115,111;,
 4;160,142,146,162;,
 4;161,163,147,143;,
 4;161,113,117,163;,
 4;164,165,50,55;,
 4;164,18,16,165;,
 4;164,166,19,18;,
 4;164,55,57,166;,
 4;165,167,51,50;,
 4;165,16,17,167;,
 4;166,168,169,19;,
 4;166,57,56,168;,
 4;167,170,52,51;,
 4;167,17,171,170;,
 4;172,173,73,174;,
 4;172,65,64,173;,
 4;175,176,63,62;,
 4;175,177,70,176;,
 4;173,178,68,73;,
 4;173,64,59,178;,
 4;176,179,58,63;,
 4;176,70,69,179;,
 4;178,179,69,68;,
 4;178,59,58,179;,
 4;180,181,182,183;,
 4;184,185,186,187;,
 4;188,189,190,191;,
 4;192,193,194,195;,
 4;192,185,196,197;,
 4;198,199,186,195;;
 
 MeshMaterialList {
  9;
  128;
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
  140;
  0.999550;-0.008283;-0.028826;,
  0.000000;-1.000000;0.000000;,
  -0.999407;-0.009584;-0.033071;,
  0.000000;1.000000;0.000000;,
  -0.014060;0.923183;0.384104;,
  -0.028183;0.920922;0.388727;,
  0.012161;0.923191;0.384150;,
  0.024376;0.920983;0.388839;,
  0.372379;-0.439621;-0.817354;,
  -0.340035;-0.446865;-0.827459;,
  0.948279;-0.130993;-0.289150;,
  -0.939261;-0.143636;-0.311699;,
  1.000000;0.000000;0.000000;,
  -1.000000;0.000000;0.000000;,
  0.199883;0.000000;0.979820;,
  -0.175336;0.000000;0.984509;,
  0.967424;0.227954;-0.110124;,
  -0.961512;0.245148;-0.124086;,
  0.369934;0.910421;-0.185156;,
  -0.334392;0.923150;-0.189673;,
  0.924526;0.356679;-0.134281;,
  -0.910062;0.386432;-0.149854;,
  0.259907;-0.274881;-0.925683;,
  -0.220845;-0.278616;-0.934666;,
  0.753743;-0.211480;-0.622212;,
  -0.436131;-0.291838;-0.851246;,
  0.270270;-0.222355;-0.936756;,
  -0.244825;-0.223525;-0.943450;,
  0.869866;-0.105517;-0.481871;,
  -0.856629;-0.110179;-0.504031;,
  0.998262;-0.058934;0.000001;,
  -0.998262;-0.058933;0.000000;,
  0.995311;-0.074652;0.061509;,
  -0.995311;-0.074651;0.061510;,
  0.988248;-0.090223;0.123390;,
  -0.988248;-0.090222;0.123391;,
  0.187345;-0.135894;0.972849;,
  -0.162468;-0.134297;0.977532;,
  0.361095;0.021625;-0.932278;,
  0.183668;0.019857;-0.982788;,
  0.999650;0.026472;0.000002;,
  -0.160745;0.019296;-0.986807;,
  0.982130;0.037642;0.184399;,
  -0.999650;0.026471;0.000000;,
  0.654447;0.047580;0.754609;,
  0.116397;0.029178;0.992774;,
  -0.982130;0.037641;0.184401;,
  -0.096071;0.028810;0.994957;,
  -0.638533;0.047752;0.768112;,
  -0.998262;-0.058933;0.000000;,
  -0.163479;-0.052320;-0.985158;,
  -0.979916;-0.075814;0.184435;,
  0.186680;-0.053577;-0.980959;,
  -0.668346;-0.121741;0.733820;,
  0.366843;-0.054319;-0.928696;,
  -0.138628;-0.133805;0.981264;,
  0.998262;-0.058934;0.000002;,
  0.164785;-0.135339;0.977000;,
  0.979917;-0.075815;0.184433;,
  0.687846;-0.121292;0.715651;,
  -0.692629;0.683779;-0.229588;,
  -0.863284;0.504718;0.000000;,
  -0.136862;0.463004;-0.875726;,
  -0.896273;0.412625;0.162589;,
  0.155182;0.469002;-0.869457;,
  -0.898110;0.314512;0.307377;,
  0.435128;0.678686;-0.591649;,
  -0.036057;0.423410;0.905220;,
  0.863284;0.504718;0.000000;,
  0.044004;0.423425;0.904862;,
  0.896273;0.412625;0.162589;,
  0.086676;0.394138;0.914955;,
  -0.692629;0.683779;-0.229588;,
  -0.863284;0.504718;0.000000;,
  -0.138958;0.463169;-0.875308;,
  -0.899361;0.419221;0.124107;,
  0.157518;0.469216;-0.868921;,
  -0.913465;0.332083;0.235166;,
  0.438056;0.678247;-0.589990;,
  -0.045204;0.429830;0.901778;,
  0.863284;0.504719;0.000001;,
  0.054898;0.430035;0.901142;,
  0.899361;0.419222;0.124106;,
  0.107862;0.406993;0.907041;,
  -0.013246;0.592516;0.805450;,
  0.014984;0.592722;0.805268;,
  -0.026305;0.623859;0.781094;,
  0.029765;0.624249;0.780658;,
  -0.997543;-0.028786;-0.063873;,
  0.998133;-0.025000;-0.055734;,
  -0.865469;-0.312667;-0.391411;,
  0.885562;-0.291150;-0.361956;,
  -0.283095;-0.560054;-0.778586;,
  0.320088;-0.551958;-0.769991;,
  0.000000;0.000000;-1.000000;,
  0.000000;0.000000;1.000000;,
  0.999919;-0.005780;-0.011345;,
  -0.999897;-0.006529;-0.012815;,
  0.391699;0.000000;0.920094;,
  -0.345239;0.000000;0.938515;,
  -0.345239;0.000000;0.938515;,
  -0.202065;0.045811;-0.978300;,
  0.239065;0.045363;-0.969943;,
  0.462044;0.043107;-0.885809;,
  -0.398094;0.044642;-0.916258;,
  0.367948;-0.130362;0.920663;,
  -0.320490;-0.128413;0.938508;,
  -0.322585;-0.052282;-0.945096;,
  -0.317314;0.020677;-0.948095;,
  0.998262;-0.058933;0.000004;,
  0.999650;0.026472;0.000004;,
  -0.998599;0.052924;0.000000;,
  -0.998599;0.052924;0.000000;,
  -0.306421;0.043015;-0.950924;,
  -0.155088;0.041299;-0.987037;,
  -0.979361;0.055499;0.194349;,
  0.177344;0.042391;-0.983236;,
  -0.922763;0.055957;0.381284;,
  0.349061;0.044855;-0.936026;,
  -0.071055;0.394352;0.916208;,
  -0.093855;0.044977;0.994569;,
  -0.046980;0.043744;0.997938;,
  0.998599;0.052924;0.000000;,
  0.998599;0.052924;0.000000;,
  0.057310;0.044172;0.997379;,
  0.979361;0.055499;0.194349;,
  0.114431;0.045785;0.992376;,
  0.898110;0.314512;0.307377;,
  0.922763;0.055957;0.381284;,
  -0.313803;0.043125;-0.948508;,
  -0.088865;0.406974;0.909107;,
  0.998599;0.052924;0.000002;,
  0.913465;0.332084;0.235165;,
  0.055795;0.466480;0.882770;,
  -0.048819;0.466254;0.883303;,
  -0.097126;0.542225;0.834601;,
  0.110961;0.542298;0.832827;,
  -0.997182;-0.042327;-0.061932;,
  0.997789;-0.037498;-0.054868;,
  -0.997259;-0.021336;-0.070853;;
  128;
  4;3,3,3,3;,
  4;3,3,3,3;,
  4;3,3,3,3;,
  4;1,1,1,1;,
  4;1,1,1,1;,
  4;1,1,1,1;,
  4;4,3,3,5;,
  4;4,6,3,3;,
  4;6,7,3,3;,
  4;1,1,1,1;,
  4;1,1,1,1;,
  4;1,1,1,1;,
  4;1,1,1,1;,
  4;1,1,1,1;,
  4;1,1,1,1;,
  4;10,0,96,12;,
  4;11,13,97,2;,
  4;12,96,12,12;,
  4;13,13,13,97;,
  4;12,12,12,12;,
  4;13,13,13,13;,
  4;98,98,14,14;,
  4;99,15,15,100;,
  4;14,14,15,15;,
  4;18,20,16,18;,
  4;18,18,19,19;,
  4;19,19,17,21;,
  4;22,23,101,102;,
  4;22,102,103,24;,
  4;23,25,104,101;,
  4;26,27,9,8;,
  4;26,8,10,28;,
  4;27,29,11,9;,
  4;28,10,12,30;,
  4;29,31,13,11;,
  4;30,12,12,32;,
  4;31,33,13,13;,
  4;32,12,12,34;,
  4;33,35,13,13;,
  4;105,98,14,36;,
  4;106,37,15,99;,
  4;36,14,15,37;,
  4;49,49,31,29;,
  4;49,43,43,49;,
  4;107,50,41,108;,
  4;107,29,27,50;,
  4;49,51,33,31;,
  4;49,43,46,51;,
  4;50,52,39,41;,
  4;50,27,26,52;,
  4;51,53,35,33;,
  4;51,46,48,53;,
  4;52,54,38,39;,
  4;52,26,28,54;,
  4;53,55,37,106;,
  4;53,48,47,55;,
  4;109,56,40,110;,
  4;109,28,30,56;,
  4;55,57,36,37;,
  4;55,47,45,57;,
  4;56,58,42,40;,
  4;56,30,32,58;,
  4;57,59,105,36;,
  4;57,45,44,59;,
  4;58,59,44,42;,
  4;58,32,34,59;,
  4;60,111,112,61;,
  4;113,62,114,113;,
  4;61,112,115,63;,
  4;62,64,116,114;,
  4;63,115,117,65;,
  4;64,66,118,116;,
  4;119,120,121,67;,
  4;122,68,123,122;,
  4;67,121,124,69;,
  4;68,70,125,123;,
  4;69,124,126,71;,
  4;70,127,128,125;,
  4;72,73,43,43;,
  4;72,60,61,73;,
  4;72,74,62,60;,
  4;129,108,41,74;,
  4;73,75,46,43;,
  4;73,61,63,75;,
  4;74,76,64,62;,
  4;74,41,39,76;,
  4;75,77,48,46;,
  4;75,63,65,77;,
  4;76,78,66,64;,
  4;76,39,38,78;,
  4;130,79,47,48;,
  4;130,119,67,79;,
  4;78,80,68,66;,
  4;131,110,40,80;,
  4;79,81,45,47;,
  4;79,67,69,81;,
  4;80,82,70,68;,
  4;80,40,42,82;,
  4;81,83,44,45;,
  4;81,69,71,83;,
  4;82,132,127,70;,
  4;82,42,44,132;,
  4;84,85,133,134;,
  4;84,6,4,85;,
  4;84,86,7,6;,
  4;84,134,135,86;,
  4;85,87,136,133;,
  4;85,4,5,87;,
  4;137,88,2,97;,
  4;137,21,17,88;,
  4;138,89,16,20;,
  4;138,96,0,89;,
  4;88,90,11,2;,
  4;88,17,139,90;,
  4;89,91,24,16;,
  4;89,0,10,91;,
  4;90,92,9,11;,
  4;90,25,23,92;,
  4;91,93,22,24;,
  4;91,10,8,93;,
  4;92,93,8,9;,
  4;92,23,22,93;,
  4;94,94,94,94;,
  4;12,12,12,12;,
  4;95,95,95,95;,
  4;13,13,13,13;,
  4;3,3,3,3;,
  4;1,1,1,1;;
 }
 MeshTextureCoords {
  200;
  0.303460;0.350320;,
  0.303460;0.000000;,
  0.000000;0.000000;,
  0.000000;0.350320;,
  0.648810;0.350320;,
  0.648810;0.000000;,
  1.000000;0.350320;,
  1.000000;0.000000;,
  0.000000;0.649680;,
  0.000000;1.000000;,
  0.303460;1.000000;,
  0.303460;0.649680;,
  0.648810;1.000000;,
  0.648810;0.649680;,
  1.000000;0.649680;,
  1.000000;1.000000;,
  0.303460;0.645440;,
  0.000000;0.645440;,
  0.648810;0.645440;,
  1.000000;0.645440;,
  0.000000;0.354560;,
  0.303460;0.354560;,
  0.303460;0.000000;,
  0.000000;0.000000;,
  0.648810;0.354560;,
  0.648810;0.000000;,
  1.000000;0.354560;,
  1.000000;0.000000;,
  1.000000;0.169740;,
  1.000000;0.000000;,
  0.645440;0.000000;,
  0.645440;0.169740;,
  0.000000;0.169740;,
  0.354560;0.169740;,
  0.354560;0.000000;,
  0.000000;0.000000;,
  0.350320;0.000000;,
  0.350320;0.169740;,
  0.649680;0.169740;,
  0.649680;0.000000;,
  0.000000;0.169740;,
  1.000000;0.169740;,
  1.000000;0.169740;,
  1.000000;0.000000;,
  0.696540;0.000000;,
  0.696540;0.169740;,
  0.000000;0.169740;,
  0.351190;0.169740;,
  0.351190;0.000000;,
  0.000000;0.000000;,
  0.303460;0.645440;,
  0.000000;0.645440;,
  0.000000;1.000000;,
  0.303460;1.000000;,
  0.648810;1.000000;,
  0.648810;0.645440;,
  1.000000;1.000000;,
  1.000000;0.645440;,
  0.303460;0.169740;,
  0.648810;0.169740;,
  0.648810;0.000000;,
  0.303460;0.000000;,
  0.000000;0.000000;,
  0.000000;0.169740;,
  1.000000;0.169740;,
  1.000000;0.000000;,
  0.303460;0.359040;,
  0.648810;0.359040;,
  0.648810;0.169740;,
  0.303460;0.169740;,
  0.000000;0.169740;,
  0.000000;0.359040;,
  1.000000;0.359040;,
  1.000000;0.169740;,
  1.000000;0.359040;,
  0.645440;0.359040;,
  0.000000;0.359040;,
  0.354560;0.359040;,
  0.350320;0.359040;,
  0.649680;0.359040;,
  0.000000;0.359040;,
  1.000000;0.359040;,
  1.000000;0.359040;,
  0.696540;0.359040;,
  0.000000;0.359040;,
  0.351190;0.359040;,
  0.000000;0.524590;,
  0.354560;0.524590;,
  0.000000;0.620180;,
  0.354560;0.620180;,
  1.000000;0.524590;,
  0.648810;0.524590;,
  0.648810;0.620180;,
  1.000000;0.620180;,
  0.649680;0.524590;,
  0.649680;0.620180;,
  0.303460;0.524590;,
  0.303460;0.620180;,
  1.000000;0.524590;,
  1.000000;0.620180;,
  0.000000;0.524590;,
  0.000000;0.620180;,
  0.000000;0.524590;,
  0.351190;0.524590;,
  0.000000;0.620180;,
  0.351190;0.620180;,
  1.000000;0.524590;,
  0.645440;0.524590;,
  0.645440;0.620180;,
  1.000000;0.620180;,
  0.696540;0.524590;,
  0.696540;0.620180;,
  0.350320;0.524590;,
  0.350320;0.620180;,
  1.000000;0.524590;,
  1.000000;0.620180;,
  0.000000;0.524590;,
  0.000000;0.620180;,
  0.000000;0.892170;,
  0.000000;1.000000;,
  0.354560;1.000000;,
  0.354560;0.892170;,
  1.000000;0.892170;,
  0.648810;0.892170;,
  0.648810;1.000000;,
  1.000000;1.000000;,
  0.649680;1.000000;,
  0.649680;0.892170;,
  0.303460;0.892170;,
  0.303460;1.000000;,
  1.000000;0.892170;,
  0.000000;0.892170;,
  0.000000;1.000000;,
  0.000000;0.892170;,
  0.000000;1.000000;,
  0.351190;1.000000;,
  0.351190;0.892170;,
  1.000000;0.892170;,
  0.645440;0.892170;,
  0.645440;1.000000;,
  1.000000;1.000000;,
  0.696540;1.000000;,
  0.696540;0.892170;,
  0.350320;0.892170;,
  0.350320;1.000000;,
  1.000000;1.000000;,
  1.000000;0.892170;,
  0.000000;0.892170;,
  0.000000;0.868460;,
  0.354560;0.868460;,
  1.000000;0.868460;,
  0.648810;0.868460;,
  0.649680;0.868460;,
  0.303460;0.868460;,
  1.000000;0.868460;,
  0.000000;0.868460;,
  0.000000;0.868460;,
  0.351190;0.868460;,
  1.000000;0.868460;,
  0.645440;0.868460;,
  0.696540;0.868460;,
  0.350320;0.868460;,
  1.000000;0.868460;,
  0.000000;0.868460;,
  0.648810;0.645440;,
  0.303460;0.645440;,
  1.000000;0.645440;,
  0.000000;0.645440;,
  1.000000;1.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;1.000000;,
  1.000000;0.000000;,
  1.000000;0.169740;,
  1.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.169740;,
  0.000000;0.000000;,
  0.648810;0.169740;,
  0.303460;0.169740;,
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
  1.000000;0.000000;;
 }
}
