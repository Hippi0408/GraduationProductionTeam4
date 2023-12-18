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
 152;
 13.64457;41.47800;-10.80000;,
 40.09200;41.47800;-10.80000;,
 40.09200;25.50972;-10.80000;,
 14.90622;33.81090;-10.80000;,
 40.09200;11.99028;-10.80000;,
 18.19731;26.59509;-10.80000;,
 40.09200;0.00000;-10.80000;,
 19.15347;0.00000;-10.80000;,
 40.09200;41.47800;-10.80000;,
 40.09200;39.98847;-6.28704;,
 40.09200;26.03460;-3.72996;,
 40.09200;25.50972;-10.80000;,
 40.09200;39.98847;6.43527;,
 40.09200;26.03460;3.87819;,
 40.09200;41.47800;10.80000;,
 40.09200;25.50972;10.80000;,
 40.09200;11.46540;-3.72996;,
 40.09200;11.99028;-10.80000;,
 40.09200;11.46540;3.87819;,
 40.09200;11.99028;10.80000;,
 40.09200;0.00000;-2.09193;,
 40.09200;0.00000;-10.80000;,
 40.09200;0.00000;2.24016;,
 40.09200;0.00000;10.80000;,
 40.09200;41.47800;10.80000;,
 13.64457;41.47800;10.80000;,
 14.90622;33.81090;10.80000;,
 40.09200;25.50972;10.80000;,
 18.19731;26.59509;10.80000;,
 40.09200;11.99028;10.80000;,
 19.15344;0.00000;10.80000;,
 40.09200;0.00000;10.80000;,
 13.64457;41.47800;10.80000;,
 40.09200;39.98847;6.43527;,
 40.09200;39.98847;-6.28704;,
 13.64457;41.47800;-10.80000;,
 19.15347;0.00000;-10.80000;,
 40.09200;0.00000;-10.80000;,
 40.09200;0.00000;-2.09193;,
 19.89027;0.00000;-10.80000;,
 40.09200;0.00000;2.24016;,
 19.89027;0.00000;10.80000;,
 40.09200;0.00000;10.80000;,
 19.15344;0.00000;10.80000;,
 19.15347;0.00000;-10.80000;,
 19.15344;0.00000;10.80000;,
 18.19731;26.59509;10.80000;,
 18.19731;26.59509;-10.80000;,
 14.90622;33.81090;-10.80000;,
 14.90622;33.81090;10.80000;,
 13.64457;41.47800;-10.80000;,
 40.09200;41.47800;-10.80000;,
 13.64457;41.47800;10.80000;,
 40.09200;41.47800;10.80000;,
 13.64457;41.47800;10.80000;,
 13.64457;41.47800;-10.80000;,
 14.90622;33.81090;-10.80000;,
 14.90622;33.81090;10.80000;,
 -13.64349;41.47800;-10.80000;,
 13.64457;41.47800;-10.80000;,
 14.90622;33.81090;-10.80000;,
 -14.90514;33.81090;-10.80000;,
 13.64457;41.47800;10.80000;,
 -13.64349;41.47800;10.80000;,
 -14.90514;33.81090;10.80000;,
 14.90622;33.81090;10.80000;,
 14.16945;41.47800;10.80000;,
 -14.16837;41.47800;10.80000;,
 -14.16837;41.47800;10.80000;,
 14.16945;41.47800;10.80000;,
 14.16945;41.47800;-10.80000;,
 -14.16837;41.47800;-10.80000;,
 -14.16837;41.47800;-10.80000;,
 14.16945;41.47800;-10.80000;,
 -14.90514;33.81090;-10.80000;,
 14.90622;33.81090;-10.80000;,
 14.90622;33.81090;10.80000;,
 -14.90514;33.81090;10.80000;,
 13.64457;41.47800;-10.80000;,
 14.16945;41.47800;-10.80000;,
 14.90622;33.81090;-10.80000;,
 14.90622;33.81090;10.80000;,
 14.16945;41.47800;10.80000;,
 13.64457;41.47800;10.80000;,
 14.90622;33.81090;10.80000;,
 14.90622;33.81090;-10.80000;,
 -13.64349;41.47800;10.80000;,
 -14.16837;41.47800;10.80000;,
 -14.90514;33.81090;10.80000;,
 -14.90514;33.81090;-10.80000;,
 -14.16837;41.47800;-10.80000;,
 -13.64349;41.47800;-10.80000;,
 -14.90514;33.81090;-10.80000;,
 -14.90514;33.81090;10.80000;,
 -40.09200;41.47800;-10.80000;,
 -14.16837;41.47800;-10.80000;,
 -14.90514;33.81090;-10.80000;,
 -40.09200;25.50972;-10.80000;,
 -18.19620;26.59509;-10.80000;,
 -40.09200;11.99028;-10.80000;,
 -19.15236;0.00000;-10.80000;,
 -40.09200;0.00000;-10.80000;,
 -14.16837;41.47800;10.80000;,
 -40.09200;41.47800;10.80000;,
 -40.09200;25.50972;10.80000;,
 -14.90514;33.81090;10.80000;,
 -40.09200;11.99028;10.80000;,
 -18.19623;26.59509;10.80000;,
 -40.09200;0.00000;10.80000;,
 -19.15239;0.00000;10.80000;,
 -40.09200;41.47800;10.80000;,
 -40.09200;39.98847;6.43527;,
 -40.09200;26.03460;3.87819;,
 -40.09200;25.50972;10.80000;,
 -40.09200;39.98847;-6.28704;,
 -40.09200;26.03460;-3.72996;,
 -40.09200;41.47800;-10.80000;,
 -40.09200;25.50972;-10.80000;,
 -40.09200;11.46540;3.87819;,
 -40.09200;11.99028;10.80000;,
 -40.09200;11.46540;-3.72996;,
 -40.09200;11.99028;-10.80000;,
 -40.09200;0.00000;2.24016;,
 -40.09200;0.00000;10.80000;,
 -40.09200;0.00000;-2.09193;,
 -40.09200;0.00000;-10.80000;,
 -40.09200;39.98847;6.43527;,
 -14.16837;41.47800;10.80000;,
 -14.16837;41.47800;-10.80000;,
 -40.09200;39.98847;-6.28704;,
 -40.09200;0.00000;-10.80000;,
 -19.15236;0.00000;-10.80000;,
 -19.88919;0.00000;-10.80000;,
 -40.09200;0.00000;-2.09193;,
 -19.88919;0.00000;10.80000;,
 -40.09200;0.00000;2.24016;,
 -19.15239;0.00000;10.80000;,
 -40.09200;0.00000;10.80000;,
 -14.90514;33.81090;10.80000;,
 -18.19623;26.59509;10.80000;,
 -18.19620;26.59509;-10.80000;,
 -14.90514;33.81090;-10.80000;,
 -19.15239;0.00000;10.80000;,
 -19.15236;0.00000;-10.80000;,
 -14.16837;41.47800;-10.80000;,
 -40.09200;41.47800;-10.80000;,
 -14.16837;41.47800;10.80000;,
 -40.09200;41.47800;10.80000;,
 -14.16837;41.47800;10.80000;,
 -14.90514;33.81090;10.80000;,
 -14.90514;33.81090;-10.80000;,
 -14.16837;41.47800;-10.80000;;
 
 62;
 4;0,1,2,3;,
 4;3,2,4,5;,
 4;5,4,6,7;,
 4;8,9,10,11;,
 4;9,12,13,10;,
 4;12,14,15,13;,
 4;11,10,16,17;,
 4;10,13,18,16;,
 4;13,15,19,18;,
 4;17,16,20,21;,
 4;16,18,22,20;,
 4;18,19,23,22;,
 4;24,25,26,27;,
 4;27,26,28,29;,
 4;29,28,30,31;,
 4;32,33,34,35;,
 4;36,37,38,39;,
 4;39,38,40,41;,
 4;41,40,42,43;,
 4;44,45,46,47;,
 4;41,43,36,39;,
 4;48,47,46,49;,
 3;50,34,51;,
 3;52,53,33;,
 4;54,55,56,57;,
 4;58,59,60,61;,
 4;62,63,64,65;,
 4;63,62,66,67;,
 4;68,69,70,71;,
 4;72,73,59,58;,
 4;74,75,76,77;,
 3;78,79,80;,
 3;81,82,83;,
 4;70,69,84,85;,
 3;86,87,88;,
 3;89,90,91;,
 4;68,71,92,93;,
 4;94,95,96,97;,
 4;97,96,98,99;,
 4;99,98,100,101;,
 4;102,103,104,105;,
 4;105,104,106,107;,
 4;107,106,108,109;,
 4;110,111,112,113;,
 4;111,114,115,112;,
 4;114,116,117,115;,
 4;113,112,118,119;,
 4;112,115,120,118;,
 4;115,117,121,120;,
 4;119,118,122,123;,
 4;118,120,124,122;,
 4;120,121,125,124;,
 4;126,127,128,129;,
 4;130,131,132,133;,
 4;133,132,134,135;,
 4;135,134,136,137;,
 4;138,139,140,141;,
 4;139,142,143,140;,
 4;136,134,132,131;,
 3;144,145,129;,
 3;146,126,147;,
 4;148,149,150,151;;
 
 MeshMaterialList {
  5;
  62;
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
  0,
  0,
  0,
  3,
  2,
  2,
  2,
  1,
  2,
  1,
  3,
  3,
  4,
  0,
  0,
  0,
  3,
  0,
  2,
  1,
  1,
  4,
  1,
  1,
  4,
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
  3,
  2,
  2,
  2,
  1,
  1,
  2,
  3,
  3,
  4;;
  Material {
   0.800000;0.800000;0.800000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
   TextureFilename {
    "Data\\texture\\building\\sandstonebricks.png";
   }
  }
  Material {
   0.800000;0.800000;0.800000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
   TextureFilename {
    "Data\\texture\\building\\sandstonebricks.png";
   }
  }
  Material {
   0.800000;0.800000;0.800000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
   TextureFilename {
    "Data\\texture\\building\\sandstonebricks.png";
   }
  }
  Material {
   0.800000;0.800000;0.800000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
   TextureFilename {
    "Data\\texture\\building\\sandstone.png";
   }
  }
  Material {
   0.800000;0.800000;0.800000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
   TextureFilename {
    "Data\\texture\\building\\sandstone.png";
   }
  }
 }
 MeshNormals {
  31;
  0.000000;0.000000;-1.000000;,
  1.000000;0.000000;0.000000;,
  0.000000;0.000000;1.000000;,
  0.000000;-1.000000;-0.000000;,
  0.028511;0.986088;-0.163759;,
  0.028488;0.986902;0.158786;,
  -0.999354;-0.035929;-0.000001;,
  -0.973226;-0.229850;-0.000000;,
  -0.956656;-0.291219;0.000000;,
  0.000000;0.949613;0.313425;,
  0.000000;0.946407;-0.322975;,
  -0.986730;-0.162370;0.000000;,
  0.000000;0.000000;-1.000000;,
  0.000000;0.000000;1.000000;,
  0.000000;0.000000;0.000000;,
  0.000000;1.000000;0.000000;,
  0.000000;-1.000000;-0.000000;,
  0.995415;0.095654;0.000000;,
  -0.995415;0.095654;0.000000;,
  0.000000;0.000000;-1.000000;,
  0.000000;0.000000;1.000000;,
  -1.000000;0.000000;0.000000;,
  0.000000;-1.000000;-0.000000;,
  -0.029086;0.986071;-0.163761;,
  -0.029062;0.986885;0.158788;,
  0.965912;-0.258872;0.000000;,
  0.973226;-0.229849;0.000001;,
  0.999354;-0.035929;0.000001;,
  0.000000;0.949613;0.313425;,
  0.000000;0.946407;-0.322975;,
  0.995415;-0.095654;-0.000000;;
  62;
  4;0,0,0,0;,
  4;0,0,0,0;,
  4;0,0,0,0;,
  4;1,1,1,1;,
  4;1,1,1,1;,
  4;1,1,1,1;,
  4;1,1,1,1;,
  4;1,1,1,1;,
  4;1,1,1,1;,
  4;1,1,1,1;,
  4;1,1,1,1;,
  4;1,1,1,1;,
  4;2,2,2,2;,
  4;2,2,2,2;,
  4;2,2,2,2;,
  4;4,4,5,5;,
  4;3,3,3,3;,
  4;3,3,3,3;,
  4;3,3,3,3;,
  4;6,6,7,7;,
  4;3,3,3,3;,
  4;8,7,7,8;,
  3;5,5,9;,
  3;4,10,4;,
  4;11,11,8,8;,
  4;12,12,12,12;,
  4;13,13,13,13;,
  4;14,14,14,14;,
  4;15,15,15,15;,
  4;14,14,14,14;,
  4;16,16,16,16;,
  3;12,12,12;,
  3;13,13,13;,
  4;17,17,17,17;,
  3;13,13,13;,
  3;12,12,12;,
  4;18,18,18,18;,
  4;19,19,19,19;,
  4;19,19,19,19;,
  4;19,19,19,19;,
  4;20,20,20,20;,
  4;20,20,20,20;,
  4;20,20,20,20;,
  4;21,21,21,21;,
  4;21,21,21,21;,
  4;21,21,21,21;,
  4;21,21,21,21;,
  4;21,21,21,21;,
  4;21,21,21,21;,
  4;21,21,21,21;,
  4;21,21,21,21;,
  4;21,21,21,21;,
  4;23,23,24,24;,
  4;22,22,22,22;,
  4;22,22,22,22;,
  4;22,22,22,22;,
  4;25,26,26,25;,
  4;26,27,27,26;,
  4;22,22,22,22;,
  3;24,28,24;,
  3;23,23,29;,
  4;30,25,25,30;;
 }
 MeshTextureCoords {
  152;
  1.456386;-1.500058;,
  3.310161;-1.500058;,
  3.310161;-0.730072;,
  1.544819;-1.130352;,
  3.310161;-0.078168;,
  1.775500;-0.782408;,
  3.310161;0.500000;,
  1.842520;0.500000;,
  -0.256303;-1.497977;,
  0.059731;-1.426227;,
  0.238798;-0.754075;,
  -0.256303;-0.728792;,
  0.950649;-1.426227;,
  0.771582;-0.754075;,
  1.256303;-1.497977;,
  1.256303;-0.728792;,
  0.238798;-0.052283;,
  -0.256303;-0.077567;,
  0.771582;-0.052283;,
  1.256303;-0.077567;,
  0.353506;0.500000;,
  -0.256303;0.500000;,
  0.656874;0.500000;,
  1.256303;0.500000;,
  3.310161;-1.500058;,
  1.456386;-1.500058;,
  1.544819;-1.130352;,
  3.310161;-0.730072;,
  1.775500;-0.782408;,
  3.310161;-0.078168;,
  1.842518;0.500000;,
  3.310161;0.500000;,
  1.492260;1.020230;,
  3.307560;0.607910;,
  3.307560;0.399230;,
  1.492260;-0.020230;,
  1.841279;-0.020231;,
  3.307563;-0.020231;,
  3.307563;0.399233;,
  1.892876;-0.020231;,
  3.307563;0.607908;,
  1.892876;1.020231;,
  3.307563;1.020231;,
  1.841277;1.020231;,
  -0.256303;0.500000;,
  1.256303;0.500000;,
  1.256303;-0.781074;,
  -0.256303;-0.781074;,
  -0.256303;-1.128656;,
  1.256303;-1.128656;,
  1.473880;-0.020230;,
  3.307560;-0.020230;,
  1.473880;1.020230;,
  3.307560;1.020230;,
  1.256300;-1.497980;,
  -0.256300;-1.497980;,
  -0.256300;-1.128660;,
  1.256300;-1.128660;,
  -0.456310;-1.500058;,
  1.456386;-1.500058;,
  1.544819;-1.130352;,
  -0.544743;-1.130352;,
  1.456386;-1.500058;,
  -0.456310;-1.500058;,
  -0.544743;-1.130352;,
  1.544819;-1.130352;,
  1.493176;-1.500058;,
  -0.493101;-1.500058;,
  -0.492180;1.020230;,
  1.492260;1.020230;,
  1.492260;-0.020230;,
  -0.492180;-0.020230;,
  -0.493101;-1.500058;,
  1.493176;-1.500058;,
  -0.543777;-0.020231;,
  1.543853;-0.020231;,
  1.543853;1.020231;,
  -0.543777;1.020231;,
  -0.256303;-1.497977;,
  -0.256303;-1.497977;,
  -0.256303;-1.128656;,
  1.256303;-1.128656;,
  1.256303;-1.497977;,
  1.256303;-1.497977;,
  1.544820;-1.130350;,
  1.544820;-1.130350;,
  1.256303;-1.497977;,
  1.256303;-1.497977;,
  1.256303;-1.128656;,
  -0.256303;-1.128656;,
  -0.256303;-1.497977;,
  -0.256303;-1.497977;,
  -0.544740;-1.130350;,
  -0.544740;-1.130350;,
  -2.310161;-1.500058;,
  -0.493101;-1.500058;,
  -0.544743;-1.130352;,
  -2.310161;-0.730072;,
  -0.775423;-0.782408;,
  -2.310161;-0.078168;,
  -0.842443;0.500000;,
  -2.310161;0.500000;,
  -0.493101;-1.500058;,
  -2.310161;-1.500058;,
  -2.310161;-0.730072;,
  -0.544743;-1.130352;,
  -2.310161;-0.078168;,
  -0.775425;-0.782408;,
  -2.310161;0.500000;,
  -0.842445;0.500000;,
  1.256303;-1.497977;,
  0.950649;-1.426227;,
  0.771582;-0.754075;,
  1.256303;-0.728792;,
  0.059731;-1.426227;,
  0.238798;-0.754075;,
  -0.256303;-1.497977;,
  -0.256303;-0.728792;,
  0.771582;-0.052283;,
  1.256303;-0.077567;,
  0.238798;-0.052283;,
  -0.256303;-0.077567;,
  0.656874;0.500000;,
  1.256303;0.500000;,
  0.353506;0.500000;,
  -0.256303;0.500000;,
  -2.307560;0.607910;,
  -0.492180;1.020230;,
  -0.492180;-0.020230;,
  -2.307560;0.399230;,
  -2.307563;-0.020231;,
  -0.841202;-0.020231;,
  -0.892800;-0.020231;,
  -2.307563;0.399233;,
  -0.892800;1.020231;,
  -2.307563;0.607908;,
  -0.841204;1.020231;,
  -2.307563;1.020231;,
  1.256303;-1.128656;,
  1.256303;-0.781074;,
  -0.256303;-0.781074;,
  -0.256303;-1.128656;,
  1.256303;0.500000;,
  -0.256303;0.500000;,
  -0.473810;-0.020230;,
  -2.307560;-0.020230;,
  -0.473810;1.020230;,
  -2.307560;1.020230;,
  -0.493100;-1.500060;,
  1.256300;-1.128660;,
  -0.256300;-1.128660;,
  -0.493100;-1.500060;;
 }
}
