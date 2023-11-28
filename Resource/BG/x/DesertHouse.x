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
 68;
 -3.15380;3.69653;-3.14760;,
 3.15380;3.69653;-3.14760;,
 3.15380;0.24808;-3.14760;,
 -3.15380;0.24808;-3.14760;,
 3.15380;3.69653;-3.14760;,
 3.15380;3.69653;3.16000;,
 3.15380;0.24808;3.16000;,
 3.15380;0.24808;-3.14760;,
 3.15380;3.69653;3.16000;,
 -3.15380;3.69653;3.16000;,
 -3.15380;0.24808;3.16000;,
 3.15380;0.24808;3.16000;,
 -3.15380;3.69653;3.16000;,
 -3.15380;3.69653;-3.14760;,
 -3.15380;0.24808;-3.14760;,
 -3.15380;0.24808;3.16000;,
 -3.15380;3.69653;3.16000;,
 3.15380;3.69653;3.16000;,
 3.15380;3.69653;-3.14760;,
 -3.15380;3.69653;-3.14760;,
 -3.15380;0.24808;-3.14760;,
 3.15380;0.24808;-3.14760;,
 3.15380;0.24808;3.16000;,
 -3.15380;0.24808;3.16000;,
 -2.25554;2.38321;-3.17124;,
 -0.67863;2.38321;-3.17124;,
 -0.67863;0.28068;-3.17124;,
 -2.25554;0.28068;-3.17124;,
 -0.67863;2.38321;-3.17124;,
 -0.67863;2.38321;-2.11997;,
 -0.67863;0.28068;-2.11997;,
 -0.67863;0.28068;-3.17124;,
 -0.67863;2.38321;-2.11997;,
 -2.25554;2.38321;-2.11997;,
 -2.25554;0.28068;-2.11997;,
 -0.67863;0.28068;-2.11997;,
 -2.25554;2.38321;-2.11997;,
 -2.25554;2.38321;-3.17124;,
 -2.25554;0.28068;-3.17124;,
 -2.25554;0.28068;-2.11997;,
 -0.67863;2.38321;-3.17124;,
 -2.25554;2.38321;-3.17124;,
 -2.25554;0.28068;-3.17124;,
 -0.67863;0.28068;-3.17124;,
 -2.36158;6.32470;-2.09944;,
 2.36158;6.32470;-2.09944;,
 2.36158;2.87625;-2.09944;,
 -2.36158;2.87625;-2.09944;,
 2.36158;6.32470;-2.09944;,
 2.36158;6.32470;2.11183;,
 2.36158;2.87625;2.11183;,
 2.36158;2.87625;-2.09944;,
 2.36158;6.32470;2.11183;,
 -2.36158;6.32470;2.11183;,
 -2.36158;2.87625;2.11183;,
 2.36158;2.87625;2.11183;,
 -2.36158;6.32470;2.11183;,
 -2.36158;6.32470;-2.09944;,
 -2.36158;2.87625;-2.09944;,
 -2.36158;2.87625;2.11183;,
 -2.36158;6.32470;2.11183;,
 2.36158;6.32470;2.11183;,
 2.36158;6.32470;-2.09944;,
 -2.36158;6.32470;-2.09944;,
 -2.36158;2.87625;-2.09944;,
 2.36158;2.87625;-2.09944;,
 2.36158;2.87625;2.11183;,
 -2.36158;2.87625;2.11183;;
 
 18;
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
 4;64,65,66,67;;
 
 MeshMaterialList {
  3;
  18;
  1,
  1,
  1,
  1,
  1,
  2,
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
  2;;
  Material {
   0.000000;0.000000;0.000000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.752800;0.759200;0.721600;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
   TextureFilename {
    "Data\\texture\\building\\sandstone.png";
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
  18;
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
  1.000000;0.000000;0.000000;,
  0.000000;0.000000;1.000000;,
  -1.000000;0.000000;0.000000;,
  0.000000;1.000000;0.000000;,
  0.000000;-1.000000;-0.000000;;
  18;
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
  4;12,12,12,12;,
  4;13,13,13,13;,
  4;14,14,14,14;,
  4;15,15,15,15;,
  4;16,16,16,16;,
  4;17,17,17,17;;
 }
 MeshTextureCoords {
  68;
  0.392580;0.551020;,
  0.392580;0.795920;,
  0.255550;0.795920;,
  0.255550;0.551020;,
  0.367580;0.551020;,
  0.367580;0.795920;,
  0.230550;0.795920;,
  0.230550;0.551020;,
  0.392580;0.795920;,
  0.392580;0.551020;,
  0.255550;0.551020;,
  0.255550;0.795920;,
  0.367580;0.795920;,
  0.367580;0.551020;,
  0.230550;0.551020;,
  0.230550;0.795920;,
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
  0.392580;0.551020;,
  0.392580;0.795920;,
  0.255550;0.795920;,
  0.255550;0.551020;,
  0.367580;0.551020;,
  0.367580;0.795920;,
  0.230550;0.795920;,
  0.230550;0.551020;,
  0.392580;0.795920;,
  0.392580;0.551020;,
  0.255550;0.551020;,
  0.255550;0.795920;,
  0.367580;0.795920;,
  0.367580;0.551020;,
  0.230550;0.551020;,
  0.230550;0.795920;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;;
 }
}