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
 139;
 -25.23036;29.57222;-25.18082;,
 25.23036;29.57222;-25.18082;,
 25.23072;10.00000;-25.18000;,
 -25.23000;10.00000;-25.18000;,
 25.23036;29.57222;-25.18082;,
 25.23036;29.57222;25.27998;,
 25.23072;10.00000;25.28080;,
 25.23072;10.00000;-25.18000;,
 25.23036;29.57222;25.27998;,
 -25.22964;29.51490;25.28162;,
 -25.23000;10.00000;25.28080;,
 25.23072;10.00000;25.28080;,
 -25.22964;29.51490;25.28162;,
 -25.23036;29.57222;-25.18082;,
 -25.23000;10.00000;-25.18000;,
 -25.23000;10.00000;25.28080;,
 -25.22964;29.51490;25.28162;,
 25.23036;29.57222;25.27998;,
 25.23036;29.57222;-25.18082;,
 -25.23036;29.57222;-25.18082;,
 -25.23000;10.00000;-25.18000;,
 25.23072;10.00000;-25.18000;,
 25.23072;10.00000;25.28080;,
 -25.23000;10.00000;25.28080;,
 -18.04428;19.06568;-25.36990;,
 -5.42908;19.06568;-25.36990;,
 -5.42908;2.24544;-25.36990;,
 -18.04428;2.24544;-25.36990;,
 -5.42908;19.06568;-25.36990;,
 -5.42908;19.06568;-16.95976;,
 -5.42908;2.24544;-16.95976;,
 -5.42908;2.24544;-25.36990;,
 -5.42908;19.06568;-16.95976;,
 -18.04428;19.06568;-16.95976;,
 -18.04428;2.24544;-16.95976;,
 -5.42908;2.24544;-16.95976;,
 -18.04428;19.06568;-16.95976;,
 -18.04428;19.06568;-25.36990;,
 -18.04428;2.24544;-25.36990;,
 -18.04428;2.24544;-16.95976;,
 -5.42908;19.06568;-25.36990;,
 -18.04428;19.06568;-25.36990;,
 -18.04428;2.24544;-25.36990;,
 -5.42908;2.24544;-25.36990;,
 -25.23000;10.00000;-25.18000;,
 25.23072;10.00000;-25.18000;,
 25.23036;1.98468;-25.18082;,
 -25.23036;1.98468;-25.18082;,
 25.23072;10.00000;-25.18000;,
 25.23072;10.00000;25.28080;,
 25.23036;1.98468;25.27998;,
 25.23036;1.98468;-25.18082;,
 25.23072;10.00000;25.28080;,
 -25.23000;10.00000;25.28080;,
 -25.23036;1.98468;25.27998;,
 25.23036;1.98468;25.27998;,
 -25.23000;10.00000;25.28080;,
 -25.23000;10.00000;-25.18000;,
 -25.23036;1.98468;-25.18082;,
 -25.23036;1.98468;25.27998;,
 -25.23000;10.00000;25.28080;,
 25.23072;10.00000;25.28080;,
 25.23072;10.00000;-25.18000;,
 -25.23000;10.00000;-25.18000;,
 -25.23036;1.98468;-25.18082;,
 25.23036;1.98468;-25.18082;,
 25.23036;1.98468;25.27998;,
 -25.23036;1.98468;25.27998;,
 22.94968;32.00216;-22.90272;,
 20.01096;32.00216;-19.96366;,
 22.78162;29.26712;-22.72780;,
 25.23036;29.57222;-25.18082;,
 20.01096;32.00216;-19.96366;,
 -20.01088;32.00216;-19.96366;,
 -22.78166;29.26712;-22.72780;,
 22.78162;29.26712;-22.72780;,
 -20.01088;32.00216;-19.96366;,
 -22.65812;31.98990;-22.99560;,
 -25.23036;29.57222;-25.18082;,
 -22.78166;29.26712;-22.72780;,
 -22.65812;31.98990;-22.99560;,
 22.94968;32.00216;-22.90272;,
 25.23036;29.57222;-25.18082;,
 -25.23036;29.57222;-25.18082;,
 -22.65812;31.98990;-22.99560;,
 -20.01088;32.00216;-19.96366;,
 20.01096;32.00216;-19.96366;,
 22.94968;32.00216;-22.90272;,
 25.23036;29.57222;-25.18082;,
 22.78162;29.26712;-22.72780;,
 -22.78166;29.26712;-22.72780;,
 -25.23036;29.57222;-25.18082;,
 22.94968;32.00216;22.99508;,
 25.23036;29.57222;25.27998;,
 22.78162;29.26712;22.83342;,
 20.01096;32.00216;20.05638;,
 20.01096;32.00216;20.05638;,
 22.78162;29.26712;22.83342;,
 -22.78250;29.26658;22.83304;,
 -20.01088;32.00216;20.05638;,
 -20.01088;32.00216;20.05638;,
 -22.78250;29.26658;22.83304;,
 -25.22964;29.51490;25.28162;,
 -22.94884;32.00216;22.99508;,
 -22.94884;32.00216;22.99508;,
 -25.22964;29.51490;25.28162;,
 25.23036;29.57222;25.27998;,
 22.94968;32.00216;22.99508;,
 -22.94884;32.00216;22.99508;,
 22.94968;32.00216;22.99508;,
 20.01096;32.00216;20.05638;,
 -20.01088;32.00216;20.05638;,
 25.23036;29.57222;25.27998;,
 -25.22964;29.51490;25.28162;,
 -22.78250;29.26658;22.83304;,
 22.78162;29.26712;22.83342;,
 22.94894;32.00216;-22.90346;,
 22.78162;29.26712;22.83342;,
 20.01096;32.00216;20.05638;,
 22.94894;32.00216;22.99506;,
 22.94894;32.00216;22.99506;,
 25.23036;29.57222;25.27998;,
 25.23036;29.57222;-25.18082;,
 22.94894;32.00216;-22.90346;,
 22.94894;32.00216;22.99506;,
 22.94894;32.00216;-22.90346;,
 20.01096;32.00216;20.05638;,
 25.23036;29.57222;25.27998;,
 22.78162;29.26712;22.83342;,
 -20.01088;32.00216;-19.96366;,
 -22.78166;29.26712;-22.72780;,
 -22.94884;32.00216;22.99508;,
 -22.65812;31.98990;-22.99560;,
 -25.23036;29.57222;-25.18082;,
 -25.22964;29.51490;25.28162;,
 -20.01088;32.00216;-19.96366;,
 -22.65812;31.98990;-22.99560;,
 -25.23036;29.57222;-25.18082;,
 -22.78166;29.26712;-22.72780;;
 
 42;
 4;0,1,2,3;,
 4;4,5,6,7;,
 4;8,9,10,11;,
 4;12,13,14,15;,
 4;16,17,18,19;,
 4;20,21,22,23;,
 4;24,25,26,27;,
 4;28,29,30,31;,
 4;32,33,34,35;,
 4;36,37,38,39;,
 4;36,29,40,41;,
 4;42,43,30,39;,
 4;44,45,46,47;,
 4;48,49,50,51;,
 4;52,53,54,55;,
 4;56,57,58,59;,
 4;60,61,62,63;,
 4;64,65,66,67;,
 4;68,69,70,71;,
 4;72,73,74,75;,
 4;76,77,78,79;,
 4;80,81,82,83;,
 4;84,85,86,87;,
 4;88,89,90,91;,
 4;92,93,94,95;,
 4;96,97,98,99;,
 4;100,101,102,103;,
 4;104,105,106,107;,
 4;108,109,110,111;,
 4;112,113,114,115;,
 4;116,71,70,69;,
 4;72,75,117,118;,
 4;95,94,93,119;,
 4;120,121,122,123;,
 4;124,125,86,126;,
 4;88,127,128,89;,
 4;77,76,79,78;,
 4;129,99,98,130;,
 4;100,103,102,101;,
 4;131,132,133,134;,
 4;108,111,135,136;,
 4;137,138,114,113;;
 
 MeshMaterialList {
  5;
  42;
  1,
  1,
  1,
  1,
  1,
  4,
  0,
  0,
  0,
  0,
  0,
  0,
  2,
  3,
  2,
  3,
  1,
  4,
  1,
  1,
  1,
  2,
  1,
  4,
  1,
  1,
  1,
  2,
  1,
  4,
  1,
  1,
  1,
  3,
  1,
  4,
  1,
  1,
  1,
  3,
  1,
  4;;
  Material {
   0.000000;0.000000;0.000000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.752800;0.759200;0.721600;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
   TextureFilename {
    "texture\\sandstone.png";
   }
  }
  Material {
   0.800000;0.800000;0.800000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
   TextureFilename {
    "texture\\sandstonebricks.png";
   }
  }
  Material {
   0.800000;0.800000;0.800000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
   TextureFilename {
    "texture\\sandstonebricks.png";
   }
  }
  Material {
   1.000000;1.000000;1.000000;1.000000;;
   0.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
 }
 MeshNormals {
  56;
  0.000000;-0.000042;-1.000000;,
  1.000000;0.000018;0.000000;,
  0.000016;-0.000000;1.000000;,
  -1.000000;0.000000;0.000007;,
  -0.000568;1.000000;0.000568;,
  0.000000;-1.000000;-0.000000;,
  0.000000;0.000000;-1.000000;,
  1.000000;0.000000;0.000000;,
  0.000000;0.000000;1.000000;,
  -1.000000;0.000000;0.000000;,
  0.000000;1.000000;0.000000;,
  0.000000;-1.000000;-0.000000;,
  0.000000;0.000102;-1.000000;,
  1.000000;-0.000045;-0.000000;,
  0.000000;-0.000102;1.000000;,
  -1.000000;0.000045;0.000000;,
  0.000000;1.000000;0.000000;,
  0.000000;-1.000000;-0.000000;,
  0.707382;0.001739;0.706830;,
  -0.806110;0.451712;0.382286;,
  0.706998;-0.001642;-0.707214;,
  0.825169;0.392369;-0.406377;,
  -0.707284;-0.001133;-0.706929;,
  -0.707458;-0.002112;-0.706752;,
  0.824684;0.393974;0.405809;,
  -0.707036;0.001460;0.707176;,
  0.000000;-0.710839;0.703355;,
  0.168114;-0.971829;0.165186;,
  0.000007;-0.712412;-0.701762;,
  0.168063;-0.971382;-0.167846;,
  -0.165190;-0.972279;0.165489;,
  -0.724303;0.099961;0.682197;,
  -0.000587;0.964077;-0.265624;,
  0.000282;0.915427;-0.402485;,
  -0.405666;0.387689;-0.827727;,
  0.000650;0.677599;-0.735431;,
  -0.001141;0.999999;-0.001152;,
  -0.000067;0.999999;-0.001078;,
  0.062056;-0.996148;-0.061950;,
  -0.056625;-0.996455;-0.062216;,
  -0.164829;-0.971936;-0.167845;,
  -0.201630;0.957415;0.206644;,
  0.405658;0.391284;0.826038;,
  -0.405823;0.391351;0.825925;,
  -0.000206;0.916713;0.399546;,
  0.000000;1.000000;0.000000;,
  -0.001074;0.999999;-0.000073;,
  0.062323;-0.996448;0.056639;,
  -0.056323;-0.996822;0.056338;,
  -0.702518;-0.711666;0.000000;,
  0.397193;0.917735;0.000000;,
  0.724303;-0.099961;-0.682197;,
  0.802643;-0.456602;-0.383770;,
  0.702484;-0.711699;0.000002;,
  0.707284;0.001133;0.706929;,
  -0.710277;0.703920;-0.001868;;
  42;
  4;0,0,0,0;,
  4;1,1,1,1;,
  4;2,2,2,2;,
  4;3,3,3,3;,
  4;4,4,4,4;,
  4;5,5,5,5;,
  4;6,6,6,6;,
  4;7,7,7,7;,
  4;8,8,8,8;,
  4;9,9,9,9;,
  4;10,10,10,10;,
  4;11,11,11,11;,
  4;12,12,12,12;,
  4;13,13,13,13;,
  4;14,14,14,14;,
  4;15,15,15,15;,
  4;16,16,16,16;,
  4;17,17,17,17;,
  4;18,18,18,24;,
  4;26,26,27,30;,
  4;31,19,19,31;,
  4;32,33,34,35;,
  4;32,36,37,33;,
  4;38,30,27,39;,
  4;20,21,20,20;,
  4;28,40,29,28;,
  4;22,22,22,22;,
  4;41,42,43,44;,
  4;41,44,45,46;,
  4;47,48,29,40;,
  4;23,34,23,23;,
  4;49,30,40,49;,
  4;25,25,43,25;,
  4;50,21,24,50;,
  4;50,50,37,45;,
  4;38,47,40,30;,
  4;51,52,51,51;,
  4;52,53,29,27;,
  4;54,54,42,54;,
  4;41,19,19,55;,
  4;41,46,36,32;,
  4;39,27,29,48;;
 }
 MeshTextureCoords {
  139;
  0.392580;0.551020;,
  0.392580;0.795920;,
  0.255550;0.795920;,
  0.255550;0.551020;,
  0.367580;0.551020;,
  0.367580;0.795920;,
  0.230550;0.795920;,
  0.230550;0.551020;,
  0.392580;0.795920;,
  0.392580;0.551020;,
  0.255550;0.551020;,
  0.255550;0.795920;,
  0.367580;0.795920;,
  0.367580;0.551020;,
  0.230550;0.551020;,
  0.230550;0.795920;,
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
  -0.435359;0.228306;,
  1.435386;0.228306;,
  1.435372;0.493254;,
  -0.435372;0.493254;,
  -0.433976;0.233790;,
  1.437715;0.233790;,
  1.437685;0.498847;,
  -0.434007;0.498847;,
  1.435386;0.228306;,
  -0.435359;0.228306;,
  -0.435372;0.493254;,
  1.435372;0.493254;,
  1.437715;0.233790;,
  -0.433976;0.233790;,
  -0.434007;0.498847;,
  1.437685;0.498847;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.392580;0.551020;,
  0.392580;0.795920;,
  0.255550;0.795920;,
  0.255550;0.551020;,
  0.367580;0.551020;,
  0.367580;0.795920;,
  0.230550;0.795920;,
  0.230550;0.551020;,
  0.392580;0.795920;,
  0.392580;0.551020;,
  0.255550;0.551020;,
  0.255550;0.795920;,
  -0.340011;-0.498575;,
  1.350820;-0.498981;,
  1.435372;-0.418658;,
  -0.435372;-0.418658;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.392580;0.551020;,
  0.255550;0.551020;,
  0.255550;0.795920;,
  0.392580;0.795920;,
  0.367580;0.551020;,
  0.230550;0.551020;,
  0.230550;0.795920;,
  0.367580;0.795920;,
  0.392580;0.795920;,
  0.255550;0.795920;,
  0.255550;0.551020;,
  0.392580;0.551020;,
  -0.350789;-0.498981;,
  -0.435346;-0.416764;,
  1.435372;-0.418658;,
  1.350820;-0.498981;,
  0.000000;0.000000;,
  0.000000;1.000000;,
  1.000000;1.000000;,
  1.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;1.000000;,
  1.000000;1.000000;,
  1.000000;0.000000;,
  0.392580;0.551020;,
  0.230550;0.795920;,
  0.367580;0.795920;,
  0.392580;0.551020;,
  1.352932;-0.493795;,
  1.437685;-0.413440;,
  -0.434007;-0.413440;,
  -0.349535;-0.493795;,
  0.000000;0.000000;,
  0.000000;1.000000;,
  1.000000;0.000000;,
  0.000000;1.000000;,
  1.000000;1.000000;,
  0.367580;0.551020;,
  0.230550;0.551020;,
  1.352933;-0.493795;,
  -0.352952;-0.493389;,
  -0.434007;-0.413440;,
  1.437746;-0.411544;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;;
 }
}