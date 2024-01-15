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
 302;
 0.00000;29.97479;-0.91153;,
 0.64211;29.97479;-0.64557;,
 0.64211;-60.54340;-0.64557;,
 0.00000;-60.54340;-0.91153;,
 0.90807;29.97479;-0.00346;,
 0.90807;-60.54340;-0.00346;,
 0.64211;29.97479;0.63865;,
 0.64211;-60.54340;0.63865;,
 0.00000;29.97479;0.90461;,
 0.00000;-60.54340;0.90461;,
 -0.64211;29.97479;0.63865;,
 -0.64211;-60.54340;0.63865;,
 -0.90807;29.97479;-0.00346;,
 -0.90807;-60.54340;-0.00346;,
 -0.64211;29.97479;-0.64557;,
 -0.64211;-60.54340;-0.64557;,
 0.00000;29.97479;-0.91153;,
 0.00000;-60.54340;-0.91153;,
 0.00000;49.73980;-0.00346;,
 0.00000;49.73980;-0.00346;,
 0.00000;49.73980;-0.00346;,
 0.00000;49.73980;-0.00346;,
 0.00000;49.73980;-0.00346;,
 0.00000;49.73980;-0.00346;,
 0.00000;49.73980;-0.00346;,
 0.00000;49.73980;-0.00346;,
 0.00000;-60.54340;-0.00346;,
 0.00000;-60.54340;-0.00346;,
 0.00000;-60.54340;-0.00346;,
 0.00000;-60.54340;-0.00346;,
 0.00000;-60.54340;-0.00346;,
 0.00000;-60.54340;-0.00346;,
 0.00000;-60.54340;-0.00346;,
 0.00000;-60.54340;-0.00346;,
 0.00000;-58.37316;-0.00346;,
 1.14902;-58.72860;-0.66686;,
 0.00000;-58.72860;-1.33023;,
 0.00000;-58.37316;-0.00346;,
 1.14902;-58.72860;0.65994;,
 0.00000;-58.37316;-0.00346;,
 0.00000;-58.72860;1.32331;,
 0.00000;-58.37316;-0.00346;,
 -1.14902;-58.72860;0.65994;,
 0.00000;-58.37316;-0.00346;,
 -1.14902;-58.72860;-0.66686;,
 0.00000;-58.37316;-0.00346;,
 0.00000;-58.72860;-1.33023;,
 1.99017;-59.69996;-1.15248;,
 0.00000;-59.69996;-2.30151;,
 1.99017;-59.69996;1.14556;,
 0.00000;-59.69996;2.29459;,
 -1.99017;-59.69996;1.14556;,
 -1.99017;-59.69996;-1.15248;,
 0.00000;-59.69996;-2.30151;,
 2.29805;-61.02667;-1.33023;,
 0.00000;-61.02667;-2.65700;,
 2.29805;-61.02667;1.32331;,
 0.00000;-61.02667;2.65008;,
 -2.29805;-61.02667;1.32331;,
 -2.29805;-61.02667;-1.33023;,
 0.00000;-61.02667;-2.65700;,
 1.99017;-62.35346;-1.15248;,
 0.00000;-62.35346;-2.30151;,
 1.99017;-62.35346;1.14556;,
 0.00000;-62.35346;2.29459;,
 -1.99017;-62.35346;1.14556;,
 -1.99017;-62.35346;-1.15248;,
 0.00000;-62.35346;-2.30151;,
 1.14902;-63.32468;-0.66686;,
 0.00000;-63.32468;-1.33023;,
 1.14902;-63.32468;0.65994;,
 0.00000;-63.32468;1.32331;,
 -1.14902;-63.32468;0.65994;,
 -1.14902;-63.32468;-0.66686;,
 0.00000;-63.32468;-1.33023;,
 0.00000;-63.68024;-0.00346;,
 0.00000;-63.68024;-0.00346;,
 0.00000;-63.68024;-0.00346;,
 0.00000;-63.68024;-0.00346;,
 0.00000;-63.68024;-0.00346;,
 0.00000;-63.68024;-0.00346;,
 0.00000;52.70076;-8.90862;,
 -1.17790;53.87215;-9.67951;,
 -1.17790;48.90335;-12.16803;,
 0.00000;48.57001;-11.10898;,
 -1.17790;56.21484;-11.22133;,
 -1.17790;49.56986;-14.28619;,
 0.00000;57.38627;-11.99222;,
 0.00000;49.90311;-15.34527;,
 1.17790;56.21484;-11.22133;,
 1.17790;49.56986;-14.28619;,
 1.17790;53.87215;-9.67951;,
 1.17790;48.90335;-12.16803;,
 0.00000;52.70076;-8.90862;,
 0.00000;48.57001;-11.10898;,
 -1.17790;43.69593;-10.55508;,
 0.00000;43.69593;-9.66039;,
 -1.17790;43.69593;-12.34448;,
 0.00000;43.69593;-13.23916;,
 1.17790;43.69593;-12.34448;,
 1.17790;43.69593;-10.55509;,
 0.00000;43.69593;-9.66039;,
 -1.17790;38.89164;-8.41146;,
 0.00000;39.89432;-7.67703;,
 -1.17790;36.88619;-9.88034;,
 0.00000;35.88344;-10.61478;,
 1.17790;36.88619;-9.88034;,
 1.17790;38.89164;-8.41146;,
 0.00000;39.89432;-7.67703;,
 -1.17790;33.37253;-5.13243;,
 0.00000;34.66311;-4.39070;,
 -1.17790;30.79129;-6.61592;,
 0.00000;23.69369;-7.35765;,
 1.17790;30.79129;-6.61592;,
 1.17790;33.37253;-5.13245;,
 0.00000;34.66311;-4.39070;,
 0.00000;59.77137;-5.92258;,
 0.00000;59.77137;-5.92258;,
 0.00000;59.77137;-5.92258;,
 0.00000;59.77137;-5.92258;,
 0.00000;59.77137;-5.92258;,
 0.00000;59.77137;-5.92258;,
 0.00000;32.69471;-0.56647;,
 0.00000;32.69471;-0.56647;,
 0.00000;32.69471;-0.56647;,
 0.00000;32.69471;-0.56647;,
 0.00000;32.69471;-0.56647;,
 0.00000;32.69471;-0.56647;,
 0.00000;52.83059;8.22422;,
 0.00000;48.32497;11.42754;,
 -1.17790;48.84572;12.40816;,
 -1.17790;54.00198;8.99512;,
 -1.17790;49.88709;14.36936;,
 -1.17790;56.34471;10.53694;,
 0.00000;50.40777;15.34995;,
 0.00000;57.51612;11.30784;,
 1.17790;49.88709;14.36936;,
 1.17790;56.34471;10.53694;,
 1.17790;48.84572;12.40816;,
 1.17790;54.00198;8.99512;,
 0.00000;48.32497;11.42754;,
 0.00000;52.83059;8.22422;,
 0.00000;43.82569;10.05501;,
 -1.17790;43.82569;10.94972;,
 -1.17790;43.82569;12.73915;,
 0.00000;43.82569;13.63383;,
 1.17790;43.82569;12.73915;,
 1.17790;43.82569;10.94972;,
 0.00000;43.82569;10.05501;,
 0.00000;40.02413;8.07168;,
 -1.17790;39.02151;8.80612;,
 -1.17790;37.01605;10.27501;,
 0.00000;36.01331;11.00944;,
 1.17790;37.01605;10.27501;,
 1.17790;39.02147;8.80612;,
 0.00000;40.02413;8.07168;,
 0.00000;34.79295;4.78533;,
 -1.17790;33.50230;5.52708;,
 -1.17790;30.92114;7.01055;,
 0.00000;23.82351;7.75230;,
 1.17790;30.92114;7.01055;,
 1.17790;33.50230;5.52708;,
 0.00000;34.79295;4.78533;,
 0.00000;60.25163;5.23821;,
 0.00000;60.25163;5.23821;,
 0.00000;60.25163;5.23821;,
 0.00000;60.25163;5.23821;,
 0.00000;60.25163;5.23821;,
 0.00000;60.25163;5.23821;,
 0.00000;32.82451;0.96112;,
 0.00000;32.82451;0.96112;,
 0.00000;32.82451;0.96112;,
 0.00000;32.82451;0.96112;,
 0.00000;32.82451;0.96112;,
 0.00000;32.82451;0.96112;,
 0.00000;50.58986;9.86695;,
 1.14902;50.23437;9.20356;,
 0.00000;50.23437;8.54018;,
 0.00000;50.58986;9.86695;,
 1.14902;50.23437;10.53035;,
 0.00000;50.58986;9.86695;,
 0.00000;50.23437;11.19374;,
 0.00000;50.58986;9.86695;,
 -1.14902;50.23437;10.53035;,
 0.00000;50.58986;9.86695;,
 -1.14902;50.23437;9.20356;,
 0.00000;50.58986;9.86695;,
 0.00000;50.23437;8.54018;,
 1.99017;49.26310;8.71793;,
 0.00000;49.26310;7.56891;,
 1.99017;49.26310;11.01597;,
 0.00000;49.26310;12.16500;,
 -1.99017;49.26310;11.01597;,
 -1.99017;49.26310;8.71793;,
 0.00000;49.26310;7.56891;,
 2.29805;47.93632;8.54018;,
 0.00000;47.93632;7.21341;,
 2.29805;47.93632;11.19374;,
 0.00000;47.93632;12.52050;,
 -2.29805;47.93632;11.19374;,
 -2.29805;47.93632;8.54018;,
 0.00000;47.93632;7.21341;,
 1.99017;46.60958;8.71793;,
 0.00000;46.60958;7.56891;,
 1.99017;46.60958;11.01597;,
 0.00000;46.60958;12.16500;,
 -1.99017;46.60958;11.01597;,
 -1.99017;46.60958;8.71793;,
 0.00000;46.60958;7.56891;,
 1.14902;45.63826;9.20356;,
 0.00000;45.63826;8.54018;,
 1.14902;45.63826;10.53035;,
 0.00000;45.63826;11.19374;,
 -1.14902;45.63826;10.53035;,
 -1.14902;45.63826;9.20356;,
 0.00000;45.63826;8.54018;,
 0.00000;45.28275;9.86695;,
 0.00000;45.28275;9.86695;,
 0.00000;45.28275;9.86695;,
 0.00000;45.28275;9.86695;,
 0.00000;45.28275;9.86695;,
 0.00000;45.28275;9.86695;,
 0.00000;82.43204;-2.47804;,
 0.51725;82.43204;-1.24075;,
 0.51725;65.71732;-2.08192;,
 0.00000;65.71732;-4.16038;,
 0.51725;82.43204;1.23383;,
 0.51725;65.71732;2.07500;,
 0.00000;82.43204;2.47112;,
 0.00000;65.71732;4.15346;,
 -0.51725;82.43204;1.23383;,
 -0.51725;65.71732;2.07500;,
 -0.51725;82.43204;-1.24075;,
 -0.51725;65.71732;-2.08192;,
 0.00000;82.43204;-2.47804;,
 0.00000;65.71732;-4.16038;,
 0.51725;48.12463;-3.37518;,
 0.00000;48.12463;-6.74690;,
 0.51725;48.12463;3.36826;,
 0.00000;48.12463;6.73997;,
 -0.51725;48.12463;3.36826;,
 -0.51725;48.12463;-3.37518;,
 0.00000;48.12463;-6.74690;,
 0.00000;108.15432;-0.00346;,
 0.00000;108.15432;-0.00346;,
 0.00000;108.15432;-0.00346;,
 0.00000;108.15432;-0.00346;,
 0.00000;108.15432;-0.00346;,
 0.00000;108.15432;-0.00346;,
 0.00000;42.67620;-0.00346;,
 0.00000;42.67620;-0.00346;,
 0.00000;42.67620;-0.00346;,
 0.00000;42.67620;-0.00346;,
 0.00000;42.67620;-0.00346;,
 0.00000;42.67620;-0.00346;,
 0.00000;50.58986;-10.07400;,
 1.14902;50.23437;-10.73740;,
 0.00000;50.23437;-11.40080;,
 0.00000;50.58986;-10.07400;,
 1.14902;50.23437;-9.41063;,
 0.00000;50.58986;-10.07400;,
 0.00000;50.23437;-8.74724;,
 0.00000;50.58986;-10.07400;,
 -1.14902;50.23437;-9.41063;,
 0.00000;50.58986;-10.07400;,
 -1.14902;50.23437;-10.73740;,
 0.00000;50.58986;-10.07400;,
 0.00000;50.23437;-11.40080;,
 1.99017;49.26310;-11.22303;,
 0.00000;49.26310;-12.37207;,
 1.99017;49.26310;-8.92500;,
 0.00000;49.26310;-7.77598;,
 -1.99017;49.26310;-8.92500;,
 -1.99017;49.26310;-11.22303;,
 0.00000;49.26310;-12.37207;,
 2.29805;47.93632;-11.40080;,
 0.00000;47.93632;-12.72757;,
 2.29805;47.93632;-8.74724;,
 0.00000;47.93632;-7.42046;,
 -2.29805;47.93632;-8.74724;,
 -2.29805;47.93632;-11.40080;,
 0.00000;47.93632;-12.72757;,
 1.99017;46.60958;-11.22303;,
 0.00000;46.60958;-12.37207;,
 1.99017;46.60958;-8.92500;,
 0.00000;46.60958;-7.77598;,
 -1.99017;46.60958;-8.92500;,
 -1.99017;46.60958;-11.22303;,
 0.00000;46.60958;-12.37207;,
 1.14902;45.63826;-10.73740;,
 0.00000;45.63826;-11.40080;,
 1.14902;45.63826;-9.41063;,
 0.00000;45.63826;-8.74724;,
 -1.14902;45.63826;-9.41063;,
 -1.14902;45.63826;-10.73740;,
 0.00000;45.63826;-11.40080;,
 0.00000;45.28275;-10.07400;,
 0.00000;45.28275;-10.07400;,
 0.00000;45.28275;-10.07400;,
 0.00000;45.28275;-10.07400;,
 0.00000;45.28275;-10.07400;,
 0.00000;45.28275;-10.07400;;
 
 228;
 4;0,1,2,3;,
 4;1,4,5,2;,
 4;4,6,7,5;,
 4;6,8,9,7;,
 4;8,10,11,9;,
 4;10,12,13,11;,
 4;12,14,15,13;,
 4;14,16,17,15;,
 3;18,1,0;,
 3;19,4,1;,
 3;20,6,4;,
 3;21,8,6;,
 3;22,10,8;,
 3;23,12,10;,
 3;24,14,12;,
 3;25,16,14;,
 3;26,3,2;,
 3;27,2,5;,
 3;28,5,7;,
 3;29,7,9;,
 3;30,9,11;,
 3;31,11,13;,
 3;32,13,15;,
 3;33,15,17;,
 3;34,35,36;,
 3;37,38,35;,
 3;39,40,38;,
 3;41,42,40;,
 3;43,44,42;,
 3;45,46,44;,
 4;36,35,47,48;,
 4;35,38,49,47;,
 4;38,40,50,49;,
 4;40,42,51,50;,
 4;42,44,52,51;,
 4;44,46,53,52;,
 4;48,47,54,55;,
 4;47,49,56,54;,
 4;49,50,57,56;,
 4;50,51,58,57;,
 4;51,52,59,58;,
 4;52,53,60,59;,
 4;55,54,61,62;,
 4;54,56,63,61;,
 4;56,57,64,63;,
 4;57,58,65,64;,
 4;58,59,66,65;,
 4;59,60,67,66;,
 4;62,61,68,69;,
 4;61,63,70,68;,
 4;63,64,71,70;,
 4;64,65,72,71;,
 4;65,66,73,72;,
 4;66,67,74,73;,
 3;69,68,75;,
 3;68,70,76;,
 3;70,71,77;,
 3;71,72,78;,
 3;72,73,79;,
 3;73,74,80;,
 4;81,82,83,84;,
 4;82,85,86,83;,
 4;85,87,88,86;,
 4;87,89,90,88;,
 4;89,91,92,90;,
 4;91,93,94,92;,
 4;84,83,95,96;,
 4;83,86,97,95;,
 4;86,88,98,97;,
 4;88,90,99,98;,
 4;90,92,100,99;,
 4;92,94,101,100;,
 4;96,95,102,103;,
 4;95,97,104,102;,
 4;97,98,105,104;,
 4;98,99,106,105;,
 4;99,100,107,106;,
 4;100,101,108,107;,
 4;103,102,109,110;,
 4;102,104,111,109;,
 4;104,105,112,111;,
 4;105,106,113,112;,
 4;106,107,114,113;,
 4;107,108,115,114;,
 3;116,82,81;,
 3;117,85,82;,
 3;118,87,85;,
 3;119,89,87;,
 3;120,91,89;,
 3;121,93,91;,
 3;122,110,109;,
 3;123,109,111;,
 3;124,111,112;,
 3;125,112,113;,
 3;126,113,114;,
 3;127,114,115;,
 4;128,129,130,131;,
 4;131,130,132,133;,
 4;133,132,134,135;,
 4;135,134,136,137;,
 4;137,136,138,139;,
 4;139,138,140,141;,
 4;129,142,143,130;,
 4;130,143,144,132;,
 4;132,144,145,134;,
 4;134,145,146,136;,
 4;136,146,147,138;,
 4;138,147,148,140;,
 4;142,149,150,143;,
 4;143,150,151,144;,
 4;144,151,152,145;,
 4;145,152,153,146;,
 4;146,153,154,147;,
 4;147,154,155,148;,
 4;149,156,157,150;,
 4;150,157,158,151;,
 4;151,158,159,152;,
 4;152,159,160,153;,
 4;153,160,161,154;,
 4;154,161,162,155;,
 3;163,128,131;,
 3;164,131,133;,
 3;165,133,135;,
 3;166,135,137;,
 3;167,137,139;,
 3;168,139,141;,
 3;169,157,156;,
 3;170,158,157;,
 3;171,159,158;,
 3;172,160,159;,
 3;173,161,160;,
 3;174,162,161;,
 3;175,176,177;,
 3;178,179,176;,
 3;180,181,179;,
 3;182,183,181;,
 3;184,185,183;,
 3;186,187,185;,
 4;177,176,188,189;,
 4;176,179,190,188;,
 4;179,181,191,190;,
 4;181,183,192,191;,
 4;183,185,193,192;,
 4;185,187,194,193;,
 4;189,188,195,196;,
 4;188,190,197,195;,
 4;190,191,198,197;,
 4;191,192,199,198;,
 4;192,193,200,199;,
 4;193,194,201,200;,
 4;196,195,202,203;,
 4;195,197,204,202;,
 4;197,198,205,204;,
 4;198,199,206,205;,
 4;199,200,207,206;,
 4;200,201,208,207;,
 4;203,202,209,210;,
 4;202,204,211,209;,
 4;204,205,212,211;,
 4;205,206,213,212;,
 4;206,207,214,213;,
 4;207,208,215,214;,
 3;210,209,216;,
 3;209,211,217;,
 3;211,212,218;,
 3;212,213,219;,
 3;213,214,220;,
 3;214,215,221;,
 4;222,223,224,225;,
 4;223,226,227,224;,
 4;226,228,229,227;,
 4;228,230,231,229;,
 4;230,232,233,231;,
 4;232,234,235,233;,
 4;225,224,236,237;,
 4;224,227,238,236;,
 4;227,229,239,238;,
 4;229,231,240,239;,
 4;231,233,241,240;,
 4;233,235,242,241;,
 3;243,223,222;,
 3;244,226,223;,
 3;245,228,226;,
 3;246,230,228;,
 3;247,232,230;,
 3;248,234,232;,
 3;249,237,236;,
 3;250,236,238;,
 3;251,238,239;,
 3;252,239,240;,
 3;253,240,241;,
 3;254,241,242;,
 3;255,256,257;,
 3;258,259,256;,
 3;260,261,259;,
 3;262,263,261;,
 3;264,265,263;,
 3;266,267,265;,
 4;257,256,268,269;,
 4;256,259,270,268;,
 4;259,261,271,270;,
 4;261,263,272,271;,
 4;263,265,273,272;,
 4;265,267,274,273;,
 4;269,268,275,276;,
 4;268,270,277,275;,
 4;270,271,278,277;,
 4;271,272,279,278;,
 4;272,273,280,279;,
 4;273,274,281,280;,
 4;276,275,282,283;,
 4;275,277,284,282;,
 4;277,278,285,284;,
 4;278,279,286,285;,
 4;279,280,287,286;,
 4;280,281,288,287;,
 4;283,282,289,290;,
 4;282,284,291,289;,
 4;284,285,292,291;,
 4;285,286,293,292;,
 4;286,287,294,293;,
 4;287,288,295,294;,
 3;290,289,296;,
 3;289,291,297;,
 3;291,292,298;,
 3;292,293,299;,
 3;293,294,300;,
 3;294,295,301;;
 
 MeshMaterialList {
  3;
  228;
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
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
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
   0.000000;0.800000;0.790400;1.000000;;
   5.000000;
   0.770000;0.770000;0.770000;;
   0.000000;0.030000;0.029640;;
  }
  Material {
   0.536800;0.536800;0.536800;1.000000;;
   5.000000;
   0.530000;0.530000;0.530000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.800000;0.432800;0.000000;1.000000;;
   5.000000;
   0.850000;0.850000;0.850000;;
   0.000000;0.000000;0.000000;;
  }
 }
 MeshNormals {
  233;
  0.706362;0.045895;-0.706362;,
  0.000000;0.022955;-0.999736;,
  0.706920;0.022955;-0.706920;,
  0.999737;0.022955;0.000000;,
  0.706921;0.022955;0.706920;,
  0.000000;0.022955;0.999736;,
  -0.706921;0.022955;0.706920;,
  -0.999737;0.022955;0.000000;,
  -0.706920;0.022955;-0.706921;,
  0.000000;0.000000;-1.000000;,
  0.707107;0.000000;-0.707107;,
  1.000000;0.000000;0.000000;,
  0.707107;0.000000;0.707106;,
  0.000000;0.000000;1.000000;,
  -0.707107;0.000000;0.707106;,
  -1.000000;0.000000;0.000000;,
  -0.707107;0.000000;-0.707107;,
  0.000000;-1.000000;-0.000000;,
  0.706362;0.045895;0.706361;,
  -0.706362;0.045895;0.706361;,
  -0.706362;0.045895;-0.706362;,
  0.000000;1.000000;-0.000000;,
  0.000000;0.870414;-0.492321;,
  0.426359;0.870416;-0.246161;,
  0.426358;0.870416;0.246160;,
  0.000000;0.870415;0.492319;,
  -0.426358;0.870416;0.246160;,
  -0.426359;0.870416;-0.246161;,
  0.000000;0.506728;-0.862106;,
  0.746603;0.506731;-0.431054;,
  0.746603;0.506732;0.431053;,
  0.000000;0.506730;0.862105;,
  -0.746603;0.506732;0.431053;,
  -0.746603;0.506731;-0.431054;,
  0.000000;0.000008;-1.000000;,
  0.866025;0.000008;-0.500001;,
  0.866025;0.000008;0.500001;,
  0.000000;0.000008;1.000000;,
  -0.866025;0.000008;0.500001;,
  -0.866025;0.000008;-0.500001;,
  0.000000;-0.506756;-0.862089;,
  0.746589;-0.506759;-0.431045;,
  0.746589;-0.506759;0.431045;,
  0.000000;-0.506756;0.862089;,
  -0.746589;-0.506759;0.431045;,
  -0.746589;-0.506759;-0.431045;,
  0.000000;-0.870408;-0.492332;,
  0.426369;-0.870409;-0.246166;,
  0.426369;-0.870409;0.246166;,
  0.000000;-0.870408;0.492331;,
  -0.426369;-0.870409;0.246166;,
  -0.426369;-0.870409;-0.246166;,
  0.000000;-1.000000;-0.000000;,
  -0.960116;0.168614;0.223042;,
  -0.701474;-0.302612;0.645259;,
  -0.911519;-0.136009;0.388118;,
  -0.940081;0.274343;-0.202444;,
  -0.753384;0.467955;-0.461985;,
  0.940081;0.274343;-0.202444;,
  0.911519;-0.136009;0.388117;,
  -0.679393;-0.050382;0.732043;,
  -0.920199;-0.026877;0.390526;,
  -0.918542;0.011758;-0.395148;,
  -0.673643;0.021981;-0.738730;,
  0.918542;0.011758;-0.395148;,
  0.920200;-0.026878;0.390525;,
  -0.611055;0.288183;0.737267;,
  -0.897730;0.160384;0.410315;,
  -0.896267;-0.143521;-0.419651;,
  -0.606545;-0.257277;-0.752271;,
  0.896267;-0.143521;-0.419651;,
  0.897731;0.160383;0.410313;,
  -0.671769;0.353486;0.650979;,
  -0.914536;0.193027;0.355478;,
  -0.929178;-0.132382;-0.345113;,
  -0.723830;-0.247112;-0.644209;,
  0.929178;-0.132382;-0.345113;,
  0.914536;0.193026;0.355477;,
  -0.765203;0.464824;0.445425;,
  -0.931572;0.210041;0.296742;,
  -0.989379;-0.144485;-0.015924;,
  -0.961595;-0.224840;-0.157421;,
  0.989379;-0.144484;-0.015924;,
  0.931573;0.210040;0.296741;,
  -0.959512;0.084154;0.268803;,
  0.753384;0.467955;-0.461985;,
  0.673643;0.021981;-0.738730;,
  0.701474;-0.302612;0.645259;,
  0.679394;-0.050382;0.732042;,
  0.606545;-0.257277;-0.752271;,
  0.611057;0.288182;0.737265;,
  0.723830;-0.247112;-0.644209;,
  0.671771;0.353485;0.650978;,
  0.961595;-0.224840;-0.157421;,
  0.765205;0.464822;0.445423;,
  0.960116;0.168613;0.223042;,
  0.959512;0.084154;0.268802;,
  -0.962630;0.165670;-0.214234;,
  -0.707419;-0.333496;-0.623168;,
  -0.914548;-0.153015;-0.374418;,
  -0.938222;0.283457;0.198474;,
  -0.751136;0.483979;0.448954;,
  0.938222;0.283457;0.198474;,
  0.914548;-0.153015;-0.374418;,
  -0.683093;-0.087438;-0.725078;,
  -0.922553;-0.046198;-0.383096;,
  -0.919437;0.041153;0.391077;,
  -0.675372;0.077178;0.733428;,
  0.919437;0.041153;0.391077;,
  0.922553;-0.046198;-0.383096;,
  -0.598006;0.289090;-0.747539;,
  -0.894153;0.161503;-0.417620;,
  -0.894442;-0.130779;0.427633;,
  -0.599755;-0.234014;0.765200;,
  0.894442;-0.130779;0.427633;,
  0.894154;0.161502;-0.417620;,
  -0.671773;0.353485;-0.650976;,
  -0.914537;0.193026;-0.355476;,
  -0.929178;-0.132383;0.345112;,
  -0.723831;-0.247114;0.644208;,
  0.929178;-0.132383;0.345112;,
  0.914538;0.193026;-0.355475;,
  -0.765212;0.464812;-0.445421;,
  -0.931575;0.210033;-0.296740;,
  -0.989379;-0.144486;0.015924;,
  -0.961595;-0.224841;0.157420;,
  0.989379;-0.144486;0.015924;,
  0.931575;0.210033;-0.296739;,
  -0.959513;0.084146;-0.268801;,
  0.751136;0.483979;0.448954;,
  0.675372;0.077178;0.733428;,
  0.683093;-0.087438;-0.725078;,
  0.707419;-0.333496;-0.623168;,
  0.599755;-0.234014;0.765200;,
  0.598008;0.289089;-0.747539;,
  0.723831;-0.247114;0.644208;,
  0.671775;0.353484;-0.650974;,
  0.961595;-0.224841;0.157420;,
  0.765214;0.464811;-0.445420;,
  0.962630;0.165670;-0.214234;,
  0.959513;0.084146;-0.268801;,
  -0.000000;1.000000;-0.000001;,
  0.000000;0.870417;-0.492316;,
  0.426356;0.870417;-0.246158;,
  0.426358;0.870416;0.246159;,
  0.000000;0.870416;0.492318;,
  -0.426358;0.870416;0.246159;,
  -0.426357;0.870417;-0.246158;,
  0.000000;0.506747;-0.862095;,
  0.746594;0.506749;-0.431048;,
  0.746595;0.506748;0.431048;,
  0.000000;0.506746;0.862096;,
  -0.746595;0.506748;0.431048;,
  -0.746594;0.506749;-0.431048;,
  0.000000;-0.000005;-1.000000;,
  0.866024;-0.000005;-0.500002;,
  0.866025;-0.000006;0.500001;,
  0.000000;-0.000006;1.000000;,
  -0.866025;-0.000006;0.500001;,
  -0.866024;-0.000005;-0.500002;,
  0.000000;-0.506738;-0.862100;,
  0.746599;-0.506740;-0.431051;,
  0.746599;-0.506740;0.431050;,
  0.000000;-0.506738;0.862100;,
  -0.746599;-0.506740;0.431050;,
  -0.746599;-0.506740;-0.431051;,
  0.000000;-0.870407;-0.492333;,
  0.426372;-0.870407;-0.246167;,
  0.426373;-0.870407;0.246167;,
  0.000000;-0.870406;0.492334;,
  -0.426373;-0.870407;0.246167;,
  -0.426372;-0.870407;-0.246167;,
  -0.000000;-1.000000;-0.000001;,
  0.999451;0.033130;-0.000000;,
  0.936209;0.029521;-0.350203;,
  0.983845;0.020106;-0.177889;,
  0.983845;0.020106;0.177888;,
  0.936209;0.029521;0.350202;,
  -0.983845;0.020106;0.177888;,
  -0.983845;0.020106;-0.177889;,
  0.966432;0.021017;-0.256063;,
  0.991588;0.010588;-0.129000;,
  0.991588;0.010588;0.129000;,
  0.966432;0.021017;0.256063;,
  -0.991588;0.010588;0.129000;,
  -0.991588;0.010588;-0.129000;,
  0.981297;-0.082666;-0.173848;,
  0.994065;-0.065208;-0.087078;,
  0.994065;-0.065208;0.087078;,
  0.981297;-0.082666;0.173848;,
  -0.994065;-0.065208;0.087078;,
  -0.994065;-0.065208;-0.087078;,
  0.987791;-0.155784;0.000000;,
  -0.936209;0.029521;0.350202;,
  -0.966432;0.021017;0.256063;,
  -0.936209;0.029521;-0.350203;,
  -0.966432;0.021017;-0.256063;,
  -0.981297;-0.082666;0.173848;,
  -0.981297;-0.082666;-0.173848;,
  -0.999451;0.033130;-0.000000;,
  -0.987791;-0.155784;0.000000;,
  -0.000000;1.000000;0.000003;,
  0.000000;0.870418;-0.492314;,
  0.426359;0.870417;-0.246157;,
  0.426359;0.870416;0.246160;,
  0.000000;0.870414;0.492320;,
  -0.426359;0.870416;0.246160;,
  -0.426359;0.870417;-0.246157;,
  0.000000;0.506751;-0.862092;,
  0.746595;0.506750;-0.431045;,
  0.746594;0.506750;0.431047;,
  0.000000;0.506751;0.862093;,
  -0.746594;0.506750;0.431047;,
  -0.746595;0.506750;-0.431045;,
  0.000000;-0.000005;-1.000000;,
  0.866026;-0.000005;-0.499999;,
  0.866026;-0.000005;0.499999;,
  0.000000;-0.000005;1.000000;,
  -0.866026;-0.000005;0.499999;,
  -0.866026;-0.000005;-0.499999;,
  0.000000;-0.506742;-0.862098;,
  0.746600;-0.506741;-0.431048;,
  0.746599;-0.506742;0.431049;,
  0.000000;-0.506742;0.862098;,
  -0.746599;-0.506742;0.431049;,
  -0.746600;-0.506741;-0.431048;,
  0.000000;-0.870408;-0.492331;,
  0.426374;-0.870407;-0.246165;,
  0.426374;-0.870406;0.246169;,
  0.000000;-0.870405;0.492337;,
  -0.426374;-0.870406;0.246169;,
  -0.426374;-0.870407;-0.246165;,
  0.000000;-1.000000;0.000003;;
  228;
  4;1,2,10,9;,
  4;2,3,11,10;,
  4;3,4,12,11;,
  4;4,5,13,12;,
  4;5,6,14,13;,
  4;6,7,15,14;,
  4;7,8,16,15;,
  4;8,1,9,16;,
  3;0,2,1;,
  3;0,3,2;,
  3;18,4,3;,
  3;18,5,4;,
  3;19,6,5;,
  3;19,7,6;,
  3;20,8,7;,
  3;20,1,8;,
  3;17,17,17;,
  3;17,17,17;,
  3;17,17,17;,
  3;17,17,17;,
  3;17,17,17;,
  3;17,17,17;,
  3;17,17,17;,
  3;17,17,17;,
  3;21,23,22;,
  3;21,24,23;,
  3;21,25,24;,
  3;21,26,25;,
  3;21,27,26;,
  3;21,22,27;,
  4;22,23,29,28;,
  4;23,24,30,29;,
  4;24,25,31,30;,
  4;25,26,32,31;,
  4;26,27,33,32;,
  4;27,22,28,33;,
  4;28,29,35,34;,
  4;29,30,36,35;,
  4;30,31,37,36;,
  4;31,32,38,37;,
  4;32,33,39,38;,
  4;33,28,34,39;,
  4;34,35,41,40;,
  4;35,36,42,41;,
  4;36,37,43,42;,
  4;37,38,44,43;,
  4;38,39,45,44;,
  4;39,34,40,45;,
  4;40,41,47,46;,
  4;41,42,48,47;,
  4;42,43,49,48;,
  4;43,44,50,49;,
  4;44,45,51,50;,
  4;45,40,46,51;,
  3;46,47,52;,
  3;47,48,52;,
  3;48,49,52;,
  3;49,50,52;,
  3;50,51,52;,
  3;51,46,52;,
  4;54,55,61,60;,
  4;55,56,62,61;,
  4;56,57,63,62;,
  4;85,58,64,86;,
  4;58,59,65,64;,
  4;59,87,88,65;,
  4;60,61,67,66;,
  4;61,62,68,67;,
  4;62,63,69,68;,
  4;86,64,70,89;,
  4;64,65,71,70;,
  4;65,88,90,71;,
  4;66,67,73,72;,
  4;67,68,74,73;,
  4;68,69,75,74;,
  4;89,70,76,91;,
  4;70,71,77,76;,
  4;71,90,92,77;,
  4;72,73,79,78;,
  4;73,74,80,79;,
  4;74,75,81,80;,
  4;91,76,82,93;,
  4;76,77,83,82;,
  4;77,92,94,83;,
  3;53,55,54;,
  3;53,56,55;,
  3;53,57,56;,
  3;95,58,85;,
  3;95,59,58;,
  3;95,87,59;,
  3;84,78,79;,
  3;84,79,80;,
  3;84,80,81;,
  3;96,93,82;,
  3;96,82,83;,
  3;96,83,94;,
  4;98,104,105,99;,
  4;99,105,106,100;,
  4;100,106,107,101;,
  4;129,130,108,102;,
  4;102,108,109,103;,
  4;103,109,131,132;,
  4;104,110,111,105;,
  4;105,111,112,106;,
  4;106,112,113,107;,
  4;130,133,114,108;,
  4;108,114,115,109;,
  4;109,115,134,131;,
  4;110,116,117,111;,
  4;111,117,118,112;,
  4;112,118,119,113;,
  4;133,135,120,114;,
  4;114,120,121,115;,
  4;115,121,136,134;,
  4;116,122,123,117;,
  4;117,123,124,118;,
  4;118,124,125,119;,
  4;135,137,126,120;,
  4;120,126,127,121;,
  4;121,127,138,136;,
  3;97,98,99;,
  3;97,99,100;,
  3;97,100,101;,
  3;139,129,102;,
  3;139,102,103;,
  3;139,103,132;,
  3;128,123,122;,
  3;128,124,123;,
  3;128,125,124;,
  3;140,126,137;,
  3;140,127,126;,
  3;140,138,127;,
  3;141,143,142;,
  3;141,144,143;,
  3;141,145,144;,
  3;141,146,145;,
  3;141,147,146;,
  3;141,142,147;,
  4;142,143,149,148;,
  4;143,144,150,149;,
  4;144,145,151,150;,
  4;145,146,152,151;,
  4;146,147,153,152;,
  4;147,142,148,153;,
  4;148,149,155,154;,
  4;149,150,156,155;,
  4;150,151,157,156;,
  4;151,152,158,157;,
  4;152,153,159,158;,
  4;153,148,154,159;,
  4;154,155,161,160;,
  4;155,156,162,161;,
  4;156,157,163,162;,
  4;157,158,164,163;,
  4;158,159,165,164;,
  4;159,154,160,165;,
  4;160,161,167,166;,
  4;161,162,168,167;,
  4;162,163,169,168;,
  4;163,164,170,169;,
  4;164,165,171,170;,
  4;165,160,166,171;,
  3;166,167,172;,
  3;167,168,172;,
  3;168,169,172;,
  3;169,170,172;,
  3;170,171,172;,
  3;171,166,172;,
  4;174,175,181,180;,
  4;175,176,182,181;,
  4;176,177,183,182;,
  4;193,178,184,194;,
  4;178,179,185,184;,
  4;179,195,196,185;,
  4;180,181,187,186;,
  4;181,182,188,187;,
  4;182,183,189,188;,
  4;194,184,190,197;,
  4;184,185,191,190;,
  4;185,196,198,191;,
  3;173,175,174;,
  3;173,176,175;,
  3;173,177,176;,
  3;199,178,193;,
  3;199,179,178;,
  3;199,195,179;,
  3;192,186,187;,
  3;192,187,188;,
  3;192,188,189;,
  3;200,197,190;,
  3;200,190,191;,
  3;200,191,198;,
  3;201,203,202;,
  3;201,204,203;,
  3;201,205,204;,
  3;201,206,205;,
  3;201,207,206;,
  3;201,202,207;,
  4;202,203,209,208;,
  4;203,204,210,209;,
  4;204,205,211,210;,
  4;205,206,212,211;,
  4;206,207,213,212;,
  4;207,202,208,213;,
  4;208,209,215,214;,
  4;209,210,216,215;,
  4;210,211,217,216;,
  4;211,212,218,217;,
  4;212,213,219,218;,
  4;213,208,214,219;,
  4;214,215,221,220;,
  4;215,216,222,221;,
  4;216,217,223,222;,
  4;217,218,224,223;,
  4;218,219,225,224;,
  4;219,214,220,225;,
  4;220,221,227,226;,
  4;221,222,228,227;,
  4;222,223,229,228;,
  4;223,224,230,229;,
  4;224,225,231,230;,
  4;225,220,226,231;,
  3;226,227,232;,
  3;227,228,232;,
  3;228,229,232;,
  3;229,230,232;,
  3;230,231,232;,
  3;231,226,232;;
 }
 MeshTextureCoords {
  302;
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
  0.937500;1.000000;,
  0.083330;0.000000;,
  0.166670;0.166670;,
  0.000000;0.166670;,
  0.250000;0.000000;,
  0.333330;0.166670;,
  0.416670;0.000000;,
  0.500000;0.166670;,
  0.583330;0.000000;,
  0.666670;0.166670;,
  0.750000;0.000000;,
  0.833330;0.166670;,
  0.916670;0.000000;,
  1.000000;0.166670;,
  0.166670;0.333330;,
  0.000000;0.333330;,
  0.333330;0.333330;,
  0.500000;0.333330;,
  0.666670;0.333330;,
  0.833330;0.333330;,
  1.000000;0.333330;,
  0.166670;0.500000;,
  0.000000;0.500000;,
  0.333330;0.500000;,
  0.500000;0.500000;,
  0.666670;0.500000;,
  0.833330;0.500000;,
  1.000000;0.500000;,
  0.166670;0.666670;,
  0.000000;0.666670;,
  0.333330;0.666670;,
  0.500000;0.666670;,
  0.666670;0.666670;,
  0.833330;0.666670;,
  1.000000;0.666670;,
  0.166670;0.833330;,
  0.000000;0.833330;,
  0.333330;0.833330;,
  0.500000;0.833330;,
  0.666670;0.833330;,
  0.833330;0.833330;,
  1.000000;0.833330;,
  0.083330;1.000000;,
  0.250000;1.000000;,
  0.416670;1.000000;,
  0.583330;1.000000;,
  0.750000;1.000000;,
  0.916670;1.000000;,
  0.000000;0.000000;,
  0.166670;0.000000;,
  0.166670;0.250000;,
  0.000000;0.250000;,
  0.333330;0.000000;,
  0.333330;0.250000;,
  0.500000;0.000000;,
  0.500000;0.250000;,
  0.666670;0.000000;,
  0.666670;0.250000;,
  0.833330;0.000000;,
  0.833330;0.250000;,
  1.000000;0.000000;,
  1.000000;0.250000;,
  0.166670;0.500000;,
  0.000000;0.500000;,
  0.333330;0.500000;,
  0.500000;0.500000;,
  0.666670;0.500000;,
  0.833330;0.500000;,
  1.000000;0.500000;,
  0.166670;0.750000;,
  0.000000;0.750000;,
  0.333330;0.750000;,
  0.500000;0.750000;,
  0.666670;0.750000;,
  0.833330;0.750000;,
  1.000000;0.750000;,
  0.166670;1.000000;,
  0.000000;1.000000;,
  0.333330;1.000000;,
  0.500000;1.000000;,
  0.666670;1.000000;,
  0.833330;1.000000;,
  1.000000;1.000000;,
  0.083330;0.000000;,
  0.250000;0.000000;,
  0.416670;0.000000;,
  0.583330;0.000000;,
  0.750000;0.000000;,
  0.916670;0.000000;,
  0.083330;1.000000;,
  0.250000;1.000000;,
  0.416670;1.000000;,
  0.583330;1.000000;,
  0.750000;1.000000;,
  0.916670;1.000000;,
  0.000000;0.000000;,
  0.000000;0.250000;,
  0.166670;0.250000;,
  0.166670;0.000000;,
  0.333330;0.250000;,
  0.333330;0.000000;,
  0.500000;0.250000;,
  0.500000;0.000000;,
  0.666670;0.250000;,
  0.666670;0.000000;,
  0.833330;0.250000;,
  0.833330;0.000000;,
  1.000000;0.250000;,
  1.000000;0.000000;,
  0.000000;0.500000;,
  0.166670;0.500000;,
  0.333330;0.500000;,
  0.500000;0.500000;,
  0.666670;0.500000;,
  0.833330;0.500000;,
  1.000000;0.500000;,
  0.000000;0.750000;,
  0.166670;0.750000;,
  0.333330;0.750000;,
  0.500000;0.750000;,
  0.666670;0.750000;,
  0.833330;0.750000;,
  1.000000;0.750000;,
  0.000000;1.000000;,
  0.166670;1.000000;,
  0.333330;1.000000;,
  0.500000;1.000000;,
  0.666670;1.000000;,
  0.833330;1.000000;,
  1.000000;1.000000;,
  0.083330;0.000000;,
  0.250000;0.000000;,
  0.416670;0.000000;,
  0.583330;0.000000;,
  0.750000;0.000000;,
  0.916670;0.000000;,
  0.083330;1.000000;,
  0.250000;1.000000;,
  0.416670;1.000000;,
  0.583330;1.000000;,
  0.750000;1.000000;,
  0.916670;1.000000;,
  0.083330;0.000000;,
  0.166670;0.166670;,
  0.000000;0.166670;,
  0.250000;0.000000;,
  0.333330;0.166670;,
  0.416670;0.000000;,
  0.500000;0.166670;,
  0.583330;0.000000;,
  0.666670;0.166670;,
  0.750000;0.000000;,
  0.833330;0.166670;,
  0.916670;0.000000;,
  1.000000;0.166670;,
  0.166670;0.333330;,
  0.000000;0.333330;,
  0.333330;0.333330;,
  0.500000;0.333330;,
  0.666670;0.333330;,
  0.833330;0.333330;,
  1.000000;0.333330;,
  0.166670;0.500000;,
  0.000000;0.500000;,
  0.333330;0.500000;,
  0.500000;0.500000;,
  0.666670;0.500000;,
  0.833330;0.500000;,
  1.000000;0.500000;,
  0.166670;0.666670;,
  0.000000;0.666670;,
  0.333330;0.666670;,
  0.500000;0.666670;,
  0.666670;0.666670;,
  0.833330;0.666670;,
  1.000000;0.666670;,
  0.166670;0.833330;,
  0.000000;0.833330;,
  0.333330;0.833330;,
  0.500000;0.833330;,
  0.666670;0.833330;,
  0.833330;0.833330;,
  1.000000;0.833330;,
  0.083330;1.000000;,
  0.250000;1.000000;,
  0.416670;1.000000;,
  0.583330;1.000000;,
  0.750000;1.000000;,
  0.916670;1.000000;,
  0.000000;0.000000;,
  0.166670;0.000000;,
  0.166670;0.500000;,
  0.000000;0.500000;,
  0.333330;0.000000;,
  0.333330;0.500000;,
  0.500000;0.000000;,
  0.500000;0.500000;,
  0.666670;0.000000;,
  0.666670;0.500000;,
  0.833330;0.000000;,
  0.833330;0.500000;,
  1.000000;0.000000;,
  1.000000;0.500000;,
  0.166670;1.000000;,
  0.000000;1.000000;,
  0.333330;1.000000;,
  0.500000;1.000000;,
  0.666670;1.000000;,
  0.833330;1.000000;,
  1.000000;1.000000;,
  0.083330;0.000000;,
  0.250000;0.000000;,
  0.416670;0.000000;,
  0.583330;0.000000;,
  0.750000;0.000000;,
  0.916670;0.000000;,
  0.083330;1.000000;,
  0.250000;1.000000;,
  0.416670;1.000000;,
  0.583330;1.000000;,
  0.750000;1.000000;,
  0.916670;1.000000;,
  0.083330;0.000000;,
  0.166670;0.166670;,
  0.000000;0.166670;,
  0.250000;0.000000;,
  0.333330;0.166670;,
  0.416670;0.000000;,
  0.500000;0.166670;,
  0.583330;0.000000;,
  0.666670;0.166670;,
  0.750000;0.000000;,
  0.833330;0.166670;,
  0.916670;0.000000;,
  1.000000;0.166670;,
  0.166670;0.333330;,
  0.000000;0.333330;,
  0.333330;0.333330;,
  0.500000;0.333330;,
  0.666670;0.333330;,
  0.833330;0.333330;,
  1.000000;0.333330;,
  0.166670;0.500000;,
  0.000000;0.500000;,
  0.333330;0.500000;,
  0.500000;0.500000;,
  0.666670;0.500000;,
  0.833330;0.500000;,
  1.000000;0.500000;,
  0.166670;0.666670;,
  0.000000;0.666670;,
  0.333330;0.666670;,
  0.500000;0.666670;,
  0.666670;0.666670;,
  0.833330;0.666670;,
  1.000000;0.666670;,
  0.166670;0.833330;,
  0.000000;0.833330;,
  0.333330;0.833330;,
  0.500000;0.833330;,
  0.666670;0.833330;,
  0.833330;0.833330;,
  1.000000;0.833330;,
  0.083330;1.000000;,
  0.250000;1.000000;,
  0.416670;1.000000;,
  0.583330;1.000000;,
  0.750000;1.000000;,
  0.916670;1.000000;;
 }
}
