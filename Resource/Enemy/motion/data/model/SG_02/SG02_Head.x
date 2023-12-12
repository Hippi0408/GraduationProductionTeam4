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
 170;
 -0.05312;5.44941;-6.67702;,
 -1.39432;6.51473;-3.64518;,
 -1.88307;9.61687;1.83778;,
 -1.04390;13.10891;5.13241;,
 -0.05312;0.29218;-0.12461;,
 -1.04390;2.86366;4.42046;,
 -2.29446;2.78229;2.62957;,
 -3.10331;1.91445;1.09556;,
 0.93766;13.10891;5.13241;,
 1.84337;9.61687;1.83778;,
 1.35462;6.51473;-3.64518;,
 -0.05312;5.44941;-6.67702;,
 0.93766;2.86366;4.42046;,
 -0.05312;0.29218;-0.12461;,
 3.06360;1.91445;1.09556;,
 2.25476;2.78229;2.62957;,
 -3.05752;4.93907;-2.75371;,
 -1.39432;6.51473;-3.64518;,
 -0.05312;5.44941;-6.67702;,
 -0.05312;4.44184;-7.09945;,
 -3.05752;4.93907;-2.75371;,
 -3.05752;7.51058;1.79134;,
 -1.39432;6.51473;-3.64518;,
 -0.05312;4.44184;-7.09945;,
 -0.05312;5.44941;-6.67702;,
 1.35462;6.51473;-3.64518;,
 3.01781;4.93907;-2.75371;,
 -3.05752;7.51058;1.79134;,
 -1.04390;7.59370;1.93839;,
 -1.04390;13.10891;5.13241;,
 -1.88307;9.61687;1.83778;,
 3.01781;4.93907;-2.75371;,
 1.35462;6.51473;-3.64518;,
 3.01781;7.51058;1.79134;,
 3.01781;7.51058;1.79134;,
 1.84337;9.61687;1.83778;,
 0.93766;13.10891;5.13241;,
 0.93766;7.59370;1.93839;,
 -3.11872;5.45647;2.95351;,
 -2.53307;3.51363;-1.94721;,
 -3.10331;1.91445;1.09556;,
 -2.53307;3.51363;-1.94721;,
 -0.05312;2.57947;-4.37213;,
 -0.05312;0.29218;-0.12461;,
 -3.10331;1.91445;1.09556;,
 -0.05312;2.57947;-4.37213;,
 2.49336;3.51363;-1.94721;,
 3.06360;1.91445;1.09556;,
 -0.05312;0.29218;-0.12461;,
 2.49336;3.51363;-1.94721;,
 3.07901;5.45647;2.95351;,
 3.06360;1.91445;1.09556;,
 -2.89605;4.28661;-2.38457;,
 -0.05312;5.87782;-1.16697;,
 -2.89605;4.28661;-2.38457;,
 -3.56132;6.85820;2.16046;,
 -0.05312;5.87782;-1.16697;,
 2.85635;4.28661;-2.38457;,
 -3.56132;6.85820;2.16046;,
 -1.04390;7.49070;3.27852;,
 2.85635;4.28661;-2.38457;,
 3.52162;6.85820;2.16046;,
 3.52162;6.85820;2.16046;,
 0.93766;7.49070;3.27852;,
 -0.05312;4.41148;-0.86377;,
 -0.83559;3.98182;-1.32348;,
 -0.05312;4.41148;-0.86377;,
 0.79588;3.98182;-1.32348;,
 -0.83559;3.98182;-1.32348;,
 -3.17647;6.55332;3.22162;,
 0.79588;3.98182;-1.32348;,
 3.13677;6.55332;3.22162;,
 -3.17647;6.55332;3.22162;,
 -3.11872;5.45647;2.95351;,
 -1.04390;4.78215;4.37213;,
 -1.04390;6.80510;3.66643;,
 3.13677;6.55332;3.22162;,
 0.93766;6.80510;3.66643;,
 0.93766;4.78215;4.37213;,
 3.07901;5.45647;2.95351;,
 -2.52736;3.52992;4.24320;,
 -3.35161;6.66726;5.38582;,
 -2.29446;2.78229;2.62957;,
 -1.27680;3.68102;5.14614;,
 -1.04390;2.86366;4.42046;,
 -3.97930;12.14092;12.43116;,
 1.16603;3.68157;5.15099;,
 3.86853;12.14135;12.43606;,
 0.93766;2.86366;4.42046;,
 2.48313;3.53044;4.24806;,
 2.25476;2.78229;2.62957;,
 3.30738;6.66786;5.39067;,
 0.00092;7.59370;1.93839;,
 0.00092;7.49070;3.27852;,
 0.00092;15.71638;5.98377;,
 0.00092;6.80510;3.66643;,
 0.00092;15.71638;5.98377;,
 -0.05312;5.44941;-6.67702;,
 0.00092;4.78215;4.37213;,
 0.00092;2.86366;4.42046;,
 0.00092;2.86366;4.42046;,
 -0.05312;0.29218;-0.12461;,
 0.00000;5.53414;-2.53266;,
 0.51838;5.31648;-2.64383;,
 0.00000;5.20958;-3.00497;,
 0.00000;5.53414;-2.53266;,
 0.32038;5.48960;-2.05957;,
 0.00000;5.53414;-2.53266;,
 -0.32038;5.48960;-2.05957;,
 0.00000;5.53414;-2.53266;,
 -0.51838;5.31648;-2.64383;,
 0.00000;5.53414;-2.53266;,
 0.00000;5.20958;-3.00497;,
 0.83876;4.84242;-2.61198;,
 0.00000;4.66938;-3.19631;,
 0.51838;5.12248;-1.66658;,
 -0.51838;5.12248;-1.66658;,
 -0.83876;4.84242;-2.61198;,
 0.00000;4.66938;-3.19631;,
 0.83876;4.29291;-2.44923;,
 0.00000;4.11987;-3.03353;,
 0.51838;4.57300;-1.50381;,
 -0.51838;4.57300;-1.50381;,
 -0.83876;4.29291;-2.44923;,
 0.00000;4.11987;-3.03353;,
 0.51838;3.87797;-2.21773;,
 0.00000;3.77107;-2.57887;,
 0.32038;4.05110;-1.63344;,
 -0.32038;4.05110;-1.63344;,
 -0.51838;3.87797;-2.21773;,
 0.00000;3.77107;-2.57887;,
 0.00000;3.75601;-2.00594;,
 0.00000;3.75601;-2.00594;,
 0.00000;3.75601;-2.00594;,
 0.00000;3.75601;-2.00594;,
 0.00000;3.75601;-2.00594;,
 0.00000;5.84990;-0.50649;,
 0.46283;5.66610;-0.45206;,
 0.46283;5.13068;-2.25950;,
 0.00000;5.31457;-2.31398;,
 0.65454;5.22233;-0.32062;,
 0.65454;4.68694;-2.12806;,
 0.46283;4.77856;-0.18917;,
 0.46283;4.24316;-1.99661;,
 0.00000;4.59476;-0.13472;,
 0.00000;4.05935;-1.94216;,
 -0.46283;4.77856;-0.18917;,
 -0.46283;4.24316;-1.99661;,
 -0.65454;5.22233;-0.32062;,
 -0.65454;4.68694;-2.12806;,
 -0.46283;5.66610;-0.45206;,
 -0.46283;5.13068;-2.25950;,
 0.00000;5.84990;-0.50649;,
 0.00000;5.31457;-2.31398;,
 0.00000;5.22233;-0.32062;,
 0.00000;5.22233;-0.32062;,
 0.00000;5.22233;-0.32062;,
 0.00000;5.22233;-0.32062;,
 0.00000;5.22233;-0.32062;,
 0.00000;5.22233;-0.32062;,
 0.00000;5.22233;-0.32062;,
 0.00000;5.22233;-0.32062;,
 0.00000;4.68694;-2.12806;,
 0.00000;4.68694;-2.12806;,
 0.00000;4.68694;-2.12806;,
 0.00000;4.68694;-2.12806;,
 0.00000;4.68694;-2.12806;,
 0.00000;4.68694;-2.12806;,
 0.00000;4.68694;-2.12806;,
 0.00000;4.68694;-2.12806;;
 
 105;
 4;0,1,2,3;,
 4;4,5,6,7;,
 4;8,9,10,11;,
 4;12,13,14,15;,
 4;16,17,18,19;,
 4;20,21,2,22;,
 4;23,24,25,26;,
 4;27,28,29,30;,
 4;31,32,9,33;,
 4;34,35,36,37;,
 4;38,39,40,6;,
 4;41,42,43,44;,
 4;45,46,47,48;,
 4;49,50,15,51;,
 4;52,16,19,53;,
 4;54,55,21,20;,
 4;56,23,26,57;,
 4;58,59,28,27;,
 4;60,31,33,61;,
 4;62,34,37,63;,
 4;64,42,41,65;,
 4;64,65,52,53;,
 4;66,56,57,67;,
 4;66,67,46,45;,
 4;68,39,38,69;,
 4;68,69,55,54;,
 4;70,60,61,71;,
 4;70,71,50,49;,
 4;72,73,74,75;,
 4;72,75,59,58;,
 4;76,62,63,77;,
 4;76,77,78,79;,
 4;80,81,73,82;,
 4;83,80,82,84;,
 4;85,83,84,74;,
 4;81,85,74,73;,
 4;81,80,83,85;,
 4;86,87,78,88;,
 4;89,86,88,90;,
 4;91,89,90,79;,
 4;87,91,79,78;,
 4;87,86,89,91;,
 4;92,28,59,93;,
 4;92,93,63,37;,
 4;92,37,36,94;,
 4;92,94,29,28;,
 4;93,59,75,95;,
 4;93,95,77,63;,
 3;96,97,3;,
 3;96,8,97;,
 4;95,75,74,98;,
 4;95,98,78,77;,
 4;98,74,84,99;,
 4;98,99,88,78;,
 3;100,101,12;,
 3;100,5,101;,
 3;102,103,104;,
 3;105,106,103;,
 3;107,108,106;,
 3;109,110,108;,
 3;111,112,110;,
 4;104,103,113,114;,
 4;103,106,115,113;,
 4;106,108,116,115;,
 4;108,110,117,116;,
 4;110,112,118,117;,
 4;114,113,119,120;,
 4;113,115,121,119;,
 4;115,116,122,121;,
 4;116,117,123,122;,
 4;117,118,124,123;,
 4;120,119,125,126;,
 4;119,121,127,125;,
 4;121,122,128,127;,
 4;122,123,129,128;,
 4;123,124,130,129;,
 3;126,125,131;,
 3;125,127,132;,
 3;127,128,133;,
 3;128,129,134;,
 3;129,130,135;,
 4;136,137,138,139;,
 4;137,140,141,138;,
 4;140,142,143,141;,
 4;142,144,145,143;,
 4;144,146,147,145;,
 4;146,148,149,147;,
 4;148,150,151,149;,
 4;150,152,153,151;,
 3;154,137,136;,
 3;155,140,137;,
 3;156,142,140;,
 3;157,144,142;,
 3;158,146,144;,
 3;159,148,146;,
 3;160,150,148;,
 3;161,152,150;,
 3;162,139,138;,
 3;163,138,141;,
 3;164,141,143;,
 3;165,143,145;,
 3;166,145,147;,
 3;167,147,149;,
 3;168,149,151;,
 3;169,151,153;;
 
 MeshMaterialList {
  7;
  105;
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  6,
  6,
  6,
  6,
  6,
  6,
  6,
  6,
  6,
  6,
  6,
  6,
  6,
  6,
  6,
  6,
  6,
  6,
  6,
  6,
  6,
  6,
  6,
  6,
  6,
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
  133;
  -0.743397;0.505562;-0.437913;,
  -0.751010;-0.650710;0.112073;,
  0.736098;0.510598;-0.444353;,
  0.745989;-0.656417;0.112326;,
  0.717038;0.578716;-0.388516;,
  0.747021;-0.567561;0.346169;,
  -0.726217;0.570110;-0.384166;,
  -0.751739;-0.563775;0.342121;,
  -0.757070;0.477864;-0.445524;,
  -0.749040;0.530557;-0.396798;,
  -0.002466;-0.869563;0.493816;,
  -0.251300;-0.833818;0.491524;,
  0.754623;0.525198;-0.393332;,
  0.242641;-0.835116;0.493667;,
  -0.867896;0.353975;-0.348510;,
  -0.761280;0.365798;-0.535392;,
  -0.907140;0.341487;-0.245934;,
  0.866820;0.353157;-0.351997;,
  -0.165390;-0.337378;0.926727;,
  0.907139;0.341490;-0.245935;,
  0.145808;-0.340553;0.928851;,
  -0.874396;-0.148314;0.461990;,
  -0.879807;-0.463717;-0.104428;,
  -0.115875;0.129611;0.984771;,
  -0.589005;-0.690746;-0.419456;,
  0.112775;0.129880;0.985095;,
  0.877013;-0.468588;-0.106176;,
  0.872711;-0.148402;0.465137;,
  0.524710;-0.527902;-0.667831;,
  0.004215;-0.915283;-0.402790;,
  -0.980655;0.134767;-0.141965;,
  -0.510621;-0.534410;-0.673552;,
  -0.157218;0.834019;0.528861;,
  0.980653;0.134776;-0.141969;,
  0.153499;0.834190;0.529683;,
  -0.004212;0.893054;-0.449929;,
  -0.387686;0.771575;-0.504352;,
  -0.488179;-0.147595;-0.860172;,
  -0.598030;0.603554;-0.527335;,
  0.538711;-0.806314;0.244229;,
  -0.174560;0.406547;0.896799;,
  0.169977;0.407571;0.897214;,
  0.719013;-0.565369;0.404201;,
  -0.727977;-0.560386;0.394990;,
  -0.535342;-0.644934;0.545407;,
  -0.952302;0.017977;0.304627;,
  -0.853260;-0.412808;0.318649;,
  0.950701;0.016589;0.309666;,
  0.847666;-0.416723;0.328336;,
  0.000000;0.997059;0.076634;,
  0.000000;0.843888;0.536519;,
  -0.009497;-0.474746;0.880071;,
  0.000000;0.412567;0.910927;,
  0.000000;0.179440;0.983769;,
  0.000000;0.025184;0.999683;,
  0.759336;0.473190;-0.446655;,
  0.756173;0.362608;-0.544719;,
  -0.489457;-0.160392;0.857150;,
  0.471868;-0.168202;0.865476;,
  0.579720;-0.697016;-0.422010;,
  0.446181;-0.819297;-0.360104;,
  -0.438620;-0.822382;-0.362353;,
  -0.294855;0.807543;0.510817;,
  -0.131762;0.965731;0.223614;,
  -0.258261;0.895825;0.361660;,
  0.287957;0.808712;0.512899;,
  0.253217;0.895440;0.366153;,
  0.129190;0.965544;0.225908;,
  0.505761;-0.138437;-0.851493;,
  0.383763;0.772759;-0.505538;,
  -0.538712;-0.806313;0.244229;,
  0.598033;0.603551;-0.527336;,
  -0.355433;0.386266;0.851155;,
  0.346530;0.389058;0.853552;,
  0.436844;0.777783;-0.451908;,
  -0.646502;-0.495727;0.579906;,
  0.519694;-0.649245;0.555337;,
  -0.425339;0.781270;-0.456841;,
  0.630749;-0.499920;0.593495;,
  -0.820555;0.445652;-0.357889;,
  0.844474;0.414235;-0.339519;,
  0.000000;0.025184;0.999683;,
  0.000000;-0.870356;0.492424;,
  0.000000;0.958817;-0.284024;,
  0.000000;0.624632;-0.780919;,
  0.543463;0.736713;-0.402371;,
  0.335873;0.918172;0.210118;,
  -0.335873;0.918172;0.210118;,
  -0.543463;0.736713;-0.402371;,
  0.567176;0.030097;-0.823047;,
  0.917682;0.336468;0.211302;,
  0.000000;0.525842;0.850583;,
  -0.917682;0.336468;0.211302;,
  0.567139;-0.473512;-0.673899;,
  0.917673;-0.167103;0.360489;,
  0.000000;0.022266;0.999752;,
  -0.917673;-0.167103;0.360489;,
  0.184635;-0.960128;-0.209916;,
  0.393620;-0.917024;-0.064274;,
  0.427940;-0.747444;0.508129;,
  -0.129165;-0.685787;0.716249;,
  -0.507761;-0.817262;0.272511;,
  0.000000;-0.958818;0.284021;,
  -0.567176;0.030097;-0.823047;,
  -0.567139;-0.473512;-0.673899;,
  0.819877;-0.410239;0.399381;,
  0.000000;-0.241057;0.970511;,
  -0.819877;-0.410239;0.399381;,
  -0.506676;-0.684018;-0.524785;,
  0.000000;0.284003;0.958824;,
  0.000000;0.958823;-0.284006;,
  0.707121;0.677975;-0.200822;,
  1.000000;0.000008;-0.000003;,
  0.707100;-0.677993;0.200837;,
  0.000000;-0.958817;0.284024;,
  -0.707100;-0.677993;0.200837;,
  -1.000000;0.000008;-0.000003;,
  -0.707121;0.677975;-0.200822;,
  0.000000;-0.284014;-0.958820;,
  0.000007;0.283988;0.958828;,
  0.000000;0.283981;0.958830;,
  0.000000;0.284003;0.958823;,
  0.000006;0.284017;0.958819;,
  0.000000;0.284023;0.958818;,
  -0.000006;0.284017;0.958819;,
  -0.000007;0.283988;0.958828;,
  0.000000;-0.284026;-0.958817;,
  0.000008;-0.284018;-0.958819;,
  0.000000;-0.284009;-0.958822;,
  -0.000004;-0.284011;-0.958821;,
  0.000000;-0.284015;-0.958820;,
  0.000004;-0.284011;-0.958821;,
  -0.000008;-0.284018;-0.958819;;
  105;
  4;8,0,6,9;,
  4;10,11,7,1;,
  4;12,4,2,55;,
  4;13,10,3,5;,
  4;14,0,8,15;,
  4;14,16,6,0;,
  4;56,55,2,17;,
  4;57,18,18,57;,
  4;17,2,4,19;,
  4;58,58,20,20;,
  4;21,22,1,7;,
  4;22,24,24,1;,
  4;59,26,3,59;,
  4;26,27,5,3;,
  4;28,60,29,29;,
  4;30,30,16,14;,
  4;29,29,61,31;,
  4;62,32,63,64;,
  4;33,17,19,33;,
  4;65,66,67,34;,
  4;35,35,36,36;,
  4;68,68,28,68;,
  4;37,37,31,37;,
  4;35,69,69,35;,
  4;36,36,38,38;,
  4;70,70,70,70;,
  4;39,39,39,39;,
  4;69,71,71,69;,
  4;72,21,23,40;,
  4;72,40,32,62;,
  4;73,65,34,41;,
  4;73,41,25,27;,
  4;43,46,21,7;,
  4;44,43,7,11;,
  4;47,47,47,47;,
  4;74,74,74,74;,
  4;46,43,44,75;,
  4;45,45,45,45;,
  4;42,76,13,5;,
  4;48,42,5,27;,
  4;77,77,77,77;,
  4;78,76,42,48;,
  4;49,63,32,50;,
  4;49,50,34,67;,
  4;51,20,20,51;,
  4;51,51,18,18;,
  4;50,32,40,52;,
  4;50,52,41,34;,
  3;79,8,9;,
  3;80,12,55;,
  4;52,40,23,53;,
  4;52,53,25,41;,
  4;53,23,81,54;,
  4;53,54,54,25;,
  3;82,10,13;,
  3;82,11,10;,
  3;83,85,84;,
  3;83,86,85;,
  3;83,87,86;,
  3;83,88,87;,
  3;83,84,88;,
  4;84,85,89,89;,
  4;85,86,90,90;,
  4;86,87,91,91;,
  4;87,88,92,92;,
  4;88,84,103,103;,
  4;89,89,93,93;,
  4;90,90,94,94;,
  4;91,91,95,95;,
  4;92,92,96,96;,
  4;103,103,104,104;,
  4;93,93,98,97;,
  4;94,94,99,105;,
  4;95,95,100,106;,
  4;96,96,101,107;,
  4;104,104,108,108;,
  3;97,98,102;,
  3;98,99,102;,
  3;99,100,102;,
  3;100,101,102;,
  3;101,97,102;,
  4;110,111,111,110;,
  4;111,112,112,111;,
  4;112,113,113,112;,
  4;113,114,114,113;,
  4;114,115,115,114;,
  4;115,116,116,115;,
  4;116,117,117,116;,
  4;117,110,110,117;,
  3;109,119,120;,
  3;109,121,119;,
  3;109,122,121;,
  3;109,123,122;,
  3;109,124,123;,
  3;109,121,124;,
  3;109,125,121;,
  3;109,120,125;,
  3;118,126,127;,
  3;118,127,128;,
  3;118,128,129;,
  3;118,129,130;,
  3;118,130,131;,
  3;118,131,128;,
  3;118,128,132;,
  3;118,132,126;;
 }
 MeshTextureCoords {
  170;
  0.331440;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  0.331440;0.000000;,
  0.331440;0.000000;,
  0.331440;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  0.657610;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.657610;1.000000;,
  0.657610;1.000000;,
  0.657610;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;0.285620;,
  0.000000;0.000000;,
  0.331440;0.000000;,
  0.331440;0.285620;,
  1.000000;0.285620;,
  0.000000;0.285620;,
  1.000000;0.000000;,
  0.657610;0.285620;,
  0.657610;0.000000;,
  1.000000;0.000000;,
  1.000000;0.285620;,
  1.000000;0.285620;,
  0.668560;0.285620;,
  0.668560;0.000000;,
  1.000000;0.000000;,
  0.000000;0.285620;,
  0.000000;0.000000;,
  1.000000;0.285620;,
  0.000000;0.285620;,
  0.000000;0.000000;,
  0.342390;0.000000;,
  0.342390;0.285620;,
  0.000000;0.544020;,
  1.000000;0.544020;,
  1.000000;1.000000;,
  0.000000;0.544020;,
  0.331440;0.544020;,
  0.331440;1.000000;,
  0.000000;1.000000;,
  0.657610;0.544020;,
  1.000000;0.544020;,
  1.000000;1.000000;,
  0.657610;1.000000;,
  0.000000;0.544020;,
  1.000000;0.544020;,
  0.000000;1.000000;,
  0.000000;0.403880;,
  0.331440;0.403880;,
  1.000000;0.403880;,
  0.000000;0.403880;,
  0.657610;0.403880;,
  1.000000;0.403880;,
  1.000000;0.403880;,
  0.668560;0.403880;,
  0.000000;0.403880;,
  1.000000;0.403880;,
  0.000000;0.403880;,
  0.342390;0.403880;,
  0.331440;0.528170;,
  0.000000;0.528170;,
  0.657610;0.528170;,
  1.000000;0.528170;,
  1.000000;0.528170;,
  0.000000;0.528170;,
  0.000000;0.528170;,
  1.000000;0.528170;,
  1.000000;0.528170;,
  1.000000;0.544020;,
  0.668560;0.544020;,
  0.668560;0.528170;,
  0.000000;0.528170;,
  0.342390;0.528170;,
  0.342390;0.544020;,
  0.000000;0.544020;,
  1.000000;1.000000;,
  1.000000;0.544020;,
  1.000000;1.000000;,
  0.668560;1.000000;,
  0.668560;1.000000;,
  0.668560;0.544020;,
  0.342390;1.000000;,
  0.342390;0.544020;,
  0.342390;1.000000;,
  0.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.544020;,
  0.496580;0.285620;,
  0.496580;0.403880;,
  0.496580;0.000000;,
  0.496580;0.528170;,
  0.503420;0.000000;,
  0.494520;1.000000;,
  0.496580;0.544020;,
  0.496580;1.000000;,
  0.503420;1.000000;,
  0.494520;0.000000;,
  0.100000;0.000000;,
  0.200000;0.200000;,
  0.000000;0.200000;,
  0.300000;0.000000;,
  0.400000;0.200000;,
  0.500000;0.000000;,
  0.600000;0.200000;,
  0.700000;0.000000;,
  0.800000;0.200000;,
  0.900000;0.000000;,
  1.000000;0.200000;,
  0.200000;0.400000;,
  0.000000;0.400000;,
  0.400000;0.400000;,
  0.600000;0.400000;,
  0.800000;0.400000;,
  1.000000;0.400000;,
  0.200000;0.600000;,
  0.000000;0.600000;,
  0.400000;0.600000;,
  0.600000;0.600000;,
  0.800000;0.600000;,
  1.000000;0.600000;,
  0.200000;0.800000;,
  0.000000;0.800000;,
  0.400000;0.800000;,
  0.600000;0.800000;,
  0.800000;0.800000;,
  1.000000;0.800000;,
  0.100000;1.000000;,
  0.300000;1.000000;,
  0.500000;1.000000;,
  0.700000;1.000000;,
  0.900000;1.000000;,
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
  0.937500;1.000000;;
 }
}