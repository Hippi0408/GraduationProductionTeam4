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
 82;
 5.00307;-6.22209;-5.94754;,
 5.00307;-6.22209;6.41246;,
 5.00307;-12.56209;6.41246;,
 5.00307;-12.56209;-5.94754;,
 -1.81693;-6.22209;6.41246;,
 -1.81693;-6.22209;-5.94754;,
 -1.81693;-12.56209;-5.94754;,
 -1.81693;-12.56209;6.41246;,
 0.20190;-6.22209;-5.94754;,
 -1.81693;-6.22209;-5.94754;,
 0.20190;-6.22209;6.41246;,
 0.20190;-12.56209;-5.94754;,
 0.20190;-12.56209;6.41246;,
 -1.81693;-12.56209;-5.94754;,
 0.20190;-6.22209;6.41246;,
 -1.81693;-6.22209;6.41246;,
 -1.81693;-12.56209;6.41246;,
 0.20190;-12.56209;6.41246;,
 2.84622;-6.22209;-5.94754;,
 2.84622;-12.56209;-5.94754;,
 0.20190;-12.56209;-5.94754;,
 0.20190;-6.22209;-5.94754;,
 2.84622;-6.22209;-5.94754;,
 2.84622;-6.22209;6.41246;,
 5.00307;-6.22209;-5.94754;,
 2.84622;-12.56209;-5.94754;,
 5.00307;-12.56209;-5.94754;,
 2.84622;-12.56209;6.41246;,
 2.84622;-6.22209;6.41246;,
 2.84622;-12.56209;6.41246;,
 5.00307;-12.56209;6.41246;,
 5.00307;-6.22209;6.41246;,
 -2.54103;-6.22209;-17.49340;,
 -7.86732;-6.22209;-15.48680;,
 -1.81693;-6.22209;-5.94754;,
 -2.54103;-12.56209;-17.49340;,
 -7.86732;-12.56209;-15.48680;,
 -1.81693;-12.56209;-5.94754;,
 -9.17941;-12.56209;-17.55550;,
 -3.13586;-12.56209;-19.99725;,
 5.42990;-6.22209;-17.93399;,
 5.00307;-6.22209;-5.94754;,
 11.23348;-6.22209;-15.72155;,
 5.42990;-12.56209;-17.93399;,
 5.00307;-12.56209;-5.94754;,
 11.23348;-12.56209;-15.72155;,
 5.89263;-12.56209;-20.08071;,
 12.34932;-12.56209;-17.47204;,
 -9.97181;-12.56209;-17.81001;,
 -2.74696;-12.56209;-20.75015;,
 -2.87659;1.07537;-20.49919;,
 -9.70768;1.07537;-17.72518;,
 5.50072;-12.56209;-20.82034;,
 13.14093;-12.56209;-17.72531;,
 5.63135;1.07537;-20.57380;,
 12.87706;1.07537;-17.64089;,
 -1.90863;1.29204;-17.64364;,
 -8.41622;1.29204;-15.13866;,
 -1.27623;-12.56209;-17.79388;,
 -8.96512;-12.56209;-14.79051;,
 11.78159;1.29204;-15.37216;,
 4.79450;1.29204;-18.07095;,
 4.15909;-12.56209;-18.20792;,
 12.32971;-12.56209;-15.02277;,
 3.88326;-6.22209;21.46167;,
 3.88326;-12.56209;21.46167;,
 -1.09331;-6.22209;21.46167;,
 4.08170;-12.56209;24.34132;,
 -1.34114;-12.56209;24.34132;,
 -1.09331;-12.56209;21.46167;,
 4.73016;-12.56209;24.94664;,
 -1.98875;-12.56209;24.93558;,
 4.51400;-1.95972;24.74486;,
 -1.77288;-1.95972;24.73750;,
 5.18018;-12.56209;21.37230;,
 4.53172;-1.74306;21.41699;,
 -1.74091;-1.74306;21.40594;,
 -2.38852;-12.56209;21.35020;,
 0.20190;-0.03059;-3.18125;,
 2.84622;-0.03059;-3.18125;,
 0.20190;-0.03059;3.64617;,
 2.84622;-0.03059;3.64617;;
 
 60;
 4;0,1,2,3;,
 4;4,5,6,7;,
 4;8,9,4,10;,
 4;11,12,7,13;,
 4;14,15,16,17;,
 4;18,19,20,21;,
 4;22,23,1,24;,
 4;25,26,2,27;,
 4;25,27,12,11;,
 4;28,29,30,31;,
 4;32,33,34,21;,
 4;32,21,20,35;,
 4;33,36,37,34;,
 4;35,20,37,36;,
 4;35,36,38,39;,
 4;40,18,41,42;,
 4;40,43,19,18;,
 4;42,41,44,45;,
 4;43,46,47,45;,
 4;43,45,44,19;,
 4;48,49,39,38;,
 4;50,49,48,51;,
 4;52,53,47,46;,
 4;54,55,53,52;,
 4;56,57,33,32;,
 4;56,50,51,57;,
 4;58,56,32,35;,
 4;49,58,35,39;,
 4;56,58,49,50;,
 4;59,48,38,36;,
 4;57,59,36,33;,
 4;57,51,48,59;,
 4;60,61,40,42;,
 4;61,60,55,54;,
 4;62,52,46,43;,
 4;61,62,43,40;,
 4;61,54,52,62;,
 4;63,60,42,45;,
 4;53,63,45,47;,
 4;60,63,53,55;,
 4;64,65,29,28;,
 4;64,28,14,66;,
 4;65,67,68,69;,
 4;65,69,17,29;,
 4;66,14,17,69;,
 4;70,71,68,67;,
 4;72,73,71,70;,
 4;74,70,67,65;,
 4;75,74,65,64;,
 4;75,72,70,74;,
 4;76,75,64,66;,
 4;75,76,73,72;,
 4;77,76,66,69;,
 4;71,77,69,68;,
 4;76,77,71,73;,
 4;78,79,22,8;,
 4;80,78,8,10;,
 4;81,80,10,23;,
 4;79,81,23,22;,
 4;79,78,80,81;;
 
 MeshMaterialList {
  5;
  60;
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
   0.800000;0.800000;0.800000;1.000000;;
   5.000000;
   0.850000;0.850000;0.850000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.800000;0.276000;0.000000;1.000000;;
   5.000000;
   0.740000;0.740000;0.740000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.571200;0.571200;0.571200;1.000000;;
   5.000000;
   0.780000;0.780000;0.780000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.615200;0.207200;0.000000;1.000000;;
   5.000000;
   0.830000;0.830000;0.830000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   1.000000;1.000000;1.000000;1.000000;;
   0.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
 }
 MeshNormals {
  44;
  -0.960329;0.000000;0.278869;,
  0.960012;0.000000;0.279958;,
  1.000000;0.000000;0.000000;,
  -1.000000;0.000000;0.000000;,
  0.000000;1.000000;0.000000;,
  0.000000;-1.000000;-0.000000;,
  0.000000;0.208548;-0.978012;,
  0.000000;0.000000;-1.000000;,
  0.972922;0.000000;-0.231135;,
  -0.844464;0.000000;0.535612;,
  -0.977548;0.000000;-0.210711;,
  0.843248;0.000000;0.537525;,
  -0.376556;0.013255;-0.926299;,
  0.375301;0.013082;-0.926811;,
  0.294133;-0.007004;0.955739;,
  0.448013;-0.007024;0.894000;,
  0.231139;0.000000;0.972921;,
  -0.285322;-0.007755;0.958400;,
  -0.450158;-0.007771;0.892915;,
  -0.537522;-0.000000;0.843250;,
  0.997634;0.000000;-0.068747;,
  -0.001408;0.018849;0.999821;,
  -0.033952;-0.005544;-0.999408;,
  0.043351;-0.005545;-0.999045;,
  0.085743;0.000000;-0.996317;,
  0.000000;0.407925;-0.913016;,
  0.000000;0.407925;0.913016;,
  0.000000;0.208548;0.978012;,
  0.000000;0.000000;1.000000;,
  -0.026987;0.997307;-0.068199;,
  0.922169;0.031748;-0.385481;,
  0.535607;0.000000;0.844467;,
  -0.924194;0.031583;0.380616;,
  0.030866;0.996475;-0.078002;,
  -0.210714;-0.000000;0.977548;,
  -0.920401;0.031760;-0.389685;,
  0.932332;0.031733;0.360209;,
  0.999408;0.000000;-0.034394;,
  -0.996317;0.000000;-0.085748;,
  -0.999079;0.000000;-0.042914;,
  -0.068742;0.000000;-0.997634;,
  0.996888;0.041271;0.067171;,
  -0.000095;0.997890;0.064930;,
  -0.997766;0.041117;0.052646;;
  60;
  4;1,2,2,1;,
  4;3,0,0,3;,
  4;4,4,4,4;,
  4;5,5,5,5;,
  4;27,28,28,28;,
  4;6,7,7,6;,
  4;4,4,4,4;,
  4;5,5,5,5;,
  4;5,5,5,5;,
  4;27,28,28,28;,
  4;4,4,4,4;,
  4;8,8,8,8;,
  4;9,9,0,0;,
  4;5,5,5,5;,
  4;5,5,5,5;,
  4;4,4,4,4;,
  4;10,10,10,10;,
  4;11,1,1,11;,
  4;5,5,5,5;,
  4;5,5,5,5;,
  4;5,5,5,5;,
  4;12,12,12,12;,
  4;5,5,5,5;,
  4;13,13,13,13;,
  4;14,15,15,14;,
  4;29,29,29,29;,
  4;16,14,14,16;,
  4;5,5,5,5;,
  4;30,30,30,30;,
  4;5,5,5,5;,
  4;15,31,31,15;,
  4;32,32,32,32;,
  4;18,17,17,18;,
  4;33,33,33,33;,
  4;5,5,5,5;,
  4;17,34,34,17;,
  4;35,35,35,35;,
  4;19,18,18,19;,
  4;5,5,5,5;,
  4;36,36,36,36;,
  4;20,20,20,37;,
  4;4,4,4,4;,
  4;5,5,5,5;,
  4;5,5,5,5;,
  4;38,39,38,38;,
  4;5,5,5,5;,
  4;21,21,21,21;,
  4;5,5,5,5;,
  4;22,40,40,22;,
  4;41,41,41,41;,
  4;23,22,22,23;,
  4;42,42,42,42;,
  4;24,23,23,24;,
  4;5,5,5,5;,
  4;43,43,43,43;,
  4;25,25,6,6;,
  4;3,3,3,39;,
  4;26,26,27,27;,
  4;2,2,37,2;,
  4;4,4,4,4;;
 }
 MeshTextureCoords {
  82;
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.296020;1.000000;,
  0.000000;1.000000;,
  0.296020;0.000000;,
  0.296020;0.000000;,
  0.296020;1.000000;,
  0.000000;0.000000;,
  0.703980;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.703980;1.000000;,
  0.683750;0.000000;,
  0.683750;1.000000;,
  0.296020;1.000000;,
  0.296020;0.000000;,
  0.683750;1.000000;,
  0.683750;0.000000;,
  1.000000;1.000000;,
  0.683750;0.000000;,
  1.000000;0.000000;,
  0.683750;1.000000;,
  0.316250;0.000000;,
  0.316250;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  0.296020;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.296020;1.000000;,
  0.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;1.000000;,
  0.296020;1.000000;,
  0.683750;0.000000;,
  1.000000;0.000000;,
  1.000000;0.000000;,
  0.683750;1.000000;,
  1.000000;1.000000;,
  1.000000;1.000000;,
  0.683750;1.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.296020;1.000000;,
  0.296020;0.000000;,
  0.000000;0.000000;,
  0.683750;1.000000;,
  1.000000;1.000000;,
  0.683750;0.000000;,
  1.000000;0.000000;,
  0.296020;0.000000;,
  0.000000;0.000000;,
  0.296020;1.000000;,
  0.000000;1.000000;,
  1.000000;0.000000;,
  0.683750;0.000000;,
  0.683750;1.000000;,
  1.000000;1.000000;,
  0.316250;0.000000;,
  0.316250;1.000000;,
  0.703980;0.000000;,
  0.316250;1.000000;,
  0.703980;1.000000;,
  0.703980;1.000000;,
  0.316250;1.000000;,
  0.703980;1.000000;,
  0.316250;0.000000;,
  0.703980;0.000000;,
  0.316250;1.000000;,
  0.316250;0.000000;,
  0.703980;0.000000;,
  0.703980;1.000000;,
  0.296020;1.000000;,
  0.683750;1.000000;,
  0.296020;0.000000;,
  0.683750;0.000000;;
 }
}