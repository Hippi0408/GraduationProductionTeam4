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
 360;
 -6.78482;10.26896;-6.17066;,
 6.78482;10.26896;-6.17066;,
 6.78482;4.93971;-6.17066;,
 -6.78482;4.93971;-6.17066;,
 6.78482;10.26896;-6.17066;,
 6.78482;10.26896;-2.05688;,
 6.78482;4.93971;-2.05688;,
 6.78482;4.93971;-6.17066;,
 6.78482;10.26896;2.05688;,
 6.78482;4.93971;2.05688;,
 6.78482;10.26896;6.17066;,
 6.78482;4.93971;6.17066;,
 6.78482;10.26896;6.17066;,
 -6.78482;10.26896;6.17066;,
 -6.78482;4.93971;6.17066;,
 6.78482;4.93971;6.17066;,
 -6.78482;10.26896;6.17066;,
 -6.78482;10.26896;2.05688;,
 -6.78482;4.93971;2.05688;,
 -6.78482;4.93971;6.17066;,
 -6.78482;10.26896;-2.05688;,
 -6.78482;4.93971;-2.05688;,
 -6.78482;10.26896;-6.17066;,
 -6.78482;4.93971;-6.17066;,
 6.78482;10.26896;2.05688;,
 -6.78482;10.26896;2.05688;,
 6.78482;10.26896;-2.05688;,
 -6.78482;10.26896;-2.05688;,
 6.78482;10.26896;-6.17066;,
 -6.78482;10.26896;-6.17066;,
 -6.78482;4.93971;2.05688;,
 6.78482;4.93971;2.05688;,
 -6.78482;4.93971;-2.05688;,
 6.78482;4.93971;-2.05688;,
 -6.78482;4.93971;-6.17066;,
 6.78482;4.93971;-6.17066;,
 8.96782;4.46777;-13.46417;,
 8.96782;2.28027;-12.87802;,
 5.23866;2.28027;-12.87802;,
 5.23866;4.46777;-13.46417;,
 8.96782;0.67889;-11.27667;,
 5.23866;0.67889;-11.27667;,
 8.96782;0.09277;-9.08917;,
 5.23866;0.09277;-9.08917;,
 8.96782;0.09277;9.42016;,
 5.23866;0.09277;9.42016;,
 8.96782;8.84277;9.42016;,
 8.96782;8.84277;-9.08917;,
 5.23866;8.84277;-9.08917;,
 5.23866;8.84277;9.42016;,
 8.96782;8.25662;-11.27667;,
 5.23866;8.25662;-11.27667;,
 8.96782;6.65527;-12.87802;,
 5.23866;6.65527;-12.87802;,
 8.96782;4.46777;-13.46417;,
 5.23866;4.46777;-13.46417;,
 8.96782;4.46775;0.16625;,
 8.96782;4.46775;0.16625;,
 8.96782;4.46775;0.16625;,
 8.96782;4.46775;0.16625;,
 8.96782;4.46775;0.16625;,
 8.96782;4.46775;0.16625;,
 8.96782;4.46775;0.16625;,
 8.96782;4.46775;0.16625;,
 5.23866;4.46775;0.16625;,
 5.23866;4.46775;0.16625;,
 5.23866;4.46775;0.16625;,
 5.23866;4.46775;0.16625;,
 5.23866;4.46775;0.16625;,
 5.23866;4.46775;0.16625;,
 5.23866;4.46775;0.16625;,
 5.23866;4.46775;0.16625;,
 -8.96782;4.46777;-13.46417;,
 -5.23866;4.46777;-13.46417;,
 -5.23866;2.28027;-12.87802;,
 -8.96782;2.28027;-12.87802;,
 -5.23866;0.67889;-11.27667;,
 -8.96782;0.67889;-11.27667;,
 -5.23866;0.09277;-9.08917;,
 -8.96782;0.09277;-9.08917;,
 -5.23866;0.09277;9.42016;,
 -8.96782;0.09277;9.42016;,
 -8.96782;8.84277;9.42016;,
 -5.23866;8.84277;9.42016;,
 -5.23866;8.84277;-9.08917;,
 -8.96782;8.84277;-9.08917;,
 -5.23866;8.25662;-11.27667;,
 -8.96782;8.25662;-11.27667;,
 -5.23866;6.65527;-12.87802;,
 -8.96782;6.65527;-12.87802;,
 -5.23866;4.46777;-13.46417;,
 -8.96782;4.46777;-13.46417;,
 -8.96782;4.46775;0.16625;,
 -8.96782;4.46775;0.16625;,
 -8.96782;4.46775;0.16625;,
 -8.96782;4.46775;0.16625;,
 -8.96782;4.46775;0.16625;,
 -8.96782;4.46775;0.16625;,
 -8.96782;4.46775;0.16625;,
 -8.96782;4.46775;0.16625;,
 -5.23866;4.46775;0.16625;,
 -5.23866;4.46775;0.16625;,
 -5.23866;4.46775;0.16625;,
 -5.23866;4.46775;0.16625;,
 -5.23866;4.46775;0.16625;,
 -5.23866;4.46775;0.16625;,
 -5.23866;4.46775;0.16625;,
 -5.23866;4.46775;0.16625;,
 8.96782;0.09277;9.42016;,
 8.96782;0.67889;11.60766;,
 5.23866;0.67889;11.60766;,
 5.23866;0.09277;9.42016;,
 8.96782;2.28027;13.20902;,
 5.23866;2.28027;13.20902;,
 8.96782;4.46777;13.79516;,
 5.23866;4.46777;13.79516;,
 8.96782;6.65527;13.20902;,
 5.23866;6.65527;13.20902;,
 8.96782;8.25662;11.60766;,
 5.23866;8.25662;11.60766;,
 8.96782;8.84277;9.42016;,
 5.23866;8.84277;9.42016;,
 8.96782;4.46775;0.16625;,
 8.96782;4.46775;0.16625;,
 8.96782;4.46775;0.16625;,
 8.96782;4.46775;0.16625;,
 8.96782;4.46775;0.16625;,
 8.96782;4.46775;0.16625;,
 5.23866;4.46775;0.16625;,
 5.23866;4.46775;0.16625;,
 5.23866;4.46775;0.16625;,
 5.23866;4.46775;0.16625;,
 5.23866;4.46775;0.16625;,
 5.23866;4.46775;0.16625;,
 -8.96782;0.09277;9.42016;,
 -5.23866;0.09277;9.42016;,
 -5.23866;0.67889;11.60766;,
 -8.96782;0.67889;11.60766;,
 -5.23866;2.28027;13.20902;,
 -8.96782;2.28027;13.20902;,
 -5.23866;4.46777;13.79516;,
 -8.96782;4.46777;13.79516;,
 -5.23866;6.65527;13.20902;,
 -8.96782;6.65527;13.20902;,
 -5.23866;8.25662;11.60766;,
 -8.96782;8.25662;11.60766;,
 -5.23866;8.84277;9.42016;,
 -8.96782;8.84277;9.42016;,
 -8.96782;4.46775;0.16625;,
 -8.96782;4.46775;0.16625;,
 -8.96782;4.46775;0.16625;,
 -8.96782;4.46775;0.16625;,
 -8.96782;4.46775;0.16625;,
 -8.96782;4.46775;0.16625;,
 -5.23866;4.46775;0.16625;,
 -5.23866;4.46775;0.16625;,
 -5.23866;4.46775;0.16625;,
 -5.23866;4.46775;0.16625;,
 -5.23866;4.46775;0.16625;,
 -5.23866;4.46775;0.16625;,
 -1.08838;23.37479;-5.26150;,
 6.71235;23.37479;-5.26150;,
 6.71235;14.20808;-6.85484;,
 -1.08838;14.20808;-6.85484;,
 6.71235;23.37479;-5.26150;,
 6.71235;23.37479;-2.48742;,
 6.71235;14.20808;-3.01852;,
 6.71235;14.20808;-6.85484;,
 6.71235;23.37479;0.28667;,
 6.71235;14.20808;0.81779;,
 6.71235;23.37479;3.06075;,
 6.71235;14.20808;4.65411;,
 6.71235;23.37479;3.06075;,
 -1.08838;23.37479;3.06075;,
 -1.08838;14.20808;4.65411;,
 6.71235;14.20808;4.65411;,
 -1.08838;23.37479;3.06075;,
 -1.08838;23.37479;0.28667;,
 -1.08838;14.20808;0.81779;,
 -1.08838;14.20808;4.65411;,
 -1.08838;23.37479;-2.48742;,
 -1.08838;14.20808;-3.01852;,
 -1.08838;23.37479;-5.26150;,
 -1.08838;14.20808;-6.85484;,
 6.71235;23.37479;0.28667;,
 -1.08838;23.37479;0.28667;,
 6.71235;23.37479;-2.48742;,
 -1.08838;23.37479;-2.48742;,
 6.71235;23.37479;-5.26150;,
 -1.08838;23.37479;-5.26150;,
 -1.08838;14.20808;0.81779;,
 6.71235;14.20808;0.81779;,
 -1.08838;14.20808;-3.01852;,
 6.71235;14.20808;-3.01852;,
 -1.08838;14.20808;-6.85484;,
 6.71235;14.20808;-6.85484;,
 -7.06100;15.58142;-7.58061;,
 7.06100;15.58142;-7.58061;,
 7.06100;9.42282;-7.58061;,
 -7.06100;9.42282;-7.58061;,
 7.06100;15.58142;-7.58061;,
 7.06100;15.58142;-0.97344;,
 7.06100;9.42282;-0.97344;,
 7.06100;9.42282;-7.58061;,
 7.06100;15.58142;5.63372;,
 7.06100;9.42282;5.63372;,
 7.06100;15.58142;12.24088;,
 7.06100;9.42282;12.24088;,
 7.06100;15.58142;12.24088;,
 -7.06100;15.58142;12.24088;,
 -7.06100;9.42282;12.24088;,
 7.06100;9.42282;12.24088;,
 -7.06100;15.58142;12.24088;,
 -7.06100;15.58142;5.63372;,
 -7.06100;9.42282;5.63372;,
 -7.06100;9.42282;12.24088;,
 -7.06100;15.58142;-0.97344;,
 -7.06100;9.42282;-0.97344;,
 -7.06100;15.58142;-7.58061;,
 -7.06100;9.42282;-7.58061;,
 7.06100;15.58142;5.63372;,
 -7.06100;15.58142;5.63372;,
 7.06100;15.58142;-0.97344;,
 -7.06100;15.58142;-0.97344;,
 7.06100;15.58142;-7.58061;,
 -7.06100;15.58142;-7.58061;,
 -7.06100;9.42282;5.63372;,
 7.06100;9.42282;5.63372;,
 -7.06100;9.42282;-0.97344;,
 7.06100;9.42282;-0.97344;,
 -7.06100;9.42282;-7.58061;,
 7.06100;9.42282;-7.58061;,
 -8.02525;27.89138;-33.34775;,
 0.01148;27.89138;-33.34775;,
 0.01148;21.87272;-36.49872;,
 -8.02525;21.87272;-36.49872;,
 0.01148;18.62525;-34.08216;,
 -8.02525;18.62525;-34.08216;,
 0.01148;27.89138;-33.34775;,
 0.01148;25.74201;-27.93336;,
 0.01148;21.87272;-30.77718;,
 0.01148;21.87272;-36.49872;,
 0.01148;15.85405;-26.64581;,
 0.01148;18.62525;-34.08216;,
 0.01148;25.74201;-27.93336;,
 -8.02525;25.74201;-27.93336;,
 -8.02525;21.87272;-30.77718;,
 0.01148;21.87272;-30.77718;,
 -8.02525;15.85405;-26.64581;,
 0.01148;15.85405;-26.64581;,
 -8.02525;25.74201;-27.93336;,
 -8.02525;27.89138;-33.34775;,
 -8.02525;21.87272;-36.49872;,
 -8.02525;21.87272;-30.77718;,
 -8.02525;18.62525;-34.08216;,
 -8.02525;15.85405;-26.64581;,
 0.01148;27.89138;-33.34775;,
 -8.02525;27.89138;-33.34775;,
 -8.02525;18.62525;-34.08216;,
 0.01148;18.62525;-34.08216;,
 -3.81696;15.61347;-5.56909;,
 -5.26500;15.55279;-5.15910;,
 -5.26500;29.30221;-11.82870;,
 -3.81696;29.13643;-12.12881;,
 -6.32504;15.38700;-4.03903;,
 -6.32504;29.75515;-11.00873;,
 -6.71303;15.16053;-2.50894;,
 -6.71305;30.37387;-9.88864;,
 -6.32504;14.93406;-0.97888;,
 -6.32504;30.99259;-8.76853;,
 -5.26500;14.76828;0.14124;,
 -5.26500;31.44552;-7.94859;,
 -3.81696;14.70760;0.55118;,
 -3.81696;31.61130;-7.64844;,
 -2.36892;14.76828;0.14124;,
 -2.36892;31.44552;-7.94859;,
 -1.30888;14.93406;-0.97888;,
 -1.30890;30.99259;-8.76853;,
 -0.92088;15.16053;-2.50894;,
 -0.92088;30.37387;-9.88864;,
 -1.30888;15.38700;-4.03903;,
 -1.30888;29.75515;-11.00873;,
 -2.36892;15.55279;-5.15910;,
 -2.36892;29.30221;-11.82869;,
 -3.81696;15.61347;-5.56909;,
 -3.81696;29.13643;-12.12881;,
 -5.26500;31.59383;-20.63633;,
 -3.81696;31.30032;-20.54314;,
 -6.32504;32.39576;-20.89092;,
 -6.71305;33.49120;-21.23868;,
 -6.32504;34.58663;-21.58644;,
 -5.26500;35.38855;-21.84103;,
 -3.81696;35.68206;-21.93420;,
 -2.36892;35.38855;-21.84103;,
 -1.30890;34.58663;-21.58644;,
 -0.92088;33.49120;-21.23868;,
 -1.30888;32.39576;-20.89092;,
 -2.36892;31.59383;-20.63633;,
 -3.81696;31.30032;-20.54314;,
 -5.36200;24.67516;-29.73827;,
 -3.81696;24.47926;-29.49299;,
 -6.49304;25.21046;-30.40839;,
 -6.90704;25.94167;-31.32379;,
 -6.49304;26.67283;-32.23916;,
 -5.36200;27.20813;-32.90931;,
 -3.81696;27.40402;-33.15457;,
 -2.27192;27.20813;-32.90931;,
 -1.14088;26.67283;-32.23916;,
 -0.72690;25.94167;-31.32379;,
 -1.14088;25.21046;-30.40839;,
 -2.27192;24.67516;-29.73827;,
 -3.81696;24.47926;-29.49299;,
 -3.81696;24.05020;-31.39257;,
 -3.81696;24.05020;-31.39257;,
 -3.81696;24.05020;-31.39257;,
 -3.81696;24.05020;-31.39257;,
 -3.81696;24.05020;-31.39257;,
 -3.81696;24.05020;-31.39257;,
 -3.81696;24.05020;-31.39257;,
 -3.81696;24.05020;-31.39257;,
 -3.81696;24.05020;-31.39257;,
 -3.81696;24.05020;-31.39257;,
 -3.81696;24.05020;-31.39257;,
 -3.81696;24.05020;-31.39257;,
 -5.46698;17.90880;5.53130;,
 5.70402;17.90880;5.53130;,
 5.70402;15.15010;4.53924;,
 -5.46698;15.15010;4.53924;,
 5.70402;17.90880;5.53130;,
 5.70402;17.90880;7.25849;,
 5.70402;15.15010;6.92781;,
 5.70402;15.15010;4.53924;,
 5.70402;17.90880;8.98569;,
 5.70402;15.15010;9.31637;,
 5.70402;17.90880;10.71290;,
 5.70402;15.15010;11.70494;,
 5.70402;17.90880;10.71290;,
 -5.46698;17.90880;10.71290;,
 -5.46698;15.15010;11.70494;,
 5.70402;15.15010;11.70494;,
 -5.46698;17.90880;10.71290;,
 -5.46698;17.90880;8.98569;,
 -5.46698;15.15010;9.31637;,
 -5.46698;15.15010;11.70494;,
 -5.46698;17.90880;7.25849;,
 -5.46698;15.15010;6.92781;,
 -5.46698;17.90880;5.53130;,
 -5.46698;15.15010;4.53924;,
 5.70402;17.90880;8.98569;,
 -5.46698;17.90880;8.98569;,
 5.70402;17.90880;7.25849;,
 -5.46698;17.90880;7.25849;,
 5.70402;17.90880;5.53130;,
 -5.46698;17.90880;5.53130;,
 -5.46698;15.15010;9.31637;,
 5.70402;15.15010;9.31637;,
 -5.46698;15.15010;6.92781;,
 5.70402;15.15010;6.92781;,
 -5.46698;15.15010;4.53924;,
 5.70402;15.15010;4.53924;;
 
 198;
 4;0,1,2,3;,
 4;4,5,6,7;,
 4;5,8,9,6;,
 4;8,10,11,9;,
 4;12,13,14,15;,
 4;16,17,18,19;,
 4;17,20,21,18;,
 4;20,22,23,21;,
 4;16,10,24,25;,
 4;25,24,26,27;,
 4;27,26,28,29;,
 4;30,31,11,19;,
 4;32,33,31,30;,
 4;34,35,33,32;,
 4;36,37,38,39;,
 4;37,40,41,38;,
 4;40,42,43,41;,
 4;42,44,45,43;,
 4;46,47,48,49;,
 4;47,50,51,48;,
 4;50,52,53,51;,
 4;52,54,55,53;,
 3;56,37,36;,
 3;57,40,37;,
 3;58,42,40;,
 3;59,44,42;,
 3;60,47,46;,
 3;61,50,47;,
 3;62,52,50;,
 3;63,54,52;,
 3;64,39,38;,
 3;65,38,41;,
 3;66,41,43;,
 3;67,43,45;,
 3;68,49,48;,
 3;69,48,51;,
 3;70,51,53;,
 3;71,53,55;,
 4;72,73,74,75;,
 4;75,74,76,77;,
 4;77,76,78,79;,
 4;79,78,80,81;,
 4;82,83,84,85;,
 4;85,84,86,87;,
 4;87,86,88,89;,
 4;89,88,90,91;,
 3;92,72,75;,
 3;93,75,77;,
 3;94,77,79;,
 3;95,79,81;,
 3;96,82,85;,
 3;97,85,87;,
 3;98,87,89;,
 3;99,89,91;,
 3;100,74,73;,
 3;101,76,74;,
 3;102,78,76;,
 3;103,80,78;,
 3;104,84,83;,
 3;105,86,84;,
 3;106,88,86;,
 3;107,90,88;,
 4;108,109,110,111;,
 4;109,112,113,110;,
 4;112,114,115,113;,
 4;114,116,117,115;,
 4;116,118,119,117;,
 4;118,120,121,119;,
 3;122,109,108;,
 3;123,112,109;,
 3;124,114,112;,
 3;125,116,114;,
 3;126,118,116;,
 3;127,120,118;,
 3;128,111,110;,
 3;129,110,113;,
 3;130,113,115;,
 3;131,115,117;,
 3;132,117,119;,
 3;133,119,121;,
 4;134,135,136,137;,
 4;137,136,138,139;,
 4;139,138,140,141;,
 4;141,140,142,143;,
 4;143,142,144,145;,
 4;145,144,146,147;,
 3;148,134,137;,
 3;149,137,139;,
 3;150,139,141;,
 3;151,141,143;,
 3;152,143,145;,
 3;153,145,147;,
 3;154,136,135;,
 3;155,138,136;,
 3;156,140,138;,
 3;157,142,140;,
 3;158,144,142;,
 3;159,146,144;,
 4;160,161,162,163;,
 4;164,165,166,167;,
 4;165,168,169,166;,
 4;168,170,171,169;,
 4;172,173,174,175;,
 4;176,177,178,179;,
 4;177,180,181,178;,
 4;180,182,183,181;,
 4;176,170,184,185;,
 4;185,184,186,187;,
 4;187,186,188,189;,
 4;190,191,171,179;,
 4;192,193,191,190;,
 4;194,195,193,192;,
 4;196,197,198,199;,
 4;200,201,202,203;,
 4;201,204,205,202;,
 4;204,206,207,205;,
 4;208,209,210,211;,
 4;212,213,214,215;,
 4;213,216,217,214;,
 4;216,218,219,217;,
 4;212,206,220,221;,
 4;221,220,222,223;,
 4;223,222,224,225;,
 4;226,227,207,215;,
 4;228,229,227,226;,
 4;230,231,229,228;,
 4;232,233,234,235;,
 4;235,234,236,237;,
 4;238,239,240,241;,
 4;241,240,242,243;,
 4;244,245,246,247;,
 4;247,246,248,249;,
 4;250,251,252,253;,
 4;253,252,254,255;,
 4;250,239,256,257;,
 4;258,259,242,255;,
 4;260,261,262,263;,
 4;261,264,265,262;,
 4;264,266,267,265;,
 4;266,268,269,267;,
 4;268,270,271,269;,
 4;270,272,273,271;,
 4;272,274,275,273;,
 4;274,276,277,275;,
 4;276,278,279,277;,
 4;278,280,281,279;,
 4;280,282,283,281;,
 4;282,284,285,283;,
 4;263,262,286,287;,
 4;262,265,288,286;,
 4;265,267,289,288;,
 4;267,269,290,289;,
 4;269,271,291,290;,
 4;271,273,292,291;,
 4;273,275,293,292;,
 4;275,277,294,293;,
 4;277,279,295,294;,
 4;279,281,296,295;,
 4;281,283,297,296;,
 4;283,285,298,297;,
 4;287,286,299,300;,
 4;286,288,301,299;,
 4;288,289,302,301;,
 4;289,290,303,302;,
 4;290,291,304,303;,
 4;291,292,305,304;,
 4;292,293,306,305;,
 4;293,294,307,306;,
 4;294,295,308,307;,
 4;295,296,309,308;,
 4;296,297,310,309;,
 4;297,298,311,310;,
 3;312,300,299;,
 3;313,299,301;,
 3;314,301,302;,
 3;315,302,303;,
 3;316,303,304;,
 3;317,304,305;,
 3;318,305,306;,
 3;319,306,307;,
 3;320,307,308;,
 3;321,308,309;,
 3;322,309,310;,
 3;323,310,311;,
 4;324,325,326,327;,
 4;328,329,330,331;,
 4;329,332,333,330;,
 4;332,334,335,333;,
 4;336,337,338,339;,
 4;340,341,342,343;,
 4;341,344,345,342;,
 4;344,346,347,345;,
 4;340,334,348,349;,
 4;349,348,350,351;,
 4;351,350,352,353;,
 4;354,355,335,343;,
 4;356,357,355,354;,
 4;358,359,357,356;;
 
 MeshMaterialList {
  3;
  198;
  0,
  0,
  0,
  0,
  0,
  0,
  0,
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
  0,
  0,
  0,
  0,
  0,
  0,
  0,
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
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2;;
  Material {
   0.800000;0.649600;0.062400;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.000000;0.000000;0.000000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.530400;0.530400;0.530400;1.000000;;
   12.000000;
   0.330000;0.330000;0.330000;;
   0.000000;0.000000;0.000000;;
  }
 }
 MeshNormals {
  109;
  0.000000;0.000000;-1.000000;,
  1.000000;0.000000;0.000000;,
  0.000000;0.000000;1.000000;,
  -1.000000;0.000000;0.000000;,
  0.000000;1.000000;0.000000;,
  0.000000;-1.000000;-0.000000;,
  1.000000;0.000000;0.000000;,
  0.000000;-0.000000;-1.000000;,
  0.000000;-0.499999;-0.866026;,
  0.000000;-0.866025;-0.500000;,
  0.000000;-0.991445;-0.130524;,
  0.000000;-1.000000;-0.000000;,
  0.000000;1.000000;0.000000;,
  0.000000;0.991445;-0.130528;,
  0.000000;0.866025;-0.500001;,
  0.000000;0.500001;-0.866025;,
  -1.000000;0.000000;0.000000;,
  0.000000;-0.965927;0.258814;,
  0.000000;-0.866025;0.500000;,
  0.000000;-0.499999;0.866026;,
  0.000000;-0.000000;1.000000;,
  0.000000;0.500001;0.866025;,
  0.000000;0.866025;0.500001;,
  0.000000;0.965925;0.258822;,
  1.000000;0.000000;-0.000000;,
  -1.000000;0.000000;0.000000;,
  0.000000;0.171250;-0.985228;,
  1.000000;0.000000;0.000000;,
  0.000000;0.171252;0.985227;,
  -1.000000;0.000000;0.000000;,
  0.000000;1.000000;0.000000;,
  0.000000;-1.000000;-0.000000;,
  0.000000;0.000000;-1.000000;,
  1.000000;0.000000;0.000000;,
  0.000000;0.000000;1.000000;,
  -1.000000;0.000000;0.000000;,
  0.000000;1.000000;0.000000;,
  0.000000;-1.000000;-0.000000;,
  0.000000;0.463815;-0.885932;,
  0.000000;-0.799769;-0.600308;,
  1.000000;0.000000;0.000000;,
  0.000000;-0.592222;0.805775;,
  0.000000;0.565927;0.824456;,
  0.000000;-0.596984;-0.802253;,
  -1.000000;0.000000;0.000000;,
  0.000000;0.929444;0.368964;,
  0.000000;-0.937049;-0.349197;,
  0.000000;-0.852956;-0.521982;,
  0.000003;-0.436443;-0.899732;,
  -0.459653;-0.387604;-0.799051;,
  -0.841208;-0.235989;-0.486495;,
  -1.000000;0.000000;0.000001;,
  -0.841210;0.235988;0.486494;,
  -0.459653;0.387604;0.799051;,
  0.000000;0.436442;0.899732;,
  0.459655;0.387604;0.799050;,
  0.841211;0.235988;0.486492;,
  1.000000;0.000002;0.000004;,
  0.841209;-0.235989;-0.486494;,
  0.459654;-0.387604;-0.799051;,
  0.000002;-0.775550;-0.631286;,
  -0.444708;-0.699987;-0.558796;,
  -0.831009;-0.442180;-0.337493;,
  -1.000000;-0.000216;0.000589;,
  -0.830344;0.440383;0.341455;,
  -0.443326;0.694428;0.566773;,
  0.000000;0.767865;0.640612;,
  0.443329;0.694427;0.566773;,
  0.830346;0.440381;0.341453;,
  1.000000;-0.000211;0.000591;,
  0.831011;-0.442176;-0.337492;,
  0.444708;-0.699987;-0.558796;,
  0.000000;-0.980467;0.196682;,
  -0.419479;-0.890836;0.174495;,
  -0.816285;-0.567774;0.106357;,
  -0.999968;0.004146;0.006831;,
  -0.814656;0.572792;-0.090801;,
  -0.419958;0.894040;-0.155972;,
  0.000000;0.984204;-0.177035;,
  0.419961;0.894039;-0.155972;,
  0.814659;0.572788;-0.090800;,
  0.999968;0.004143;0.006838;,
  0.816283;-0.567776;0.106363;,
  0.419479;-0.890836;0.174495;,
  0.000000;-0.906435;0.422346;,
  -0.358948;-0.871218;0.334865;,
  -0.682362;-0.727163;0.074943;,
  -0.999886;0.008645;0.012358;,
  -0.802395;0.485037;-0.347710;,
  -0.405253;0.737009;-0.540915;,
  0.000000;0.804857;-0.593469;,
  0.405254;0.737008;-0.540914;,
  0.802398;0.485034;-0.347707;,
  0.999886;0.008631;0.012371;,
  0.682358;-0.727166;0.074947;,
  0.358949;-0.871218;0.334865;,
  -0.446184;-0.709075;-0.546015;,
  -0.322041;-0.572100;-0.754315;,
  -0.163224;-0.490894;-0.855793;,
  0.000000;-0.465092;-0.885262;,
  0.163224;-0.490894;-0.855793;,
  0.322043;-0.572102;-0.754313;,
  0.446186;-0.709073;-0.546016;,
  0.000000;0.338395;-0.941004;,
  1.000000;0.000000;0.000000;,
  0.000000;0.338390;0.941006;,
  -1.000000;0.000000;0.000000;,
  0.000000;1.000000;0.000000;,
  0.000000;-1.000000;-0.000000;;
  198;
  4;0,0,0,0;,
  4;1,1,1,1;,
  4;1,1,1,1;,
  4;1,1,1,1;,
  4;2,2,2,2;,
  4;3,3,3,3;,
  4;3,3,3,3;,
  4;3,3,3,3;,
  4;4,4,4,4;,
  4;4,4,4,4;,
  4;4,4,4,4;,
  4;5,5,5,5;,
  4;5,5,5,5;,
  4;5,5,5,5;,
  4;7,8,8,7;,
  4;8,9,9,8;,
  4;9,10,10,9;,
  4;10,11,11,10;,
  4;12,13,13,12;,
  4;13,14,14,13;,
  4;14,15,15,14;,
  4;15,7,7,15;,
  3;6,6,6;,
  3;6,6,6;,
  3;6,6,6;,
  3;6,24,6;,
  3;6,6,6;,
  3;6,6,6;,
  3;6,6,6;,
  3;6,6,6;,
  3;16,16,16;,
  3;16,16,16;,
  3;16,16,16;,
  3;16,16,25;,
  3;16,16,16;,
  3;16,16,16;,
  3;16,16,16;,
  3;16,16,16;,
  4;7,7,8,8;,
  4;8,8,9,9;,
  4;9,9,10,10;,
  4;10,10,11,11;,
  4;12,12,13,13;,
  4;13,13,14,14;,
  4;14,14,15,15;,
  4;15,15,7,7;,
  3;16,16,16;,
  3;16,16,16;,
  3;16,16,16;,
  3;16,16,25;,
  3;16,16,16;,
  3;16,16,16;,
  3;16,16,16;,
  3;16,16,16;,
  3;6,6,6;,
  3;6,6,6;,
  3;6,6,6;,
  3;6,24,6;,
  3;6,6,6;,
  3;6,6,6;,
  3;6,6,6;,
  3;6,6,6;,
  4;17,18,18,17;,
  4;18,19,19,18;,
  4;19,20,20,19;,
  4;20,21,21,20;,
  4;21,22,22,21;,
  4;22,23,23,22;,
  3;6,6,6;,
  3;6,6,6;,
  3;6,6,6;,
  3;6,6,6;,
  3;6,6,6;,
  3;6,24,6;,
  3;16,16,16;,
  3;16,16,16;,
  3;16,16,16;,
  3;16,16,16;,
  3;16,16,16;,
  3;16,16,25;,
  4;17,17,18,18;,
  4;18,18,19,19;,
  4;19,19,20,20;,
  4;20,20,21,21;,
  4;21,21,22,22;,
  4;22,22,23,23;,
  3;16,16,16;,
  3;16,16,16;,
  3;16,16,16;,
  3;16,16,16;,
  3;16,16,16;,
  3;16,16,25;,
  3;6,6,6;,
  3;6,6,6;,
  3;6,6,6;,
  3;6,6,6;,
  3;6,6,6;,
  3;6,24,6;,
  4;26,26,26,26;,
  4;27,27,27,27;,
  4;27,27,27,27;,
  4;27,27,27,27;,
  4;28,28,28,28;,
  4;29,29,29,29;,
  4;29,29,29,29;,
  4;29,29,29,29;,
  4;30,30,30,30;,
  4;30,30,30,30;,
  4;30,30,30,30;,
  4;31,31,31,31;,
  4;31,31,31,31;,
  4;31,31,31,31;,
  4;32,32,32,32;,
  4;33,33,33,33;,
  4;33,33,33,33;,
  4;33,33,33,33;,
  4;34,34,34,34;,
  4;35,35,35,35;,
  4;35,35,35,35;,
  4;35,35,35,35;,
  4;36,36,36,36;,
  4;36,36,36,36;,
  4;36,36,36,36;,
  4;37,37,37,37;,
  4;37,37,37,37;,
  4;37,37,37,37;,
  4;38,38,38,38;,
  4;43,43,39,39;,
  4;40,40,40,40;,
  4;40,40,40,40;,
  4;41,41,41,41;,
  4;42,42,42,42;,
  4;44,44,44,44;,
  4;44,44,44,44;,
  4;45,45,45,45;,
  4;39,39,46,46;,
  4;48,49,61,60;,
  4;49,50,62,61;,
  4;50,51,63,62;,
  4;51,52,64,63;,
  4;52,53,65,64;,
  4;53,54,66,65;,
  4;54,55,67,66;,
  4;55,56,68,67;,
  4;56,57,69,68;,
  4;57,58,70,69;,
  4;58,59,71,70;,
  4;59,48,60,71;,
  4;60,61,73,72;,
  4;61,62,74,73;,
  4;62,63,75,74;,
  4;63,64,76,75;,
  4;64,65,77,76;,
  4;65,66,78,77;,
  4;66,67,79,78;,
  4;67,68,80,79;,
  4;68,69,81,80;,
  4;69,70,82,81;,
  4;70,71,83,82;,
  4;71,60,72,83;,
  4;72,73,85,84;,
  4;73,74,86,85;,
  4;74,75,87,86;,
  4;75,76,88,87;,
  4;76,77,89,88;,
  4;77,78,90,89;,
  4;78,79,91,90;,
  4;79,80,92,91;,
  4;80,81,93,92;,
  4;81,82,94,93;,
  4;82,83,95,94;,
  4;83,72,84,95;,
  3;47,84,85;,
  3;47,85,86;,
  3;47,86,96;,
  3;47,96,97;,
  3;47,97,98;,
  3;47,98,99;,
  3;47,99,100;,
  3;47,100,101;,
  3;47,101,102;,
  3;47,102,94;,
  3;47,94,95;,
  3;47,95,84;,
  4;103,103,103,103;,
  4;104,104,104,104;,
  4;104,104,104,104;,
  4;104,104,104,104;,
  4;105,105,105,105;,
  4;106,106,106,106;,
  4;106,106,106,106;,
  4;106,106,106,106;,
  4;107,107,107,107;,
  4;107,107,107,107;,
  4;107,107,107,107;,
  4;108,108,108,108;,
  4;108,108,108,108;,
  4;108,108,108,108;;
 }
 MeshTextureCoords {
  360;
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  0.333330;0.000000;,
  0.333330;1.000000;,
  0.000000;1.000000;,
  0.666670;0.000000;,
  0.666670;1.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
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
  0.000000;0.666670;,
  1.000000;0.666670;,
  0.000000;0.333330;,
  1.000000;0.333330;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  0.000000;0.000000;,
  0.083330;0.000000;,
  0.083330;1.000000;,
  0.000000;1.000000;,
  0.166670;0.000000;,
  0.166670;1.000000;,
  0.250000;0.000000;,
  0.250000;1.000000;,
  0.333330;0.000000;,
  0.333330;1.000000;,
  0.666670;0.000000;,
  0.750000;0.000000;,
  0.750000;1.000000;,
  0.666670;1.000000;,
  0.833330;0.000000;,
  0.833330;1.000000;,
  0.916670;0.000000;,
  0.916670;1.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.041670;0.000000;,
  0.125000;0.000000;,
  0.208330;0.000000;,
  0.291670;0.000000;,
  0.708330;0.000000;,
  0.791670;0.000000;,
  0.875000;0.000000;,
  0.958330;0.000000;,
  0.041670;1.000000;,
  0.125000;1.000000;,
  0.208330;1.000000;,
  0.291670;1.000000;,
  0.708330;1.000000;,
  0.791670;1.000000;,
  0.875000;1.000000;,
  0.958330;1.000000;,
  0.000000;0.000000;,
  0.000000;1.000000;,
  0.083330;1.000000;,
  0.083330;0.000000;,
  0.166670;1.000000;,
  0.166670;0.000000;,
  0.250000;1.000000;,
  0.250000;0.000000;,
  0.333330;1.000000;,
  0.333330;0.000000;,
  0.666670;0.000000;,
  0.666670;1.000000;,
  0.750000;1.000000;,
  0.750000;0.000000;,
  0.833330;1.000000;,
  0.833330;0.000000;,
  0.916670;1.000000;,
  0.916670;0.000000;,
  1.000000;1.000000;,
  1.000000;0.000000;,
  0.041670;0.000000;,
  0.125000;0.000000;,
  0.208330;0.000000;,
  0.291670;0.000000;,
  0.708330;0.000000;,
  0.791670;0.000000;,
  0.875000;0.000000;,
  0.958330;0.000000;,
  0.041670;1.000000;,
  0.125000;1.000000;,
  0.208330;1.000000;,
  0.291670;1.000000;,
  0.708330;1.000000;,
  0.791670;1.000000;,
  0.875000;1.000000;,
  0.958330;1.000000;,
  0.250000;0.000000;,
  0.333330;0.000000;,
  0.333330;1.000000;,
  0.250000;1.000000;,
  0.416670;0.000000;,
  0.416670;1.000000;,
  0.500000;0.000000;,
  0.500000;1.000000;,
  0.583330;0.000000;,
  0.583330;1.000000;,
  0.666670;0.000000;,
  0.666670;1.000000;,
  0.750000;0.000000;,
  0.750000;1.000000;,
  0.291670;0.000000;,
  0.375000;0.000000;,
  0.458330;0.000000;,
  0.541670;0.000000;,
  0.625000;0.000000;,
  0.708330;0.000000;,
  0.291670;1.000000;,
  0.375000;1.000000;,
  0.458330;1.000000;,
  0.541670;1.000000;,
  0.625000;1.000000;,
  0.708330;1.000000;,
  0.250000;0.000000;,
  0.250000;1.000000;,
  0.333330;1.000000;,
  0.333330;0.000000;,
  0.416670;1.000000;,
  0.416670;0.000000;,
  0.500000;1.000000;,
  0.500000;0.000000;,
  0.583330;1.000000;,
  0.583330;0.000000;,
  0.666670;1.000000;,
  0.666670;0.000000;,
  0.750000;1.000000;,
  0.750000;0.000000;,
  0.291670;0.000000;,
  0.375000;0.000000;,
  0.458330;0.000000;,
  0.541670;0.000000;,
  0.625000;0.000000;,
  0.708330;0.000000;,
  0.291670;1.000000;,
  0.375000;1.000000;,
  0.458330;1.000000;,
  0.541670;1.000000;,
  0.625000;1.000000;,
  0.708330;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  0.333330;0.000000;,
  0.333330;1.000000;,
  0.000000;1.000000;,
  0.666670;0.000000;,
  0.666670;1.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
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
  0.000000;0.666670;,
  1.000000;0.666670;,
  0.000000;0.333330;,
  1.000000;0.333330;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  0.333330;0.000000;,
  0.333330;1.000000;,
  0.000000;1.000000;,
  0.666670;0.000000;,
  0.666670;1.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
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
  0.000000;0.666670;,
  1.000000;0.666670;,
  0.000000;0.333330;,
  1.000000;0.333330;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;0.500000;,
  0.000000;0.500000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;0.500000;,
  0.000000;0.500000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;0.500000;,
  0.000000;0.500000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;0.500000;,
  0.000000;0.500000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  0.333330;0.000000;,
  0.333330;0.083330;,
  0.500000;0.083330;,
  0.500000;0.000000;,
  0.333330;0.166670;,
  0.500000;0.166670;,
  0.333330;0.250000;,
  0.500000;0.250000;,
  0.333330;0.333330;,
  0.500000;0.333330;,
  0.333330;0.416670;,
  0.500000;0.416670;,
  0.333330;0.500000;,
  0.500000;0.500000;,
  0.333330;0.583330;,
  0.500000;0.583330;,
  0.333330;0.666670;,
  0.500000;0.666670;,
  0.333330;0.750000;,
  0.500000;0.750000;,
  0.333330;0.833330;,
  0.500000;0.833330;,
  0.333330;0.916670;,
  0.500000;0.916670;,
  0.333330;1.000000;,
  0.500000;1.000000;,
  0.666670;0.083330;,
  0.666670;0.000000;,
  0.666670;0.166670;,
  0.666670;0.250000;,
  0.666670;0.333330;,
  0.666670;0.416670;,
  0.666670;0.500000;,
  0.666670;0.583330;,
  0.666670;0.666670;,
  0.666670;0.750000;,
  0.666670;0.833330;,
  0.666670;0.916670;,
  0.666670;1.000000;,
  0.833330;0.083330;,
  0.833330;0.000000;,
  0.833330;0.166670;,
  0.833330;0.250000;,
  0.833330;0.333330;,
  0.833330;0.416670;,
  0.833330;0.500000;,
  0.833330;0.583330;,
  0.833330;0.666670;,
  0.833330;0.750000;,
  0.833330;0.833330;,
  0.833330;0.916670;,
  0.833330;1.000000;,
  1.000000;0.041670;,
  1.000000;0.125000;,
  1.000000;0.208330;,
  1.000000;0.291670;,
  1.000000;0.375000;,
  1.000000;0.458330;,
  1.000000;0.541670;,
  1.000000;0.625000;,
  1.000000;0.708330;,
  1.000000;0.791670;,
  1.000000;0.875000;,
  1.000000;0.958330;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  0.333330;0.000000;,
  0.333330;1.000000;,
  0.000000;1.000000;,
  0.666670;0.000000;,
  0.666670;1.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
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
  0.000000;0.666670;,
  1.000000;0.666670;,
  0.000000;0.333330;,
  1.000000;0.333330;,
  0.000000;0.000000;,
  1.000000;0.000000;;
 }
}
