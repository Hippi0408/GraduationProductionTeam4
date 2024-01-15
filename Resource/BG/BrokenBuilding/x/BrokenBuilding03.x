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
 319;
 71.62500;71.88935;-12.54420;,
 71.62500;60.76467;12.54420;,
 71.62500;46.56975;12.54420;,
 71.62500;46.56975;-12.54420;,
 71.62500;78.00000;-27.00000;,
 71.62500;29.86280;-12.54420;,
 71.62500;-0.12740;-27.00000;,
 71.62500;29.86280;12.54420;,
 71.62500;53.25103;27.00000;,
 71.62500;-0.12740;27.00000;,
 28.50382;53.25092;27.00000;,
 -46.38896;42.78697;27.00000;,
 -71.62500;-0.12740;27.00000;,
 71.62500;-0.12740;27.00000;,
 -32.52336;47.04262;12.54420;,
 -16.17175;58.16730;-12.54420;,
 -31.43948;-0.12751;-27.00000;,
 -71.62500;-0.12740;27.00000;,
 28.50382;53.25092;27.00000;,
 71.62500;53.25103;27.00000;,
 71.62500;60.76467;12.54420;,
 28.50382;60.76458;12.54420;,
 -32.52336;47.04262;12.54420;,
 28.50382;60.76458;12.54420;,
 28.50382;71.88925;-12.54420;,
 -16.17175;58.16730;-12.54420;,
 71.62500;71.88935;-12.54420;,
 28.50382;71.88925;-12.54420;,
 28.50382;77.99990;-27.00000;,
 -16.17175;64.27794;-27.00000;,
 71.62500;78.00000;-27.00000;,
 28.50382;77.99990;-27.00000;,
 -31.43948;-0.12751;-27.00000;,
 71.62500;-0.12740;-27.00000;,
 71.62500;-0.12740;27.00000;,
 -71.62500;-0.12740;27.00000;,
 -46.38896;42.78697;27.00000;,
 71.62500;53.25103;27.00000;,
 -16.17175;64.27794;-27.00000;,
 -31.43948;-0.12751;-27.00000;,
 -16.17175;64.27794;-27.00000;,
 28.50382;77.99990;-27.00000;,
 71.62500;-0.12740;-27.00000;,
 71.62500;78.00000;-27.00000;,
 -46.38896;42.78697;27.00000;,
 28.50382;60.76458;12.54420;,
 -46.38896;42.78697;27.00000;,
 -28.50473;53.24792;27.00000;,
 28.50382;53.24792;27.00000;,
 28.50382;96.57817;27.00000;,
 -28.50473;90.56489;27.00000;,
 71.62500;53.24802;27.00000;,
 71.62500;96.57827;27.00000;,
 71.62500;53.24802;27.00000;,
 71.62500;60.76467;12.54420;,
 71.62500;96.57830;12.54420;,
 71.62500;96.57827;27.00000;,
 71.62500;71.88935;-12.54420;,
 71.62500;104.97785;-12.54420;,
 71.62500;77.99699;-27.00000;,
 71.62500;104.97785;-27.00000;,
 71.62500;77.99699;-27.00000;,
 28.50382;77.99689;-27.00000;,
 28.50382;104.97774;-27.00000;,
 71.62500;104.97785;-27.00000;,
 -28.50473;77.99689;-27.00000;,
 -28.50473;98.96445;-27.00000;,
 -71.62500;77.99699;-27.00000;,
 -71.62500;95.95779;-27.00000;,
 -71.62500;77.99699;-27.00000;,
 -71.62500;71.88935;-12.54420;,
 -71.62500;95.95779;-12.54420;,
 -71.62500;95.95779;-27.00000;,
 -71.62500;60.76467;12.54420;,
 -71.62500;87.55832;12.54420;,
 -71.62500;77.99699;-27.00000;,
 -28.50473;77.99689;-27.00000;,
 -28.50473;71.88925;-12.54420;,
 -71.62500;71.88935;-12.54420;,
 28.50382;77.99689;-27.00000;,
 28.50382;71.88925;-12.54420;,
 71.62500;77.99699;-27.00000;,
 71.62500;71.88935;-12.54420;,
 -28.50473;60.76458;12.54420;,
 -71.62500;60.76467;12.54420;,
 28.50382;60.76458;12.54420;,
 71.62500;60.76467;12.54420;,
 -28.50473;53.24792;27.00000;,
 -71.62500;53.24802;27.00000;,
 28.50382;53.24792;27.00000;,
 71.62500;53.24802;27.00000;,
 -71.62500;87.55832;27.00000;,
 -28.50473;90.56489;27.00000;,
 -28.50473;90.56492;12.54420;,
 -71.62500;87.55832;12.54420;,
 28.50382;96.57817;27.00000;,
 28.50382;96.57820;12.54420;,
 71.62500;96.57827;27.00000;,
 71.62500;96.57830;12.54420;,
 -28.50473;98.96442;-12.54420;,
 -71.62500;95.95779;-12.54420;,
 28.50382;104.97772;-12.54420;,
 71.62500;104.97785;-12.54420;,
 -28.50473;98.96445;-27.00000;,
 -71.62500;95.95779;-27.00000;,
 28.50382;104.97774;-27.00000;,
 71.62500;104.97785;-27.00000;,
 -71.62500;87.55832;27.00000;,
 -71.62500;87.55832;27.00000;,
 -71.62500;53.24802;27.00000;,
 -71.62500;53.24802;27.00000;,
 -71.62500;87.55832;27.00000;,
 -28.50473;90.56489;27.00000;,
 -28.50473;114.14402;27.00002;,
 -71.62500;114.14412;27.00002;,
 28.50382;96.57817;27.00000;,
 26.33892;127.02725;27.00000;,
 71.62500;96.57827;27.00000;,
 71.62500;127.88655;27.00002;,
 71.62500;96.57827;27.00000;,
 71.62500;96.57830;12.54420;,
 71.62500;134.37300;12.54422;,
 71.62500;127.88655;27.00002;,
 71.62500;123.77437;-12.54420;,
 71.62500;142.60733;-12.54418;,
 71.62500;129.33181;-27.00000;,
 71.62500;145.70371;-26.99998;,
 71.62500;129.33181;-27.00000;,
 28.50382;129.33169;-27.00000;,
 26.33892;145.07434;-27.00000;,
 71.62500;145.70371;-26.99998;,
 -28.50473;106.71655;-27.00000;,
 -28.50473;131.96128;-26.99998;,
 -71.62500;106.71665;-27.00000;,
 -71.62500;131.96138;-26.99998;,
 -71.62500;106.71665;-27.00000;,
 -71.62500;110.03194;-12.54420;,
 -71.62500;128.86494;-12.54418;,
 -71.62500;131.96138;-26.99998;,
 -71.62500;87.55832;12.54420;,
 -71.62500;120.63052;12.54422;,
 -71.62500;87.55832;27.00000;,
 -71.62500;114.14412;27.00002;,
 -71.62500;106.71665;-27.00000;,
 -28.50473;106.71655;-27.00000;,
 -28.50473;110.03184;-12.54420;,
 -71.62500;110.03194;-12.54420;,
 28.50382;129.33169;-27.00000;,
 28.50382;123.77425;-12.54420;,
 71.62500;129.33181;-27.00000;,
 71.62500;123.77437;-12.54420;,
 -28.50473;90.56492;12.54420;,
 -71.62500;87.55832;12.54420;,
 28.50382;96.57820;12.54420;,
 71.62500;96.57830;12.54420;,
 -28.50473;90.56489;27.00000;,
 -71.62500;87.55832;27.00000;,
 28.50382;96.57817;27.00000;,
 71.62500;96.57827;27.00000;,
 -71.62500;114.14412;27.00002;,
 -28.50473;114.14402;27.00002;,
 -28.50473;120.63042;12.54422;,
 -71.62500;120.63052;12.54422;,
 26.33892;127.02725;27.00000;,
 28.50382;134.37288;12.54422;,
 71.62500;127.88655;27.00002;,
 71.62500;134.37300;12.54422;,
 -28.50473;128.86485;-12.54418;,
 -71.62500;128.86494;-12.54418;,
 28.50382;142.60723;-12.54418;,
 71.62500;142.60733;-12.54418;,
 -28.50473;131.96128;-26.99998;,
 -71.62500;131.96138;-26.99998;,
 26.33892;145.07434;-27.00000;,
 71.62500;145.70371;-26.99998;,
 28.50382;104.97774;-27.00000;,
 -28.50473;95.98837;-27.00000;,
 -28.50473;106.71655;-27.00000;,
 28.50382;129.33169;-27.00000;,
 -71.62500;95.95779;-27.00000;,
 -71.62500;106.71665;-27.00000;,
 -71.62500;95.95779;-27.00000;,
 -71.62500;95.95779;-12.54420;,
 -71.62500;110.03194;-12.54420;,
 -71.62500;106.71665;-27.00000;,
 -28.50473;95.98837;-27.00000;,
 28.50382;104.97774;-27.00000;,
 71.62500;96.57830;12.54420;,
 -71.62500;95.95779;-12.54420;,
 -71.62500;110.03194;-12.54420;,
 -71.62500;87.55832;12.54420;,
 -28.81111;105.00781;-6.12098;,
 -71.62500;106.71665;-27.00000;,
 71.62500;96.57830;12.54420;,
 26.56804;113.04218;10.18137;,
 28.50382;129.33169;-27.00000;,
 -28.50473;106.71655;-27.00000;,
 71.62500;123.77437;-12.54420;,
 71.62500;129.33181;-27.00000;,
 71.62500;123.77437;-12.54420;,
 71.62500;96.57830;12.54420;,
 71.62500;104.97785;-12.54420;,
 71.62500;104.97785;-27.00000;,
 71.62500;129.33181;-27.00000;,
 71.62500;123.77437;-12.54420;,
 71.62500;104.97785;-27.00000;,
 71.62500;129.33181;-27.00000;,
 -71.62500;87.55832;12.54420;,
 -71.62500;106.71665;-27.00000;,
 71.62500;96.57830;12.54420;,
 -28.50473;95.98837;-27.00000;,
 -71.62500;87.55832;12.54420;,
 -28.50473;95.98837;-27.00000;,
 -71.62500;95.95779;-12.54420;,
 -71.62500;95.95779;-27.00000;,
 28.50382;104.97774;-27.00000;,
 71.62500;104.97785;-27.00000;,
 71.62500;104.97785;-12.54420;,
 71.62500;96.57830;12.54420;,
 71.62500;96.57830;12.54420;,
 -28.50473;95.98837;-27.00000;,
 -71.62500;87.55832;12.54420;,
 44.56587;176.24749;-27.00000;,
 71.62649;176.24761;-27.00000;,
 71.62500;145.07444;-27.00000;,
 26.33892;145.07434;-27.00000;,
 71.62649;176.24761;-27.00000;,
 71.62649;176.24761;27.00000;,
 71.62500;127.02735;27.00000;,
 71.62500;145.07444;-27.00000;,
 71.62649;176.24761;27.00000;,
 44.56587;176.24749;27.00000;,
 26.33892;127.02725;27.00000;,
 71.62500;127.02735;27.00000;,
 44.56587;176.24749;27.00000;,
 44.56587;176.24749;-27.00000;,
 26.33892;145.07434;-27.00000;,
 26.33892;127.02725;27.00000;,
 44.56587;176.24749;27.00000;,
 71.62649;176.24761;27.00000;,
 71.62649;176.24761;-27.00000;,
 44.56587;176.24749;-27.00000;,
 26.33892;145.07434;-27.00000;,
 71.62500;145.07444;-27.00000;,
 71.62500;127.02735;27.00000;,
 26.33892;127.02725;27.00000;,
 -32.08463;176.24749;-27.00000;,
 -6.02283;146.38645;-27.00000;,
 -28.50473;131.96128;-26.99998;,
 -49.19168;131.96128;-26.99998;,
 -32.08463;176.24749;27.00000;,
 -32.08463;176.24749;-27.00000;,
 -49.19168;131.96128;-26.99998;,
 -28.50473;114.14402;27.00002;,
 -32.08463;176.24749;27.00000;,
 -6.02283;138.28230;27.00000;,
 -6.02283;146.38645;-27.00000;,
 -32.08463;176.24749;-27.00000;,
 -49.19168;131.96128;-26.99998;,
 -28.50473;131.96128;-26.99998;,
 -6.02283;138.28230;27.00000;,
 -28.50473;114.14402;27.00002;,
 -6.02283;138.28230;27.00000;,
 -28.50473;131.96128;-26.99998;,
 -6.02283;146.38645;-27.00000;,
 -6.02283;138.28230;27.00000;,
 -32.08463;176.24749;27.00000;,
 -28.50473;114.14402;27.00002;,
 44.56587;176.24749;-27.00000;,
 44.56587;176.24749;27.00000;,
 -6.02283;138.28230;27.00000;,
 -6.02283;146.38645;-27.00000;,
 -32.08463;176.24749;27.00000;,
 -32.08463;176.24749;-27.00000;,
 -32.08463;176.24749;27.00000;,
 44.56587;176.24749;27.00000;,
 44.56587;176.24749;-27.00000;,
 -32.08463;176.24749;-27.00000;,
 -6.02283;138.28230;27.00000;,
 44.56587;176.24749;27.00000;,
 -32.08463;176.24749;27.00000;,
 -6.02283;146.38645;-27.00000;,
 -32.08463;176.24749;-27.00000;,
 44.56587;176.24749;-27.00000;,
 -16.17175;64.27794;-27.00000;,
 -46.38896;42.78697;27.00000;,
 -37.40355;46.56962;12.54420;,
 -37.40355;46.56962;-12.54420;,
 -16.17175;64.27794;-27.00000;,
 -37.40355;29.86270;-12.54420;,
 -31.43948;-0.12751;-27.00000;,
 -37.40355;29.86270;12.54420;,
 -46.38896;42.78697;27.00000;,
 -71.62500;-0.12740;27.00000;,
 -71.62500;60.76467;12.54420;,
 -71.62500;71.88935;-12.54420;,
 -71.62500;-0.12740;-27.00000;,
 -71.62500;-0.12740;27.00000;,
 -71.62500;60.76467;12.54420;,
 -46.38896;42.78697;27.00000;,
 -16.17175;64.27794;-27.00000;,
 -71.62500;71.88935;-12.54420;,
 -71.62500;53.25103;27.00000;,
 -71.62500;-0.12740;27.00000;,
 -46.38896;42.78697;27.00000;,
 -71.62500;53.25103;27.00000;,
 -71.62500;78.00000;-27.00000;,
 -31.43948;-0.12751;-27.00000;,
 -71.62500;78.00000;-27.00000;,
 -16.17175;64.27794;-27.00000;,
 -71.62500;60.76467;12.54420;,
 -71.62500;53.25103;27.00000;,
 -46.38896;42.78697;27.00000;,
 -71.62500;-0.12740;-27.00000;,
 -16.17175;64.27794;-27.00000;,
 -71.62500;78.00000;-27.00000;,
 -71.62500;-0.12740;27.00000;,
 -71.62500;-0.12740;-27.00000;,
 -31.43948;-0.12751;-27.00000;;
 
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
 4;115,117,118,116;,
 4;119,120,121,122;,
 4;120,123,124,121;,
 4;123,125,126,124;,
 4;127,128,129,130;,
 4;128,131,132,129;,
 4;131,133,134,132;,
 4;135,136,137,138;,
 4;136,139,140,137;,
 4;139,141,142,140;,
 4;143,144,145,146;,
 4;144,147,148,145;,
 4;147,149,150,148;,
 4;146,145,151,152;,
 4;145,148,153,151;,
 4;148,150,154,153;,
 4;152,151,155,156;,
 4;151,153,157,155;,
 4;153,154,158,157;,
 4;159,160,161,162;,
 4;160,163,164,161;,
 4;163,165,166,164;,
 4;162,161,167,168;,
 4;161,164,169,167;,
 4;164,166,170,169;,
 4;168,167,171,172;,
 4;167,169,173,171;,
 4;169,170,174,173;,
 4;175,176,177,178;,
 4;176,179,180,177;,
 4;181,182,183,184;,
 4;185,186,187,188;,
 4;189,190,191,192;,
 4;190,193,194,191;,
 4;191,194,195,196;,
 4;194,197,198,195;,
 3;199,200,201;,
 3;199,202,203;,
 3;204,194,193;,
 3;202,199,201;,
 3;205,175,178;,
 3;178,206,205;,
 3;207,183,182;,
 3;208,191,196;,
 3;209,190,210;,
 3;211,188,187;,
 3;212,213,214;,
 3;215,216,217;,
 3;218,186,217;,
 3;219,220,221;,
 4;222,223,224,225;,
 4;226,227,228,229;,
 4;230,231,232,233;,
 4;234,235,236,237;,
 4;238,239,240,241;,
 4;242,243,244,245;,
 4;246,247,248,249;,
 4;250,251,252,253;,
 4;254,255,256,257;,
 4;258,259,260,261;,
 3;262,263,264;,
 3;265,266,267;,
 4;268,269,270,271;,
 4;272,273,271,270;,
 4;274,275,276,277;,
 3;278,279,280;,
 3;281,282,283;,
 4;284,285,286,287;,
 4;288,287,289,290;,
 4;287,286,291,289;,
 4;286,292,293,291;,
 4;289,291,293,290;,
 4;294,295,296,297;,
 4;298,299,300,301;,
 3;297,302,294;,
 3;303,304,305;,
 3;296,295,306;,
 3;307,308,309;,
 3;310,311,312;,
 3;308,307,313;,
 3;314,315,301;,
 3;316,317,318;;
 
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
  1,
  0,
  2,
  3,
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
    "texture\\bill003.jpg";
   }
  }
  Material {
   0.800000;0.800000;0.800000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
   TextureFilename {
    "texture\\bill003.jpg";
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
 }
 MeshNormals {
  156;
  -0.272225;0.886302;0.374651;,
  -0.137417;0.912350;0.385662;,
  1.000000;0.000000;0.000000;,
  -0.925585;0.321486;-0.199848;,
  0.000000;0.000000;1.000000;,
  -0.649555;0.668472;-0.362247;,
  -0.118490;0.928136;0.352878;,
  -0.129467;0.916119;0.379425;,
  -0.753992;0.401430;-0.519951;,
  -0.061634;0.885614;0.460314;,
  -0.000002;0.887301;0.461190;,
  -0.000002;0.901163;0.433481;,
  -0.241104;0.910831;0.335046;,
  -0.256765;0.898919;0.354988;,
  -0.000002;0.917658;0.397371;,
  -0.000002;0.921088;0.389355;,
  0.000001;-1.000000;0.000001;,
  -0.421108;0.906948;-0.010644;,
  -0.968441;0.229575;0.097044;,
  0.000000;0.000000;-1.000000;,
  0.000000;0.000000;-1.000000;,
  -0.000002;-0.887226;-0.461335;,
  -0.069557;0.997578;0.000001;,
  0.000000;0.000000;1.000000;,
  1.000000;0.000000;0.000000;,
  0.000000;0.000000;-1.000000;,
  -1.000000;0.000000;0.000000;,
  -0.000001;-0.917693;-0.397289;,
  0.000001;-0.917693;-0.397289;,
  -0.000001;-0.901127;-0.433555;,
  0.000001;-0.901127;-0.433555;,
  -0.086115;0.983310;0.160267;,
  -0.051848;0.985651;0.160639;,
  -0.086116;0.983310;0.160267;,
  -0.051848;0.985651;0.160638;,
  -0.000002;-0.921156;-0.389193;,
  -0.000001;-0.921157;-0.389193;,
  -0.000002;-0.917693;-0.397289;,
  0.000001;-0.921157;-0.389193;,
  0.000002;-0.921156;-0.389193;,
  0.000002;-0.917693;-0.397290;,
  -0.000002;-0.901127;-0.433555;,
  0.000002;-0.901127;-0.433555;,
  -0.000001;-0.887226;-0.461336;,
  0.000001;-0.887226;-0.461336;,
  0.000002;-0.887226;-0.461335;,
  -0.087241;0.996187;0.000001;,
  -0.068656;0.984650;0.160472;,
  -0.052523;0.998620;0.000002;,
  -0.000002;1.000000;0.000002;,
  -0.000002;0.986982;0.160833;,
  -0.068656;0.984650;0.160472;,
  -0.000003;0.986982;0.160832;,
  -0.087242;0.996187;0.000001;,
  -0.069558;0.997578;0.000001;,
  -0.052523;0.998620;0.000001;,
  -0.000003;1.000000;0.000000;,
  0.000000;-0.000001;1.000000;,
  0.000000;-0.000001;1.000000;,
  0.000000;-0.000000;1.000000;,
  -0.000000;-0.000000;1.000000;,
  1.000000;0.000000;0.000000;,
  -0.000000;0.000001;-1.000000;,
  -0.000000;0.000001;-1.000000;,
  0.000000;0.000001;-1.000000;,
  -1.000000;0.000000;0.000000;,
  0.123358;-0.940783;-0.315770;,
  0.111639;-0.869079;-0.481912;,
  0.086318;-0.932650;-0.350304;,
  0.061681;-0.922499;-0.381040;,
  -0.109453;0.926051;0.361178;,
  -0.111600;0.923707;0.366483;,
  -0.113891;0.959276;0.258493;,
  -0.115631;0.960377;0.253585;,
  0.000000;0.000001;-1.000000;,
  -0.000002;-0.974696;0.223536;,
  0.153600;-0.984679;0.082548;,
  0.014486;-0.972464;-0.232601;,
  0.153730;-0.964371;-0.215303;,
  0.000003;-0.933399;-0.358840;,
  0.000002;-0.827388;-0.561631;,
  0.050799;-0.938857;-0.340540;,
  0.000002;-0.915983;-0.401217;,
  0.087241;-0.996187;-0.000001;,
  0.069557;-0.997578;-0.000001;,
  0.052523;-0.998620;-0.000002;,
  0.000002;-1.000000;-0.000002;,
  0.000002;0.912363;0.409382;,
  -0.106245;0.905252;0.411377;,
  0.000002;0.932523;0.361110;,
  -0.110457;0.899979;0.421706;,
  -0.008471;0.902652;0.430288;,
  -0.004245;0.928292;0.371828;,
  0.000002;0.965334;0.261016;,
  -0.003433;0.967888;0.251359;,
  -0.115117;0.971683;0.206352;,
  0.000002;0.977820;0.209449;,
  -0.118523;0.973329;0.196426;,
  -0.006849;0.981785;0.189870;,
  -0.044879;0.908374;0.415743;,
  0.000000;0.000000;-1.000000;,
  0.076140;-0.968020;-0.239038;,
  1.000000;0.000000;0.000000;,
  -0.008105;0.925036;0.379793;,
  0.101281;0.818121;0.566056;,
  -1.000000;0.000000;0.000000;,
  -0.099215;0.929142;0.356162;,
  -0.066771;0.827281;0.557806;,
  0.046419;-0.993163;-0.107111;,
  0.061157;-0.984230;-0.165985;,
  0.045813;-0.985007;-0.166318;,
  0.075442;0.964830;0.251816;,
  0.037891;0.985154;0.167440;,
  0.000954;0.809517;0.587096;,
  -0.160779;0.937619;0.308255;,
  -0.156842;0.975040;0.157156;,
  0.061146;-0.971088;-0.230759;,
  0.000709;-1.000000;-0.000000;,
  0.000003;-1.000000;-0.000000;,
  0.053690;-0.985632;-0.160148;,
  -0.062199;0.987802;0.142757;,
  0.000000;0.000000;-1.000000;,
  1.000000;-0.000039;-0.000005;,
  0.000000;0.000000;1.000000;,
  -0.902307;0.427180;0.057958;,
  -0.000005;1.000000;0.000000;,
  0.000002;-0.948435;-0.316972;,
  -0.000000;-0.000001;-1.000000;,
  0.789477;0.612312;0.042425;,
  -0.971231;0.158963;0.177315;,
  0.387164;-0.875581;-0.288897;,
  0.464408;-0.860746;-0.208426;,
  0.535772;-0.835011;-0.125316;,
  0.000001;0.000000;1.000000;,
  -0.789477;-0.612312;-0.042425;,
  0.553971;-0.830386;-0.059787;,
  0.000000;1.000000;0.000000;,
  0.000000;-0.000000;1.000000;,
  0.000000;0.000000;-1.000000;,
  -1.000000;0.000000;0.000000;,
  0.766579;-0.302037;0.566683;,
  0.798486;-0.185507;0.572719;,
  0.909204;-0.128296;0.396091;,
  0.924426;-0.159777;0.346278;,
  0.895349;-0.209479;0.393024;,
  0.908920;-0.239221;0.341523;,
  0.798909;-0.345060;0.492624;,
  0.833336;-0.231590;0.501914;,
  0.304485;0.845150;0.439330;,
  0.242905;0.877874;0.412717;,
  0.000000;-0.000000;1.000000;,
  0.000000;0.000000;-1.000000;,
  0.345289;0.832729;0.432825;,
  0.000000;0.000000;-1.000000;,
  0.222226;0.898056;0.379620;,
  -0.000003;-1.000000;0.000000;;
  139;
  4;2,2,2,2;,
  4;2,2,2,2;,
  4;2,2,2,2;,
  4;2,2,2,2;,
  4;2,2,2,2;,
  4;4,4,4,4;,
  4;5,3,3,8;,
  4;9,10,11,6;,
  4;12,6,7,13;,
  4;6,11,14,7;,
  4;13,7,1,0;,
  4;7,14,15,1;,
  4;16,16,16,16;,
  3;2,2,2;,
  3;8,17,5;,
  3;4,4,4;,
  3;3,3,18;,
  3;19,19,19;,
  3;19,19,20;,
  3;2,2,2;,
  3;17,6,5;,
  3;6,17,9;,
  3;19,19,19;,
  4;23,23,23,23;,
  4;23,23,23,23;,
  4;24,24,24,24;,
  4;24,24,24,24;,
  4;24,24,24,24;,
  4;25,25,25,25;,
  4;25,25,25,25;,
  4;25,25,25,25;,
  4;26,26,26,26;,
  4;26,26,26,26;,
  4;35,36,27,37;,
  4;36,38,28,27;,
  4;38,39,40,28;,
  4;37,27,29,41;,
  4;27,28,30,29;,
  4;28,40,42,30;,
  4;41,29,43,21;,
  4;29,30,44,43;,
  4;30,42,45,44;,
  4;22,46,31,47;,
  4;46,48,32,31;,
  4;48,49,50,32;,
  4;47,31,33,51;,
  4;31,32,34,33;,
  4;32,50,52,34;,
  4;51,33,53,54;,
  4;33,34,55,53;,
  4;34,52,56,55;,
  3;23,23,23;,
  3;26,26,26;,
  3;23,23,23;,
  3;26,26,26;,
  4;57,58,58,57;,
  4;58,59,59,58;,
  4;59,60,60,59;,
  4;61,61,61,61;,
  4;61,61,61,61;,
  4;61,61,61,61;,
  4;74,62,62,74;,
  4;62,63,63,62;,
  4;63,64,64,63;,
  4;65,65,65,65;,
  4;65,65,65,65;,
  4;65,65,65,65;,
  4;75,76,66,77;,
  4;76,78,67,66;,
  4;78,79,80,67;,
  4;77,66,68,81;,
  4;66,67,69,68;,
  4;67,80,82,69;,
  4;81,68,83,84;,
  4;68,69,85,83;,
  4;69,82,86,85;,
  4;87,88,70,89;,
  4;88,90,71,70;,
  4;90,91,92,71;,
  4;89,70,72,93;,
  4;70,71,73,72;,
  4;71,92,94,73;,
  4;93,72,95,96;,
  4;72,73,97,95;,
  4;73,94,98,97;,
  4;100,100,100,100;,
  4;100,100,100,100;,
  4;105,105,105,105;,
  4;108,109,101,110;,
  4;111,99,106,112;,
  4;99,113,107,106;,
  4;106,107,114,115;,
  4;107,104,103,114;,
  3;102,102,102;,
  3;102,102,102;,
  3;104,107,113;,
  3;102,102,102;,
  3;100,100,100;,
  3;100,100,100;,
  3;105,105,105;,
  3;112,106,115;,
  3;101,116,108;,
  3;116,110,101;,
  3;108,110,117;,
  3;109,118,119;,
  3;101,109,119;,
  3;113,120,99;,
  4;121,121,121,121;,
  4;122,122,122,122;,
  4;123,123,123,123;,
  4;124,124,124,124;,
  4;125,125,125,125;,
  4;126,126,126,126;,
  4;127,127,127,127;,
  4;129,129,129,129;,
  4;128,128,128,128;,
  4;130,131,131,130;,
  3;131,131,132;,
  3;133,133,133;,
  4;135,135,135,135;,
  4;134,134,134,134;,
  4;136,136,136,136;,
  3;137,137,137;,
  3;138,138,138;,
  4;141,147,143,142;,
  4;141,142,144,140;,
  4;142,143,145,144;,
  4;143,147,146,145;,
  4;144,145,146,140;,
  4;139,139,139,139;,
  4;148,148,149,149;,
  3;139,139,139;,
  3;150,150,150;,
  3;139,139,139;,
  3;151,151,151;,
  3;148,152,148;,
  3;151,151,153;,
  3;149,154,149;,
  3;155,155,155;;
 }
 MeshTextureCoords {
  319;
  0.423975;0.198604;,
  0.576025;0.272769;,
  0.576025;0.367402;,
  0.423975;0.367402;,
  0.336364;0.157867;,
  0.423975;0.478781;,
  0.336364;0.678716;,
  0.576025;0.478781;,
  0.663636;0.322860;,
  0.663636;0.678716;,
  0.690025;0.324327;,
  0.190740;0.394087;,
  0.022500;0.680183;,
  0.977500;0.680183;,
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
  -1.071974;-0.850000;,
  4.081250;-0.850000;,
  4.081250;1.850000;,
  -3.081250;1.850000;,
  0.859710;0.851260;,
  0.977500;0.324326;,
  0.140290;0.686630;,
  0.290403;0.680183;,
  0.392188;0.250814;,
  0.690025;0.159334;,
  0.977500;0.680183;,
  0.977500;0.159333;,
  0.166670;0.000000;,
  0.500000;0.333330;,
  0.333330;0.000000;,
  0.309968;0.324347;,
  0.690025;0.324347;,
  0.690025;0.035479;,
  0.309968;0.075567;,
  0.977500;0.324347;,
  0.977500;0.035478;,
  0.663636;0.322880;,
  0.576025;0.272769;,
  0.576025;0.034011;,
  0.663636;0.034012;,
  0.423975;0.198604;,
  0.423975;-0.021986;,
  0.336364;0.157887;,
  0.336364;-0.021986;,
  0.977500;0.159353;,
  0.690025;0.159354;,
  0.690025;-0.020518;,
  0.977500;-0.020519;,
  0.309968;0.159354;,
  0.309968;0.019570;,
  0.022500;0.159353;,
  0.022500;0.039615;,
  0.336364;0.157887;,
  0.423975;0.198604;,
  0.423975;0.038148;,
  0.336364;0.038148;,
  0.576025;0.272769;,
  0.576025;0.094145;,
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
  0.022500;0.095611;,
  0.663636;0.094145;,
  0.022500;0.324347;,
  0.663636;0.322880;,
  0.022500;0.095611;,
  0.309968;0.075567;,
  0.309968;-0.081627;,
  0.022500;-0.081627;,
  0.690025;0.035479;,
  0.675593;-0.167515;,
  0.977500;0.035478;,
  0.977500;-0.173244;,
  0.663636;0.034012;,
  0.576025;0.034011;,
  0.576026;-0.217953;,
  0.663637;-0.174710;,
  0.423975;-0.147296;,
  0.423975;-0.272849;,
  0.336364;-0.184345;,
  0.336364;-0.293491;,
  0.977500;-0.182879;,
  0.690025;-0.182878;,
  0.675593;-0.287829;,
  0.977500;-0.292025;,
  0.309968;-0.032110;,
  0.309968;-0.200409;,
  0.022500;-0.032111;,
  0.022500;-0.200409;,
  0.336364;-0.033578;,
  0.423975;-0.055680;,
  0.423975;-0.181233;,
  0.336364;-0.201876;,
  0.576025;0.094145;,
  0.576026;-0.126337;,
  0.663636;0.094145;,
  0.663637;-0.083094;,
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
  0.690025;-0.020518;,
  0.309968;0.039411;,
  0.309968;-0.032110;,
  0.690025;-0.182878;,
  0.022500;0.039615;,
  0.022500;-0.032111;,
  0.336364;0.038148;,
  0.423975;0.038148;,
  0.423975;-0.055680;,
  0.336364;-0.033578;,
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
  0.423975;-0.147296;,
  0.576025;0.034011;,
  0.423975;-0.021986;,
  0.336364;-0.021986;,
  0.336364;-0.184345;,
  1.000000;0.500000;,
  0.977500;-0.020519;,
  0.977500;-0.182879;,
  0.576025;0.094145;,
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
  0.797106;-0.495650;,
  0.977510;-0.495651;,
  0.977500;-0.287830;,
  0.675593;-0.287829;,
  0.336364;-0.497117;,
  0.663636;-0.497117;,
  0.663636;-0.168982;,
  0.336364;-0.289296;,
  0.977510;-0.495651;,
  0.797106;-0.495650;,
  0.675593;-0.167515;,
  0.977500;-0.167516;,
  0.859710;0.023860;,
  0.140290;0.023860;,
  0.140290;0.149180;,
  0.859710;0.269230;,
  2.728293;1.850000;,
  4.081325;1.850000;,
  4.081325;-0.850000;,
  2.728293;-0.850000;,
  0.140290;0.423860;,
  0.859710;0.423860;,
  0.859710;0.423860;,
  0.140290;0.423860;,
  0.286102;-0.495650;,
  0.459848;-0.296576;,
  0.309968;-0.200409;,
  0.172055;-0.200409;,
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
  0.459848;-0.242549;,
  0.286102;-0.495650;,
  0.309968;-0.081627;,
  0.761290;0.020000;,
  0.761290;0.020000;,
  0.464690;0.194360;,
  0.464690;0.140450;,
  0.311880;0.020000;,
  0.311880;0.020000;,
  -1.104231;1.850000;,
  2.728293;1.850000;,
  2.728293;-0.850000;,
  -1.104231;-0.850000;,
  0.459848;-0.242549;,
  0.797106;-0.495650;,
  0.286102;-0.495650;,
  0.459848;-0.296576;,
  0.286102;-0.495650;,
  0.797106;-0.495650;,
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
  0.576025;0.272769;,
  0.423975;0.198604;,
  0.336364;0.678716;,
  0.663636;0.678716;,
  0.666670;0.333330;,
  1.000000;0.333330;,
  1.000000;0.666670;,
  0.666670;0.666670;,
  0.663636;0.322860;,
  0.022500;0.680183;,
  0.190740;0.394087;,
  0.022500;0.324326;,
  0.336364;0.157867;,
  0.290403;0.680183;,
  0.022500;0.159333;,
  0.392188;0.250814;,
  0.166670;0.333330;,
  0.000000;0.000000;,
  0.333330;0.000000;,
  0.022500;0.680183;,
  1.000000;0.833330;,
  0.666670;1.000000;,
  -3.081250;1.850000;,
  -3.081250;-0.850000;,
  -1.071974;-0.850000;;
 }
}
