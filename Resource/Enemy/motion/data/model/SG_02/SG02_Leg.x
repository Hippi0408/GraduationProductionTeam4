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
 68;
 -0.15954;-32.49497;-6.49613;,
 1.50721;-33.25185;-2.32192;,
 2.35162;-30.63520;4.34479;,
 -0.15954;-30.16996;5.53011;,
 -2.72981;-30.63520;4.34479;,
 -1.88541;-33.25185;-2.32192;,
 -0.15954;7.57810;-4.19537;,
 -2.72981;5.26632;-1.84672;,
 -2.72981;-0.03442;3.53858;,
 -0.15954;-0.97685;4.49606;,
 2.35162;-0.03442;3.53858;,
 2.35162;5.26632;-1.84672;,
 1.49038;-5.07858;-1.57293;,
 -0.16954;-5.07858;-3.59959;,
 -0.15954;7.57810;-4.19537;,
 2.35162;5.26632;-1.84672;,
 1.49038;-5.07858;-1.57293;,
 2.35162;5.26632;-1.84672;,
 1.49038;-5.07858;3.07406;,
 -1.86856;-5.07858;-1.57293;,
 -2.72981;5.26632;-1.84672;,
 1.49038;-5.07858;3.07406;,
 2.35162;-0.03442;3.53858;,
 -0.15954;-0.97685;4.49606;,
 -0.16954;-5.07858;3.90029;,
 -1.86856;-5.07858;-1.57293;,
 -1.86856;-5.07858;3.07406;,
 -2.72981;5.26632;-1.84672;,
 -2.72981;-0.03442;3.53858;,
 -1.86856;-5.07858;3.07406;,
 0.80413;-15.50073;-0.86878;,
 0.80413;-15.50073;1.87940;,
 0.80413;-15.50073;-0.86878;,
 -0.17754;-15.50073;-2.06732;,
 0.80413;-15.50073;1.87940;,
 -0.17754;-15.50073;2.36801;,
 -1.18231;-15.50073;-0.86878;,
 -1.18231;-15.50073;1.87940;,
 -1.18231;-15.50073;-0.86878;,
 -1.18231;-15.50073;1.87940;,
 0.67083;-19.38150;-0.73201;,
 0.67083;-19.38150;1.64735;,
 0.67083;-19.38150;-0.73201;,
 -0.17909;-19.38150;-1.76970;,
 0.67083;-19.38150;1.64735;,
 -0.17909;-19.38150;2.07039;,
 -1.04902;-19.38150;-0.73201;,
 -1.04902;-19.38150;1.64735;,
 -1.04902;-19.38150;-0.73201;,
 -1.04902;-19.38150;1.64735;,
 0.98834;-25.90966;-1.05780;,
 0.98834;-25.90966;2.20010;,
 1.50721;-33.25185;-2.32192;,
 0.98834;-25.90966;-1.05780;,
 1.50721;-33.25185;-2.32192;,
 -0.15954;-32.49497;-6.49613;,
 -0.17540;-25.90966;-2.47864;,
 0.98834;-25.90966;2.20010;,
 -0.17540;-25.90966;2.77933;,
 -0.15954;-30.16996;5.53011;,
 2.35162;-30.63520;4.34479;,
 -1.88541;-33.25185;-2.32192;,
 -1.36653;-25.90966;-1.05780;,
 -1.36653;-25.90966;2.20010;,
 -2.72981;-30.63520;4.34479;,
 -1.36653;-25.90966;-1.05780;,
 -1.88541;-33.25185;-2.32192;,
 -1.36653;-25.90966;2.20010;;
 
 34;
 4;0,1,2,3;,
 4;0,3,4,5;,
 4;6,7,8,9;,
 4;6,9,10,11;,
 4;12,13,14,15;,
 4;16,17,10,18;,
 4;13,19,20,14;,
 4;21,22,23,24;,
 4;25,26,8,27;,
 4;24,23,28,29;,
 4;30,16,18,31;,
 4;32,33,13,12;,
 4;34,21,24,35;,
 4;33,36,19,13;,
 4;35,24,29,37;,
 4;38,39,26,25;,
 4;40,30,31,41;,
 4;42,43,33,32;,
 4;44,34,35,45;,
 4;43,46,36,33;,
 4;45,35,37,47;,
 4;48,49,39,38;,
 4;50,40,41,51;,
 4;50,51,2,52;,
 4;53,54,55,56;,
 4;53,56,43,42;,
 4;57,44,45,58;,
 4;57,58,59,60;,
 4;56,55,61,62;,
 4;56,62,46,43;,
 4;58,45,47,63;,
 4;58,63,64,59;,
 4;65,66,4,67;,
 4;65,67,49,48;;
 
 MeshMaterialList {
  7;
  34;
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
  0;;
  Material {
   0.800000;0.800000;0.800000;1.000000;;
   21.000000;
   0.920000;0.920000;0.920000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.800000;0.279200;0.119200;1.000000;;
   5.000000;
   0.520000;0.520000;0.520000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.571200;0.571200;0.571200;1.000000;;
   5.000000;
   0.960000;0.960000;0.960000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.000000;0.395200;0.408000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.028000;0.088000;0.489600;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.000000;0.646400;0.656000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.571200;0.000000;0.160000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
 }
 MeshNormals {
  60;
  -0.000005;0.712680;0.701490;,
  0.356861;-0.893592;0.272294;,
  0.000005;0.712680;0.701490;,
  -0.364969;-0.890399;0.272006;,
  0.241241;0.327088;0.913683;,
  -0.236282;0.327425;0.914857;,
  -0.004347;-0.956464;0.291819;,
  0.000000;0.712680;0.701490;,
  0.002404;0.337003;0.941500;,
  0.927112;-0.091744;-0.363381;,
  0.746011;-0.075976;-0.661586;,
  0.995130;-0.096323;-0.020936;,
  -0.925038;-0.091821;-0.368610;,
  0.004525;-0.149934;0.988686;,
  -0.995130;-0.096324;-0.020936;,
  0.939843;-0.064304;-0.335499;,
  0.998748;-0.050022;-0.000000;,
  0.771669;-0.071111;-0.632036;,
  0.004578;-0.111056;0.993804;,
  -0.937902;-0.064480;-0.340856;,
  -0.435143;-0.099739;0.894820;,
  0.941723;0.009168;-0.336265;,
  0.999975;0.007132;0.000000;,
  0.773588;0.010137;-0.633608;,
  0.004606;0.015842;0.999864;,
  -0.939787;0.009194;-0.341638;,
  -0.437280;0.014211;0.899213;,
  0.941668;0.113057;-0.316985;,
  0.994741;0.089709;-0.049420;,
  0.817499;0.127964;-0.561534;,
  0.004499;0.326937;0.945035;,
  -0.939764;0.113680;-0.322368;,
  -0.432197;0.294094;0.852476;,
  0.720404;-0.058470;-0.691086;,
  0.914733;-0.099028;-0.391735;,
  0.991044;-0.126810;-0.041843;,
  -0.738511;-0.075761;-0.669972;,
  -0.912535;-0.098949;-0.396848;,
  -0.712688;-0.057929;-0.699085;,
  0.431767;-0.135871;0.891693;,
  -0.991044;-0.126811;-0.041843;,
  -0.423585;-0.135189;0.895712;,
  0.443369;-0.099797;0.890766;,
  -0.764390;-0.071197;-0.640812;,
  -0.998748;-0.050021;0.000000;,
  0.445548;0.014219;0.895145;,
  -0.766295;0.010150;-0.642409;,
  -0.999975;0.007133;0.000000;,
  0.986534;0.130466;-0.098634;,
  0.940743;0.161444;-0.298224;,
  0.854602;0.185496;-0.485023;,
  0.440308;0.294276;0.848251;,
  0.004198;0.527022;0.849841;,
  0.419181;0.479548;0.770922;,
  -0.810852;0.128806;-0.570902;,
  -0.848604;0.187079;-0.494845;,
  -0.938842;0.162454;-0.303619;,
  -0.411544;0.479267;0.775200;,
  -0.986534;0.130467;-0.098634;,
  -0.994741;0.089710;-0.049419;;
  34;
  4;6,3,3,6;,
  4;6,6,1,1;,
  4;7,0,5,8;,
  4;7,8,4,2;,
  4;9,10,33,34;,
  4;9,34,35,11;,
  4;36,12,37,38;,
  4;39,4,8,13;,
  4;12,14,40,37;,
  4;13,8,5,41;,
  4;15,9,11,16;,
  4;15,17,10,9;,
  4;42,39,13,18;,
  4;43,19,12,36;,
  4;18,13,41,20;,
  4;19,44,14,12;,
  4;21,15,16,22;,
  4;21,23,17,15;,
  4;45,42,18,24;,
  4;46,25,19,43;,
  4;24,18,20,26;,
  4;25,47,44,19;,
  4;27,21,22,28;,
  4;27,28,48,49;,
  4;27,49,50,29;,
  4;27,29,23,21;,
  4;51,45,24,30;,
  4;51,30,52,53;,
  4;54,55,56,31;,
  4;54,31,25,46;,
  4;30,24,26,32;,
  4;30,32,57,52;,
  4;31,56,58,59;,
  4;31,59,47,25;;
 }
 MeshTextureCoords {
  68;
  0.503260;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.503260;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  0.503260;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  0.503260;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  1.000000;0.516830;,
  0.503260;0.516830;,
  0.503260;0.000000;,
  1.000000;0.000000;,
  0.000000;0.516830;,
  0.000000;0.000000;,
  1.000000;0.516830;,
  0.000000;0.516830;,
  0.000000;0.000000;,
  0.000000;0.516830;,
  0.000000;0.000000;,
  0.496740;0.000000;,
  0.496740;0.516830;,
  1.000000;0.516830;,
  0.000000;0.516830;,
  1.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;0.516830;,
  0.000000;0.689180;,
  1.000000;0.689180;,
  1.000000;0.689180;,
  0.503260;0.689180;,
  0.000000;0.689180;,
  0.496740;0.689180;,
  0.000000;0.689180;,
  1.000000;0.689180;,
  1.000000;0.689180;,
  0.000000;0.689180;,
  0.000000;0.789160;,
  1.000000;0.789160;,
  1.000000;0.789160;,
  0.503260;0.789160;,
  0.000000;0.789160;,
  0.496740;0.789160;,
  0.000000;0.789160;,
  1.000000;0.789160;,
  1.000000;0.789160;,
  0.000000;0.789160;,
  0.000000;0.883520;,
  1.000000;0.883520;,
  0.000000;1.000000;,
  1.000000;0.883520;,
  1.000000;1.000000;,
  0.503260;1.000000;,
  0.503260;0.883520;,
  0.000000;0.883520;,
  0.496740;0.883520;,
  0.496740;1.000000;,
  0.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.883520;,
  1.000000;0.883520;,
  1.000000;1.000000;,
  1.000000;0.883520;,
  1.000000;1.000000;,
  0.000000;0.883520;;
 }
}
