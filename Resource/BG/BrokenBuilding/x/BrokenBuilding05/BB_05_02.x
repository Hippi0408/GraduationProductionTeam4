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
 222;
 24.99966;62.80504;-9.92260;,
 24.99966;53.96107;9.92315;,
 24.99966;42.67622;9.92315;,
 24.99966;42.67622;-9.92260;,
 24.99966;67.66279;-24.99973;,
 24.99966;29.39442;-9.92260;,
 24.99966;-0.31973;-24.99973;,
 24.99966;29.39442;9.92315;,
 25.00079;47.98789;25.00027;,
 25.00079;-0.31951;25.00027;,
 6.38466;47.98794;24.99987;,
 -4.93569;27.86412;24.99987;,
 -24.99921;-0.31936;24.99987;,
 25.00079;-0.31951;25.00027;,
 -7.28444;43.05232;9.92275;,
 -3.62226;51.89630;-9.92300;,
 -7.04169;-0.31971;-25.00013;,
 -24.99921;-0.31936;24.99987;,
 6.38466;47.98794;24.99987;,
 25.00079;47.98789;25.00027;,
 24.99966;53.96107;9.92315;,
 6.38354;53.96112;9.92275;,
 -7.28444;43.05232;9.92275;,
 6.38354;53.96112;9.92275;,
 6.38354;62.80512;-9.92300;,
 -3.62226;51.89630;-9.92300;,
 24.99966;62.80504;-9.92260;,
 6.38354;62.80512;-9.92300;,
 6.38354;67.66286;-25.00013;,
 -3.62226;56.75407;-25.00013;,
 24.99966;67.66279;-24.99973;,
 6.38354;67.66286;-25.00013;,
 -7.04169;-0.31971;-25.00013;,
 24.99966;-0.31973;-24.99973;,
 25.00079;-0.31951;25.00027;,
 -24.99921;-0.31936;24.99987;,
 -4.93569;27.86412;24.99987;,
 25.00079;47.98789;25.00027;,
 -3.62226;56.75407;-25.00013;,
 -7.04169;-0.31971;-25.00013;,
 -3.62226;56.75407;-25.00013;,
 6.38354;67.66286;-25.00013;,
 24.99966;-0.31973;-24.99973;,
 24.99966;67.66279;-24.99973;,
 -4.93569;27.86412;24.99987;,
 6.38354;53.96112;9.92275;,
 -4.93569;27.86412;24.99987;,
 -6.38329;47.98557;24.99987;,
 6.38466;47.98557;24.99987;,
 6.38466;82.43264;24.99987;,
 -6.38329;77.65214;24.99987;,
 25.00079;47.98552;25.00027;,
 25.00079;82.43257;25.00027;,
 25.00079;47.98552;25.00027;,
 24.99966;53.96107;9.92315;,
 24.99966;82.43247;9.92315;,
 25.00079;82.43257;25.00027;,
 24.99966;62.80504;-9.92260;,
 24.99966;89.11005;-9.92260;,
 24.99966;67.66044;-24.99973;,
 24.99966;89.10992;-24.99973;,
 24.99966;67.66044;-24.99973;,
 6.38354;67.66049;-25.00013;,
 6.38354;89.10997;-25.00013;,
 24.99966;89.10992;-24.99973;,
 -6.38441;67.66049;-25.00013;,
 -6.38441;84.32944;-25.00013;,
 -25.00034;67.66057;-25.00013;,
 -25.00034;81.93922;-25.00013;,
 -25.00034;67.66057;-25.00013;,
 -25.00034;62.80519;-9.92300;,
 -25.00034;81.93937;-9.92300;,
 -25.00034;81.93922;-25.00013;,
 -25.00034;53.96119;9.92275;,
 -25.00034;75.26187;9.92275;,
 -25.00034;67.66057;-25.00013;,
 -6.38441;67.66049;-25.00013;,
 -6.38441;62.80512;-9.92300;,
 -25.00034;62.80519;-9.92300;,
 6.38354;67.66049;-25.00013;,
 6.38354;62.80512;-9.92300;,
 24.99966;67.66044;-24.99973;,
 24.99966;62.80504;-9.92260;,
 -6.38441;53.96112;9.92275;,
 -25.00034;53.96119;9.92275;,
 6.38354;53.96112;9.92275;,
 24.99966;53.96107;9.92315;,
 -6.38329;47.98557;24.99987;,
 -24.99921;47.98567;24.99987;,
 6.38466;47.98557;24.99987;,
 25.00079;47.98552;25.00027;,
 -24.99921;75.26197;24.99987;,
 -6.38329;77.65214;24.99987;,
 -6.38441;77.65205;9.92275;,
 -25.00034;75.26187;9.92275;,
 6.38466;82.43264;24.99987;,
 6.38354;82.43257;9.92275;,
 25.00079;82.43257;25.00027;,
 24.99966;82.43247;9.92315;,
 -6.38441;84.32959;-9.92303;,
 -25.00034;81.93937;-9.92300;,
 6.38354;89.11009;-9.92303;,
 24.99966;89.11005;-9.92260;,
 -6.38441;84.32944;-25.00013;,
 -25.00034;81.93922;-25.00013;,
 6.38354;89.10997;-25.00013;,
 24.99966;89.10992;-24.99973;,
 -24.99921;75.26197;24.99987;,
 -24.99921;75.26197;24.99987;,
 -24.99921;47.98567;24.99987;,
 -24.99921;47.98567;24.99987;,
 6.38354;89.10997;-25.00013;,
 -6.38441;81.96351;-25.00013;,
 -6.38441;90.49227;-25.00013;,
 6.38354;108.47107;-25.00013;,
 -25.00034;81.93922;-25.00013;,
 -25.00034;90.49234;-25.00013;,
 -25.00034;81.93922;-25.00013;,
 -25.00034;81.93937;-9.92300;,
 -25.00034;93.12817;-9.92300;,
 -25.00034;90.49234;-25.00013;,
 -6.38441;81.96351;-25.00013;,
 6.38354;89.10997;-25.00013;,
 24.99966;82.43247;9.92315;,
 -25.00034;81.93937;-9.92300;,
 -25.00034;93.12817;-9.92300;,
 -25.00034;75.26187;9.92275;,
 -6.45304;89.13404;-4.84203;,
 -25.00034;90.49234;-25.00013;,
 24.99966;82.43247;9.92315;,
 5.94999;95.52119;8.05367;,
 6.38354;108.47107;-25.00013;,
 -6.38441;90.49227;-25.00013;,
 24.99966;104.05305;-9.92260;,
 24.99966;108.47102;-24.99973;,
 24.99966;104.05305;-9.92260;,
 24.99966;82.43247;9.92315;,
 24.99966;89.11005;-9.92260;,
 24.99966;89.10992;-24.99973;,
 24.99966;108.47102;-24.99973;,
 24.99966;104.05305;-9.92260;,
 24.99966;89.10992;-24.99973;,
 24.99966;108.47102;-24.99973;,
 -25.00034;75.26187;9.92275;,
 -25.00034;90.49234;-25.00013;,
 24.99966;82.43247;9.92315;,
 -6.38441;81.96351;-25.00013;,
 -25.00034;75.26187;9.92275;,
 -6.38441;81.96351;-25.00013;,
 -25.00034;81.93937;-9.92300;,
 -25.00034;81.93922;-25.00013;,
 6.38354;89.10997;-25.00013;,
 24.99966;89.10992;-24.99973;,
 24.99966;89.11005;-9.92260;,
 24.99966;82.43247;9.92315;,
 24.99966;82.43247;9.92315;,
 -6.38441;81.96351;-25.00013;,
 -25.00034;75.26187;9.92275;,
 -24.99921;75.26197;24.99987;,
 -6.38329;77.65214;24.99987;,
 -6.38329;96.39729;24.99990;,
 -24.99921;96.39737;24.99990;,
 6.38466;82.43264;24.99987;,
 5.89979;106.63931;24.99987;,
 25.00079;82.43257;25.00027;,
 25.00079;107.32232;25.00030;,
 25.00079;82.43257;25.00027;,
 24.99966;82.43247;9.92315;,
 24.99966;112.47888;9.92317;,
 25.00079;107.32232;25.00030;,
 24.99966;104.05305;-9.92260;,
 24.99966;119.02510;-9.92260;,
 24.99966;108.47102;-24.99973;,
 24.99966;121.48657;-24.99970;,
 24.99966;108.47102;-24.99973;,
 6.38354;108.47107;-25.00013;,
 5.89866;120.98643;-25.00013;,
 24.99966;121.48657;-24.99970;,
 -6.38441;90.49227;-25.00013;,
 -6.38441;110.56160;-25.00010;,
 -25.00034;90.49234;-25.00013;,
 -25.00034;110.56170;-25.00010;,
 -25.00034;90.49234;-25.00013;,
 -25.00034;93.12817;-9.92300;,
 -25.00034;108.10022;-9.92300;,
 -25.00034;110.56170;-25.00010;,
 -25.00034;75.26187;9.92275;,
 -25.00034;101.55387;9.92277;,
 -24.99921;75.26197;24.99987;,
 -24.99921;96.39737;24.99990;,
 -25.00034;90.49234;-25.00013;,
 -6.38441;90.49227;-25.00013;,
 -6.38441;93.12809;-9.92300;,
 -25.00034;93.12817;-9.92300;,
 6.38354;108.47107;-25.00013;,
 6.38354;104.05310;-9.92300;,
 24.99966;108.47102;-24.99973;,
 24.99966;104.05305;-9.92260;,
 -6.38441;77.65205;9.92275;,
 -25.00034;75.26187;9.92275;,
 6.38354;82.43257;9.92275;,
 24.99966;82.43247;9.92315;,
 -6.38329;77.65214;24.99987;,
 -24.99921;75.26197;24.99987;,
 6.38466;82.43264;24.99987;,
 25.00079;82.43257;25.00027;,
 -24.99921;96.39737;24.99990;,
 -6.38329;96.39729;24.99990;,
 -6.38441;101.55382;9.92277;,
 -25.00034;101.55387;9.92277;,
 5.89979;106.63931;24.99987;,
 6.38354;112.47893;9.92277;,
 25.00079;107.32232;25.00030;,
 24.99966;112.47888;9.92317;,
 -6.38441;108.10012;-9.92300;,
 -25.00034;108.10022;-9.92300;,
 6.38354;119.02520;-9.92300;,
 24.99966;119.02510;-9.92260;,
 -6.38441;110.56160;-25.00010;,
 -25.00034;110.56170;-25.00010;,
 5.89866;120.98643;-25.00013;,
 24.99966;121.48657;-24.99970;;
 
 107;
 4;0,1,2,3;,
 4;4,3,5,6;,
 4;3,2,7,5;,
 4;2,8,9,7;,
 4;5,7,9,6;,
 4;10,11,12,13;,
 4;14,15,16,17;,
 4;18,19,20,21;,
 4;22,23,24,25;,
 4;21,20,26,27;,
 4;25,24,28,29;,
 4;27,26,30,31;,
 4;32,33,34,35;,
 3;8,2,1;,
 3;17,36,14;,
 3;13,37,10;,
 3;16,15,38;,
 3;39,40,41;,
 3;42,41,43;,
 3;4,0,3;,
 3;44,23,22;,
 3;45,46,18;,
 3;41,42,39;,
 4;47,48,49,50;,
 4;48,51,52,49;,
 4;53,54,55,56;,
 4;54,57,58,55;,
 4;57,59,60,58;,
 4;61,62,63,64;,
 4;62,65,66,63;,
 4;65,67,68,66;,
 4;69,70,71,72;,
 4;70,73,74,71;,
 4;75,76,77,78;,
 4;76,79,80,77;,
 4;79,81,82,80;,
 4;78,77,83,84;,
 4;77,80,85,83;,
 4;80,82,86,85;,
 4;84,83,87,88;,
 4;83,85,89,87;,
 4;85,86,90,89;,
 4;91,92,93,94;,
 4;92,95,96,93;,
 4;95,97,98,96;,
 4;94,93,99,100;,
 4;93,96,101,99;,
 4;96,98,102,101;,
 4;100,99,103,104;,
 4;99,101,105,103;,
 4;101,102,106,105;,
 3;107,47,50;,
 3;108,74,73;,
 3;47,107,109;,
 3;73,110,108;,
 4;111,112,113,114;,
 4;112,115,116,113;,
 4;117,118,119,120;,
 4;121,122,123,124;,
 4;125,126,127,128;,
 4;126,129,130,127;,
 4;127,130,131,132;,
 4;130,133,134,131;,
 3;135,136,137;,
 3;135,138,139;,
 3;140,130,129;,
 3;138,135,137;,
 3;141,111,114;,
 3;114,142,141;,
 3;143,119,118;,
 3;144,127,132;,
 3;145,126,146;,
 3;147,124,123;,
 3;148,149,150;,
 3;151,152,153;,
 3;154,122,153;,
 3;155,156,157;,
 4;158,159,160,161;,
 4;159,162,163,160;,
 4;162,164,165,163;,
 4;166,167,168,169;,
 4;167,170,171,168;,
 4;170,172,173,171;,
 4;174,175,176,177;,
 4;175,178,179,176;,
 4;178,180,181,179;,
 4;182,183,184,185;,
 4;183,186,187,184;,
 4;186,188,189,187;,
 4;190,191,192,193;,
 4;191,194,195,192;,
 4;194,196,197,195;,
 4;193,192,198,199;,
 4;192,195,200,198;,
 4;195,197,201,200;,
 4;199,198,202,203;,
 4;198,200,204,202;,
 4;200,201,205,204;,
 4;206,207,208,209;,
 4;207,210,211,208;,
 4;210,212,213,211;,
 4;209,208,214,215;,
 4;208,211,216,214;,
 4;211,213,217,216;,
 4;215,214,218,219;,
 4;214,216,220,218;,
 4;216,217,221,220;;
 
 MeshMaterialList {
  4;
  107;
  3,
  3,
  3,
  3,
  3,
  0,
  1,
  1,
  1,
  1,
  1,
  1,
  2,
  3,
  1,
  0,
  1,
  0,
  0,
  3,
  1,
  1,
  0,
  0,
  0,
  3,
  3,
  3,
  0,
  0,
  0,
  3,
  3,
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
  1,
  1,
  1,
  1,
  1,
  1,
  0,
  3,
  0,
  3,
  0,
  0,
  3,
  1,
  1,
  1,
  1,
  1,
  3,
  3,
  1,
  3,
  0,
  0,
  3,
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
  3,
  3,
  3,
  0,
  0,
  0,
  3,
  3,
  3,
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
  1,
  1,
  1,
  1,
  1,
  1;;
  Material {
   0.800000;0.800000;0.800000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
   TextureFilename {
    "texture\\bill005.jpg";
   }
  }
  Material {
   0.800000;0.800000;0.800000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
   TextureFilename {
    "texture\\Concrete.png";
   }
  }
  Material {
   0.800000;0.800000;0.800000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
   TextureFilename {
    "texture\\Concrete.png";
   }
  }
  Material {
   0.800000;0.800000;0.800000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
   TextureFilename {
    "texture\\bill005.jpg";
   }
  }
 }
 MeshNormals {
  137;
  -0.915166;0.383655;0.123611;,
  -0.391217;0.875955;0.282227;,
  1.000000;0.000000;0.000000;,
  -0.986605;0.122278;-0.107975;,
  1.000000;0.000007;-0.000006;,
  1.000000;0.000000;-0.000037;,
  1.000000;0.000000;-0.000075;,
  1.000000;0.000004;-0.000004;,
  1.000000;0.000004;-0.000029;,
  1.000000;0.000007;-0.000043;,
  -0.000015;0.000003;1.000000;,
  -0.567979;0.440079;0.695507;,
  -0.763332;0.541362;0.352493;,
  -0.898325;0.433805;0.069462;,
  -0.436949;0.797429;0.416153;,
  -0.371802;0.871572;0.319572;,
  -0.373534;0.265914;0.888686;,
  -0.000004;-0.929648;-0.368448;,
  -0.127349;0.991858;0.000003;,
  0.000000;0.000000;1.000000;,
  -0.000011;0.000000;1.000000;,
  -0.000021;0.000000;1.000000;,
  0.000011;0.000000;-1.000000;,
  0.000000;0.000000;-1.000000;,
  -1.000000;0.000000;0.000000;,
  -1.000000;0.000000;0.000050;,
  -1.000000;0.000000;0.000037;,
  -0.000002;-0.933987;-0.357308;,
  0.000002;-0.933987;-0.357308;,
  -0.000002;-0.921729;-0.387833;,
  0.000003;-0.921729;-0.387833;,
  -0.237749;0.958518;0.157221;,
  -0.176167;0.971386;0.159294;,
  -0.237750;0.958520;0.157210;,
  -0.176168;0.971387;0.159286;,
  -0.132585;0.909778;0.393351;,
  0.192520;-0.952343;-0.236600;,
  -0.036822;0.945816;0.322607;,
  0.172929;0.829533;0.531009;,
  0.000014;0.000000;-1.000000;,
  0.000011;0.000000;-1.000000;,
  -0.272012;0.900602;0.339008;,
  -0.220847;0.814694;0.536191;,
  0.000000;-0.000001;1.000000;,
  0.000001;-0.000001;1.000000;,
  -0.000010;-0.000001;1.000000;,
  -0.000022;-0.000001;1.000000;,
  1.000000;0.000000;-0.000037;,
  0.000010;0.000001;-1.000000;,
  -0.000001;0.000001;-1.000000;,
  0.000000;0.000001;-1.000000;,
  -1.000000;-0.000000;0.000037;,
  0.337563;-0.886530;-0.316411;,
  0.315015;-0.830136;-0.460043;,
  0.247993;-0.907327;-0.339497;,
  0.205305;-0.904810;-0.373053;,
  -0.332385;0.893519;0.301900;,
  -0.336341;0.890525;0.306332;,
  -0.339568;0.913657;0.223439;,
  -0.342746;0.913524;0.219088;,
  -0.955232;0.182288;-0.233031;,
  -0.491072;0.809865;0.320885;,
  -0.000005;0.929698;0.368323;,
  -0.000006;0.921756;0.387771;,
  -0.000004;0.933961;0.357374;,
  -0.000003;0.951816;0.306669;,
  -0.000002;-1.000000;0.000006;,
  0.000006;-0.000001;-1.000000;,
  0.000011;-0.000001;-1.000000;,
  0.000017;-0.000001;-1.000000;,
  0.000021;0.000000;-1.000000;,
  0.000021;0.000000;-1.000000;,
  -0.000004;-0.951860;-0.306533;,
  -0.000002;-0.951860;-0.306533;,
  -0.000004;-0.933987;-0.357308;,
  0.000002;-0.951860;-0.306534;,
  0.000003;-0.951860;-0.306534;,
  0.000005;-0.933987;-0.357308;,
  -0.000004;-0.921730;-0.387833;,
  0.000006;-0.921729;-0.387833;,
  -0.000002;-0.929648;-0.368449;,
  0.000003;-0.929648;-0.368449;,
  0.000005;-0.929648;-0.368449;,
  -0.240593;0.970626;0.000012;,
  -0.125701;0.979022;0.160360;,
  -0.178170;0.984000;0.000008;,
  0.000005;1.000000;-0.000006;,
  0.000001;0.986861;0.161572;,
  -0.125703;0.979023;0.160354;,
  -0.000000;0.986861;0.161571;,
  -0.240594;0.970626;-0.000009;,
  -0.127351;0.991858;-0.000010;,
  -0.178171;0.983999;-0.000008;,
  0.000002;1.000000;-0.000008;,
  -1.000000;0.000000;0.000075;,
  0.128628;-0.985961;-0.106470;,
  0.166032;-0.970766;-0.173343;,
  0.127166;-0.976238;-0.175464;,
  0.127681;0.951024;0.281515;,
  0.064363;0.982321;0.175792;,
  -0.049644;0.827215;0.559687;,
  -0.422229;0.868545;0.259525;,
  -0.406204;0.905596;0.122038;,
  1.000000;0.000000;-0.000000;,
  0.000021;0.000000;-1.000000;,
  0.138612;-0.966519;-0.215933;,
  0.001305;-0.999999;0.000010;,
  -0.000003;-1.000000;0.000009;,
  0.127697;-0.979202;-0.157661;,
  -0.141042;0.983471;0.113543;,
  1.000000;0.000000;-0.000075;,
  0.000022;0.000001;-1.000000;,
  -1.000000;-0.000000;0.000075;,
  -0.000004;-0.985060;0.172211;,
  0.404821;-0.910481;0.084522;,
  0.026239;-0.965547;-0.258902;,
  0.405915;-0.898956;-0.164656;,
  0.000004;-0.959649;-0.281201;,
  0.000009;-0.849051;-0.528310;,
  0.093094;-0.935273;-0.341464;,
  0.000005;-0.915485;-0.402351;,
  0.240593;-0.970626;-0.000012;,
  0.127349;-0.991858;-0.000003;,
  0.178170;-0.984000;-0.000008;,
  -0.000005;-1.000000;0.000006;,
  0.000003;0.946192;0.323606;,
  -0.330151;0.892067;0.308573;,
  0.000004;0.947944;0.318437;,
  -0.338017;0.886014;0.317371;,
  -0.016681;0.939575;0.341938;,
  -0.008343;0.944764;0.327645;,
  0.000005;0.971284;0.237923;,
  -0.006516;0.973115;0.230228;,
  -0.342662;0.927371;0.150216;,
  0.000005;0.986934;0.161126;,
  -0.348761;0.926459;0.141559;,
  -0.012980;0.989276;0.145479;;
  107;
  4;2,5,5,2;,
  4;2,2,7,4;,
  4;2,5,8,7;,
  4;5,6,9,8;,
  4;7,8,9,4;,
  4;10,11,16,10;,
  4;12,13,3,60;,
  4;61,62,63,14;,
  4;12,14,15,13;,
  4;14,63,64,15;,
  4;13,15,1,0;,
  4;15,64,65,1;,
  4;66,66,66,66;,
  3;6,5,5;,
  3;16,11,12;,
  3;10,21,10;,
  3;3,13,0;,
  3;67,23,68;,
  3;69,68,70;,
  3;2,2,2;,
  3;11,14,12;,
  3;14,11,61;,
  3;68,69,67;,
  4;19,20,20,19;,
  4;20,21,21,20;,
  4;6,5,5,6;,
  4;5,2,2,5;,
  4;2,2,2,2;,
  4;71,22,22,71;,
  4;22,23,23,22;,
  4;23,23,23,23;,
  4;24,24,24,24;,
  4;24,25,26,24;,
  4;72,73,27,74;,
  4;73,75,28,27;,
  4;75,76,77,28;,
  4;74,27,29,78;,
  4;27,28,30,29;,
  4;28,77,79,30;,
  4;78,29,80,17;,
  4;29,30,81,80;,
  4;30,79,82,81;,
  4;18,83,31,84;,
  4;83,85,32,31;,
  4;85,86,87,32;,
  4;84,31,33,88;,
  4;31,32,34,33;,
  4;32,87,89,34;,
  4;88,33,90,91;,
  4;33,34,92,90;,
  4;34,89,93,92;,
  3;19,19,19;,
  3;94,26,25;,
  3;19,19,19;,
  3;25,94,94;,
  4;40,23,23,39;,
  4;23,23,23,23;,
  4;24,24,24,24;,
  4;95,96,36,97;,
  4;98,35,41,99;,
  4;35,100,42,41;,
  4;41,42,101,102;,
  4;42,38,37,101;,
  3;2,103,2;,
  3;2,2,2;,
  3;38,42,100;,
  3;2,2,2;,
  3;104,40,39;,
  3;39,104,104;,
  3;24,24,24;,
  3;99,41,102;,
  3;36,105,95;,
  3;105,97,36;,
  3;95,97,106;,
  3;96,107,108;,
  3;36,96,108;,
  3;100,109,35;,
  4;43,44,44,43;,
  4;44,45,45,44;,
  4;45,46,46,45;,
  4;110,47,47,110;,
  4;47,2,2,47;,
  4;2,2,2,2;,
  4;111,48,48,111;,
  4;48,49,49,48;,
  4;49,50,50,49;,
  4;24,24,24,24;,
  4;24,51,51,24;,
  4;51,112,112,51;,
  4;113,114,52,115;,
  4;114,116,53,52;,
  4;116,117,118,53;,
  4;115,52,54,119;,
  4;52,53,55,54;,
  4;53,118,120,55;,
  4;119,54,121,122;,
  4;54,55,123,121;,
  4;55,120,124,123;,
  4;125,126,56,127;,
  4;126,128,57,56;,
  4;128,129,130,57;,
  4;127,56,58,131;,
  4;56,57,59,58;,
  4;57,130,132,59;,
  4;131,58,133,134;,
  4;58,59,135,133;,
  4;59,132,136,135;;
 }
 MeshTextureCoords {
  222;
  0.347345;0.524204;,
  0.652664;0.591204;,
  0.652664;0.676695;,
  0.347345;0.676695;,
  0.115389;0.487403;,
  0.347345;0.777315;,
  0.115389;1.002422;,
  0.652664;0.777315;,
  0.884620;0.636455;,
  0.884620;1.002420;,
  0.598226;0.636455;,
  0.424066;0.788908;,
  0.115397;1.002419;,
  0.884627;1.002420;,
  0.667120;0.801280;,
  0.332880;0.727280;,
  0.140290;0.980000;,
  0.859710;0.980000;,
  0.666670;0.000000;,
  1.000000;0.000000;,
  1.000000;0.333330;,
  0.666670;0.333330;,
  0.000000;0.333330;,
  0.333330;0.333330;,
  0.333330;0.666670;,
  0.000000;0.666670;,
  1.000000;0.666670;,
  0.666670;0.666670;,
  0.333330;1.000000;,
  0.000000;1.000000;,
  1.000000;1.000000;,
  0.666670;1.000000;,
  0.147916;-0.750006;,
  1.749983;-0.749986;,
  1.750039;1.750014;,
  -0.749961;1.749994;,
  0.859710;0.851260;,
  0.884627;0.636455;,
  0.140290;0.686630;,
  0.391666;1.002422;,
  0.444273;0.570045;,
  0.598208;0.487403;,
  0.884610;1.002422;,
  0.884610;0.487403;,
  0.166670;0.000000;,
  0.500000;0.333330;,
  0.333330;0.000000;,
  0.401796;0.636473;,
  0.598226;0.636473;,
  0.598226;0.375510;,
  0.401796;0.411726;,
  0.884627;0.636473;,
  0.884627;0.375511;,
  0.884620;0.636473;,
  0.652664;0.591204;,
  0.652664;0.375512;,
  0.884620;0.375511;,
  0.347345;0.524204;,
  0.347345;0.324924;,
  0.115389;0.487421;,
  0.115389;0.324925;,
  0.884610;0.487421;,
  0.598208;0.487420;,
  0.598208;0.324924;,
  0.884610;0.324925;,
  0.401778;0.487420;,
  0.401778;0.361141;,
  0.115379;0.487420;,
  0.115379;0.379248;,
  0.115383;0.487420;,
  0.347338;0.524203;,
  0.347338;0.379247;,
  0.115383;0.379248;,
  0.652658;0.591203;,
  0.652658;0.429834;,
  0.000000;0.000000;,
  0.333330;0.000000;,
  0.333330;0.333330;,
  0.000000;0.333330;,
  0.666670;0.000000;,
  0.666670;0.333330;,
  1.000000;0.000000;,
  1.000000;0.333330;,
  0.333330;0.666670;,
  0.000000;0.666670;,
  0.666670;0.666670;,
  1.000000;0.666670;,
  0.333330;1.000000;,
  0.000000;1.000000;,
  0.666670;1.000000;,
  1.000000;1.000000;,
  0.000000;0.000000;,
  0.333330;0.000000;,
  0.333330;0.333330;,
  0.000000;0.333330;,
  0.666670;0.000000;,
  0.666670;0.333330;,
  1.000000;0.000000;,
  1.000000;0.333330;,
  0.333330;0.666670;,
  0.000000;0.666670;,
  0.666670;0.666670;,
  1.000000;0.666670;,
  0.333330;1.000000;,
  0.000000;1.000000;,
  0.666670;1.000000;,
  1.000000;1.000000;,
  0.115397;0.429834;,
  0.884613;0.429834;,
  0.115397;0.636472;,
  0.884613;0.636472;,
  0.598208;0.324924;,
  0.401778;0.379064;,
  0.401778;0.314453;,
  0.598208;0.178249;,
  0.115379;0.379248;,
  0.115379;0.314452;,
  0.115383;0.379248;,
  0.347338;0.379247;,
  0.347338;0.294484;,
  0.115383;0.314452;,
  0.333330;0.333330;,
  0.666670;0.333330;,
  0.666670;0.666670;,
  0.333330;0.666670;,
  0.000000;0.333330;,
  0.333330;0.333330;,
  0.333330;0.666670;,
  0.000000;0.666670;,
  0.666670;0.333330;,
  0.666670;0.666670;,
  0.666670;1.000000;,
  0.333330;1.000000;,
  1.000000;0.666670;,
  1.000000;1.000000;,
  0.347345;0.211719;,
  0.652664;0.375512;,
  0.347345;0.324924;,
  0.115389;0.324925;,
  0.115389;0.178250;,
  1.000000;0.500000;,
  0.884610;0.324925;,
  0.884610;0.178250;,
  0.652658;0.429834;,
  0.000000;0.833330;,
  0.666670;0.166670;,
  0.333330;0.000000;,
  0.500000;1.000000;,
  0.333330;0.166670;,
  0.000000;0.333330;,
  0.000000;0.000000;,
  0.666670;0.166670;,
  1.000000;0.000000;,
  1.000000;0.333330;,
  0.833330;0.666670;,
  0.547080;0.356870;,
  0.452920;0.352370;,
  0.452920;0.361360;,
  0.115397;0.429834;,
  0.401796;0.411726;,
  0.401796;0.269718;,
  0.115397;0.269717;,
  0.598226;0.375510;,
  0.590766;0.192126;,
  0.884627;0.375511;,
  0.884627;0.186952;,
  0.884620;0.375511;,
  0.652664;0.375512;,
  0.652664;0.147887;,
  0.884620;0.186952;,
  0.347345;0.211719;,
  0.347345;0.098295;,
  0.115389;0.178250;,
  0.115389;0.079647;,
  0.884610;0.178250;,
  0.598208;0.178249;,
  0.590749;0.083436;,
  0.884610;0.079647;,
  0.401778;0.314453;,
  0.401778;0.162412;,
  0.115379;0.314452;,
  0.115379;0.162411;,
  0.115383;0.314452;,
  0.347338;0.294484;,
  0.347338;0.181059;,
  0.115383;0.162411;,
  0.652658;0.429834;,
  0.652658;0.230653;,
  0.884613;0.429834;,
  0.884614;0.269717;,
  0.000000;0.000000;,
  0.333330;0.000000;,
  0.333330;0.333330;,
  0.000000;0.333330;,
  0.666670;0.000000;,
  0.666670;0.333330;,
  1.000000;0.000000;,
  1.000000;0.333330;,
  0.333330;0.666670;,
  0.000000;0.666670;,
  0.666670;0.666670;,
  1.000000;0.666670;,
  0.333330;1.000000;,
  0.000000;1.000000;,
  0.666670;1.000000;,
  1.000000;1.000000;,
  0.000000;0.000000;,
  0.333330;0.000000;,
  0.333330;0.333330;,
  0.000000;0.333330;,
  0.666670;0.000000;,
  0.666670;0.333330;,
  1.000000;0.000000;,
  1.000000;0.333330;,
  0.333330;0.666670;,
  0.000000;0.666670;,
  0.666670;0.666670;,
  1.000000;0.666670;,
  0.333330;1.000000;,
  0.000000;1.000000;,
  0.666670;1.000000;,
  1.000000;1.000000;;
 }
}
