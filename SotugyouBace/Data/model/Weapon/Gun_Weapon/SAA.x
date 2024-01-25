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
 330;
 1.67200;-4.95613;2.44929;,
 0.85002;-4.95613;0.25211;,
 0.85002;0.29394;-1.36923;,
 1.67200;1.84758;-0.74242;,
 -0.79391;-4.95613;0.25211;,
 -0.79391;0.29394;-1.36923;,
 -1.61589;-4.95613;2.44929;,
 -1.61589;1.84758;-0.74242;,
 -0.79391;-4.95613;4.64646;,
 -0.79391;4.65952;-0.11563;,
 0.85002;-4.95613;4.64646;,
 0.85002;4.65952;-0.11563;,
 1.67200;-4.95613;2.44929;,
 1.67200;1.84758;-0.74242;,
 0.85002;0.33152;-2.70879;,
 1.67200;4.49149;-2.10936;,
 -0.79391;0.33152;-2.70879;,
 -1.61589;4.49149;-2.10936;,
 -0.79391;4.43026;-1.48257;,
 0.85002;4.43026;-1.48257;,
 1.67200;4.49149;-2.10936;,
 1.47223;1.79514;-3.94125;,
 2.91641;4.29654;-3.94125;,
 -1.41611;1.79514;-3.94125;,
 -2.86030;4.29654;-3.94125;,
 -1.41611;6.79792;-3.94125;,
 1.47223;6.79792;-3.94125;,
 2.91641;4.29654;-3.94125;,
 0.02806;-6.05400;2.44929;,
 0.02806;-6.05400;2.44929;,
 0.02806;-6.05400;2.44929;,
 0.02806;-6.05400;2.44929;,
 0.02806;-6.05400;2.44929;,
 0.02806;-6.05400;2.44929;,
 0.02806;4.29654;-3.94125;,
 0.02806;4.29654;-3.94125;,
 0.02806;4.29654;-3.94125;,
 0.02806;4.29654;-3.94125;,
 0.02806;4.29654;-3.94125;,
 0.02806;4.29654;-3.94125;,
 0.92265;5.73477;-20.24617;,
 0.66063;5.10219;-20.24617;,
 0.66062;5.10219;-34.35224;,
 0.92265;5.73477;-34.35224;,
 0.53411;5.22871;-20.24617;,
 0.74373;5.73477;-20.24617;,
 0.74373;5.73477;-34.35224;,
 0.53411;5.22871;-34.35224;,
 0.02805;4.84017;-20.24617;,
 0.02805;4.84017;-34.35224;,
 0.02805;5.01909;-20.24617;,
 0.02805;5.01909;-34.35224;,
 -0.60452;5.10219;-20.24617;,
 -0.60452;5.10219;-34.35224;,
 -0.47801;5.22871;-20.24617;,
 -0.47801;5.22871;-34.35224;,
 -0.86654;5.73477;-20.24617;,
 -0.86654;5.73477;-34.35224;,
 -0.68762;5.73477;-20.24617;,
 -0.68763;5.73477;-34.35224;,
 -0.60452;6.36734;-20.24617;,
 -0.60452;6.36734;-34.35224;,
 -0.47801;6.24083;-20.24617;,
 -0.47801;6.24083;-34.35224;,
 0.02805;6.62936;-20.24617;,
 0.02805;6.62936;-34.35224;,
 0.02805;6.45045;-20.24617;,
 0.02805;6.45045;-34.35224;,
 0.66063;6.36734;-20.24617;,
 0.66062;6.36734;-34.35224;,
 0.53411;6.24083;-20.24617;,
 0.53411;6.24083;-34.35224;,
 0.92265;5.73477;-20.24617;,
 0.92265;5.73477;-34.35224;,
 0.74373;5.73477;-20.24617;,
 0.74373;5.73477;-34.35224;,
 0.53411;5.22871;-20.24617;,
 0.66063;5.10219;-20.24617;,
 0.92265;5.73477;-34.35224;,
 0.66062;5.10219;-34.35224;,
 0.53411;5.22871;-34.35224;,
 0.74373;5.73477;-34.35224;,
 0.02805;5.01909;-20.24617;,
 0.02805;4.84017;-20.24617;,
 0.02805;4.84017;-34.35224;,
 0.02805;5.01909;-34.35224;,
 -0.47801;5.22871;-20.24617;,
 -0.60452;5.10219;-20.24617;,
 -0.60452;5.10219;-34.35224;,
 -0.47801;5.22871;-34.35224;,
 -0.68762;5.73477;-20.24617;,
 -0.86654;5.73477;-20.24617;,
 -0.86654;5.73477;-34.35224;,
 -0.68763;5.73477;-34.35224;,
 -0.47801;6.24083;-20.24617;,
 -0.60452;6.36734;-20.24617;,
 -0.60452;6.36734;-34.35224;,
 -0.47801;6.24083;-34.35224;,
 0.02805;6.45045;-20.24617;,
 0.02805;6.62936;-20.24617;,
 0.02805;6.62936;-34.35224;,
 0.02805;6.45045;-34.35224;,
 0.53411;6.24083;-20.24617;,
 0.66063;6.36734;-20.24617;,
 0.66062;6.36734;-34.35224;,
 0.53411;6.24083;-34.35224;,
 1.35467;5.24595;-12.14456;,
 0.96611;3.93570;-12.14456;,
 0.96611;3.93570;-33.59097;,
 1.35466;5.24595;-33.59097;,
 0.02805;3.39298;-12.14456;,
 0.02805;3.39298;-33.59097;,
 -0.91000;3.93570;-12.14456;,
 -0.91000;3.93570;-33.59097;,
 -1.29856;5.24595;-12.14456;,
 -1.29856;5.24595;-33.59097;,
 -0.91000;6.55621;-12.14456;,
 -0.91000;6.55621;-33.59097;,
 0.02805;7.09893;-12.14456;,
 0.02805;7.09893;-33.59097;,
 0.96611;6.55621;-12.14456;,
 0.96611;6.55621;-33.59097;,
 1.35467;5.24595;-12.14456;,
 1.35466;5.24595;-33.59097;,
 0.02805;5.24595;-12.14456;,
 0.02805;5.24595;-12.14456;,
 0.02805;5.24595;-12.14456;,
 0.02805;5.24595;-12.14456;,
 0.02805;5.24595;-12.14456;,
 0.02805;5.24595;-12.14456;,
 0.02805;5.24595;-12.14456;,
 0.02805;5.24595;-12.14456;,
 0.02805;5.24595;-33.59097;,
 0.02805;5.24595;-33.59097;,
 0.02805;5.24595;-33.59097;,
 0.02805;5.24595;-33.59097;,
 0.02805;5.24595;-33.59097;,
 0.02805;5.24595;-33.59097;,
 0.02805;5.24595;-33.59097;,
 0.02805;5.24595;-33.59097;,
 0.82968;3.09449;-8.97034;,
 0.59489;2.40594;-8.97034;,
 0.59489;2.40594;-19.22160;,
 0.82968;3.09449;-19.22160;,
 0.02805;2.12073;-8.97034;,
 0.02805;2.12073;-19.22160;,
 -0.53878;2.40594;-8.97034;,
 -0.53879;2.40594;-19.22160;,
 -0.77357;3.09449;-8.97034;,
 -0.77357;3.09449;-19.22160;,
 -0.53878;3.78304;-8.97034;,
 -0.53879;3.78304;-19.22160;,
 0.02805;4.06824;-8.97034;,
 0.02805;4.06825;-19.22160;,
 0.59489;3.78304;-8.97034;,
 0.59489;3.78304;-19.22160;,
 0.82968;3.09449;-8.97034;,
 0.82968;3.09449;-19.22160;,
 0.02805;3.09449;-8.97034;,
 0.02805;3.09449;-8.97034;,
 0.02805;3.09449;-8.97034;,
 0.02805;3.09449;-8.97034;,
 0.02805;3.09449;-8.97034;,
 0.02805;3.09449;-8.97034;,
 0.02805;3.09449;-8.97034;,
 0.02805;3.09449;-8.97034;,
 0.02805;3.50597;-23.26401;,
 0.02805;3.50597;-23.26401;,
 0.02805;3.50597;-23.26401;,
 0.02805;3.50597;-23.26401;,
 0.02805;3.50597;-23.26401;,
 0.02805;3.50597;-23.26401;,
 0.02805;3.50597;-23.26401;,
 0.02805;3.50597;-23.26401;,
 1.45773;5.58661;-9.04661;,
 1.03899;4.16041;-9.04661;,
 1.03898;4.16041;-12.30185;,
 1.45773;5.58661;-12.30185;,
 0.02805;3.56966;-9.04661;,
 0.02805;3.56966;-12.30185;,
 -0.98288;4.16041;-9.04661;,
 -0.98288;4.16041;-12.30185;,
 -1.40162;5.58661;-9.04661;,
 -1.40162;5.58661;-12.30185;,
 -0.98288;7.01280;-9.04661;,
 -0.98288;7.01280;-12.30185;,
 0.02805;7.60355;-9.04661;,
 0.02805;7.60355;-12.30185;,
 1.03899;7.01280;-9.04661;,
 1.03898;7.01280;-12.30185;,
 1.45773;5.58661;-9.04661;,
 1.45773;5.58661;-12.30185;,
 0.02805;5.58661;-9.04661;,
 0.02805;5.58661;-9.04661;,
 0.02805;5.58661;-9.04661;,
 0.02805;5.58661;-9.04661;,
 0.02805;5.58661;-9.04661;,
 0.02805;5.58661;-9.04661;,
 0.02805;5.58661;-9.04661;,
 0.02805;5.58661;-9.04661;,
 0.02805;5.58661;-12.30185;,
 0.02805;5.58661;-12.30185;,
 0.02805;5.58661;-12.30185;,
 0.02805;5.58661;-12.30185;,
 0.02805;5.58661;-12.30185;,
 0.02805;5.58661;-12.30185;,
 0.02805;5.58661;-12.30185;,
 0.02805;5.58661;-12.30185;,
 2.42968;4.45078;-4.14289;,
 1.72627;2.75258;-4.14289;,
 1.72627;2.75258;-8.94615;,
 2.42968;4.45078;-8.94615;,
 0.02806;2.04916;-4.14289;,
 0.02805;2.04916;-8.94615;,
 -1.67016;2.75258;-4.14289;,
 -1.67016;2.75258;-8.94615;,
 -2.37357;4.45078;-4.14289;,
 -2.37357;4.45078;-8.94615;,
 -1.67016;6.14900;-4.14289;,
 -1.67016;6.14900;-8.94615;,
 0.02806;6.85242;-4.14289;,
 0.02805;6.85242;-8.94615;,
 1.72627;6.14900;-4.14289;,
 1.72627;6.14900;-8.94615;,
 2.42968;4.45078;-4.14289;,
 2.42968;4.45078;-8.94615;,
 0.02806;4.45078;-4.14289;,
 0.02806;4.45078;-4.14289;,
 0.02806;4.45078;-4.14289;,
 0.02806;4.45078;-4.14289;,
 0.02806;4.45078;-4.14289;,
 0.02806;4.45078;-4.14289;,
 0.02806;4.45078;-4.14289;,
 0.02806;4.45078;-4.14289;,
 0.02805;4.45078;-8.94615;,
 0.02805;4.45078;-8.94615;,
 0.02805;4.45078;-8.94615;,
 0.02805;4.45078;-8.94615;,
 0.02805;4.45078;-8.94615;,
 0.02805;4.45078;-8.94615;,
 0.02805;4.45078;-8.94615;,
 0.02805;4.45078;-8.94615;,
 2.13867;6.24504;-3.74654;,
 0.79056;6.69033;-3.93469;,
 0.79056;7.01192;-9.03063;,
 2.13867;6.24504;-9.03063;,
 -0.60074;6.72669;-3.93469;,
 -0.60074;7.04829;-9.03063;,
 -1.90988;6.20983;-3.74654;,
 -1.90988;6.20983;-9.03063;,
 0.09725;7.54855;-3.74654;,
 0.09725;7.54855;-9.03063;,
 2.13867;6.24504;-3.74654;,
 2.13867;6.24504;-9.03063;,
 0.21849;6.98989;-3.93469;,
 0.21849;6.98989;-3.93469;,
 0.21849;6.98989;-3.93469;,
 0.21849;6.98989;-3.93469;,
 0.21849;6.98989;-3.93469;,
 0.21849;7.31148;-9.03063;,
 0.21849;7.31148;-9.03063;,
 0.21849;7.31148;-9.03063;,
 0.21849;7.31148;-9.03063;,
 0.21849;7.31148;-9.03063;,
 1.66800;2.31582;-4.16270;,
 1.66800;1.77392;-4.16270;,
 0.58093;1.04568;-11.63677;,
 0.58093;2.32991;-11.63677;,
 -1.61189;1.77392;-4.16270;,
 -0.52482;1.04568;-11.63677;,
 -1.61189;2.31582;-4.16270;,
 -0.52482;2.32991;-11.63677;,
 1.66800;2.31582;-4.16270;,
 0.58093;2.32991;-11.63677;,
 0.02806;2.04488;-4.16270;,
 0.02806;2.04488;-4.16270;,
 0.02806;2.04488;-4.16270;,
 0.02806;2.04488;-4.16270;,
 0.02805;2.35850;-12.34737;,
 0.02805;2.35850;-12.34737;,
 0.02805;2.35850;-12.34737;,
 0.02805;2.35850;-12.34737;,
 -0.22588;6.04488;-3.20647;,
 -0.22588;4.61879;-1.70851;,
 -0.26104;6.36010;-2.13975;,
 -0.26104;6.49958;-2.33046;,
 0.28199;4.61879;-1.70851;,
 0.31715;6.36010;-2.13975;,
 0.28199;6.04488;-3.20647;,
 0.31715;6.49958;-2.33046;,
 -0.22588;6.04488;-3.20647;,
 -0.26104;6.49958;-2.33046;,
 -0.26104;7.08765;-1.53712;,
 -0.26104;7.22713;-1.72783;,
 0.31715;7.08765;-1.53712;,
 0.31715;7.22713;-1.72783;,
 -0.26104;7.22713;-1.72783;,
 -0.26104;7.37821;-0.40651;,
 -0.26104;7.51764;-0.59720;,
 0.31715;7.37821;-0.40651;,
 0.31715;7.51764;-0.59720;,
 -0.26104;7.51764;-0.59720;,
 0.02806;5.33183;-2.45748;,
 0.02806;5.33183;-2.45748;,
 0.02806;5.33183;-2.45748;,
 0.02806;5.33183;-2.45748;,
 0.02806;7.44792;-0.50188;,
 0.02806;7.44792;-0.50188;,
 0.02806;7.44792;-0.50188;,
 0.02806;7.44792;-0.50188;,
 0.19800;7.37249;-32.95620;,
 0.14614;7.24897;-31.76165;,
 0.18974;7.02429;-31.76165;,
 0.26075;7.04911;-32.95620;,
 0.14614;7.24897;-31.76165;,
 -0.09003;7.24897;-31.76165;,
 -0.13363;7.02429;-31.76165;,
 0.18974;7.02429;-31.76165;,
 -0.09003;7.24897;-31.76165;,
 -0.14190;7.37249;-32.95620;,
 -0.20464;7.04911;-32.95620;,
 -0.13363;7.02429;-31.76165;,
 -0.14190;7.37249;-32.95620;,
 0.19800;7.37249;-32.95620;,
 0.26075;7.04911;-32.95620;,
 -0.20464;7.04911;-32.95620;,
 0.14614;7.24897;-31.76165;,
 0.19800;7.37249;-32.95620;,
 0.26075;7.04911;-32.95620;,
 0.18974;7.02429;-31.76165;;
 
 211;
 4;0,1,2,3;,
 4;1,4,5,2;,
 4;4,6,7,5;,
 4;6,8,9,7;,
 4;8,10,11,9;,
 4;10,12,13,11;,
 4;3,2,14,15;,
 4;2,5,16,14;,
 4;5,7,17,16;,
 4;7,9,18,17;,
 4;9,11,19,18;,
 4;11,13,20,19;,
 4;15,14,21,22;,
 4;14,16,23,21;,
 4;16,17,24,23;,
 4;17,18,25,24;,
 4;18,19,26,25;,
 4;19,20,27,26;,
 3;28,1,0;,
 3;29,4,1;,
 3;30,6,4;,
 3;31,8,6;,
 3;32,10,8;,
 3;33,12,10;,
 3;34,22,21;,
 3;35,21,23;,
 3;36,23,24;,
 3;37,24,25;,
 3;38,25,26;,
 3;39,26,27;,
 4;40,41,42,43;,
 4;44,45,46,47;,
 4;41,48,49,42;,
 4;50,44,47,51;,
 4;48,52,53,49;,
 4;54,50,51,55;,
 4;52,56,57,53;,
 4;58,54,55,59;,
 4;56,60,61,57;,
 4;62,58,59,63;,
 4;60,64,65,61;,
 4;66,62,63,67;,
 4;64,68,69,65;,
 4;70,66,67,71;,
 4;68,72,73,69;,
 4;74,70,71,75;,
 4;40,45,76,77;,
 4;78,79,80,81;,
 4;77,76,82,83;,
 4;79,84,85,80;,
 4;83,82,86,87;,
 4;84,88,89,85;,
 4;87,86,90,91;,
 4;88,92,93,89;,
 4;91,90,94,95;,
 4;92,96,97,93;,
 4;95,94,98,99;,
 4;96,100,101,97;,
 4;99,98,102,103;,
 4;100,104,105,101;,
 4;103,102,45,40;,
 4;104,78,81,105;,
 4;106,107,108,109;,
 4;107,110,111,108;,
 4;110,112,113,111;,
 4;112,114,115,113;,
 4;114,116,117,115;,
 4;116,118,119,117;,
 4;118,120,121,119;,
 4;120,122,123,121;,
 3;124,107,106;,
 3;125,110,107;,
 3;126,112,110;,
 3;127,114,112;,
 3;128,116,114;,
 3;129,118,116;,
 3;130,120,118;,
 3;131,122,120;,
 3;132,109,108;,
 3;133,108,111;,
 3;134,111,113;,
 3;135,113,115;,
 3;136,115,117;,
 3;137,117,119;,
 3;138,119,121;,
 3;139,121,123;,
 4;140,141,142,143;,
 4;141,144,145,142;,
 4;144,146,147,145;,
 4;146,148,149,147;,
 4;148,150,151,149;,
 4;150,152,153,151;,
 4;152,154,155,153;,
 4;154,156,157,155;,
 3;158,141,140;,
 3;159,144,141;,
 3;160,146,144;,
 3;161,148,146;,
 3;162,150,148;,
 3;163,152,150;,
 3;164,154,152;,
 3;165,156,154;,
 3;166,143,142;,
 3;167,142,145;,
 3;168,145,147;,
 3;169,147,149;,
 3;170,149,151;,
 3;171,151,153;,
 3;172,153,155;,
 3;173,155,157;,
 4;174,175,176,177;,
 4;175,178,179,176;,
 4;178,180,181,179;,
 4;180,182,183,181;,
 4;182,184,185,183;,
 4;184,186,187,185;,
 4;186,188,189,187;,
 4;188,190,191,189;,
 3;192,175,174;,
 3;193,178,175;,
 3;194,180,178;,
 3;195,182,180;,
 3;196,184,182;,
 3;197,186,184;,
 3;198,188,186;,
 3;199,190,188;,
 3;200,177,176;,
 3;201,176,179;,
 3;202,179,181;,
 3;203,181,183;,
 3;204,183,185;,
 3;205,185,187;,
 3;206,187,189;,
 3;207,189,191;,
 4;208,209,210,211;,
 4;209,212,213,210;,
 4;212,214,215,213;,
 4;214,216,217,215;,
 4;216,218,219,217;,
 4;218,220,221,219;,
 4;220,222,223,221;,
 4;222,224,225,223;,
 3;226,209,208;,
 3;227,212,209;,
 3;228,214,212;,
 3;229,216,214;,
 3;230,218,216;,
 3;231,220,218;,
 3;232,222,220;,
 3;233,224,222;,
 3;234,211,210;,
 3;235,210,213;,
 3;236,213,215;,
 3;237,215,217;,
 3;238,217,219;,
 3;239,219,221;,
 3;240,221,223;,
 3;241,223,225;,
 4;242,243,244,245;,
 4;243,246,247,244;,
 4;246,248,249,247;,
 4;248,250,251,249;,
 4;250,252,253,251;,
 3;254,243,242;,
 3;255,246,243;,
 3;256,248,246;,
 3;257,250,248;,
 3;258,252,250;,
 3;259,245,244;,
 3;260,244,247;,
 3;261,247,249;,
 3;262,249,251;,
 3;263,251,253;,
 4;264,265,266,267;,
 4;265,268,269,266;,
 4;268,270,271,269;,
 4;270,272,273,271;,
 3;274,265,264;,
 3;275,268,265;,
 3;276,270,268;,
 3;277,272,270;,
 3;278,267,266;,
 3;279,266,269;,
 3;280,269,271;,
 3;281,271,273;,
 4;282,283,284,285;,
 4;283,286,287,284;,
 4;286,288,289,287;,
 4;288,290,291,289;,
 4;285,284,292,293;,
 4;284,287,294,292;,
 4;287,289,295,294;,
 4;289,291,296,295;,
 4;293,292,297,298;,
 4;292,294,299,297;,
 4;294,295,300,299;,
 4;295,296,301,300;,
 3;302,283,282;,
 3;303,286,283;,
 3;304,288,286;,
 3;305,290,288;,
 3;306,298,297;,
 3;307,297,299;,
 3;308,299,300;,
 3;309,300,301;,
 4;310,311,312,313;,
 4;314,315,316,317;,
 4;318,319,320,321;,
 4;322,323,324,325;,
 4;322,315,326,327;,
 4;328,329,316,325;;
 
 MeshMaterialList {
  2;
  211;
  1,
  1,
  1,
  1,
  1,
  1,
  0,
  0,
  0,
  0,
  1,
  0,
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
   0.166400;0.166400;0.166400;1.000000;;
   5.000000;
   0.910000;0.910000;0.910000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.530400;0.344800;0.000000;1.000000;;
   5.000000;
   0.360000;0.360000;0.360000;;
   0.000000;0.000000;0.000000;;
  }
 }
 MeshNormals {
  167;
  0.000000;-1.000000;0.000001;,
  0.871115;-0.490618;-0.021259;,
  0.550486;-0.724205;-0.415323;,
  -0.207156;-0.763408;-0.611796;,
  -0.871115;-0.490618;-0.021259;,
  -0.917484;0.172895;0.358233;,
  0.000000;0.443800;0.896126;,
  0.998711;0.018658;0.047199;,
  0.923777;-0.245570;-0.293822;,
  0.000000;-0.295072;-0.955475;,
  -0.998711;0.018658;0.047200;,
  -0.883544;0.277700;0.377138;,
  0.481125;0.472100;0.738675;,
  0.935067;0.073215;0.346827;,
  0.934907;-0.332715;0.123488;,
  0.000000;-0.900670;-0.434504;,
  -0.935067;0.073215;0.346828;,
  -0.533972;0.588498;0.607078;,
  0.244922;0.867383;0.433197;,
  0.832818;0.105515;0.543398;,
  0.860761;-0.328141;0.389120;,
  0.000000;-0.226886;-0.973921;,
  -0.832818;0.105515;0.543398;,
  -0.333099;0.656372;0.676921;,
  0.333099;0.656371;0.676921;,
  0.000000;0.000000;-1.000000;,
  -0.886667;-0.173059;-0.428804;,
  -0.923777;-0.245570;-0.293822;,
  0.917484;0.172895;0.358233;,
  0.000000;-0.999607;-0.028046;,
  -0.934907;-0.332715;0.123488;,
  0.000000;0.986225;-0.165408;,
  0.838566;0.379035;0.391331;,
  -0.860761;-0.328141;0.389120;,
  -0.285061;-0.895812;0.340970;,
  0.285061;-0.895812;0.340970;,
  1.000000;0.000001;-0.000000;,
  0.707107;-0.707107;-0.000000;,
  0.000000;-1.000000;-0.000000;,
  -0.707107;-0.707107;0.000000;,
  -1.000000;0.000001;0.000000;,
  -0.707107;0.707106;0.000000;,
  0.000000;1.000000;-0.000000;,
  0.707107;0.707106;-0.000000;,
  -1.000000;-0.000001;0.000000;,
  -0.707107;0.707107;0.000000;,
  -0.000000;1.000000;0.000000;,
  0.707107;0.707107;-0.000000;,
  1.000000;-0.000001;-0.000000;,
  0.707108;-0.707106;-0.000000;,
  -0.000000;-1.000000;0.000000;,
  -0.707108;-0.707106;0.000000;,
  0.000000;0.000000;1.000000;,
  0.000000;0.000000;-1.000000;,
  0.000000;0.000000;1.000000;,
  1.000000;-0.000001;-0.000000;,
  0.785502;-0.618859;-0.000000;,
  0.500786;-0.865571;-0.000000;,
  -0.785502;-0.618860;0.000000;,
  -1.000000;-0.000001;0.000000;,
  -0.785502;0.618859;0.000000;,
  -0.500785;0.865572;0.000000;,
  0.785502;0.618859;-0.000000;,
  0.000000;0.000000;-1.000000;,
  -0.500786;-0.865571;0.000000;,
  0.500785;0.865572;-0.000000;,
  0.000000;0.000000;1.000000;,
  1.000000;0.000000;-0.000000;,
  0.754026;-0.656844;-0.000000;,
  0.000000;-1.000000;0.000000;,
  -0.754026;-0.656844;0.000000;,
  -1.000000;0.000000;0.000000;,
  -0.754029;0.656842;0.000000;,
  0.000000;1.000000;0.000001;,
  0.754028;0.656842;0.000000;,
  0.995216;0.001001;-0.097699;,
  0.748161;-0.648960;-0.138225;,
  0.000000;-0.986260;-0.165200;,
  -0.748161;-0.648960;-0.138225;,
  -0.995216;0.001001;-0.097698;,
  -0.751640;0.655320;-0.074781;,
  0.000000;0.997609;-0.069116;,
  0.751640;0.655321;-0.074781;,
  0.904853;-0.336109;-0.261287;,
  -0.904853;-0.336109;-0.261287;,
  0.000000;0.990464;-0.137770;,
  0.000000;0.000000;1.000000;,
  1.000000;0.000000;-0.000000;,
  0.787677;-0.616088;-0.000000;,
  0.504535;-0.863391;-0.000000;,
  -0.787677;-0.616088;0.000000;,
  -1.000000;0.000000;0.000000;,
  -0.787675;0.616091;0.000000;,
  -0.504530;0.863394;0.000000;,
  0.787675;0.616091;-0.000000;,
  0.000000;0.000000;-1.000000;,
  -0.504535;-0.863391;0.000000;,
  0.504530;0.863394;-0.000000;,
  0.000000;0.000000;1.000000;,
  1.000000;-0.000001;-0.000000;,
  0.707107;-0.707106;-0.000000;,
  -0.000000;-1.000000;-0.000000;,
  -0.707107;-0.707106;0.000000;,
  -1.000000;-0.000001;0.000000;,
  -0.707108;0.707105;0.000000;,
  -0.000000;1.000000;-0.000000;,
  0.707109;0.707105;-0.000000;,
  0.000000;0.000000;-1.000000;,
  -0.087324;-0.311090;0.946360;,
  -0.351357;-0.694055;0.628360;,
  -0.272073;-0.927329;0.256977;,
  0.244374;-0.952232;-0.183127;,
  0.374706;-0.895954;-0.238457;,
  -0.554882;0.831929;0.000000;,
  -0.405817;-0.913540;-0.027530;,
  -0.220185;-0.974367;-0.046134;,
  0.221434;-0.974078;-0.046250;,
  0.455192;-0.889994;-0.026668;,
  0.000000;0.000000;1.000000;,
  0.538173;0.842834;-0.000000;,
  0.274972;-0.855891;-0.437996;,
  -0.021204;-0.323228;0.946084;,
  0.184999;-0.277368;0.942784;,
  0.000000;0.000000;-1.000000;,
  0.000000;0.000000;1.000000;,
  0.989588;0.000000;-0.143930;,
  0.000000;-0.995287;0.096977;,
  -0.989588;0.000000;-0.143930;,
  0.919959;0.000000;-0.392016;,
  -0.919959;0.000000;-0.392015;,
  0.449711;-0.271232;-0.850995;,
  0.000000;0.999998;0.001885;,
  0.000000;0.999779;0.021046;,
  0.000000;-0.476017;-0.879436;,
  -0.789249;0.000000;-0.614073;,
  0.000000;0.999192;0.040198;,
  0.000000;-0.724268;-0.689519;,
  -0.999277;-0.029240;-0.024298;,
  0.000000;0.240389;0.970677;,
  0.999277;-0.029240;-0.024298;,
  -0.999819;-0.014623;-0.012151;,
  0.000000;-0.222614;0.974907;,
  0.999819;-0.014622;-0.012151;,
  -1.000000;-0.000000;0.000000;,
  0.000000;-0.844432;0.535663;,
  1.000000;0.000000;-0.000000;,
  -1.000000;-0.000000;0.000000;,
  0.000000;-0.968529;0.248901;,
  1.000000;0.000000;-0.000000;,
  0.000000;0.807231;0.590236;,
  0.000000;0.887561;-0.460690;,
  0.000000;0.778260;-0.627942;,
  0.000000;0.844442;-0.535647;,
  0.000025;0.940667;0.339331;,
  -0.000025;0.940667;0.339331;,
  -0.000004;-0.724268;-0.689518;,
  -0.000004;-0.724267;-0.689519;,
  0.000004;-0.724268;-0.689518;,
  0.000004;-0.724267;-0.689519;,
  0.000034;0.807280;0.590169;,
  -0.000034;0.807280;0.590169;,
  0.979790;0.190114;0.062197;,
  0.000000;0.000000;1.000000;,
  -0.979790;0.190114;0.062197;,
  0.000000;0.000000;-1.000000;,
  0.000000;0.994696;0.102855;,
  0.000000;-0.999784;-0.020777;;
  211;
  4;1,2,8,7;,
  4;9,3,9,9;,
  4;26,4,10,27;,
  4;4,5,11,10;,
  4;6,6,12,6;,
  4;28,1,7,28;,
  4;7,8,14,13;,
  4;29,29,15,15;,
  4;27,10,16,30;,
  4;10,11,17,16;,
  4;31,31,18,31;,
  4;12,7,13,32;,
  4;13,14,20,19;,
  4;15,15,21,21;,
  4;30,16,22,33;,
  4;16,17,23,22;,
  4;17,18,24,23;,
  4;18,13,19,24;,
  3;0,2,1;,
  3;0,3,2;,
  3;0,4,3;,
  3;0,34,4;,
  3;0,35,34;,
  3;0,1,35;,
  3;25,25,21;,
  3;25,21,21;,
  3;25,21,25;,
  3;25,25,25;,
  3;25,25,25;,
  3;25,25,25;,
  4;36,37,37,36;,
  4;45,44,44,45;,
  4;37,38,38,37;,
  4;46,45,45,46;,
  4;38,39,39,38;,
  4;47,46,46,47;,
  4;39,40,40,39;,
  4;48,47,47,48;,
  4;40,41,41,40;,
  4;49,48,48,49;,
  4;41,42,42,41;,
  4;50,49,49,50;,
  4;42,43,43,42;,
  4;51,50,50,51;,
  4;43,36,36,43;,
  4;44,51,51,44;,
  4;52,52,52,52;,
  4;53,53,53,53;,
  4;52,52,52,52;,
  4;53,53,53,53;,
  4;52,52,52,52;,
  4;53,53,53,53;,
  4;52,52,52,52;,
  4;53,53,53,53;,
  4;52,52,52,52;,
  4;53,53,53,53;,
  4;52,52,52,52;,
  4;53,53,53,53;,
  4;52,52,52,52;,
  4;53,53,53,53;,
  4;52,52,52,52;,
  4;53,53,53,53;,
  4;55,56,56,55;,
  4;56,57,57,56;,
  4;64,58,58,64;,
  4;58,59,59,58;,
  4;59,60,60,59;,
  4;60,61,61,60;,
  4;65,62,62,65;,
  4;62,55,55,62;,
  3;54,54,54;,
  3;54,54,54;,
  3;54,54,54;,
  3;54,54,54;,
  3;54,54,54;,
  3;54,54,54;,
  3;54,54,54;,
  3;54,54,54;,
  3;63,63,63;,
  3;63,63,63;,
  3;63,63,63;,
  3;63,63,63;,
  3;63,63,63;,
  3;63,63,63;,
  3;63,63,63;,
  3;63,63,63;,
  4;67,68,76,75;,
  4;68,69,77,76;,
  4;69,70,78,77;,
  4;70,71,79,78;,
  4;71,72,80,79;,
  4;72,73,81,80;,
  4;73,74,82,81;,
  4;74,67,75,82;,
  3;66,66,66;,
  3;66,66,66;,
  3;66,66,66;,
  3;66,66,66;,
  3;66,66,66;,
  3;66,66,66;,
  3;66,66,66;,
  3;66,66,66;,
  3;83,75,76;,
  3;83,76,77;,
  3;84,77,78;,
  3;84,78,79;,
  3;84,79,80;,
  3;85,80,81;,
  3;85,81,82;,
  3;83,82,75;,
  4;87,88,88,87;,
  4;88,89,89,88;,
  4;96,90,90,96;,
  4;90,91,91,90;,
  4;91,92,92,91;,
  4;92,93,93,92;,
  4;97,94,94,97;,
  4;94,87,87,94;,
  3;86,86,86;,
  3;86,86,86;,
  3;86,86,86;,
  3;86,86,86;,
  3;86,86,86;,
  3;86,86,86;,
  3;86,86,86;,
  3;86,86,86;,
  3;95,95,95;,
  3;95,95,95;,
  3;95,95,95;,
  3;95,95,95;,
  3;95,95,95;,
  3;95,95,95;,
  3;95,95,95;,
  3;95,95,95;,
  4;99,100,100,99;,
  4;100,101,101,100;,
  4;101,102,102,101;,
  4;102,103,103,102;,
  4;103,104,104,103;,
  4;104,105,105,104;,
  4;105,106,106,105;,
  4;106,99,99,106;,
  3;98,98,98;,
  3;98,98,98;,
  3;98,98,98;,
  3;98,98,98;,
  3;98,98,98;,
  3;98,98,98;,
  3;98,98,98;,
  3;98,98,98;,
  3;107,107,107;,
  3;107,107,107;,
  3;107,107,107;,
  3;107,107,107;,
  3;107,107,107;,
  3;107,107,107;,
  3;107,107,107;,
  3;107,107,107;,
  4;109,110,115,114;,
  4;110,111,116,115;,
  4;111,112,117,116;,
  4;113,113,113,113;,
  4;119,119,119,119;,
  3;108,110,109;,
  3;108,118,118;,
  3;120,112,111;,
  3;108,121,122;,
  3;108,109,121;,
  3;118,118,118;,
  3;123,123,123;,
  3;118,118,118;,
  3;123,123,123;,
  3;123,123,123;,
  4;125,125,128,128;,
  4;126,126,126,126;,
  4;127,127,129,129;,
  4;131,131,132,132;,
  3;124,124,124;,
  3;124,124,124;,
  3;124,124,124;,
  3;124,124,124;,
  3;130,128,128;,
  3;130,133,133;,
  3;134,129,129;,
  3;135,132,132;,
  4;137,137,140,140;,
  4;138,138,141,141;,
  4;139,139,142,142;,
  4;150,150,151,151;,
  4;140,140,143,143;,
  4;141,141,144,144;,
  4;142,142,145,145;,
  4;151,151,152,152;,
  4;143,143,146,146;,
  4;144,144,147,147;,
  4;145,145,148,148;,
  4;152,152,153,154;,
  3;136,155,156;,
  3;136,157,155;,
  3;136,158,157;,
  3;136,156,158;,
  3;149,153,159;,
  3;149,159,160;,
  3;149,160,154;,
  3;149,154,153;,
  4;161,161,161,161;,
  4;162,162,162,162;,
  4;163,163,163,163;,
  4;164,164,164,164;,
  4;165,165,165,165;,
  4;166,166,166,166;;
 }
 MeshTextureCoords {
  330;
  0.000000;0.000000;,
  0.166670;0.000000;,
  0.166670;0.333330;,
  0.000000;0.333330;,
  0.333330;0.000000;,
  0.333330;0.333330;,
  0.500000;0.000000;,
  0.500000;0.333330;,
  0.666670;0.000000;,
  0.666670;0.333330;,
  0.833330;0.000000;,
  0.833330;0.333330;,
  1.000000;0.000000;,
  1.000000;0.333330;,
  0.166670;0.666670;,
  0.000000;0.666670;,
  0.333330;0.666670;,
  0.500000;0.666670;,
  0.666670;0.666670;,
  0.833330;0.666670;,
  1.000000;0.666670;,
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
  0.125000;0.000000;,
  0.125000;1.000000;,
  0.000000;1.000000;,
  0.125000;0.000000;,
  0.000000;0.000000;,
  0.000000;1.000000;,
  0.125000;1.000000;,
  0.250000;0.000000;,
  0.250000;1.000000;,
  0.250000;0.000000;,
  0.250000;1.000000;,
  0.375000;0.000000;,
  0.375000;1.000000;,
  0.375000;0.000000;,
  0.375000;1.000000;,
  0.500000;0.000000;,
  0.500000;1.000000;,
  0.500000;0.000000;,
  0.500000;1.000000;,
  0.625000;0.000000;,
  0.625000;1.000000;,
  0.625000;0.000000;,
  0.625000;1.000000;,
  0.750000;0.000000;,
  0.750000;1.000000;,
  0.750000;0.000000;,
  0.750000;1.000000;,
  0.875000;0.000000;,
  0.875000;1.000000;,
  0.875000;0.000000;,
  0.875000;1.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
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
  0.000000;0.000000;,
  0.200000;0.000000;,
  0.200000;1.000000;,
  0.000000;1.000000;,
  0.400000;0.000000;,
  0.400000;1.000000;,
  0.600000;0.000000;,
  0.600000;1.000000;,
  0.800000;0.000000;,
  0.800000;1.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.100000;0.000000;,
  0.300000;0.000000;,
  0.500000;0.000000;,
  0.700000;0.000000;,
  0.900000;0.000000;,
  0.100000;1.000000;,
  0.300000;1.000000;,
  0.500000;1.000000;,
  0.700000;1.000000;,
  0.900000;1.000000;,
  0.000000;0.000000;,
  0.250000;0.000000;,
  0.250000;1.000000;,
  0.000000;1.000000;,
  0.500000;0.000000;,
  0.500000;1.000000;,
  0.750000;0.000000;,
  0.750000;1.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.125000;0.000000;,
  0.375000;0.000000;,
  0.625000;0.000000;,
  0.875000;0.000000;,
  0.125000;1.000000;,
  0.375000;1.000000;,
  0.625000;1.000000;,
  0.875000;1.000000;,
  0.000000;0.000000;,
  0.250000;0.000000;,
  0.250000;0.333330;,
  0.000000;0.333330;,
  0.500000;0.000000;,
  0.500000;0.333330;,
  0.750000;0.000000;,
  0.750000;0.333330;,
  1.000000;0.000000;,
  1.000000;0.333330;,
  0.250000;0.666670;,
  0.000000;0.666670;,
  0.500000;0.666670;,
  0.750000;0.666670;,
  1.000000;0.666670;,
  0.250000;1.000000;,
  0.000000;1.000000;,
  0.500000;1.000000;,
  0.750000;1.000000;,
  1.000000;1.000000;,
  0.125000;0.000000;,
  0.375000;0.000000;,
  0.625000;0.000000;,
  0.875000;0.000000;,
  0.125000;1.000000;,
  0.375000;1.000000;,
  0.625000;1.000000;,
  0.875000;1.000000;,
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
  1.000000;0.000000;;
 }
}