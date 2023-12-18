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
 401;
 5.10710;74.92120;-20.00000;,
 5.10710;68.02480;-7.93830;,
 -2.89754;52.53786;-7.93830;,
 -2.89754;59.43434;-20.00000;,
 5.10710;55.46926;7.93830;,
 -5.82728;39.98238;7.93830;,
 5.10800;46.98932;20.00000;,
 -3.94828;18.42018;20.00000;,
 -19.99910;46.98944;20.00000;,
 -20.00000;55.46940;7.93830;,
 -5.82728;39.98238;7.93830;,
 -3.94828;18.42018;20.00000;,
 -20.00000;68.02490;-7.93830;,
 -2.89754;52.53786;-7.93830;,
 -20.00000;74.92132;-20.00000;,
 -2.89754;59.43434;-20.00000;,
 5.10710;55.46926;7.93830;,
 -20.00000;55.46940;7.93830;,
 5.10710;68.02480;-7.93830;,
 -20.00000;68.02490;-7.93830;,
 5.10710;74.92120;-20.00000;,
 -20.00000;74.92132;-20.00000;,
 -3.94828;18.42018;20.00000;,
 5.10800;46.98932;20.00000;,
 -19.99910;46.98944;20.00000;,
 -2.89754;59.43434;-20.00000;,
 -20.00000;74.92132;-20.00000;,
 5.10710;74.92120;-20.00000;,
 20.00000;68.02474;-7.93798;,
 20.00000;55.46918;7.93862;,
 20.00000;39.44846;7.93862;,
 20.00000;39.44846;-7.93798;,
 20.00000;74.92108;-19.99968;,
 20.00000;20.59266;-7.93798;,
 20.00000;-0.00014;-19.99968;,
 20.00000;20.59266;7.93862;,
 20.00090;46.98924;20.00032;,
 20.00090;0.00004;20.00032;,
 5.10800;46.98932;20.00000;,
 -3.94828;18.42018;20.00000;,
 -19.99910;0.00016;20.00000;,
 20.00090;0.00004;20.00032;,
 -5.82728;39.98238;7.93830;,
 -2.89754;52.53786;-7.93830;,
 -5.63308;-0.00012;-20.00000;,
 -19.99910;0.00016;20.00000;,
 5.10800;46.98932;20.00000;,
 20.00090;46.98924;20.00032;,
 20.00000;55.46918;7.93862;,
 5.10710;55.46926;7.93830;,
 -5.82728;39.98238;7.93830;,
 5.10710;55.46926;7.93830;,
 5.10710;68.02480;-7.93830;,
 -2.89754;52.53786;-7.93830;,
 20.00000;68.02474;-7.93798;,
 5.10710;68.02480;-7.93830;,
 5.10710;74.92120;-20.00000;,
 -2.89754;59.43434;-20.00000;,
 20.00000;74.92108;-19.99968;,
 5.10710;74.92120;-20.00000;,
 -5.63308;-0.00012;-20.00000;,
 20.00000;-0.00014;-19.99968;,
 20.00090;0.00004;20.00032;,
 -19.99910;0.00016;20.00000;,
 -3.94828;18.42018;20.00000;,
 20.00090;46.98924;20.00032;,
 -2.89754;59.43434;-20.00000;,
 -5.63308;-0.00012;-20.00000;,
 -2.89754;59.43434;-20.00000;,
 5.10710;74.92120;-20.00000;,
 20.00000;-0.00014;-19.99968;,
 20.00000;74.92108;-19.99968;,
 -3.94828;18.42018;20.00000;,
 5.10710;55.46926;7.93830;,
 -3.94828;18.42018;20.00000;,
 -5.10636;46.98596;20.00000;,
 5.10800;46.98596;20.00000;,
 5.10800;95.88938;20.00000;,
 -5.10636;89.10264;20.00000;,
 20.00090;46.98588;20.00032;,
 20.00090;95.88928;20.00032;,
 20.00090;46.98588;20.00032;,
 20.00000;55.46918;7.93862;,
 20.00000;95.88918;7.93862;,
 20.00090;95.88928;20.00032;,
 20.00000;68.02474;-7.93798;,
 20.00000;105.36908;-7.93798;,
 20.00000;74.91778;-19.99968;,
 20.00000;105.36890;-19.99968;,
 20.00000;74.91778;-19.99968;,
 5.10710;74.91786;-20.00000;,
 5.10710;105.36898;-20.00000;,
 20.00000;105.36890;-19.99968;,
 -5.10726;74.91786;-20.00000;,
 -5.10726;98.58216;-20.00000;,
 -20.00000;74.91796;-20.00000;,
 -20.00000;95.18892;-20.00000;,
 -20.00000;74.91796;-20.00000;,
 -20.00000;68.02490;-7.93830;,
 -20.00000;95.18914;-7.93830;,
 -20.00000;95.18892;-20.00000;,
 -20.00000;55.46940;7.93830;,
 -20.00000;85.70930;7.93830;,
 -20.00000;74.91796;-20.00000;,
 -5.10726;74.91786;-20.00000;,
 -5.10726;68.02480;-7.93830;,
 -20.00000;68.02490;-7.93830;,
 5.10710;74.91786;-20.00000;,
 5.10710;68.02480;-7.93830;,
 20.00000;74.91778;-19.99968;,
 20.00000;68.02474;-7.93798;,
 -5.10726;55.46926;7.93830;,
 -20.00000;55.46940;7.93830;,
 5.10710;55.46926;7.93830;,
 20.00000;55.46918;7.93862;,
 -5.10636;46.98596;20.00000;,
 -19.99910;46.98612;20.00000;,
 5.10800;46.98596;20.00000;,
 20.00090;46.98588;20.00032;,
 -19.99910;85.70944;20.00000;,
 -5.10636;89.10264;20.00000;,
 -5.10726;89.10252;7.93830;,
 -20.00000;85.70930;7.93830;,
 5.10800;95.88938;20.00000;,
 5.10710;95.88924;7.93830;,
 20.00090;95.88928;20.00032;,
 20.00000;95.88918;7.93862;,
 -5.10726;98.58240;-7.93832;,
 -20.00000;95.18914;-7.93830;,
 5.10710;105.36914;-7.93832;,
 20.00000;105.36908;-7.93798;,
 -5.10726;98.58216;-20.00000;,
 -20.00000;95.18892;-20.00000;,
 5.10710;105.36898;-20.00000;,
 20.00000;105.36890;-19.99968;,
 -19.99910;85.70944;20.00000;,
 -19.99910;85.70944;20.00000;,
 -19.99910;46.98612;20.00000;,
 -19.99910;46.98612;20.00000;,
 -19.99910;85.70944;20.00000;,
 -5.10636;89.10264;20.00000;,
 -5.10636;115.71456;20.00002;,
 -19.99910;115.71466;20.00002;,
 5.10800;95.88938;20.00000;,
 4.72010;130.25484;20.00000;,
 20.00090;95.88928;20.00032;,
 20.00090;131.22442;20.00034;,
 20.00090;95.88928;20.00032;,
 20.00000;95.88918;7.93862;,
 20.00000;138.54511;7.93864;,
 20.00090;131.22442;20.00034;,
 20.00000;126.58316;-7.93798;,
 20.00000;147.83853;-7.93798;,
 20.00000;132.85523;-19.99968;,
 20.00000;151.33294;-19.99966;,
 20.00000;132.85523;-19.99968;,
 5.10710;132.85529;-20.00000;,
 4.71920;150.62293;-20.00000;,
 20.00000;151.33294;-19.99966;,
 -5.10726;107.33139;-20.00000;,
 -5.10726;135.82316;-19.99998;,
 -20.00000;107.33154;-20.00000;,
 -20.00000;135.82331;-19.99998;,
 -20.00000;107.33154;-20.00000;,
 -20.00000;111.07356;-7.93830;,
 -20.00000;132.32879;-7.93830;,
 -20.00000;135.82331;-19.99998;,
 -20.00000;85.70930;7.93830;,
 -20.00000;123.03521;7.93832;,
 -19.99910;85.70944;20.00000;,
 -19.99910;115.71466;20.00002;,
 -20.00000;107.33154;-20.00000;,
 -5.10726;107.33139;-20.00000;,
 -5.10726;111.07344;-7.93830;,
 -20.00000;111.07356;-7.93830;,
 5.10710;132.85529;-20.00000;,
 5.10710;126.58322;-7.93830;,
 20.00000;132.85523;-19.99968;,
 20.00000;126.58316;-7.93798;,
 -5.10726;89.10252;7.93830;,
 -20.00000;85.70930;7.93830;,
 5.10710;95.88924;7.93830;,
 20.00000;95.88918;7.93862;,
 -5.10636;89.10264;20.00000;,
 -19.99910;85.70944;20.00000;,
 5.10800;95.88938;20.00000;,
 20.00090;95.88928;20.00032;,
 -19.99910;115.71466;20.00002;,
 -5.10636;115.71456;20.00002;,
 -5.10726;123.03510;7.93832;,
 -20.00000;123.03521;7.93832;,
 4.72010;130.25484;20.00000;,
 5.10710;138.54517;7.93832;,
 20.00090;131.22442;20.00034;,
 20.00000;138.54511;7.93864;,
 -5.10726;132.32866;-7.93830;,
 -20.00000;132.32879;-7.93830;,
 5.10710;147.83858;-7.93830;,
 20.00000;147.83853;-7.93798;,
 -5.10726;135.82316;-19.99998;,
 -20.00000;135.82331;-19.99998;,
 4.71920;150.62293;-20.00000;,
 20.00000;151.33294;-19.99966;,
 5.10710;105.36898;-20.00000;,
 -5.10726;95.22338;-20.00000;,
 -5.10726;107.33139;-20.00000;,
 5.10710;132.85529;-20.00000;,
 -20.00000;95.18892;-20.00000;,
 -20.00000;107.33154;-20.00000;,
 -20.00000;95.18892;-20.00000;,
 -20.00000;95.18914;-7.93830;,
 -20.00000;111.07356;-7.93830;,
 -20.00000;107.33154;-20.00000;,
 -5.10726;95.22338;-20.00000;,
 5.10710;105.36898;-20.00000;,
 20.00000;95.88918;7.93862;,
 -20.00000;95.18914;-7.93830;,
 -20.00000;111.07356;-7.93830;,
 -20.00000;85.70930;7.93830;,
 -5.16216;105.40316;-3.87352;,
 -20.00000;107.33154;-20.00000;,
 20.00000;95.88918;7.93862;,
 4.76026;114.47080;6.44304;,
 5.10710;132.85529;-20.00000;,
 -5.10726;107.33139;-20.00000;,
 20.00000;126.58316;-7.93798;,
 20.00000;132.85523;-19.99968;,
 20.00000;126.58316;-7.93798;,
 20.00000;95.88918;7.93862;,
 20.00000;105.36908;-7.93798;,
 20.00000;105.36890;-19.99968;,
 20.00000;132.85523;-19.99968;,
 20.00000;126.58316;-7.93798;,
 20.00000;105.36890;-19.99968;,
 20.00000;132.85523;-19.99968;,
 -20.00000;85.70930;7.93830;,
 -20.00000;107.33154;-20.00000;,
 20.00000;95.88918;7.93862;,
 -5.10726;95.22338;-20.00000;,
 -20.00000;85.70930;7.93830;,
 -5.10726;95.22338;-20.00000;,
 -20.00000;95.18914;-7.93830;,
 -20.00000;95.18892;-20.00000;,
 5.10710;105.36898;-20.00000;,
 20.00000;105.36890;-19.99968;,
 20.00000;105.36908;-7.93798;,
 20.00000;95.88918;7.93862;,
 20.00000;95.88918;7.93862;,
 -5.10726;95.22338;-20.00000;,
 -20.00000;85.70930;7.93830;,
 7.98400;174.00000;-20.00000;,
 19.99902;173.99998;-19.99968;,
 20.00000;150.62278;-19.99968;,
 4.71920;150.62293;-20.00000;,
 19.99902;173.99998;-19.99968;,
 19.99992;174.00025;20.00032;,
 20.00090;130.25480;20.00032;,
 20.00000;150.62278;-19.99968;,
 19.99992;174.00025;20.00032;,
 7.98490;174.00026;20.00000;,
 4.72010;130.25484;20.00000;,
 20.00090;130.25480;20.00032;,
 7.98490;174.00026;20.00000;,
 7.98400;174.00000;-20.00000;,
 4.71920;150.62293;-20.00000;,
 4.72010;130.25484;20.00000;,
 7.98490;174.00026;20.00000;,
 19.99992;174.00025;20.00032;,
 19.99902;173.99998;-19.99968;,
 7.98400;174.00000;-20.00000;,
 4.71920;150.62293;-20.00000;,
 20.00000;150.62278;-19.99968;,
 20.00090;130.25480;20.00032;,
 4.72010;130.25484;20.00000;,
 -1.07912;152.10373;-20.00000;,
 7.98400;174.00000;-20.00000;,
 4.71920;150.62293;-20.00000;,
 -5.10726;135.82316;-19.99998;,
 7.98400;174.00000;-20.00000;,
 7.98490;174.00026;20.00000;,
 4.72010;130.25484;20.00000;,
 4.71920;150.62293;-20.00000;,
 7.98490;174.00026;20.00000;,
 -1.07822;142.95756;20.00000;,
 -5.10636;115.71456;20.00002;,
 4.72010;130.25484;20.00000;,
 -1.07822;142.95756;20.00000;,
 -1.07912;152.10373;-20.00000;,
 -5.10726;135.82316;-19.99998;,
 -5.10636;115.71456;20.00002;,
 7.98400;174.00000;-20.00000;,
 -1.07912;152.10373;-20.00000;,
 -5.10726;135.82316;-19.99998;,
 4.71920;150.62293;-20.00000;,
 -5.74966;174.00000;-20.00000;,
 -1.07912;152.10373;-20.00000;,
 -5.10726;135.82316;-19.99998;,
 -8.81378;135.82316;-19.99998;,
 -5.74876;174.00026;20.00000;,
 -5.74966;174.00000;-20.00000;,
 -8.81378;135.82316;-19.99998;,
 -5.10636;115.71456;20.00002;,
 -5.74876;174.00026;20.00000;,
 -1.07822;142.95756;20.00000;,
 -1.07912;152.10373;-20.00000;,
 -5.74966;174.00000;-20.00000;,
 -8.81378;135.82316;-19.99998;,
 -5.10726;135.82316;-19.99998;,
 -1.07822;142.95756;20.00000;,
 -5.10636;115.71456;20.00002;,
 -1.07822;142.95756;20.00000;,
 -5.10726;135.82316;-19.99998;,
 -1.07912;152.10373;-20.00000;,
 -1.07822;142.95756;20.00000;,
 -5.74876;174.00026;20.00000;,
 -5.10636;115.71456;20.00002;,
 -20.00082;174.00019;-20.00000;,
 -5.74966;174.00000;-20.00000;,
 -8.81378;135.82316;-19.99998;,
 -20.00000;135.82331;-19.99998;,
 -5.74966;174.00000;-20.00000;,
 -5.74876;174.00026;20.00000;,
 -5.10636;115.71456;20.00002;,
 -8.81378;135.82316;-19.99998;,
 -5.74876;174.00026;20.00000;,
 -19.99992;174.00036;20.00000;,
 -19.99910;115.71466;20.00002;,
 -5.10636;115.71456;20.00002;,
 -19.99992;174.00036;20.00000;,
 -20.00082;174.00026;5.69544;,
 -20.00000;123.03521;7.93832;,
 -19.99910;115.71466;20.00002;,
 -20.00082;174.00026;-5.69544;,
 -20.00000;132.32879;-7.93830;,
 -20.00082;174.00019;-20.00000;,
 -20.00000;135.82331;-19.99998;,
 -20.00082;174.00026;5.69544;,
 -5.74876;174.00026;20.00000;,
 -5.74966;174.00000;-20.00000;,
 -20.00082;174.00026;-5.69544;,
 -20.00000;132.32879;-7.93830;,
 -8.81378;135.82316;-19.99998;,
 -5.10636;115.71456;20.00002;,
 -20.00000;123.03521;7.93832;,
 -5.10636;115.71456;20.00002;,
 -19.99910;115.71466;20.00002;,
 -8.81378;135.82316;-19.99998;,
 -20.00000;135.82331;-19.99998;,
 -19.99992;174.00036;20.00000;,
 -20.00082;174.00019;-20.00000;,
 7.98400;174.00000;-20.00000;,
 7.98490;174.00026;20.00000;,
 -1.07822;142.95756;20.00000;,
 -1.07912;152.10373;-20.00000;,
 -5.74876;174.00026;20.00000;,
 -5.74966;174.00000;-20.00000;,
 -5.74876;174.00026;20.00000;,
 7.98490;174.00026;20.00000;,
 7.98400;174.00000;-20.00000;,
 -5.74966;174.00000;-20.00000;,
 -1.07822;142.95756;20.00000;,
 7.98490;174.00026;20.00000;,
 -5.74876;174.00026;20.00000;,
 -1.07912;152.10373;-20.00000;,
 -5.74966;174.00000;-20.00000;,
 7.98400;174.00000;-20.00000;,
 -2.89754;59.43434;-20.00000;,
 -3.94828;18.42018;20.00000;,
 -6.70168;39.44856;7.93830;,
 -6.70168;39.44856;-7.93830;,
 -2.89754;59.43434;-20.00000;,
 -6.70168;20.59280;-7.93830;,
 -5.63308;-0.00012;-20.00000;,
 -6.70168;20.59280;7.93830;,
 -3.94828;18.42018;20.00000;,
 -19.99910;0.00016;20.00000;,
 -20.00000;55.46940;7.93830;,
 -20.00000;68.02490;-7.93830;,
 -20.00000;-0.00004;-20.00000;,
 -19.99910;0.00016;20.00000;,
 -20.00000;55.46940;7.93830;,
 -3.94828;18.42018;20.00000;,
 -2.89754;59.43434;-20.00000;,
 -20.00000;68.02490;-7.93830;,
 -19.99910;46.98944;20.00000;,
 -19.99910;0.00016;20.00000;,
 -3.94828;18.42018;20.00000;,
 -19.99910;46.98944;20.00000;,
 -20.00000;74.92132;-20.00000;,
 -5.63308;-0.00012;-20.00000;,
 -20.00000;74.92132;-20.00000;,
 -2.89754;59.43434;-20.00000;,
 -20.00000;55.46940;7.93830;,
 -19.99910;46.98944;20.00000;,
 -3.94828;18.42018;20.00000;,
 -20.00000;-0.00004;-20.00000;,
 -2.89754;59.43434;-20.00000;,
 -20.00000;74.92132;-20.00000;,
 -19.99910;0.00016;20.00000;,
 -20.00000;-0.00004;-20.00000;,
 -5.63308;-0.00012;-20.00000;;
 
 168;
 4;0,1,2,3;,
 4;1,4,5,2;,
 4;4,6,7,5;,
 4;8,9,10,11;,
 4;9,12,13,10;,
 4;12,14,15,13;,
 4;8,6,16,17;,
 4;17,16,18,19;,
 4;19,18,20,21;,
 3;22,23,24;,
 3;25,26,27;,
 4;28,29,30,31;,
 4;32,31,33,34;,
 4;31,30,35,33;,
 4;30,36,37,35;,
 4;33,35,37,34;,
 4;38,39,40,41;,
 4;42,43,44,45;,
 4;46,47,48,49;,
 4;50,51,52,53;,
 4;49,48,54,55;,
 4;53,52,56,57;,
 4;55,54,58,59;,
 4;60,61,62,63;,
 3;36,30,29;,
 3;45,64,42;,
 3;41,65,38;,
 3;44,43,66;,
 3;67,68,69;,
 3;70,69,71;,
 3;32,28,31;,
 3;72,51,50;,
 3;73,74,46;,
 3;69,70,67;,
 4;75,76,77,78;,
 4;76,79,80,77;,
 4;81,82,83,84;,
 4;82,85,86,83;,
 4;85,87,88,86;,
 4;89,90,91,92;,
 4;90,93,94,91;,
 4;93,95,96,94;,
 4;97,98,99,100;,
 4;98,101,102,99;,
 4;103,104,105,106;,
 4;104,107,108,105;,
 4;107,109,110,108;,
 4;106,105,111,112;,
 4;105,108,113,111;,
 4;108,110,114,113;,
 4;112,111,115,116;,
 4;111,113,117,115;,
 4;113,114,118,117;,
 4;119,120,121,122;,
 4;120,123,124,121;,
 4;123,125,126,124;,
 4;122,121,127,128;,
 4;121,124,129,127;,
 4;124,126,130,129;,
 4;128,127,131,132;,
 4;127,129,133,131;,
 4;129,130,134,133;,
 3;135,75,78;,
 3;136,102,101;,
 3;75,135,137;,
 3;101,138,136;,
 4;139,140,141,142;,
 4;140,143,144,141;,
 4;143,145,146,144;,
 4;147,148,149,150;,
 4;148,151,152,149;,
 4;151,153,154,152;,
 4;155,156,157,158;,
 4;156,159,160,157;,
 4;159,161,162,160;,
 4;163,164,165,166;,
 4;164,167,168,165;,
 4;167,169,170,168;,
 4;171,172,173,174;,
 4;172,175,176,173;,
 4;175,177,178,176;,
 4;174,173,179,180;,
 4;173,176,181,179;,
 4;176,178,182,181;,
 4;180,179,183,184;,
 4;179,181,185,183;,
 4;181,182,186,185;,
 4;187,188,189,190;,
 4;188,191,192,189;,
 4;191,193,194,192;,
 4;190,189,195,196;,
 4;189,192,197,195;,
 4;192,194,198,197;,
 4;196,195,199,200;,
 4;195,197,201,199;,
 4;197,198,202,201;,
 4;203,204,205,206;,
 4;204,207,208,205;,
 4;209,210,211,212;,
 4;213,214,215,216;,
 4;217,218,219,220;,
 4;218,221,222,219;,
 4;219,222,223,224;,
 4;222,225,226,223;,
 3;227,228,229;,
 3;227,230,231;,
 3;232,222,221;,
 3;230,227,229;,
 3;233,203,206;,
 3;206,234,233;,
 3;235,211,210;,
 3;236,219,224;,
 3;237,218,238;,
 3;239,216,215;,
 3;240,241,242;,
 3;243,244,245;,
 3;246,214,245;,
 3;247,248,249;,
 4;250,251,252,253;,
 4;254,255,256,257;,
 4;258,259,260,261;,
 4;262,263,264,265;,
 4;266,267,268,269;,
 4;270,271,272,273;,
 4;274,275,276,277;,
 4;278,279,280,281;,
 4;282,283,284,285;,
 4;286,287,288,289;,
 4;286,279,290,291;,
 4;292,293,280,289;,
 4;294,295,296,297;,
 4;298,299,300,301;,
 4;302,303,304,305;,
 4;306,307,308,309;,
 3;310,311,312;,
 3;313,314,315;,
 4;316,317,318,319;,
 4;320,321,322,323;,
 4;324,325,326,327;,
 4;328,329,330,331;,
 4;329,332,333,330;,
 4;332,334,335,333;,
 4;336,337,338,339;,
 4;340,341,342,343;,
 3;344,345,343;,
 3;346,340,347;,
 3;337,336,348;,
 3;338,349,339;,
 4;350,351,352,353;,
 4;354,355,353,352;,
 4;356,357,358,359;,
 3;360,361,362;,
 3;363,364,365;,
 4;366,367,368,369;,
 4;370,369,371,372;,
 4;369,368,373,371;,
 4;368,374,375,373;,
 4;371,373,375,372;,
 4;376,377,378,379;,
 4;380,381,382,383;,
 3;379,384,376;,
 3;385,386,387;,
 3;378,377,388;,
 3;389,390,391;,
 3;392,393,394;,
 3;390,389,395;,
 3;396,397,383;,
 3;398,399,400;;
 
 MeshMaterialList {
  4;
  168;
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
  0,
  2,
  0,
  1,
  1,
  1,
  3,
  2,
  2,
  2,
  3,
  3,
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
    "Data\\texture\\building\\bill007.jpg";
   }
  }
  Material {
   0.800000;0.800000;0.800000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
   TextureFilename {
    "Data\\texture\\building\\bill007.jpg";
   }
  }
  Material {
   0.800000;0.800000;0.800000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
   TextureFilename {
    "Data\\texture\\building\\Concrete.png";
   }
  }
  Material {
   0.800000;0.800000;0.800000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
   TextureFilename {
    "Data\\texture\\building\\Concrete.png";
   }
  }
 }
 MeshNormals {
  226;
  -0.618018;-0.682483;-0.390219;,
  0.859237;-0.444110;-0.253926;,
  0.835615;-0.468983;-0.286012;,
  0.800054;-0.447234;-0.399868;,
  0.782782;-0.397636;-0.478683;,
  -0.690216;-0.506641;-0.516639;,
  -0.644905;-0.555017;-0.525408;,
  -0.609437;-0.643887;-0.462597;,
  0.000002;0.460904;0.887450;,
  0.000004;0.801532;0.597952;,
  0.000004;0.828565;0.559893;,
  0.000004;0.868119;0.496356;,
  0.000000;-0.000000;1.000000;,
  0.000000;0.000000;-1.000000;,
  -0.956804;0.252392;0.144308;,
  -0.494180;0.754708;0.431512;,
  1.000000;0.000000;0.000000;,
  -0.989746;0.100821;-0.101183;,
  1.000000;0.000008;-0.000006;,
  1.000000;0.000000;-0.000037;,
  1.000000;0.000000;-0.000075;,
  1.000000;0.000005;-0.000004;,
  1.000000;0.000005;-0.000029;,
  1.000000;0.000008;-0.000043;,
  -0.000014;0.302768;0.953064;,
  -0.546033;0.304383;0.780512;,
  -0.786649;0.405258;0.465779;,
  -0.949798;0.297421;0.097075;,
  -0.522502;0.635270;0.568703;,
  -0.475201;0.737087;0.480507;,
  -0.243857;0.212491;0.946246;,
  -0.000015;0.000003;1.000000;,
  -0.961758;0.153731;-0.226689;,
  -0.000017;0.460905;0.887450;,
  -0.000009;0.801532;0.597952;,
  -0.000008;0.828565;0.559893;,
  -0.000006;0.868120;0.496354;,
  -0.000002;-1.000000;0.000006;,
  0.000006;-0.000001;-1.000000;,
  0.000000;0.000000;-1.000000;,
  0.000011;-0.000001;-1.000000;,
  0.000017;-0.000001;-1.000000;,
  0.000022;0.000000;-1.000000;,
  -0.932429;0.295575;0.207873;,
  -0.000008;-0.817952;-0.575286;,
  -0.222150;0.975012;0.000006;,
  0.000000;0.000000;1.000000;,
  -0.000011;0.000000;1.000000;,
  -0.000022;0.000000;1.000000;,
  1.000000;0.000000;-0.000037;,
  1.000000;0.000000;0.000000;,
  0.000011;0.000000;-1.000000;,
  0.000000;0.000000;-1.000000;,
  -1.000000;0.000000;0.000000;,
  -1.000000;0.000000;0.000050;,
  -1.000000;0.000000;0.000037;,
  -0.000003;-0.828623;-0.559807;,
  0.000004;-0.828623;-0.559807;,
  -0.000004;-0.801477;-0.598026;,
  0.000004;-0.801476;-0.598027;,
  -0.383228;0.889616;0.248436;,
  -0.282026;0.924184;0.257574;,
  -0.383231;0.889619;0.248419;,
  -0.282028;0.924187;0.257562;,
  1.000000;0.000000;-0.000075;,
  0.000022;0.000000;-1.000000;,
  -0.000006;-0.868223;-0.496175;,
  -0.000003;-0.868223;-0.496175;,
  -0.000006;-0.828623;-0.559807;,
  0.000003;-0.868223;-0.496175;,
  0.000007;-0.868223;-0.496174;,
  0.000008;-0.828623;-0.559807;,
  -0.000007;-0.801477;-0.598026;,
  0.000009;-0.801476;-0.598027;,
  -0.000004;-0.817952;-0.575286;,
  0.000004;-0.817952;-0.575287;,
  0.000008;-0.817952;-0.575286;,
  -0.394235;0.919009;0.000019;,
  -0.214477;0.941332;0.260566;,
  -0.289040;0.957317;0.000012;,
  0.000005;1.000000;-0.000010;,
  -0.000001;0.964001;0.265899;,
  -0.214479;0.941334;0.260554;,
  -0.000002;0.964001;0.265897;,
  -0.394238;0.919008;-0.000016;,
  -0.222152;0.975012;-0.000019;,
  -0.289042;0.957317;-0.000015;,
  0.000005;1.000000;-0.000014;,
  -1.000000;0.000000;0.000075;,
  0.000000;-0.000001;1.000000;,
  0.000001;-0.000001;1.000000;,
  -0.000010;-0.000000;1.000000;,
  -0.000022;-0.000000;1.000000;,
  0.000003;0.490488;0.871448;,
  0.000003;0.321385;0.946949;,
  -0.009780;0.313711;0.949468;,
  -0.014910;0.478267;0.878088;,
  1.000000;0.000000;-0.000037;,
  1.000000;0.000000;0.000000;,
  0.000010;0.000001;-1.000000;,
  -0.000001;0.000001;-1.000000;,
  0.000000;0.000001;-1.000000;,
  -1.000000;0.000000;0.000000;,
  -1.000000;-0.000000;0.000037;,
  -0.000009;-0.955092;0.296309;,
  0.533141;-0.545079;-0.647031;,
  0.374159;-0.810177;-0.451241;,
  0.304469;-0.819096;-0.486189;,
  -0.440297;0.770209;0.461430;,
  -0.446231;0.763725;0.466479;,
  -0.457292;0.816846;0.351634;,
  -0.462772;0.817169;0.343622;,
  1.000000;0.000000;-0.000075;,
  0.000022;0.000001;-1.000000;,
  -1.000000;-0.000000;0.000075;,
  0.886144;-0.463281;-0.010975;,
  0.749321;-0.512581;-0.419260;,
  0.000006;-0.887217;-0.461352;,
  0.000012;-0.706342;-0.707871;,
  0.060147;-0.557535;-0.827972;,
  0.159974;-0.868478;-0.469206;,
  0.000017;-0.459432;-0.888213;,
  0.394235;-0.919009;-0.000019;,
  0.222150;-0.975012;-0.000006;,
  0.289040;-0.957317;-0.000012;,
  -0.000005;-1.000000;0.000010;,
  0.000006;0.858970;0.512025;,
  -0.786237;0.524552;0.326614;,
  -0.013090;0.851745;0.523792;,
  0.000008;0.918790;0.394747;,
  -0.011424;0.923940;0.382367;,
  -0.465546;0.850496;0.244793;,
  0.000009;0.960501;0.278276;,
  -0.475551;0.849414;0.228796;,
  -0.022624;0.967377;0.252329;,
  -0.000022;0.956486;0.291778;,
  0.000000;0.000000;-1.000000;,
  0.298897;-0.880343;-0.368315;,
  1.000000;0.000000;0.000000;,
  -0.057542;0.854902;0.515588;,
  0.198115;0.680043;0.705898;,
  0.000014;0.000000;-1.000000;,
  -1.000000;0.000000;0.000000;,
  0.000011;0.000000;-1.000000;,
  0.122960;0.960945;0.247921;,
  -0.278630;0.582395;0.763663;,
  0.199005;-0.966316;-0.163189;,
  0.251320;-0.931458;-0.263104;,
  0.192345;-0.943064;-0.271356;,
  0.241873;0.897414;0.368980;,
  -0.377350;0.138785;0.915612;,
  0.027814;0.306751;0.951383;,
  -0.708830;0.327093;0.624956;,
  -0.535325;0.741553;0.404384;,
  -0.877407;0.440228;0.190672;,
  0.000022;0.000000;-1.000000;,
  0.000022;0.000000;-1.000000;,
  0.000011;0.992927;0.118723;,
  0.230803;-0.906887;-0.352541;,
  0.002314;-0.999997;0.000018;,
  -0.000006;-1.000000;0.000015;,
  0.202505;-0.946826;-0.250023;,
  -0.241914;0.950553;0.194746;,
  0.000024;-0.000002;-1.000000;,
  1.000000;0.000032;-0.000017;,
  -0.000024;0.000001;1.000000;,
  -0.994141;0.106418;0.018970;,
  0.000002;1.000000;-0.000007;,
  0.000004;-0.891123;-0.453761;,
  -0.000000;-0.000001;-1.000000;,
  0.994141;-0.106418;-0.018970;,
  0.930778;-0.333178;-0.150484;,
  0.000001;0.000000;1.000000;,
  -0.963559;0.263107;0.048251;,
  -0.979083;0.193074;0.064182;,
  -0.942833;0.331720;0.032059;,
  0.799718;-0.535707;-0.271053;,
  -0.000001;-0.000001;-1.000000;,
  0.952180;-0.271920;-0.139332;,
  -0.998455;0.034581;0.043502;,
  0.983746;0.178761;0.016987;,
  0.999324;-0.031241;-0.019377;,
  0.646807;-0.681391;-0.342560;,
  0.849594;-0.484292;-0.208928;,
  0.000002;0.000000;1.000000;,
  -0.000000;-0.000001;-1.000000;,
  0.998455;-0.034581;-0.043502;,
  0.000000;0.000000;1.000000;,
  -1.000000;-0.000016;0.000030;,
  -1.000000;-0.000019;-0.000004;,
  -1.000000;-0.000014;0.000065;,
  -1.000000;-0.000021;-0.000003;,
  0.000010;1.000000;-0.000005;,
  0.000013;1.000000;-0.000004;,
  -0.050523;-0.925290;-0.375880;,
  -0.050266;-0.867739;-0.494472;,
  -0.000006;-0.854870;-0.518842;,
  -0.000013;-0.960501;-0.278277;,
  0.000007;1.000000;-0.000007;,
  0.000013;1.000000;-0.000005;,
  -0.983746;-0.178761;-0.016987;,
  0.942833;-0.331720;-0.032059;,
  0.000000;1.000000;-0.000006;,
  0.000000;-0.000000;1.000000;,
  0.000000;0.000000;-1.000000;,
  -1.000000;0.000000;0.000000;,
  -1.000000;-0.000003;0.000006;,
  0.959240;-0.193026;0.206396;,
  -0.127776;-0.444950;-0.886393;,
  -0.226519;-0.788802;-0.571385;,
  0.981943;-0.129218;0.138168;,
  0.970624;-0.238444;-0.032148;,
  0.933540;-0.355259;-0.047898;,
  -1.000000;0.000000;0.000075;,
  -1.000000;-0.000003;0.000043;,
  0.810648;0.428739;0.398790;,
  0.993005;-0.011448;0.117512;,
  0.975577;-0.171954;-0.136679;,
  0.903501;-0.335509;-0.266682;,
  0.757767;0.505696;0.412384;,
  0.652207;0.614547;0.443800;,
  0.000000;-0.000000;1.000000;,
  0.000000;0.000000;-1.000000;,
  0.824338;0.463131;0.325542;,
  0.618017;0.682484;0.390218;,
  -0.000006;-1.000000;0.000005;;
  168;
  4;1,2,2,1;,
  4;2,3,3,2;,
  4;3,4,4,3;,
  4;5,6,6,5;,
  4;6,7,7,6;,
  4;7,0,0,7;,
  4;8,8,9,9;,
  4;9,9,10,10;,
  4;10,10,11,11;,
  3;12,8,8;,
  3;13,13,13;,
  4;16,19,19,16;,
  4;16,16,21,18;,
  4;16,19,22,21;,
  4;19,20,23,22;,
  4;21,22,23,18;,
  4;24,25,30,31;,
  4;26,27,17,32;,
  4;24,33,34,28;,
  4;26,28,29,27;,
  4;28,34,35,29;,
  4;27,29,15,14;,
  4;29,35,36,15;,
  4;37,37,37,37;,
  3;20,19,19;,
  3;30,25,26;,
  3;31,33,24;,
  3;17,27,14;,
  3;38,39,40;,
  3;41,40,42;,
  3;16,16,16;,
  3;25,28,26;,
  3;28,25,43;,
  3;40,41,38;,
  4;46,47,47,46;,
  4;47,48,48,47;,
  4;64,49,49,64;,
  4;49,50,50,49;,
  4;50,50,50,50;,
  4;65,51,51,65;,
  4;51,52,52,51;,
  4;52,52,52,52;,
  4;53,53,53,53;,
  4;53,54,55,53;,
  4;66,67,56,68;,
  4;67,69,57,56;,
  4;69,70,71,57;,
  4;68,56,58,72;,
  4;56,57,59,58;,
  4;57,71,73,59;,
  4;72,58,74,44;,
  4;58,59,75,74;,
  4;59,73,76,75;,
  4;45,77,60,78;,
  4;77,79,61,60;,
  4;79,80,81,61;,
  4;78,60,62,82;,
  4;60,61,63,62;,
  4;61,81,83,63;,
  4;82,62,84,85;,
  4;62,63,86,84;,
  4;63,83,87,86;,
  3;46,46,46;,
  3;88,55,54;,
  3;46,46,46;,
  3;54,88,88;,
  4;89,90,94,93;,
  4;90,91,95,94;,
  4;91,92,96,95;,
  4;112,97,97,112;,
  4;97,98,98,97;,
  4;98,98,98,98;,
  4;113,99,99,113;,
  4;99,100,100,99;,
  4;100,101,101,100;,
  4;102,102,102,102;,
  4;102,103,103,102;,
  4;103,114,114,103;,
  4;104,104,104,104;,
  4;115,115,105,116;,
  4;117,117,118,117;,
  4;119,119,106,120;,
  4;116,105,107,106;,
  4;105,118,121,107;,
  4;120,106,122,123;,
  4;106,107,124,122;,
  4;107,125,125,124;,
  4;93,94,108,126;,
  4;127,127,109,108;,
  4;95,96,128,109;,
  4;126,108,110,129;,
  4;108,109,111,110;,
  4;109,128,130,111;,
  4;129,110,131,132;,
  4;110,111,133,131;,
  4;111,130,134,133;,
  4;143,136,136,141;,
  4;136,136,136,136;,
  4;142,142,142,142;,
  4;146,147,137,148;,
  4;149,135,144,144;,
  4;150,151,145,152;,
  4;152,145,153,154;,
  4;145,140,139,153;,
  3;138,138,138;,
  3;138,138,138;,
  3;140,145,151;,
  3;138,138,138;,
  3;155,143,141;,
  3;141,156,155;,
  3;142,142,142;,
  3;144,144,157;,
  3;137,158,146;,
  3;158,148,137;,
  3;146,148,159;,
  3;147,160,161;,
  3;137,147,161;,
  3;162,162,135;,
  4;163,163,163,163;,
  4;164,164,164,164;,
  4;165,165,165,165;,
  4;166,166,166,166;,
  4;167,167,167,167;,
  4;168,168,168,168;,
  4;169,169,169,169;,
  4;170,170,171,171;,
  4;172,172,172,172;,
  4;173,173,174,174;,
  4;173,175,175,173;,
  4;176,171,171,176;,
  4;177,177,177,177;,
  4;179,179,179,179;,
  4;180,178,181,180;,
  4;182,183,178,182;,
  3;178,183,181;,
  3;184,184,184;,
  4;185,185,185,185;,
  4;186,186,186,186;,
  4;187,187,187,187;,
  4;190,188,188,190;,
  4;188,189,189,188;,
  4;189,191,191,189;,
  4;192,192,193,193;,
  4;194,194,195,195;,
  3;195,196,195;,
  3;194,194,197;,
  3;192,192,198;,
  3;193,199,193;,
  4;201,201,201,201;,
  4;200,200,200,200;,
  4;202,202,202,202;,
  3;203,203,203;,
  3;204,204,204;,
  4;208,209,209,209;,
  4;215,216,210,207;,
  4;216,217,211,210;,
  4;217,218,212,211;,
  4;210,211,212,207;,
  4;214,206,206,214;,
  4;219,219,215,220;,
  3;214,213,214;,
  3;221,221,221;,
  3;206,206,205;,
  3;222,222,208;,
  3;219,223,219;,
  3;222,222,222;,
  3;215,224,220;,
  3;225,225,225;;
 }
 MeshTextureCoords {
  401;
  0.000000;0.000000;,
  0.333330;0.000000;,
  0.333330;1.000000;,
  0.000000;1.000000;,
  0.666670;0.000000;,
  0.666670;1.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;0.000000;,
  0.333330;0.000000;,
  0.333330;1.000000;,
  0.000000;1.000000;,
  0.666670;0.000000;,
  0.666670;1.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  1.000000;0.333330;,
  0.000000;0.333330;,
  1.000000;0.666670;,
  0.000000;0.666670;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.425728;0.867643;,
  0.596087;0.709031;,
  0.123794;0.709030;,
  0.445494;0.639938;,
  0.123777;0.553957;,
  0.596070;0.553957;,
  0.350675;0.592221;,
  0.649337;0.661923;,
  0.649337;0.750861;,
  0.350675;0.750861;,
  0.123778;0.553936;,
  0.350675;0.855538;,
  0.123778;0.969858;,
  0.649337;0.855538;,
  0.876234;0.708998;,
  0.876234;0.969857;,
  0.596087;0.709031;,
  0.425728;0.867643;,
  0.123794;0.969908;,
  0.876240;0.969909;,
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
  0.359173;0.000000;,
  1.000000;0.000008;,
  1.000022;1.000008;,
  0.000023;1.000000;,
  0.859710;0.851260;,
  0.876240;0.709032;,
  0.140290;0.686630;,
  0.394035;0.969910;,
  0.445494;0.639938;,
  0.596070;0.553957;,
  0.876223;0.969910;,
  0.876223;0.553958;,
  0.166670;0.000000;,
  0.500000;0.333330;,
  0.333330;0.000000;,
  0.403944;0.709050;,
  0.596087;0.709050;,
  0.596087;0.437545;,
  0.403944;0.475224;,
  0.876240;0.709050;,
  0.876240;0.437546;,
  0.876234;0.709017;,
  0.649337;0.661923;,
  0.649337;0.437533;,
  0.876234;0.437532;,
  0.350675;0.592221;,
  0.350675;0.384906;,
  0.123778;0.553955;,
  0.123778;0.384907;,
  0.876223;0.553976;,
  0.596070;0.553976;,
  0.596070;0.384916;,
  0.876223;0.384916;,
  0.403927;0.553976;,
  0.403927;0.422595;,
  0.123777;0.553975;,
  0.123777;0.441434;,
  0.123772;0.553954;,
  0.350669;0.592220;,
  0.350669;0.441419;,
  0.123772;0.441420;,
  0.649331;0.661921;,
  0.649331;0.494046;,
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
  0.123794;0.494063;,
  0.876228;0.494045;,
  0.123794;0.709049;,
  0.876228;0.709016;,
  0.123794;0.494063;,
  0.403944;0.475224;,
  0.403944;0.327479;,
  0.123794;0.327478;,
  0.596087;0.437545;,
  0.588790;0.246753;,
  0.876240;0.437546;,
  0.876240;0.241370;,
  0.876234;0.437532;,
  0.649337;0.437533;,
  0.649337;0.200731;,
  0.876235;0.241371;,
  0.350675;0.267137;,
  0.350675;0.149139;,
  0.123778;0.232318;,
  0.123778;0.129740;,
  0.876223;0.232316;,
  0.596070;0.232316;,
  0.588773;0.133672;,
  0.876223;0.129731;,
  0.403927;0.374021;,
  0.403927;0.215839;,
  0.123777;0.374020;,
  0.123777;0.215838;,
  0.123772;0.374011;,
  0.350669;0.353238;,
  0.350669;0.235240;,
  0.123772;0.215841;,
  0.649331;0.494046;,
  0.649331;0.286833;,
  0.876228;0.494045;,
  0.876229;0.327473;,
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
  0.596070;0.384916;,
  0.403927;0.441243;,
  0.403927;0.374021;,
  0.596070;0.232316;,
  0.123777;0.441434;,
  0.123777;0.374020;,
  0.123772;0.441420;,
  0.350669;0.441419;,
  0.350669;0.353238;,
  0.123772;0.374011;,
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
  0.350675;0.267137;,
  0.649337;0.437533;,
  0.350675;0.384906;,
  0.123778;0.384907;,
  0.123778;0.232318;,
  1.000000;0.500000;,
  0.876223;0.384916;,
  0.876223;0.232316;,
  0.649331;0.494046;,
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
  0.650188;0.003886;,
  0.876204;0.003886;,
  0.876223;0.133673;,
  0.588773;0.133672;,
  0.123778;0.003905;,
  0.876234;0.003904;,
  0.876234;0.246754;,
  0.123778;0.133682;,
  0.876221;0.003885;,
  0.650205;0.003885;,
  0.588790;0.246753;,
  0.876240;0.246753;,
  0.859710;0.023860;,
  0.140290;0.023860;,
  0.140290;0.149180;,
  0.859710;0.269230;,
  0.699623;1.000000;,
  0.999998;1.000008;,
  0.999976;0.000008;,
  0.699600;0.000000;,
  0.140290;0.423860;,
  0.859710;0.423860;,
  0.859710;0.423860;,
  0.140290;0.423860;,
  0.479701;0.125451;,
  0.650188;0.003886;,
  0.588773;0.133672;,
  0.403927;0.215839;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.650205;0.003885;,
  0.479717;0.176229;,
  0.403944;0.327479;,
  0.588790;0.246753;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  0.391842;0.003886;,
  0.479701;0.125451;,
  0.403927;0.215839;,
  0.334203;0.215839;,
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
  0.479717;0.176229;,
  0.391859;0.003885;,
  0.403944;0.327479;,
  0.123762;0.003885;,
  0.391842;0.003886;,
  0.334203;0.215839;,
  0.123777;0.215838;,
  0.333330;0.000000;,
  0.666670;0.000000;,
  0.666670;1.000000;,
  0.333330;1.000000;,
  0.391859;0.003885;,
  0.123779;0.003884;,
  0.123794;0.327478;,
  0.403944;0.327479;,
  0.876228;0.003903;,
  0.607139;0.003903;,
  0.649331;0.286833;,
  0.876229;0.327473;,
  0.392861;0.003903;,
  0.350669;0.235240;,
  0.123772;0.003904;,
  0.123772;0.215841;,
  -0.000020;0.642386;,
  0.356281;1.000000;,
  0.356259;0.000000;,
  -0.000020;0.357614;,
  0.000000;0.333330;,
  1.000000;0.333330;,
  1.000000;0.666670;,
  0.000000;0.666670;,
  1.000000;0.833330;,
  0.000000;1.000000;,
  1.000000;0.166670;,
  0.000000;0.000000;,
  0.000002;1.000000;,
  -0.000020;0.000000;,
  0.761290;0.020000;,
  0.761290;0.020000;,
  0.464690;0.194360;,
  0.464690;0.140450;,
  0.311880;0.020000;,
  0.311880;0.020000;,
  0.356281;1.000000;,
  0.699623;1.000000;,
  0.699600;0.000000;,
  0.356259;0.000000;,
  0.479717;0.176229;,
  0.650205;0.003885;,
  0.391859;0.003885;,
  0.479701;0.125451;,
  0.391842;0.003886;,
  0.650188;0.003886;,
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
  0.649331;0.661921;,
  0.350669;0.592220;,
  0.123772;0.969857;,
  0.876228;0.969856;,
  0.666670;0.333330;,
  1.000000;0.333330;,
  1.000000;0.666670;,
  0.666670;0.666670;,
  0.876228;0.708997;,
  0.123794;0.969908;,
  0.425728;0.867643;,
  0.123794;0.709030;,
  0.123772;0.553935;,
  0.394035;0.969910;,
  0.123777;0.553957;,
  0.445494;0.639938;,
  0.166670;0.333330;,
  0.000000;0.000000;,
  0.333330;0.000000;,
  0.123777;0.969909;,
  1.000000;0.833330;,
  0.666670;1.000000;,
  0.000023;1.000000;,
  0.000000;0.000000;,
  0.359173;0.000000;;
 }
}
