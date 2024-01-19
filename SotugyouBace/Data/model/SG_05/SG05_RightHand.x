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
 300;
 1.14420;0.11841;-2.93500;,
 1.14420;-6.50667;-2.93500;,
 -1.43872;-6.50667;-2.93500;,
 -1.43872;0.11841;-2.93500;,
 -1.43872;0.11841;-2.93500;,
 -1.43872;-6.50667;-2.93500;,
 -1.43872;-6.50667;2.93500;,
 -1.43872;0.11841;2.93500;,
 -1.43872;0.11841;2.93500;,
 -1.43872;-6.50667;2.93500;,
 1.14420;-6.50667;2.93500;,
 1.14420;0.11841;2.93500;,
 1.14420;0.11841;2.93500;,
 1.14420;-6.50667;2.93500;,
 1.14420;-6.50667;-2.93500;,
 1.14420;0.11841;-2.93500;,
 1.14420;0.11841;-2.93500;,
 -1.43872;0.11841;-2.93500;,
 1.14420;-6.50667;-2.93500;,
 -1.43872;-6.50667;-2.93500;,
 0.03726;-6.52929;-2.77913;,
 3.90819;-6.05400;-2.77913;,
 4.12025;-7.78102;-2.77913;,
 0.24930;-8.25633;-2.77913;,
 0.24930;-8.25633;-2.77913;,
 4.12025;-7.78102;-2.77913;,
 4.12025;-7.78102;-1.61773;,
 0.24930;-8.25633;-1.61773;,
 0.24930;-8.25633;-1.61773;,
 4.12025;-7.78102;-1.61773;,
 3.90819;-6.05400;-1.61773;,
 0.03726;-6.52929;-1.61773;,
 0.03726;-6.52929;-1.61773;,
 3.90819;-6.05400;-1.61773;,
 3.90819;-6.05400;-2.77913;,
 0.03726;-6.52929;-2.77913;,
 0.03726;-6.52929;-2.77913;,
 0.24930;-8.25633;-2.77913;,
 3.90819;-6.05400;-2.77913;,
 4.12025;-7.78102;-2.77913;,
 3.08759;-6.60805;-2.77913;,
 2.54412;-4.25382;-2.77913;,
 4.23947;-3.86242;-2.77913;,
 4.78303;-6.21662;-2.77913;,
 4.78303;-6.21662;-2.77913;,
 4.23947;-3.86242;-2.77913;,
 4.23947;-3.86242;-1.61773;,
 4.78303;-6.21662;-1.61773;,
 4.78303;-6.21662;-1.61773;,
 4.23947;-3.86242;-1.61773;,
 2.54412;-4.25382;-1.61773;,
 3.08759;-6.60805;-1.61773;,
 3.08759;-6.60805;-1.61773;,
 2.54412;-4.25382;-1.61773;,
 2.54412;-4.25382;-2.77913;,
 3.08759;-6.60805;-2.77913;,
 3.08759;-6.60805;-2.77913;,
 4.78303;-6.21662;-2.77913;,
 2.54412;-4.25382;-2.77913;,
 4.23947;-3.86242;-2.77913;,
 2.95959;-4.73977;-2.77913;,
 1.27292;-4.69559;-2.77913;,
 1.31852;-2.95620;-2.77913;,
 3.00512;-3.00033;-2.77913;,
 3.00512;-3.00033;-2.77913;,
 1.31852;-2.95620;-2.77913;,
 1.31852;-2.95620;-1.61773;,
 3.00512;-3.00033;-1.61773;,
 3.00512;-3.00033;-1.61773;,
 1.31852;-2.95620;-1.61773;,
 1.27292;-4.69559;-1.61773;,
 2.95959;-4.73977;-1.61773;,
 2.95959;-4.73977;-1.61773;,
 1.27292;-4.69559;-1.61773;,
 1.27292;-4.69559;-2.77913;,
 2.95959;-4.73977;-2.77913;,
 2.95959;-4.73977;-2.77913;,
 3.00512;-3.00033;-2.77913;,
 1.27292;-4.69559;-2.77913;,
 1.31852;-2.95620;-2.77913;,
 0.03726;-6.52929;-1.35223;,
 3.90819;-6.05400;-1.35223;,
 4.12025;-7.78102;-1.35223;,
 0.24930;-8.25633;-1.35223;,
 0.24930;-8.25633;-1.35223;,
 4.12025;-7.78102;-1.35223;,
 4.12025;-7.78102;-0.19083;,
 0.24930;-8.25633;-0.19083;,
 0.24930;-8.25633;-0.19083;,
 4.12025;-7.78102;-0.19083;,
 3.90819;-6.05400;-0.19083;,
 0.03726;-6.52929;-0.19083;,
 0.03726;-6.52929;-0.19083;,
 3.90819;-6.05400;-0.19083;,
 3.90819;-6.05400;-1.35223;,
 0.03726;-6.52929;-1.35223;,
 0.03726;-6.52929;-1.35223;,
 0.24930;-8.25633;-1.35223;,
 3.90819;-6.05400;-1.35223;,
 4.12025;-7.78102;-1.35223;,
 3.08759;-6.60805;-1.35223;,
 2.54412;-4.25382;-1.35223;,
 4.23947;-3.86242;-1.35223;,
 4.78303;-6.21662;-1.35223;,
 4.78303;-6.21662;-1.35223;,
 4.23947;-3.86242;-1.35223;,
 4.23947;-3.86242;-0.19083;,
 4.78303;-6.21662;-0.19083;,
 4.78303;-6.21662;-0.19083;,
 4.23947;-3.86242;-0.19083;,
 2.54412;-4.25382;-0.19083;,
 3.08759;-6.60805;-0.19083;,
 3.08759;-6.60805;-0.19083;,
 2.54412;-4.25382;-0.19083;,
 2.54412;-4.25382;-1.35223;,
 3.08759;-6.60805;-1.35223;,
 3.08759;-6.60805;-1.35223;,
 4.78303;-6.21662;-1.35223;,
 2.54412;-4.25382;-1.35223;,
 4.23947;-3.86242;-1.35223;,
 2.95959;-4.73977;-1.35223;,
 1.27292;-4.69559;-1.35223;,
 1.31852;-2.95620;-1.35223;,
 3.00512;-3.00033;-1.35223;,
 3.00512;-3.00033;-1.35223;,
 1.31852;-2.95620;-1.35223;,
 1.31852;-2.95620;-0.19083;,
 3.00512;-3.00033;-0.19083;,
 3.00512;-3.00033;-0.19083;,
 1.31852;-2.95620;-0.19083;,
 1.27292;-4.69559;-0.19083;,
 2.95959;-4.73977;-0.19083;,
 2.95959;-4.73977;-0.19083;,
 1.27292;-4.69559;-0.19083;,
 1.27292;-4.69559;-1.35223;,
 2.95959;-4.73977;-1.35223;,
 2.95959;-4.73977;-1.35223;,
 3.00512;-3.00033;-1.35223;,
 1.27292;-4.69559;-1.35223;,
 1.31852;-2.95620;-1.35223;,
 0.03726;-6.52929;0.10719;,
 3.90819;-6.05400;0.10719;,
 4.12025;-7.78102;0.10719;,
 0.24930;-8.25633;0.10719;,
 0.24930;-8.25633;0.10719;,
 4.12025;-7.78102;0.10719;,
 4.12025;-7.78102;1.26859;,
 0.24930;-8.25633;1.26859;,
 0.24930;-8.25633;1.26859;,
 4.12025;-7.78102;1.26859;,
 3.90819;-6.05400;1.26859;,
 0.03726;-6.52929;1.26859;,
 0.03726;-6.52929;1.26859;,
 3.90819;-6.05400;1.26859;,
 3.90819;-6.05400;0.10719;,
 0.03726;-6.52929;0.10719;,
 0.03726;-6.52929;0.10719;,
 0.24930;-8.25633;0.10719;,
 3.90819;-6.05400;0.10719;,
 4.12025;-7.78102;0.10719;,
 3.08759;-6.60805;0.10719;,
 2.54412;-4.25382;0.10719;,
 4.23947;-3.86242;0.10719;,
 4.78303;-6.21662;0.10719;,
 4.78303;-6.21662;0.10719;,
 4.23947;-3.86242;0.10719;,
 4.23947;-3.86242;1.26859;,
 4.78303;-6.21662;1.26859;,
 4.78303;-6.21662;1.26859;,
 4.23947;-3.86242;1.26859;,
 2.54412;-4.25382;1.26859;,
 3.08759;-6.60805;1.26859;,
 3.08759;-6.60805;1.26859;,
 2.54412;-4.25382;1.26859;,
 2.54412;-4.25382;0.10719;,
 3.08759;-6.60805;0.10719;,
 3.08759;-6.60805;0.10719;,
 4.78303;-6.21662;0.10719;,
 2.54412;-4.25382;0.10719;,
 4.23947;-3.86242;0.10719;,
 2.95959;-4.73977;0.10719;,
 1.27292;-4.69559;0.10719;,
 1.31852;-2.95620;0.10719;,
 3.00512;-3.00033;0.10719;,
 3.00512;-3.00033;0.10719;,
 1.31852;-2.95620;0.10719;,
 1.31852;-2.95620;1.26859;,
 3.00512;-3.00033;1.26859;,
 3.00512;-3.00033;1.26859;,
 1.31852;-2.95620;1.26859;,
 1.27292;-4.69559;1.26859;,
 2.95959;-4.73977;1.26859;,
 2.95959;-4.73977;1.26859;,
 1.27292;-4.69559;1.26859;,
 1.27292;-4.69559;0.10719;,
 2.95959;-4.73977;0.10719;,
 2.95959;-4.73977;0.10719;,
 3.00512;-3.00033;0.10719;,
 1.27292;-4.69559;0.10719;,
 1.31852;-2.95620;0.10719;,
 0.03726;-6.52929;1.50084;,
 3.90819;-6.05400;1.50084;,
 4.12025;-7.78102;1.50084;,
 0.24930;-8.25633;1.50084;,
 0.24930;-8.25633;1.50084;,
 4.12025;-7.78102;1.50084;,
 4.12025;-7.78102;2.66224;,
 0.24930;-8.25633;2.66224;,
 0.24930;-8.25633;2.66224;,
 4.12025;-7.78102;2.66224;,
 3.90819;-6.05400;2.66224;,
 0.03726;-6.52929;2.66224;,
 0.03726;-6.52929;2.66224;,
 3.90819;-6.05400;2.66224;,
 3.90819;-6.05400;1.50084;,
 0.03726;-6.52929;1.50084;,
 0.03726;-6.52929;1.50084;,
 0.24930;-8.25633;1.50084;,
 3.90819;-6.05400;1.50084;,
 4.12025;-7.78102;1.50084;,
 3.08759;-6.60805;1.50084;,
 2.54412;-4.25382;1.50084;,
 4.23947;-3.86242;1.50084;,
 4.78303;-6.21662;1.50084;,
 4.78303;-6.21662;1.50084;,
 4.23947;-3.86242;1.50084;,
 4.23947;-3.86242;2.66224;,
 4.78303;-6.21662;2.66224;,
 4.78303;-6.21662;2.66224;,
 4.23947;-3.86242;2.66224;,
 2.54412;-4.25382;2.66224;,
 3.08759;-6.60805;2.66224;,
 3.08759;-6.60805;2.66224;,
 2.54412;-4.25382;2.66224;,
 2.54412;-4.25382;1.50084;,
 3.08759;-6.60805;1.50084;,
 3.08759;-6.60805;1.50084;,
 4.78303;-6.21662;1.50084;,
 2.54412;-4.25382;1.50084;,
 4.23947;-3.86242;1.50084;,
 2.95959;-4.73977;1.50084;,
 1.27292;-4.69559;1.50084;,
 1.31852;-2.95620;1.50084;,
 3.00512;-3.00033;1.50084;,
 3.00512;-3.00033;1.50084;,
 1.31852;-2.95620;1.50084;,
 1.31852;-2.95620;2.66224;,
 3.00512;-3.00033;2.66224;,
 3.00512;-3.00033;2.66224;,
 1.31852;-2.95620;2.66224;,
 1.27292;-4.69559;2.66224;,
 2.95959;-4.73977;2.66224;,
 2.95959;-4.73977;2.66224;,
 1.27292;-4.69559;2.66224;,
 1.27292;-4.69559;1.50084;,
 2.95959;-4.73977;1.50084;,
 2.95959;-4.73977;1.50084;,
 3.00512;-3.00033;1.50084;,
 1.27292;-4.69559;1.50084;,
 1.31852;-2.95620;1.50084;,
 0.85385;0.35370;-3.80982;,
 3.00641;-2.83316;-4.45819;,
 1.55546;-3.77428;-4.64966;,
 -0.59710;-0.58742;-4.00129;,
 -0.59710;-0.58742;-4.00129;,
 1.55546;-3.77428;-4.64966;,
 1.55546;-3.97365;-3.66974;,
 -0.59710;-0.78679;-3.02136;,
 -0.59710;-0.78679;-3.02136;,
 1.55546;-3.97365;-3.66974;,
 3.00641;-3.03253;-3.47827;,
 0.85385;0.15431;-2.82989;,
 0.85385;0.15431;-2.82989;,
 3.00641;-3.03253;-3.47827;,
 3.00641;-2.83316;-4.45819;,
 0.85385;0.35370;-3.80982;,
 0.85385;0.35370;-3.80982;,
 -0.59710;-0.58742;-4.00129;,
 3.00641;-2.83316;-4.45819;,
 1.55546;-3.77428;-4.64966;,
 3.09105;-3.26632;-4.53260;,
 4.52820;-5.32542;-3.84363;,
 3.07725;-6.23616;-3.53890;,
 1.64008;-4.17705;-4.22786;,
 1.64008;-4.17705;-4.22786;,
 3.07725;-6.23616;-3.53890;,
 3.07725;-5.91885;-2.59057;,
 1.64008;-3.85974;-3.27954;,
 1.64008;-3.85974;-3.27954;,
 3.07725;-5.91885;-2.59057;,
 4.52820;-5.00811;-2.89530;,
 3.09105;-2.94901;-3.58427;,
 3.09105;-2.94901;-3.58427;,
 4.52820;-5.00811;-2.89530;,
 4.52820;-5.32542;-3.84363;,
 3.09105;-3.26632;-4.53260;,
 3.09105;-3.26632;-4.53260;,
 1.64008;-4.17705;-4.22786;,
 4.52820;-5.32542;-3.84363;,
 3.07725;-6.23616;-3.53890;;
 
 90;
 4;0,1,2,3;,
 4;4,5,6,7;,
 4;8,9,10,11;,
 4;12,13,14,15;,
 4;12,16,17,7;,
 4;18,13,6,19;,
 4;20,21,22,23;,
 4;24,25,26,27;,
 4;28,29,30,31;,
 4;32,33,34,35;,
 4;32,36,37,27;,
 4;38,33,26,39;,
 4;40,41,42,43;,
 4;44,45,46,47;,
 4;48,49,50,51;,
 4;52,53,54,55;,
 4;52,56,57,47;,
 4;58,53,46,59;,
 4;60,61,62,63;,
 4;64,65,66,67;,
 4;68,69,70,71;,
 4;72,73,74,75;,
 4;72,76,77,67;,
 4;78,73,66,79;,
 4;80,81,82,83;,
 4;84,85,86,87;,
 4;88,89,90,91;,
 4;92,93,94,95;,
 4;92,96,97,87;,
 4;98,93,86,99;,
 4;100,101,102,103;,
 4;104,105,106,107;,
 4;108,109,110,111;,
 4;112,113,114,115;,
 4;112,116,117,107;,
 4;118,113,106,119;,
 4;120,121,122,123;,
 4;124,125,126,127;,
 4;128,129,130,131;,
 4;132,133,134,135;,
 4;132,136,137,127;,
 4;138,133,126,139;,
 4;140,141,142,143;,
 4;144,145,146,147;,
 4;148,149,150,151;,
 4;152,153,154,155;,
 4;152,156,157,147;,
 4;158,153,146,159;,
 4;160,161,162,163;,
 4;164,165,166,167;,
 4;168,169,170,171;,
 4;172,173,174,175;,
 4;172,176,177,167;,
 4;178,173,166,179;,
 4;180,181,182,183;,
 4;184,185,186,187;,
 4;188,189,190,191;,
 4;192,193,194,195;,
 4;192,196,197,187;,
 4;198,193,186,199;,
 4;200,201,202,203;,
 4;204,205,206,207;,
 4;208,209,210,211;,
 4;212,213,214,215;,
 4;212,216,217,207;,
 4;218,213,206,219;,
 4;220,221,222,223;,
 4;224,225,226,227;,
 4;228,229,230,231;,
 4;232,233,234,235;,
 4;232,236,237,227;,
 4;238,233,226,239;,
 4;240,241,242,243;,
 4;244,245,246,247;,
 4;248,249,250,251;,
 4;252,253,254,255;,
 4;252,256,257,247;,
 4;258,253,246,259;,
 4;260,261,262,263;,
 4;264,265,266,267;,
 4;268,269,270,271;,
 4;272,273,274,275;,
 4;272,276,277,267;,
 4;278,273,266,279;,
 4;280,281,282,283;,
 4;284,285,286,287;,
 4;288,289,290,291;,
 4;292,293,294,295;,
 4;292,296,297,287;,
 4;298,293,286,299;;
 
 MeshMaterialList {
  5;
  90;
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4;;
  Material {
   0.339200;0.339200;0.339200;1.000000;;
   5.000000;
   0.830000;0.830000;0.830000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.000000;0.078400;0.564800;1.000000;;
   5.000000;
   0.800000;0.800000;0.800000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.241600;0.269600;0.156800;1.000000;;
   5.000000;
   0.430000;0.430000;0.430000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.000000;0.138400;0.003200;1.000000;;
   5.000000;
   0.620000;0.620000;0.620000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.012800;0.012800;0.012800;1.000000;;
   5.000000;
   0.590000;0.590000;0.590000;;
   0.000000;0.000000;0.000000;;
  }
 }
 MeshNormals {
  36;
  0.000000;0.000000;-1.000000;,
  -1.000000;0.000000;0.000000;,
  0.000000;-0.000000;1.000000;,
  0.121874;-0.992546;-0.000000;,
  0.974365;0.224971;0.000000;,
  0.026152;0.999658;0.000000;,
  0.974365;0.224971;0.000000;,
  0.026152;0.999658;0.000000;,
  -0.000001;0.199367;-0.979925;,
  -0.833884;-0.540858;-0.110041;,
  0.000001;-0.199369;0.979924;,
  -0.000003;-0.317306;-0.948323;,
  -0.833884;-0.523416;0.175135;,
  0.000000;0.317306;0.948323;,
  1.000000;0.000000;0.000000;,
  0.000000;1.000000;0.000000;,
  0.000000;-1.000000;-0.000000;,
  -0.121869;0.992546;0.000000;,
  -0.992547;-0.121862;0.000000;,
  0.992546;0.121874;0.000000;,
  -0.974374;-0.224933;0.000000;,
  0.224955;-0.974369;-0.000000;,
  -0.224953;0.974370;0.000000;,
  -0.026185;-0.999657;0.000000;,
  0.999658;-0.026167;-0.000000;,
  -0.999656;0.026208;0.000000;,
  -0.992547;-0.121862;0.000000;,
  -0.974374;-0.224933;0.000000;,
  0.224955;-0.974369;-0.000000;,
  -0.999656;0.026208;0.000000;,
  0.833884;0.540858;0.110044;,
  -0.551948;0.817137;0.166253;,
  0.551951;-0.817135;-0.166254;,
  0.833887;0.523413;-0.175133;,
  -0.551931;0.790797;-0.264601;,
  0.551940;-0.790791;0.264597;;
  90;
  4;0,0,0,0;,
  4;1,1,1,1;,
  4;2,2,2,2;,
  4;14,14,14,14;,
  4;15,15,15,15;,
  4;16,16,16,16;,
  4;0,0,0,0;,
  4;3,3,3,3;,
  4;2,2,2,2;,
  4;17,17,17,17;,
  4;18,18,18,18;,
  4;19,19,19,19;,
  4;0,0,0,0;,
  4;4,4,4,4;,
  4;2,2,2,2;,
  4;20,20,20,20;,
  4;21,21,21,21;,
  4;22,22,22,22;,
  4;0,0,0,0;,
  4;5,5,5,5;,
  4;2,2,2,2;,
  4;23,23,23,23;,
  4;24,24,24,24;,
  4;25,25,25,25;,
  4;0,0,0,0;,
  4;3,3,3,3;,
  4;2,2,2,2;,
  4;17,17,17,17;,
  4;26,26,26,26;,
  4;19,19,19,19;,
  4;0,0,0,0;,
  4;6,6,6,6;,
  4;2,2,2,2;,
  4;27,27,27,27;,
  4;28,28,28,28;,
  4;22,22,22,22;,
  4;0,0,0,0;,
  4;7,7,7,7;,
  4;2,2,2,2;,
  4;23,23,23,23;,
  4;24,24,24,24;,
  4;29,29,29,29;,
  4;0,0,0,0;,
  4;3,3,3,3;,
  4;2,2,2,2;,
  4;17,17,17,17;,
  4;26,26,26,26;,
  4;19,19,19,19;,
  4;0,0,0,0;,
  4;6,6,6,6;,
  4;2,2,2,2;,
  4;27,27,27,27;,
  4;28,28,28,28;,
  4;22,22,22,22;,
  4;0,0,0,0;,
  4;7,7,7,7;,
  4;2,2,2,2;,
  4;23,23,23,23;,
  4;24,24,24,24;,
  4;29,29,29,29;,
  4;0,0,0,0;,
  4;3,3,3,3;,
  4;2,2,2,2;,
  4;17,17,17,17;,
  4;18,18,18,18;,
  4;19,19,19,19;,
  4;0,0,0,0;,
  4;4,4,4,4;,
  4;2,2,2,2;,
  4;20,20,20,20;,
  4;21,21,21,21;,
  4;22,22,22,22;,
  4;0,0,0,0;,
  4;5,5,5,5;,
  4;2,2,2,2;,
  4;23,23,23,23;,
  4;24,24,24,24;,
  4;25,25,25,25;,
  4;8,8,8,8;,
  4;9,9,9,9;,
  4;10,10,10,10;,
  4;30,30,30,30;,
  4;31,31,31,31;,
  4;32,32,32,32;,
  4;11,11,11,11;,
  4;12,12,12,12;,
  4;13,13,13,13;,
  4;33,33,33,33;,
  4;34,34,34,34;,
  4;35,35,35,35;;
 }
 MeshTextureCoords {
  300;
  0.000000;0.000000;,
  0.000000;1.000000;,
  1.000000;1.000000;,
  1.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;1.000000;,
  1.000000;1.000000;,
  1.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;1.000000;,
  1.000000;1.000000;,
  1.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;1.000000;,
  1.000000;1.000000;,
  1.000000;0.000000;,
  0.000000;1.000000;,
  1.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;1.000000;,
  1.000000;1.000000;,
  1.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;1.000000;,
  1.000000;1.000000;,
  1.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;1.000000;,
  1.000000;1.000000;,
  1.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;1.000000;,
  1.000000;1.000000;,
  1.000000;0.000000;,
  0.000000;1.000000;,
  1.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;1.000000;,
  1.000000;1.000000;,
  1.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;1.000000;,
  1.000000;1.000000;,
  1.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;1.000000;,
  1.000000;1.000000;,
  1.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;1.000000;,
  1.000000;1.000000;,
  1.000000;0.000000;,
  0.000000;1.000000;,
  1.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;1.000000;,
  1.000000;1.000000;,
  1.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;1.000000;,
  1.000000;1.000000;,
  1.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;1.000000;,
  1.000000;1.000000;,
  1.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;1.000000;,
  1.000000;1.000000;,
  1.000000;0.000000;,
  0.000000;1.000000;,
  1.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;1.000000;,
  1.000000;1.000000;,
  1.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;1.000000;,
  1.000000;1.000000;,
  1.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;1.000000;,
  1.000000;1.000000;,
  1.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;1.000000;,
  1.000000;1.000000;,
  1.000000;0.000000;,
  0.000000;1.000000;,
  1.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;1.000000;,
  1.000000;1.000000;,
  1.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;1.000000;,
  1.000000;1.000000;,
  1.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;1.000000;,
  1.000000;1.000000;,
  1.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;1.000000;,
  1.000000;1.000000;,
  1.000000;0.000000;,
  0.000000;1.000000;,
  1.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;1.000000;,
  1.000000;1.000000;,
  1.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;1.000000;,
  1.000000;1.000000;,
  1.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;1.000000;,
  1.000000;1.000000;,
  1.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;1.000000;,
  1.000000;1.000000;,
  1.000000;0.000000;,
  0.000000;1.000000;,
  1.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;1.000000;,
  1.000000;1.000000;,
  1.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;1.000000;,
  1.000000;1.000000;,
  1.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;1.000000;,
  1.000000;1.000000;,
  1.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;1.000000;,
  1.000000;1.000000;,
  1.000000;0.000000;,
  0.000000;1.000000;,
  1.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;1.000000;,
  1.000000;1.000000;,
  1.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;1.000000;,
  1.000000;1.000000;,
  1.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;1.000000;,
  1.000000;1.000000;,
  1.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;1.000000;,
  1.000000;1.000000;,
  1.000000;0.000000;,
  0.000000;1.000000;,
  1.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;1.000000;,
  1.000000;1.000000;,
  1.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;1.000000;,
  1.000000;1.000000;,
  1.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;1.000000;,
  1.000000;1.000000;,
  1.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;1.000000;,
  1.000000;1.000000;,
  1.000000;0.000000;,
  0.000000;1.000000;,
  1.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;1.000000;,
  1.000000;1.000000;,
  1.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;1.000000;,
  1.000000;1.000000;,
  1.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;1.000000;,
  1.000000;1.000000;,
  1.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;1.000000;,
  1.000000;1.000000;,
  1.000000;0.000000;,
  0.000000;1.000000;,
  1.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;1.000000;,
  1.000000;1.000000;,
  1.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;1.000000;,
  1.000000;1.000000;,
  1.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;1.000000;,
  1.000000;1.000000;,
  1.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;1.000000;,
  1.000000;1.000000;,
  1.000000;0.000000;,
  0.000000;1.000000;,
  1.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;1.000000;,
  1.000000;1.000000;,
  1.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;1.000000;,
  1.000000;1.000000;,
  1.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;1.000000;,
  1.000000;1.000000;,
  1.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;1.000000;,
  1.000000;1.000000;,
  1.000000;0.000000;,
  0.000000;1.000000;,
  1.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;1.000000;,
  1.000000;1.000000;,
  1.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;1.000000;,
  1.000000;1.000000;,
  1.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;1.000000;,
  1.000000;1.000000;,
  1.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;1.000000;,
  1.000000;1.000000;,
  1.000000;0.000000;,
  0.000000;1.000000;,
  1.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;1.000000;,
  1.000000;1.000000;,
  1.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;1.000000;,
  1.000000;1.000000;,
  1.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;1.000000;,
  1.000000;1.000000;,
  1.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;1.000000;,
  1.000000;1.000000;,
  1.000000;0.000000;,
  0.000000;1.000000;,
  1.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;;
 }
}
