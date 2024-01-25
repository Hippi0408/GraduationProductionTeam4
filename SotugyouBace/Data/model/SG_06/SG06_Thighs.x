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
 110;
 -2.82556;5.20652;2.36633;,
 -2.82556;1.98626;5.17132;,
 1.77346;1.98626;5.17132;,
 1.77346;5.20652;2.36633;,
 1.77346;12.03387;0.53099;,
 -2.82556;12.03387;0.53099;,
 -3.34731;-0.94077;-8.15339;,
 2.29521;-0.94077;-8.15339;,
 2.29521;-4.20647;-3.92933;,
 -3.34731;-4.20647;-3.92933;,
 -2.82556;6.84047;-5.97418;,
 1.77346;6.84047;-5.97418;,
 -4.52799;-12.42833;-2.61395;,
 -5.33904;-3.62506;-3.64396;,
 -3.34731;-4.20647;-3.92933;,
 -3.91908;-15.46014;-2.50374;,
 -6.49030;-2.76161;0.79812;,
 -5.38730;3.78920;1.82430;,
 -4.58832;-1.80549;-4.35092;,
 4.28694;-3.62506;-3.64396;,
 4.33520;1.11160;-2.83839;,
 4.33520;3.78920;1.82430;,
 5.43820;-2.76161;0.79812;,
 3.47590;-12.42833;-2.61395;,
 2.86698;-15.46014;-2.50374;,
 2.29521;-4.20647;-3.92933;,
 -3.33459;-0.69016;1.38702;,
 -4.64956;-2.32972;3.02008;,
 -3.34731;-2.22259;6.27685;,
 -2.82556;5.20652;2.36633;,
 2.83489;1.11160;4.15662;,
 1.77346;5.20652;2.36633;,
 3.59747;-2.32972;3.02008;,
 2.29521;-2.22259;6.27685;,
 2.83489;9.46607;0.29824;,
 2.83489;5.14783;-5.11072;,
 1.77346;6.84047;-5.97418;,
 4.33520;3.78920;1.82430;,
 4.33520;1.11160;-2.83839;,
 -3.88698;5.14783;-5.11072;,
 -3.88698;9.46607;0.29824;,
 -2.82556;6.84047;-5.97418;,
 -5.38730;3.78920;1.82430;,
 -4.58832;-1.80549;-4.35092;,
 -4.64956;-0.90968;-7.15621;,
 -3.88698;5.14783;-5.11072;,
 -5.33904;-3.62506;-3.64396;,
 -4.58832;-1.80549;-4.35092;,
 2.83489;5.14783;-5.11072;,
 3.59747;-0.90968;-7.15621;,
 4.28694;-3.62506;-3.64396;,
 4.33520;1.11160;-2.83839;,
 -0.52605;13.78963;12.73422;,
 1.77346;1.98626;5.17132;,
 -2.82556;1.98626;5.17132;,
 -0.52605;13.78963;12.73422;,
 -3.34731;-2.22259;6.27685;,
 -0.52605;13.78963;12.73422;,
 2.29521;-2.22259;6.27685;,
 -0.52605;13.78963;12.73422;,
 -0.52605;17.27727;1.46280;,
 -0.52605;17.27727;1.46280;,
 -0.52605;17.27727;1.46280;,
 -0.52605;17.27727;1.46280;,
 2.29521;2.91246;-16.53815;,
 -3.34731;2.91246;-16.53815;,
 3.55463;-16.31118;-5.19721;,
 2.86698;-15.46014;-2.50374;,
 -4.60672;-16.31118;-5.19721;,
 -3.91908;-15.46014;-2.50374;,
 3.72458;-13.64350;9.21049;,
 -4.77668;-13.64350;9.21049;,
 -3.91908;-13.58655;7.13514;,
 2.86698;-13.58655;7.13514;,
 -3.88228;0.18981;12.16549;,
 2.83018;0.18981;12.16549;,
 -4.60672;-16.31118;-5.19721;,
 -5.93474;-13.26541;-4.41989;,
 -5.24973;-14.93051;4.14317;,
 -3.91908;-14.21127;3.92129;,
 -6.86270;-11.87466;2.79839;,
 -6.53488;-4.20349;-5.26296;,
 -7.67453;-2.93939;0.88631;,
 3.55463;-16.31118;-5.19721;,
 4.19765;-14.93051;4.14317;,
 2.86698;-14.21127;3.92129;,
 4.88265;-13.26541;-4.41989;,
 5.81061;-11.87466;2.79839;,
 6.62244;-2.93939;0.88631;,
 5.48278;-4.20349;-5.26296;,
 -4.77668;-13.64350;9.21049;,
 -3.91908;-13.58655;7.13514;,
 -6.81295;-10.99701;6.71858;,
 -5.77085;-2.20073;4.27938;,
 -3.88228;0.18981;12.16549;,
 2.83018;0.18981;12.16549;,
 4.71876;-2.20073;4.27938;,
 5.76085;-10.99701;6.71858;,
 3.72458;-13.64350;9.21049;,
 2.86698;-13.58655;7.13514;,
 -3.91908;-17.11156;-2.18274;,
 -3.91908;-22.19466;5.47311;,
 -3.91908;-14.21127;3.92129;,
 -3.91908;-15.46014;-2.50374;,
 2.86698;-17.11156;-2.18274;,
 2.86698;-15.46014;-2.50374;,
 2.86698;-22.19466;5.47311;,
 2.86698;-14.21127;3.92129;,
 2.86698;-15.23799;7.45615;,
 -3.91908;-15.23799;7.45615;;
 
 74;
 4;0,1,2,3;,
 4;4,5,0,3;,
 4;6,7,8,9;,
 4;6,10,11,7;,
 4;12,13,14,15;,
 4;13,16,17,18;,
 4;19,20,21,22;,
 4;19,23,24,25;,
 4;26,27,28,1;,
 4;17,26,1,29;,
 4;16,27,26,17;,
 4;30,21,31,2;,
 4;32,30,2,33;,
 4;22,21,30,32;,
 4;34,35,36,4;,
 4;37,34,4,3;,
 4;35,34,37,38;,
 4;39,40,5,41;,
 4;40,42,0,5;,
 4;40,39,43,42;,
 4;44,45,10,6;,
 4;46,44,6,9;,
 4;45,44,46,47;,
 4;48,49,7,11;,
 4;49,50,8,7;,
 4;49,48,51,50;,
 3;52,53,54;,
 3;55,54,56;,
 3;57,56,58;,
 3;59,58,53;,
 3;60,36,41;,
 3;61,41,5;,
 3;62,5,4;,
 3;63,4,36;,
 4;64,65,9,8;,
 4;66,64,8,67;,
 4;68,66,67,69;,
 4;65,68,69,9;,
 4;65,64,66,68;,
 4;70,71,72,73;,
 4;74,75,58,56;,
 4;74,71,70,75;,
 4;76,77,12,15;,
 4;78,76,15,79;,
 4;80,77,76,78;,
 4;77,81,13,12;,
 4;81,82,16,13;,
 4;81,77,80,82;,
 4;83,84,85,24;,
 4;86,83,24,23;,
 4;86,87,84,83;,
 4;88,89,19,22;,
 4;89,86,23,19;,
 4;89,88,87,86;,
 4;90,78,79,91;,
 4;92,80,78,90;,
 4;93,94,28,27;,
 4;93,92,90,94;,
 4;82,93,27,16;,
 4;82,80,92,93;,
 4;95,96,32,33;,
 4;97,96,95,98;,
 4;84,98,99,85;,
 4;87,97,98,84;,
 4;96,88,22,32;,
 4;88,96,97,87;,
 4;100,101,102,103;,
 4;104,100,103,105;,
 4;106,104,105,107;,
 4;101,100,104,106;,
 4;108,106,107,99;,
 4;109,108,99,91;,
 4;101,109,91,102;,
 4;101,106,108,109;;
 
 MeshMaterialList {
  5;
  74;
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
   0.332800;0.332800;0.332800;1.000000;;
   5.000000;
   0.870000;0.870000;0.870000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.800000;0.731200;0.000000;1.000000;;
   5.000000;
   0.820000;0.820000;0.820000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.800000;0.000000;0.034400;1.000000;;
   5.000000;
   0.910000;0.910000;0.910000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.000000;0.000000;0.000000;1.000000;;
   5.000000;
   0.800000;0.800000;0.800000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.800000;0.398400;0.000000;1.000000;;
   5.000000;
   0.870000;0.870000;0.870000;;
   0.000000;0.000000;0.000000;;
  }
 }
 MeshNormals {
  111;
  -0.130111;-0.155026;-0.979305;,
  0.130110;-0.155026;-0.979305;,
  0.713698;0.408986;0.568653;,
  -0.251512;-0.965011;0.074136;,
  -0.712510;0.366400;0.598399;,
  0.251514;-0.965010;0.074136;,
  -0.349029;0.351758;0.868588;,
  0.301661;0.434239;0.848786;,
  0.478346;-0.862170;0.166877;,
  -0.478341;-0.862173;0.166877;,
  -0.226410;-0.586709;-0.777503;,
  0.226408;-0.586709;-0.777503;,
  -0.964929;0.251235;0.076111;,
  0.944401;0.159531;0.287499;,
  -0.432385;0.438318;-0.787986;,
  0.432384;0.438318;-0.787986;,
  -0.180638;0.124550;0.975632;,
  0.180637;0.124550;0.975632;,
  -0.188570;-0.769597;-0.610051;,
  0.188569;-0.769597;-0.610051;,
  -0.967181;0.220479;-0.126295;,
  -0.257852;-0.116421;-0.959145;,
  0.970202;0.153715;-0.187294;,
  0.257850;-0.116421;-0.959145;,
  0.779650;0.215349;0.588022;,
  -0.768530;0.310780;0.559265;,
  -0.859948;0.274155;0.430497;,
  0.886385;0.246455;0.391894;,
  -0.336568;-0.448306;-0.828096;,
  0.973478;0.110835;-0.200140;,
  -0.925047;0.235619;-0.297947;,
  0.972370;0.068782;0.223081;,
  -0.754537;0.422035;0.502553;,
  0.836382;0.094047;0.540018;,
  -0.918380;0.282775;-0.276798;,
  0.899704;0.260983;-0.349886;,
  -0.930771;0.268309;-0.248346;,
  0.919248;0.314872;-0.236302;,
  -0.903727;0.298086;-0.307282;,
  0.864200;0.200850;-0.461321;,
  0.000000;0.539496;-0.841988;,
  -0.479020;0.576953;-0.661563;,
  0.243962;-0.939605;0.240051;,
  0.981166;-0.181544;0.065988;,
  0.000000;0.870793;0.491649;,
  0.087914;0.952240;-0.292420;,
  -0.087913;0.952240;-0.292420;,
  0.811847;0.149304;-0.564458;,
  -0.811847;0.149304;-0.564458;,
  0.954892;-0.114214;0.274111;,
  -0.954892;-0.114214;0.274109;,
  -0.969189;-0.237564;0.065082;,
  0.969189;-0.237563;0.065083;,
  0.796840;-0.000162;-0.604190;,
  0.159472;0.960607;-0.227604;,
  -0.132316;0.974244;-0.182595;,
  0.132316;0.974244;-0.182595;,
  0.035192;0.984671;-0.170834;,
  -0.035192;0.984671;-0.170834;,
  -1.000000;0.000000;0.000000;,
  0.000000;-0.554973;-0.831868;,
  1.000000;0.000000;0.000000;,
  0.000000;-0.042839;0.999082;,
  -0.373619;0.292605;-0.880222;,
  0.373617;0.292605;-0.880223;,
  -0.960990;0.258919;-0.097262;,
  0.336567;-0.448306;-0.828097;,
  -0.931277;0.356738;0.073899;,
  -0.412370;0.394804;0.821024;,
  0.868704;0.387101;-0.309042;,
  0.853213;0.407600;-0.325408;,
  0.512147;0.268491;0.815854;,
  -0.853214;0.407599;-0.325407;,
  -0.868706;0.387098;-0.309039;,
  -0.512149;0.268491;0.815853;,
  -0.370347;-0.720334;-0.586483;,
  0.370345;-0.720335;-0.586483;,
  -0.986743;0.142649;0.077389;,
  -0.000000;-0.374010;0.927425;,
  0.986743;0.142649;0.077389;,
  -0.000000;-0.174970;0.984574;,
  0.836930;0.427722;-0.341472;,
  0.986261;0.087969;0.139823;,
  0.996559;0.044136;0.070153;,
  -0.243959;-0.939606;0.240051;,
  -0.986261;0.087968;0.139821;,
  -0.981166;-0.181544;0.065988;,
  -0.996559;0.044136;0.070152;,
  0.000000;-0.508115;-0.861289;,
  0.000000;-0.208902;0.977937;,
  0.807253;0.295166;-0.511097;,
  -0.959133;-0.272803;-0.075112;,
  -0.892676;-0.445132;0.070628;,
  -0.159473;0.960607;-0.227604;,
  -0.985900;-0.099362;-0.134645;,
  -0.998322;-0.014135;0.056154;,
  -0.807252;0.295167;-0.511098;,
  0.959133;-0.272803;-0.075113;,
  0.892676;-0.445130;0.070628;,
  -0.796840;-0.000163;-0.604190;,
  0.985899;-0.099362;-0.134646;,
  0.998322;-0.014135;0.056154;,
  -0.935177;-0.209370;0.285672;,
  -0.945223;0.060008;0.320861;,
  -0.917360;0.047919;0.395163;,
  0.945223;0.060008;0.320862;,
  0.917360;0.047919;0.395164;,
  0.935177;-0.209369;0.285673;,
  0.000000;-0.833093;-0.553132;,
  0.000000;0.190810;0.981627;,
  0.000000;-0.274136;0.961691;;
  74;
  4;6,4,2,7;,
  4;17,16,6,7;,
  4;18,19,11,10;,
  4;63,14,15,64;,
  4;21,28,10,0;,
  4;65,30,26,20;,
  4;29,22,27,31;,
  4;66,23,1,11;,
  4;25,32,12,67;,
  4;26,25,4,6;,
  4;68,32,25,26;,
  4;24,27,7,2;,
  4;33,24,2,13;,
  4;31,27,24,33;,
  4;37,35,69,70;,
  4;27,71,17,7;,
  4;35,37,27,22;,
  4;34,36,72,73;,
  4;74,26,6,16;,
  4;36,34,20,26;,
  4;38,34,14,63;,
  4;28,75,18,10;,
  4;34,38,65,20;,
  4;35,39,64,15;,
  4;76,66,11,19;,
  4;39,35,22,29;,
  3;40,40,40;,
  3;77,4,12;,
  3;78,78,78;,
  3;79,13,2;,
  3;41,15,14;,
  3;41,14,72;,
  3;80,16,17;,
  3;81,70,15;,
  4;44,44,44,44;,
  4;43,82,82,83;,
  4;42,84,84,42;,
  4;85,86,87,85;,
  4;88,88,88,88;,
  4;3,5,5,3;,
  4;45,46,46,45;,
  4;89,89,89,89;,
  4;90,47,47,90;,
  4;8,42,42,8;,
  4;51,91,86,92;,
  4;47,53,53,47;,
  4;93,55,55,93;,
  4;94,91,51,95;,
  4;84,9,9,84;,
  4;48,96,96,48;,
  4;97,52,98,43;,
  4;56,54,54,56;,
  4;99,48,48,99;,
  4;100,101,52,97;,
  4;5,8,8,5;,
  4;50,51,92,102;,
  4;57,45,45,57;,
  4;103,50,102,104;,
  4;55,57,57,55;,
  4;95,51,50,103;,
  4;46,58,58,46;,
  4;49,105,106,107;,
  4;9,3,3,9;,
  4;52,49,107,98;,
  4;58,56,56,58;,
  4;101,105,49,52;,
  4;59,59,59,87;,
  4;60,60,0,1;,
  4;61,61,83,61;,
  4;108,60,60,108;,
  4;61,61,61,61;,
  4;62,62,109,109;,
  4;59,59,59,59;,
  4;110,110,62,62;;
 }
 MeshTextureCoords {
  110;
  0.000000;0.333430;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;0.333430;,
  1.000000;0.333430;,
  0.000000;0.333430;,
  0.000000;0.408600;,
  1.000000;0.408600;,
  1.000000;0.408600;,
  0.000000;0.408600;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  1.000000;0.408600;,
  1.000000;0.408600;,
  1.000000;1.000000;,
  0.333430;0.408600;,
  0.333430;0.000000;,
  1.000000;0.000000;,
  0.000000;0.408600;,
  0.000000;0.000000;,
  0.666570;0.000000;,
  0.666570;0.408600;,
  0.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.408600;,
  0.000000;0.000000;,
  0.000000;0.408600;,
  0.000000;0.408600;,
  0.333430;0.000000;,
  1.000000;0.000000;,
  0.666570;0.000000;,
  1.000000;0.408600;,
  1.000000;0.408600;,
  1.000000;0.333430;,
  1.000000;1.000000;,
  1.000000;1.000000;,
  1.000000;0.333430;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.333430;,
  0.000000;1.000000;,
  0.000000;0.333430;,
  0.000000;1.000000;,
  0.000000;0.408600;,
  0.000000;0.000000;,
  0.000000;0.408600;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;0.408600;,
  1.000000;0.408600;,
  1.000000;0.000000;,
  0.500000;0.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;0.204300;,
  1.000000;0.408600;,
  0.500000;0.408600;,
  0.000000;0.408600;,
  0.000000;0.204300;,
  0.500000;1.000000;,
  0.000000;0.666710;,
  0.500000;0.333430;,
  1.000000;0.666710;,
  1.000000;0.408600;,
  0.000000;0.408600;,
  1.000000;1.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;1.000000;,
  1.000000;1.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  1.000000;0.408600;,
  0.000000;0.408600;,
  1.000000;1.000000;,
  1.000000;1.000000;,
  0.333430;1.000000;,
  0.333430;1.000000;,
  0.333430;1.000000;,
  1.000000;0.408600;,
  0.333430;0.408600;,
  0.000000;1.000000;,
  0.666570;1.000000;,
  0.666570;1.000000;,
  0.000000;1.000000;,
  0.666570;1.000000;,
  0.666570;0.408600;,
  0.000000;0.408600;,
  0.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.408600;,
  0.000000;0.408600;,
  1.000000;0.408600;,
  1.000000;0.408600;,
  1.000000;1.000000;,
  1.000000;1.000000;,
  1.000000;1.000000;,
  0.000000;0.000000;,
  0.000000;0.666570;,
  0.000000;0.666570;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;0.666570;,
  1.000000;0.666570;,
  1.000000;1.000000;,
  0.000000;1.000000;;
 }
}