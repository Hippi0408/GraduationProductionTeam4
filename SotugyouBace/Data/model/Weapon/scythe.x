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
 122;
 0.65295;52.13632;0.24992;,
 0.23421;52.13632;1.26085;,
 0.23421;25.09385;1.26085;,
 0.65295;25.09385;0.24992;,
 -0.77672;52.13632;1.67958;,
 -0.77672;25.09385;1.67958;,
 -1.78765;52.13632;1.26085;,
 -1.78765;25.09385;1.26085;,
 -2.20639;52.13632;0.24992;,
 -2.20639;25.09385;0.24992;,
 -1.78765;52.13632;-0.76102;,
 -1.78765;25.09385;-0.76102;,
 -0.77672;52.13632;-1.17975;,
 -0.77672;25.09385;-1.17975;,
 0.23421;52.13632;-0.76102;,
 0.23421;25.09385;-0.76102;,
 0.65295;52.13632;0.24992;,
 0.65295;25.09385;0.24992;,
 0.23421;-14.79750;1.26085;,
 0.65295;-14.79750;0.24992;,
 -0.77672;-14.79750;1.67958;,
 -1.78765;-14.79750;1.26085;,
 -2.20639;-14.79750;0.24992;,
 -1.78765;-14.79750;-0.76102;,
 -0.77672;-14.79750;-1.17975;,
 0.23421;-14.79750;-0.76102;,
 0.65295;-14.79750;0.24992;,
 -0.77672;57.69397;0.24992;,
 -0.77672;57.69397;0.24992;,
 -0.77672;57.69397;0.24992;,
 -0.77672;57.69397;0.24992;,
 -0.77672;57.69397;0.24992;,
 -0.77672;57.69397;0.24992;,
 -0.77672;57.69397;0.24992;,
 -0.77672;57.69397;0.24992;,
 -0.77672;-35.36915;0.24992;,
 -0.77672;-35.36915;0.24992;,
 -0.77672;-35.36915;0.24992;,
 -0.77672;-35.36915;0.24992;,
 -0.77672;-35.36915;0.24992;,
 -0.77672;-35.36915;0.24992;,
 -0.77672;-35.36915;0.24992;,
 -0.77672;-35.36915;0.24992;,
 -0.44015;44.00436;7.22750;,
 -0.53873;37.66820;7.22750;,
 -0.53873;43.87597;0.15880;,
 -0.44015;46.03352;0.15880;,
 -0.77672;35.04361;7.22750;,
 -0.77672;42.98227;0.15880;,
 -1.01471;37.66820;7.22750;,
 -1.01471;43.87597;0.15880;,
 -1.11329;44.00436;7.22750;,
 -1.11329;46.03352;0.15880;,
 -2.32912;51.24844;7.22750;,
 -1.54130;48.50021;0.15880;,
 -0.77672;52.05739;7.22750;,
 -0.77672;48.77564;0.15880;,
 0.77568;51.24844;7.22750;,
 -0.01214;48.50021;0.15880;,
 -0.44015;44.00436;7.22750;,
 -0.44015;46.03352;0.15880;,
 -0.53873;47.38145;-15.36652;,
 -0.44015;50.47254;-14.69166;,
 -0.77672;43.38427;-14.69166;,
 -1.01471;47.38145;-15.36652;,
 -1.11329;50.47254;-14.69166;,
 -2.32912;56.20285;-14.69166;,
 -0.77672;56.84269;-14.69166;,
 0.77568;56.20285;-14.69166;,
 -0.44015;50.47254;-14.69166;,
 -0.53873;50.39840;-24.91431;,
 -0.44015;53.90985;-23.29896;,
 -0.77672;45.70210;-23.29896;,
 -1.01471;50.39840;-24.91431;,
 -1.11329;53.90985;-23.29896;,
 -2.32912;59.64014;-23.29896;,
 -0.77672;60.27998;-23.29896;,
 0.77568;59.64014;-23.29896;,
 -0.44015;53.90985;-23.29896;,
 -0.53873;50.90683;-33.89117;,
 -0.44015;55.41684;-31.02499;,
 -0.77672;46.53532;-33.47889;,
 -1.01471;50.90683;-33.89117;,
 -1.11329;55.41684;-31.02499;,
 -2.32912;61.14714;-31.02499;,
 -0.77672;61.78698;-31.02499;,
 0.77568;61.14714;-31.02499;,
 -0.44015;55.41684;-31.02499;,
 -0.53874;50.45617;-43.91538;,
 -0.44016;54.04898;-43.91538;,
 -0.77672;46.14870;-43.91538;,
 -1.01472;50.45617;-43.91538;,
 -1.11329;54.04898;-43.91538;,
 -2.32913;59.77926;-43.91538;,
 -0.77672;60.41911;-43.91538;,
 0.77567;59.77926;-43.91538;,
 -0.44016;54.04898;-43.91538;,
 -0.53874;48.27896;-54.69941;,
 -0.44016;51.30570;-55.86948;,
 -0.77672;44.41330;-54.21478;,
 -1.01472;48.27896;-54.69941;,
 -1.11330;51.30570;-55.86948;,
 -2.32913;56.87768;-57.20721;,
 -0.77672;57.49978;-57.35655;,
 0.77567;56.87768;-57.20721;,
 -0.44016;51.30570;-55.86948;,
 -0.77672;33.52507;22.39212;,
 -0.77672;33.52507;22.39212;,
 -0.77672;33.52507;22.39212;,
 -0.77672;33.52507;22.39212;,
 -0.77672;33.52507;22.39212;,
 -0.77672;33.52507;22.39212;,
 -0.77672;33.52507;22.39212;,
 -0.77672;33.52507;22.39212;,
 -0.77673;36.74696;-76.42659;,
 -0.77673;36.74696;-76.42659;,
 -0.77673;36.74696;-76.42659;,
 -0.77673;36.74696;-76.42659;,
 -0.77673;36.74696;-76.42659;,
 -0.77673;36.74696;-76.42659;,
 -0.77673;36.74696;-76.42659;,
 -0.77673;36.74696;-76.42659;;
 
 96;
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
 4;43,44,45,46;,
 4;44,47,48,45;,
 4;47,49,50,48;,
 4;49,51,52,50;,
 4;51,53,54,52;,
 4;53,55,56,54;,
 4;55,57,58,56;,
 4;57,59,60,58;,
 4;46,45,61,62;,
 4;45,48,63,61;,
 4;48,50,64,63;,
 4;50,52,65,64;,
 4;52,54,66,65;,
 4;54,56,67,66;,
 4;56,58,68,67;,
 4;58,60,69,68;,
 4;62,61,70,71;,
 4;61,63,72,70;,
 4;63,64,73,72;,
 4;64,65,74,73;,
 4;65,66,75,74;,
 4;66,67,76,75;,
 4;67,68,77,76;,
 4;68,69,78,77;,
 4;71,70,79,80;,
 4;70,72,81,79;,
 4;72,73,82,81;,
 4;73,74,83,82;,
 4;74,75,84,83;,
 4;75,76,85,84;,
 4;76,77,86,85;,
 4;77,78,87,86;,
 4;80,79,88,89;,
 4;79,81,90,88;,
 4;81,82,91,90;,
 4;82,83,92,91;,
 4;83,84,93,92;,
 4;84,85,94,93;,
 4;85,86,95,94;,
 4;86,87,96,95;,
 4;89,88,97,98;,
 4;88,90,99,97;,
 4;90,91,100,99;,
 4;91,92,101,100;,
 4;92,93,102,101;,
 4;93,94,103,102;,
 4;94,95,104,103;,
 4;95,96,105,104;,
 3;106,44,43;,
 3;107,47,44;,
 3;108,49,47;,
 3;109,51,49;,
 3;110,53,51;,
 3;111,55,53;,
 3;112,57,55;,
 3;113,59,57;,
 3;114,98,97;,
 3;115,97,99;,
 3;116,99,100;,
 3;117,100,101;,
 3;118,101,102;,
 3;119,102,103;,
 3;120,103,104;,
 3;121,104,105;;
 
 MeshMaterialList {
  4;
  96;
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
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
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  0,
  1,
  1,
  0,
  0,
  0,
  0,
  0,
  0,
  1,
  1,
  0,
  0,
  0,
  0,
  0,
  0,
  1,
  1,
  0,
  0,
  0,
  0,
  0,
  0,
  1,
  1,
  0,
  0,
  0,
  0,
  0,
  0,
  1,
  1,
  0,
  0,
  0,
  0,
  0,
  0,
  1,
  1,
  0,
  0,
  0,
  0,
  0,
  0,
  1,
  1,
  0,
  0,
  0,
  0,
  0,
  0,
  1,
  1,
  0,
  0,
  0,
  0,
  0;;
  Material {
   0.213600;0.000000;0.204000;1.000000;;
   5.000000;
   0.720000;0.720000;0.720000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.000000;0.000000;0.000000;1.000000;;
   5.000000;
   0.890000;0.890000;0.890000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.304000;0.292000;0.000000;1.000000;;
   5.000000;
   0.820000;0.820000;0.820000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.800000;0.000000;0.646400;1.000000;;
   5.000000;
   0.760000;0.760000;0.760000;;
   0.000000;0.000000;0.000000;;
  }
 }
 MeshNormals {
  117;
  0.684810;0.249132;0.684813;,
  0.992050;0.125847;0.000002;,
  0.701483;0.125847;0.701487;,
  -0.000001;0.125846;0.992050;,
  -0.701484;0.125846;0.701486;,
  -0.992050;0.125847;0.000002;,
  -0.701485;0.125847;-0.701485;,
  -0.000001;0.125847;-0.992050;,
  0.701485;0.125847;-0.701485;,
  1.000000;0.000000;0.000002;,
  0.707105;0.000000;0.707108;,
  -0.000001;0.000000;1.000000;,
  -0.707106;0.000000;0.707108;,
  -1.000000;0.000000;0.000002;,
  -0.707107;0.000000;-0.707106;,
  -0.000001;0.000000;-1.000000;,
  0.707107;0.000000;-0.707107;,
  0.999398;-0.034692;0.000002;,
  0.706679;-0.034692;0.706683;,
  -0.000001;-0.034692;0.999398;,
  -0.706680;-0.034692;0.706682;,
  -0.999398;-0.034692;0.000002;,
  -0.706681;-0.034692;-0.706681;,
  -0.000001;-0.034692;-0.999398;,
  0.706681;-0.034692;-0.706681;,
  0.705404;-0.069330;0.705407;,
  -0.684810;0.249132;0.684813;,
  -0.684811;0.249133;-0.684811;,
  0.684811;0.249134;-0.684811;,
  -0.705404;-0.069330;0.705407;,
  -0.705406;-0.069330;-0.705405;,
  0.705405;-0.069330;-0.705405;,
  0.995446;-0.090488;-0.029988;,
  0.994839;-0.095078;-0.035447;,
  0.996068;-0.077284;-0.043316;,
  0.987636;-0.131321;-0.085612;,
  -0.996068;-0.077284;-0.043315;,
  -0.994839;-0.095078;-0.035447;,
  -0.983579;-0.166479;-0.069701;,
  -0.000001;0.913265;-0.407365;,
  0.371520;0.847898;-0.378208;,
  0.993811;-0.106670;-0.030998;,
  0.993735;-0.100454;-0.048976;,
  0.982291;-0.166321;-0.086269;,
  -0.993736;-0.100453;-0.048975;,
  -0.993811;-0.106670;-0.030998;,
  -0.982644;-0.178547;-0.050318;,
  -0.000001;0.999083;0.042807;,
  0.380881;0.923776;0.039581;,
  0.992537;-0.115566;-0.038916;,
  0.997393;-0.071198;-0.011748;,
  0.993827;-0.110062;-0.013946;,
  -0.997393;-0.071197;-0.011748;,
  -0.992537;-0.115566;-0.038915;,
  -0.977849;-0.197962;-0.067994;,
  -0.000000;0.905549;0.424241;,
  0.340070;0.851579;0.398957;,
  0.992588;-0.116655;-0.034063;,
  0.999133;-0.040768;-0.008396;,
  0.998351;-0.056433;-0.010514;,
  -0.999133;-0.040768;-0.008396;,
  -0.992588;-0.116655;-0.034063;,
  -0.976369;-0.207162;-0.061541;,
  -0.000000;0.959200;0.282729;,
  0.367656;0.892019;0.262927;,
  0.993183;-0.116462;-0.004943;,
  0.999230;-0.039221;-0.000673;,
  0.998540;-0.054006;-0.000720;,
  -0.999230;-0.039226;-0.000671;,
  -0.993183;-0.116461;-0.004942;,
  -0.978182;-0.207547;-0.009220;,
  0.000000;0.999050;0.043584;,
  0.380755;0.923797;0.040301;,
  0.992933;-0.117138;0.019060;,
  0.999119;-0.041645;0.005234;,
  0.998401;-0.056160;0.006438;,
  -0.999119;-0.041650;0.005235;,
  -0.992933;-0.117138;0.019061;,
  -0.977925;-0.206180;0.033935;,
  0.000000;0.987214;-0.159400;,
  0.378746;0.913667;-0.147525;,
  0.992665;-0.112870;0.043329;,
  0.998976;-0.043981;0.010605;,
  0.998180;-0.058284;0.015483;,
  -0.998976;-0.043982;0.010605;,
  -0.992665;-0.112870;0.043329;,
  -0.977451;-0.195179;0.080594;,
  0.000000;0.865618;-0.500705;,
  0.365485;0.805732;-0.466065;,
  0.994654;-0.091890;0.047105;,
  -0.987637;-0.131319;-0.085611;,
  -0.982291;-0.166319;-0.086268;,
  -0.371521;0.847898;-0.378208;,
  -0.380882;0.923776;0.039581;,
  0.983579;-0.166479;-0.069701;,
  0.982644;-0.178548;-0.050318;,
  -0.993827;-0.110061;-0.013946;,
  -0.340071;0.851578;0.398957;,
  0.977849;-0.197962;-0.067994;,
  -0.998351;-0.056433;-0.010513;,
  -0.367657;0.892019;0.262927;,
  0.976369;-0.207162;-0.061541;,
  -0.998540;-0.054016;-0.000717;,
  -0.380754;0.923798;0.040301;,
  0.978182;-0.207546;-0.009221;,
  -0.998400;-0.056171;0.006441;,
  -0.378746;0.913668;-0.147525;,
  0.977926;-0.206180;0.033934;,
  -0.998180;-0.058285;0.015484;,
  -0.365484;0.805732;-0.466065;,
  0.977451;-0.195179;0.080594;,
  -0.995446;-0.090487;-0.029987;,
  -0.000000;0.633283;0.773920;,
  -0.313376;0.601384;0.734937;,
  0.313376;0.601384;0.734937;,
  -0.994654;-0.091890;0.047105;,
  0.000000;0.676623;-0.736330;;
  96;
  4;1,2,10,9;,
  4;2,3,11,10;,
  4;3,4,12,11;,
  4;4,5,13,12;,
  4;5,6,14,13;,
  4;6,7,15,14;,
  4;7,8,16,15;,
  4;8,1,9,16;,
  4;9,10,18,17;,
  4;10,11,19,18;,
  4;11,12,20,19;,
  4;12,13,21,20;,
  4;13,14,22,21;,
  4;14,15,23,22;,
  4;15,16,24,23;,
  4;16,9,17,24;,
  3;0,2,1;,
  3;0,3,2;,
  3;26,4,3;,
  3;26,5,4;,
  3;27,6,5;,
  3;27,7,6;,
  3;28,8,7;,
  3;28,1,8;,
  3;25,17,18;,
  3;25,18,19;,
  3;29,19,20;,
  3;29,20,21;,
  3;30,21,22;,
  3;30,22,23;,
  3;31,23,24;,
  3;31,24,17;,
  4;33,34,42,41;,
  4;34,35,43,42;,
  4;90,36,44,91;,
  4;36,37,45,44;,
  4;37,38,46,45;,
  4;92,39,47,93;,
  4;39,40,48,47;,
  4;94,33,41,95;,
  4;41,42,50,49;,
  4;42,43,51,50;,
  4;91,44,52,96;,
  4;44,45,53,52;,
  4;45,46,54,53;,
  4;93,47,55,97;,
  4;47,48,56,55;,
  4;95,41,49,98;,
  4;49,50,58,57;,
  4;50,51,59,58;,
  4;96,52,60,99;,
  4;52,53,61,60;,
  4;53,54,62,61;,
  4;97,55,63,100;,
  4;55,56,64,63;,
  4;98,49,57,101;,
  4;57,58,66,65;,
  4;58,59,67,66;,
  4;99,60,68,102;,
  4;60,61,69,68;,
  4;61,62,70,69;,
  4;100,63,71,103;,
  4;63,64,72,71;,
  4;101,57,65,104;,
  4;65,66,74,73;,
  4;66,67,75,74;,
  4;102,68,76,105;,
  4;68,69,77,76;,
  4;69,70,78,77;,
  4;103,71,79,106;,
  4;71,72,80,79;,
  4;104,65,73,107;,
  4;73,74,82,81;,
  4;74,75,83,82;,
  4;105,76,84,108;,
  4;76,77,85,84;,
  4;77,78,86,85;,
  4;106,79,87,109;,
  4;79,80,88,87;,
  4;107,73,81,110;,
  3;32,34,33;,
  3;32,35,34;,
  3;111,36,90;,
  3;111,37,36;,
  3;111,38,37;,
  3;112,112,113;,
  3;112,114,112;,
  3;32,33,94;,
  3;89,81,82;,
  3;89,82,83;,
  3;115,108,84;,
  3;115,84,85;,
  3;115,85,86;,
  3;116,109,87;,
  3;116,87,88;,
  3;89,110,81;;
 }
 MeshTextureCoords {
  122;
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
  0.000000;0.000000;,
  0.125000;0.000000;,
  0.125000;0.166670;,
  0.000000;0.166670;,
  0.250000;0.000000;,
  0.250000;0.166670;,
  0.375000;0.000000;,
  0.375000;0.166670;,
  0.500000;0.000000;,
  0.500000;0.166670;,
  0.625000;0.000000;,
  0.625000;0.166670;,
  0.750000;0.000000;,
  0.750000;0.166670;,
  0.875000;0.000000;,
  0.875000;0.166670;,
  1.000000;0.000000;,
  1.000000;0.166670;,
  0.125000;0.333330;,
  0.000000;0.333330;,
  0.250000;0.333330;,
  0.375000;0.333330;,
  0.500000;0.333330;,
  0.625000;0.333330;,
  0.750000;0.333330;,
  0.875000;0.333330;,
  1.000000;0.333330;,
  0.125000;0.500000;,
  0.000000;0.500000;,
  0.250000;0.500000;,
  0.375000;0.500000;,
  0.500000;0.500000;,
  0.625000;0.500000;,
  0.750000;0.500000;,
  0.875000;0.500000;,
  1.000000;0.500000;,
  0.125000;0.666670;,
  0.000000;0.666670;,
  0.250000;0.666670;,
  0.375000;0.666670;,
  0.500000;0.666670;,
  0.625000;0.666670;,
  0.750000;0.666670;,
  0.875000;0.666670;,
  1.000000;0.666670;,
  0.125000;0.833330;,
  0.000000;0.833330;,
  0.250000;0.833330;,
  0.375000;0.833330;,
  0.500000;0.833330;,
  0.625000;0.833330;,
  0.750000;0.833330;,
  0.875000;0.833330;,
  1.000000;0.833330;,
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
  0.937500;1.000000;;
 }
}