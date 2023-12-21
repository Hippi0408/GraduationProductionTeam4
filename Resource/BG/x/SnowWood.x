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
 224;
 0.00152;-1.01610;0.00004;,
 0.04720;-1.76870;-9.42350;,
 3.09042;-1.63154;-6.61028;,
 2.82228;-1.10856;-15.07366;,
 5.67248;-1.01610;-12.26810;,
 -1.40626;-1.07316;-16.40048;,
 7.45108;-1.77162;-6.65816;,
 9.90438;-1.10794;-12.43330;,
 13.94254;-1.07042;-10.70176;,
 7.43152;-1.63248;-2.66576;,
 13.69238;-1.01610;-5.08160;,
 10.56498;-1.79132;0.06482;,
 18.28974;-1.06230;-1.25560;,
 7.41892;-1.63396;2.69606;,
 16.80904;-1.09248;2.52672;,
 13.69238;-1.01610;5.08168;,
 7.49706;-1.77218;6.62036;,
 13.89920;-1.10898;8.87104;,
 11.94494;-1.06796;12.47724;,
 3.08662;-1.63650;6.62300;,
 5.67248;-1.01610;12.26814;,
 0.09858;-1.78768;9.45996;,
 2.83008;-1.10190;15.07676;,
 -1.40198;-1.07124;16.40018;,
 -3.05134;-1.63430;6.62972;,
 -5.66946;-1.01610;12.26814;,
 -7.52284;-1.78448;6.62714;,
 -11.94798;-1.07248;12.48750;,
 -7.41006;-1.63584;2.71708;,
 -13.89760;-1.10452;8.87004;,
 -13.68936;-1.01610;5.08168;,
 -10.55934;-1.79078;0.00502;,
 -16.82172;-1.10666;2.52268;,
 -18.29840;-1.06672;-1.26340;,
 -7.39070;-1.63650;-2.76182;,
 -7.39070;-1.63650;-2.76182;,
 -13.68936;-1.01610;-5.08160;,
 -7.49124;-1.79428;-6.67870;,
 -13.89166;-1.10640;-8.87560;,
 -7.49124;-1.79428;-6.67870;,
 -11.93762;-1.06094;-12.47898;,
 -3.12788;-1.63340;-6.60116;,
 -3.12788;-1.63340;-6.60116;,
 -5.66946;-1.01610;-12.26810;,
 -1.40626;-1.07316;-16.40048;,
 0.04720;-1.76870;-9.42350;,
 2.89052;58.56020;3.72718;,
 3.01034;54.89152;-3.22432;,
 -2.61152;49.16660;-5.69512;,
 1.17004;18.61300;-5.91608;,
 6.45386;20.19676;0.38350;,
 6.01236;50.73454;3.79232;,
 1.16734;17.78726;6.18924;,
 -2.15190;49.68678;6.18722;,
 -2.71790;19.62552;6.26414;,
 -6.00246;48.33802;1.07380;,
 -6.00828;18.21024;2.47396;,
 -4.95470;18.08808;-3.62160;,
 -2.61152;49.16660;-5.69512;,
 1.17004;18.61300;-5.91608;,
 6.06608;2.65280;-7.20156;,
 -0.47092;3.19056;-9.65166;,
 -0.47092;3.19056;-9.65166;,
 2.82228;-1.10856;-15.07366;,
 6.06608;2.65280;-7.20156;,
 5.67248;-1.01610;-12.26810;,
 10.40330;2.00556;-0.67970;,
 7.29094;2.09760;5.90462;,
 -0.36462;2.93782;9.52854;,
 -7.05110;3.20138;7.14230;,
 -10.18866;2.57110;-0.22710;,
 -6.92696;2.68612;-7.00868;,
 -12.83656;60.60018;-13.73728;,
 -10.09262;53.54318;-9.48958;,
 -9.55068;53.93592;-6.11298;,
 -14.43372;68.88608;-20.87218;,
 -11.60900;59.96406;-17.34468;,
 -8.17702;53.16508;-12.23678;,
 -4.83800;53.02960;-12.67900;,
 -7.97304;60.26558;-16.22156;,
 -1.88262;53.33968;-9.48454;,
 -9.20060;60.90164;-12.61416;,
 -2.94832;53.89172;-5.11622;,
 -6.76196;54.10794;-4.10076;,
 0.51010;46.76756;0.54900;,
 -2.57810;47.61690;3.40458;,
 -4.03028;49.48412;0.92712;,
 -3.63956;48.55580;-2.16044;,
 -1.13190;47.38454;-4.18210;,
 1.75490;48.91914;-4.19200;,
 4.33974;47.44460;-0.80560;,
 3.20702;46.53416;3.46862;,
 -0.57950;46.57002;4.73286;,
 -1.13190;47.38454;-4.18210;,
 1.75490;48.91914;-4.19200;,
 4.33974;47.44460;-0.80560;,
 3.20702;46.53416;3.46862;,
 -9.35094;61.01832;9.26264;,
 -4.88992;54.02250;9.23294;,
 -3.34836;54.61360;4.91226;,
 -12.36244;66.96640;13.07908;,
 -11.68104;60.43828;11.97442;,
 -8.02826;53.31432;9.75510;,
 -14.20736;59.86964;10.55500;,
 -10.35662;52.93960;7.58652;,
 -13.95592;59.97012;7.51926;,
 -10.70612;53.06262;4.23508;,
 -8.87202;53.61130;1.66392;,
 -11.14132;60.63878;6.55940;,
 -5.92872;54.26422;1.37924;,
 -0.33160;44.20418;-0.23880;,
 3.34824;44.51378;-0.40486;,
 2.41552;46.78492;3.36290;,
 -0.02692;45.90306;4.71764;,
 -2.85320;44.79034;3.71620;,
 -4.43332;46.24818;1.30060;,
 -3.39650;44.84738;-2.71242;,
 0.30714;43.98250;-4.09144;,
 -2.60428;56.98352;-27.23788;,
 -0.43960;51.21486;-24.75034;,
 -3.14908;51.02508;-25.47274;,
 -1.96292;44.34792;-17.76304;,
 -4.03982;46.31244;-16.94694;,
 -2.64318;48.83986;-15.30742;,
 -2.40198;52.80978;-23.43616;,
 0.81394;47.87032;-15.35738;,
 0.81490;45.11174;-16.92824;,
 -0.62698;41.92610;1.59348;,
 -3.45242;40.04296;-1.22040;,
 -0.25068;38.42020;1.70292;,
 -3.75778;44.01616;-0.15400;,
 -1.54494;45.57962;-0.95628;,
 1.36546;44.95972;1.38044;,
 2.42492;41.59292;2.82460;,
 -2.73670;44.45930;-1.31948;,
 -2.41766;41.68342;-0.91536;,
 0.98622;43.03990;-1.34250;,
 -0.16580;46.22438;-1.42190;,
 0.81394;47.87032;-15.35738;,
 -2.64318;48.83986;-15.30742;,
 0.81490;45.11174;-16.92824;,
 -0.25068;38.42020;1.70292;,
 -1.96292;44.34792;-17.76304;,
 4.07978;49.22306;-9.46130;,
 0.98622;43.03990;-1.34250;,
 -2.41766;41.68342;-0.91536;,
 -0.16580;46.22438;-1.42190;,
 -2.73670;44.45930;-1.31948;,
 19.12358;52.41764;10.18434;,
 11.82130;42.13898;9.26134;,
 12.88052;41.48280;6.35436;,
 10.42590;44.66816;9.27154;,
 10.54008;46.02262;5.71514;,
 12.11190;43.93296;3.96592;,
 -3.23840;38.45962;-1.17500;,
 -3.25454;34.92946;-1.16622;,
 -2.18018;37.01826;2.99658;,
 -3.10104;40.97182;2.34824;,
 -1.42176;42.26940;0.38880;,
 -2.10918;41.22822;-3.35660;,
 -2.93480;37.71512;-4.60566;,
 16.05100;47.49770;-5.56006;,
 8.26452;44.21542;-6.30998;,
 8.27530;47.26394;-5.80644;,
 8.10996;45.28546;0.00230;,
 -1.61804;41.65198;2.18612;,
 -0.05506;39.44284;-1.56942;,
 -1.67886;38.22866;1.03242;,
 -0.41234;42.74996;-0.80822;,
 -2.10918;41.22822;-3.35660;,
 -2.93480;37.71512;-4.60566;,
 -0.05506;39.44284;-1.56942;,
 -0.41234;42.74996;-0.80822;,
 8.27530;47.26394;-5.80644;,
 -17.94356;53.27172;10.42754;,
 -14.96446;40.69012;6.60100;,
 -13.51582;41.37482;9.30654;,
 -11.45474;43.63016;9.01452;,
 -11.53110;44.57820;5.71514;,
 -13.97128;42.48664;4.19500;,
 -0.06588;33.48680;-1.17504;,
 -1.43942;32.38536;2.99658;,
 -0.91088;30.07250;-1.16622;,
 0.41388;35.95120;2.34824;,
 -0.89184;37.66596;0.38876;,
 -0.48166;36.47138;-3.35660;,
 -0.54062;32.85110;-4.60570;,
 -16.58366;47.38046;-5.64816;,
 -9.10000;44.96012;-5.99810;,
 -9.82814;41.97250;-6.29388;,
 -9.23434;43.78132;-0.11914;,
 -1.09672;35.28428;1.74978;,
 -2.90106;35.31128;-1.56942;,
 -1.74974;38.40756;-0.80822;,
 -0.91088;30.07250;-1.16622;,
 -1.43942;32.38536;2.99658;,
 -0.89184;37.66596;0.38876;,
 -0.48166;36.47138;-3.35660;,
 -0.54062;32.85110;-4.60570;,
 7.82258;56.29072;27.17862;,
 5.00548;44.78702;18.00008;,
 7.73256;46.49290;16.88686;,
 6.70256;49.44902;15.35292;,
 6.85262;61.56454;28.84138;,
 6.30424;58.26846;25.13370;,
 2.46228;49.07874;15.84952;,
 4.72552;56.31148;26.90338;,
 2.07856;46.26886;17.40040;,
 -0.61488;41.56796;-2.31914;,
 3.62256;40.34382;-0.49316;,
 -0.23842;37.66880;-2.47116;,
 2.68848;44.69694;-1.53212;,
 0.31674;45.83810;0.21440;,
 -3.28454;44.34220;-1.20228;,
 -4.07118;40.37772;-2.50224;,
 1.91328;44.94496;0.09900;,
 2.08758;41.84306;-0.34856;,
 -1.58162;42.43922;1.43376;,
 -1.09748;46.19122;1.25000;,
 -0.23842;37.66880;-2.47116;,
 3.62256;40.34382;-0.49316;,
 2.68848;44.69694;-1.53212;,
 0.31674;45.83810;0.21440;,
 -3.38562;48.43624;11.46316;;
 
 328;
 3;0,1,2;,
 3;1,3,2;,
 3;2,3,4;,
 3;1,5,3;,
 3;0,2,6;,
 3;2,7,6;,
 3;6,7,8;,
 3;2,4,7;,
 3;0,6,9;,
 3;6,8,9;,
 3;9,8,10;,
 3;0,9,11;,
 3;9,12,11;,
 3;9,10,12;,
 3;0,11,13;,
 3;11,14,13;,
 3;13,14,15;,
 3;11,12,14;,
 3;0,13,16;,
 3;13,17,16;,
 3;16,17,18;,
 3;13,15,17;,
 3;0,16,19;,
 3;16,18,19;,
 3;19,18,20;,
 3;0,19,21;,
 3;19,22,21;,
 3;21,22,23;,
 3;19,20,22;,
 3;0,21,24;,
 3;21,23,24;,
 3;24,23,25;,
 3;0,24,26;,
 3;24,27,26;,
 3;24,25,27;,
 3;0,26,28;,
 3;26,29,28;,
 3;28,29,30;,
 3;26,27,29;,
 3;0,28,31;,
 3;28,32,31;,
 3;31,32,33;,
 3;28,30,32;,
 3;0,31,34;,
 3;31,33,35;,
 3;35,33,36;,
 3;0,34,37;,
 3;35,38,39;,
 3;39,38,40;,
 3;35,36,38;,
 3;0,37,41;,
 3;39,40,42;,
 3;42,40,43;,
 3;0,41,1;,
 3;42,44,45;,
 3;42,43,44;,
 3;46,47,48;,
 3;47,49,48;,
 3;47,50,49;,
 3;46,51,47;,
 3;51,50,47;,
 3;51,52,50;,
 3;46,53,51;,
 3;51,53,52;,
 3;53,54,52;,
 3;46,55,53;,
 3;55,56,54;,
 3;55,54,53;,
 3;55,57,56;,
 3;46,48,55;,
 3;58,57,55;,
 3;58,59,57;,
 3;49,60,61;,
 3;62,63,44;,
 3;62,64,65;,
 3;62,65,63;,
 3;60,7,4;,
 3;60,8,7;,
 3;50,66,60;,
 3;50,60,49;,
 3;60,66,10;,
 3;60,10,8;,
 3;66,12,10;,
 3;50,67,66;,
 3;66,14,12;,
 3;66,67,15;,
 3;66,15,14;,
 3;50,52,67;,
 3;67,17,15;,
 3;67,18,17;,
 3;67,20,18;,
 3;52,68,67;,
 3;68,22,20;,
 3;68,20,67;,
 3;68,23,22;,
 3;52,54,68;,
 3;54,69,68;,
 3;68,69,25;,
 3;68,25,23;,
 3;56,69,54;,
 3;69,27,25;,
 3;56,70,69;,
 3;69,29,27;,
 3;69,70,30;,
 3;69,30,29;,
 3;70,32,30;,
 3;70,33,32;,
 3;57,70,56;,
 3;70,36,33;,
 3;57,71,70;,
 3;71,38,36;,
 3;71,36,70;,
 3;71,40,38;,
 3;71,43,40;,
 3;57,59,62;,
 3;57,62,71;,
 3;62,44,43;,
 3;62,43,71;,
 3;72,73,74;,
 3;75,76,72;,
 3;76,73,72;,
 3;76,77,73;,
 3;76,78,77;,
 3;75,79,76;,
 3;79,78,76;,
 3;79,80,78;,
 3;75,81,79;,
 3;81,80,79;,
 3;81,82,80;,
 3;81,83,82;,
 3;75,72,81;,
 3;72,83,81;,
 3;72,74,83;,
 3;84,85,86;,
 3;84,86,87;,
 3;84,87,88;,
 3;84,88,89;,
 3;84,89,90;,
 3;84,90,91;,
 3;84,91,92;,
 3;84,92,85;,
 3;74,86,85;,
 3;74,73,87;,
 3;74,87,86;,
 3;77,87,73;,
 3;77,93,87;,
 3;78,93,77;,
 3;78,94,93;,
 3;80,95,94;,
 3;80,94,78;,
 3;80,96,95;,
 3;82,96,80;,
 3;82,83,96;,
 3;83,92,91;,
 3;83,74,85;,
 3;83,85,92;,
 3;97,98,99;,
 3;100,101,97;,
 3;101,98,97;,
 3;101,102,98;,
 3;100,103,101;,
 3;103,104,101;,
 3;101,104,102;,
 3;100,105,103;,
 3;105,106,103;,
 3;103,106,104;,
 3;105,107,106;,
 3;100,108,105;,
 3;108,107,105;,
 3;108,109,107;,
 3;108,99,109;,
 3;100,97,108;,
 3;97,99,108;,
 3;110,111,112;,
 3;110,112,113;,
 3;110,113,114;,
 3;110,114,115;,
 3;110,115,116;,
 3;110,116,117;,
 3;110,117,111;,
 3;99,112,111;,
 3;98,112,99;,
 3;98,113,112;,
 3;98,102,113;,
 3;102,114,113;,
 3;102,104,114;,
 3;104,115,114;,
 3;104,106,115;,
 3;106,116,115;,
 3;107,116,106;,
 3;107,117,116;,
 3;109,117,107;,
 3;99,111,117;,
 3;99,117,109;,
 3;118,119,120;,
 3;120,119,121;,
 3;120,121,122;,
 3;120,122,123;,
 3;118,120,124;,
 3;124,120,123;,
 3;124,123,125;,
 3;118,124,119;,
 3;119,124,125;,
 3;119,125,126;,
 3;119,126,121;,
 3;127,128,129;,
 3;127,130,128;,
 3;127,131,130;,
 3;127,132,131;,
 3;127,133,132;,
 3;127,129,133;,
 3;134,135,136;,
 3;134,136,137;,
 3;121,129,128;,
 3;128,122,121;,
 3;128,130,122;,
 3;130,123,122;,
 3;123,130,131;,
 3;131,132,123;,
 3;132,138,139;,
 3;132,133,138;,
 3;133,140,138;,
 3;140,133,141;,
 3;140,141,142;,
 3;143,144,145;,
 3;143,146,144;,
 3;143,147,146;,
 3;143,145,147;,
 3;148,149,150;,
 3;148,151,149;,
 3;148,152,151;,
 3;148,153,152;,
 3;148,150,153;,
 3;154,155,156;,
 3;154,156,157;,
 3;154,157,158;,
 3;154,158,159;,
 3;154,159,160;,
 3;154,160,155;,
 3;161,162,163;,
 3;161,163,164;,
 3;161,164,162;,
 3;165,166,167;,
 3;165,168,166;,
 3;150,149,156;,
 3;150,156,155;,
 3;151,156,149;,
 3;151,157,156;,
 3;151,158,157;,
 3;152,158,151;,
 3;152,169,158;,
 3;152,170,169;,
 3;153,170,152;,
 3;153,150,170;,
 3;150,155,170;,
 3;162,167,171;,
 3;162,171,172;,
 3;162,172,163;,
 3;168,165,173;,
 3;165,164,163;,
 3;165,167,164;,
 3;164,167,162;,
 3;174,175,176;,
 3;174,176,177;,
 3;174,177,178;,
 3;174,178,179;,
 3;174,179,175;,
 3;180,181,182;,
 3;180,183,181;,
 3;180,184,183;,
 3;180,185,184;,
 3;180,186,185;,
 3;180,182,186;,
 3;187,188,189;,
 3;187,190,188;,
 3;187,189,190;,
 3;191,192,193;,
 3;175,194,195;,
 3;175,195,176;,
 3;195,183,177;,
 3;195,177,176;,
 3;177,183,196;,
 3;196,178,177;,
 3;196,197,178;,
 3;197,198,178;,
 3;198,179,178;,
 3;179,198,194;,
 3;179,194,175;,
 3;189,192,191;,
 3;189,193,192;,
 3;189,188,193;,
 3;188,191,193;,
 3;190,191,188;,
 3;190,189,191;,
 3;199,200,201;,
 3;199,201,202;,
 3;203,199,204;,
 3;204,199,202;,
 3;204,202,205;,
 3;203,204,206;,
 3;206,204,205;,
 3;206,205,207;,
 3;206,207,200;,
 3;203,206,199;,
 3;199,206,200;,
 3;208,209,210;,
 3;208,211,209;,
 3;208,212,211;,
 3;208,213,212;,
 3;208,214,213;,
 3;208,210,214;,
 3;215,216,217;,
 3;215,217,218;,
 3;200,219,220;,
 3;200,220,201;,
 3;220,221,202;,
 3;220,202,201;,
 3;202,221,222;,
 3;222,205,202;,
 3;222,213,205;,
 3;213,214,205;,
 3;205,214,207;,
 3;207,214,219;,
 3;207,219,200;,
 3;223,217,216;,
 3;223,218,217;,
 3;223,215,218;,
 3;223,216,215;;
 
 MeshMaterialList {
  4;
  328;
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
  2,
  2,
  2,
  2,
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
  1,
  1,
  1,
  2,
  2,
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
  2,
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
  2,
  2,
  2,
  2,
  2,
  2,
  2,
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
  1,
  2,
  2,
  2,
  2,
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
  1,
  2,
  2,
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
  1,
  2,
  1,
  1,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  1,
  1,
  2,
  2,
  2,
  2,
  2,
  1,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
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
  1,
  2,
  2,
  2,
  2;;
  Material {
   0.800000;0.800000;0.800000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.385882;0.266667;0.156863;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
   TextureFilename {
    "texture\\Cedar.png";
   }
  }
  Material {
   0.800000;0.800000;0.800000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
   TextureFilename {
    "texture\\Cedar.png";
   }
  }
  Material {
   0.062400;0.062400;0.062400;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
 }
 MeshNormals {
  330;
  -0.711404;0.397527;-0.579548;,
  -0.565911;0.725087;-0.392421;,
  0.281615;0.139382;-0.949350;,
  0.906840;0.156696;-0.391264;,
  0.989790;0.135472;0.044298;,
  0.398527;0.101243;0.911552;,
  0.189718;0.048840;0.980623;,
  -0.467553;0.116142;0.876302;,
  -0.948786;0.155929;0.274758;,
  -0.716079;0.692558;-0.087140;,
  -0.955599;0.251475;0.153595;,
  -0.764158;0.156367;-0.625789;,
  0.461786;0.687281;-0.560713;,
  0.074886;-0.994152;-0.077811;,
  0.034781;-0.995117;-0.092373;,
  -0.003402;-0.993491;-0.113860;,
  0.094075;-0.995457;-0.014686;,
  0.083674;-0.995798;-0.037220;,
  0.503075;0.860064;-0.084887;,
  0.077731;-0.994838;-0.065229;,
  0.072630;-0.993494;0.087722;,
  0.084452;-0.995784;0.035818;,
  0.102948;-0.994680;-0.003727;,
  0.013640;-0.994424;0.104568;,
  0.510774;0.715286;0.476944;,
  0.041503;-0.995045;0.090344;,
  0.078244;-0.993709;0.080129;,
  -0.057532;-0.994667;0.085601;,
  0.068794;0.651952;0.755133;,
  -0.034412;-0.995060;0.093120;,
  -0.545684;0.658178;0.518682;,
  -0.013534;-0.994338;0.105398;,
  -0.105416;-0.994416;-0.004968;,
  -0.083750;-0.995740;0.038574;,
  -0.071362;-0.993730;0.086072;,
  -0.077606;-0.994766;-0.066464;,
  -0.706529;0.707442;-0.018507;,
  -0.086736;-0.995755;-0.030797;,
  -0.105638;-0.994395;0.004360;,
  -0.012166;-0.993927;-0.109369;,
  -0.479013;0.740237;-0.471801;,
  -0.035805;-0.995084;-0.092336;,
  -0.037364;0.658887;-0.751314;,
  -0.056031;-0.994892;-0.083965;,
  0.000218;-1.000000;-0.000209;,
  0.013569;-0.999232;-0.036760;,
  0.003819;-0.999844;-0.017221;,
  0.008744;-0.999852;-0.014806;,
  0.037224;-0.999117;-0.019460;,
  0.016506;-0.999854;0.004449;,
  0.033524;-0.999289;0.017273;,
  0.013540;-0.999861;0.009742;,
  0.018148;-0.999102;0.038300;,
  0.004145;-0.999832;0.017875;,
  -0.015864;-0.999002;0.041742;,
  -0.014090;-0.999858;0.009276;,
  -0.033902;-0.999295;0.016122;,
  -0.016071;-0.999865;0.003318;,
  -0.037254;-0.999198;-0.014651;,
  -0.012881;-0.999853;-0.011357;,
  -0.013131;-0.998970;-0.043433;,
  0.807015;0.129938;-0.576059;,
  0.357821;0.051030;-0.932395;,
  0.914816;0.363476;-0.176058;,
  0.716662;0.093047;0.691186;,
  0.266125;0.114131;0.957158;,
  0.272282;0.071622;0.959548;,
  -0.800162;0.286343;0.527018;,
  0.283282;0.827778;-0.484288;,
  -0.126624;0.846440;-0.517209;,
  0.223561;0.813813;-0.536404;,
  0.095637;0.840191;-0.533791;,
  0.325303;0.914462;-0.240703;,
  0.412136;0.889260;-0.198394;,
  0.353196;0.928880;-0.111507;,
  0.891968;0.169149;0.419262;,
  0.325707;0.915974;0.234320;,
  0.393652;0.902789;0.173235;,
  0.400950;0.911462;0.092062;,
  0.181275;0.930057;0.319583;,
  0.229780;0.865061;0.445949;,
  0.269902;0.845709;0.460359;,
  -0.118344;0.865349;0.486997;,
  -0.198683;0.789795;0.580301;,
  -0.239799;0.853459;0.462714;,
  -0.506829;0.853749;0.119321;,
  -0.484737;0.855736;0.180960;,
  -0.377014;0.884774;0.273925;,
  -0.394451;0.911818;-0.113998;,
  -0.451231;0.867097;-0.211028;,
  -0.453200;0.884960;-0.107034;,
  -0.212565;0.885965;-0.412167;,
  -0.240498;0.801047;-0.548164;,
  -0.817038;-0.551201;0.169195;,
  -0.588754;-0.808312;0.000861;,
  -0.167326;-0.973678;-0.154765;,
  -0.564939;-0.824560;0.030728;,
  -0.783213;-0.615392;-0.088713;,
  -0.047382;-0.936641;-0.347070;,
  -0.397517;-0.812192;-0.426993;,
  0.520353;-0.624989;-0.581912;,
  0.360283;-0.508134;-0.782302;,
  0.063424;-0.952798;-0.296908;,
  0.742233;-0.114903;-0.660218;,
  0.041108;-0.992246;-0.117294;,
  0.482270;0.804418;0.346881;,
  -0.209067;-0.972736;-0.100375;,
  -0.120100;0.736561;0.665623;,
  -0.192965;-0.881732;-0.430480;,
  -0.894936;-0.377429;-0.237983;,
  -0.922623;-0.374781;-0.091141;,
  -0.695719;-0.572514;-0.433823;,
  0.464240;-0.203393;-0.862040;,
  0.471084;0.808855;0.351899;,
  0.304574;-0.265259;-0.914807;,
  0.304358;-0.287417;-0.908162;,
  0.753347;0.641846;0.143185;,
  0.723254;0.678914;0.126409;,
  0.637404;0.756912;0.144225;,
  -0.281940;0.594259;0.753237;,
  -0.358193;0.617120;0.700615;,
  -0.528830;0.493169;0.690741;,
  0.379047;-0.618491;-0.688326;,
  0.755499;-0.143629;-0.639213;,
  0.395075;0.831935;0.389615;,
  0.410125;0.863791;0.292682;,
  0.067323;0.781741;0.619959;,
  -0.309834;0.626869;0.714869;,
  0.397887;-0.687222;0.607793;,
  -0.029558;-0.981614;0.188572;,
  0.612194;0.136610;0.778817;,
  0.316467;-0.645575;0.695040;,
  -0.336358;-0.869588;0.361496;,
  -0.130333;-0.505758;0.852773;,
  -0.651176;-0.644285;0.401083;,
  -0.621007;-0.782834;0.039010;,
  -0.452446;-0.886018;0.101313;,
  -0.865056;-0.460725;-0.198521;,
  -0.473195;0.243576;-0.846615;,
  0.201288;0.635319;-0.745556;,
  -0.067637;-0.996643;0.046133;,
  0.093599;-0.945945;0.310527;,
  0.696698;0.684615;-0.214277;,
  0.761299;-0.030137;0.647701;,
  0.762780;0.306035;0.569657;,
  0.580907;0.066679;0.811234;,
  -0.609900;-0.456474;0.647807;,
  -0.888515;0.067358;-0.453876;,
  0.120540;0.705556;-0.698327;,
  -0.446865;-0.194406;0.873223;,
  -0.449314;-0.409622;0.793931;,
  -0.752514;0.506192;-0.421299;,
  -0.994572;-0.060862;-0.084391;,
  -0.380741;0.626893;-0.679737;,
  0.608908;0.623188;-0.490782;,
  0.553134;0.692226;-0.463536;,
  0.810471;0.578529;0.091873;,
  0.675651;0.640325;-0.365348;,
  -0.570672;0.052673;-0.819487;,
  0.196433;0.549218;-0.812265;,
  -0.139141;-0.868263;-0.476192;,
  -0.462922;0.163357;0.871216;,
  -0.954524;-0.252417;-0.158647;,
  -0.828082;-0.138188;0.543308;,
  -0.847369;0.511765;0.141640;,
  -0.485543;0.462939;0.741576;,
  -0.302709;0.767620;0.564913;,
  0.728573;0.665711;0.161277;,
  -0.431050;0.341754;0.835105;,
  -0.357733;0.136610;0.923778;,
  0.896682;-0.400205;-0.189200;,
  -0.540827;-0.031811;0.840532;,
  0.265377;-0.296083;-0.917556;,
  0.253493;-0.524039;-0.813096;,
  -0.962553;0.216001;0.163817;,
  0.297861;-0.590092;-0.750380;,
  0.323043;0.178197;0.929456;,
  0.459988;0.188042;0.867785;,
  0.258800;-0.813444;-0.520895;,
  0.041000;0.091402;0.994970;,
  0.063644;0.150931;0.986493;,
  -0.708240;-0.583932;-0.396762;,
  -0.946694;0.282730;0.154380;,
  -0.901524;0.411667;0.133362;,
  -0.963567;0.153077;0.219331;,
  0.579869;0.720921;0.379506;,
  0.185915;0.943997;0.272589;,
  0.723243;0.483871;0.492735;,
  0.868547;0.454814;0.196901;,
  0.991940;0.062962;-0.109961;,
  0.375063;-0.700725;-0.606887;,
  0.053798;-0.953915;-0.295216;,
  -0.493504;-0.829850;-0.260390;,
  -0.980874;0.189957;0.042449;,
  0.151450;0.970188;0.189201;,
  0.950861;0.308810;0.022369;,
  0.992645;-0.090267;-0.080674;,
  0.782145;-0.599311;-0.170514;,
  0.792771;0.300022;0.530567;,
  -0.565744;0.824534;0.008782;,
  -0.699369;-0.181044;-0.691453;,
  0.614755;-0.778289;-0.127839;,
  -0.771698;-0.097339;0.628497;,
  -0.983731;0.178920;-0.016170;,
  0.499922;-0.787720;0.359966;,
  -0.296614;-0.066699;0.952665;,
  -0.980021;0.178011;-0.088721;,
  -0.594792;0.803750;0.014439;,
  -0.445296;0.887633;0.117554;,
  -0.776255;0.618739;-0.120793;,
  -0.983032;0.140817;-0.117554;,
  0.035229;0.656930;-0.753128;,
  -0.996754;0.004757;0.080372;,
  0.877551;-0.472532;-0.081342;,
  -0.370624;0.150193;-0.916559;,
  -0.810540;0.100228;-0.577044;,
  -0.702373;0.089223;-0.706195;,
  -0.272656;0.157731;-0.949094;,
  -0.156894;0.936230;0.314418;,
  -0.902831;0.079600;-0.422563;,
  -0.869730;0.171421;-0.462800;,
  0.026357;0.162820;-0.986304;,
  -0.067737;-0.041392;0.996844;,
  -0.207280;-0.118277;0.971105;,
  -0.658694;0.709933;0.249231;,
  -0.487163;0.827639;0.278721;,
  -0.051783;0.617830;-0.784605;,
  0.212875;0.523476;-0.825019;,
  0.697735;-0.375691;-0.609936;,
  -0.038623;0.946227;0.321189;,
  -0.228532;0.934317;0.273542;,
  0.369710;-0.914544;0.164084;,
  0.476414;-0.753906;0.452389;,
  0.469069;-0.881438;0.055159;,
  0.194522;-0.917373;0.347257;,
  0.175725;-0.897316;0.404901;,
  -0.463344;0.037273;0.885394;,
  -0.377661;0.887495;0.264053;,
  0.537402;-0.092204;-0.838271;,
  0.530795;0.170425;-0.830188;,
  0.516854;-0.688117;-0.509270;,
  0.515450;-0.856919;-0.000661;,
  0.426056;-0.892106;-0.150412;,
  -0.366168;0.911601;0.186829;,
  -0.320449;0.914846;0.245700;,
  0.316453;-0.307995;0.897216;,
  0.997515;-0.068818;-0.015110;,
  -0.622436;-0.611819;0.488109;,
  0.324025;-0.098661;0.940890;,
  0.734200;-0.259199;0.627508;,
  0.967549;0.250187;0.035445;,
  0.654233;0.755214;0.040391;,
  0.778772;0.627176;-0.012824;,
  0.907719;0.402295;-0.119186;,
  0.013023;0.577883;-0.816016;,
  0.987613;-0.104143;-0.117370;,
  -0.779732;-0.621708;0.074149;,
  0.967600;-0.239262;0.080647;,
  -0.968997;-0.243010;0.044615;,
  0.733949;-0.108060;-0.670554;,
  0.674871;-0.089012;-0.732548;,
  0.278997;0.027036;-0.959911;,
  0.516274;0.837359;0.179697;,
  0.859351;-0.204287;-0.468811;,
  0.379960;0.016289;-0.924860;,
  -0.013592;0.101791;-0.994713;,
  0.171303;-0.029038;0.984790;,
  0.257176;-0.110724;0.960000;,
  0.831037;0.539396;0.135756;,
  0.692817;0.693649;0.197116;,
  0.082404;0.521225;-0.849432;,
  -0.153065;0.500999;-0.851805;,
  -0.773929;-0.356247;-0.523566;,
  0.310083;0.930765;0.193715;,
  0.376684;0.830400;0.410542;,
  -0.583623;-0.762419;0.279467;,
  -0.698020;-0.641125;0.318946;,
  -0.657576;-0.703595;0.269347;,
  -0.396835;-0.822831;0.406782;,
  -0.394483;-0.821312;0.412105;,
  0.451950;-0.073252;0.889030;,
  -0.467583;0.295105;-0.833234;,
  -0.271860;0.479521;-0.834357;,
  -0.696786;-0.519441;-0.494642;,
  -0.682791;-0.480737;-0.550171;,
  -0.761854;-0.501419;0.410070;,
  -0.747807;-0.573048;0.335263;,
  0.403985;0.751641;0.521375;,
  0.022789;0.636305;0.771101;,
  0.101099;0.234085;-0.966945;,
  0.596085;-0.716674;0.362025;,
  0.936057;0.228213;-0.267797;,
  0.743412;0.070291;-0.665130;,
  0.104275;0.543198;-0.833104;,
  -0.088954;0.855626;-0.509893;,
  -0.754792;0.648095;-0.101301;,
  0.039820;0.405897;-0.913051;,
  -0.011418;0.184344;-0.982795;,
  -0.964865;0.215068;0.150932;,
  0.256887;-0.841561;0.475168;,
  0.229884;0.060066;-0.971363;,
  0.880509;0.282061;-0.380979;,
  0.155711;-0.544552;0.824147;,
  0.882211;0.326170;-0.339583;,
  -0.912121;0.391456;-0.121645;,
  -0.640590;0.080672;-0.763634;,
  -0.745718;0.063742;-0.663205;,
  -0.389493;0.053460;-0.919477;,
  0.118176;-0.842750;0.525174;,
  -0.420413;0.106389;-0.901074;,
  0.908454;0.291414;-0.299649;,
  0.947055;0.199403;-0.251645;,
  -0.670645;0.621739;-0.404569;,
  -0.011625;0.914423;-0.404594;,
  -0.853926;0.445192;-0.269472;,
  -0.201689;-0.508295;0.837232;,
  -0.488692;-0.710512;0.506313;,
  -0.428427;-0.558908;0.709980;,
  -0.086134;-0.313952;0.945524;,
  0.502615;-0.848375;0.166246;,
  0.535707;-0.829264;0.159180;,
  0.953499;0.141026;-0.266365;,
  -0.329110;0.932600;-0.148135;,
  -0.951066;0.091989;0.294977;,
  -0.951017;0.171205;0.257402;,
  -0.534182;-0.751351;0.387456;,
  -0.506406;-0.768276;0.391542;,
  -0.964037;0.112604;-0.240734;,
  0.336525;0.932709;-0.129630;,
  0.905028;-0.010499;0.425223;;
  328;
  3;44,46,45;,
  3;46,13,45;,
  3;45,13,14;,
  3;46,43,13;,
  3;44,45,47;,
  3;45,15,47;,
  3;47,15,16;,
  3;45,14,15;,
  3;44,47,48;,
  3;47,16,48;,
  3;48,16,17;,
  3;44,48,49;,
  3;48,19,49;,
  3;48,17,19;,
  3;44,49,50;,
  3;49,20,50;,
  3;50,20,21;,
  3;49,19,20;,
  3;44,50,51;,
  3;50,22,51;,
  3;51,22,23;,
  3;50,21,22;,
  3;44,51,52;,
  3;51,23,52;,
  3;52,23,25;,
  3;44,52,53;,
  3;52,26,53;,
  3;53,26,27;,
  3;52,25,26;,
  3;44,53,54;,
  3;53,27,54;,
  3;54,27,29;,
  3;44,54,55;,
  3;54,31,55;,
  3;54,29,31;,
  3;44,55,56;,
  3;55,32,56;,
  3;56,32,33;,
  3;55,31,32;,
  3;44,56,57;,
  3;56,34,57;,
  3;57,34,35;,
  3;56,33,34;,
  3;44,57,58;,
  3;57,35,58;,
  3;58,35,37;,
  3;44,58,59;,
  3;58,38,59;,
  3;59,38,39;,
  3;58,37,38;,
  3;44,59,60;,
  3;59,39,60;,
  3;60,39,41;,
  3;44,60,46;,
  3;60,43,46;,
  3;60,41,43;,
  3;9,1,0;,
  3;61,2,62;,
  3;61,3,2;,
  3;63,4,61;,
  3;4,3,61;,
  3;4,5,64;,
  3;65,6,66;,
  3;66,6,5;,
  3;6,7,5;,
  3;9,10,67;,
  3;10,8,7;,
  3;10,7,67;,
  3;10,11,8;,
  3;9,0,10;,
  3;0,11,10;,
  3;0,2,11;,
  3;2,12,42;,
  3;42,68,69;,
  3;42,12,70;,
  3;42,70,68;,
  3;12,71,70;,
  3;12,72,71;,
  3;3,18,12;,
  3;3,12,2;,
  3;12,18,73;,
  3;12,73,72;,
  3;18,74,73;,
  3;3,24,75;,
  3;18,76,74;,
  3;18,24,77;,
  3;18,77,76;,
  3;64,5,24;,
  3;24,78,77;,
  3;24,79,78;,
  3;24,80,79;,
  3;5,28,24;,
  3;28,81,80;,
  3;28,80,24;,
  3;28,82,81;,
  3;5,7,28;,
  3;7,30,28;,
  3;28,30,83;,
  3;28,83,82;,
  3;8,30,7;,
  3;30,84,83;,
  3;8,36,30;,
  3;30,85,84;,
  3;30,36,86;,
  3;30,86,85;,
  3;36,87,86;,
  3;36,88,87;,
  3;11,36,8;,
  3;36,89,88;,
  3;11,40,36;,
  3;40,90,89;,
  3;40,89,36;,
  3;40,91,90;,
  3;40,92,91;,
  3;11,2,42;,
  3;11,42,40;,
  3;42,69,92;,
  3;42,92,40;,
  3;110,97,93;,
  3;109,111,110;,
  3;111,97,110;,
  3;111,99,97;,
  3;111,101,99;,
  3;114,112,115;,
  3;112,101,115;,
  3;112,103,101;,
  3;116,113,117;,
  3;113,118,117;,
  3;113,105,118;,
  3;113,107,105;,
  3;119,120,119;,
  3;120,107,113;,
  3;120,121,107;,
  3;95,108,94;,
  3;95,94,96;,
  3;95,96,98;,
  3;95,98,100;,
  3;95,100,102;,
  3;95,102,104;,
  3;95,104,106;,
  3;95,106,108;,
  3;122,122,108;,
  3;93,97,96;,
  3;93,96,94;,
  3;99,96,97;,
  3;99,98,96;,
  3;101,98,99;,
  3;101,100,98;,
  3;103,123,100;,
  3;103,100,101;,
  3;118,124,125;,
  3;105,124,118;,
  3;105,107,124;,
  3;107,126,124;,
  3;107,121,127;,
  3;107,127,126;,
  3;144,130,142;,
  3;143,145,144;,
  3;145,130,144;,
  3;145,133,130;,
  3;149,146,150;,
  3;146,134,150;,
  3;150,134,133;,
  3;151,147,152;,
  3;147,137,152;,
  3;146,137,134;,
  3;147,138,137;,
  3;151,148,153;,
  3;148,138,147;,
  3;148,139,138;,
  3;148,142,139;,
  3;154,155,148;,
  3;155,142,148;,
  3;129,141,128;,
  3;129,128,131;,
  3;129,131,132;,
  3;129,132,135;,
  3;129,135,136;,
  3;129,136,140;,
  3;129,140,141;,
  3;142,156,157;,
  3;130,156,142;,
  3;130,131,128;,
  3;130,133,131;,
  3;133,132,131;,
  3;133,134,132;,
  3;134,135,132;,
  3;134,137,135;,
  3;137,136,135;,
  3;138,158,137;,
  3;138,159,158;,
  3;139,159,138;,
  3;142,157,159;,
  3;142,159,139;,
  3;172,175,173;,
  3;173,175,160;,
  3;181,160,162;,
  3;182,183,164;,
  3;184,182,174;,
  3;174,182,164;,
  3;185,186,167;,
  3;187,185,188;,
  3;188,185,167;,
  3;188,189,170;,
  3;175,190,160;,
  3;161,163,171;,
  3;161,165,163;,
  3;161,166,165;,
  3;161,168,166;,
  3;161,169,168;,
  3;161,171,169;,
  3;179,180,176;,
  3;179,176,177;,
  3;160,191,192;,
  3;192,162,160;,
  3;163,193,162;,
  3;193,164,162;,
  3;164,165,166;,
  3;166,194,186;,
  3;194,167,186;,
  3;195,196,167;,
  3;196,170,167;,
  3;170,196,197;,
  3;170,191,160;,
  3;178,178,178;,
  3;198,177,176;,
  3;199,199,199;,
  3;200,200,200;,
  3;213,204,201;,
  3;222,205,223;,
  3;224,208,225;,
  3;226,211,227;,
  3;213,201,228;,
  3;203,212,202;,
  3;203,202,206;,
  3;203,206,207;,
  3;203,207,209;,
  3;203,209,210;,
  3;203,210,212;,
  3;221,214,217;,
  3;229,230,218;,
  3;231,232,233;,
  3;219,215,220;,
  3;219,216,215;,
  3;201,204,234;,
  3;201,234,235;,
  3;205,202,223;,
  3;205,236,202;,
  3;225,207,237;,
  3;208,207,225;,
  3;208,209,207;,
  3;227,238,239;,
  3;211,238,227;,
  3;228,201,238;,
  3;201,240,238;,
  3;233,241,242;,
  3;214,215,216;,
  3;214,216,217;,
  3;243,244,230;,
  3;244,218,230;,
  3;245,245,232;,
  3;232,241,233;,
  3;258,256,247;,
  3;266,267,248;,
  3;268,269,251;,
  3;270,271,254;,
  3;258,272,256;,
  3;246,249,257;,
  3;246,250,249;,
  3;246,252,250;,
  3;246,253,252;,
  3;246,255,253;,
  3;246,257,255;,
  3;265,261,264;,
  3;273,262,274;,
  3;275,276,277;,
  3;263,259,260;,
  3;256,278,279;,
  3;256,279,247;,
  3;249,280,248;,
  3;249,248,267;,
  3;269,250,252;,
  3;252,251,269;,
  3;252,253,251;,
  3;281,282,271;,
  3;282,254,271;,
  3;272,283,284;,
  3;272,284,256;,
  3;276,285,286;,
  3;264,260,259;,
  3;264,261,260;,
  3;274,287,288;,
  3;262,287,274;,
  3;277,276,286;,
  3;302,299,290;,
  3;310,311,291;,
  3;301,310,303;,
  3;303,310,291;,
  3;312,313,295;,
  3;314,312,304;,
  3;304,312,295;,
  3;304,295,298;,
  3;315,316,317;,
  3;318,315,302;,
  3;302,315,299;,
  3;289,292,300;,
  3;289,293,292;,
  3;289,294,293;,
  3;289,296,294;,
  3;289,297,296;,
  3;289,300,297;,
  3;307,309,305;,
  3;307,305,306;,
  3;299,319,320;,
  3;299,320,290;,
  3;292,321,291;,
  3;292,291,311;,
  3;313,293,294;,
  3;294,295,313;,
  3;294,322,295;,
  3;323,324,295;,
  3;295,324,298;,
  3;316,325,326;,
  3;316,326,299;,
  3;308,308,308;,
  3;327,306,305;,
  3;328,328,328;,
  3;329,329,329;;
 }
 MeshTextureCoords {
  224;
  0.253290;1.233020;,
  0.000800;1.247400;,
  0.069600;1.244780;,
  0.029460;1.234790;,
  0.068930;1.233020;,
  -0.013610;1.234110;,
  0.133930;1.247450;,
  0.107060;1.234780;,
  0.145810;1.234060;,
  0.195190;1.244800;,
  0.193440;1.233020;,
  0.250980;1.247830;,
  0.239090;1.233910;,
  0.305480;1.244820;,
  0.273750;1.234480;,
  0.306560;1.233020;,
  0.365130;1.247460;,
  0.340410;1.234800;,
  0.378470;1.234010;,
  0.430590;1.244870;,
  0.431070;1.233020;,
  0.498340;1.247760;,
  0.470470;1.234660;,
  0.513570;1.234080;,
  0.568650;1.244830;,
  0.568900;1.233020;,
  0.635060;1.247700;,
  0.621490;1.234100;,
  0.694060;1.244860;,
  0.659590;1.234710;,
  0.693430;1.233020;,
  0.749920;1.247820;,
  0.726310;1.234750;,
  0.760970;1.233990;,
  -0.193080;1.244870;,
  0.806920;1.244870;,
  0.806570;1.233020;,
  -0.134120;1.247890;,
  0.840490;1.234750;,
  0.865880;1.247890;,
  0.878530;1.233880;,
  -0.070430;1.244810;,
  0.929570;1.244810;,
  0.931100;1.233020;,
  0.986390;1.234110;,
  1.000800;1.247400;,
  0.273000;0.071840;,
  0.150440;0.231620;,
  -0.072630;0.273260;,
  0.037890;1.083330;,
  0.258600;1.043000;,
  0.337410;0.250380;,
  0.464270;1.104350;,
  0.551670;0.265670;,
  0.576680;1.057550;,
  0.716810;0.285340;,
  0.697160;1.093580;,
  0.835470;1.096690;,
  0.927370;0.273260;,
  1.037890;1.083330;,
  0.111410;1.162960;,
  -0.007760;1.152690;,
  0.992240;1.152690;,
  1.029460;1.234790;,
  1.111410;1.162960;,
  1.068930;1.233020;,
  0.239620;1.175320;,
  0.358340;1.173560;,
  0.506090;1.157510;,
  0.623980;1.152480;,
  0.753550;1.164520;,
  0.875930;1.162320;,
  0.873760;0.106460;,
  0.863040;0.209410;,
  0.833240;0.203680;,
  0.897830;-0.014420;,
  0.900290;0.115740;,
  0.900300;0.214920;,
  0.938340;0.216900;,
  0.922540;0.111340;,
  0.967980;0.212380;,
  0.893510;0.102060;,
  0.911180;0.204320;,
  0.828490;0.201170;,
  0.387070;0.308250;,
  0.599000;0.295860;,
  0.705980;0.268620;,
  0.824120;0.282170;,
  -0.042490;0.299250;,
  0.076210;0.276870;,
  0.232200;0.298380;,
  0.377770;0.311660;,
  0.515130;0.311140;,
  0.957510;0.299250;,
  1.076210;0.276870;,
  1.232200;0.298380;,
  1.377770;0.311660;,
  0.628300;0.100360;,
  0.578720;0.202420;,
  0.593790;0.193790;,
  0.623990;0.013590;,
  0.626300;0.108820;,
  0.612010;0.212750;,
  0.651370;0.117120;,
  0.651440;0.218210;,
  0.673350;0.115650;,
  0.690130;0.216420;,
  0.717850;0.208420;,
  0.666900;0.105900;,
  0.709030;0.198890;,
  0.731190;0.345650;,
  0.244020;0.341130;,
  0.396700;0.308000;,
  0.496190;0.320870;,
  0.600920;0.337100;,
  0.698140;0.315830;,
  0.846900;0.336270;,
  1.019820;0.348880;,
  0.984370;0.159220;,
  0.997880;0.243380;,
  0.979620;0.246140;,
  0.982180;0.343550;,
  0.960700;0.314890;,
  0.971730;0.278020;,
  0.983300;0.220110;,
  1.010800;0.292170;,
  1.009790;0.332410;,
  0.544050;0.378880;,
  0.791650;0.406360;,
  0.509860;0.430030;,
  0.745530;0.348390;,
  0.818180;0.325580;,
  0.376190;0.334630;,
  0.383880;0.383740;,
  0.807370;0.341930;,
  0.791260;0.382420;,
  1.134170;0.362630;,
  0.995810;0.316180;,
  0.010800;0.292170;,
  -0.028270;0.278020;,
  0.009790;0.332410;,
  -0.490140;0.430030;,
  -0.017820;0.343550;,
  0.073040;0.272430;,
  0.134170;0.362630;,
  -0.208740;0.382420;,
  -0.004190;0.316180;,
  -0.192630;0.341930;,
  0.324220;0.225830;,
  0.351300;0.375780;,
  0.320150;0.385350;,
  0.360970;0.338880;,
  0.326260;0.319120;,
  0.299350;0.349610;,
  0.792370;0.429450;,
  0.791780;0.480950;,
  0.594520;0.450480;,
  0.640900;0.392800;,
  0.679890;0.373880;,
  0.904200;0.389060;,
  0.903410;0.440310;,
  0.203090;0.297600;,
  0.156300;0.345490;,
  0.162670;0.301010;,
  0.254760;0.329880;,
  0.591880;0.382880;,
  1.010810;0.415110;,
  0.644550;0.432820;,
  0.920720;0.366860;,
  -0.095800;0.389060;,
  -0.096590;0.440310;,
  0.010810;0.415110;,
  -0.079280;0.366860;,
  1.162670;0.301010;,
  0.669100;0.213370;,
  0.685420;0.396910;,
  0.656730;0.386930;,
  0.646500;0.354020;,
  0.677880;0.340190;,
  0.703750;0.370710;,
  0.013440;0.502000;,
  -0.435320;0.518070;,
  -0.118670;0.551810;,
  0.464400;0.466050;,
  -0.357630;0.441030;,
  -0.019000;0.458460;,
  -0.015870;0.511270;,
  0.796940;0.299310;,
  0.835270;0.334620;,
  0.833340;0.378210;,
  0.747650;0.351820;,
  0.575490;0.475780;,
  0.815760;0.475380;,
  0.798340;0.430210;,
  0.881330;0.551810;,
  0.564680;0.518070;,
  0.642370;0.441030;,
  0.981000;0.458460;,
  0.984130;0.511270;,
  0.451780;0.169330;,
  0.453110;0.337150;,
  0.426910;0.312260;,
  0.429810;0.269140;,
  0.459690;0.092390;,
  0.457530;0.140480;,
  0.472600;0.274540;,
  0.469670;0.169020;,
  0.478610;0.315530;,
  0.960970;0.384110;,
  1.240990;0.401970;,
  0.992160;0.440990;,
  1.187190;0.338460;,
  1.373110;0.321810;,
  0.792970;0.343640;,
  0.827320;0.401470;,
  0.275880;0.334840;,
  0.244370;0.380090;,
  0.618110;0.371400;,
  0.595420;0.316660;,
  -0.007840;0.440990;,
  0.240990;0.401970;,
  0.187190;0.338460;,
  0.373110;0.321810;,
  0.546170;0.283910;;
 }
}
