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
 34.20459;93.75289;-32.40000;,
 34.20459;86.42010;-15.05304;,
 -19.40610;69.95376;-15.05304;,
 -19.40610;77.28654;-32.40000;,
 34.20459;73.07049;15.05304;,
 -39.02802;56.60415;15.05304;,
 34.20459;64.05411;32.40000;,
 -26.44947;19.25028;32.40000;,
 -111.00000;64.05423;32.40000;,
 -111.00000;73.07061;15.05304;,
 -39.02802;56.60415;15.05304;,
 -26.44947;19.25028;32.40000;,
 -111.00000;86.42023;-15.05304;,
 -19.40610;69.95376;-15.05304;,
 -111.00000;93.75301;-32.40000;,
 -19.40610;77.28654;-32.40000;,
 34.20459;73.07049;15.05304;,
 -111.00000;73.07061;15.05304;,
 34.20459;86.42010;-15.05304;,
 -111.00000;86.42023;-15.05304;,
 34.20459;93.75289;-32.40000;,
 -111.00000;93.75301;-32.40000;,
 -26.44947;19.25028;32.40000;,
 34.20459;64.05411;32.40000;,
 -111.00000;64.05423;32.40000;,
 -19.40610;77.28654;-32.40000;,
 -111.00000;93.75301;-32.40000;,
 34.20459;93.75289;-32.40000;,
 111.00000;86.42023;-15.05304;,
 111.00000;73.07061;15.05304;,
 111.00000;56.03670;15.05304;,
 111.00000;56.03670;-15.05304;,
 111.00000;93.75301;-32.40000;,
 111.00000;35.98836;-15.05304;,
 111.00000;0.00012;-32.40000;,
 111.00000;35.98836;15.05304;,
 111.00000;64.05423;32.40000;,
 111.00000;0.00012;32.40000;,
 34.20459;64.05411;32.40000;,
 -26.44947;19.25028;32.40000;,
 -111.00000;0.00012;32.40000;,
 111.00000;0.00012;32.40000;,
 -39.02802;56.60415;15.05304;,
 -19.40610;69.95376;-15.05304;,
 -37.72737;0.00000;-32.40000;,
 -111.00000;0.00012;32.40000;,
 34.20459;64.05411;32.40000;,
 111.00000;64.05423;32.40000;,
 111.00000;73.07061;15.05304;,
 34.20459;73.07049;15.05304;,
 -39.02802;56.60415;15.05304;,
 34.20459;73.07049;15.05304;,
 34.20459;86.42010;-15.05304;,
 -19.40610;69.95376;-15.05304;,
 111.00000;86.42023;-15.05304;,
 34.20459;86.42010;-15.05304;,
 34.20459;93.75289;-32.40000;,
 -19.40610;77.28654;-32.40000;,
 111.00000;93.75301;-32.40000;,
 34.20459;93.75289;-32.40000;,
 -37.72737;0.00000;-32.40000;,
 111.00000;0.00012;-32.40000;,
 111.00000;0.00012;32.40000;,
 -111.00000;0.00012;32.40000;,
 -26.44947;19.25028;32.40000;,
 111.00000;64.05423;32.40000;,
 -19.40610;77.28654;-32.40000;,
 -37.72737;0.00000;-32.40000;,
 -19.40610;77.28654;-32.40000;,
 34.20459;93.75289;-32.40000;,
 111.00000;0.00012;-32.40000;,
 111.00000;93.75301;-32.40000;,
 -26.44947;19.25028;32.40000;,
 34.20459;73.07049;15.05304;,
 -26.44947;19.25028;32.40000;,
 -34.20567;64.05051;32.40000;,
 34.20459;64.05051;32.40000;,
 34.20459;116.04681;32.40000;,
 -34.20567;108.83088;32.40000;,
 111.00000;64.05063;32.40000;,
 111.00000;116.04693;32.40000;,
 111.00000;64.05063;32.40000;,
 111.00000;73.07061;15.05304;,
 111.00000;116.04697;15.05304;,
 111.00000;116.04693;32.40000;,
 111.00000;86.42023;-15.05304;,
 111.00000;126.12642;-15.05304;,
 111.00000;93.74940;-32.40000;,
 111.00000;126.12642;-32.40000;,
 111.00000;93.74940;-32.40000;,
 34.20459;93.74928;-32.40000;,
 34.20459;126.12630;-32.40000;,
 111.00000;126.12642;-32.40000;,
 -34.20567;93.74928;-32.40000;,
 -34.20567;118.91034;-32.40000;,
 -111.00000;93.74940;-32.40000;,
 -111.00000;115.30236;-32.40000;,
 -111.00000;93.74940;-32.40000;,
 -111.00000;86.42023;-15.05304;,
 -111.00000;115.30236;-15.05304;,
 -111.00000;115.30236;-32.40000;,
 -111.00000;73.07061;15.05304;,
 -111.00000;105.22299;15.05304;,
 -111.00000;93.74940;-32.40000;,
 -34.20567;93.74928;-32.40000;,
 -34.20567;86.42010;-15.05304;,
 -111.00000;86.42023;-15.05304;,
 34.20459;93.74928;-32.40000;,
 34.20459;86.42010;-15.05304;,
 111.00000;93.74940;-32.40000;,
 111.00000;86.42023;-15.05304;,
 -34.20567;73.07049;15.05304;,
 -111.00000;73.07061;15.05304;,
 34.20459;73.07049;15.05304;,
 111.00000;73.07061;15.05304;,
 -34.20567;64.05051;32.40000;,
 -111.00000;64.05063;32.40000;,
 34.20459;64.05051;32.40000;,
 111.00000;64.05063;32.40000;,
 -111.00000;105.22299;32.40000;,
 -34.20567;108.83088;32.40000;,
 -34.20567;108.83092;15.05304;,
 -111.00000;105.22299;15.05304;,
 34.20459;116.04681;32.40000;,
 34.20459;116.04685;15.05304;,
 111.00000;116.04693;32.40000;,
 111.00000;116.04697;15.05304;,
 -34.20567;118.91032;-15.05304;,
 -111.00000;115.30236;-15.05304;,
 34.20459;126.12627;-15.05304;,
 111.00000;126.12642;-15.05304;,
 -34.20567;118.91034;-32.40000;,
 -111.00000;115.30236;-32.40000;,
 34.20459;126.12630;-32.40000;,
 111.00000;126.12642;-32.40000;,
 -111.00000;105.22299;32.40000;,
 -111.00000;105.22299;32.40000;,
 -111.00000;64.05063;32.40000;,
 -111.00000;64.05063;32.40000;,
 -111.00000;105.22299;32.40000;,
 -34.20567;108.83088;32.40000;,
 -34.20567;137.12583;32.40003;,
 -111.00000;137.12595;32.40003;,
 34.20459;116.04681;32.40000;,
 31.60671;152.58570;32.40000;,
 111.00000;116.04693;32.40000;,
 111.00000;153.61687;32.40003;,
 111.00000;116.04693;32.40000;,
 111.00000;116.04697;15.05304;,
 111.00000;161.40061;15.05307;,
 111.00000;153.61687;32.40003;,
 111.00000;148.68226;-15.05304;,
 111.00000;171.28179;-15.05301;,
 111.00000;155.35117;-32.40000;,
 111.00000;174.99746;-32.39997;,
 111.00000;155.35117;-32.40000;,
 34.20459;155.35104;-32.40000;,
 31.60671;174.24222;-32.40000;,
 111.00000;174.99746;-32.39997;,
 -34.20567;128.21286;-32.40000;,
 -34.20567;158.50654;-32.39997;,
 -111.00000;128.21298;-32.40000;,
 -111.00000;158.50667;-32.39997;,
 -111.00000;128.21298;-32.40000;,
 -111.00000;132.19134;-15.05304;,
 -111.00000;154.79094;-15.05301;,
 -111.00000;158.50667;-32.39997;,
 -111.00000;105.22299;15.05304;,
 -111.00000;144.90964;15.05307;,
 -111.00000;105.22299;32.40000;,
 -111.00000;137.12595;32.40003;,
 -111.00000;128.21298;-32.40000;,
 -34.20567;128.21286;-32.40000;,
 -34.20567;132.19122;-15.05304;,
 -111.00000;132.19134;-15.05304;,
 34.20459;155.35104;-32.40000;,
 34.20459;148.68210;-15.05304;,
 111.00000;155.35117;-32.40000;,
 111.00000;148.68226;-15.05304;,
 -34.20567;108.83092;15.05304;,
 -111.00000;105.22299;15.05304;,
 34.20459;116.04685;15.05304;,
 111.00000;116.04697;15.05304;,
 -34.20567;108.83088;32.40000;,
 -111.00000;105.22299;32.40000;,
 34.20459;116.04681;32.40000;,
 111.00000;116.04693;32.40000;,
 -111.00000;137.12595;32.40003;,
 -34.20567;137.12583;32.40003;,
 -34.20567;144.90952;15.05307;,
 -111.00000;144.90964;15.05307;,
 31.60671;152.58570;32.40000;,
 34.20459;161.40046;15.05307;,
 111.00000;153.61687;32.40003;,
 111.00000;161.40061;15.05307;,
 -34.20567;154.79083;-15.05301;,
 -111.00000;154.79094;-15.05301;,
 34.20459;171.28168;-15.05301;,
 111.00000;171.28179;-15.05301;,
 -34.20567;158.50654;-32.39997;,
 -111.00000;158.50667;-32.39997;,
 31.60671;174.24222;-32.40000;,
 111.00000;174.99746;-32.39997;,
 34.20459;126.12630;-32.40000;,
 -34.20567;115.33905;-32.40000;,
 -34.20567;128.21286;-32.40000;,
 34.20459;155.35104;-32.40000;,
 -111.00000;115.30236;-32.40000;,
 -111.00000;128.21298;-32.40000;,
 -111.00000;115.30236;-32.40000;,
 -111.00000;115.30236;-15.05304;,
 -111.00000;132.19134;-15.05304;,
 -111.00000;128.21298;-32.40000;,
 -34.20567;115.33905;-32.40000;,
 34.20459;126.12630;-32.40000;,
 111.00000;116.04697;15.05304;,
 -111.00000;115.30236;-15.05304;,
 -111.00000;132.19134;-15.05304;,
 -111.00000;105.22299;15.05304;,
 -34.57332;126.16239;-7.34517;,
 -111.00000;128.21298;-32.40000;,
 111.00000;116.04697;15.05304;,
 31.88166;135.80362;12.21765;,
 34.20459;155.35104;-32.40000;,
 -34.20567;128.21286;-32.40000;,
 111.00000;148.68226;-15.05304;,
 111.00000;155.35117;-32.40000;,
 111.00000;148.68226;-15.05304;,
 111.00000;116.04697;15.05304;,
 111.00000;126.12642;-15.05304;,
 111.00000;126.12642;-32.40000;,
 111.00000;155.35117;-32.40000;,
 111.00000;148.68226;-15.05304;,
 111.00000;126.12642;-32.40000;,
 111.00000;155.35117;-32.40000;,
 -111.00000;105.22299;15.05304;,
 -111.00000;128.21298;-32.40000;,
 111.00000;116.04697;15.05304;,
 -34.20567;115.33905;-32.40000;,
 -111.00000;105.22299;15.05304;,
 -34.20567;115.33905;-32.40000;,
 -111.00000;115.30236;-15.05304;,
 -111.00000;115.30236;-32.40000;,
 34.20459;126.12630;-32.40000;,
 111.00000;126.12642;-32.40000;,
 111.00000;126.12642;-15.05304;,
 111.00000;116.04697;15.05304;,
 111.00000;116.04697;15.05304;,
 -34.20567;115.33905;-32.40000;,
 -111.00000;105.22299;15.05304;,
 53.47800;210.60001;-32.40000;,
 110.99895;210.60014;-32.40000;,
 111.00000;174.24235;-32.40000;,
 31.60671;174.24222;-32.40000;,
 110.99895;210.60014;-32.40000;,
 110.99895;210.60014;32.40000;,
 111.00000;152.58582;32.40000;,
 111.00000;174.24235;-32.40000;,
 110.99895;210.60014;32.40000;,
 53.47800;210.60001;32.40000;,
 31.60671;152.58570;32.40000;,
 111.00000;152.58582;32.40000;,
 53.47800;210.60001;32.40000;,
 53.47800;210.60001;-32.40000;,
 31.60671;174.24222;-32.40000;,
 31.60671;152.58570;32.40000;,
 53.47800;210.60001;32.40000;,
 110.99895;210.60014;32.40000;,
 110.99895;210.60014;-32.40000;,
 53.47800;210.60001;-32.40000;,
 31.60671;174.24222;-32.40000;,
 111.00000;174.24235;-32.40000;,
 111.00000;152.58582;32.40000;,
 31.60671;152.58570;32.40000;,
 -7.22739;175.81674;-32.40000;,
 53.47800;210.60001;-32.40000;,
 31.60671;174.24222;-32.40000;,
 -34.20567;158.50654;-32.39997;,
 53.47800;210.60001;-32.40000;,
 53.47800;210.60001;32.40000;,
 31.60671;152.58570;32.40000;,
 31.60671;174.24222;-32.40000;,
 53.47800;210.60001;32.40000;,
 -7.22739;166.09177;32.40000;,
 -34.20567;137.12583;32.40003;,
 31.60671;152.58570;32.40000;,
 -7.22739;166.09177;32.40000;,
 -7.22739;175.81674;-32.40000;,
 -34.20567;158.50654;-32.39997;,
 -34.20567;137.12583;32.40003;,
 53.47800;210.60001;-32.40000;,
 -7.22739;175.81674;-32.40000;,
 -34.20567;158.50654;-32.39997;,
 31.60671;174.24222;-32.40000;,
 -38.50257;210.60001;-32.40000;,
 -7.22739;175.81674;-32.40000;,
 -34.20567;158.50654;-32.39997;,
 -59.03001;158.50654;-32.39997;,
 -38.50257;210.60001;32.40000;,
 -38.50257;210.60001;-32.40000;,
 -59.03001;158.50654;-32.39997;,
 -34.20567;137.12583;32.40003;,
 -38.50257;210.60001;32.40000;,
 -7.22739;166.09177;32.40000;,
 -7.22739;175.81674;-32.40000;,
 -38.50257;210.60001;-32.40000;,
 -59.03001;158.50654;-32.39997;,
 -34.20567;158.50654;-32.39997;,
 -7.22739;166.09177;32.40000;,
 -34.20567;137.12583;32.40003;,
 -7.22739;166.09177;32.40000;,
 -34.20567;158.50654;-32.39997;,
 -7.22739;175.81674;-32.40000;,
 -7.22739;166.09177;32.40000;,
 -38.50257;210.60001;32.40000;,
 -34.20567;137.12583;32.40003;,
 -110.99925;210.60014;-32.40000;,
 -38.50257;210.60001;-32.40000;,
 -59.03001;158.50654;-32.39997;,
 -111.00000;158.50667;-32.39997;,
 -38.50257;210.60001;-32.40000;,
 -38.50257;210.60001;32.40000;,
 -34.20567;137.12583;32.40003;,
 -59.03001;158.50654;-32.39997;,
 -38.50257;210.60001;32.40000;,
 -110.99925;210.60014;32.40000;,
 -111.00000;137.12595;32.40003;,
 -34.20567;137.12583;32.40003;,
 -110.99925;210.60014;32.40000;,
 -110.99925;210.60014;10.80000;,
 -111.00000;144.90964;15.05307;,
 -111.00000;137.12595;32.40003;,
 -110.99925;210.60014;-10.80000;,
 -111.00000;154.79094;-15.05301;,
 -110.99925;210.60014;-32.40000;,
 -111.00000;158.50667;-32.39997;,
 -110.99925;210.60014;10.80000;,
 -38.50257;210.60001;32.40000;,
 -38.50257;210.60001;-32.40000;,
 -110.99925;210.60014;-10.80000;,
 -111.00000;154.79094;-15.05301;,
 -59.03001;158.50654;-32.39997;,
 -34.20567;137.12583;32.40003;,
 -111.00000;144.90964;15.05307;,
 -34.20567;137.12583;32.40003;,
 -111.00000;137.12595;32.40003;,
 -59.03001;158.50654;-32.39997;,
 -111.00000;158.50667;-32.39997;,
 -110.99925;210.60014;32.40000;,
 -110.99925;210.60014;-32.40000;,
 53.47800;210.60001;-32.40000;,
 53.47800;210.60001;32.40000;,
 -7.22739;166.09177;32.40000;,
 -7.22739;175.81674;-32.40000;,
 -38.50257;210.60001;32.40000;,
 -38.50257;210.60001;-32.40000;,
 -38.50257;210.60001;32.40000;,
 53.47800;210.60001;32.40000;,
 53.47800;210.60001;-32.40000;,
 -38.50257;210.60001;-32.40000;,
 -7.22739;166.09177;32.40000;,
 53.47800;210.60001;32.40000;,
 -38.50257;210.60001;32.40000;,
 -7.22739;175.81674;-32.40000;,
 -38.50257;210.60001;-32.40000;,
 53.47800;210.60001;-32.40000;,
 -19.40610;77.28654;-32.40000;,
 -26.44947;19.25028;32.40000;,
 -44.88426;56.03655;15.05304;,
 -44.88426;56.03655;-15.05304;,
 -19.40610;77.28654;-32.40000;,
 -44.88426;35.98824;-15.05304;,
 -37.72737;0.00000;-32.40000;,
 -44.88426;35.98824;15.05304;,
 -26.44947;19.25028;32.40000;,
 -111.00000;0.00012;32.40000;,
 -111.00000;73.07061;15.05304;,
 -111.00000;86.42023;-15.05304;,
 -111.00000;0.00012;-32.40000;,
 -111.00000;0.00012;32.40000;,
 -111.00000;73.07061;15.05304;,
 -26.44947;19.25028;32.40000;,
 -19.40610;77.28654;-32.40000;,
 -111.00000;86.42023;-15.05304;,
 -111.00000;64.05423;32.40000;,
 -111.00000;0.00012;32.40000;,
 -26.44947;19.25028;32.40000;,
 -111.00000;64.05423;32.40000;,
 -111.00000;93.75301;-32.40000;,
 -37.72737;0.00000;-32.40000;,
 -111.00000;93.75301;-32.40000;,
 -19.40610;77.28654;-32.40000;,
 -111.00000;73.07061;15.05304;,
 -111.00000;64.05423;32.40000;,
 -26.44947;19.25028;32.40000;,
 -111.00000;0.00012;-32.40000;,
 -19.40610;77.28654;-32.40000;,
 -111.00000;93.75301;-32.40000;,
 -111.00000;0.00012;32.40000;,
 -111.00000;0.00012;-32.40000;,
 -37.72737;0.00000;-32.40000;;
 
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
    "Data\\texture\\building\\bill004.jpg";
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
  195;
  -0.163366;-0.908713;-0.384125;,
  0.272225;-0.886302;-0.374651;,
  0.256765;-0.898919;-0.354988;,
  0.246370;-0.800626;-0.546168;,
  0.055773;-0.919654;-0.388749;,
  0.043522;-0.918479;-0.393067;,
  0.016705;-0.821500;-0.569964;,
  0.237656;-0.644989;-0.726298;,
  0.001408;-0.692918;-0.721015;,
  -0.234923;-0.700561;-0.673814;,
  -0.209856;-0.799009;-0.563512;,
  -0.171811;-0.894584;-0.412554;,
  0.000001;0.887301;0.461190;,
  0.000001;0.901163;0.433481;,
  0.000001;0.917658;0.397371;,
  0.000001;0.921088;0.389356;,
  0.000000;-0.000000;1.000000;,
  0.000000;0.000000;-1.000000;,
  -0.272225;0.886302;0.374651;,
  -0.137417;0.912349;0.385662;,
  1.000000;0.000000;0.000000;,
  -0.905067;0.354411;-0.235045;,
  0.000000;0.000000;1.000000;,
  -0.199975;0.421368;0.884567;,
  -0.724140;0.433215;-0.536606;,
  -0.187859;0.823534;0.535258;,
  -0.129467;0.916119;0.379426;,
  -0.045896;0.201583;0.978396;,
  -0.286041;0.850228;0.441920;,
  -0.000001;0.887301;0.461190;,
  -0.000001;0.901163;0.433481;,
  -0.150759;0.610706;0.777374;,
  -0.256765;0.898919;0.354988;,
  -0.000001;0.917658;0.397371;,
  -0.000001;0.921088;0.389356;,
  0.000000;-1.000000;0.000001;,
  -0.968441;0.229575;0.097044;,
  0.000000;0.000000;-1.000000;,
  -0.000001;-0.887226;-0.461335;,
  -0.046930;0.998898;0.000001;,
  0.000000;0.000000;1.000000;,
  1.000000;0.000000;0.000000;,
  0.000000;0.000000;-1.000000;,
  -1.000000;0.000000;0.000000;,
  -0.000001;-0.917693;-0.397290;,
  0.000001;-0.917693;-0.397290;,
  -0.000001;-0.901127;-0.433554;,
  0.000001;-0.901127;-0.433554;,
  -0.074966;0.984200;0.160407;,
  -0.051847;0.985651;0.160639;,
  -0.074966;0.984200;0.160406;,
  -0.051848;0.985651;0.160639;,
  -0.000001;-0.921156;-0.389193;,
  -0.000001;-0.921156;-0.389193;,
  -0.000001;-0.917693;-0.397290;,
  0.000001;-0.921156;-0.389193;,
  0.000001;-0.921156;-0.389193;,
  0.000001;-0.917693;-0.397290;,
  -0.000001;-0.901127;-0.433554;,
  0.000001;-0.901127;-0.433554;,
  -0.000001;-0.887226;-0.461335;,
  0.000001;-0.887226;-0.461335;,
  0.000001;-0.887226;-0.461335;,
  -0.075946;0.997112;0.000002;,
  -0.046320;0.985921;0.160668;,
  -0.052522;0.998620;0.000002;,
  -0.000002;1.000000;0.000002;,
  -0.000002;0.986982;0.160833;,
  -0.046321;0.985921;0.160668;,
  -0.000002;0.986982;0.160833;,
  -0.075947;0.997112;0.000001;,
  -0.046930;0.998898;0.000001;,
  -0.052523;0.998620;0.000001;,
  -0.000002;1.000000;0.000001;,
  -1.000000;0.000000;0.000000;,
  0.000000;-0.000001;1.000000;,
  0.000000;-0.000001;1.000000;,
  0.000000;-0.000000;1.000000;,
  -0.000000;-0.000000;1.000000;,
  1.000000;0.000000;0.000000;,
  -0.000000;0.000001;-1.000000;,
  -0.000000;0.000001;-1.000000;,
  0.000000;0.000001;-1.000000;,
  -1.000000;0.000000;0.000000;,
  0.121064;-0.941044;-0.315880;,
  0.111639;-0.869079;-0.481912;,
  0.078038;-0.933326;-0.350446;,
  0.061681;-0.922499;-0.381041;,
  -0.109453;0.926051;0.361178;,
  -0.110935;0.923743;0.366595;,
  -0.113891;0.959276;0.258492;,
  -0.115094;0.960458;0.253523;,
  0.000000;0.000001;-1.000000;,
  -0.000002;-0.974695;0.223537;,
  0.153600;-0.984679;0.082549;,
  0.009766;-0.972508;-0.232665;,
  0.153729;-0.964371;-0.215303;,
  0.000002;-0.933399;-0.358839;,
  0.000002;-0.827388;-0.561631;,
  0.034265;-0.939586;-0.340592;,
  0.000002;-0.915983;-0.401217;,
  0.075946;-0.997112;-0.000002;,
  0.046930;-0.998898;-0.000001;,
  0.052522;-0.998620;-0.000002;,
  0.000002;-1.000000;-0.000002;,
  0.000001;0.912363;0.409383;,
  -0.106245;0.905252;0.411377;,
  0.000001;0.932523;0.361110;,
  -0.109128;0.900036;0.421932;,
  -0.005796;0.902515;0.430619;,
  -0.002905;0.928230;0.371996;,
  0.000001;0.965334;0.261016;,
  -0.002350;0.967931;0.251205;,
  -0.115117;0.971683;0.206351;,
  0.000002;0.977820;0.209449;,
  -0.117450;0.973486;0.196293;,
  -0.004689;0.981858;0.189559;,
  -0.043550;0.918159;0.393812;,
  0.000000;0.000000;-1.000000;,
  0.060149;-0.967573;-0.245327;,
  1.000000;0.000000;0.000000;,
  -0.005491;0.925005;0.379915;,
  0.069853;0.819595;0.568669;,
  -1.000000;0.000000;0.000000;,
  -0.101304;0.934176;0.342129;,
  -0.078669;0.835001;0.544596;,
  0.041035;-0.992487;-0.115267;,
  0.048921;-0.982866;-0.177710;,
  0.040546;-0.983223;-0.177847;,
  0.050971;0.966711;0.250741;,
  0.025589;0.985654;0.166825;,
  -0.011918;0.823480;0.567220;,
  -0.159487;0.937798;0.308381;,
  -0.156842;0.975040;0.157155;,
  0.047438;-0.972961;-0.226044;,
  0.000478;-1.000000;-0.000000;,
  0.000002;-1.000000;-0.000000;,
  0.036261;-0.986366;-0.160521;,
  -0.048267;0.989950;0.132927;,
  0.000000;0.000000;-1.000000;,
  1.000000;0.000024;0.000003;,
  0.000000;0.000000;1.000000;,
  -0.898295;0.435429;0.058883;,
  -0.000002;1.000000;0.000000;,
  0.000001;-0.948435;-0.316972;,
  -0.000000;-0.000001;-1.000000;,
  0.898295;-0.435429;-0.058883;,
  0.621273;-0.756674;-0.203631;,
  0.000000;0.000000;1.000000;,
  -0.589117;0.799463;0.117473;,
  -0.630357;0.756583;0.173875;,
  -0.543918;0.836970;0.060281;,
  0.219442;-0.925909;-0.307471;,
  -0.000000;-0.000001;-1.000000;,
  0.781512;0.622400;0.043099;,
  -0.970737;0.161939;0.177327;,
  0.387164;-0.875581;-0.288897;,
  0.464408;-0.860746;-0.208426;,
  0.535772;-0.835011;-0.125316;,
  0.000001;0.000000;1.000000;,
  -0.000000;-0.000001;-1.000000;,
  0.970737;-0.161939;-0.177327;,
  0.000000;0.000000;1.000000;,
  -1.000000;0.000012;0.000002;,
  -1.000000;0.000013;0.000002;,
  -1.000000;0.000011;0.000003;,
  -1.000000;0.000014;0.000002;,
  0.000002;1.000000;0.000000;,
  -0.016052;-0.965773;-0.258890;,
  -0.016054;-0.933174;-0.359067;,
  -0.000001;-0.912363;-0.409383;,
  -0.000002;-0.977820;-0.209449;,
  -0.781512;-0.622400;-0.043099;,
  0.543918;-0.836970;-0.060281;,
  0.000000;1.000000;0.000000;,
  0.000000;-0.000000;1.000000;,
  0.000000;0.000000;-1.000000;,
  -1.000000;0.000000;0.000000;,
  0.686792;-0.381343;0.618785;,
  -0.466530;-0.777586;-0.421556;,
  0.858072;-0.269422;0.437178;,
  0.907672;-0.349843;0.231823;,
  0.455898;-0.347214;-0.819512;,
  0.653670;-0.087524;0.751701;,
  0.909305;-0.048127;0.413338;,
  1.000000;0.000000;0.000000;,
  0.358189;-0.904181;0.232718;,
  0.334768;0.811377;0.479164;,
  0.254141;0.615963;0.745655;,
  0.202647;0.863489;0.461868;,
  0.000000;-0.000000;1.000000;,
  0.000000;0.000000;-1.000000;,
  0.425500;0.802971;0.417358;,
  0.163366;0.908713;0.384125;,
  -0.000002;-1.000000;0.000000;;
  168;
  4;1,2,5,4;,
  4;2,3,6,5;,
  4;3,7,8,6;,
  4;9,10,6,8;,
  4;10,11,5,6;,
  4;11,0,4,5;,
  4;12,12,13,13;,
  4;13,13,14,14;,
  4;14,14,15,15;,
  3;16,16,16;,
  3;17,17,17;,
  4;20,20,20,20;,
  4;20,20,20,20;,
  4;20,20,20,20;,
  4;20,20,20,20;,
  4;20,20,20,20;,
  4;22,23,27,22;,
  4;24,21,21,24;,
  4;28,29,30,25;,
  4;31,25,26,32;,
  4;25,30,33,26;,
  4;32,26,19,18;,
  4;26,33,34,19;,
  4;35,35,35,35;,
  3;20,20,20;,
  3;27,23,31;,
  3;22,22,22;,
  3;21,21,36;,
  3;37,37,37;,
  3;37,37,37;,
  3;20,20,20;,
  3;23,25,31;,
  3;25,23,28;,
  3;37,37,37;,
  4;40,40,40,40;,
  4;40,40,40,40;,
  4;41,41,41,41;,
  4;41,41,41,41;,
  4;41,41,41,41;,
  4;42,42,42,42;,
  4;42,42,42,42;,
  4;42,42,42,42;,
  4;43,43,43,43;,
  4;43,43,43,43;,
  4;52,53,44,54;,
  4;53,55,45,44;,
  4;55,56,57,45;,
  4;54,44,46,58;,
  4;44,45,47,46;,
  4;45,57,59,47;,
  4;58,46,60,38;,
  4;46,47,61,60;,
  4;47,59,62,61;,
  4;39,63,48,64;,
  4;63,65,49,48;,
  4;65,66,67,49;,
  4;64,48,50,68;,
  4;48,49,51,50;,
  4;49,67,69,51;,
  4;68,50,70,71;,
  4;50,51,72,70;,
  4;51,69,73,72;,
  3;40,40,40;,
  3;43,43,43;,
  3;40,40,40;,
  3;43,74,43;,
  4;75,76,76,75;,
  4;76,77,77,76;,
  4;77,78,78,77;,
  4;79,79,79,79;,
  4;79,79,79,79;,
  4;79,79,79,79;,
  4;92,80,80,92;,
  4;80,81,81,80;,
  4;81,82,82,81;,
  4;83,83,83,83;,
  4;83,83,83,83;,
  4;83,83,83,83;,
  4;93,94,84,95;,
  4;94,96,85,84;,
  4;96,97,98,85;,
  4;95,84,86,99;,
  4;84,85,87,86;,
  4;85,98,100,87;,
  4;99,86,101,102;,
  4;86,87,103,101;,
  4;87,100,104,103;,
  4;105,106,88,107;,
  4;106,108,89,88;,
  4;108,109,110,89;,
  4;107,88,90,111;,
  4;88,89,91,90;,
  4;89,110,112,91;,
  4;111,90,113,114;,
  4;90,91,115,113;,
  4;91,112,116,115;,
  4;118,118,118,118;,
  4;118,118,118,118;,
  4;123,123,123,123;,
  4;126,127,119,128;,
  4;129,117,124,130;,
  4;117,131,125,124;,
  4;124,125,132,133;,
  4;125,122,121,132;,
  3;120,120,120;,
  3;120,120,120;,
  3;122,125,131;,
  3;120,120,120;,
  3;118,118,118;,
  3;118,118,118;,
  3;123,123,123;,
  3;130,124,133;,
  3;119,134,126;,
  3;134,128,119;,
  3;126,128,135;,
  3;127,136,137;,
  3;119,127,137;,
  3;131,138,117;,
  4;139,139,139,139;,
  4;140,140,140,140;,
  4;141,141,141,141;,
  4;142,142,142,142;,
  4;143,143,143,143;,
  4;144,144,144,144;,
  4;145,145,145,145;,
  4;146,146,147,147;,
  4;148,148,148,148;,
  4;149,149,150,150;,
  4;149,151,151,149;,
  4;152,147,147,152;,
  4;153,153,153,153;,
  4;155,155,155,155;,
  4;154,154,154,154;,
  4;156,157,157,156;,
  3;157,157,158;,
  3;159,159,159;,
  4;160,160,160,160;,
  4;161,161,161,161;,
  4;162,162,162,162;,
  4;165,163,163,165;,
  4;163,164,164,163;,
  4;164,166,166,164;,
  4;167,167,167,167;,
  4;168,168,169,169;,
  3;169,170,169;,
  3;168,168,171;,
  3;167,167,167;,
  3;167,167,167;,
  4;173,173,173,173;,
  4;172,172,172,172;,
  4;174,174,174,174;,
  3;175,175,175;,
  3;176,176,176;,
  4;179,179,179,179;,
  4;183,184,180,178;,
  4;184,185,181,180;,
  4;182,182,182,182;,
  4;180,181,186,178;,
  4;177,177,177,177;,
  4;187,188,189,189;,
  3;177,177,177;,
  3;190,188,190;,
  3;177,177,177;,
  3;191,191,191;,
  3;187,192,188;,
  3;191,191,191;,
  3;189,193,189;,
  3;186,194,194;;
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
  0.354338;0.890178;,
  0.688370;0.641819;,
  -0.111295;0.641818;,
  0.393127;0.568468;,
  -0.111295;0.477191;,
  0.688370;0.477191;,
  0.357935;0.467924;,
  0.642065;0.534899;,
  0.642065;0.620358;,
  0.357935;0.620358;,
  0.194221;0.431136;,
  0.357935;0.720941;,
  0.194221;0.901494;,
  0.642065;0.720941;,
  0.805779;0.580134;,
  0.805779;0.901494;,
  0.688370;0.641819;,
  0.354338;0.890178;,
  -0.111295;0.996886;,
  1.111295;0.996886;,
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
  -0.128789;-0.040000;,
  2.350000;-0.040000;,
  2.350000;1.040000;,
  -1.350000;1.040000;,
  0.859710;0.851260;,
  1.111295;0.641818;,
  0.140290;0.686630;,
  0.292229;0.996887;,
  0.393127;0.568468;,
  0.688370;0.477191;,
  1.111295;0.996886;,
  1.111295;0.477191;,
  0.166670;0.000000;,
  0.500000;0.333330;,
  0.333330;0.000000;,
  0.311624;0.641839;,
  0.688370;0.641839;,
  0.688370;0.353610;,
  0.311624;0.393610;,
  1.111295;0.641838;,
  1.111295;0.353610;,
  0.805779;0.580152;,
  0.642065;0.534899;,
  0.642065;0.319287;,
  0.805779;0.319287;,
  0.357935;0.467924;,
  0.357935;0.268718;,
  0.194221;0.431154;,
  0.194221;0.268718;,
  1.111295;0.477211;,
  0.688370;0.477211;,
  0.688370;0.297737;,
  1.111295;0.297737;,
  0.311624;0.477211;,
  0.311624;0.337737;,
  -0.111295;0.477211;,
  -0.111295;0.357737;,
  0.194221;0.431154;,
  0.357935;0.467924;,
  0.357935;0.323023;,
  0.194221;0.323023;,
  0.642065;0.534899;,
  0.642065;0.373591;,
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
  -0.111295;0.413610;,
  0.805779;0.373591;,
  -0.111295;0.641838;,
  0.805779;0.580152;,
  -0.111295;0.413610;,
  0.311624;0.393610;,
  0.311624;0.236764;,
  -0.111295;0.236764;,
  0.688370;0.353610;,
  0.674063;0.151066;,
  1.111295;0.353610;,
  1.111295;0.145350;,
  0.805779;0.319287;,
  0.642065;0.319287;,
  0.642065;0.091748;,
  0.805779;0.130799;,
  0.357935;0.155556;,
  0.357935;0.042174;,
  0.194221;0.122098;,
  0.194221;0.023533;,
  1.111295;0.135737;,
  0.688370;0.135737;,
  0.674063;0.031019;,
  1.111295;0.026832;,
  0.311624;0.286171;,
  0.311624;0.118246;,
  -0.111295;0.286170;,
  -0.111295;0.118245;,
  0.194221;0.258250;,
  0.357935;0.238291;,
  0.357935;0.124909;,
  0.194221;0.106267;,
  0.642065;0.373591;,
  0.642065;0.174483;,
  0.805779;0.373591;,
  0.805779;0.213534;,
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
  0.688370;0.297737;,
  0.311624;0.357534;,
  0.311624;0.286171;,
  0.688370;0.135737;,
  -0.111295;0.357737;,
  -0.111295;0.286170;,
  0.194221;0.323023;,
  0.357935;0.323023;,
  0.357935;0.238291;,
  0.194221;0.258250;,
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
  0.357935;0.155556;,
  0.642065;0.319287;,
  0.357935;0.268718;,
  0.194221;0.268718;,
  0.194221;0.122098;,
  1.000000;0.500000;,
  1.111295;0.297737;,
  1.111295;0.135737;,
  0.642065;0.373591;,
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
  0.794512;-0.170521;,
  1.111290;-0.170522;,
  1.111295;0.031018;,
  0.674063;0.031019;,
  0.194221;-0.155086;,
  0.805779;-0.155086;,
  0.805779;0.135972;,
  0.194221;0.027321;,
  1.111290;-0.170522;,
  0.794512;-0.170521;,
  0.674063;0.151066;,
  1.111295;0.151066;,
  0.859710;0.023860;,
  0.140290;0.023860;,
  0.140290;0.149180;,
  0.859710;0.269230;,
  1.391300;1.040000;,
  2.349982;1.040000;,
  2.349982;-0.040000;,
  1.391300;-0.040000;,
  0.140290;0.423860;,
  0.859710;0.423860;,
  0.859710;0.423860;,
  0.140290;0.423860;,
  0.460198;0.022291;,
  0.794512;-0.170521;,
  0.674063;0.031019;,
  0.311624;0.118246;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.794512;-0.170521;,
  0.460198;0.076199;,
  0.311624;0.236764;,
  0.674063;0.151066;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  0.287960;-0.170521;,
  0.460198;0.022291;,
  0.311624;0.118246;,
  0.174912;0.118246;,
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
  0.460198;0.076199;,
  0.287960;-0.170521;,
  0.311624;0.236764;,
  -0.111291;-0.170522;,
  0.287960;-0.170521;,
  0.174912;0.118246;,
  -0.111295;0.118245;,
  0.333330;0.000000;,
  0.666670;0.000000;,
  0.666670;1.000000;,
  0.333330;1.000000;,
  0.287960;-0.170521;,
  -0.111291;-0.170522;,
  -0.111295;0.236764;,
  0.311624;0.236764;,
  0.805779;-0.155086;,
  0.601926;-0.155086;,
  0.642065;0.174483;,
  0.805779;0.213534;,
  0.398074;-0.155086;,
  0.357935;0.124909;,
  0.194221;-0.155086;,
  0.194221;0.106267;,
  -1.349987;0.680000;,
  -0.141710;1.040000;,
  -0.141710;-0.040000;,
  -1.349987;0.320000;,
  0.000000;0.333330;,
  1.000000;0.333330;,
  1.000000;0.666670;,
  0.000000;0.666670;,
  1.000000;0.833330;,
  0.000000;1.000000;,
  1.000000;0.166670;,
  0.000000;0.000000;,
  -1.349987;1.040000;,
  -1.349987;-0.040000;,
  0.761290;0.020000;,
  0.761290;0.020000;,
  0.464690;0.194360;,
  0.464690;0.140450;,
  0.311880;0.020000;,
  0.311880;0.020000;,
  -0.141710;1.040000;,
  1.391300;1.040000;,
  1.391300;-0.040000;,
  -0.141710;-0.040000;,
  0.460198;0.076199;,
  0.794512;-0.170521;,
  0.287960;-0.170521;,
  0.460198;0.022291;,
  0.287960;-0.170521;,
  0.794512;-0.170521;,
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
  0.642065;0.534899;,
  0.357935;0.467924;,
  0.194221;0.901494;,
  0.805779;0.901494;,
  0.666670;0.333330;,
  1.000000;0.333330;,
  1.000000;0.666670;,
  0.666670;0.666670;,
  0.805779;0.580134;,
  -0.111295;0.996886;,
  0.354338;0.890178;,
  -0.111295;0.641818;,
  0.194221;0.431136;,
  0.292229;0.996887;,
  -0.111295;0.477191;,
  0.393127;0.568468;,
  0.166670;0.333330;,
  0.000000;0.000000;,
  0.333330;0.000000;,
  -0.111295;0.996886;,
  1.000000;0.833330;,
  0.666670;1.000000;,
  -1.350000;1.040000;,
  -1.350000;-0.040000;,
  -0.128789;-0.040000;;
 }
}
