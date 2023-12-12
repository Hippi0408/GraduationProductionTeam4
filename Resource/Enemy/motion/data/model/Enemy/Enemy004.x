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
 178;
 0.55658;23.79146;2.51569;,
 0.55658;12.16027;7.76817;,
 0.55658;-6.09418;13.03027;,
 0.55658;-2.23004;9.64251;,
 0.55658;12.16027;7.76817;,
 -0.47196;12.16027;7.76817;,
 -0.47196;-6.09418;13.03027;,
 0.55658;-6.09418;13.03027;,
 -0.47196;12.16027;7.76817;,
 -0.47196;23.79146;2.51569;,
 -0.47196;-2.23004;9.64251;,
 -0.47196;-6.09418;13.03027;,
 -0.47196;23.79146;2.51569;,
 0.55658;23.79146;2.51569;,
 0.55658;-2.23004;9.64251;,
 -0.47196;-2.23004;9.64251;,
 0.55658;12.16027;7.76817;,
 0.55658;23.79146;2.51569;,
 0.55658;-2.23004;9.64251;,
 0.55658;-6.09418;13.03027;,
 0.04231;14.26252;-0.14998;,
 2.74828;8.88473;2.55600;,
 3.86914;8.88473;-0.14998;,
 0.04231;14.26252;-0.14998;,
 0.04231;8.88473;3.67686;,
 0.04231;14.26252;-0.14998;,
 -2.66367;8.88473;2.55600;,
 0.04231;14.26252;-0.14998;,
 -3.78452;8.88473;-0.14998;,
 0.04231;14.26252;-0.14998;,
 -2.66367;8.88473;-2.85597;,
 0.04231;14.26252;-0.14998;,
 0.04230;8.88473;-3.97683;,
 0.04231;14.26252;-0.14998;,
 2.74828;8.88473;-2.85597;,
 0.04231;14.26252;-0.14998;,
 3.86914;8.88473;-0.14998;,
 5.04231;6.71701;4.85002;,
 7.11338;6.71701;-0.14998;,
 0.04231;6.71701;6.92109;,
 -4.95769;6.71701;4.85002;,
 -7.02876;6.71701;-0.14998;,
 -4.95770;6.71701;-5.14999;,
 0.04230;6.71701;-7.22106;,
 5.04230;6.71701;-5.14999;,
 7.11338;6.71701;-0.14998;,
 6.57512;3.47277;6.38284;,
 9.28110;3.47277;-0.14998;,
 0.04231;3.47277;9.08882;,
 -6.49050;3.47277;6.38284;,
 -9.19648;3.47277;-0.14998;,
 -6.49051;3.47277;-8.32387;,
 0.04230;3.47277;-9.38879;,
 6.57511;3.47277;-7.58925;,
 9.28110;3.47277;-0.14998;,
 7.11338;-0.35406;6.92109;,
 13.18738;-0.35406;-0.14998;,
 0.04231;-0.35406;9.85002;,
 -7.02876;-0.35406;6.92109;,
 -14.41537;-0.35406;-0.14998;,
 -7.02877;-0.35406;-8.45878;,
 0.04230;-0.35406;-6.54256;,
 7.11337;-0.35406;-8.33933;,
 13.18738;-0.35406;-0.14998;,
 6.57512;-4.18090;6.38284;,
 9.28110;-4.18090;-0.14998;,
 0.04231;-4.18090;9.08882;,
 -6.49050;-4.18090;6.38284;,
 -9.19648;-4.18090;-0.14998;,
 -6.49051;-4.18090;-8.50615;,
 0.04230;-4.18090;-9.38879;,
 6.28472;-4.31208;-7.68741;,
 9.28110;-4.18090;-0.14998;,
 5.04231;-7.42513;4.85002;,
 7.11338;-7.42513;-0.14998;,
 0.04231;-7.42513;6.92109;,
 -4.95769;-7.42513;4.85002;,
 -7.02876;-7.42513;-0.14998;,
 -4.95770;-7.42513;-5.14999;,
 0.04230;-7.42513;-7.22106;,
 5.04230;-7.42513;-5.14999;,
 7.11338;-7.42513;-0.14998;,
 2.74828;-9.59286;2.55600;,
 3.86914;-9.59286;-0.14998;,
 0.04231;-9.59286;3.67686;,
 -2.66367;-9.59286;2.55600;,
 -3.78452;-9.59286;-0.14998;,
 -2.66367;-9.59286;-2.85597;,
 0.04230;-9.59286;-3.97683;,
 2.74828;-9.59286;-2.85597;,
 3.86914;-9.59286;-0.14998;,
 0.04231;-14.54503;-0.14998;,
 0.04231;-14.54503;-0.14998;,
 0.04231;-14.54503;-0.14998;,
 0.04231;-14.54503;-0.14998;,
 0.04231;-14.54503;-0.14998;,
 0.04231;-14.54503;-0.14998;,
 0.04231;-14.54503;-0.14998;,
 0.04231;-14.54503;-0.14998;,
 0.04230;2.67471;-8.20026;,
 0.70859;2.46554;-7.60321;,
 0.98457;2.46554;-8.20026;,
 0.04230;2.67471;-8.20026;,
 0.04230;2.46554;-7.35590;,
 0.04230;2.67471;-8.20026;,
 -0.62399;2.46554;-7.60321;,
 0.04230;2.67471;-8.20026;,
 -0.89997;2.46554;-8.20026;,
 0.04230;2.67471;-8.20026;,
 -0.62399;2.46554;-8.79730;,
 0.04230;2.67471;-8.20026;,
 0.04230;2.46554;-9.04461;,
 0.04230;2.67471;-8.20026;,
 0.70859;2.46554;-8.79730;,
 0.04230;2.67471;-8.20026;,
 0.98457;2.46554;-8.20026;,
 1.27344;1.86989;-7.09706;,
 1.78339;1.86989;-8.20026;,
 0.04230;1.86989;-6.64010;,
 -1.18884;1.86989;-7.09706;,
 -1.69879;1.86989;-8.20026;,
 -1.18884;1.86989;-9.30346;,
 0.04230;1.86989;-9.76041;,
 1.27344;1.86989;-9.30346;,
 1.78339;1.86989;-8.20026;,
 1.65086;0.97843;-6.75886;,
 2.31714;0.97843;-8.20026;,
 0.04230;0.97843;-6.16181;,
 -1.56626;0.97843;-6.75886;,
 -2.23254;0.97843;-8.20026;,
 -1.56626;0.97843;-9.64166;,
 0.04230;0.97843;-10.23870;,
 1.65086;0.97843;-9.64166;,
 2.31714;0.97843;-8.20026;,
 1.78339;-0.07312;-6.64010;,
 2.50457;-0.07312;-8.20026;,
 0.04230;-0.07312;-5.99386;,
 -1.69879;-0.07312;-6.64010;,
 -2.41997;-0.07312;-8.20026;,
 -1.69879;-0.07312;-9.76041;,
 0.04230;-0.07312;-10.40665;,
 1.78339;-0.07312;-9.76041;,
 2.50457;-0.07312;-8.20026;,
 1.65086;-1.12467;-6.75886;,
 2.31714;-1.12467;-8.20026;,
 0.04230;-1.12467;-6.16181;,
 -1.56626;-1.12467;-6.75886;,
 -2.23254;-1.12467;-8.20026;,
 -1.56626;-1.12467;-9.64166;,
 0.04230;-1.12467;-10.23870;,
 1.65086;-1.12467;-9.64166;,
 2.31714;-1.12467;-8.20026;,
 1.27344;-2.01614;-7.09706;,
 1.78339;-2.01614;-8.20026;,
 0.04230;-2.01614;-6.64010;,
 -1.18884;-2.01614;-7.09706;,
 -1.69879;-2.01614;-8.20026;,
 -1.18884;-2.01614;-9.30346;,
 0.04230;-2.01614;-9.76041;,
 1.27344;-2.01614;-9.30346;,
 1.78339;-2.01614;-8.20026;,
 0.70859;-2.61179;-7.60321;,
 0.98457;-2.61179;-8.20026;,
 0.04230;-2.61179;-7.35590;,
 -0.62399;-2.61179;-7.60321;,
 -0.89997;-2.61179;-8.20026;,
 -0.62399;-2.61179;-8.79730;,
 0.04230;-2.61179;-9.04461;,
 0.70859;-2.61179;-8.79730;,
 0.98457;-2.61179;-8.20026;,
 0.04230;-2.82096;-8.20026;,
 0.04230;-2.82096;-8.20026;,
 0.04230;-2.82096;-8.20026;,
 0.04230;-2.82096;-8.20026;,
 0.04230;-2.82096;-8.20026;,
 0.04230;-2.82096;-8.20026;,
 0.04230;-2.82096;-8.20026;,
 0.04230;-2.82096;-8.20026;;
 
 134;
 4;0,1,2,3;,
 4;4,5,6,7;,
 4;8,9,10,11;,
 4;12,13,14,15;,
 4;12,5,16,17;,
 4;18,19,6,15;,
 3;20,21,22;,
 3;23,24,21;,
 3;25,26,24;,
 3;27,28,26;,
 3;29,30,28;,
 3;31,32,30;,
 3;33,34,32;,
 3;35,36,34;,
 4;22,21,37,38;,
 4;21,24,39,37;,
 4;24,26,40,39;,
 4;26,28,41,40;,
 4;28,30,42,41;,
 4;30,32,43,42;,
 4;32,34,44,43;,
 4;34,36,45,44;,
 4;38,37,46,47;,
 4;37,39,48,46;,
 4;39,40,49,48;,
 4;40,41,50,49;,
 4;41,42,51,50;,
 4;42,43,52,51;,
 4;43,44,53,52;,
 4;44,45,54,53;,
 4;47,46,55,56;,
 4;46,48,57,55;,
 4;48,49,58,57;,
 4;49,50,59,58;,
 4;50,51,60,59;,
 4;51,52,61,60;,
 4;52,53,62,61;,
 4;53,54,63,62;,
 4;56,55,64,65;,
 4;55,57,66,64;,
 4;57,58,67,66;,
 4;58,59,68,67;,
 4;59,60,69,68;,
 4;60,61,70,69;,
 4;61,62,71,70;,
 4;62,63,72,71;,
 4;65,64,73,74;,
 4;64,66,75,73;,
 4;66,67,76,75;,
 4;67,68,77,76;,
 4;68,69,78,77;,
 4;69,70,79,78;,
 4;70,71,80,79;,
 4;71,72,81,80;,
 4;74,73,82,83;,
 4;73,75,84,82;,
 4;75,76,85,84;,
 4;76,77,86,85;,
 4;77,78,87,86;,
 4;78,79,88,87;,
 4;79,80,89,88;,
 4;80,81,90,89;,
 3;83,82,91;,
 3;82,84,92;,
 3;84,85,93;,
 3;85,86,94;,
 3;86,87,95;,
 3;87,88,96;,
 3;88,89,97;,
 3;89,90,98;,
 3;99,100,101;,
 3;102,103,100;,
 3;104,105,103;,
 3;106,107,105;,
 3;108,109,107;,
 3;110,111,109;,
 3;112,113,111;,
 3;114,115,113;,
 4;101,100,116,117;,
 4;100,103,118,116;,
 4;103,105,119,118;,
 4;105,107,120,119;,
 4;107,109,121,120;,
 4;109,111,122,121;,
 4;111,113,123,122;,
 4;113,115,124,123;,
 4;117,116,125,126;,
 4;116,118,127,125;,
 4;118,119,128,127;,
 4;119,120,129,128;,
 4;120,121,130,129;,
 4;121,122,131,130;,
 4;122,123,132,131;,
 4;123,124,133,132;,
 4;126,125,134,135;,
 4;125,127,136,134;,
 4;127,128,137,136;,
 4;128,129,138,137;,
 4;129,130,139,138;,
 4;130,131,140,139;,
 4;131,132,141,140;,
 4;132,133,142,141;,
 4;135,134,143,144;,
 4;134,136,145,143;,
 4;136,137,146,145;,
 4;137,138,147,146;,
 4;138,139,148,147;,
 4;139,140,149,148;,
 4;140,141,150,149;,
 4;141,142,151,150;,
 4;144,143,152,153;,
 4;143,145,154,152;,
 4;145,146,155,154;,
 4;146,147,156,155;,
 4;147,148,157,156;,
 4;148,149,158,157;,
 4;149,150,159,158;,
 4;150,151,160,159;,
 4;153,152,161,162;,
 4;152,154,163,161;,
 4;154,155,164,163;,
 4;155,156,165,164;,
 4;156,157,166,165;,
 4;157,158,167,166;,
 4;158,159,168,167;,
 4;159,160,169,168;,
 3;162,161,170;,
 3;161,163,171;,
 3;163,164,172;,
 3;164,165,173;,
 3;165,166,174;,
 3;166,167,175;,
 3;167,168,176;,
 3;168,169,177;;
 
 MeshMaterialList {
  3;
  134;
  2,
  2,
  2,
  2,
  2,
  2,
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
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
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
   0.106400;0.000000;0.800000;1.000000;;
   5.000000;
   0.820000;0.820000;0.820000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.800000;0.000000;0.068800;1.000000;;
   5.000000;
   0.710000;0.710000;0.710000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.144000;0.144000;0.144000;1.000000;;
   5.000000;
   0.620000;0.620000;0.620000;;
   0.000000;0.000000;0.000000;;
  }
 }
 MeshNormals {
  136;
  1.000000;-0.000000;-0.000000;,
  0.000000;0.345164;0.938542;,
  0.000000;0.276985;0.960874;,
  -1.000000;0.000000;0.000000;,
  -0.000000;-0.264154;-0.964481;,
  -0.000000;-0.473768;-0.880650;,
  0.000000;0.411566;0.911380;,
  0.000000;-0.659236;-0.751936;,
  0.296360;0.632668;0.715474;,
  0.694773;0.719229;0.000000;,
  0.491279;0.719229;0.491278;,
  0.000000;0.719230;0.694773;,
  -0.491279;0.719229;0.491278;,
  -0.694773;0.719229;0.000001;,
  -0.491279;0.719230;-0.491277;,
  -0.000000;0.719230;-0.694772;,
  0.491279;0.719230;-0.491278;,
  0.700637;0.713493;0.006004;,
  0.498494;0.709231;0.498493;,
  0.000000;0.709231;0.704976;,
  -0.498494;0.709231;0.498493;,
  -0.697899;0.716130;0.009779;,
  -0.460217;0.751042;-0.473430;,
  0.014915;0.745014;-0.666882;,
  0.476812;0.734333;-0.483120;,
  0.853928;0.520019;0.019664;,
  0.606564;0.438713;0.663032;,
  0.000000;0.384551;0.923104;,
  -0.595541;0.450229;0.665301;,
  -0.838192;0.544716;0.026794;,
  -0.622642;0.593643;-0.509810;,
  0.032485;0.199664;-0.979326;,
  0.647406;0.558146;-0.518978;,
  0.999537;-0.007395;0.029513;,
  0.645798;0.000000;0.763508;,
  0.000000;0.000000;1.000000;,
  -0.629930;0.000000;0.776652;,
  -0.857152;0.513903;0.034569;,
  -0.884269;0.003496;-0.466966;,
  0.033035;0.011752;-0.999385;,
  -0.013515;0.011747;-0.999840;,
  0.851445;-0.524220;0.015323;,
  0.606563;-0.438714;0.663032;,
  0.000000;-0.384551;0.923104;,
  -0.595541;-0.450229;0.665301;,
  -0.838797;-0.543719;0.028089;,
  -0.620419;-0.597819;-0.507634;,
  0.119283;-0.002569;-0.992857;,
  0.417836;-0.364067;-0.832387;,
  0.702461;-0.711714;0.003485;,
  0.498494;-0.709230;0.498494;,
  0.000000;-0.709231;0.704976;,
  -0.498494;-0.709230;0.498494;,
  -0.697303;-0.716698;0.010599;,
  -0.456214;-0.754790;-0.471340;,
  0.016407;-0.748145;-0.663332;,
  0.475622;-0.733911;-0.484932;,
  0.680840;-0.732432;0.000000;,
  0.481427;-0.732432;0.481426;,
  0.000000;-0.732432;0.680840;,
  -0.481427;-0.732432;0.481426;,
  -0.680840;-0.732432;0.000001;,
  -0.481427;-0.732433;-0.481425;,
  -0.000000;-0.732433;-0.680839;,
  0.481427;-0.732432;-0.481426;,
  0.286266;-0.663644;0.691106;,
  -0.715475;0.632667;-0.296358;,
  0.576128;0.579789;-0.576126;,
  0.070775;-0.319092;-0.945077;,
  0.080702;0.011730;-0.996669;,
  -0.015353;-0.239323;-0.970819;,
  0.885182;-0.013020;-0.465063;,
  -0.859315;-0.510213;0.035499;,
  0.081574;0.341237;-0.936431;,
  0.785421;-0.454425;-0.420252;,
  -0.184676;-0.660246;-0.727991;,
  -0.691107;-0.663644;-0.286265;,
  0.559515;-0.611464;-0.559513;,
  0.000000;1.000000;-0.000001;,
  0.413391;0.910554;-0.000001;,
  0.289890;0.901915;0.320177;,
  0.000000;0.893487;0.449088;,
  -0.289889;0.901915;0.320177;,
  -0.413390;0.910554;-0.000001;,
  -0.289888;0.901915;-0.320178;,
  0.000000;0.893487;-0.449089;,
  0.289889;0.901915;-0.320179;,
  0.739568;0.673082;-0.000001;,
  0.511086;0.652993;0.558919;,
  0.000000;0.634124;0.773232;,
  -0.511086;0.652993;0.558919;,
  -0.739568;0.673082;-0.000001;,
  -0.511084;0.652995;-0.558920;,
  0.000000;0.634124;-0.773231;,
  0.511084;0.652994;-0.558921;,
  0.935942;0.352155;-0.000001;,
  0.638491;0.335656;0.692578;,
  -0.000000;0.320671;0.947191;,
  -0.638491;0.335656;0.692578;,
  -0.935942;0.352155;-0.000000;,
  -0.638490;0.335655;-0.692580;,
  0.000000;0.320668;-0.947191;,
  0.638489;0.335655;-0.692580;,
  1.000000;-0.000000;-0.000001;,
  0.678875;0.000000;0.734254;,
  -0.000000;0.000000;1.000000;,
  -0.678875;0.000000;0.734254;,
  -1.000000;0.000000;-0.000001;,
  -0.678873;-0.000000;-0.734255;,
  0.000000;-0.000000;-1.000000;,
  0.678873;-0.000000;-0.734256;,
  0.935943;-0.352153;-0.000001;,
  0.638492;-0.335654;0.692578;,
  -0.000000;-0.320668;0.947192;,
  -0.638492;-0.335654;0.692578;,
  -0.935943;-0.352153;-0.000000;,
  -0.638490;-0.335653;-0.692580;,
  0.000000;-0.320666;-0.947192;,
  0.638490;-0.335653;-0.692580;,
  0.739569;-0.673081;-0.000001;,
  0.511087;-0.652992;0.558920;,
  -0.000000;-0.634122;0.773233;,
  -0.511087;-0.652991;0.558920;,
  -0.739569;-0.673080;-0.000001;,
  -0.511085;-0.652993;-0.558921;,
  -0.000000;-0.634123;-0.773232;,
  0.511084;-0.652993;-0.558921;,
  0.413390;-0.910554;-0.000001;,
  0.289889;-0.901915;0.320177;,
  -0.000000;-0.893487;0.449089;,
  -0.289890;-0.901915;0.320177;,
  -0.413391;-0.910554;-0.000001;,
  -0.289889;-0.901915;-0.320179;,
  -0.000000;-0.893487;-0.449089;,
  0.289888;-0.901915;-0.320178;,
  0.000000;-1.000000;-0.000001;;
  134;
  4;0,0,0,0;,
  4;1,1,2,2;,
  4;3,3,3,3;,
  4;4,4,5,5;,
  4;6,1,1,6;,
  4;5,7,7,5;,
  3;8,10,9;,
  3;8,11,10;,
  3;8,12,11;,
  3;66,13,12;,
  3;66,14,13;,
  3;66,15,14;,
  3;67,16,15;,
  3;67,9,16;,
  4;9,10,18,17;,
  4;10,11,19,18;,
  4;11,12,20,19;,
  4;12,13,21,20;,
  4;13,14,22,21;,
  4;14,15,23,22;,
  4;15,16,24,23;,
  4;16,9,17,24;,
  4;17,18,26,25;,
  4;18,19,27,26;,
  4;19,20,28,27;,
  4;20,21,29,28;,
  4;21,22,30,29;,
  4;22,23,31,30;,
  4;23,24,32,31;,
  4;24,17,25,32;,
  4;25,26,34,33;,
  4;26,27,35,34;,
  4;27,28,36,35;,
  4;28,29,37,36;,
  4;29,30,38,37;,
  4;68,31,39,69;,
  4;31,70,40,39;,
  4;32,25,33,71;,
  4;33,34,42,41;,
  4;34,35,43,42;,
  4;35,36,44,43;,
  4;36,72,45,44;,
  4;72,38,46,45;,
  4;69,39,47,73;,
  4;39,40,48,47;,
  4;71,33,41,74;,
  4;41,42,50,49;,
  4;42,43,51,50;,
  4;43,44,52,51;,
  4;44,45,53,52;,
  4;45,46,54,53;,
  4;46,75,55,54;,
  4;47,48,56,55;,
  4;48,41,49,56;,
  4;49,50,58,57;,
  4;50,51,59,58;,
  4;51,52,60,59;,
  4;52,53,61,60;,
  4;53,54,62,61;,
  4;54,55,63,62;,
  4;55,56,64,63;,
  4;56,49,57,64;,
  3;57,58,65;,
  3;58,59,65;,
  3;59,60,65;,
  3;60,61,76;,
  3;61,62,76;,
  3;62,63,76;,
  3;63,64,77;,
  3;64,57,77;,
  3;78,80,79;,
  3;78,81,80;,
  3;78,82,81;,
  3;78,83,82;,
  3;78,84,83;,
  3;78,85,84;,
  3;78,86,85;,
  3;78,79,86;,
  4;79,80,88,87;,
  4;80,81,89,88;,
  4;81,82,90,89;,
  4;82,83,91,90;,
  4;83,84,92,91;,
  4;84,85,93,92;,
  4;85,86,94,93;,
  4;86,79,87,94;,
  4;87,88,96,95;,
  4;88,89,97,96;,
  4;89,90,98,97;,
  4;90,91,99,98;,
  4;91,92,100,99;,
  4;92,93,101,100;,
  4;93,94,102,101;,
  4;94,87,95,102;,
  4;95,96,104,103;,
  4;96,97,105,104;,
  4;97,98,106,105;,
  4;98,99,107,106;,
  4;99,100,108,107;,
  4;100,101,109,108;,
  4;101,102,110,109;,
  4;102,95,103,110;,
  4;103,104,112,111;,
  4;104,105,113,112;,
  4;105,106,114,113;,
  4;106,107,115,114;,
  4;107,108,116,115;,
  4;108,109,117,116;,
  4;109,110,118,117;,
  4;110,103,111,118;,
  4;111,112,120,119;,
  4;112,113,121,120;,
  4;113,114,122,121;,
  4;114,115,123,122;,
  4;115,116,124,123;,
  4;116,117,125,124;,
  4;117,118,126,125;,
  4;118,111,119,126;,
  4;119,120,128,127;,
  4;120,121,129,128;,
  4;121,122,130,129;,
  4;122,123,131,130;,
  4;123,124,132,131;,
  4;124,125,133,132;,
  4;125,126,134,133;,
  4;126,119,127,134;,
  3;127,128,135;,
  3;128,129,135;,
  3;129,130,135;,
  3;130,131,135;,
  3;131,132,135;,
  3;132,133,135;,
  3;133,134,135;,
  3;134,127,135;;
 }
 MeshTextureCoords {
  178;
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
  0.062500;0.000000;,
  0.125000;0.125000;,
  0.000000;0.125000;,
  0.187500;0.000000;,
  0.250000;0.125000;,
  0.312500;0.000000;,
  0.375000;0.125000;,
  0.437500;0.000000;,
  0.500000;0.125000;,
  0.562500;0.000000;,
  0.625000;0.125000;,
  0.687500;0.000000;,
  0.750000;0.125000;,
  0.812500;0.000000;,
  0.875000;0.125000;,
  0.937500;0.000000;,
  1.000000;0.125000;,
  0.125000;0.250000;,
  0.000000;0.250000;,
  0.250000;0.250000;,
  0.375000;0.250000;,
  0.500000;0.250000;,
  0.625000;0.250000;,
  0.750000;0.250000;,
  0.875000;0.250000;,
  1.000000;0.250000;,
  0.125000;0.375000;,
  0.000000;0.375000;,
  0.250000;0.375000;,
  0.375000;0.375000;,
  0.500000;0.375000;,
  0.625000;0.375000;,
  0.750000;0.375000;,
  0.875000;0.375000;,
  1.000000;0.375000;,
  0.125000;0.500000;,
  0.000000;0.500000;,
  0.250000;0.500000;,
  0.375000;0.500000;,
  0.500000;0.500000;,
  0.625000;0.500000;,
  0.750000;0.500000;,
  0.875000;0.500000;,
  1.000000;0.500000;,
  0.125000;0.625000;,
  0.000000;0.625000;,
  0.250000;0.625000;,
  0.375000;0.625000;,
  0.500000;0.625000;,
  0.625000;0.625000;,
  0.750000;0.625000;,
  0.875000;0.625000;,
  1.000000;0.625000;,
  0.125000;0.750000;,
  0.000000;0.750000;,
  0.250000;0.750000;,
  0.375000;0.750000;,
  0.500000;0.750000;,
  0.625000;0.750000;,
  0.750000;0.750000;,
  0.875000;0.750000;,
  1.000000;0.750000;,
  0.125000;0.875000;,
  0.000000;0.875000;,
  0.250000;0.875000;,
  0.375000;0.875000;,
  0.500000;0.875000;,
  0.625000;0.875000;,
  0.750000;0.875000;,
  0.875000;0.875000;,
  1.000000;0.875000;,
  0.062500;1.000000;,
  0.187500;1.000000;,
  0.312500;1.000000;,
  0.437500;1.000000;,
  0.562500;1.000000;,
  0.687500;1.000000;,
  0.812500;1.000000;,
  0.937500;1.000000;,
  0.062500;0.000000;,
  0.125000;0.125000;,
  0.000000;0.125000;,
  0.187500;0.000000;,
  0.250000;0.125000;,
  0.312500;0.000000;,
  0.375000;0.125000;,
  0.437500;0.000000;,
  0.500000;0.125000;,
  0.562500;0.000000;,
  0.625000;0.125000;,
  0.687500;0.000000;,
  0.750000;0.125000;,
  0.812500;0.000000;,
  0.875000;0.125000;,
  0.937500;0.000000;,
  1.000000;0.125000;,
  0.125000;0.250000;,
  0.000000;0.250000;,
  0.250000;0.250000;,
  0.375000;0.250000;,
  0.500000;0.250000;,
  0.625000;0.250000;,
  0.750000;0.250000;,
  0.875000;0.250000;,
  1.000000;0.250000;,
  0.125000;0.375000;,
  0.000000;0.375000;,
  0.250000;0.375000;,
  0.375000;0.375000;,
  0.500000;0.375000;,
  0.625000;0.375000;,
  0.750000;0.375000;,
  0.875000;0.375000;,
  1.000000;0.375000;,
  0.125000;0.500000;,
  0.000000;0.500000;,
  0.250000;0.500000;,
  0.375000;0.500000;,
  0.500000;0.500000;,
  0.625000;0.500000;,
  0.750000;0.500000;,
  0.875000;0.500000;,
  1.000000;0.500000;,
  0.125000;0.625000;,
  0.000000;0.625000;,
  0.250000;0.625000;,
  0.375000;0.625000;,
  0.500000;0.625000;,
  0.625000;0.625000;,
  0.750000;0.625000;,
  0.875000;0.625000;,
  1.000000;0.625000;,
  0.125000;0.750000;,
  0.000000;0.750000;,
  0.250000;0.750000;,
  0.375000;0.750000;,
  0.500000;0.750000;,
  0.625000;0.750000;,
  0.750000;0.750000;,
  0.875000;0.750000;,
  1.000000;0.750000;,
  0.125000;0.875000;,
  0.000000;0.875000;,
  0.250000;0.875000;,
  0.375000;0.875000;,
  0.500000;0.875000;,
  0.625000;0.875000;,
  0.750000;0.875000;,
  0.875000;0.875000;,
  1.000000;0.875000;,
  0.062500;1.000000;,
  0.187500;1.000000;,
  0.312500;1.000000;,
  0.437500;1.000000;,
  0.562500;1.000000;,
  0.687500;1.000000;,
  0.812500;1.000000;,
  0.937500;1.000000;;
 }
}