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
 76;
 -0.33361;-0.30094;4.19084;,
 1.63815;-0.30094;3.14885;,
 1.63815;-0.30094;-2.49594;,
 -0.33361;-0.30094;-3.53793;,
 -2.54507;-0.30094;-2.49594;,
 -2.54507;-0.30094;3.14885;,
 -0.20397;-3.27555;-7.71791;,
 -0.33361;-0.30094;-3.53793;,
 1.63815;-0.30094;-2.49594;,
 3.90057;-3.27555;-5.54884;,
 -4.80749;-3.27555;-5.54884;,
 -2.54507;-0.30094;-2.49594;,
 3.90057;-3.27555;-5.54884;,
 1.63815;-0.30094;-2.49594;,
 3.90057;-3.27555;6.20174;,
 -4.80749;-3.27555;-5.54884;,
 -4.80749;-3.27555;6.20174;,
 -2.54507;-0.30094;-2.49594;,
 3.90057;-3.27555;6.20174;,
 1.63815;-0.30094;3.14885;,
 -0.33361;-0.30094;4.19084;,
 -0.20397;-3.27555;8.37081;,
 -4.80749;-3.27555;6.20174;,
 -2.54507;-0.30094;3.14885;,
 -0.12848;-8.28747;-10.15187;,
 5.21797;-8.28747;-7.32652;,
 -6.12489;-8.28747;-7.32652;,
 5.21797;-8.28747;-7.32652;,
 5.21797;-8.28747;7.97943;,
 -6.12489;-8.28747;-7.32652;,
 -6.12489;-8.28747;7.97943;,
 5.21797;-8.28747;7.97943;,
 -0.12848;-8.28747;10.80478;,
 -6.12489;-8.28747;7.97943;,
 4.04395;-23.89772;-3.60784;,
 4.04395;-23.89772;4.26075;,
 4.04395;-23.89772;-3.60784;,
 -0.19575;-25.79865;-5.06032;,
 4.04395;-23.89772;4.26075;,
 -0.19575;-25.79865;5.71323;,
 -4.95088;-23.89772;-3.60784;,
 -4.95088;-23.89772;4.26075;,
 -4.95088;-23.89772;-3.60784;,
 -4.95088;-23.89772;4.26075;,
 -0.09982;-32.14769;7.23957;,
 -7.34266;-29.10341;5.31654;,
 -7.34266;-29.10341;-4.66363;,
 -0.09982;-32.14769;-6.58666;,
 6.49393;-29.08494;-4.64940;,
 6.49393;-29.08494;5.30231;,
 6.88166;-26.12961;6.20472;,
 5.77159;-26.12961;-5.55181;,
 6.49393;-29.08494;-4.64940;,
 -0.09021;-28.70906;9.04417;,
 6.88166;-26.12961;6.20472;,
 -0.09982;-32.14769;7.23957;,
 6.49393;-29.08494;5.30231;,
 -7.74784;-26.13213;6.22607;,
 -7.34266;-29.10341;5.31654;,
 -6.63777;-26.13213;-5.57316;,
 -7.74784;-26.13213;6.22607;,
 -7.34266;-29.10341;-4.66363;,
 3.65071;-18.86275;-8.83132;,
 -0.21087;-16.52415;-9.61349;,
 6.70706;-24.83825;-9.51273;,
 5.77159;-26.12961;-5.55181;,
 -0.09724;-30.32466;-11.75990;,
 6.80016;-29.79838;-5.89354;,
 6.49393;-29.08494;-4.64940;,
 -0.08939;-35.31824;-6.62994;,
 -0.09982;-32.14769;-6.58666;,
 -4.54599;-18.85442;-8.82842;,
 -7.53154;-24.87133;-9.55764;,
 -6.63777;-26.13213;-5.57316;,
 -7.57527;-29.87120;-5.93938;,
 -7.34266;-29.10341;-4.66363;;
 
 42;
 4;0,1,2,3;,
 4;0,3,4,5;,
 4;6,7,8,9;,
 4;6,10,11,7;,
 4;12,13,1,14;,
 4;15,16,5,17;,
 4;18,19,20,21;,
 4;22,21,20,23;,
 4;24,6,9,25;,
 4;24,26,10,6;,
 4;27,12,14,28;,
 4;29,30,16,15;,
 4;31,18,21,32;,
 4;33,32,21,22;,
 4;34,27,28,35;,
 4;36,37,24,25;,
 4;38,31,32,39;,
 4;37,40,26,24;,
 4;39,32,33,41;,
 4;42,43,30,29;,
 4;44,45,46,47;,
 4;44,47,48,49;,
 4;50,51,34,35;,
 4;51,50,49,52;,
 4;53,54,38,39;,
 4;54,53,55,56;,
 4;57,53,39,41;,
 4;53,57,58,55;,
 4;59,60,43,42;,
 4;59,61,45,60;,
 4;62,63,37,36;,
 4;64,62,36,65;,
 4;64,66,63,62;,
 4;67,64,65,68;,
 4;69,67,68,70;,
 4;64,67,69,66;,
 4;71,72,73,40;,
 4;63,71,40,37;,
 4;66,72,71,63;,
 4;74,69,70,75;,
 4;72,74,75,73;,
 4;66,69,74,72;;
 
 MeshMaterialList {
  5;
  42;
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2;;
  Material {
   0.339200;0.339200;0.339200;1.000000;;
   5.000000;
   0.830000;0.830000;0.830000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.000000;0.078400;0.564800;1.000000;;
   5.000000;
   0.800000;0.800000;0.800000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.241600;0.269600;0.156800;1.000000;;
   5.000000;
   0.430000;0.430000;0.430000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.000000;0.138400;0.003200;1.000000;;
   5.000000;
   0.620000;0.620000;0.620000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.012800;0.012800;0.012800;1.000000;;
   5.000000;
   0.590000;0.590000;0.590000;;
   0.000000;0.000000;0.000000;;
  }
 }
 MeshNormals {
  67;
  -0.397303;0.893061;-0.211169;,
  0.405024;0.891095;-0.204708;,
  0.405024;0.891095;0.204708;,
  -0.397303;0.893061;0.211169;,
  0.006462;0.954530;0.298044;,
  0.006462;0.954531;-0.298043;,
  0.016867;0.651066;-0.758833;,
  0.710979;0.585522;-0.389453;,
  -0.699900;0.589483;-0.403298;,
  0.710979;0.585522;0.389453;,
  -0.699900;0.589483;0.403298;,
  0.016867;0.651066;0.758833;,
  0.022481;0.088406;-0.995831;,
  0.855704;0.100509;-0.507610;,
  -0.415238;0.078389;-0.906329;,
  0.855704;0.100509;0.507610;,
  -0.995864;0.090861;0.000000;,
  0.022481;0.088407;0.995831;,
  0.920456;0.376795;0.103859;,
  0.933762;0.357343;-0.019884;,
  0.021695;-0.272575;-0.961890;,
  0.021695;-0.272575;0.961890;,
  -0.394449;-0.248960;-0.884550;,
  -0.394450;-0.248960;0.884550;,
  -0.387481;-0.921878;0.000000;,
  0.421267;-0.906937;-0.000000;,
  0.495887;-0.731052;0.468678;,
  0.018471;-0.999829;-0.000000;,
  0.919109;0.377305;0.113491;,
  0.904741;0.423607;-0.044732;,
  0.000246;0.699491;0.714642;,
  -0.925265;0.365674;0.100834;,
  0.017525;0.700409;0.713527;,
  -0.213104;0.555262;0.803910;,
  -0.009200;0.569301;0.822077;,
  -0.866961;0.388701;0.311913;,
  -0.069874;-0.478350;0.875385;,
  0.949500;0.248337;0.191779;,
  0.002744;-0.480081;0.877220;,
  0.909706;0.324452;0.259164;,
  0.018737;-0.228352;-0.973398;,
  -0.921233;0.309617;0.235513;,
  -0.415238;0.078390;0.906329;,
  0.433940;-0.247205;-0.866364;,
  0.433940;-0.247205;0.866364;,
  -0.923428;0.370683;0.099371;,
  -0.935395;0.353040;-0.019954;,
  0.996478;0.069100;-0.047501;,
  0.984323;0.160567;0.072979;,
  -0.017033;0.698363;0.715541;,
  0.443480;-0.367898;0.817299;,
  0.019521;-0.409110;0.912276;,
  -0.408156;-0.372404;0.833501;,
  -0.907932;0.416726;-0.044705;,
  -0.987810;0.145774;0.054609;,
  -0.996883;0.063148;-0.047298;,
  0.859071;0.396701;0.323459;,
  0.439286;-0.201231;-0.875519;,
  0.011888;0.174524;-0.984581;,
  0.223359;0.172101;-0.959423;,
  0.075347;-0.479277;0.874423;,
  0.570412;-0.535718;-0.622605;,
  0.195092;0.559371;0.805632;,
  -0.405470;-0.212717;-0.889014;,
  -0.200123;0.169030;-0.965080;,
  -0.961653;0.225878;0.155572;,
  -0.532284;-0.553264;-0.640760;;
  42;
  4;4,2,1,5;,
  4;4,5,0,3;,
  4;6,5,1,7;,
  4;6,8,0,5;,
  4;7,1,2,9;,
  4;8,10,3,0;,
  4;9,2,4,11;,
  4;10,11,4,3;,
  4;12,6,7,13;,
  4;12,14,8,6;,
  4;13,7,9,15;,
  4;16,16,10,8;,
  4;15,9,11,17;,
  4;42,17,11,10;,
  4;18,13,15,19;,
  4;43,20,12,13;,
  4;44,15,17,21;,
  4;20,22,14,12;,
  4;21,17,42,23;,
  4;45,46,16,16;,
  4;27,24,24,27;,
  4;27,27,25,26;,
  4;29,28,18,19;,
  4;28,29,47,48;,
  4;30,49,49,30;,
  4;50,51,51,26;,
  4;32,30,30,32;,
  4;51,52,52,51;,
  4;31,53,46,45;,
  4;31,54,55,53;,
  4;33,34,34,33;,
  4;39,56,18,28;,
  4;57,40,58,59;,
  4;37,39,28,48;,
  4;38,60,60,38;,
  4;57,61,61,40;,
  4;35,41,31,45;,
  4;34,62,62,34;,
  4;40,63,64,58;,
  4;36,38,38,36;,
  4;41,65,54,31;,
  4;40,66,66,63;;
 }
 MeshTextureCoords {
  76;
  0.528650;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.528650;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  0.528650;0.170080;,
  0.528650;0.000000;,
  1.000000;0.000000;,
  1.000000;0.170080;,
  0.000000;0.170080;,
  0.000000;0.000000;,
  0.000000;0.170080;,
  0.000000;0.000000;,
  1.000000;0.170080;,
  1.000000;0.170080;,
  0.000000;0.170080;,
  1.000000;0.000000;,
  0.000000;0.170080;,
  0.000000;0.000000;,
  0.471350;0.000000;,
  0.471350;0.170080;,
  1.000000;0.170080;,
  1.000000;0.000000;,
  0.528650;0.382980;,
  1.000000;0.382980;,
  0.000000;0.382980;,
  0.000000;0.382980;,
  1.000000;0.382980;,
  1.000000;0.382980;,
  0.000000;0.382980;,
  0.000000;0.382980;,
  0.471350;0.382980;,
  1.000000;0.382980;,
  0.000000;0.932840;,
  1.000000;0.932840;,
  1.000000;0.932840;,
  0.528650;0.932840;,
  0.000000;0.932840;,
  0.471350;0.932840;,
  0.000000;0.932840;,
  1.000000;0.932840;,
  1.000000;0.932840;,
  0.000000;0.932840;,
  0.528650;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  0.528650;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  1.000000;0.932840;,
  0.000000;0.932840;,
  0.000000;1.000000;,
  0.471350;0.932840;,
  0.000000;0.932840;,
  0.471350;1.000000;,
  0.000000;1.000000;,
  1.000000;0.932840;,
  1.000000;1.000000;,
  1.000000;0.932840;,
  0.000000;0.932840;,
  1.000000;1.000000;,
  1.000000;0.932840;,
  0.528650;0.932840;,
  1.000000;0.932840;,
  1.000000;0.932840;,
  0.528650;0.932840;,
  1.000000;1.000000;,
  1.000000;1.000000;,
  0.528650;1.000000;,
  0.528650;1.000000;,
  0.000000;0.932840;,
  0.000000;0.932840;,
  0.000000;0.932840;,
  0.000000;1.000000;,
  0.000000;1.000000;;
 }
}