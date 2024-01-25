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
 48;
 0.60486;5.18018;-3.63096;,
 14.45181;5.18018;-3.63096;,
 17.11455;-3.25945;-3.63096;,
 0.60486;-3.25945;-3.63096;,
 14.45181;5.18018;3.63096;,
 0.60486;5.18018;3.63096;,
 0.60486;-3.25945;3.63096;,
 17.11455;-3.25945;3.63096;,
 14.45181;5.18018;-0.95918;,
 17.11455;-3.25945;-0.95918;,
 17.11455;-3.25945;-3.63096;,
 14.45181;5.18018;-3.63096;,
 14.45181;5.18018;-0.95918;,
 14.45181;5.18018;-3.63096;,
 0.60486;5.18018;-3.63096;,
 0.60486;5.18018;-0.95918;,
 17.11455;-3.25945;-0.95918;,
 0.60486;-3.25945;-0.95918;,
 0.60486;-3.25945;-3.63096;,
 17.11455;-3.25945;-3.63096;,
 0.60486;5.18018;-0.95918;,
 0.60486;5.18018;-3.63096;,
 0.60486;-3.25945;-3.63096;,
 0.60486;-3.25945;-0.95918;,
 14.45181;5.18018;1.14937;,
 14.45181;5.18018;3.63096;,
 17.11455;-3.25945;3.63096;,
 17.11455;-3.25945;1.14937;,
 14.45181;5.18018;1.14937;,
 0.60486;5.18018;1.14937;,
 0.60486;5.18018;3.63096;,
 17.11455;-3.25945;1.14937;,
 0.60486;-3.25945;3.63096;,
 0.60486;-3.25945;1.14937;,
 0.60486;5.18018;1.14937;,
 0.60486;-3.25945;1.14937;,
 17.81057;-3.77862;1.14937;,
 15.14783;6.16101;1.14937;,
 15.14783;6.16101;-0.95918;,
 17.81057;-3.77862;-0.95918;,
 0.60486;6.68018;-0.95918;,
 15.14783;6.16101;-0.95918;,
 0.60486;6.68018;1.14937;,
 15.14783;6.16101;1.14937;,
 0.60486;-4.75943;1.14937;,
 17.81057;-3.77862;1.14937;,
 0.60486;-4.75943;-0.95918;,
 17.81057;-3.77862;-0.95918;;
 
 22;
 4;0,1,2,3;,
 4;4,5,6,7;,
 4;8,9,10,11;,
 4;12,13,14,15;,
 4;16,17,18,19;,
 4;20,21,22,23;,
 4;24,25,26,27;,
 4;28,29,30,25;,
 4;31,26,32,33;,
 4;34,20,23,35;,
 4;34,35,32,30;,
 4;36,37,24,27;,
 4;38,39,9,8;,
 4;37,36,39,38;,
 4;40,41,12,15;,
 4;42,40,15,29;,
 4;43,42,29,28;,
 4;43,41,40,42;,
 4;44,45,31,33;,
 4;46,44,33,17;,
 4;47,46,17,16;,
 4;45,44,46,47;;
 
 MeshMaterialList {
  5;
  22;
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
  2,
  2,
  2,
  2;;
  Material {
   0.332800;0.332800;0.332800;1.000000;;
   5.000000;
   0.870000;0.870000;0.870000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.800000;0.731200;0.000000;1.000000;;
   5.000000;
   0.820000;0.820000;0.820000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.800000;0.000000;0.034400;1.000000;;
   5.000000;
   0.910000;0.910000;0.910000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.000000;0.000000;0.000000;1.000000;;
   5.000000;
   0.800000;0.800000;0.800000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.800000;0.398400;0.000000;1.000000;;
   5.000000;
   0.870000;0.870000;0.870000;;
   0.000000;0.000000;0.000000;;
  }
 }
 MeshNormals {
  10;
  0.000000;0.000000;-1.000000;,
  0.000000;0.000000;1.000000;,
  0.953661;0.300884;0.000000;,
  0.000000;1.000000;0.000000;,
  0.000000;-1.000000;0.000000;,
  0.953661;0.300884;0.000000;,
  -1.000000;0.000000;0.000000;,
  0.965940;0.258767;0.000000;,
  0.035676;0.999363;0.000000;,
  0.056913;-0.998379;-0.000000;;
  22;
  4;0,0,0,0;,
  4;1,1,1,1;,
  4;2,2,2,2;,
  4;3,3,3,3;,
  4;4,4,4,4;,
  4;6,6,6,6;,
  4;5,5,5,5;,
  4;3,3,3,3;,
  4;4,4,4,4;,
  4;6,6,6,6;,
  4;6,6,6,6;,
  4;1,1,1,1;,
  4;0,0,0,0;,
  4;7,7,7,7;,
  4;0,0,0,0;,
  4;6,6,6,6;,
  4;1,1,1,1;,
  4;8,8,8,8;,
  4;1,1,1,1;,
  4;6,6,6,6;,
  4;0,0,0,0;,
  4;9,9,9,9;;
 }
 MeshTextureCoords {
  48;
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.367920;0.000000;,
  0.367920;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.632080;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.632080;,
  1.000000;0.367920;,
  0.000000;0.367920;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  0.632080;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.632080;1.000000;,
  0.658270;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.658270;1.000000;,
  1.000000;0.341730;,
  0.000000;0.341730;,
  0.000000;0.000000;,
  1.000000;0.658270;,
  0.000000;1.000000;,
  0.000000;0.658270;,
  0.341730;0.000000;,
  0.341730;1.000000;,
  0.658270;1.000000;,
  0.658270;0.000000;,
  0.367920;0.000000;,
  0.367920;1.000000;,
  0.000000;0.632080;,
  1.000000;0.632080;,
  0.000000;0.341730;,
  1.000000;0.341730;,
  0.000000;0.658270;,
  1.000000;0.658270;,
  0.000000;0.367920;,
  1.000000;0.367920;;
 }
}