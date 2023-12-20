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
 148;
 -12.00000;21.92442;-12.00000;,
 -1.01968;21.92442;-12.00000;,
 7.35176;0.00000;-12.00000;,
 -12.00000;0.00000;-12.00000;,
 -1.01968;21.92442;-12.00000;,
 -1.01968;21.92442;12.00000;,
 7.35176;0.00000;12.00000;,
 7.35176;0.00000;-12.00000;,
 -1.01968;21.92442;12.00000;,
 -12.00000;21.92442;12.00000;,
 -12.00000;0.00000;12.00000;,
 7.35176;0.00000;12.00000;,
 -12.00000;21.92442;12.00000;,
 -12.00000;21.92442;-12.00000;,
 -12.00000;0.00000;-12.00000;,
 -12.00000;0.00000;12.00000;,
 -12.00000;21.92442;12.00000;,
 -1.01968;21.92442;12.00000;,
 -1.01968;21.92442;-12.00000;,
 -12.00000;21.92442;-12.00000;,
 -12.00000;0.00000;-12.00000;,
 7.35176;0.00000;-12.00000;,
 7.35176;0.00000;12.00000;,
 -12.00000;0.00000;12.00000;,
 -8.58216;8.12400;-12.08992;,
 -2.58216;8.12400;-12.08992;,
 -2.58216;0.12400;-12.08992;,
 -8.58216;0.12400;-12.08992;,
 -2.58216;8.12400;-12.08992;,
 -2.58216;8.12400;-8.08992;,
 -2.58216;0.12400;-8.08992;,
 -2.58216;0.12400;-12.08992;,
 -2.58216;8.12400;-8.08992;,
 -8.58216;8.12400;-8.08992;,
 -8.58216;0.12400;-8.08992;,
 -2.58216;0.12400;-8.08992;,
 -8.58216;8.12400;-8.08992;,
 -8.58216;8.12400;-12.08992;,
 -8.58216;0.12400;-12.08992;,
 -8.58216;0.12400;-8.08992;,
 -2.58216;8.12400;-12.08992;,
 -8.58216;8.12400;-12.08992;,
 -8.58216;0.12400;-12.08992;,
 -2.58216;0.12400;-12.08992;,
 -1.01968;21.92442;-12.00000;,
 12.00000;21.92442;-12.00000;,
 12.00000;0.00000;-12.00000;,
 7.35176;0.00000;-12.00000;,
 12.00000;21.92442;-12.00000;,
 12.00000;21.92442;12.00000;,
 12.00000;0.00000;12.00000;,
 12.00000;0.00000;-12.00000;,
 12.00000;21.92442;12.00000;,
 -1.01968;21.92442;12.00000;,
 7.35176;0.00000;12.00000;,
 12.00000;0.00000;12.00000;,
 -1.01968;21.92442;12.00000;,
 -1.01968;21.92442;-12.00000;,
 7.35176;0.00000;-12.00000;,
 7.35176;0.00000;12.00000;,
 -1.01968;21.92442;12.00000;,
 12.00000;21.92442;12.00000;,
 12.00000;21.92442;-12.00000;,
 -1.01968;21.92442;-12.00000;,
 7.35176;0.00000;-12.00000;,
 12.00000;0.00000;-12.00000;,
 12.00000;0.00000;12.00000;,
 7.35176;0.00000;12.00000;,
 -2.55386;15.00000;-10.50000;,
 10.50000;15.00000;-10.50000;,
 14.00000;11.00000;-14.00000;,
 1.47920;11.00000;-14.00000;,
 10.50000;15.00000;-10.50000;,
 10.50000;15.00000;10.50000;,
 14.00000;11.00000;14.00000;,
 14.00000;11.00000;-14.00000;,
 10.50000;15.00000;10.50000;,
 -3.97546;15.00000;10.50000;,
 0.00000;11.00000;14.00000;,
 14.00000;11.00000;14.00000;,
 -3.97546;15.00000;10.50000;,
 -2.55386;15.00000;-10.50000;,
 1.47920;11.00000;-14.00000;,
 0.00000;11.00000;14.00000;,
 10.50000;15.00000;-10.50000;,
 -2.55386;15.00000;-10.50000;,
 1.47920;11.00000;-14.00000;,
 14.00000;11.00000;-14.00000;,
 0.00000;34.04468;-14.00000;,
 0.00000;32.04468;-14.00000;,
 -12.00000;21.04468;-14.00000;,
 -14.00000;21.04468;-14.00000;,
 0.00000;32.04468;14.00000;,
 -12.00000;21.04468;14.00000;,
 0.00000;34.04468;14.00000;,
 -14.00000;21.04468;14.00000;,
 0.00000;34.04468;-14.00000;,
 14.00000;21.04468;-14.00000;,
 12.00000;21.04468;-14.00000;,
 0.00000;32.04468;-14.00000;,
 12.00000;21.04468;14.00000;,
 0.00000;32.04468;14.00000;,
 14.00000;21.04468;14.00000;,
 0.00000;34.04468;14.00000;,
 0.00000;32.46394;-12.00000;,
 0.00000;32.46394;-12.00000;,
 12.00000;21.40450;-12.00000;,
 -12.00000;21.40450;-12.00000;,
 0.00000;32.46394;-12.00000;,
 0.00000;32.46394;12.00000;,
 12.00000;21.40450;12.00000;,
 12.00000;21.40450;-12.00000;,
 0.00000;32.46394;12.00000;,
 0.00000;32.46394;12.00000;,
 -12.00000;21.40450;12.00000;,
 12.00000;21.40450;12.00000;,
 0.00000;32.46394;12.00000;,
 0.00000;32.46394;-12.00000;,
 -12.00000;21.40450;-12.00000;,
 -12.00000;21.40450;12.00000;,
 0.00000;32.46394;12.00000;,
 0.00000;32.46394;12.00000;,
 0.00000;32.46394;-12.00000;,
 0.00000;32.46394;-12.00000;,
 -12.00000;21.40450;-12.00000;,
 12.00000;21.40450;-12.00000;,
 12.00000;21.40450;12.00000;,
 -12.00000;21.40450;12.00000;,
 -10.50000;15.00000;-10.50000;,
 -2.55386;15.00000;-10.50000;,
 1.47920;11.00000;-14.00000;,
 -14.00000;11.00000;-14.00000;,
 -2.55386;15.00000;-10.50000;,
 -3.97546;15.00000;10.50000;,
 0.00000;11.00000;14.00000;,
 1.47920;11.00000;-14.00000;,
 -3.97546;15.00000;10.50000;,
 -10.50000;15.00000;10.50000;,
 -14.00000;11.00000;14.00000;,
 0.00000;11.00000;14.00000;,
 -10.50000;15.00000;10.50000;,
 -10.50000;15.00000;-10.50000;,
 -14.00000;11.00000;-14.00000;,
 -14.00000;11.00000;14.00000;,
 -2.55386;15.00000;-10.50000;,
 -10.50000;15.00000;-10.50000;,
 -14.00000;11.00000;-14.00000;,
 1.47920;11.00000;-14.00000;;
 
 48;
 4;0,1,2,3;,
 4;4,5,6,7;,
 4;8,9,10,11;,
 4;12,13,14,15;,
 4;16,17,18,19;,
 4;20,21,22,23;,
 4;24,25,26,27;,
 4;28,29,30,31;,
 4;32,33,34,35;,
 4;36,37,38,39;,
 4;36,29,40,41;,
 4;42,43,30,39;,
 4;44,45,46,47;,
 4;48,49,50,51;,
 4;52,53,54,55;,
 4;56,57,58,59;,
 4;60,61,62,63;,
 4;64,65,66,67;,
 4;68,69,70,71;,
 4;72,73,74,75;,
 4;76,77,78,79;,
 4;80,81,82,83;,
 4;80,73,84,85;,
 4;86,87,74,83;,
 4;88,89,90,91;,
 4;89,92,93,90;,
 4;92,94,95,93;,
 4;94,88,91,95;,
 4;94,92,89,88;,
 4;91,90,93,95;,
 4;96,97,98,99;,
 4;99,98,100,101;,
 4;101,100,102,103;,
 4;103,102,97,96;,
 4;103,96,99,101;,
 4;97,102,100,98;,
 4;104,105,106,107;,
 4;108,109,110,111;,
 4;112,113,114,115;,
 4;116,117,118,119;,
 4;120,121,122,123;,
 4;124,125,126,127;,
 4;128,129,130,131;,
 4;132,133,134,135;,
 4;136,137,138,139;,
 4;140,141,142,143;,
 4;140,133,144,145;,
 4;146,147,134,143;;
 
 MeshMaterialList {
  8;
  48;
  0,
  1,
  0,
  1,
  6,
  6,
  5,
  5,
  5,
  5,
  5,
  5,
  0,
  1,
  0,
  1,
  6,
  6,
  2,
  2,
  2,
  5,
  2,
  5,
  3,
  3,
  3,
  3,
  3,
  3,
  4,
  4,
  4,
  4,
  4,
  4,
  0,
  1,
  0,
  1,
  7,
  6,
  2,
  5,
  2,
  2,
  2,
  5;;
  Material {
   0.800000;0.800000;0.800000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
   TextureFilename {
    "Data\\texture\\building\\ConvenienceStoreWall.png";
   }
  }
  Material {
   0.800000;0.800000;0.800000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
   TextureFilename {
    "Data\\texture\\building\\ConvenienceStoreWall.png";
   }
  }
  Material {
   0.279200;0.251200;0.272800;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
   TextureFilename {
    "Data\\texture\\building\\House.png";
   }
  }
  Material {
   0.241600;0.216800;0.235200;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
   TextureFilename {
    "Data\\texture\\building\\House.png";
   }
  }
  Material {
   0.241600;0.216800;0.235200;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
   TextureFilename {
    "Data\\texture\\building\\House.png";
   }
  }
  Material {
   0.000000;0.000000;0.000000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.460800;0.448800;0.448800;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
   TextureFilename {
    "Data\\texture\\building\\Palm.png";
   }
  }
  Material {
   1.000000;1.000000;1.000000;1.000000;;
   0.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
 }
 MeshNormals {
  47;
  0.000000;0.000000;-1.000000;,
  0.934214;0.356713;0.000000;,
  0.000000;0.000000;1.000000;,
  1.000000;0.000000;0.000000;,
  -1.000000;0.000000;0.000000;,
  0.000000;1.000000;0.000000;,
  0.000000;-1.000000;-0.000000;,
  0.000000;0.000000;-1.000000;,
  1.000000;0.000000;0.000000;,
  0.000000;0.000000;1.000000;,
  -0.934214;-0.356713;0.000000;,
  0.000000;1.000000;0.000000;,
  0.000000;-1.000000;-0.000000;,
  0.000000;0.910633;-0.413216;,
  0.000000;0.658505;-0.752577;,
  0.413216;0.910633;0.000000;,
  0.752577;0.658505;0.000000;,
  0.000000;0.910633;0.413216;,
  0.000000;0.658505;0.752577;,
  -0.704172;-0.708767;-0.042315;,
  -0.380910;-0.924329;-0.022889;,
  0.000000;-1.000000;-0.000000;,
  0.000000;0.000000;-1.000000;,
  0.915348;-0.402663;-0.000000;,
  0.362523;-0.931975;-0.000000;,
  0.000000;0.000000;1.000000;,
  -0.362523;-0.931975;0.000000;,
  -0.916638;0.399718;0.000000;,
  -0.680451;0.732793;0.000000;,
  0.916638;0.399718;0.000000;,
  0.000000;-1.000000;-0.000000;,
  -0.915348;-0.402663;0.000000;,
  0.680451;0.732793;0.000000;,
  0.000000;0.000000;-1.000000;,
  0.677701;0.735337;0.000000;,
  0.000000;0.000000;1.000000;,
  -0.677701;0.735337;0.000000;,
  0.000000;0.000000;0.000000;,
  0.000000;-1.000000;-0.000000;,
  0.000000;0.910633;-0.413216;,
  0.000000;0.658505;-0.752577;,
  0.380910;0.924329;0.022889;,
  0.704172;0.708767;0.042315;,
  0.000000;0.910633;0.413216;,
  0.000000;0.658505;0.752577;,
  -0.752577;0.658505;0.000000;,
  0.000000;-1.000000;-0.000000;;
  48;
  4;0,0,0,0;,
  4;1,1,1,1;,
  4;2,2,2,2;,
  4;4,4,4,4;,
  4;5,5,5,5;,
  4;6,6,6,6;,
  4;0,0,0,0;,
  4;3,3,3,3;,
  4;2,2,2,2;,
  4;4,4,4,4;,
  4;5,5,5,5;,
  4;6,6,6,6;,
  4;7,7,7,7;,
  4;8,8,8,8;,
  4;9,9,9,9;,
  4;10,10,10,10;,
  4;11,11,11,11;,
  4;12,12,12,12;,
  4;13,13,14,14;,
  4;16,15,16,16;,
  4;18,17,18,18;,
  4;19,19,20,20;,
  4;17,15,13,13;,
  4;20,21,21,20;,
  4;22,22,22,22;,
  4;23,23,24,24;,
  4;25,25,25,25;,
  4;27,27,28,28;,
  4;29,23,23,29;,
  4;30,24,24,30;,
  4;22,22,22,22;,
  4;31,26,26,31;,
  4;25,25,25,25;,
  4;29,32,32,29;,
  4;27,27,31,31;,
  4;30,30,26,26;,
  4;33,33,33,33;,
  4;34,34,34,34;,
  4;35,35,35,35;,
  4;36,36,36,36;,
  4;37,37,37,37;,
  4;38,38,38,38;,
  4;39,39,40,40;,
  4;42,41,42,42;,
  4;44,43,44,44;,
  4;45,45,45,45;,
  4;43,41,39,39;,
  4;46,46,46,46;;
 }
 MeshTextureCoords {
  148;
  0.392576;0.551020;,
  0.392576;0.663064;,
  0.255549;0.748487;,
  0.255549;0.551020;,
  0.367576;0.551020;,
  0.367576;0.795918;,
  0.230549;0.795918;,
  0.230549;0.551020;,
  0.392576;0.663064;,
  0.392576;0.551020;,
  0.255549;0.551020;,
  0.255549;0.748487;,
  0.367576;0.795918;,
  0.367576;0.551020;,
  0.230549;0.551020;,
  0.230549;0.795918;,
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
  0.392576;0.663064;,
  0.392576;0.795918;,
  0.255549;0.795918;,
  0.255549;0.748487;,
  0.367576;0.551020;,
  0.367576;0.795918;,
  0.230549;0.795918;,
  0.230549;0.551020;,
  0.392576;0.795918;,
  0.392576;0.663064;,
  0.255549;0.748487;,
  0.255549;0.795918;,
  0.367576;0.795918;,
  0.367576;0.551020;,
  0.230549;0.551020;,
  0.230549;0.795918;,
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
  0.000000;1.236745;,
  0.000000;1.413522;,
  0.000000;3.446454;,
  0.000000;3.623230;,
  1.000000;1.413522;,
  1.000000;3.446454;,
  1.000000;1.236745;,
  1.000000;3.623230;,
  0.000000;-0.236745;,
  0.000000;-2.623230;,
  0.000000;-2.446454;,
  0.000000;-0.413521;,
  1.000000;-2.446454;,
  1.000000;-0.413521;,
  1.000000;-2.623230;,
  1.000000;-0.236745;,
  0.458448;0.673469;,
  0.458448;0.673469;,
  0.389327;0.795918;,
  0.389327;0.551020;,
  0.433448;0.551020;,
  0.433448;0.795918;,
  0.364327;0.795918;,
  0.364327;0.551020;,
  0.458448;0.673469;,
  0.458448;0.673469;,
  0.389327;0.551020;,
  0.389327;0.795918;,
  0.433448;0.795918;,
  0.433448;0.551020;,
  0.364327;0.551020;,
  0.364327;0.795918;,
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