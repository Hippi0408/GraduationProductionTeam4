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
 20;
 -0.00634;8.99806;-0.00936;,
 4.67429;6.40888;-0.00936;,
 4.67429;6.40888;-19.12443;,
 -0.00634;8.99806;-19.12443;,
 6.61307;0.15806;-0.00936;,
 6.61307;0.15806;-19.12443;,
 -6.62576;0.15806;-0.00936;,
 -4.68698;6.40888;-0.00936;,
 -4.68698;6.40888;-19.12443;,
 -6.62576;0.15806;-19.12443;,
 -0.00634;8.99806;-0.00936;,
 -0.00634;8.99806;-19.12443;,
 -0.00634;0.15806;-0.00936;,
 -0.00634;0.15806;-0.00936;,
 -0.00634;0.15806;-0.00936;,
 -0.00634;0.15806;-0.00936;,
 -0.00634;0.15806;-19.12443;,
 -0.00634;0.15806;-19.12443;,
 -0.00634;0.15806;-19.12443;,
 -0.00634;0.15806;-19.12443;;
 
 13;
 4;0,1,2,3;,
 4;1,4,5,2;,
 4;6,7,8,9;,
 4;7,10,11,8;,
 3;12,1,0;,
 3;13,4,1;,
 3;14,7,6;,
 3;15,10,7;,
 3;16,3,2;,
 3;17,2,5;,
 3;18,9,8;,
 3;19,8,11;,
 4;9,5,4,6;;
 
 MeshMaterialList {
  2;
  13;
  0,
  0,
  0,
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
   0.800000;0.580000;0.272800;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.800000;0.019200;0.000000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
 }
 MeshNormals {
  10;
  0.000000;0.000000;1.000000;,
  0.000000;1.000000;0.000000;,
  0.775595;0.631231;0.000000;,
  0.955113;0.296242;0.000000;,
  -0.955113;0.296242;0.000000;,
  -0.775595;0.631231;0.000000;,
  0.000000;0.000000;-1.000000;,
  0.000000;0.000000;1.000000;,
  0.000000;0.000000;-1.000000;,
  0.000000;-1.000000;-0.000000;;
  13;
  4;1,2,2,1;,
  4;2,3,3,2;,
  4;4,5,5,4;,
  4;5,1,1,5;,
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,7;,
  3;0,0,0;,
  3;6,6,6;,
  3;6,6,6;,
  3;6,8,6;,
  3;6,6,6;,
  4;9,9,9,9;;
 }
 MeshTextureCoords {
  20;
  0.000000;0.000000;,
  0.125000;0.000000;,
  0.125000;1.000000;,
  0.000000;1.000000;,
  0.250000;0.000000;,
  0.250000;1.000000;,
  0.750000;0.000000;,
  0.875000;0.000000;,
  0.875000;1.000000;,
  0.750000;1.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.062500;0.000000;,
  0.187500;0.000000;,
  0.812500;0.000000;,
  0.937500;0.000000;,
  0.062500;1.000000;,
  0.187500;1.000000;,
  0.812500;1.000000;,
  0.937500;1.000000;;
 }
}
