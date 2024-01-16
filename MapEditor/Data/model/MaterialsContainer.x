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
 400;
 -5.00000;10.50000;-5.00000;,
 5.00000;10.50000;-5.00000;,
 5.00000;0.50000;-5.00000;,
 -5.00000;0.50000;-5.00000;,
 5.00000;10.50000;-5.00000;,
 5.00000;10.50000;5.00000;,
 5.00000;0.50000;5.00000;,
 5.00000;0.50000;-5.00000;,
 5.00000;10.50000;5.00000;,
 -5.00000;10.50000;5.00000;,
 -5.00000;0.50000;5.00000;,
 5.00000;0.50000;5.00000;,
 -5.00000;10.50000;5.00000;,
 -5.00000;10.50000;-5.00000;,
 -5.00000;0.50000;-5.00000;,
 -5.00000;0.50000;5.00000;,
 5.00000;10.50000;-5.00000;,
 -5.00000;10.50000;-5.00000;,
 -5.00000;0.50000;-5.00000;,
 5.00000;0.50000;-5.00000;,
 4.50000;11.00000;-5.50000;,
 5.50000;11.00000;-5.50000;,
 5.50000;0.00000;-5.50000;,
 4.50000;0.00000;-5.50000;,
 5.50000;11.00000;-5.50000;,
 5.50000;11.00000;-4.50000;,
 5.50000;0.00000;-4.50000;,
 5.50000;0.00000;-5.50000;,
 5.50000;11.00000;-4.50000;,
 4.50000;11.00000;-4.50000;,
 4.50000;0.00000;-4.50000;,
 5.50000;0.00000;-4.50000;,
 4.50000;11.00000;-4.50000;,
 4.50000;11.00000;-5.50000;,
 4.50000;0.00000;-5.50000;,
 4.50000;0.00000;-4.50000;,
 5.50000;11.00000;-5.50000;,
 4.50000;11.00000;-5.50000;,
 4.50000;0.00000;-5.50000;,
 5.50000;0.00000;-5.50000;,
 4.50000;11.00000;4.50000;,
 5.50000;11.00000;4.50000;,
 5.50000;0.00000;4.50000;,
 4.50000;0.00000;4.50000;,
 5.50000;11.00000;4.50000;,
 5.50000;11.00000;5.50000;,
 5.50000;0.00000;5.50000;,
 5.50000;0.00000;4.50000;,
 5.50000;11.00000;5.50000;,
 4.50000;11.00000;5.50000;,
 4.50000;0.00000;5.50000;,
 5.50000;0.00000;5.50000;,
 4.50000;11.00000;5.50000;,
 4.50000;11.00000;4.50000;,
 4.50000;0.00000;4.50000;,
 4.50000;0.00000;5.50000;,
 5.50000;11.00000;4.50000;,
 4.50000;11.00000;4.50000;,
 4.50000;0.00000;4.50000;,
 5.50000;0.00000;4.50000;,
 -4.50000;11.00000;4.50000;,
 -4.50000;0.00000;4.50000;,
 -5.50000;0.00000;4.50000;,
 -5.50000;11.00000;4.50000;,
 -5.50000;11.00000;4.50000;,
 -5.50000;0.00000;4.50000;,
 -5.50000;0.00000;5.50000;,
 -5.50000;11.00000;5.50000;,
 -5.50000;11.00000;5.50000;,
 -5.50000;0.00000;5.50000;,
 -4.50000;0.00000;5.50000;,
 -4.50000;11.00000;5.50000;,
 -4.50000;11.00000;5.50000;,
 -4.50000;0.00000;5.50000;,
 -4.50000;0.00000;4.50000;,
 -4.50000;11.00000;4.50000;,
 -4.50000;11.00000;4.50000;,
 -5.50000;11.00000;4.50000;,
 -4.50000;0.00000;4.50000;,
 -5.50000;0.00000;4.50000;,
 -4.50000;11.00000;-5.50000;,
 -4.50000;0.00000;-5.50000;,
 -5.50000;0.00000;-5.50000;,
 -5.50000;11.00000;-5.50000;,
 -5.50000;11.00000;-5.50000;,
 -5.50000;0.00000;-5.50000;,
 -5.50000;0.00000;-4.50000;,
 -5.50000;11.00000;-4.50000;,
 -5.50000;11.00000;-4.50000;,
 -5.50000;0.00000;-4.50000;,
 -4.50000;0.00000;-4.50000;,
 -4.50000;11.00000;-4.50000;,
 -4.50000;11.00000;-4.50000;,
 -4.50000;0.00000;-4.50000;,
 -4.50000;0.00000;-5.50000;,
 -4.50000;11.00000;-5.50000;,
 -4.50000;11.00000;-5.50000;,
 -5.50000;11.00000;-5.50000;,
 -4.50000;0.00000;-5.50000;,
 -5.50000;0.00000;-5.50000;,
 -4.50000;11.00000;5.50000;,
 -4.50000;11.00000;-5.50000;,
 -5.50000;11.00000;-5.50000;,
 -5.50000;11.00000;5.50000;,
 -5.50000;11.00000;5.50000;,
 -5.50000;11.00000;-5.50000;,
 -5.50000;10.00000;-5.50000;,
 -5.50000;10.00000;5.50000;,
 -5.50000;10.00000;5.50000;,
 -5.50000;10.00000;-5.50000;,
 -4.50000;10.00000;-5.50000;,
 -4.50000;10.00000;5.50000;,
 -4.50000;10.00000;5.50000;,
 -4.50000;10.00000;-5.50000;,
 -4.50000;11.00000;-5.50000;,
 -4.50000;11.00000;5.50000;,
 -4.50000;11.00000;5.50000;,
 -5.50000;11.00000;5.50000;,
 -4.50000;11.00000;-5.50000;,
 -5.50000;11.00000;-5.50000;,
 -4.50000;1.00000;5.50000;,
 -4.50000;1.00000;-5.50000;,
 -5.50000;1.00000;-5.50000;,
 -5.50000;1.00000;5.50000;,
 -5.50000;1.00000;5.50000;,
 -5.50000;1.00000;-5.50000;,
 -5.50000;0.00000;-5.50000;,
 -5.50000;0.00000;5.50000;,
 -5.50000;0.00000;5.50000;,
 -5.50000;0.00000;-5.50000;,
 -4.50000;0.00000;-5.50000;,
 -4.50000;0.00000;5.50000;,
 -4.50000;0.00000;5.50000;,
 -4.50000;0.00000;-5.50000;,
 -4.50000;1.00000;-5.50000;,
 -4.50000;1.00000;5.50000;,
 -4.50000;1.00000;5.50000;,
 -5.50000;1.00000;5.50000;,
 -4.50000;1.00000;-5.50000;,
 -5.50000;1.00000;-5.50000;,
 4.50000;1.00000;5.50000;,
 5.50000;1.00000;5.50000;,
 5.50000;1.00000;-5.50000;,
 4.50000;1.00000;-5.50000;,
 5.50000;1.00000;5.50000;,
 5.50000;-0.00000;5.50000;,
 5.50000;0.00000;-5.50000;,
 5.50000;1.00000;-5.50000;,
 5.50000;-0.00000;5.50000;,
 4.50000;-0.00000;5.50000;,
 4.50000;0.00000;-5.50000;,
 5.50000;0.00000;-5.50000;,
 4.50000;-0.00000;5.50000;,
 4.50000;1.00000;5.50000;,
 4.50000;1.00000;-5.50000;,
 4.50000;0.00000;-5.50000;,
 5.50000;1.00000;5.50000;,
 4.50000;1.00000;5.50000;,
 4.50000;1.00000;-5.50000;,
 5.50000;1.00000;-5.50000;,
 4.50000;11.00000;5.50000;,
 5.50000;11.00000;5.50000;,
 5.50000;11.00000;-5.50000;,
 4.50000;11.00000;-5.50000;,
 5.50000;11.00000;5.50000;,
 5.50000;10.00000;5.50000;,
 5.50000;10.00000;-5.50000;,
 5.50000;11.00000;-5.50000;,
 5.50000;10.00000;5.50000;,
 4.50000;10.00000;5.50000;,
 4.50000;10.00000;-5.50000;,
 5.50000;10.00000;-5.50000;,
 4.50000;10.00000;5.50000;,
 4.50000;11.00000;5.50000;,
 4.50000;11.00000;-5.50000;,
 4.50000;10.00000;-5.50000;,
 5.50000;11.00000;5.50000;,
 4.50000;11.00000;5.50000;,
 4.50000;11.00000;-5.50000;,
 5.50000;11.00000;-5.50000;,
 5.50000;11.00000;-4.50000;,
 5.50000;11.00000;-5.50000;,
 -5.50000;11.00000;-5.50000;,
 -5.50000;11.00000;-4.50000;,
 5.50000;11.00000;-5.50000;,
 5.50000;10.00000;-5.50000;,
 -5.50000;10.00000;-5.50000;,
 -5.50000;11.00000;-5.50000;,
 5.50000;10.00000;-5.50000;,
 5.50000;10.00000;-4.50000;,
 -5.50000;10.00000;-4.50000;,
 -5.50000;10.00000;-5.50000;,
 5.50000;10.00000;-4.50000;,
 5.50000;11.00000;-4.50000;,
 -5.50000;11.00000;-4.50000;,
 -5.50000;10.00000;-4.50000;,
 5.50000;11.00000;-5.50000;,
 5.50000;11.00000;-4.50000;,
 -5.50000;11.00000;-4.50000;,
 -5.50000;11.00000;-5.50000;,
 5.50000;1.00000;-4.50000;,
 5.50000;1.00000;-5.50000;,
 -5.50000;1.00000;-5.50000;,
 -5.50000;1.00000;-4.50000;,
 5.50000;1.00000;-5.50000;,
 5.50000;0.00000;-5.50000;,
 -5.50000;0.00000;-5.50000;,
 -5.50000;1.00000;-5.50000;,
 5.50000;0.00000;-5.50000;,
 5.50000;0.00000;-4.50000;,
 -5.50000;0.00000;-4.50000;,
 -5.50000;0.00000;-5.50000;,
 5.50000;0.00000;-4.50000;,
 5.50000;1.00000;-4.50000;,
 -5.50000;1.00000;-4.50000;,
 -5.50000;0.00000;-4.50000;,
 5.50000;1.00000;-5.50000;,
 5.50000;1.00000;-4.50000;,
 -5.50000;1.00000;-4.50000;,
 -5.50000;1.00000;-5.50000;,
 5.50000;1.00000;4.50000;,
 -5.50000;1.00000;4.50000;,
 -5.50000;1.00000;5.50000;,
 5.50000;1.00000;5.50000;,
 5.50000;1.00000;5.50000;,
 -5.50000;1.00000;5.50000;,
 -5.50000;0.00000;5.50000;,
 5.50000;0.00000;5.50000;,
 5.50000;0.00000;5.50000;,
 -5.50000;0.00000;5.50000;,
 -5.50000;0.00000;4.50000;,
 5.50000;0.00000;4.50000;,
 5.50000;0.00000;4.50000;,
 -5.50000;0.00000;4.50000;,
 -5.50000;1.00000;4.50000;,
 5.50000;1.00000;4.50000;,
 5.50000;1.00000;4.50000;,
 5.50000;1.00000;5.50000;,
 -5.50000;1.00000;4.50000;,
 -5.50000;1.00000;5.50000;,
 5.50000;11.00000;4.50000;,
 -5.50000;11.00000;4.50000;,
 -5.50000;11.00000;5.50000;,
 5.50000;11.00000;5.50000;,
 5.50000;11.00000;5.50000;,
 -5.50000;11.00000;5.50000;,
 -5.50000;10.00000;5.50000;,
 5.50000;10.00000;5.50000;,
 5.50000;10.00000;5.50000;,
 -5.50000;10.00000;5.50000;,
 -5.50000;10.00000;4.50000;,
 5.50000;10.00000;4.50000;,
 5.50000;10.00000;4.50000;,
 -5.50000;10.00000;4.50000;,
 -5.50000;11.00000;4.50000;,
 5.50000;11.00000;4.50000;,
 5.50000;11.00000;4.50000;,
 5.50000;11.00000;5.50000;,
 -5.50000;11.00000;4.50000;,
 -5.50000;11.00000;5.50000;,
 5.46066;0.81933;5.03930;,
 4.57678;-0.06455;5.03930;,
 -5.14594;9.65817;5.03930;,
 -4.26206;10.54205;5.03930;,
 4.57678;-0.06455;5.03930;,
 4.57678;-0.06455;5.17996;,
 -5.14594;9.65817;5.17996;,
 -5.14594;9.65817;5.03930;,
 4.57678;-0.06455;5.17996;,
 5.46066;0.81933;5.17996;,
 -4.26206;10.54205;5.17996;,
 -5.14594;9.65817;5.17996;,
 5.46066;0.81933;5.17996;,
 5.46066;0.81933;5.03930;,
 -4.26206;10.54205;5.03930;,
 -4.26206;10.54205;5.17996;,
 4.57678;-0.06455;5.03930;,
 5.46066;0.81933;5.03930;,
 -4.26206;10.54205;5.03930;,
 -5.14594;9.65817;5.03930;,
 -5.46066;0.81933;-5.16868;,
 4.26206;10.54205;-5.16868;,
 5.14594;9.65817;-5.16868;,
 -4.57678;-0.06455;-5.16868;,
 -4.57678;-0.06455;-5.16868;,
 5.14594;9.65817;-5.16868;,
 5.14594;9.65817;-5.02802;,
 -4.57678;-0.06455;-5.02802;,
 -4.57678;-0.06455;-5.02802;,
 5.14594;9.65817;-5.02802;,
 4.26206;10.54205;-5.02802;,
 -5.46066;0.81933;-5.02802;,
 -5.46066;0.81933;-5.02802;,
 4.26206;10.54205;-5.02802;,
 4.26206;10.54205;-5.16868;,
 -5.46066;0.81933;-5.16868;,
 -5.46066;0.81933;-5.16868;,
 -4.57678;-0.06455;-5.16868;,
 4.26206;10.54205;-5.16868;,
 5.14594;9.65817;-5.16868;,
 -5.03366;10.69941;4.42506;,
 -5.03366;9.81553;5.30894;,
 -5.03366;0.09281;-4.41378;,
 -5.03366;0.97669;-5.29766;,
 -5.03366;9.81553;5.30894;,
 -5.17432;9.81553;5.30894;,
 -5.17432;0.09281;-4.41378;,
 -5.03366;0.09281;-4.41378;,
 -5.17432;9.81553;5.30894;,
 -5.17432;10.69941;4.42506;,
 -5.17432;0.97669;-5.29766;,
 -5.17432;0.09281;-4.41378;,
 -5.17432;10.69941;4.42506;,
 -5.03366;10.69941;4.42506;,
 -5.03366;0.97669;-5.29766;,
 -5.17432;0.97669;-5.29766;,
 -5.03366;9.81553;5.30894;,
 -5.03366;10.69941;4.42506;,
 -5.03366;0.97669;-5.29766;,
 -5.03366;0.09281;-4.41378;,
 5.17432;-0.22191;4.42506;,
 5.17432;9.50081;-5.29766;,
 5.17432;10.38469;-4.41378;,
 5.17432;0.66197;5.30894;,
 5.17432;0.66197;5.30894;,
 5.17432;10.38469;-4.41378;,
 5.03366;10.38469;-4.41378;,
 5.03366;0.66197;5.30894;,
 5.03366;0.66197;5.30894;,
 5.03366;10.38469;-4.41378;,
 5.03366;9.50081;-5.29766;,
 5.03366;-0.22191;4.42506;,
 5.03366;-0.22191;4.42506;,
 5.03366;9.50081;-5.29766;,
 5.17432;9.50081;-5.29766;,
 5.17432;-0.22191;4.42506;,
 5.17432;-0.22191;4.42506;,
 5.17432;0.66197;5.30894;,
 5.17432;9.50081;-5.29766;,
 5.17432;10.38469;-4.41378;,
 5.17432;0.66197;-5.29766;,
 5.17432;10.38469;4.42506;,
 5.17432;9.50080;5.30894;,
 5.17432;-0.22191;-4.41378;,
 5.17432;-0.22191;-4.41378;,
 5.17432;9.50080;5.30894;,
 5.03366;9.50080;5.30894;,
 5.03366;-0.22191;-4.41378;,
 5.03366;-0.22191;-4.41378;,
 5.03366;9.50080;5.30894;,
 5.03366;10.38469;4.42506;,
 5.03366;0.66197;-5.29766;,
 5.03366;0.66197;-5.29766;,
 5.03366;10.38469;4.42506;,
 5.17432;10.38469;4.42506;,
 5.17432;0.66197;-5.29766;,
 5.17432;0.66197;-5.29766;,
 5.17432;-0.22191;-4.41378;,
 5.17432;10.38469;4.42506;,
 5.17432;9.50080;5.30894;,
 -5.37070;10.57301;4.42506;,
 4.35202;10.57301;-5.29766;,
 5.23590;10.57300;-4.41378;,
 -4.48682;10.57301;5.30894;,
 -4.48682;10.57301;5.30894;,
 5.23590;10.57300;-4.41378;,
 5.23590;10.71366;-4.41378;,
 -4.48682;10.71367;5.30894;,
 -4.48682;10.71367;5.30894;,
 5.23590;10.71366;-4.41378;,
 4.35202;10.71367;-5.29766;,
 -5.37070;10.71367;4.42506;,
 -5.37070;10.71367;4.42506;,
 4.35202;10.71367;-5.29766;,
 4.35202;10.57301;-5.29766;,
 -5.37070;10.57301;4.42506;,
 -5.37070;10.57301;4.42506;,
 -4.48682;10.57301;5.30894;,
 4.35202;10.57301;-5.29766;,
 5.23590;10.57300;-4.41378;,
 -4.48682;10.57301;-5.29766;,
 5.23590;10.57300;4.42506;,
 4.35202;10.57300;5.30894;,
 -5.37070;10.57301;-4.41378;,
 -5.37070;10.57301;-4.41378;,
 4.35202;10.57300;5.30894;,
 4.35202;10.71366;5.30894;,
 -5.37070;10.71367;-4.41378;,
 -5.37070;10.71367;-4.41378;,
 4.35202;10.71366;5.30894;,
 5.23590;10.71366;4.42506;,
 -4.48682;10.71367;-5.29766;,
 -4.48682;10.71367;-5.29766;,
 5.23590;10.71366;4.42506;,
 5.23590;10.57300;4.42506;,
 -4.48682;10.57301;-5.29766;,
 -4.48682;10.57301;-5.29766;,
 -5.37070;10.57301;-4.41378;,
 5.23590;10.57300;4.42506;,
 4.35202;10.57300;5.30894;;
 
 120;
 4;0,1,2,3;,
 4;4,5,6,7;,
 4;8,9,10,11;,
 4;12,13,14,15;,
 4;12,5,16,17;,
 4;18,19,6,15;,
 4;20,21,22,23;,
 4;24,25,26,27;,
 4;28,29,30,31;,
 4;32,33,34,35;,
 4;32,25,36,37;,
 4;38,39,26,35;,
 4;40,41,42,43;,
 4;44,45,46,47;,
 4;48,49,50,51;,
 4;52,53,54,55;,
 4;52,45,56,57;,
 4;58,59,46,55;,
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
 4;152,145,156,157;,
 4;158,159,146,155;,
 4;160,161,162,163;,
 4;164,165,166,167;,
 4;168,169,170,171;,
 4;172,173,174,175;,
 4;172,165,176,177;,
 4;178,179,166,175;,
 4;180,181,182,183;,
 4;184,185,186,187;,
 4;188,189,190,191;,
 4;192,193,194,195;,
 4;192,185,196,197;,
 4;198,199,186,195;,
 4;200,201,202,203;,
 4;204,205,206,207;,
 4;208,209,210,211;,
 4;212,213,214,215;,
 4;212,205,216,217;,
 4;218,219,206,215;,
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
 4;272,265,276,277;,
 4;278,279,266,275;,
 4;280,281,282,283;,
 4;284,285,286,287;,
 4;288,289,290,291;,
 4;292,293,294,295;,
 4;292,296,297,287;,
 4;298,293,286,299;,
 4;300,301,302,303;,
 4;304,305,306,307;,
 4;308,309,310,311;,
 4;312,313,314,315;,
 4;312,305,316,317;,
 4;318,319,306,315;,
 4;320,321,322,323;,
 4;324,325,326,327;,
 4;328,329,330,331;,
 4;332,333,334,335;,
 4;332,336,337,327;,
 4;338,333,326,339;,
 4;340,341,342,343;,
 4;344,345,346,347;,
 4;348,349,350,351;,
 4;352,353,354,355;,
 4;352,356,357,347;,
 4;358,353,346,359;,
 4;360,361,362,363;,
 4;364,365,366,367;,
 4;368,369,370,371;,
 4;372,373,374,375;,
 4;372,376,377,367;,
 4;378,373,366,379;,
 4;380,381,382,383;,
 4;384,385,386,387;,
 4;388,389,390,391;,
 4;392,393,394,395;,
 4;392,396,397,387;,
 4;398,393,386,399;;
 
 MeshMaterialList {
  2;
  120;
  0,
  0,
  0,
  0,
  0,
  0,
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
  1;;
  Material {
   0.674400;0.630400;0.432800;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
   TextureFilename {
    "Data\\texture\\Palm.png";
   }
  }
  Material {
   0.483200;0.452000;0.310400;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
 }
 MeshNormals {
  48;
  0.000000;0.000000;-1.000000;,
  1.000000;0.000000;0.000000;,
  0.000000;0.000000;1.000000;,
  -1.000000;0.000000;0.000000;,
  0.000000;1.000000;0.000000;,
  0.000000;-1.000000;-0.000000;,
  0.000000;0.000000;-1.000000;,
  1.000000;0.000000;0.000000;,
  0.000000;0.000000;1.000000;,
  -1.000000;0.000000;0.000000;,
  0.000000;1.000000;0.000000;,
  0.000000;-1.000000;-0.000000;,
  0.000000;0.000000;-1.000000;,
  -0.707107;-0.707107;0.000000;,
  0.000000;0.000000;1.000000;,
  0.707107;0.707107;0.000000;,
  0.707107;-0.707107;-0.000000;,
  -0.707107;0.707107;0.000000;,
  0.000000;0.000000;-1.000000;,
  0.707107;-0.707107;-0.000000;,
  0.000000;-0.000000;1.000000;,
  -0.707107;0.707107;0.000000;,
  -0.707107;-0.707107;0.000000;,
  0.707107;0.707107;0.000000;,
  1.000000;0.000000;0.000000;,
  0.000000;-0.707107;0.707107;,
  -1.000000;0.000000;0.000000;,
  0.000000;0.707107;-0.707107;,
  0.000000;0.707107;0.707107;,
  0.000000;-0.707107;-0.707107;,
  1.000000;0.000000;0.000000;,
  0.000000;0.707107;0.707107;,
  -1.000000;0.000000;0.000000;,
  0.000000;-0.707107;0.707106;,
  0.000000;-0.707107;-0.707107;,
  0.000000;-0.707107;0.707107;,
  0.000000;0.707107;-0.707107;,
  0.000000;0.707107;-0.707107;,
  0.000000;-0.707107;-0.707107;,
  0.000000;0.707103;0.707111;,
  -0.000003;-1.000000;-0.000003;,
  0.707107;0.000000;0.707107;,
  0.000003;1.000000;0.000003;,
  -0.000001;-1.000000;-0.000001;,
  -0.707107;0.000000;0.707107;,
  0.000001;1.000000;0.000001;,
  -0.707107;0.000000;-0.707107;,
  0.707107;0.000000;-0.707107;;
  120;
  4;0,0,0,0;,
  4;1,1,1,1;,
  4;2,2,2,2;,
  4;3,3,3,3;,
  4;4,4,4,4;,
  4;5,5,5,5;,
  4;6,6,6,6;,
  4;7,7,7,7;,
  4;8,8,8,8;,
  4;9,9,9,9;,
  4;10,10,10,10;,
  4;11,11,11,11;,
  4;6,6,6,6;,
  4;7,7,7,7;,
  4;8,8,8,8;,
  4;9,9,9,9;,
  4;10,10,10,10;,
  4;11,11,11,11;,
  4;6,6,6,6;,
  4;9,9,9,9;,
  4;8,8,8,8;,
  4;7,7,7,7;,
  4;10,10,10,10;,
  4;11,11,11,11;,
  4;6,6,6,6;,
  4;9,9,9,9;,
  4;8,8,8,8;,
  4;7,7,7,7;,
  4;10,10,10,10;,
  4;11,11,11,11;,
  4;10,10,10,10;,
  4;9,9,9,9;,
  4;11,11,11,11;,
  4;7,7,7,7;,
  4;8,8,8,8;,
  4;6,6,6,6;,
  4;10,10,10,10;,
  4;9,9,9,9;,
  4;11,11,11,11;,
  4;7,7,7,7;,
  4;8,8,8,8;,
  4;6,6,6,6;,
  4;10,10,10,10;,
  4;7,7,7,7;,
  4;11,11,11,11;,
  4;9,9,9,9;,
  4;8,8,8,8;,
  4;6,6,6,6;,
  4;10,10,10,10;,
  4;7,7,7,7;,
  4;11,11,11,11;,
  4;9,9,9,9;,
  4;8,8,8,8;,
  4;6,6,6,6;,
  4;10,10,10,10;,
  4;6,6,6,6;,
  4;11,11,11,11;,
  4;8,8,8,8;,
  4;7,7,7,7;,
  4;9,9,9,9;,
  4;10,10,10,10;,
  4;6,6,6,6;,
  4;11,11,11,11;,
  4;8,8,8,8;,
  4;7,7,7,7;,
  4;9,9,9,9;,
  4;10,10,10,10;,
  4;8,8,8,8;,
  4;11,11,11,11;,
  4;6,6,6,6;,
  4;7,7,7,7;,
  4;9,9,9,9;,
  4;10,10,10,10;,
  4;8,8,8,8;,
  4;11,11,11,11;,
  4;6,6,6,6;,
  4;7,7,7,7;,
  4;9,9,9,9;,
  4;12,12,12,12;,
  4;13,13,13,13;,
  4;14,14,14,14;,
  4;15,15,15,15;,
  4;16,16,16,16;,
  4;17,17,17,17;,
  4;18,18,18,18;,
  4;19,19,19,19;,
  4;20,20,20,20;,
  4;21,21,21,21;,
  4;22,22,22,22;,
  4;23,23,23,23;,
  4;24,24,24,24;,
  4;25,25,25,25;,
  4;26,26,26,26;,
  4;27,27,27,27;,
  4;28,28,28,28;,
  4;29,29,29,29;,
  4;30,30,30,30;,
  4;31,31,31,31;,
  4;32,32,32,32;,
  4;34,34,34,34;,
  4;35,35,35,35;,
  4;36,36,36,36;,
  4;30,30,30,30;,
  4;33,33,33,33;,
  4;32,32,32,32;,
  4;37,37,37,37;,
  4;38,38,38,38;,
  4;39,39,39,39;,
  4;40,40,40,40;,
  4;41,41,41,41;,
  4;42,42,42,42;,
  4;46,46,46,46;,
  4;44,44,44,44;,
  4;47,47,47,47;,
  4;43,43,43,43;,
  4;44,44,44,44;,
  4;45,45,45,45;,
  4;47,47,47,47;,
  4;46,46,46,46;,
  4;41,41,41,41;;
 }
 MeshTextureCoords {
  400;
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
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
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
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
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
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
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
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
