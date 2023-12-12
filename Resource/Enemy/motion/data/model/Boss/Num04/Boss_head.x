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
 69;
 0.00000;13.06097;1.11584;,
 1.98699;9.00370;0.79652;,
 4.15694;11.37928;-1.24053;,
 0.00000;13.06347;-1.10798;,
 0.04247;-0.21570;-0.04841;,
 0.00000;-1.94762;-2.28938;,
 -1.98699;9.00370;0.79652;,
 -4.15694;11.37928;-1.24053;,
 0.00000;13.06097;1.11584;,
 0.00000;13.06347;-1.10798;,
 0.00000;8.88927;2.25045;,
 0.00000;8.88927;2.25045;,
 0.00000;8.88927;2.25045;,
 0.00000;8.88927;2.25045;,
 0.00000;7.81494;-4.36147;,
 0.00000;7.81494;-4.36147;,
 0.00000;7.81494;-4.36147;,
 0.00000;7.81494;-4.36147;,
 3.07048;13.84545;-0.27740;,
 6.12505;17.56384;1.02415;,
 1.82309;14.58198;-2.58365;,
 1.53524;13.56030;-2.21951;,
 3.64619;12.75668;-0.27740;,
 2.82763;11.53243;-2.58365;,
 3.07048;13.84545;-0.27740;,
 1.53524;13.56030;-2.21951;,
 -1.82309;14.58198;-2.58365;,
 -1.53524;13.56030;-2.21951;,
 -2.82763;11.53243;-2.58365;,
 -1.53524;13.56030;-2.21951;,
 -6.12505;17.97807;1.02415;,
 -3.07048;13.56030;-0.27740;,
 -3.64619;12.75668;-0.27740;,
 -3.07048;13.56030;-0.27740;,
 -1.82309;14.36389;2.02885;,
 -1.53524;13.56030;1.66471;,
 -1.82309;12.75668;2.02885;,
 -1.53524;13.56030;1.66471;,
 1.82309;14.36389;2.02885;,
 1.53524;13.56030;1.66471;,
 1.82309;12.75668;2.02885;,
 1.53524;13.56030;1.66471;,
 6.12505;17.56384;1.02415;,
 3.07048;13.84545;-0.27740;,
 3.64619;12.75668;-0.27740;,
 3.07048;13.84545;-0.27740;,
 0.00000;8.54259;-4.28449;,
 0.60481;8.29211;-4.28449;,
 0.00000;8.29211;-4.88929;,
 0.00000;8.54259;-4.28449;,
 0.00000;8.29211;-3.67968;,
 0.00000;8.54259;-4.28449;,
 -0.60481;8.29211;-4.28449;,
 0.00000;8.54259;-4.28449;,
 0.00000;8.29211;-4.88929;,
 0.85532;7.68729;-4.28449;,
 0.00000;7.68729;-5.13981;,
 0.00000;7.68729;-3.42916;,
 -0.85532;7.68729;-4.28449;,
 0.00000;7.68729;-5.13981;,
 0.60481;7.08248;-4.28449;,
 0.00000;7.08248;-4.88929;,
 0.00000;7.08248;-3.67968;,
 -0.60481;7.08248;-4.28449;,
 0.00000;7.08248;-4.88929;,
 0.00000;6.83201;-4.28449;,
 0.00000;6.83201;-4.28449;,
 0.00000;6.83201;-4.28449;,
 0.00000;6.83201;-4.28449;;
 
 46;
 4;0,1,2,3;,
 4;1,4,5,2;,
 4;4,6,7,5;,
 4;6,8,9,7;,
 3;10,1,0;,
 3;11,4,1;,
 3;12,6,4;,
 3;13,8,6;,
 3;14,3,2;,
 3;15,2,5;,
 3;16,5,7;,
 3;17,7,9;,
 4;18,19,20,21;,
 4;19,22,23,20;,
 4;22,24,25,23;,
 4;21,20,26,27;,
 4;20,23,28,26;,
 4;23,25,29,28;,
 4;27,26,30,31;,
 4;26,28,32,30;,
 4;28,29,33,32;,
 4;31,30,34,35;,
 4;30,32,36,34;,
 4;32,33,37,36;,
 4;35,34,38,39;,
 4;34,36,40,38;,
 4;36,37,41,40;,
 4;39,38,42,43;,
 4;38,40,44,42;,
 4;40,41,45,44;,
 3;46,47,48;,
 3;49,50,47;,
 3;51,52,50;,
 3;53,54,52;,
 4;48,47,55,56;,
 4;47,50,57,55;,
 4;50,52,58,57;,
 4;52,54,59,58;,
 4;56,55,60,61;,
 4;55,57,62,60;,
 4;57,58,63,62;,
 4;58,59,64,63;,
 3;61,60,65;,
 3;60,62,66;,
 3;62,63,67;,
 3;63,64,68;;
 
 MeshMaterialList {
  6;
  46;
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
  1,
  1,
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
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4;;
  Material {
   0.656000;0.656000;0.656000;1.000000;;
   5.000000;
   0.840000;0.840000;0.840000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.344800;0.344800;0.344800;1.000000;;
   5.000000;
   0.550000;0.550000;0.550000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.737600;0.737600;0.737600;1.000000;;
   5.000000;
   0.750000;0.750000;0.750000;;
   0.378020;0.378020;0.378020;;
  }
  Material {
   0.344800;0.344800;0.344800;1.000000;;
   5.000000;
   0.800000;0.800000;0.800000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.800000;0.019200;0.000000;1.000000;;
   5.000000;
   0.630000;0.630000;0.630000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.800000;0.800000;0.800000;1.000000;;
   5.000000;
   0.910000;0.910000;0.910000;;
   0.000000;0.000000;0.000000;;
  }
 }
 MeshNormals {
  69;
  0.590101;0.010319;0.807264;,
  0.635565;0.397913;0.661606;,
  0.733166;0.084431;0.674788;,
  0.751567;-0.238719;0.614948;,
  -0.730737;0.082280;0.677682;,
  0.667636;0.557977;0.492872;,
  0.852039;0.160509;0.498263;,
  0.872838;-0.267780;0.407980;,
  -0.848080;0.159098;0.505419;,
  0.255432;0.334448;-0.907138;,
  -0.746308;-0.242238;0.619955;,
  -0.865843;-0.270301;0.421015;,
  -0.635565;0.397913;0.661606;,
  -0.667636;0.557977;0.492872;,
  -0.590215;0.007658;0.807210;,
  0.000000;0.526870;-0.849946;,
  0.472202;0.200826;-0.858309;,
  0.674027;-0.153373;-0.722609;,
  -0.674027;-0.153373;-0.722609;,
  -0.472202;0.200826;-0.858309;,
  -0.793714;-0.022134;0.607888;,
  -0.741476;0.409229;0.531737;,
  0.803921;0.054692;-0.592216;,
  -0.427985;0.035550;0.903086;,
  -0.409628;0.411551;0.814144;,
  0.450502;0.030648;-0.892249;,
  0.425757;0.008025;0.904802;,
  0.402729;0.392160;0.827055;,
  -0.451834;0.033582;-0.891469;,
  0.791685;-0.073890;0.606445;,
  0.733539;0.378562;0.564456;,
  -0.805593;0.059876;-0.589436;,
  0.351133;0.513083;-0.783232;,
  -0.370401;-0.122011;0.920824;,
  -0.270718;-0.173569;-0.946882;,
  -0.360863;0.537136;-0.762406;,
  0.365428;-0.129763;0.921750;,
  -0.691495;-0.449189;0.565742;,
  -0.382254;-0.346011;0.856831;,
  0.381807;-0.383978;0.840705;,
  0.683689;-0.510836;0.521167;,
  0.649719;0.536643;-0.538405;,
  -0.682148;-0.224701;0.695833;,
  0.683887;-0.489932;-0.540615;,
  0.371477;-0.490313;-0.788415;,
  -0.371253;-0.461277;-0.805850;,
  -0.661198;0.571436;-0.486084;,
  0.673667;-0.239219;0.699247;,
  -0.686369;-0.440072;-0.578994;,
  0.000000;1.000000;-0.000003;,
  0.267626;0.791464;-0.549510;,
  0.549504;0.791466;-0.267631;,
  0.267629;0.791467;0.549504;,
  -0.549506;0.791467;0.267625;,
  0.707104;-0.000004;-0.707110;,
  0.707109;-0.000003;0.707105;,
  -0.707109;-0.000003;0.707105;,
  0.267625;-0.791473;-0.549498;,
  0.549492;-0.791475;-0.267630;,
  0.267627;-0.791475;0.549493;,
  -0.549495;-0.791475;0.267624;,
  0.000000;-1.000000;-0.000003;,
  0.678602;0.281075;0.678598;,
  -0.678602;0.281075;0.678598;,
  -0.678598;0.281072;-0.678604;,
  -0.707104;-0.000004;-0.707110;,
  0.678601;-0.281080;0.678597;,
  -0.678601;-0.281080;0.678597;,
  -0.678596;-0.281080;-0.678602;;
  46;
  4;1,2,6,5;,
  4;2,3,7,6;,
  4;10,4,8,11;,
  4;4,12,13,8;,
  3;0,2,1;,
  3;0,3,2;,
  3;14,4,10;,
  3;14,12,4;,
  3;9,15,16;,
  3;9,16,17;,
  3;18,18,19;,
  3;9,19,15;,
  4;20,21,24,23;,
  4;22,22,25,25;,
  4;37,20,23,38;,
  4;23,24,27,26;,
  4;25,25,28,28;,
  4;38,23,26,39;,
  4;26,27,30,29;,
  4;28,28,31,31;,
  4;39,26,29,40;,
  4;41,41,32,32;,
  4;42,42,33,33;,
  4;43,43,44,44;,
  4;32,32,35,34;,
  4;33,33,36,36;,
  4;44,44,34,45;,
  4;46,35,46,46;,
  4;36,36,47,47;,
  4;45,34,48,48;,
  3;49,51,50;,
  3;49,52,51;,
  3;49,53,52;,
  3;49,50,53;,
  4;50,51,54,54;,
  4;62,52,55,55;,
  4;63,53,56,56;,
  4;64,64,65,65;,
  4;54,54,58,57;,
  4;55,55,59,66;,
  4;56,56,60,67;,
  4;65,65,68,68;,
  3;57,58,61;,
  3;58,59,61;,
  3;59,60,61;,
  3;60,57,61;;
 }
 MeshTextureCoords {
  69;
  0.000000;0.000000;,
  0.250000;0.000000;,
  0.250000;1.000000;,
  0.000000;1.000000;,
  0.500000;0.000000;,
  0.500000;1.000000;,
  0.750000;0.000000;,
  0.750000;1.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.125000;0.000000;,
  0.375000;0.000000;,
  0.625000;0.000000;,
  0.875000;0.000000;,
  0.125000;1.000000;,
  0.375000;1.000000;,
  0.625000;1.000000;,
  0.875000;1.000000;,
  0.000000;0.000000;,
  0.000000;0.333330;,
  0.166670;0.333330;,
  0.166670;0.000000;,
  0.000000;0.666670;,
  0.166670;0.666670;,
  0.000000;1.000000;,
  0.166670;1.000000;,
  0.333330;0.333330;,
  0.333330;0.000000;,
  0.333330;0.666670;,
  0.333330;1.000000;,
  0.500000;0.333330;,
  0.500000;0.000000;,
  0.500000;0.666670;,
  0.500000;1.000000;,
  0.666670;0.333330;,
  0.666670;0.000000;,
  0.666670;0.666670;,
  0.666670;1.000000;,
  0.833330;0.333330;,
  0.833330;0.000000;,
  0.833330;0.666670;,
  0.833330;1.000000;,
  1.000000;0.333330;,
  1.000000;0.000000;,
  1.000000;0.666670;,
  1.000000;1.000000;,
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
