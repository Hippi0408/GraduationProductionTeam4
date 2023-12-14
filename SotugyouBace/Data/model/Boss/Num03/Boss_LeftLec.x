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
 26;
 0.00966;-2.13355;-1.36011;,
 1.02893;-2.13355;-0.68006;,
 0.06223;-8.08130;-0.31864;,
 -0.41535;-8.08130;-0.63728;,
 1.02893;-2.13355;0.68006;,
 0.06223;-8.08130;0.31864;,
 0.00966;-2.13355;1.36011;,
 -0.41535;-8.08130;0.63728;,
 -1.00962;-2.13355;0.68006;,
 -0.89293;-8.08130;0.31864;,
 -1.00962;-2.13355;-0.68006;,
 -0.89293;-8.08130;-0.31864;,
 0.00966;-2.13355;-1.36011;,
 -0.41535;-8.08130;-0.63728;,
 0.00966;0.03189;0.00000;,
 0.00966;0.03189;0.00000;,
 0.00966;0.03189;0.00000;,
 0.00966;0.03189;0.00000;,
 0.00966;0.03189;0.00000;,
 0.00966;0.03189;0.00000;,
 -0.41535;-8.08130;0.00000;,
 -0.41535;-8.08130;0.00000;,
 -0.41535;-8.08130;0.00000;,
 -0.41535;-8.08130;0.00000;,
 -0.41535;-8.08130;0.00000;,
 -0.41535;-8.08130;0.00000;;
 
 18;
 4;0,1,2,3;,
 4;1,4,5,2;,
 4;4,6,7,5;,
 4;6,8,9,7;,
 4;8,10,11,9;,
 4;10,12,13,11;,
 3;14,1,0;,
 3;15,4,1;,
 3;16,6,4;,
 3;17,8,6;,
 3;18,10,8;,
 3;19,12,10;,
 3;20,3,2;,
 3;21,2,5;,
 3;22,5,7;,
 3;23,7,9;,
 3;24,9,11;,
 3;25,11,13;;
 
 MeshMaterialList {
  4;
  18;
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
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
   0.401600;0.401600;0.401600;1.000000;;
   5.000000;
   0.910000;0.910000;0.910000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.191200;0.000000;0.276000;1.000000;;
   5.000000;
   0.720000;0.720000;0.720000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.062400;0.062400;0.062400;1.000000;;
   5.000000;
   0.830000;0.830000;0.830000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.282400;0.000000;0.006400;1.000000;;
   5.000000;
   0.960000;0.960000;0.960000;;
   0.000000;0.000000;0.000000;;
  }
 }
 MeshNormals {
  20;
  0.770656;0.490504;-0.406811;,
  0.546927;0.169988;-0.819741;,
  0.869224;0.174582;-0.462569;,
  0.869224;0.174582;0.462569;,
  0.546927;0.169988;0.819741;,
  -0.858352;0.235074;0.456040;,
  -0.858352;0.235074;-0.456040;,
  0.549587;-0.139380;-0.823728;,
  0.868605;-0.169470;-0.465624;,
  0.868605;-0.169470;0.465624;,
  0.549587;-0.139380;0.823728;,
  -0.881044;-0.045894;0.470802;,
  -0.881044;-0.045894;-0.470802;,
  0.000000;-1.000000;-0.000000;,
  -0.542802;0.208514;0.813565;,
  -0.553958;-0.061321;0.830283;,
  -0.542802;0.208514;-0.813565;,
  -0.553958;-0.061321;-0.830283;,
  0.000002;0.531883;0.846818;,
  -0.770653;0.490507;-0.406812;;
  18;
  4;1,2,8,7;,
  4;2,3,9,8;,
  4;3,4,10,9;,
  4;14,5,11,15;,
  4;5,6,12,11;,
  4;6,16,17,12;,
  3;0,2,1;,
  3;0,3,2;,
  3;18,4,3;,
  3;18,5,14;,
  3;19,6,5;,
  3;19,16,6;,
  3;13,13,13;,
  3;13,13,13;,
  3;13,13,13;,
  3;13,13,13;,
  3;13,13,13;,
  3;13,13,13;;
 }
 MeshTextureCoords {
  26;
  0.000000;0.000000;,
  0.166670;0.000000;,
  0.166670;1.000000;,
  0.000000;1.000000;,
  0.333330;0.000000;,
  0.333330;1.000000;,
  0.500000;0.000000;,
  0.500000;1.000000;,
  0.666670;0.000000;,
  0.666670;1.000000;,
  0.833330;0.000000;,
  0.833330;1.000000;,
  1.000000;0.000000;,
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
  0.916670;1.000000;;
 }
}
