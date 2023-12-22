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
 120;
 -16.70500;17.28250;-4.50000;,
 -5.68479;17.28250;-4.50000;,
 -6.21047;14.08788;-4.50000;,
 -16.70500;10.62905;-4.50000;,
 5.68524;17.28250;-4.50000;,
 6.21093;14.08788;-4.50000;,
 16.70500;17.28250;-4.50000;,
 16.70500;10.62905;-4.50000;,
 -7.58175;11.08129;-4.50000;,
 -16.70500;4.99595;-4.50000;,
 16.70500;4.99595;-4.50000;,
 7.58221;11.08129;-4.50000;,
 -7.98015;0.00000;-4.50000;,
 -16.70500;0.00000;-4.50000;,
 16.70500;0.00000;-4.50000;,
 7.98061;0.00000;-4.50000;,
 16.70500;17.28250;-4.50000;,
 16.70500;16.66186;-2.61960;,
 16.70500;10.84775;-1.55415;,
 16.70500;10.62905;-4.50000;,
 16.70500;16.66186;2.68136;,
 16.70500;10.84775;1.61591;,
 16.70500;17.28250;4.50000;,
 16.70500;10.62905;4.50000;,
 16.70500;4.77725;-1.55415;,
 16.70500;4.99595;-4.50000;,
 16.70500;4.77725;1.61591;,
 16.70500;4.99595;4.50000;,
 16.70500;0.00000;-0.87164;,
 16.70500;0.00000;-4.50000;,
 16.70500;0.00000;0.93340;,
 16.70500;0.00000;4.50000;,
 16.70500;17.28250;4.50000;,
 5.68524;17.28250;4.50000;,
 6.21093;14.08788;4.50000;,
 16.70500;10.62905;4.50000;,
 -5.68479;17.28250;4.50000;,
 -6.21047;14.08788;4.50000;,
 -16.70500;17.28250;4.50000;,
 -16.70500;10.62905;4.50000;,
 7.58221;11.08129;4.50000;,
 16.70500;4.99595;4.50000;,
 -16.70500;4.99595;4.50000;,
 -7.58176;11.08129;4.50000;,
 7.98060;0.00000;4.50000;,
 16.70500;0.00000;4.50000;,
 -16.70500;0.00000;4.50000;,
 -7.98016;0.00000;4.50000;,
 -16.70500;17.28250;4.50000;,
 -16.70500;16.66186;2.68136;,
 -16.70500;10.84775;1.61591;,
 -16.70500;10.62905;4.50000;,
 -16.70500;16.66186;-2.61960;,
 -16.70500;10.84775;-1.55415;,
 -16.70500;17.28250;-4.50000;,
 -16.70500;10.62905;-4.50000;,
 -16.70500;4.77725;1.61591;,
 -16.70500;4.99595;4.50000;,
 -16.70500;4.77725;-1.55415;,
 -16.70500;4.99595;-4.50000;,
 -16.70500;0.00000;0.93340;,
 -16.70500;0.00000;4.50000;,
 -16.70500;0.00000;-0.87164;,
 -16.70500;0.00000;-4.50000;,
 -16.70500;17.28250;4.50000;,
 -5.68479;17.28250;4.50000;,
 -5.90349;17.28250;4.50000;,
 -16.70500;16.66186;2.68136;,
 5.90394;17.28250;4.50000;,
 -5.90349;17.28250;4.50000;,
 5.68524;17.28250;4.50000;,
 16.70500;17.28250;4.50000;,
 16.70500;16.66186;2.68136;,
 5.90394;17.28250;4.50000;,
 -5.90349;17.28250;-4.50000;,
 -16.70500;16.66186;-2.61960;,
 5.90394;17.28250;-4.50000;,
 16.70500;16.66186;-2.61960;,
 -5.68479;17.28250;-4.50000;,
 -16.70500;17.28250;-4.50000;,
 -5.90349;17.28250;-4.50000;,
 5.90394;17.28250;-4.50000;,
 16.70500;17.28250;-4.50000;,
 5.68524;17.28250;-4.50000;,
 -16.70500;0.00000;-4.50000;,
 -7.98015;0.00000;-4.50000;,
 -8.28716;0.00000;-4.50000;,
 -16.70500;0.00000;-0.87164;,
 8.28761;0.00000;-4.50000;,
 -8.28716;0.00000;-4.50000;,
 7.98061;0.00000;-4.50000;,
 16.70500;0.00000;-4.50000;,
 16.70500;0.00000;-0.87164;,
 8.28761;0.00000;-4.50000;,
 -8.28716;0.00000;4.50000;,
 -16.70500;0.00000;0.93340;,
 16.70500;0.00000;0.93340;,
 8.28761;0.00000;4.50000;,
 -7.98016;0.00000;4.50000;,
 -16.70500;0.00000;4.50000;,
 -8.28716;0.00000;4.50000;,
 8.28761;0.00000;4.50000;,
 16.70500;0.00000;4.50000;,
 7.98060;0.00000;4.50000;,
 7.98061;0.00000;-4.50000;,
 7.98060;0.00000;4.50000;,
 7.58221;11.08129;4.50000;,
 7.58221;11.08129;-4.50000;,
 6.21093;14.08788;-4.50000;,
 6.21093;14.08788;4.50000;,
 -6.21047;14.08788;-4.50000;,
 6.21093;14.08788;-4.50000;,
 6.21093;14.08788;4.50000;,
 -6.21047;14.08788;4.50000;,
 -6.21047;14.08788;4.50000;,
 -7.58176;11.08129;4.50000;,
 -7.58175;11.08129;-4.50000;,
 -6.21047;14.08788;-4.50000;,
 -7.98016;0.00000;4.50000;,
 -7.98015;0.00000;-4.50000;;
 
 56;
 4;0,1,2,3;,
 4;1,4,5,2;,
 4;4,6,7,5;,
 4;3,2,8,9;,
 4;5,7,10,11;,
 4;9,8,12,13;,
 4;11,10,14,15;,
 4;16,17,18,19;,
 4;17,20,21,18;,
 4;20,22,23,21;,
 4;19,18,24,25;,
 4;18,21,26,24;,
 4;21,23,27,26;,
 4;25,24,28,29;,
 4;24,26,30,28;,
 4;26,27,31,30;,
 4;32,33,34,35;,
 4;33,36,37,34;,
 4;36,38,39,37;,
 4;35,34,40,41;,
 4;37,39,42,43;,
 4;41,40,44,45;,
 4;43,42,46,47;,
 4;48,49,50,51;,
 4;49,52,53,50;,
 4;52,54,55,53;,
 4;51,50,56,57;,
 4;50,53,58,56;,
 4;53,55,59,58;,
 4;57,56,60,61;,
 4;56,58,62,60;,
 4;58,59,63,62;,
 4;64,65,66,67;,
 4;36,33,68,69;,
 4;70,71,72,73;,
 4;67,66,74,75;,
 4;66,73,76,74;,
 4;73,72,77,76;,
 4;75,74,78,79;,
 4;80,81,4,1;,
 4;76,77,82,83;,
 4;84,85,86,87;,
 4;12,15,88,89;,
 4;90,91,92,93;,
 4;87,86,94,95;,
 4;93,92,96,97;,
 4;95,94,98,99;,
 4;100,101,44,47;,
 4;97,96,102,103;,
 4;104,105,106,107;,
 4;97,103,90,93;,
 4;108,107,106,109;,
 4;110,111,112,113;,
 4;114,115,116,117;,
 4;115,118,119,116;,
 4;98,94,86,85;;
 
 MeshMaterialList {
  4;
  56;
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
  3,
  0,
  3,
  3,
  3,
  3,
  3,
  0,
  3,
  2,
  0,
  2,
  2,
  2,
  2,
  0,
  2,
  1,
  2,
  1,
  2,
  1,
  1,
  2;;
  Material {
   0.800000;0.800000;0.800000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
   TextureFilename {
    "texture\\sandstonebricks.png";
   }
  }
  Material {
   0.800000;0.800000;0.800000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
   TextureFilename {
    "texture\\sandstonebricks.png";
   }
  }
  Material {
   0.800000;0.800000;0.800000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
   TextureFilename {
    "texture\\sandstonebricks.png";
   }
  }
  Material {
   0.800000;0.800000;0.800000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
   TextureFilename {
    "texture\\sandstone.png";
   }
  }
 }
 MeshNormals {
  23;
  0.000000;0.000000;-1.000000;,
  1.000000;0.000000;0.000000;,
  0.000000;0.000000;1.000000;,
  -1.000000;0.000000;0.000000;,
  -0.019360;0.993853;-0.109004;,
  0.000000;0.000000;0.000000;,
  -0.019346;0.994209;0.105703;,
  0.019347;0.994209;0.105703;,
  0.000000;-1.000000;-0.000000;,
  0.000000;0.946407;-0.322975;,
  -0.029086;0.986071;-0.163761;,
  0.029087;0.986071;-0.163761;,
  0.019361;0.993853;-0.109004;,
  -0.029062;0.986885;0.158788;,
  0.029063;0.986885;0.158788;,
  0.000000;0.949613;0.313425;,
  0.000000;0.949613;0.313425;,
  -0.999354;-0.035929;-0.000001;,
  -0.973226;-0.229850;-0.000000;,
  -0.909835;-0.414970;0.000000;,
  0.909836;-0.414969;0.000001;,
  0.973226;-0.229849;0.000001;,
  0.999354;-0.035929;0.000001;;
  56;
  4;0,0,0,0;,
  4;0,0,0,0;,
  4;0,0,0,0;,
  4;0,0,0,0;,
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
  4;2,2,2,2;,
  4;2,2,2,2;,
  4;2,2,2,2;,
  4;2,2,2,2;,
  4;3,3,3,3;,
  4;3,3,3,3;,
  4;3,3,3,3;,
  4;3,3,3,3;,
  4;3,3,3,3;,
  4;3,3,3,3;,
  4;3,3,3,3;,
  4;3,3,3,3;,
  4;3,3,3,3;,
  4;9,9,4,10;,
  4;5,5,5,5;,
  4;9,9,11,12;,
  4;10,4,6,13;,
  4;4,12,7,6;,
  4;12,11,14,7;,
  4;13,6,15,15;,
  4;5,5,5,5;,
  4;7,14,16,16;,
  4;8,8,8,8;,
  4;5,5,5,5;,
  4;8,8,8,8;,
  4;8,8,8,8;,
  4;8,8,8,8;,
  4;8,8,8,8;,
  4;5,5,5,5;,
  4;8,8,8,8;,
  4;17,17,18,18;,
  4;8,8,8,8;,
  4;19,18,18,19;,
  4;8,8,8,8;,
  4;20,21,21,20;,
  4;21,22,22,21;,
  4;8,8,8,8;;
 }
 MeshTextureCoords {
  120;
  -2.310161;-1.500058;,
  -0.456310;-1.500058;,
  -0.544743;-1.130352;,
  -2.310161;-0.730072;,
  1.456386;-1.500058;,
  1.544819;-1.130352;,
  3.310161;-1.500058;,
  3.310161;-0.730072;,
  -0.775423;-0.782408;,
  -2.310161;-0.078168;,
  3.310161;-0.078168;,
  1.775500;-0.782408;,
  -0.842443;0.500000;,
  -2.310161;0.500000;,
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
  -0.456310;-1.500058;,
  -0.544743;-1.130352;,
  -2.310161;-1.500058;,
  -2.310161;-0.730072;,
  1.775500;-0.782408;,
  3.310161;-0.078168;,
  -2.310161;-0.078168;,
  -0.775425;-0.782408;,
  1.842518;0.500000;,
  3.310161;0.500000;,
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
  -2.307560;1.020230;,
  -0.455430;1.020230;,
  -0.492180;1.020230;,
  -2.307560;0.607910;,
  1.493176;-1.500058;,
  -0.493101;-1.500058;,
  1.455500;1.020230;,
  3.307560;1.020230;,
  3.307560;0.607910;,
  1.492260;1.020230;,
  -0.492180;-0.020230;,
  -2.307560;0.399230;,
  1.492260;-0.020230;,
  3.307560;0.399230;,
  -0.455430;-0.020230;,
  -2.307560;-0.020230;,
  -0.493101;-1.500058;,
  1.493176;-1.500058;,
  3.307560;-0.020230;,
  1.455500;-0.020230;,
  -2.307563;-0.020231;,
  -0.841202;-0.020231;,
  -0.892800;-0.020231;,
  -2.307563;0.399233;,
  1.894165;0.500000;,
  -0.894089;0.500000;,
  1.841279;-0.020231;,
  3.307563;-0.020231;,
  3.307563;0.399233;,
  1.892876;-0.020231;,
  -0.892800;1.020231;,
  -2.307563;0.607908;,
  3.307563;0.607908;,
  1.892876;1.020231;,
  -0.841204;1.020231;,
  -2.307563;1.020231;,
  -0.894089;0.500000;,
  1.894165;0.500000;,
  3.307563;1.020231;,
  1.841277;1.020231;,
  -0.256303;0.500000;,
  1.256303;0.500000;,
  1.256303;-0.781074;,
  -0.256303;-0.781074;,
  -0.256303;-1.128656;,
  1.256303;-1.128656;,
  -0.543777;-0.020231;,
  1.543853;-0.020231;,
  1.543853;1.020231;,
  -0.543777;1.020231;,
  1.256303;-1.128656;,
  1.256303;-0.781074;,
  -0.256303;-0.781074;,
  -0.256303;-1.128656;,
  1.256303;0.500000;,
  -0.256303;0.500000;;
 }
}
