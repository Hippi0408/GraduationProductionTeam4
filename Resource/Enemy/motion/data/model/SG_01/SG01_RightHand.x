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
 0.96357;-0.31228;-2.93500;,
 0.96357;-6.93735;-2.93500;,
 -1.61935;-6.93735;-2.93500;,
 -1.61935;-0.31228;-2.93500;,
 -1.61935;-0.31228;-2.93500;,
 -1.61935;-6.93735;-2.93500;,
 -1.61935;-6.93735;2.93500;,
 -1.61935;-0.31228;2.93500;,
 -1.61935;-0.31228;2.93500;,
 -1.61935;-6.93735;2.93500;,
 0.96357;-6.93735;2.93500;,
 0.96357;-0.31228;2.93500;,
 0.96357;-0.31228;2.93500;,
 0.96357;-6.93735;2.93500;,
 0.96357;-6.93735;-2.93500;,
 0.96357;-0.31228;-2.93500;,
 0.96357;-0.31228;-2.93500;,
 -1.61935;-0.31228;-2.93500;,
 0.96357;-6.93735;-2.93500;,
 -1.61935;-6.93735;-2.93500;,
 -0.14337;-6.95997;-2.77913;,
 3.72756;-6.48468;-2.77913;,
 3.93962;-8.21170;-2.77913;,
 0.06867;-8.68701;-2.77913;,
 0.06867;-8.68701;-2.77913;,
 3.93962;-8.21170;-2.77913;,
 3.93962;-8.21170;-1.61773;,
 0.06867;-8.68701;-1.61773;,
 0.06867;-8.68701;-1.61773;,
 3.93962;-8.21170;-1.61773;,
 3.72756;-6.48468;-1.61773;,
 -0.14337;-6.95997;-1.61773;,
 -0.14337;-6.95997;-1.61773;,
 3.72756;-6.48468;-1.61773;,
 3.72756;-6.48468;-2.77913;,
 -0.14337;-6.95997;-2.77913;,
 -0.14337;-6.95997;-2.77913;,
 0.06867;-8.68701;-2.77913;,
 3.72756;-6.48468;-2.77913;,
 3.93962;-8.21170;-2.77913;,
 2.90696;-7.03873;-2.77913;,
 2.36348;-4.68451;-2.77913;,
 4.05884;-4.29309;-2.77913;,
 4.60239;-6.64730;-2.77913;,
 4.60239;-6.64730;-2.77913;,
 4.05884;-4.29309;-2.77913;,
 4.05884;-4.29309;-1.61773;,
 4.60239;-6.64730;-1.61773;,
 4.60239;-6.64730;-1.61773;,
 4.05884;-4.29309;-1.61773;,
 2.36348;-4.68451;-1.61773;,
 2.90696;-7.03873;-1.61773;,
 2.90696;-7.03873;-1.61773;,
 2.36348;-4.68451;-1.61773;,
 2.36348;-4.68451;-2.77913;,
 2.90696;-7.03873;-2.77913;,
 2.90696;-7.03873;-2.77913;,
 4.60239;-6.64730;-2.77913;,
 2.36348;-4.68451;-2.77913;,
 4.05884;-4.29309;-2.77913;,
 2.77895;-5.17045;-2.77913;,
 1.09229;-5.12627;-2.77913;,
 1.13789;-3.38689;-2.77913;,
 2.82449;-3.43101;-2.77913;,
 2.82449;-3.43101;-2.77913;,
 1.13789;-3.38689;-2.77913;,
 1.13789;-3.38689;-1.61773;,
 2.82449;-3.43101;-1.61773;,
 2.82449;-3.43101;-1.61773;,
 1.13789;-3.38689;-1.61773;,
 1.09229;-5.12627;-1.61773;,
 2.77895;-5.17045;-1.61773;,
 2.77895;-5.17045;-1.61773;,
 1.09229;-5.12627;-1.61773;,
 1.09229;-5.12627;-2.77913;,
 2.77895;-5.17045;-2.77913;,
 2.77895;-5.17045;-2.77913;,
 2.82449;-3.43101;-2.77913;,
 1.09229;-5.12627;-2.77913;,
 1.13789;-3.38689;-2.77913;,
 -0.14337;-6.95997;-1.35223;,
 3.72756;-6.48468;-1.35223;,
 3.93962;-8.21170;-1.35223;,
 0.06867;-8.68701;-1.35223;,
 0.06867;-8.68701;-1.35223;,
 3.93962;-8.21170;-1.35223;,
 3.93962;-8.21170;-0.19083;,
 0.06867;-8.68701;-0.19083;,
 0.06867;-8.68701;-0.19083;,
 3.93962;-8.21170;-0.19083;,
 3.72756;-6.48468;-0.19083;,
 -0.14337;-6.95997;-0.19083;,
 -0.14337;-6.95997;-0.19083;,
 3.72756;-6.48468;-0.19083;,
 3.72756;-6.48468;-1.35223;,
 -0.14337;-6.95997;-1.35223;,
 -0.14337;-6.95997;-1.35223;,
 0.06867;-8.68701;-1.35223;,
 3.72756;-6.48468;-1.35223;,
 3.93962;-8.21170;-1.35223;,
 2.90696;-7.03873;-1.35223;,
 2.36348;-4.68451;-1.35223;,
 4.05884;-4.29309;-1.35223;,
 4.60239;-6.64730;-1.35223;,
 4.60239;-6.64730;-1.35223;,
 4.05884;-4.29309;-1.35223;,
 4.05884;-4.29309;-0.19083;,
 4.60239;-6.64730;-0.19083;,
 4.60239;-6.64730;-0.19083;,
 4.05884;-4.29309;-0.19083;,
 2.36348;-4.68451;-0.19083;,
 2.90696;-7.03873;-0.19083;,
 2.90696;-7.03873;-0.19083;,
 2.36348;-4.68451;-0.19083;,
 2.36348;-4.68451;-1.35223;,
 2.90696;-7.03873;-1.35223;,
 2.90696;-7.03873;-1.35223;,
 4.60239;-6.64730;-1.35223;,
 2.36348;-4.68451;-1.35223;,
 4.05884;-4.29309;-1.35223;,
 2.77895;-5.17045;-1.35223;,
 1.09229;-5.12627;-1.35223;,
 1.13789;-3.38689;-1.35223;,
 2.82449;-3.43101;-1.35223;,
 2.82449;-3.43101;-1.35223;,
 1.13789;-3.38689;-1.35223;,
 1.13789;-3.38689;-0.19083;,
 2.82449;-3.43101;-0.19083;,
 2.82449;-3.43101;-0.19083;,
 1.13789;-3.38689;-0.19083;,
 1.09229;-5.12627;-0.19083;,
 2.77895;-5.17045;-0.19083;,
 2.77895;-5.17045;-0.19083;,
 1.09229;-5.12627;-0.19083;,
 1.09229;-5.12627;-1.35223;,
 2.77895;-5.17045;-1.35223;,
 2.77895;-5.17045;-1.35223;,
 2.82449;-3.43101;-1.35223;,
 1.09229;-5.12627;-1.35223;,
 1.13789;-3.38689;-1.35223;,
 -0.14337;-6.95997;0.10719;,
 3.72756;-6.48468;0.10719;,
 3.93962;-8.21170;0.10719;,
 0.06867;-8.68701;0.10719;,
 0.06867;-8.68701;0.10719;,
 3.93962;-8.21170;0.10719;,
 3.93962;-8.21170;1.26859;,
 0.06867;-8.68701;1.26859;,
 0.06867;-8.68701;1.26859;,
 3.93962;-8.21170;1.26859;,
 3.72756;-6.48468;1.26859;,
 -0.14337;-6.95997;1.26859;,
 -0.14337;-6.95997;1.26859;,
 3.72756;-6.48468;1.26859;,
 3.72756;-6.48468;0.10719;,
 -0.14337;-6.95997;0.10719;,
 -0.14337;-6.95997;0.10719;,
 0.06867;-8.68701;0.10719;,
 3.72756;-6.48468;0.10719;,
 3.93962;-8.21170;0.10719;,
 2.90696;-7.03873;0.10719;,
 2.36348;-4.68451;0.10719;,
 4.05884;-4.29309;0.10719;,
 4.60239;-6.64730;0.10719;,
 4.60239;-6.64730;0.10719;,
 4.05884;-4.29309;0.10719;,
 4.05884;-4.29309;1.26859;,
 4.60239;-6.64730;1.26859;,
 4.60239;-6.64730;1.26859;,
 4.05884;-4.29309;1.26859;,
 2.36348;-4.68451;1.26859;,
 2.90696;-7.03873;1.26859;,
 2.90696;-7.03873;1.26859;,
 2.36348;-4.68451;1.26859;,
 2.36348;-4.68451;0.10719;,
 2.90696;-7.03873;0.10719;,
 2.90696;-7.03873;0.10719;,
 4.60239;-6.64730;0.10719;,
 2.36348;-4.68451;0.10719;,
 4.05884;-4.29309;0.10719;,
 2.77895;-5.17045;0.10719;,
 1.09229;-5.12627;0.10719;,
 1.13789;-3.38689;0.10719;,
 2.82449;-3.43101;0.10719;,
 2.82449;-3.43101;0.10719;,
 1.13789;-3.38689;0.10719;,
 1.13789;-3.38689;1.26859;,
 2.82449;-3.43101;1.26859;,
 2.82449;-3.43101;1.26859;,
 1.13789;-3.38689;1.26859;,
 1.09229;-5.12627;1.26859;,
 2.77895;-5.17045;1.26859;,
 2.77895;-5.17045;1.26859;,
 1.09229;-5.12627;1.26859;,
 1.09229;-5.12627;0.10719;,
 2.77895;-5.17045;0.10719;,
 2.77895;-5.17045;0.10719;,
 2.82449;-3.43101;0.10719;,
 1.09229;-5.12627;0.10719;,
 1.13789;-3.38689;0.10719;,
 -0.14337;-6.95997;1.50084;,
 3.72756;-6.48468;1.50084;,
 3.93962;-8.21170;1.50084;,
 0.06867;-8.68701;1.50084;,
 0.06867;-8.68701;1.50084;,
 3.93962;-8.21170;1.50084;,
 3.93962;-8.21170;2.66224;,
 0.06867;-8.68701;2.66224;,
 0.06867;-8.68701;2.66224;,
 3.93962;-8.21170;2.66224;,
 3.72756;-6.48468;2.66224;,
 -0.14337;-6.95997;2.66224;,
 -0.14337;-6.95997;2.66224;,
 3.72756;-6.48468;2.66224;,
 3.72756;-6.48468;1.50084;,
 -0.14337;-6.95997;1.50084;,
 -0.14337;-6.95997;1.50084;,
 0.06867;-8.68701;1.50084;,
 3.72756;-6.48468;1.50084;,
 3.93962;-8.21170;1.50084;,
 2.90696;-7.03873;1.50084;,
 2.36348;-4.68451;1.50084;,
 4.05884;-4.29309;1.50084;,
 4.60239;-6.64730;1.50084;,
 4.60239;-6.64730;1.50084;,
 4.05884;-4.29309;1.50084;,
 4.05884;-4.29309;2.66224;,
 4.60239;-6.64730;2.66224;,
 4.60239;-6.64730;2.66224;,
 4.05884;-4.29309;2.66224;,
 2.36348;-4.68451;2.66224;,
 2.90696;-7.03873;2.66224;,
 2.90696;-7.03873;2.66224;,
 2.36348;-4.68451;2.66224;,
 2.36348;-4.68451;1.50084;,
 2.90696;-7.03873;1.50084;,
 2.90696;-7.03873;1.50084;,
 4.60239;-6.64730;1.50084;,
 2.36348;-4.68451;1.50084;,
 4.05884;-4.29309;1.50084;,
 2.77895;-5.17045;1.50084;,
 1.09229;-5.12627;1.50084;,
 1.13789;-3.38689;1.50084;,
 2.82449;-3.43101;1.50084;,
 2.82449;-3.43101;1.50084;,
 1.13789;-3.38689;1.50084;,
 1.13789;-3.38689;2.66224;,
 2.82449;-3.43101;2.66224;,
 2.82449;-3.43101;2.66224;,
 1.13789;-3.38689;2.66224;,
 1.09229;-5.12627;2.66224;,
 2.77895;-5.17045;2.66224;,
 2.77895;-5.17045;2.66224;,
 1.09229;-5.12627;2.66224;,
 1.09229;-5.12627;1.50084;,
 2.77895;-5.17045;1.50084;,
 2.77895;-5.17045;1.50084;,
 2.82449;-3.43101;1.50084;,
 1.09229;-5.12627;1.50084;,
 1.13789;-3.38689;1.50084;,
 0.67322;-0.07699;-3.80982;,
 2.82578;-3.26385;-4.45819;,
 1.37482;-4.20496;-4.64966;,
 -0.77773;-1.01811;-4.00129;,
 -0.77773;-1.01811;-4.00129;,
 1.37482;-4.20496;-4.64966;,
 1.37482;-4.40434;-3.66974;,
 -0.77773;-1.21747;-3.02136;,
 -0.77773;-1.21747;-3.02136;,
 1.37482;-4.40434;-3.66974;,
 2.82578;-3.46322;-3.47827;,
 0.67322;-0.27637;-2.82989;,
 0.67322;-0.27637;-2.82989;,
 2.82578;-3.46322;-3.47827;,
 2.82578;-3.26385;-4.45819;,
 0.67322;-0.07699;-3.80982;,
 0.67322;-0.07699;-3.80982;,
 -0.77773;-1.01811;-4.00129;,
 2.82578;-3.26385;-4.45819;,
 1.37482;-4.20496;-4.64966;,
 2.91041;-3.69699;-4.53260;,
 4.34757;-5.75609;-3.84363;,
 2.89661;-6.66684;-3.53890;,
 1.45945;-4.60773;-4.22786;,
 1.45945;-4.60773;-4.22786;,
 2.89661;-6.66684;-3.53890;,
 2.89661;-6.34953;-2.59057;,
 1.45945;-4.29041;-3.27954;,
 1.45945;-4.29041;-3.27954;,
 2.89661;-6.34953;-2.59057;,
 4.34757;-5.43879;-2.89530;,
 2.91041;-3.37968;-3.58427;,
 2.91041;-3.37968;-3.58427;,
 4.34757;-5.43879;-2.89530;,
 4.34757;-5.75609;-3.84363;,
 2.91041;-3.69699;-4.53260;,
 2.91041;-3.69699;-4.53260;,
 1.45945;-4.60773;-4.22786;,
 4.34757;-5.75609;-3.84363;,
 2.89661;-6.66684;-3.53890;;
 
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
  9;
  90;
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
  5;;
  Material {
   0.762400;0.746400;0.800000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.746400;0.743200;0.800000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.800000;0.800000;0.800000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.140400;0.043550;0.043550;1.000000;;
   15.000000;
   0.550000;0.550000;0.550000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.800000;0.800000;0.800000;1.000000;;
   21.000000;
   0.270000;0.270000;0.270000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.062400;0.040800;0.040800;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.169600;0.442400;0.448800;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.069960;0.182490;0.185130;;
  }
  Material {
   0.194400;0.222400;0.592800;1.000000;;
   5.000000;
   0.710000;0.710000;0.710000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.489600;0.260000;0.140800;1.000000;;
   5.000000;
   0.470000;0.470000;0.470000;;
   0.000000;0.000000;0.000000;;
  }
 }
 MeshNormals {
  38;
  0.000000;0.000000;-1.000000;,
  -1.000000;0.000000;0.000000;,
  0.000000;-0.000000;1.000000;,
  0.121873;-0.992546;-0.000000;,
  0.974366;0.224968;0.000000;,
  0.026148;0.999658;0.000000;,
  0.121873;-0.992546;-0.000000;,
  -0.000000;0.199367;-0.979925;,
  -0.833886;-0.540856;-0.110040;,
  0.000001;-0.199369;0.979925;,
  -0.000003;-0.317305;-0.948323;,
  -0.833887;-0.523412;0.175135;,
  0.000001;0.317305;0.948323;,
  1.000000;0.000000;0.000000;,
  0.000000;1.000000;0.000000;,
  0.000000;-1.000000;-0.000000;,
  -0.121869;0.992546;0.000000;,
  -0.992547;-0.121861;0.000000;,
  0.992546;0.121875;0.000000;,
  -0.974373;-0.224937;0.000000;,
  0.224956;-0.974369;-0.000000;,
  -0.224959;0.974368;0.000000;,
  -0.026183;-0.999657;0.000000;,
  0.999658;-0.026171;-0.000000;,
  -0.999656;0.026207;0.000000;,
  -0.121869;0.992546;0.000000;,
  0.992546;0.121875;0.000000;,
  -0.974373;-0.224937;0.000000;,
  0.224956;-0.974369;-0.000000;,
  -0.224959;0.974368;0.000000;,
  -0.026183;-0.999657;0.000000;,
  0.999657;-0.026171;-0.000000;,
  0.833885;0.540858;0.110042;,
  -0.551948;0.817138;0.166248;,
  0.551947;-0.817137;-0.166257;,
  0.833886;0.523414;-0.175132;,
  -0.551935;0.790793;-0.264602;,
  0.551939;-0.790792;0.264595;;
  90;
  4;0,0,0,0;,
  4;1,1,1,1;,
  4;2,2,2,2;,
  4;13,13,13,13;,
  4;14,14,14,14;,
  4;15,15,15,15;,
  4;0,0,0,0;,
  4;3,3,3,3;,
  4;2,2,2,2;,
  4;16,16,16,16;,
  4;17,17,17,17;,
  4;18,18,18,18;,
  4;0,0,0,0;,
  4;4,4,4,4;,
  4;2,2,2,2;,
  4;19,19,19,19;,
  4;20,20,20,20;,
  4;21,21,21,21;,
  4;0,0,0,0;,
  4;5,5,5,5;,
  4;2,2,2,2;,
  4;22,22,22,22;,
  4;23,23,23,23;,
  4;24,24,24,24;,
  4;0,0,0,0;,
  4;6,6,6,6;,
  4;2,2,2,2;,
  4;25,25,25,25;,
  4;17,17,17,17;,
  4;26,26,26,26;,
  4;0,0,0,0;,
  4;4,4,4,4;,
  4;2,2,2,2;,
  4;27,27,27,27;,
  4;28,28,28,28;,
  4;29,29,29,29;,
  4;0,0,0,0;,
  4;5,5,5,5;,
  4;2,2,2,2;,
  4;30,30,30,30;,
  4;31,31,31,31;,
  4;24,24,24,24;,
  4;0,0,0,0;,
  4;6,6,6,6;,
  4;2,2,2,2;,
  4;25,25,25,25;,
  4;17,17,17,17;,
  4;26,26,26,26;,
  4;0,0,0,0;,
  4;4,4,4,4;,
  4;2,2,2,2;,
  4;27,27,27,27;,
  4;28,28,28,28;,
  4;29,29,29,29;,
  4;0,0,0,0;,
  4;5,5,5,5;,
  4;2,2,2,2;,
  4;30,30,30,30;,
  4;31,31,31,31;,
  4;24,24,24,24;,
  4;0,0,0,0;,
  4;3,3,3,3;,
  4;2,2,2,2;,
  4;16,16,16,16;,
  4;17,17,17,17;,
  4;18,18,18,18;,
  4;0,0,0,0;,
  4;4,4,4,4;,
  4;2,2,2,2;,
  4;19,19,19,19;,
  4;20,20,20,20;,
  4;21,21,21,21;,
  4;0,0,0,0;,
  4;5,5,5,5;,
  4;2,2,2,2;,
  4;22,22,22,22;,
  4;23,23,23,23;,
  4;24,24,24,24;,
  4;7,7,7,7;,
  4;8,8,8,8;,
  4;9,9,9,9;,
  4;32,32,32,32;,
  4;33,33,33,33;,
  4;34,34,34,34;,
  4;10,10,10,10;,
  4;11,11,11,11;,
  4;12,12,12,12;,
  4;35,35,35,35;,
  4;36,36,36,36;,
  4;37,37,37,37;;
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
