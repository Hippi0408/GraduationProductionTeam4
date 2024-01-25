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
 308;
 25.00000;62.80510;-9.92247;,
 25.00000;53.96113;9.92328;,
 25.00000;42.67628;9.92328;,
 25.00000;42.67628;-9.92247;,
 25.00000;67.66285;-24.99960;,
 25.00000;29.39448;-9.92247;,
 25.00000;-0.31967;-24.99960;,
 25.00000;29.39448;9.92328;,
 25.00113;47.98795;25.00040;,
 25.00113;-0.31945;25.00040;,
 6.38500;47.98800;25.00000;,
 -4.93535;27.86418;25.00000;,
 -24.99887;-0.31930;25.00000;,
 25.00113;-0.31945;25.00040;,
 -7.28410;43.05238;9.92288;,
 -3.62192;51.89635;-9.92287;,
 -7.04135;-0.31965;-25.00000;,
 -24.99887;-0.31930;25.00000;,
 6.38500;47.98800;25.00000;,
 25.00113;47.98795;25.00040;,
 25.00000;53.96113;9.92328;,
 6.38388;53.96118;9.92288;,
 -7.28410;43.05238;9.92288;,
 6.38388;53.96118;9.92288;,
 6.38388;62.80518;-9.92287;,
 -3.62192;51.89635;-9.92287;,
 25.00000;62.80510;-9.92247;,
 6.38388;62.80518;-9.92287;,
 6.38388;67.66293;-25.00000;,
 -3.62192;56.75413;-25.00000;,
 25.00000;67.66285;-24.99960;,
 6.38388;67.66293;-25.00000;,
 -7.04135;-0.31965;-25.00000;,
 25.00000;-0.31967;-24.99960;,
 25.00113;-0.31945;25.00040;,
 -24.99887;-0.31930;25.00000;,
 -4.93535;27.86418;25.00000;,
 25.00113;47.98795;25.00040;,
 -3.62192;56.75413;-25.00000;,
 -7.04135;-0.31965;-25.00000;,
 -3.62192;56.75413;-25.00000;,
 6.38388;67.66293;-25.00000;,
 25.00000;-0.31967;-24.99960;,
 25.00000;67.66285;-24.99960;,
 -4.93535;27.86418;25.00000;,
 6.38388;53.96118;9.92288;,
 -4.93535;27.86418;25.00000;,
 -6.38295;47.98563;25.00000;,
 6.38500;47.98563;25.00000;,
 6.38500;82.43270;25.00000;,
 -6.38295;77.65220;25.00000;,
 25.00113;47.98558;25.00040;,
 25.00113;82.43263;25.00040;,
 25.00113;47.98558;25.00040;,
 25.00000;53.96113;9.92328;,
 25.00000;82.43253;9.92328;,
 25.00113;82.43263;25.00040;,
 25.00000;62.80510;-9.92247;,
 25.00000;89.11011;-9.92247;,
 25.00000;67.66050;-24.99960;,
 25.00000;89.10997;-24.99960;,
 25.00000;67.66050;-24.99960;,
 6.38388;67.66055;-25.00000;,
 6.38388;89.11003;-25.00000;,
 25.00000;89.10997;-24.99960;,
 -6.38407;67.66055;-25.00000;,
 -6.38407;84.32950;-25.00000;,
 -25.00000;67.66063;-25.00000;,
 -25.00000;81.93928;-25.00000;,
 -25.00000;62.80525;-9.92287;,
 -25.00000;81.93943;-9.92287;,
 -25.00000;53.96125;9.92288;,
 -25.00000;75.26193;9.92288;,
 -25.00000;67.66063;-25.00000;,
 -6.38407;67.66055;-25.00000;,
 -6.38407;62.80518;-9.92287;,
 -25.00000;62.80525;-9.92287;,
 6.38388;67.66055;-25.00000;,
 6.38388;62.80518;-9.92287;,
 25.00000;67.66050;-24.99960;,
 25.00000;62.80510;-9.92247;,
 -6.38407;53.96118;9.92288;,
 -25.00000;53.96125;9.92288;,
 6.38388;53.96118;9.92288;,
 25.00000;53.96113;9.92328;,
 -6.38295;47.98563;25.00000;,
 -24.99887;47.98573;25.00000;,
 6.38500;47.98563;25.00000;,
 25.00113;47.98558;25.00040;,
 -24.99887;75.26203;25.00000;,
 -6.38295;77.65220;25.00000;,
 -6.38407;77.65211;9.92288;,
 -25.00000;75.26193;9.92288;,
 6.38500;82.43270;25.00000;,
 6.38388;82.43263;9.92288;,
 25.00113;82.43263;25.00040;,
 25.00000;82.43253;9.92328;,
 -6.38407;84.32965;-9.92290;,
 -25.00000;81.93943;-9.92287;,
 6.38388;89.11015;-9.92290;,
 25.00000;89.11011;-9.92247;,
 -6.38407;84.32950;-25.00000;,
 -25.00000;81.93928;-25.00000;,
 6.38388;89.11003;-25.00000;,
 25.00000;89.10997;-24.99960;,
 -24.99887;75.26203;25.00000;,
 -24.99887;75.26203;25.00000;,
 -24.99887;47.98573;25.00000;,
 -24.99887;47.98573;25.00000;,
 -24.99887;75.26203;25.00000;,
 -6.38295;77.65220;25.00000;,
 -6.38295;96.39735;25.00003;,
 -24.99887;96.39743;25.00003;,
 6.38500;82.43270;25.00000;,
 5.90013;106.63936;25.00000;,
 25.00113;82.43263;25.00040;,
 25.00113;107.32236;25.00043;,
 25.00113;82.43263;25.00040;,
 25.00000;82.43253;9.92328;,
 25.00000;112.47891;9.92330;,
 25.00113;107.32236;25.00043;,
 25.00000;104.05310;-9.92247;,
 25.00000;119.02510;-9.92247;,
 25.00000;108.47105;-24.99960;,
 25.00000;121.48655;-24.99957;,
 25.00000;108.47105;-24.99960;,
 6.38388;108.47111;-25.00000;,
 5.89900;120.98640;-25.00000;,
 25.00000;121.48655;-24.99957;,
 -6.38407;90.49233;-25.00000;,
 -6.38407;110.56162;-24.99997;,
 -25.00000;90.49240;-25.00000;,
 -25.00000;110.56172;-24.99997;,
 -25.00000;93.12823;-9.92287;,
 -25.00000;108.10025;-9.92287;,
 -25.00000;110.56172;-24.99997;,
 -25.00000;75.26193;9.92288;,
 -25.00000;101.55393;9.92290;,
 -24.99887;75.26203;25.00000;,
 -24.99887;96.39743;25.00003;,
 -25.00000;90.49240;-25.00000;,
 -6.38407;90.49233;-25.00000;,
 -6.38407;93.12815;-9.92287;,
 -25.00000;93.12823;-9.92287;,
 6.38388;108.47111;-25.00000;,
 6.38388;104.05315;-9.92287;,
 25.00000;108.47105;-24.99960;,
 25.00000;104.05310;-9.92247;,
 -6.38407;77.65211;9.92288;,
 -25.00000;75.26193;9.92288;,
 6.38388;82.43263;9.92288;,
 25.00000;82.43253;9.92328;,
 -6.38295;77.65220;25.00000;,
 -24.99887;75.26203;25.00000;,
 6.38500;82.43270;25.00000;,
 25.00113;82.43263;25.00040;,
 -24.99887;96.39743;25.00003;,
 -6.38295;96.39735;25.00003;,
 -6.38407;101.55388;9.92290;,
 -25.00000;101.55393;9.92290;,
 5.90013;106.63936;25.00000;,
 6.38388;112.47896;9.92290;,
 25.00113;107.32236;25.00043;,
 25.00000;112.47891;9.92330;,
 -6.38407;108.10015;-9.92287;,
 -25.00000;108.10025;-9.92287;,
 6.38388;119.02517;-9.92287;,
 25.00000;119.02510;-9.92247;,
 -6.38407;110.56162;-24.99997;,
 -25.00000;110.56172;-24.99997;,
 5.89900;120.98640;-25.00000;,
 25.00000;121.48655;-24.99957;,
 6.38388;89.11003;-25.00000;,
 -6.38407;81.96357;-25.00000;,
 -6.38407;90.49233;-25.00000;,
 6.38388;108.47111;-25.00000;,
 -25.00000;81.93928;-25.00000;,
 -25.00000;90.49240;-25.00000;,
 -25.00000;81.93943;-9.92287;,
 -25.00000;93.12823;-9.92287;,
 -6.38407;81.96357;-25.00000;,
 6.38388;89.11003;-25.00000;,
 25.00000;82.43253;9.92328;,
 -25.00000;81.93943;-9.92287;,
 -25.00000;93.12823;-9.92287;,
 -25.00000;75.26193;9.92288;,
 -6.45270;89.13410;-4.84190;,
 -25.00000;90.49240;-25.00000;,
 25.00000;82.43253;9.92328;,
 5.95033;95.52125;8.05380;,
 6.38388;108.47111;-25.00000;,
 -6.38407;90.49233;-25.00000;,
 25.00000;104.05310;-9.92247;,
 25.00000;108.47105;-24.99960;,
 25.00000;104.05310;-9.92247;,
 25.00000;82.43253;9.92328;,
 25.00000;89.11011;-9.92247;,
 25.00000;89.10997;-24.99960;,
 25.00000;108.47105;-24.99960;,
 25.00000;104.05310;-9.92247;,
 25.00000;89.10997;-24.99960;,
 25.00000;108.47105;-24.99960;,
 -25.00000;75.26193;9.92288;,
 -25.00000;90.49240;-25.00000;,
 25.00000;82.43253;9.92328;,
 -6.38407;81.96357;-25.00000;,
 -25.00000;75.26193;9.92288;,
 -6.38407;81.96357;-25.00000;,
 -25.00000;81.93943;-9.92287;,
 -25.00000;81.93928;-25.00000;,
 6.38388;89.11003;-25.00000;,
 25.00000;89.10997;-24.99960;,
 25.00000;89.11011;-9.92247;,
 25.00000;82.43253;9.92328;,
 25.00000;82.43253;9.92328;,
 -6.38407;81.96357;-25.00000;,
 -25.00000;75.26193;9.92288;,
 -1.34890;122.02946;-25.00000;,
 9.98103;131.43035;-25.00000;,
 5.89900;120.98640;-25.00000;,
 -6.38407;110.56162;-24.99997;,
 9.98103;131.43035;-25.00000;,
 9.98215;131.43062;25.00000;,
 5.90013;106.63936;25.00000;,
 5.89900;120.98640;-25.00000;,
 9.98215;131.43062;25.00000;,
 -1.34777;115.58701;25.00000;,
 -6.38295;96.39735;25.00003;,
 5.90013;106.63936;25.00000;,
 -1.34777;115.58701;25.00000;,
 -1.34890;122.02946;-25.00000;,
 -6.38407;110.56162;-24.99997;,
 -6.38295;96.39735;25.00003;,
 9.98103;131.43035;-25.00000;,
 -1.34890;122.02946;-25.00000;,
 -6.38407;110.56162;-24.99997;,
 5.89900;120.98640;-25.00000;,
 -7.18605;131.43035;-25.00000;,
 -1.34890;122.02946;-25.00000;,
 -6.38407;110.56162;-24.99997;,
 -11.01722;110.56162;-24.99997;,
 -7.18492;131.43062;25.00000;,
 -7.18605;131.43035;-25.00000;,
 -11.01722;110.56162;-24.99997;,
 -6.38295;96.39735;25.00003;,
 -7.18492;131.43062;25.00000;,
 -1.34777;115.58701;25.00000;,
 -1.34890;122.02946;-25.00000;,
 -7.18605;131.43035;-25.00000;,
 -11.01722;110.56162;-24.99997;,
 -6.38407;110.56162;-24.99997;,
 -1.34777;115.58701;25.00000;,
 -6.38295;96.39735;25.00003;,
 -1.34777;115.58701;25.00000;,
 -6.38407;110.56162;-24.99997;,
 -1.34890;122.02946;-25.00000;,
 -1.34777;115.58701;25.00000;,
 -7.18492;131.43062;25.00000;,
 -6.38295;96.39735;25.00003;,
 9.98103;131.43035;-25.00000;,
 9.98215;131.43062;25.00000;,
 -1.34777;115.58701;25.00000;,
 -1.34890;122.02946;-25.00000;,
 -7.18492;131.43062;25.00000;,
 -7.18605;131.43035;-25.00000;,
 -7.18492;131.43062;25.00000;,
 9.98215;131.43062;25.00000;,
 9.98103;131.43035;-25.00000;,
 -7.18605;131.43035;-25.00000;,
 -1.34777;115.58701;25.00000;,
 9.98215;131.43062;25.00000;,
 -7.18492;131.43062;25.00000;,
 -1.34890;122.02946;-25.00000;,
 -7.18605;131.43035;-25.00000;,
 9.98103;131.43035;-25.00000;,
 -3.62192;56.75413;-25.00000;,
 -4.93535;27.86418;25.00000;,
 -8.37710;42.67635;9.92288;,
 -8.37710;42.67635;-9.92287;,
 -3.62192;56.75413;-25.00000;,
 -8.37710;29.39453;-9.92287;,
 -7.04135;-0.31965;-25.00000;,
 -8.37710;29.39453;9.92288;,
 -4.93535;27.86418;25.00000;,
 -24.99887;-0.31930;25.00000;,
 -25.00000;53.96125;9.92288;,
 -25.00000;62.80525;-9.92287;,
 -25.00000;-0.31955;-25.00000;,
 -24.99887;-0.31930;25.00000;,
 -25.00000;53.96125;9.92288;,
 -4.93535;27.86418;25.00000;,
 -3.62192;56.75413;-25.00000;,
 -25.00000;62.80525;-9.92287;,
 -24.99887;47.98810;25.00000;,
 -24.99887;-0.31930;25.00000;,
 -4.93535;27.86418;25.00000;,
 -24.99887;47.98810;25.00000;,
 -25.00000;67.66300;-25.00000;,
 -7.04135;-0.31965;-25.00000;,
 -3.62192;56.75413;-25.00000;,
 -25.00000;53.96125;9.92288;,
 -24.99887;47.98810;25.00000;,
 -4.93535;27.86418;25.00000;,
 -3.62192;56.75413;-25.00000;,
 -25.00000;67.66300;-25.00000;,
 -24.99887;-0.31930;25.00000;,
 -25.00000;-0.31955;-25.00000;,
 -7.04135;-0.31965;-25.00000;;
 
 139;
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
 4;67,69,70,68;,
 4;69,71,72,70;,
 4;73,74,75,76;,
 4;74,77,78,75;,
 4;77,79,80,78;,
 4;76,75,81,82;,
 4;75,78,83,81;,
 4;78,80,84,83;,
 4;82,81,85,86;,
 4;81,83,87,85;,
 4;83,84,88,87;,
 4;89,90,91,92;,
 4;90,93,94,91;,
 4;93,95,96,94;,
 4;92,91,97,98;,
 4;91,94,99,97;,
 4;94,96,100,99;,
 4;98,97,101,102;,
 4;97,99,103,101;,
 4;99,100,104,103;,
 3;105,47,50;,
 3;106,72,71;,
 3;47,105,107;,
 3;71,108,106;,
 4;109,110,111,112;,
 4;110,113,114,111;,
 4;113,115,116,114;,
 4;117,118,119,120;,
 4;118,121,122,119;,
 4;121,123,124,122;,
 4;125,126,127,128;,
 4;126,129,130,127;,
 4;129,131,132,130;,
 4;131,133,134,135;,
 4;133,136,137,134;,
 4;136,138,139,137;,
 4;140,141,142,143;,
 4;141,144,145,142;,
 4;144,146,147,145;,
 4;143,142,148,149;,
 4;142,145,150,148;,
 4;145,147,151,150;,
 4;149,148,152,153;,
 4;148,150,154,152;,
 4;150,151,155,154;,
 4;156,157,158,159;,
 4;157,160,161,158;,
 4;160,162,163,161;,
 4;159,158,164,165;,
 4;158,161,166,164;,
 4;161,163,167,166;,
 4;165,164,168,169;,
 4;164,166,170,168;,
 4;166,167,171,170;,
 4;172,173,174,175;,
 4;173,176,177,174;,
 4;176,178,179,177;,
 4;180,181,182,183;,
 4;184,185,186,187;,
 4;185,188,189,186;,
 4;186,189,190,191;,
 4;189,192,193,190;,
 3;194,195,196;,
 3;194,197,198;,
 3;199,189,188;,
 3;197,194,196;,
 3;200,172,175;,
 3;175,201,200;,
 3;202,179,178;,
 3;203,186,191;,
 3;204,185,205;,
 3;206,183,182;,
 3;207,208,209;,
 3;210,211,212;,
 3;213,181,212;,
 3;214,215,216;,
 4;217,218,219,220;,
 4;221,222,223,224;,
 4;225,226,227,228;,
 4;229,230,231,232;,
 4;229,222,233,234;,
 4;235,236,223,232;,
 4;237,238,239,240;,
 4;241,242,243,244;,
 4;245,246,247,248;,
 4;249,250,251,252;,
 3;253,254,255;,
 3;256,257,258;,
 4;259,260,261,262;,
 4;263,264,262,261;,
 4;265,266,267,268;,
 3;269,270,271;,
 3;272,273,274;,
 4;275,276,277,278;,
 4;279,278,280,281;,
 4;278,277,282,280;,
 4;277,283,284,282;,
 4;280,282,284,281;,
 4;285,286,287,288;,
 4;289,290,291,292;,
 3;288,293,285;,
 3;294,295,296;,
 3;287,286,297;,
 3;298,297,299;,
 3;300,301,302;,
 3;297,298,287;,
 3;303,304,292;,
 3;305,306,307;;
 
 MeshMaterialList {
  4;
  139;
  1,
  1,
  1,
  1,
  1,
  0,
  2,
  2,
  2,
  2,
  2,
  2,
  3,
  1,
  2,
  0,
  2,
  0,
  0,
  1,
  2,
  2,
  0,
  0,
  0,
  1,
  1,
  1,
  0,
  0,
  0,
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
  0,
  1,
  0,
  1,
  0,
  0,
  0,
  1,
  1,
  1,
  0,
  0,
  0,
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
  0,
  0,
  1,
  2,
  2,
  2,
  2,
  2,
  1,
  1,
  2,
  1,
  0,
  0,
  1,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  0,
  2,
  0,
  2,
  2,
  2,
  0,
  2,
  2,
  2,
  2,
  0,
  2,
  2,
  3,
  0,
  0,
  2,
  2,
  2,
  2,
  2,
  1,
  2,
  1,
  0,
  1,
  0,
  2,
  0,
  2,
  3;;
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
    "Data\\texture\\bill005.jpg";
   }
  }
  Material {
   0.800000;0.800000;0.800000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
   TextureFilename {
    "Data\\texture\\Concrete.png";
   }
  }
  Material {
   0.800000;0.800000;0.800000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
   TextureFilename {
    "Data\\texture\\Concrete.png";
   }
  }
 }
 MeshNormals {
  187;
  -0.915166;0.383655;0.123612;,
  -0.391217;0.875955;0.282227;,
  1.000000;0.000000;0.000000;,
  -0.986605;0.122278;-0.107975;,
  1.000000;0.000012;-0.000006;,
  1.000000;0.000000;-0.000037;,
  1.000000;0.000000;-0.000075;,
  1.000000;0.000008;-0.000004;,
  1.000000;0.000008;-0.000029;,
  1.000000;0.000012;-0.000043;,
  -0.000015;0.000003;1.000000;,
  -0.567979;0.440079;0.695507;,
  -0.763332;0.541362;0.352493;,
  -0.898325;0.433805;0.069462;,
  -0.436949;0.797429;0.416153;,
  -0.371802;0.871572;0.319572;,
  -0.373534;0.265914;0.888686;,
  -0.955232;0.182289;-0.233031;,
  -0.491072;0.809865;0.320885;,
  -0.000005;0.929698;0.368323;,
  -0.000006;0.921756;0.387771;,
  -0.000004;0.933961;0.357374;,
  -0.000003;0.951816;0.306669;,
  -0.000002;-1.000000;0.000006;,
  -0.000021;0.000000;1.000000;,
  0.000006;-0.000001;-1.000000;,
  0.000000;0.000000;-1.000000;,
  0.000011;-0.000001;-1.000000;,
  0.000017;-0.000001;-1.000000;,
  0.000021;0.000000;-1.000000;,
  -0.000004;-0.929648;-0.368449;,
  -0.127349;0.991858;0.000003;,
  0.000000;0.000000;1.000000;,
  -0.000011;0.000000;1.000000;,
  -0.000021;0.000000;1.000000;,
  1.000000;0.000000;-0.000037;,
  1.000000;0.000000;0.000000;,
  0.000011;0.000000;-1.000000;,
  0.000000;0.000000;-1.000000;,
  -1.000000;0.000000;0.000000;,
  -1.000000;0.000000;0.000050;,
  -1.000000;0.000000;0.000037;,
  -0.000002;-0.933987;-0.357308;,
  0.000002;-0.933987;-0.357308;,
  -0.000002;-0.921729;-0.387834;,
  0.000003;-0.921729;-0.387834;,
  -0.237749;0.958518;0.157221;,
  -0.176167;0.971386;0.159294;,
  -0.237750;0.958520;0.157210;,
  -0.176167;0.971387;0.159286;,
  1.000000;0.000000;-0.000075;,
  0.000021;0.000000;-1.000000;,
  -0.000004;-0.951860;-0.306533;,
  -0.000002;-0.951860;-0.306533;,
  -0.000004;-0.933987;-0.357308;,
  0.000002;-0.951860;-0.306533;,
  0.000003;-0.951860;-0.306533;,
  0.000004;-0.933987;-0.357308;,
  -0.000004;-0.921729;-0.387833;,
  0.000006;-0.921729;-0.387833;,
  -0.000002;-0.929648;-0.368449;,
  0.000003;-0.929648;-0.368450;,
  0.000005;-0.929648;-0.368450;,
  -0.240593;0.970626;0.000012;,
  -0.125701;0.979022;0.160361;,
  -0.178170;0.984000;0.000008;,
  0.000005;1.000000;-0.000006;,
  0.000001;0.986861;0.161572;,
  -0.125702;0.979023;0.160354;,
  -0.000000;0.986861;0.161571;,
  -0.240594;0.970626;-0.000009;,
  -0.127351;0.991858;-0.000010;,
  -0.178171;0.984000;-0.000009;,
  0.000003;1.000000;-0.000009;,
  -1.000000;0.000000;0.000075;,
  0.000000;-0.000002;1.000000;,
  0.000001;-0.000001;1.000000;,
  -0.000010;-0.000001;1.000000;,
  -0.000022;-0.000001;1.000000;,
  1.000000;0.000000;-0.000037;,
  1.000000;0.000000;0.000000;,
  0.000010;0.000001;-1.000000;,
  -0.000001;0.000001;-1.000000;,
  0.000000;0.000002;-1.000000;,
  -1.000000;0.000000;0.000000;,
  -1.000000;-0.000000;0.000037;,
  0.337563;-0.886530;-0.316411;,
  0.315015;-0.830136;-0.460042;,
  0.247993;-0.907327;-0.339497;,
  0.205305;-0.904810;-0.373052;,
  -0.332384;0.893520;0.301899;,
  -0.336341;0.890526;0.306331;,
  -0.339567;0.913657;0.223438;,
  -0.342745;0.913524;0.219087;,
  1.000000;0.000000;-0.000075;,
  0.000022;0.000002;-1.000000;,
  -1.000000;-0.000000;0.000075;,
  -0.000004;-0.985060;0.172211;,
  0.404820;-0.910482;0.084522;,
  0.026239;-0.965547;-0.258902;,
  0.405915;-0.898956;-0.164655;,
  0.000003;-0.959649;-0.281200;,
  0.000009;-0.849052;-0.528310;,
  0.093094;-0.935273;-0.341464;,
  0.000005;-0.915485;-0.402351;,
  0.240593;-0.970626;-0.000012;,
  0.127349;-0.991858;-0.000003;,
  0.178170;-0.984000;-0.000008;,
  -0.000005;-1.000000;0.000006;,
  0.000003;0.946192;0.323606;,
  -0.330151;0.892067;0.308573;,
  0.000003;0.947945;0.318436;,
  -0.338017;0.886014;0.317370;,
  -0.016681;0.939575;0.341937;,
  -0.008344;0.944764;0.327644;,
  0.000004;0.971284;0.237922;,
  -0.006517;0.973115;0.230227;,
  -0.342661;0.927372;0.150216;,
  0.000005;0.986934;0.161126;,
  -0.348760;0.926460;0.141558;,
  -0.012981;0.989276;0.145478;,
  -0.132585;0.909778;0.393351;,
  0.000000;0.000000;-1.000000;,
  0.192520;-0.952343;-0.236600;,
  1.000000;0.000000;0.000000;,
  -0.036822;0.945817;0.322606;,
  0.172929;0.829533;0.531009;,
  0.000014;0.000000;-1.000000;,
  -1.000000;0.000000;0.000000;,
  0.000011;0.000000;-1.000000;,
  -0.272012;0.900602;0.339008;,
  -0.220847;0.814694;0.536191;,
  0.128628;-0.985961;-0.106470;,
  0.166032;-0.970766;-0.173342;,
  0.127166;-0.976238;-0.175464;,
  0.127681;0.951024;0.281515;,
  0.064363;0.982321;0.175792;,
  -0.049644;0.827216;0.559687;,
  -0.422229;0.868545;0.259524;,
  -0.406204;0.905597;0.122038;,
  0.000021;0.000000;-1.000000;,
  0.138612;-0.966519;-0.215933;,
  0.001305;-0.999999;0.000010;,
  -0.000003;-1.000000;0.000009;,
  0.127696;-0.979202;-0.157661;,
  -0.141042;0.983471;0.113542;,
  -0.000000;-0.000001;-1.000000;,
  0.964051;-0.264683;-0.023439;,
  0.837443;-0.532182;-0.124387;,
  0.000001;0.000001;1.000000;,
  -0.855274;0.515669;0.050919;,
  -0.942527;0.328341;0.061936;,
  -0.731393;0.680912;0.037722;,
  0.628952;-0.747647;-0.213173;,
  -0.000001;-0.000002;-1.000000;,
  0.999657;0.020573;-0.016215;,
  -0.995909;0.079369;0.043205;,
  0.898311;0.438791;0.022348;,
  0.606996;-0.764613;-0.216617;,
  0.786018;-0.602455;-0.138651;,
  0.000003;0.000001;1.000000;,
  -0.898311;-0.438791;-0.022348;,
  0.731393;-0.680912;-0.037722;,
  0.000000;1.000000;-0.000005;,
  0.000000;-0.000000;1.000000;,
  0.000000;0.000000;-1.000000;,
  -1.000000;0.000000;0.000000;,
  -1.000000;-0.000004;0.000006;,
  0.960701;-0.175722;0.214884;,
  -0.261931;-0.897484;-0.354844;,
  0.982553;-0.117735;0.143974;,
  0.977480;-0.209743;-0.023265;,
  0.949016;-0.313307;-0.034753;,
  -1.000000;0.000000;0.000075;,
  -1.000000;-0.000004;0.000043;,
  0.728659;0.592264;0.343919;,
  0.991797;-0.014790;0.126966;,
  0.980978;-0.150309;-0.122839;,
  0.924635;-0.294900;-0.241005;,
  0.611969;0.718606;0.330303;,
  0.488374;0.806476;0.333298;,
  0.000000;-0.000000;1.000000;,
  0.000000;0.000000;-1.000000;,
  0.682001;0.679954;0.269328;,
  0.000000;0.000000;-1.000000;,
  0.436890;0.856173;0.275853;,
  -0.000006;-1.000000;0.000005;;
  139;
  4;2,5,5,2;,
  4;2,2,7,4;,
  4;2,5,8,7;,
  4;5,6,9,8;,
  4;7,8,9,4;,
  4;10,11,16,10;,
  4;12,13,3,17;,
  4;18,19,20,14;,
  4;12,14,15,13;,
  4;14,20,21,15;,
  4;13,15,1,0;,
  4;15,21,22,1;,
  4;23,23,23,23;,
  3;6,5,5;,
  3;16,11,12;,
  3;10,24,10;,
  3;3,13,0;,
  3;25,26,27;,
  3;28,27,29;,
  3;2,2,2;,
  3;11,14,12;,
  3;14,11,18;,
  3;27,28,25;,
  4;32,33,33,32;,
  4;33,34,34,33;,
  4;50,35,35,50;,
  4;35,36,36,35;,
  4;36,36,36,36;,
  4;51,37,37,51;,
  4;37,38,38,37;,
  4;38,38,38,38;,
  4;39,39,39,39;,
  4;39,40,41,39;,
  4;52,53,42,54;,
  4;53,55,43,42;,
  4;55,56,57,43;,
  4;54,42,44,58;,
  4;42,43,45,44;,
  4;43,57,59,45;,
  4;58,44,60,30;,
  4;44,45,61,60;,
  4;45,59,62,61;,
  4;31,63,46,64;,
  4;63,65,47,46;,
  4;65,66,67,47;,
  4;64,46,48,68;,
  4;46,47,49,48;,
  4;47,67,69,49;,
  4;68,48,70,71;,
  4;48,49,72,70;,
  4;49,69,73,72;,
  3;32,32,32;,
  3;74,41,40;,
  3;32,32,32;,
  3;40,74,74;,
  4;75,76,76,75;,
  4;76,77,77,76;,
  4;77,78,78,77;,
  4;94,79,79,94;,
  4;79,80,80,79;,
  4;80,80,80,80;,
  4;95,81,81,95;,
  4;81,82,82,81;,
  4;82,83,83,82;,
  4;84,84,84,84;,
  4;84,85,85,84;,
  4;85,96,96,85;,
  4;97,98,86,99;,
  4;98,100,87,86;,
  4;100,101,102,87;,
  4;99,86,88,103;,
  4;86,87,89,88;,
  4;87,102,104,89;,
  4;103,88,105,106;,
  4;88,89,107,105;,
  4;89,104,108,107;,
  4;109,110,90,111;,
  4;110,112,91,90;,
  4;112,113,114,91;,
  4;111,90,92,115;,
  4;90,91,93,92;,
  4;91,114,116,93;,
  4;115,92,117,118;,
  4;92,93,119,117;,
  4;93,116,120,119;,
  4;129,122,122,127;,
  4;122,122,122,122;,
  4;128,128,128,128;,
  4;132,133,123,134;,
  4;135,121,130,136;,
  4;121,137,131,130;,
  4;130,131,138,139;,
  4;131,126,125,138;,
  3;124,124,124;,
  3;124,124,124;,
  3;126,131,137;,
  3;124,124,124;,
  3;140,129,127;,
  3;127,140,140;,
  3;128,128,128;,
  3;136,130,139;,
  3;123,141,132;,
  3;141,134,123;,
  3;132,134,142;,
  3;133,143,144;,
  3;123,133,144;,
  3;137,145,121;,
  4;146,146,146,146;,
  4;147,147,148,148;,
  4;149,149,149,149;,
  4;150,150,151,151;,
  4;150,152,152,150;,
  4;153,148,148,153;,
  4;154,154,154,154;,
  4;156,156,156,156;,
  4;157,155,155,157;,
  4;158,159,158,158;,
  3;155,159,155;,
  3;160,160,160;,
  4;162,162,162,162;,
  4;161,161,161,161;,
  4;163,163,163,163;,
  3;164,164,164;,
  3;165,165,165;,
  4;169,169,169,169;,
  4;175,176,170,168;,
  4;176,177,171,170;,
  4;177,178,172,171;,
  4;170,171,172,168;,
  4;174,167,167,174;,
  4;179,179,175,180;,
  3;174,173,174;,
  3;181,181,181;,
  3;167,167,166;,
  3;182,182,182;,
  3;179,183,179;,
  3;182,182,184;,
  3;175,185,180;,
  3;186,186,186;;
 }
 MeshTextureCoords {
  308;
  0.347347;0.524204;,
  0.652666;0.591204;,
  0.652666;0.676695;,
  0.347347;0.676695;,
  0.115391;0.487403;,
  0.347347;0.777315;,
  0.115391;1.002422;,
  0.652666;0.777315;,
  0.884622;0.636455;,
  0.884622;1.002420;,
  0.598231;0.636455;,
  0.424072;0.788908;,
  0.115402;1.002419;,
  0.884633;1.002420;,
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
  0.147933;-0.750000;,
  1.750000;-0.749980;,
  1.750057;1.750020;,
  -0.749943;1.750000;,
  0.859710;0.851260;,
  0.884633;0.636455;,
  0.140290;0.686630;,
  0.391672;1.002422;,
  0.444278;0.570044;,
  0.598214;0.487402;,
  0.884615;1.002422;,
  0.884615;0.487403;,
  0.166670;0.000000;,
  0.500000;0.333330;,
  0.333330;0.000000;,
  0.401801;0.636472;,
  0.598231;0.636472;,
  0.598231;0.375510;,
  0.401801;0.411726;,
  0.884633;0.636473;,
  0.884633;0.375510;,
  0.884622;0.636473;,
  0.652666;0.591204;,
  0.652666;0.375511;,
  0.884622;0.375510;,
  0.347347;0.524204;,
  0.347347;0.324923;,
  0.115391;0.487420;,
  0.115391;0.324924;,
  0.884615;0.487420;,
  0.598214;0.487420;,
  0.598214;0.324924;,
  0.884615;0.324924;,
  0.401784;0.487420;,
  0.401784;0.361140;,
  0.115385;0.487419;,
  0.115385;0.379248;,
  0.347340;0.524203;,
  0.347340;0.379247;,
  0.652660;0.591203;,
  0.652660;0.429834;,
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
  0.115402;0.429833;,
  0.884615;0.429833;,
  0.115402;0.636472;,
  0.884615;0.636472;,
  0.115402;0.429833;,
  0.401801;0.411726;,
  0.401801;0.269717;,
  0.115402;0.269716;,
  0.598231;0.375510;,
  0.590771;0.192126;,
  0.884633;0.375510;,
  0.884633;0.186952;,
  0.884622;0.375510;,
  0.652666;0.375511;,
  0.652666;0.147887;,
  0.884622;0.186952;,
  0.347347;0.211719;,
  0.347347;0.098295;,
  0.115391;0.178250;,
  0.115391;0.079647;,
  0.884615;0.178250;,
  0.598214;0.178249;,
  0.590754;0.083436;,
  0.884615;0.079647;,
  0.401784;0.314452;,
  0.401784;0.162412;,
  0.115385;0.314452;,
  0.115385;0.162411;,
  0.347340;0.294483;,
  0.347340;0.181059;,
  0.115385;0.162411;,
  0.652660;0.429834;,
  0.652660;0.230652;,
  0.884615;0.429833;,
  0.884616;0.269716;,
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
  0.598214;0.324924;,
  0.401784;0.379064;,
  0.401784;0.314452;,
  0.598214;0.178249;,
  0.115385;0.379248;,
  0.115385;0.314452;,
  0.347340;0.379247;,
  0.347340;0.294483;,
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
  0.347347;0.211719;,
  0.652666;0.375511;,
  0.347347;0.324923;,
  0.115391;0.324924;,
  0.115391;0.178250;,
  1.000000;0.500000;,
  0.884615;0.324924;,
  0.884615;0.178250;,
  0.652660;0.429834;,
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
  0.479248;0.075534;,
  0.653554;0.004316;,
  0.590754;0.083436;,
  0.401784;0.162412;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.653572;0.004314;,
  0.479265;0.124341;,
  0.401801;0.269717;,
  0.590771;0.192126;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  0.389445;0.004316;,
  0.479248;0.075534;,
  0.401784;0.162412;,
  0.330504;0.162412;,
  0.859710;0.023860;,
  0.140290;0.023860;,
  0.140290;0.236410;,
  0.859710;0.354930;,
  0.311880;0.023860;,
  0.625120;0.023860;,
  0.625120;0.023860;,
  0.311880;0.023860;,
  0.211590;0.236410;,
  0.859710;0.423860;,
  0.464690;0.194360;,
  0.332880;0.354930;,
  0.859710;0.109110;,
  0.140290;0.423860;,
  0.140290;0.023860;,
  0.479265;0.124341;,
  0.389463;0.004314;,
  0.401801;0.269717;,
  0.761290;0.020000;,
  0.761290;0.020000;,
  0.464690;0.194360;,
  0.464690;0.140450;,
  0.311880;0.020000;,
  0.311880;0.020000;,
  0.140754;1.750000;,
  0.999107;1.750000;,
  0.999052;-0.750000;,
  0.140698;-0.750000;,
  0.479265;0.124341;,
  0.653572;0.004314;,
  0.389463;0.004314;,
  0.479248;0.075534;,
  0.389445;0.004316;,
  0.653554;0.004316;,
  0.332880;0.636000;,
  0.859710;0.759980;,
  0.667120;0.804420;,
  0.332880;0.804420;,
  0.140290;0.595350;,
  0.332880;0.915560;,
  0.140290;0.980000;,
  0.667120;0.915560;,
  0.859710;0.851260;,
  0.859710;0.980000;,
  0.652660;0.591203;,
  0.347340;0.524203;,
  0.115385;1.002421;,
  0.884615;1.002419;,
  0.666670;0.333330;,
  1.000000;0.333330;,
  1.000000;0.666670;,
  0.666670;0.666670;,
  0.884615;0.636454;,
  0.115402;1.002419;,
  0.424072;0.788908;,
  0.115402;0.636454;,
  0.115385;0.487401;,
  0.391672;1.002422;,
  0.444278;0.570044;,
  0.166670;0.333330;,
  0.000000;0.000000;,
  0.333330;0.000000;,
  1.000000;0.833330;,
  0.666670;1.000000;,
  -0.749943;1.750000;,
  -0.750000;-0.750000;,
  0.147933;-0.750000;;
 }
}