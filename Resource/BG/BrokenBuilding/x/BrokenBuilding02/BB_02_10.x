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
 16;
 36.31900;345.00001;-50.00000;,
 36.31900;345.00001;50.00000;,
 -4.90850;279.16966;49.99998;,
 -4.90850;295.37796;-50.00002;,
 -26.14850;345.00001;50.00000;,
 -26.14850;345.00001;-50.00000;,
 -26.14850;345.00001;50.00000;,
 36.31900;345.00001;50.00000;,
 36.31900;345.00001;-50.00000;,
 -26.14850;345.00001;-50.00000;,
 -4.90850;279.16966;49.99998;,
 36.31900;345.00001;50.00000;,
 -26.14850;345.00001;50.00000;,
 -4.90850;295.37796;-50.00002;,
 -26.14850;345.00001;-50.00000;,
 36.31900;345.00001;-50.00000;;
 
 5;
 4;0,1,2,3;,
 4;4,5,3,2;,
 4;6,7,8,9;,
 3;10,11,12;,
 3;13,14,15;;
 
 MeshMaterialList {
  4;
  5;
  2,
  2,
  3,
  0,
  0;;
  Material {
   0.800000;0.800000;0.800000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
   TextureFilename {
    "texture\\bill002.jpg";
   }
  }
  Material {
   0.800000;0.800000;0.800000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
   TextureFilename {
    "texture\\bill002.jpg";
   }
  }
  Material {
   0.800000;0.800000;0.800000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
   TextureFilename {
    "texture\\Concrete.png";
   }
  }
  Material {
   0.800000;0.800000;0.800000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
   TextureFilename {
    "texture\\Concrete.png";
   }
  }
 }
 MeshNormals {
  5;
  -0.936204;-0.350574;-0.024888;,
  0.809331;-0.585778;-0.042992;,
  0.000000;1.000000;0.000000;,
  0.000000;-0.000000;1.000000;,
  0.000000;0.000000;-1.000000;;
  5;
  4;1,1,1,1;,
  4;0,0,0,0;,
  4;2,2,2,2;,
  3;3,3,3;,
  3;4,4,4;;
 }
 MeshTextureCoords {
  16;
  0.761290;0.020000;,
  0.761290;0.020000;,
  0.464690;0.194360;,
  0.464690;0.140450;,
  0.311880;0.020000;,
  0.311880;0.020000;,
  -0.807425;3.000000;,
  2.315950;3.000000;,
  2.315950;-2.000000;,
  -0.807425;-2.000000;,
  0.468719;-0.937678;,
  0.731457;-1.313499;,
  0.333359;-1.313499;,
  0.468719;-1.030210;,
  0.333359;-1.313499;,
  0.731457;-1.313499;;
 }
}
